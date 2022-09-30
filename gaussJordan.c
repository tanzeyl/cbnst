#include <stdio.h>

void printAugmentedMatrix(float [3][4]);
void rowTransformToUTM(float [3][4]);
void printEquations(float [3][4]);
float extractCoeff(char [], float [3][4], int);

int main()
{
    char equnX[20], equnY[20], equnZ[20];
    float augmented[3][4], x, y, z, temp;
    int i = 0, j = 0;
    printf("Enter the equations without spaces in between:\n");
    scanf("%s",equnX); fflush(stdin);
    scanf("%s",equnY); fflush(stdin);
    scanf("%s",equnZ); fflush(stdin);
    extractCoeff(equnX, augmented, 0);
    extractCoeff(equnY, augmented, 1);
    extractCoeff(equnZ, augmented, 2);
    printf("The augemented matrix is:\n");
    printAugmentedMatrix(augmented);
    rowTransformToUTM(augmented);
    printf("The diagonal matrix is:\n");
    printAugmentedMatrix(augmented);
    printf("The equations after row transformations are:\n");
    printEquations(augmented);
    z = augmented[2][3]/augmented[2][2];
    y = augmented[1][3]/augmented[1][1];
    x = augmented[0][3]/augmented[0][0];
    printf("The roots of these equations are: X = %0.1f, Y = %0.1f and Z = %0.1f.\n", x, y, z);
}

void printAugmentedMatrix(float augmented[3][4])
{
    int i, j;
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
    denom = augmented[0][1]/augmented[1][1];
    for (j=0; j<4; j++)
    { augmented[0][j] -= denom*augmented[1][j]; }
    denom = augmented[1][2]/augmented[2][2];
    for (j=0; j<4; j++)
    { augmented[1][j] -= denom*augmented[2][j]; }
    denom = augmented[0][2]/augmented[2][2];
    for (j=0; j<4; j++)
    { augmented[0][j] -= denom*augmented[2][j]; }
}

void printEquations(float augmented[3][4])
{
  printf("%0.1fX = %0.1f\n",augmented[0][0], augmented[0][3]);
  printf("%0.1fY = %0.1f\n",augmented[1][1], augmented[1][3]);
  printf("%0.1fZ = %0.1f\n",augmented[2][2], augmented[2][3]);
}

float extractCoeff(char equation[], float augmented[3][4], int row)
{
    float temp = 0;
    int i = 0, j = 0, k, flag = 0;
    while (equation[i] != '\0')
    {
        if ((equation[i] == 'x' || equation[i] == 'X' || equation[i] == 'y' || equation[i] == 'Y' ||
              equation[i] == 'z' || equation[i] == 'Z') && (equation[i-1] < 48 || equation[i-1] > 57))
          {
            augmented[row][j] = 1;
            j++;
          }
        else if (equation[i] >= 48 && equation[i] <= 57)
        {
            k = i;
            while (equation[k] >= 48 && equation[k] <= 57)
            {
                temp = temp * 10.0 + ((float)equation[k]-48.0);
                k++;
            }
            if (i != 0 && equation[i-1] == '-') temp = temp * -1;
            augmented[row][j] = temp;
            temp = 0;
            j++;
        }
        i++;
    }
}
