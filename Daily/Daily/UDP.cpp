//#include <iostream>
//#include <string>
//#include <winsock2.h>
//
//#pragma comment(lib, "ws2_32.lib")
//
//const int MAX_PACKET_SIZE = 1024;
//const int WINDOW_SIZE = 5;
//
//// 数据包结构
//struct Packet
//{
//    int sequenceNumber;
//    bool isAck;
//    std::string data;
//};
//
//// 生成校验和
//unsigned short generateChecksum(const char* data, int size)
//{
//    unsigned long sum = 0;
//    while (size > 1)
//    {
//        sum += *(unsigned short*)data;
//        data += 2;
//        size -= 2;
//    }
//    if (size > 0)
//        sum += *(unsigned char*)data;
//
//    while (sum >> 16)
//        sum = (sum & 0xFFFF) + (sum >> 16);
//
//    return ~sum;
//}
//
//// 发送数据包
//bool sendPacket(SOCKET socket, const Packet& packet, const sockaddr_in& serverAddr)
//{
//    char buffer[MAX_PACKET_SIZE];
//    int bufferSize = sizeof(packet.sequenceNumber) + sizeof(packet.isAck) + packet.data.length();
//    memcpy(buffer, &packet.sequenceNumber, sizeof(packet.sequenceNumber));
//    memcpy(buffer + sizeof(packet.sequenceNumber), &packet.isAck, sizeof(packet.isAck));
//    memcpy(buffer + sizeof(packet.sequenceNumber) + sizeof(packet.isAck), packet.data.c_str(), packet.data.length());
//
//    // 生成校验和
//    unsigned short checksum = generateChecksum(buffer, bufferSize);
//    memcpy(buffer + bufferSize, &checksum, sizeof(checksum));
//    bufferSize += sizeof(checksum);
//
//    // 发送数据包
//    int bytesSent = sendto(socket, buffer, bufferSize, 0, (sockaddr*)&serverAddr, sizeof(serverAddr));
//    return bytesSent == bufferSize;
//}
//
//// 接收数据包
//bool receivePacket(SOCKET socket, Packet& packet, sockaddr_in& clientAddr)
//{
//    char buffer[MAX_PACKET_SIZE];
//    int bufferSize = sizeof(buffer);
//    int clientAddrSize = sizeof(clientAddr);
//    int bytesReceived = recvfrom(socket, buffer, bufferSize, 0, (sockaddr*)&clientAddr, &clientAddrSize);
//    if (bytesReceived <= 0)
//        return false;
//
//    memcpy(&packet.sequenceNumber, buffer, sizeof(packet.sequenceNumber));
//    memcpy(&packet.isAck, buffer + sizeof(packet.sequenceNumber), sizeof(packet.isAck));
//    packet.data = std::string(buffer + sizeof(packet.sequenceNumber) + sizeof(packet.isAck),
//        bytesReceived - sizeof(packet.sequenceNumber) - sizeof(packet.isAck));
//
//    // 验证校验和
//    unsigned short checksum;
//    memcpy(&checksum, buffer + bytesReceived, sizeof(checksum));
//    unsigned short calculatedChecksum = generateChecksum(buffer, bytesReceived);
//    return checksum == calculatedChecksum;
//}
//
//// 客户端发送数据
//void clientSend(SOCKET socket, const sockaddr_in& serverAddr)
//{
//    int sequenceNumber = 0;
//    std::string message;
//
//    std::cout << "Enter message to send (enter 'exit' to quit): ";
//    std::getline(std::cin, message);
//
//    while (message != "exit")
//    {
//        Packet packet;
//        packet.sequenceNumber = sequenceNumber;
//        packet.isAck = false;
//        packet.data = message;
//
//        // 发送数据包
//        if (sendPacket(socket, packet, serverAddr))
//        {
//            std::cout << "Sent packet with sequence number: " << sequenceNumber << std::endl;
//
//            // 等待ACK
//            Packet ackPacket;
//            sockaddr_in clientAddr;
//            while (true)
//            {
//                if (receivePacket(socket, ackPacket, clientAddr) && ackPacket.isAck && ackPacket.sequenceNumber == sequenceNumber)
//                {
//                    std::cout << "Received ACK for packet with sequence number: " << sequenceNumber << std::endl;
//                    break;
//                }
//                // 重传数据包
//                sendPacket(socket, packet, serverAddr);
//            }
//
//            sequenceNumber++;
//        }
//
//        std::cout << "Enter message to send (enter 'exit' to quit): ";
//        std::getline(std::cin, message);
//    }
//}
//
//// 服务器接收数据
//void serverReceive(SOCKET socket, const sockaddr_in& clientAddr)
//{
//    int expectedSequenceNumber = 0;
//
//    while (true)
//    {
//        Packet packet;
//        sockaddr_in receivedClientAddr;
//        if (receivePacket(socket, packet, receivedClientAddr) && receivedClientAddr.sin_addr.s_addr == clientAddr.sin_addr.s_addr)
//        {
//            if (packet.sequenceNumber == expectedSequenceNumber)
//            {
//                std::cout << "Received packet with sequence number: " << expectedSequenceNumber << std::endl;
//
//                // 发送ACK
//                Packet ackPacket;
//                ackPacket.sequenceNumber = expectedSequenceNumber;
//                ackPacket.isAck = true;
//                sendPacket(socket, ackPacket, clientAddr);
//
//                expectedSequenceNumber++;
//            }
//            else
//            {
//                std::cout << "Received out-of-order packet. Expected sequence number: "
//                    << expectedSequenceNumber << ", Received sequence number: " << packet.sequenceNumber << std::endl;
//                // 丢弃乱序的数据包，不发送ACK
//            }
//        }
//    }
//}
//
//int main()
//{
//    WSADATA wsaData;
//    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
//    {
//        std::cerr << "Failed to initialize winsock" << std::endl;
//        return 1;
//    }
//
//    // 创建套接字
//    SOCKET socket = ::socket(AF_INET, SOCK_DGRAM, 0);
//    if (socket == INVALID_SOCKET)
//    {
//        std::cerr << "Failed to create socket" << std::endl;
//        WSACleanup();
//        return 1;
//    }
//
//    sockaddr_in serverAddr;
//    serverAddr.sin_family = AF_INET;
//    serverAddr.sin_port = htons(12345);  // 选择合适的端口号
//    serverAddr.sin_addr.s_addr = INADDR_ANY;
//
//    // 绑定套接字
//    if (bind(socket, (sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR)
//    {
//        std::cerr << "Failed to bind socket" << std::endl;
//        closesocket(socket);
//        WSACleanup();
//        return 1;
//    }
//
//    // 运行作为服务器或客户端
//    std::cout << "Enter 's' to run as server, 'c' to run as client: ";
//    std::string mode;
//    std::getline(std::cin, mode);
//
//    if (mode == "s")
//    {
//        std::cout << "Running as server..." << std::endl;
//        serverReceive(socket, serverAddr);
//    }
//    else if (mode == "c")
//    {
//        std::cout << "Running as client..." << std::endl;
//        clientSend(socket, serverAddr);
//    }
//    else
//    {
//        std::cerr << "Invalid mode" << std::endl;
//    }
//
//    // 关闭套接字和清理Winsock
//    closesocket(socket);
//    WSACleanup();
//
//    return 0;
//}
