#include <stdio.h>
#include <math.h>

float calculateValue(int [], int [], int, float);
void printPoly(int [], int [], int);

int main()
{
    int terms, i, prev, current, approx;
    float val1, val2, x1, x2, x, val;
    printf("Enter the number of terms in the equation.\n");
    scanf("%d",&terms);
    int polyPower[terms], polyCoeffs[terms];
    printf("Enter the powers starting from the left.\n");
    for (i=0; i<terms; i++)
    { scanf("%d",&polyPower[i]); }
    printf("Enter the corresponding coefficients.\n");
    for (i=0; i<terms; i++)
    { scanf("%d",&polyCoeffs[i]); }
    printf("The equation is:\n");
    printPoly(polyPower, polyCoeffs, terms);
    for (i=0; ; i++)
    {
        val1 = calculateValue(polyPower, polyCoeffs, terms, i);
        val2 = calculateValue(polyPower, polyCoeffs, terms, i+1);
        if (val1 * val2 < 0) { x1 = i; x2 = i+1; break; }
    }
    printf("\nEnter the number of approximations.\n");
    scanf("%d",&approx);
    for (i=0; i<approx; i++)
    {
      x = (x1+x2)/2.0;
      val = calculateValue(polyPower, polyCoeffs, terms, x);
      if (val * val1 > 0) { x1 = x; }
      else if (val * val2 > 0) { x2 = x; }
      printf("The new range of root is: (%f, %f).\n",x1, x2);
      printf("The approximated root in iteration number %d is %f.\n", i+1, x);
    }
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

float calculateValue(int power[], int coeffs[], int terms, float x)
{
    float result = 0;
    int i;
    for (i=0; i<terms; i++)
    { result += coeffs[i] * pow(x, power[i]); }
    return result;
}
