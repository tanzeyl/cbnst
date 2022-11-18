#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int findClosest(int [], int, int, int *);
void findDeltas(int [], float [], int, int);

int main()
{
    int n, target, a, h, fa;
    float u, interpolation;
    printf("Enter the number of values.\n");
    scanf("%d",&n);
    int x[n], deltas[n-1];
    float y[n];
    printf("Enter the values of all the Xs.\n");
    for (int i=0; i<n; i++) scanf("%d",&x[i]);
    printf("Enter the values of all the Ys.\n");
    for (int i=0; i<n; i++) scanf("%f",&y[i]);
    printf("Enter the value of X you want to calculate.\n");
    scanf("%d",&target);
    a = findClosest(x, target, n, &fa);
    h = x[1] - x[0];
    u = (target-a)/(h+0.0);
    printf("Pivot value: %d, H = %d and U = %0.3f.\n",a, h, u);
    findDeltas(deltas, y, n, fa);
    interpolation = y[fa] + u * deltas[0] + u*(u-1)/2*deltas[1] + u*(u-1)*(u-2)/6*deltas[2] + u*(u-1)*(u-2)*(u-3)/24*deltas[3];
    printf("The approximated value at %d is %0.4f.\n",target,interpolation);
}

int findClosest(int x[], int target, int n, int *fa)
{
    int min = INT_MAX, index;
    for (int i=0; i<n; i++)
    { if (abs(x[i]-target) < min) { min = abs(x[i]-target); index = i; } }
    *fa = index;
    return x[index];
}

void findDeltas(int deltas[], float y[], int n, int fa)
{
    int temp[n-1], count = n-1, k = 2, j = 1;
    for (int i=0; i<n-1; i++)
    { temp[i] = y[i+1]-y[i]; }
    deltas[0] = temp[fa];
    while (--count)
    {
        for (int i=0; i<n-k; i++)
        { temp[i] = temp[i+1]-temp[i]; }
        deltas[j] = temp[fa];
        j++; k++;
    }
}
