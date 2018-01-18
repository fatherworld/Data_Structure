#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string>
/*
魔方阵简介:
    古代魔方阵又称纵横图,是1,2...n的平方的n*n方阵
    其中每个元素的值都不相等
    每行，每列以及主,副对角线上的n个元素和相等
 */

/*
3阶魔方示意图:
    8  1  6
    3  5  7
    4  9  2
*/


/*
魔方阵的存放规律:
    将数字1放在第一行的中间一列
    从数字2开始，n的平方结束,存放的法则如下:
    后一个数字放在前一个数字的前一行，后一列
    如:数字2放在第一行的前一行即n行，后一列n/2+1列
    如果按照上面的规则确定的位置上已经存在数字，或上一个数是第一行第n列，则把下一个数放在上一个数的下面
*/


//奇数行列魔方阵存放代码
int odd_matrix()
{
    int ret = 0;
    int matrix_degree;
    printf("Please input a number what in range of (1,15) and it must be a odd");
    scanf("%d", &matrix_degree);
    //该条件不明觉厉
    while (!(matrix_degree > 1 && matrix_degree < 15) || matrix_degree % 2 == 0)
    {
        printf("The number is invalid: Please insert again");
        scanf("%d", &matrix_degree);
    }

    int** matrix = (int**)malloc(sizeof(int*)*matrix_degree);
    for (int i = 0; i < matrix_degree; i++)
    {
        matrix[i] = (int*)malloc(sizeof(int)*matrix_degree);
        memset(matrix[i], 0, sizeof(int)*matrix_degree);
    }

    //确定第一个元素的存放位置
    int row = 0;
    int cols = matrix_degree / 2;
    matrix[0][cols] = 1;
    int prerow = row;
    int precols = cols;


    for (int j = 2; j <= pow(matrix_degree, 2); j++)
    {
        row--;
        cols++;

        if (row == -1)
        {
            row = matrix_degree - 1;
        }
        if (cols == matrix_degree)
        {
            cols = 0;
        }
        if (*(matrix[row] + cols) || (prerow == 0 && precols == matrix_degree - 1))
        {
            row = prerow + 1;
            if (row == matrix_degree) row = 0;
            cols = precols;
        }

        (*(matrix[row] + cols)) = j;

        prerow = row;
        precols = cols;

    }

    for (int p = 0; p < matrix_degree; p++)
    {
        for (int q = 0; q < matrix_degree; q++)
        {
            printf("%3d", (*(matrix[p] + q)));
        }
        printf("\n");
    }


    if (matrix)
    {
        for (int i = 0; i < matrix_degree; i++)
        {
            if (matrix[i])
            {
                free(matrix[i]);
                matrix[i] = NULL;
            }
        }
        free(matrix);
        matrix = NULL;
    }
    system("pause");
    return ret;
}

int main()
{
    return odd_matrix();
}