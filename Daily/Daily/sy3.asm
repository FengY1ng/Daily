data segment;
y db 10 dup(0);����һ������Ϊ10���ֽڵ�ջ��
data ends;segment����Ķν���
stack segment para stack 'stack';�����ջ��
sta db 100 dup(0);����һ������Ϊ100���ֽڵ�ջ��
top equ length sta;���staջ�Ĵ�С
stack ends;����Ķν���
code segment
        assume cs:code,ds:data,ss:stack,es:data
start proc far
        push ds;��psp��ֵѹջ
        xor ax,ax;��ax����������ʹax��cf����
        push ax;ʹax��ջ
        mov ax,data;��data��ֵ�洢��ax��
        mov ds,ax
        lea si,y;ȡy�ĵ�ַ��ƫ�����������䴫�͵�si���ڵĵ�Ԫ
        mov dl,ah
        mov ah,02
        mov dl,'s'
        int 21h;�ж�ָ��
        mov dl,'='
        int 21h
        mov bx,1;ʹbx����������ʼֵΪ1
        mov ax,0;ʹax�����պͣ���ʼֵΪ0
        xor ch,ch;��ch����
        mov cl,100;�޶��ظ�����Ϊ100
lop: add ax,bx;��ax��bx��Ӳ��洢��ax��
        inc bx;bx��1
        loop lop;�ظ��˲���100��
        mov bx,000ah
lop1: xor dx,dx;ʹdx����
        div bx;��ax��Ϊ10������
        mov [si],dl
        inc si;ʹsi����1
        cmp ax,000ah;�Ƚ�����
        jae lop1;�����ڵ��ڣ����������ת��
        mov [si],al
        mov [si+1],dl
lop2: mov dl,[si]
        call disp
        dec si
        cmp si,0;�Ƚ�si��0
        jge lop2;��siС��0�����������ת��
        mov ah,4ch;��DOS���ܺ�4CH�����ۼ���AH
        int 21h;�ж�ָ��
disp proc near
        mov ah,2
        or dl,30h
        int 21h;�ж�ָ��
        ret
disp endp;diso���̽���
start endp;proc������̽���
code ends;����ν���
        end start;Դ�������
