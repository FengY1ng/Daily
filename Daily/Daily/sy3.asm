data segment;
y db 10 dup(0);定义一个容量为10个字节的栈段
data ends;segment定义的段结束
stack segment para stack 'stack';定义堆栈段
sta db 100 dup(0);定义一个容量为100个字节的栈段
top equ length sta;获得sta栈的大小
stack ends;定义的段结束
code segment
        assume cs:code,ds:data,ss:stack,es:data
start proc far
        push ds;将psp的值压栈
        xor ax,ax;对ax进行异或操作使ax、cf清零
        push ax;使ax入栈
        mov ax,data;将data的值存储到ax中
        mov ds,ax
        lea si,y;取y的地址的偏移量，并将其传送到si所在的单元
        mov dl,ah
        mov ah,02
        mov dl,'s'
        int 21h;中断指令
        mov dl,'='
        int 21h
        mov bx,1;使bx（加数）初始值为1
        mov ax,0;使ax（最终和）初始值为0
        xor ch,ch;将ch清零
        mov cl,100;限定重复次数为100
lop: add ax,bx;将ax，bx相加并存储到ax中
        inc bx;bx加1
        loop lop;重复此操作100次
        mov bx,000ah
lop1: xor dx,dx;使dx清零
        div bx;将ax化为10进制数
        mov [si],dl
        inc si;使si自增1
        cmp ax,000ah;比较两数
        jae lop1;若大于等于，则进行数据转移
        mov [si],al
        mov [si+1],dl
lop2: mov dl,[si]
        call disp
        dec si
        cmp si,0;比较si与0
        jge lop2;若si小于0，则进行数据转移
        mov ah,4ch;将DOS功能号4CH送于累加器AH
        int 21h;中断指令
disp proc near
        mov ah,2
        or dl,30h
        int 21h;中断指令
        ret
disp endp;diso过程结束
start endp;proc定义过程结束
code ends;代码段结束
        end start;源程序结束
