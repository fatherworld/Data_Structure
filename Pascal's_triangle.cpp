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

//利用递归来解决杨辉三角问题:
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

//利用数组和for循环来解决杨辉三角问题
int c1(int n)
{
    int i, j;
    int ** a = (int**)malloc(sizeof(int*)*n);
    for (int i = 0; i < n; i++)
    {
        a[i] = (int*)malloc(sizeof(int)*n);
    }
    printf("杨辉三角!:\n");
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
        scanf("%d", &n);//输入正确的值来保证屏幕能够显示足够的长度
    }

    for (i = 0; i <= n; i++)
    {
        for (k = 0; k < 24 - 2 * i; k++)
        {
            printf(" ");//每一行非空格离行首的空格数
        }
        for (j = 1; j < i + 2; j++)
        {
            printf("%4d", c(i, j));//行是从0开始计数，列是从1开始计数
        }
        printf("\n");//控制换行
    }
    system("pause");
    return 0;
}


