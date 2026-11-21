#include <stdio.h>

#define MAX_TERMS 101
#define MAX_ROWS 20
#define MAX_COLS 20

typedef struct {
    int row;
    int col;
    int value;
} term;

term a[MAX_TERMS], b[MAX_TERMS], c[MAX_TERMS];

/* Simple Transpose */
void simpleTranspose(term a[], term b[])
{
    int i, j, k = 1;

    b[0].row = a[0].col;
    b[0].col = a[0].row;
    b[0].value = a[0].value;

    for (i = 0; i < a[0].col; i++)
    {
        for (j = 1; j <= a[0].value; j++)
        {
            if (a[j].col == i)
            {
                b[k].row = a[j].col;
                b[k].col = a[j].row;
                b[k].value = a[j].value;
                k++;
            }
        }
    }
}

/* Fast Transpose */
void fastTranspose(term a[], term b[])
{
    int rowTerms[MAX_COLS] = {0};
    int startingPos[MAX_COLS];
    int i, j;

    b[0].row = a[0].col;
    b[0].col = a[0].row;
    b[0].value = a[0].value;

    /* Step 1: Count elements in each column */
    for (i = 1; i <= a[0].value; i++)
    {
        rowTerms[a[i].col]++;
    }

    /* Step 2: Find starting position of each row */
    startingPos[0] = 1;

    for (i = 1; i < a[0].col; i++)
    {
        startingPos[i] =
            startingPos[i - 1] + rowTerms[i - 1];
    }

    /* Step 3: Place elements in correct positions */
    for (i = 1; i <= a[0].value; i++)
    {
        j = startingPos[a[i].col]++;

        b[j].row = a[i].col;
        b[j].col = a[i].row;
        b[j].value = a[i].value;
    }
}

/* Display sparse matrix in triplet form */
void display(term a[])
{
    int i;

    printf("\nRow\tColumn\tValue\n");

    for (i = 0; i <= a[0].value; i++)
    {
        printf("%d\t%d\t%d\n",
               a[i].row, a[i].col, a[i].value);
    }
}

int main()
{
    int i, rows, cols, n;

    printf("Enter number of rows and columns: ");
    scanf("%d%d", &rows, &cols);

    if (rows <= 0 || rows > MAX_ROWS ||
        cols <= 0 || cols > MAX_COLS)
    {
        printf("Invalid matrix size\n");
        return 0;
    }

    printf("Enter number of non-zero elements: ");
    scanf("%d", &n);

    if (n < 0 || n > MAX_TERMS - 1)
    {
        printf("Invalid number of elements\n");
        return 0;
    }

    a[0].row = rows;
    a[0].col = cols;
    a[0].value = n;

    printf("Enter row, column and value of each element:\n");

    for (i = 1; i <= n; i++)
    {
        scanf("%d%d%d",
              &a[i].row, &a[i].col, &a[i].value);

        if (a[i].row < 0 || a[i].row >= rows ||
            a[i].col < 0 || a[i].col >= cols ||
            a[i].value == 0)
        {
            printf("Invalid element\n");
            return 0;
        }
    }

    printf("\nOriginal Sparse Matrix:");
    display(a);

    /* Simple Transpose */
    simpleTranspose(a, b);

    printf("\nSimple Transpose:");
    display(b);

    /* Fast Transpose */
    fastTranspose(a, c);

    printf("\nFast Transpose:");
    display(c);

    return 0;
}