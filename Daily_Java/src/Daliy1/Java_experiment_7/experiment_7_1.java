package Daliy1.Java_experiment_7;

import java.util.Date;
import java.text.SimpleDateFormat;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Scanner;

class MyFile {
    FileReader filereader;
    BufferedReader bfreader;
    StringBuffer streader;
    FileWriter filewriter;
    BufferedWriter bfwriter;

    public void read() throws Exception {
        filereader = new FileReader("D:\\learn\\java\\base.txt");
        bfreader = new BufferedReader(filereader);
        String s;
        streader = new StringBuffer();
        System.out.println("Sno" + "  " + "Sname" + "  " + "Sex" + "  " + "Sep" + "  " + "Sday" + "  ");
        while ((s = bfreader.readLine()) != null) {
            System.out.println(s);
        }
        bfreader.close();
    }

    public void alter() throws Exception {
        String median, swap;
        int index, swit = 1, i = 0;
        boolean flag = true;
        String s;
        streader = new StringBuffer();
        filereader = new FileReader("D:\\learn\\java\\base.txt");
        bfreader = new BufferedReader(filereader);
        System.out.println("Sno" + "  " + "Sname" + "  " + "Sex" + "  " + "Sep" + "  " + "Sday" + "  ");
        while ((s = bfreader.readLine()) != null) {
            s = s + " ";
            streader.append(s);
            System.out.println(s);
        }
        String[] words = streader.toString().split("\\s+");
        Scanner cin = new Scanner(System.in);
        while (flag) {
            System.out.println("输入相关信息如：1 Sno 2104060802修改第一行的sno修改为，，，，");
            index = cin.nextInt();
            median = cin.next();
            swap = cin.next();
            switch (median) {
                case "Sno":
                    words[(index - 1) * 5] = swap;
                    break;
                case "Sname":
                    words[(index - 1) * 5 + 1] = swap;
                    break;
                case "Sex":
                    words[(index - 1) * 5 + 2] = swap;
                    break;
                case "Sep":
                    words[(index - 1) * 5 + 3] = swap;
                    break;
                case "Sday":
                    words[(index - 1) * 5 + 4] = swap;
                    break;
            }
            System.out.println("是否继续修改yes->(1),no->(0)");
            swit = cin.nextInt();
            if (swit == 0)
                flag = false;
        }
        bfreader.close();
        // input.close();
        filewriter = new FileWriter("base.txt");
        bfwriter = new BufferedWriter(filewriter);
        System.out.println("修改后的表");
        System.out.println("Sno" + "  " + "Sname" + "  " + "Sex" + "  " + "Sep" + "  " + "Sday" + "  ");
        for (String a : words) {
            a = a + " ";
            i = i + 1;
            bfwriter.write(a);
            System.out.print(a);
            if (i % 5 == 0) {
                bfwriter.newLine();
                System.out.println();
            }
        }
        bfwriter.close();
    }

    public void drop() throws Exception {
        String[] temp;
        String s;
        int i = 0, drop_value, begin, end;
        Scanner input;
        boolean flag4 = true;
        int star_stop = 1;
        streader = new StringBuffer();
        filereader = new FileReader("base.txt");
        bfreader = new BufferedReader(filereader);
        System.out.println("Sno" + "  " + "Sname" + " " + "Sex" + " " + "Sep" + " " + "Sday" + " ");
        while ((s = bfreader.readLine()) != null) {
            System.out.println(s);
            s = s + " ";
            streader.append(s);
        }
        temp = streader.toString().split("\\s+");
        bfreader.close();
        filewriter = new FileWriter("base.txt");
        bfwriter = new BufferedWriter(filewriter);
        streader = new StringBuffer();
        input = new Scanner(System.in);
        while (flag4) {
            System.out.println("输入你想删除的信息 例如：3，删除第三行数据");
            drop_value = input.nextInt();
            begin = (drop_value - 1) * 5 + 1;
            end = drop_value * 5;
            for (String a : temp) {
                a = a + " ";
                i = i + 1;
                if (i < begin || end < i) {
                    streader.append(a);
                    System.out.print(a);
                    if (i % 5 == 0) {
                        System.out.println();
                    }
                }
            }
            temp = streader.toString().split("\\s+");
            streader.setLength(0);
            System.out.println("是否继续删除yes(1),no(0)");
            star_stop = input.nextInt();
            if (star_stop == 0) {
                flag4 = false;
            }
            i = 0;
        }
        i = 0;
        System.out.println("删除后的信息");
        System.out.println("Sno" + " " + "Sname" + " " + "Sex" + " " + "Sep" + " " + "Sday" + " ");
        for (String a : temp) {
            a = a + " ";
            i = i + 1;
            bfwriter.write(a);
            System.out.print(a);
            if (i % 5 == 0) {
                bfwriter.newLine();
                System.out.println();
            }

        }
        bfwriter.close();
    }

    public void insert() throws Exception {
        String s;
        int i = 0;
        Scanner input;
        String insert_value;
        String[] words;
        boolean flag3 = true;
        int sta_sto = 1;
        streader = new StringBuffer();
        filereader = new FileReader("test.txt");
        bfreader = new BufferedReader(filereader);
        while ((s = bfreader.readLine()) != null) {
            s = s + " ";
            streader.append(s);
        }
        filereader.close();
        bfreader.close();
        input = new Scanner(System.in);
        while (flag3) {
            System.out.println("输入相关信息如:1234567890 张三 男 软工 2000-01-01");
            insert_value = input.nextLine();
            insert_value = " " + insert_value;
            streader.append(insert_value);
            System.out.println("是否继续插入\nyes(1)/no(2)");
            sta_sto = input.nextInt();
            if (sta_sto == 2) {
                flag3 = false;
            }
        }
        // input.close();
        System.out.println("插入结果");
        words = streader.toString().split("\\s+");
        System.out.println("Sno" + "  " + "Sname" + "  " + "Sex" + "  " + "Sep" + "  " + "Sday" + "  ");
        filewriter = new FileWriter("base.txt");
        bfwriter = new BufferedWriter(filewriter);
        for (String a : words) {
            a = a + " ";
            i = i + 1;
            bfwriter.write(a);
            System.out.print(a);
            if (i % 5 == 0) {
                bfwriter.newLine();
                System.out.println();
            }
        }
        bfwriter.close();
    }
}

public class experiment_7_1 {
    public static void main(String[] args){
        System.out.println("软件工程21-8_2104060804_冯雪岩");
		SimpleDateFormat df = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
		System.out.println(df.format(new Date()));
        System.out.println("欢迎进入哈尔滨理工大学学生通讯录入系统！");
        boolean flag1 = true;
        Scanner input;
        int start_stop = 1;
        int mode;
        MyFile file = new MyFile();
        Scanner cin = new Scanner(System.in);
        while (flag1) {
            System.out.println("输入你想进行的操作:查询(1).修改(2).插入(3)删除(4)");
            mode = cin.nextInt();
            switch (mode) {
                case 1:
                    file.read();
                    break;
                case 2:
                    file.alter();
                    break;
                case 3:
                    file.insert();
                    break;
                case 4:
                    file.drop();
                    break;
            }
            System.out.println("是否退出y(1)/n(0)");
            // cin = new Scanner(System.in);
            start_stop = cin.nextInt();
            if (start_stop == 0) {
                // cin.close();
                flag1 = false;
            }
        }
    }
}
