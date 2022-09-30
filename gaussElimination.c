#include <stdio.h>

void printAugmentedMatrix(float [3][4]);
void rowTransformToUTM(float [3][4]);
void printEquations(float [3][4]);

int main()
{
    float augmented[3][4], x, y, z;
    int i, j;
    for (i=0; i<3; i++)
    {
        printf("Enter the coefficients of X, Y and Z and the constant in equation %d.\n", i+1);
        for (j=0; j<4; j++) { scanf("%f",&augmented[i][j]); }
    }
    printAugmentedMatrix(augmented);
    rowTransformToUTM(augmented);
    printf("The equations after row transformations are:\n");
    printEquations(augmented);
    z = augmented[2][3]/augmented[2][2];
    y = (augmented[1][3]-(augmented[1][2]*z))/augmented[1][1];
    x = (augmented[0][3]-(augmented[0][2]*z)-(augmented[0][1]*y))/augmented[0][0];
    printf("The roots of these equations are: X = %0.1f, Y = %0.1f and Z = %0.1f.\n", x, y, z);
}

void printAugmentedMatrix(float augmented[3][4])
{
    int i, j;
    printf("The augemented matrix is:\n");
    for (i=0; i<3; i++)
    {
        for (j=0; j<4; j++)
        {
            printf("%0.0f\t",augmented[i][j]);
            if (j == 2) { printf(":\t"); }
        }
        printf("\n");
    }

}

void rowTransformToUTM(float augmented[3][4])
{
    int j;
    float denom;
    denom = augmented[1][0]/augmented[0][0];
    for (j=0; j<4; j++)
    { augmented[1][j] -= denom*augmented[0][j]; }
    denom = augmented[2][0]/augmented[0][0];
    for (j=0; j<4; j++)
    { augmented[2][j] -= denom*augmented[0][j]; }
    denom = augmented[2][1]/augmented[1][1];
    for (j=0; j<4; j++)
    { augmented[2][j] -= denom*augmented[1][j]; }
}

void printEquations(float augmented[3][4])
{
    int i, j;
    for (i=0; i<3; i++)
    {
        for (j=0; j<4; j++)
        {
            if (augmented[i][j] != 0)
            {
                if (j == 0) { printf("%0.1fX+", augmented[i][j]); }
                else if (j == 1) { printf("%0.1fY+", augmented[i][j]); }
                else if (j == 2) { printf("%0.1fZ=", augmented[i][j]); }
                else if (j == 3) { printf("%0.1f", augmented[i][j]); }
            }
        }
        printf("\n");
    }
}
