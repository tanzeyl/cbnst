#include <stdio.h>

int main()
{
    int n;
    float target, result = 0;
    printf("Enter the number of terms.\n");
    scanf("%d",&n);
    float x[n], y[n], numr[n], denom[n];
    for (int i=0; i<n; i++) { numr [i] = 1; denom[i] = 1; }
    printf("Enter all the Xs.\n");
    for (int i=0; i<n; i++) scanf("%f",&x[i]);
    printf("Enter all the respective Ys.\n");
    for (int i=0; i<n; i++) scanf("%f",&y[i]);
    printf("Enter the target X.\n");
    scanf("%f",&target);
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            if (i == j) continue;
            numr[i] *= (target-x[j]);
        }
        numr[i] *= y[i];
    }
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            if (i == j) continue;
            denom[i] *= (x[i] - x[j]);
        }
    }
    for (int i=0; i<n; i++)
    { result += numr[i]/denom[i]; }
    printf("The value of Y at X = %f is: %f.\n",target, result);
}
