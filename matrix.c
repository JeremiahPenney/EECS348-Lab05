#include <stdio.h>
#define MAX 10 //// this is just the maz sizw that will allow for the rows and collums in my matrices

// I used alot of variable names so as You go revert back to this becuz you know you be forgetting shi
// what each letter var mean for later
// a - first m user enter shi in
// b -  2nd m user enter shi in
// d - m used to store result of add m a and b
// m -  m used to store the result of the * m a and b
// t - m used to store the transpose of m a
// r1 num for r in m 1
// c1 - num of c in m1
// r2 - r1 for m2
// c2 - c1 for m2
// i -  will see this when im usingum a loop through r (Make sure you understnad this go back and pratice/ struggle with it ask ta or s)
// j - same as i but for c
// k used in * to move -> r & cs
// temp - BEST VAR NAME AOT but just used to store the running sum when doing m *

// theses are just my function prototypes
void printM(int a[MAX][MAX], int r, int c);
void addM(int a[MAX][MAX], int b[MAX][MAX], int d[MAX][MAX], int r, int c);
void multM(int a[MAX][MAX], int b[MAX][MAX], int d[MAX][MAX], int r1, int c1, int c2);
void transM(int a[MAX][MAX], int t[MAX][MAX], int r, int c);

// This just makes so the func is printed out nice and it will loop through my riws and cilums and print each value

void printM(int a[MAX][MAX], int r, int c)
{
    int i = 0, j;
    while (i < r)
    { // this makes sure we go through each row
        j = 0;
        while (j < c)
        { // go through every collum (c)
            printf("%4d", a[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
}

// this will add two matrixs and it stores the result of that in matrix d

void addM(int a[MAX][MAX], int b[MAX][MAX], int d[MAX][MAX], int r, int c)
{
    int i = 0, j;
    while (i < r)
    {
        j = 0;
        while (j < c)
        {
            d[i][j] = a[i][j] + b[i][j];
            j++;
        }
        i++;
    }
}

// This creates the transpose of da matrix => just means r become c and c become r

void transM(int a[MAX][MAX], int t[MAX][MAX], int r, int c)
{
    int i = 0, j;
    while (i < r)
    {
        j = 0;
        while (j < c)
        {
            t[j][i] = a[i][j]; // looks confusing but it just swap row and column positions (transpose is all that means)
            j++;
        }
        i++;
    }
}

// This just keeps the function with multi two matrices and it uses temp var to keep track of the sums

void multM(int a[MAX][MAX], int b[MAX][MAX], int d[MAX][MAX], int r1, int c1, int c2)
{
    int i = 0, j, k, temp;
    while (i < r1)
    {
        j = 0;
        while (j < c2)
        {
            temp = 0;
            k = 0;
            while (k < c1)
            {
                temp = temp + a[i][k] * b[k][j];
                k++;
            }
            d[i][j] = temp; // will stor the final val in result matrix
            j++;
        }
        i++;
    }
}

// now this part of my code controls i would say the flow of this program
// first it creates matrixes  that will store the users input and the results of various opps
// it will also ask the user to enter the r and c of the matrixs and type val for each of them
// once they are stored it will print both matrixs so the user can see wth was entered and what happened and will do that for multi different opps
// put simply once the it goes through the user input it calls the matrix functions and will output/ show the final results
int main()
{
    int a[MAX][MAX], b[MAX][MAX], d[MAX][MAX], m[MAX][MAX], t[MAX][MAX];
    int r1, c1, r2, c2;
    int i = 0, j;
    //// get the size of m1 from user
    printf("Enter rows and columns for matrix 1: ");
    scanf("%d%d", &r1, &c1);
    //// get the size of m2 from user
    printf("Enter values for matrix 1:\n");
    while (i < r1)
    {
        j = 0;
        while (j < c1)
        {
            scanf("%d", &a[i][j]);
            j++;
        }
        i++;
    }

    printf("Enter rows and columns for matrix 2: ");
    scanf("%d%d", &r2, &c2);

    i = 0;
    printf("Enter values for matrix 2:\n");
    while (i < r2)
    {
        j = 0;
        while (j < c2)
        {
            scanf("%d", &b[i][j]);
            j++;
        }
        i++;
    }

    printf("\nMatrix 1:\n");
    printM(a, r1, c1);

    printf("\nMatrix 2:\n");
    printM(b, r2, c2);
    // create the transpose of matrix 1 (rows become columns)
    // will also print it just think (transpose sh nothing special )
    transM(a, t, r1, c1);
    printf("\nTranspose of Matrix 1:\n");
    printM(t, c1, r1);

    // This just checks to see if the m have the same size so they can be add(one of the opps)
    if (r1 == r2 && c1 == c2)
    {
        addM(a, b, d, r1, c1);
        printf("\nAdded Matrix:\n");
        printM(d, r1, c1);
    }
    else
    {
        printf("\nAddition cannot be done.\n");
    }

    // will check and see if mulip is even possible
    // will see if the c of matrix 1 must be equal ro r of m2
    //=> if it is then its acutally valud ti muliply and will show the result

    if (c1 == r2)
    {
        multM(a, b, m, r1, c1, c2);
        printf("\nMultiplied Matrix:\n");
        printM(m, r1, c2);
    }
    else
    {
        printf("\nMultiplication cannot be done.\n");
    }

    return 0;
}