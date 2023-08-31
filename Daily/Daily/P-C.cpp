#include <stdio.h>
#include <stdlib.h>

int num = 0;
int Matrix[100][100];
void chessBoard(int tr, int tc, int dr, int dc, int size);
int main()
{
    int size, r, c, row, col;
    printf("���������̵����к�");
    scanf("%d", &size);
    printf("���������ⷽ������к�");
    scanf("%d %d", &row, &col);
    chessBoard(0, 0, row, col, size);

    for (r = 0; r < size; r++)
    {
        for (c = 0; c < size; c++)
        {
            printf("%2d ", Matrix[r][c]);
        }
        printf("\n");
    }

    return 0;
}

void chessBoard(int tr, int tc, int dr, int dc, int size)
{
    if (size == 1)
        return;
    int s = size / 2;     //�ָ�����
    int t = ++num;      //L�͹��ƺ�

    //�������Ͻ�������
    if (dr < tr + s && dc < tc + s)
    {
        //���ⷽ���ڴ�������
        chessBoard(tr, tc, dr, dc, s);
    }
    else            //�������������ⷽ��
    {
        //��t��L�͹��Ƹ������½�
        Matrix[tr + s - 1][tc + s - 1] = t;
        //�������෽��
        chessBoard(tr, tc, tr + s - 1, tc + s - 1, s);
    }

    //�������Ͻ�������
    if (dr < tr + s && dc >= tc + s)
    {
        //���ⷽ���ڴ�������
        chessBoard(tr, tc + s, dr, dc, s);
    }
    else            //�������������ⷽ��
    {
        //��t��L�͹��Ƹ������½�
        Matrix[tr + s - 1][tc + s] = t;
        //�������෽��
        chessBoard(tr, tc + s, tr + s - 1, tc + s, s);
    }

    //�������½�������
    if (dr >= tr + s && dc < tc + s)
    {
        //���ⷽ���ڴ�������
        chessBoard(tr + s, tc, dr, dc, s);
    }
    else
    {
        //��t��L�͹��Ƹ������Ͻ�
        Matrix[tr + s][tc + s - 1] = t;
        //�������෽��
        chessBoard(tr + s, tc, tr + s, tc + s - 1, s);
    }

    //�������½�������
    if (dr >= tr + s && dc >= tc + s)
    {
        //���ⷽ���ڴ�������
        chessBoard(tr + s, tc + s, dr, dc, s);
    }
    else
    {
        //��t��L�͹��Ƹ������Ͻ�
        Matrix[tr + s][tc + s] = t;
        //�������෽��
        chessBoard(tr + s, tc + s, tr + s, tc + s, s);
    }

}