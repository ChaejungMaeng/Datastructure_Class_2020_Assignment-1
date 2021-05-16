//Transpose_case1.c

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
    int i, j, k, item, p, x;
    a[0].row = m;
    a[0].col = n;
    k = 1;

    printf("\nEnter the elements:\n");
    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &item);
            if (item == 0)
                continue;
            a[k].row = i;
            a[k].col = j;
            a[k].val = item;
            k++;
        }
    }
    a[0].val = k - 1;

    printf("\nThe entered sparse matrix is:\n");
    printf("\nRow\tColumn\tValue\n");

    for (p = 1; p <= a[0].val; p++)
    {
        printf("%d\t", a[p].row);
        printf("%d\t", a[p].col);
        printf("%d\n", a[p].val);
    }

    printf("\n");
    printf("Shape of Original matrix : \n");

    for (p = 1; p <= a[0].col; p++)
        printf("%d\t", a[p].val);
    printf("\n");

    for (p = a[0].col + 1; p <= a[0].col * 2; p++)
        printf("%d\t", a[p].val);
    printf("\n");

    if (a[0].row >= 3) {
        for (p = a[0].col * 2 + 1; p <= a[0].col * 3; p++)
            printf("%d\t", a[p].val);
        printf("\n");
    }

}

void transpose(sparse a[], sparse b[])
{
    int row_terms[100], start_pos[100];
    int i, j, p, currentb;

    int numTerms = a[0].val;
    int numCols = a[0].col;


    b[0].row = numCols;
    b[0].col = a[0].row;
    b[0].val = numTerms;

    if (numTerms > 0)
    {
        currentb = 0;

        for (i = 0; i <= a[0].col; i++)
            for (j = 1; j <= numTerms; j++)
                if (a[j - 1].col == i) {
                    b[currentb].row = a[j].col;
                    b[currentb].col = a[j].row;
                    b[currentb].val = a[j].val;
                    currentb++;
                }

    }
    printf("\nThe Transpose sparse matrix is:\n");
    printf("\nRow\tColumn\tValue\n");

    for (p = 0; p < a[0].val; p++)
    {
        printf("%d\t", b[p].row);
        printf("%d\t", b[p].col);
        printf("%d\n", b[p].val);
    }


    printf("\n");
    //      printf("Shape of Transpose matrix : \n");

}

void main()
{
    int m, n;


    sparse a[MAX], b[MAX];
    printf("\nEnter  the number of rows and columns:\t");
    scanf("%d%d", &m, &n);

    readsparse(a, m, n);
    transpose(a, b);


}


