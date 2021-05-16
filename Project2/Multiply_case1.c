//
//  Multiply.c
//  Datastructure2020
//
//  Created by 맹채정 on 2020/3/31.
//  Copyright © 2020 맹채정. All rights reserved.
//




#include <stdio.h>

int main()
{
    int rows, columns, rows2, columns2;
    int i, j, k, a, b, c, d;
    int sum = 0;

    int first[10][10], second[10][10], multiply[10][10];

    printf("Enter number of rows and columns of First matrix\n");
    scanf_s("%d%d", &rows, &columns);
    printf("Enter elements of First matrix (%d x %d): \n", rows, columns);

    for (i = 0; i < rows; i++)
        for (j = 0; j < columns; j++)
            scanf_s("%d", &first[i][j]);

    printf("Shape of First matrix : \n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++)
            printf("%d\t", first[i][j]);
        printf("\n");
    }



    printf("Enter number of rows and columns of Second matrix\n");
    scanf_s("%d%d", &rows2, &columns2);

    printf("Enter elements of Second matrix (%d x %d): \n", rows2, columns2);

    if (columns != rows2)
        printf("The multiplication isn't possible.\n");
    else
    {

        for (a = 0; a < rows2; a++)
            for (b = 0; b < columns2; b++)
                scanf_s("%d", &second[a][b]);

        for (c = 0; c < rows; c++) {
            for (d = 0; d < columns2; d++) {
                for (k = 0; k < rows2; k++) {
                    sum = sum + first[c][k] * second[k][d];
                }

                multiply[c][d] = sum;
                sum = 0;
            }
        }

        printf("Shape of Second matrix : \n");
        for (i = 0; i < rows2; i++) {
            for (j = 0; j < columns2; j++)
                printf("%d\t", first[i][j]);
            printf("\n");
        }


        printf("Product of the Multiply Matrices:\n");

        for (c = 0; c < rows; c++) {
            for (d = 0; d < columns2; d++)
                printf("%d\t", multiply[c][d]);

            printf("\n");
        }

    }

    return 0;
}
