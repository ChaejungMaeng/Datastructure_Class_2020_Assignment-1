

//  Multiply_sparse.c
//  Datastructure2020
//
//  Created by 맹채정 on 2020/4/1.
//  Copyright © 2020 맹채정. All rights reserved.
//
#include <stdio.h>


#include<stdio.h>
#include<stdlib.h>
#define MAX 100

typedef struct
{
            int row;
            int col;
            int val;
}sparse;


void readsparse(sparse a[], int m, int n)
{
            int i, j, k, item, p;
            a[0].row = m;
            a[0].col = n;
            k = 1;

            printf("\nEnter the elements:\n");
            for(i=1; i<=m; i++)
            {
                        for(j=1; j<=n; j++)
                        {
                                    scanf("%d",&item);
                                    if(item == 0)
                                                continue;
                                    a[k].row = i;
                                    a[k].col = j;
                                    a[k].val = item;
                                    k++;
                        }
            }
            a[0].val = k-1;

            printf("\nThe entered sparse matrix is:\n");
            printf("\nRow\tColumn\tValue\n");

            for(p=1;  p<=a[0].val;  p++)
            {
                        printf("%d\t", a[p].row);
                        printf("%d\t", a[p].col);
                        printf("%d\n", a[p].val);
            }

            printf("\n");
            printf("Shape of Original matrix : \n");

         //   for(x=1; x<a[0].row;  x++){
                for(p=1;  p<=a[0].col;  p++)
                    printf("%d\t", a[p].val);
                printf("\n");

                for(p=a[0].col+1;  p<=a[0].col*2;  p++)
                    printf("%d\t", a[p].val);
                printf("\n");

                if(a[0].row>=3){
                    for(p=a[0].col*2+1;  p<=a[0].col*3;  p++)
                        printf("%d\t", a[p].val);
                    printf("\n");
                }

}

void fast_transpose(sparse a[],  sparse b[])
{
            int row_terms[100],  start_pos[100];
            int i,  j,  p;

            int numTerms = a[0].val;
            int numCols = a[0].col;


            b[0].row = numCols;
            b[0].col = a[0].row;
            b[0].val = numTerms;

            if(numTerms>0)
            {
                        for(i =0; i<numCols;  i++)
                                                row_terms[i] = 0;

                        for(i=1; i<=numTerms; i++)
                                                row_terms[a[i].col]++;

                        start_pos[0]=0;

                        for(i=1; i<numCols; i++)
                                                start_pos[i] = start_pos[i-1] + row_terms[i];

                        for(i=1; i<=numTerms; i++)
                        {
                                                j = start_pos[a[i].col]++;
                                                b[j].row = a[i].col;
                                                b[j].col = a[i].row;
                                                b[j].val = a[i].val;
                        }

             }
            printf("\nThe Fast Transpose sparse matrix is:\n");
            printf("\nRow\tColumn\tValue\n");

            for(p=0; p<a[0].val; p++)
            {
                        printf("%d\t", b[p].row);
                        printf("%d\t", b[p].col);
                        printf("%d\n", b[p].val);
            }


            printf("\n");


}

void storeSum(sparse d[], int* totalD, int row1, int column1, int* sum) {
    if (*sum)
        if (*totalD < MAX) {
            d[*totalD].row = row1;
            d[*totalD].col = column1;
            d[*totalD].val = *sum;
            *sum = 0;
        }
        else {
            fprintf(stderr, "Numbers of %d\n", MAX);
            exit(EXIT_FAILURE);
        }
    else {
        exit(EXIT_FAILURE);
    }
}

void multiply(sparse a[], sparse b[], sparse d[], sparse newB[]) {
    int i, j, column, r;
    int totalB = b[0].val;
    int totalD = 0;
    int rowsA = a[0].row;
    int colsA = a[0].col;
    int totalA = a[0].val;
    int colsB = b[0].col;

    int rowBegin = 1, row = a[1].row, sum = 0;

    // int newB[MAX];

    if (colsA != b[0].row) {
        fprintf(stderr, "Incompatible");
        exit(EXIT_FAILURE);
    }

    fast_transpose(b, newB);

    a[totalA + 1].row = rowsA;
    newB[totalB + 1].row = colsB;

    newB[totalB + 1].col = 0;


    for (i = 1; i <= totalA; i++) {

        column = newB[1].row;

        for (j = 1; j <= totalB + 1; j++) {
            if (a[i].row != row) {
                storeSum(d, &totalD, row, column, &sum);
                i = rowBegin;
                for (j = 0; newB[j].row == column; j++)
                    column = newB[j].row;
            }
            else if (newB[j].row == column) {
                storeSum(d, &totalD, row, column, &sum);
                i = rowBegin;
                column = newB[j].row;
            }
            else
                if (a[i].col < newB[j].col) {
                    i++;
                }
            if (a[i].col == newB[j].col) {
                sum += (a[i++].val * newB[j++].val);
            }
            if (a[i].col > newB[j].col) {
                j++;
            }

        }
        for (i = 0; a[i].row == row; i++)
            rowBegin = i; row = a[i].row;
    }
    d[0].row = rowsA;
    d[0].col = colsB;
    d[0].val = totalD;


    for (r = 0; r < d[0].val; r++)
    {
        printf("%d\t", newB[r].row);
        printf("%d\t", newB[r].col);
        printf("%d\n", newB[r].val);
    }
}



int main()
{
    int m, n, totalD, sum;
    int row1, column1;


    sparse a[MAX], b[MAX], d[MAX], newB[MAX];
    printf("\nEnter  the number of rows and columns:\t");
    scanf("%d%d", &m, &n);

    readsparse(a, m, n);
    fast_transpose(a, b);
    storeSum(d, &totalD, row1, column1, &sum);
    multiply(a, b, d, newB);
    return 0;

}
