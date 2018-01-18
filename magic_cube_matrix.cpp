#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string>
/*
ħ������:
    �Ŵ�ħ�����ֳ��ݺ�ͼ,��1,2...n��ƽ����n*n����
    ����ÿ��Ԫ�ص�ֵ�������
    ÿ�У�ÿ���Լ���,���Խ����ϵ�n��Ԫ�غ����
 */

/*
3��ħ��ʾ��ͼ:
    8  1  6
    3  5  7
    4  9  2
*/


/*
ħ����Ĵ�Ź���:
    ������1���ڵ�һ�е��м�һ��
    ������2��ʼ��n��ƽ������,��ŵķ�������:
    ��һ�����ַ���ǰһ�����ֵ�ǰһ�У���һ��
    ��:����2���ڵ�һ�е�ǰһ�м�n�У���һ��n/2+1��
    �����������Ĺ���ȷ����λ�����Ѿ��������֣�����һ�����ǵ�һ�е�n�У������һ����������һ����������
*/


//��������ħ�����Ŵ���
int odd_matrix()
{
    int ret = 0;
    int matrix_degree;
    printf("Please input a number what in range of (1,15) and it must be a odd");
    scanf("%d", &matrix_degree);
    //��������������
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

    //ȷ����һ��Ԫ�صĴ��λ��
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