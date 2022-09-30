#include <stdio.h>
#include <math.h>

float calculateValue(int [], int [], int, float);
void printEquation(int [], int [], int);

int main()
{
    int terms, i, iter;
    float val, val1, val2, x, x1, x2;
    printf("Enter the number of terms in the polynomial.\n");
    scanf("%d",&terms);
    int powers[terms], coeffs[terms];
    printf("Enter the powers in descending order.\n");
    for (i=0; i<terms; i++) { scanf("%d",&powers[i]); }
    printf("Enter the corresponding coefficients.\n");
    for (i=0; i<terms; i++) { scanf("%d",&coeffs[i]); }
    printf("The equation is:\n");
    printEquation(powers, coeffs, terms);
    printf("\n");
    for (i=0; ; i++)
    {
        val1 = calculateValue(powers, coeffs, terms, i);
        val2 = calculateValue(powers, coeffs, terms, i+1);
        if (val1 * val2 < 0) { x1 = i; x2 = i+1; break; }
    }
    printf("Enter the number of iterations.\n");
    scanf("%d",&iter);
    for (i=0; i<iter; i++)
    {
        x = ((x1-x2)*val1)/(val2-val1) + x1;
        val = calculateValue(powers, coeffs, terms, x);
        if (val * val1 > 0) { x1 = x; }
        else if (val * val2 > 0) { x2 = x; }
        printf("The new range of root is: (%f, %f).\n",x1, x2);
        printf("The approximated root in iteration number %d is %f.\n", i+1, x);
    }
}

void printEquation(int powers[], int coeffs[], int terms)
{
    int i;
    for (i=0; i< terms; i++)
    {
        if (coeffs[i] == 0 && powers[i] == 0) continue;
        if (coeffs[i] != 1) { printf("%d", coeffs[i]); }
        printf("x^%d", powers[i]);
        if (i < terms-1 && coeffs[i+1] > 0)
        { printf("+"); }
    }
}

float calculateValue(int powers[], int coeffs[], int terms, float x)
{
    float result = 0;
    int i;
    for (i=0; i<terms; i++)
    { result += coeffs[i] * pow(x, powers[i]); }
    return result;
}
