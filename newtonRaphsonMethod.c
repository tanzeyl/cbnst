#include <stdio.h>
#include <math.h>

void findDerivative(int [], int [], int [], int [], int);
float calculateValue(int [], int [], int, float);
void printPoly(int [], int [], int);

int main()
{
    int terms, i, prev, current, approx;
    float valZero, value, x, dervValue;
    printf("Enter the number of terms in the equation.\n");
    scanf("%d",&terms);
    int polyPower[terms], polyCoeffs[terms], dervPower[terms], dervCoeffs[terms];
    printf("Enter the powers starting from the left.\n");
    for (i=0; i<terms; i++)
    { scanf("%d",&polyPower[i]); }
    printf("Enter the corresponding coefficients.\n");
    for (i=0; i<terms; i++)
    { scanf("%d",&polyCoeffs[i]); }
    findDerivative(polyPower, polyCoeffs, dervPower, dervCoeffs, terms);
    printf("The equation is:\n");
    printPoly(polyPower, polyCoeffs, terms);
    printf("\nThe derivative is:\n");
    printPoly(dervPower, dervCoeffs, terms);
    valZero = calculateValue(polyPower, polyCoeffs, terms, 0);
    value = calculateValue(polyPower, polyCoeffs, terms, 1);
    i = 2;
    if (valZero * value < 0)
    { x = 0.5; }
    else
    {
        while (valZero * value > 0)
        {
            value = calculateValue(polyPower, polyCoeffs, terms, i);
            prev = i-1; current = i; i++;
        }
        x = (prev + current)/2.0;
    }
    printf("\nEnter the number of approximations.\n");
    scanf("%d",&approx);
    for (i=0; i<approx; i++)
    {
        value = calculateValue(polyPower, polyCoeffs, terms, x);
        dervValue = calculateValue(dervPower, dervCoeffs, terms, x);
        x = x - (value/dervValue);
        printf("The approximated root at iteration number %d is %f.\n", i+1, x);
    }
}

void findDerivative(int polyPower[], int polyCoeffs[], int dervPower[], int dervCoeffs[], int terms)
{
    int i;
    for (i=0; i<terms; i++)
    {
        dervPower[i] = (polyPower[i] == 0) ? 0 : polyPower[i] - 1;
        dervCoeffs[i] = polyCoeffs[i] * polyPower[i];
    }
}

float calculateValue(int power[], int coeffs[], int terms, float x)
{
    float result = 0;
    int i;
    for (i=0; i<terms; i++)
    { result += coeffs[i] * pow(x, power[i]); }
    return result;
}

void printPoly(int power[], int coeffs[], int terms)
{
  int i;
  for (i=0; i<terms; i++)
  {
    if (coeffs[i] == 0 && power[i] == 0) continue;
    if (coeffs[i] != 1) { printf("%d",coeffs[i]); }
    printf("x^%d",power[i]);
    if (i < terms-1 && coeffs[i+1] > 0) { printf("+"); }
  }
}
