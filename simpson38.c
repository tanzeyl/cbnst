#include <stdio.h>
#include <math.h>

float calculateFunction(float x)
{ return pow(sin(x), 2); }

int main()
{
    int lower, upper, intervals;
    float h, oddSum = 0, evenSum = 0, result;
    printf("Enter the lower limit, upper limit and the number of intervals.\n");
    scanf("%d%d%d",&lower,&upper,&intervals);

    h = (upper-lower*1.0)/intervals;
    float x[intervals+1], y[intervals+1];
    x[0] = lower+0.0;

    for (int i=1; i<intervals+1; i++)
    { x[i] = x[i-1]+h; }

    for (int i=0; i<intervals+1; i++)
    { y[i] = calculateFunction(x[i]); }

    for (int i=0; i<intervals+1; i++)
    { printf("f(%f) = %f.\n",x[i],y[i]); }

    for (int i=1; i<intervals+1; i++)
    {
        if (i%3==0) continue;
        oddSum += y[i];
    }
    for (int i=3; i<intervals+1; i += 3)
    { evenSum += y[i]; }


    result = (3*h/8)*((y[0] + y[intervals]) + 3*oddSum + 2*evenSum);
    printf("The value of this function in the given limit is: %0.3f.\n",result);
}
