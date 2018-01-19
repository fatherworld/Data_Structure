#include<stdio.h>
#include<stdlib.h>
#include<string>
#define MAX_TERMS 100

typedef struct 
{
    float coef;
    int expon;
} polynomial;

polynomial terms[MAX_TERMS];
int avial = 0;


int COMPARE(int coef1, int coef2)
{
    if (coef1 < coef2)
        return -1;
    else if (coef1 == coef2)
        return 0;
    else
        return 1;
}


int padd(polynomial * left, int left_leng, polynomial* right, int right_leng)
{
   int ret = 0;
   polynomial * pResult = (polynomial*)malloc(sizeof(polynomial)*(right_leng + left_leng));
//   polynomial * pResult = left;
   int count = 0;
   bool leftSmall = false;
   bool rightSmall = false;
   bool equal = false;
   int j = 0;
   int i = 0;
   for (; i < left_leng; i++)
   {
       for (; j < right_leng; j++)
       {
           int sw = COMPARE(left[i].expon, right[j].expon);
           switch (sw)
           {
                 case 0:
                     pResult[count].expon = left[i].expon;
                     pResult[count].coef = left[i].coef + right[j].coef;
                     count++;
                     equal = true;
                     break;
                 case -1:
                     leftSmall = true;
                     break;
                 case 1:
                     rightSmall =  true;
                     break;
           }
           if (rightSmall)
           {
                pResult[count].expon = left[i].expon;
                pResult[count].coef = left[i].coef;
                count++;
                rightSmall = false;
                break;
           }
           if(leftSmall)
           {
               pResult[count].expon = right[j].expon;
               pResult[count].coef =  right[j].coef;
               count++;
               leftSmall = false;
           }
           if (equal)
           {
               break;
           }
       }
       if (equal)
       {
           j++;
       }
       if (j == right_leng)
       {
           if (equal)
           {
               i++;
           }
           break;
       }
       equal = false;
   }

   if (i < left_leng)
   {
       for (int k = 0; k < left_leng - i; k++)
       {
           pResult[k + count ].coef = left[i + k].coef;
           pResult[k + count ].expon = left[i+ k].expon;
      }
       count += left_leng - i;
   }
   if (j < right_leng)
   {
       for (int k = 0; k < right_leng - j; k++)
       {
           pResult[k + count].coef = right[k+j].coef;
           pResult[k + count].expon = right[k+j].expon;
       }
       count += right_leng - j;
   }
   for (int i = 0; i < count; i++)
   {
       printf("result of coef is  %f", pResult[i].coef);
       printf("result of expon is  %d \n", pResult[i].expon);
   }
   return ret;
}

int main()
{
    int ret = 0;

    polynomial * left = (polynomial*)malloc(sizeof(polynomial) * 6);

    polynomial * right = (polynomial*)malloc(sizeof(polynomial) * 6);

    for (int i = 0; i < 6; i++)
    {
        left[i].coef = 9 - i;
        left[i].expon = 10 - i;
        right[i].coef = 23 - i;
        right[i].expon = 19 - i;
    }

    ret = padd(left, 6, right,6);
    return ret;
}