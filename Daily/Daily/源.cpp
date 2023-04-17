#include <iostream>
using namespace std;
int main()
{
    int a = 0, b = 0, c;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> c;
        a += (c >= 60 ? 1 : 0);
        b += (c >= 85 ? 1 : 0);
    }
    cout << (a * 100) / n << "%" << endl << b * 100 / n << "%" << endl;

    return 0;
}

//#include <iostream>
//#include <vector>
//#include <stack>
//
//using namespace std;
//
//int Calculate(vector<int> vec)
//{
//    int res = 0;
//    stack<int> stk;
//    for (int i = 0; i < vec.size(); i++)
//    {
//        if (vec[i] == 0)
//        {
//            stk.push(0);
//            if (stk.size() > 1)
//            {
//                int j;
//                stack<int> new_stk;
//                for (j = i ; j < vec.size(); j++)
//                {
//                    if (vec[j] == 0)
//                    {
//                        new_stk.push(0);
//                    }
//                    if (vec[j] == 1)
//                    {
//                        if (stk.size() == 0)
//                        {
//                            break;
//                        }
//                        new_stk.pop();
//                    }
//                }
//                vector<int>::iterator new_beg = vec.begin() + i;
//                vector<int>::iterator new_end = vec.begin() + j + 1;
//                vector<int> new_vec;
//                new_vec.assign(new_beg, new_end);
//                res += 2 * Calculate(new_vec);
//            }
//        }
//        else
//        {
//            stk.pop();
//            res += 1;
//        }
//    }
//    return res;
//}
//
//int main()
//{
//     int n;
//     cin>>n;
//     vector<int> vec(n,0);
//     for(int i=0;i<vec.size();i++)
//     {
//         cin>>vec[i];
//     }
//     cout<<Calculate(vec)<<endl;
//}

//#include <iostream>
//#include <stack>
//#include <vector>
//using namespace std;
//
//stack<int> s;
//
//int RecursiveComputation(vector<int> arr)
//{
//    int ans = 0, val = 0;
//    for (int i = 0; i < arr.size(); i++)
//    {
//        if (arr[i] == 0)
//        {
//            s.push(0);
//        }
//        else
//        {
//            val = 1;
//            s.pop();
//            while (!s.empty())
//            {
//                vector<int>::iterator beg = arr.begin() + i;
//                vector<int>::iterator end = find(beg, arr.end(), 1);
//                i += end - beg;
//                vector<int> vec;
//                vec.assign(beg, end);
//                val += 2*RecursiveComputation(vec);
//            }
//            
//        }
//        ans += val;
//        val = 0;
//    }
//    return ans;
//}
//
//int main() {
//    int n;
//    cin >> n;
//    vector<int> arr(n);
//    for (int i = 0; i < n; i++) {
//        cin >> arr[i];
//    }
//    
//    cout << RecursiveComputation(arr) << endl;
//    return 0;
//}




////2. 数字的全排列
////给定一个整数 n，将数字 1∼n 排成一排，将会有很多种排列方法。
////现在，请你按照字典序将所有的排列方法输出。
////输入格式
////共一行，包含一个整数 n。
////输出格式
////按字典序输出所有排列方案，每个方案占一行。
////数据范围
////1≤n≤7
////输入样例：
////3
////输出样例：
////1 2 3
////1 3 2
////2 1 3
////2 3 1
////3 1 2
////3 2 1
//
//#include <iostream>
//#include <vector>
//using namespace std;
//
//void dfs(vector<int>& path, vector<bool>& visited, int n) {
//    if (path.size() == n) { // 当前排列已经排好
//        for (int num : path) {
//            cout << num << " ";
//        }
//        cout << endl;
//        return;
//    }
//
//    for (int i = 1; i <= n; i++) {
//        if (!visited[i]) { // 如果数字i还没有被使用过，可以将其加入当前排列中
//            path.push_back(i);
//            visited[i] = true;
//            dfs(path, visited, n); // 递归到下一层
//            visited[i] = false; // 回溯到上一层，将数字i从当前排列中删除，并标记为未使用过
//            path.pop_back();
//        }
//    }
//}
//
//int main() {
//    int n;
//    cin >> n;
//
//    vector<int> path; // 存放当前排列
//    vector<bool> visited(n + 1, false); // 标记每个数字是否使用过，初始化为false
//
//    dfs(path, visited, n);
//
//    return 0;
//}


//迭代算法（无字典序）

//vector<string> WholeArrangement(string str)
//{
//	vector<string> res;
//	string med;
//	med.push_back(str[0]);
//	res.push_back(med);
//	for (int i = 1; i < str.length(); i++)
//	{
//		char ch = str[i];
//		vector<string> temp_res;
//		for (string str : res)
//		{
//			//插在前面
//			temp_res.push_back(ch + str);
//			//插在后面
//			temp_res.push_back(str + ch);
//			//插在中间
//			for (int j = 1; j < str.length(); j++)
//			{
//				temp_res.push_back(str.substr(0, j) + ch + str.substr(j));
//			}
//		}
//		res = temp_res;
//	}
//	return res;
//}
//
//string DigitalConversionString(int num)
//{
//	string res;
//	for (int i = 1; i <= num; i++)
//	{
//		res.push_back((char)(i + 48));
//	}
//	return res;
//}
//
//int main()
//{
//	int num;
//	vector<string> res;
//	cin >> num;
//	res=WholeArrangement(DigitalConversionString(num));
//	for (string answer : res)
//	{
//		cout << answer.size() << endl;
//	}
//}