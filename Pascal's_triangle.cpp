#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
/*
                   1
                 1   1
               1   2   1
             1   3   3   1
           1   4   9   4   1
         1   5   13  13   5  1
*/

//���õݹ�����������������:
int c(int x, int y)
{
    int z;
    if ((y==1) || (y==x+1))
    {
        return 1;
    }
    z = c(x - 1, y - 1) + c(x - 1, y);
    return z;
}

//���������forѭ������������������
int c1(int n)
{
    int i, j;
    int ** a = (int**)malloc(sizeof(int*)*n);
    for (int i = 0; i < n; i++)
    {
        a[i] = (int*)malloc(sizeof(int)*n);
    }
    printf("�������!:\n");
    for (int i = 0; i < n; i++)
    {
        a[i][0] = 1;
        a[i][i] = 1;
    }
    for (i = 2; i < n; i++)
    {
        for (j = 1; j < i; j++)
        {
            a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%*d",  25 - i * 2, a[i][0]);
        for (j = 1; j <= i; j++)
        {
            printf("%4d", a[i][j]);
        }
        printf("\n");
    }
    if (a)
    {
        for (int i = 0; i < n; i++)
        {
            if (a[i])
            {
                free(a[i]);
                a[i] = NULL;
            }
        }
        free(a);
        a = NULL;
    }
    return 0;
}



int  main()
{

    int i, j,k, n = 13;
    printf("N= ");
    while (n > 12)
    {
        scanf("%d", &n);//������ȷ��ֵ����֤��Ļ�ܹ���ʾ�㹻�ĳ���
    }

    for (i = 0; i <= n; i++)
    {
        for (k = 0; k < 24 - 2 * i; k++)
        {
            printf(" ");//ÿһ�зǿո������׵Ŀո���
        }
        for (j = 1; j < i + 2; j++)
        {
            printf("%4d", c(i, j));//���Ǵ�0��ʼ���������Ǵ�1��ʼ����
        }
        printf("\n");//���ƻ���
    }
    system("pause");
    return 0;
}


