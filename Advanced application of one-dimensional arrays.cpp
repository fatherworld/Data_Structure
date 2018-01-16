#pragma warning(disable:4996)
#include "stdio.h"
#include "stdlib.h"
#define DataLeng 100
void main()
{
    int Data[DataLeng] = { 0 };
    int Digit;
    int i, j, r, k;
    int N;
//     for (int i = 0; i < 40; i++)
//         Data[i] = 0;
    Data[0] = 1;
    Data[1] = 1;
    Digit = 1;
    printf("Enter a number what you want to calculus: ");
    scanf("%d", &N);
    for (int i = 1; i < N + 1; i++)
    {
        for (int j = 1; j < Digit + 1; j++)
        {
            Data[j] *= i;
        }
        for (int j = 1; j < Digit + 1; j++)
        {
            if (Data[j] > 10)
            {
                for (r = 1; r < Digit+1; r++)
                {
                    if (Data[Digit] > 10)
                        Digit++;
                    Data[r + 1] += Data[r] / 10;
                    Data[r] = Data[r] % 10;
                }
            }
        }
        printf("%d != ", i);
        for (k = Digit; k > 0; k--)
        {
            printf("%d", Data[k]);
        }
        printf("\n");
    }
    system("pause");
}