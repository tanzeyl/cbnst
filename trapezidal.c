#include <stdio.h>
#include <math.h>

double calculateFunction(double x)
{ return pow(sin(x), 2); }

int main()
{
    double lowerLimit, upperLimit, intervals;
    printf("Enter the lower limit, upper limit and intervals.\n");
    scanf("%lf%lf%lf",&lowerLimit,&upperLimit,&intervals);
    double sum = 0, result;
    double h = fabs((upperLimit-lowerLimit*1.0)/intervals), x;
    for (int i=1; i<intervals; i++)
    {
        x = lowerLimit + i * h;
        sum += calculateFunction(x);
    }
    result = (h/2) * (calculateFunction(lowerLimit) + calculateFunction(upperLimit) + 2*sum);
    printf("The value of the integral is: %lf.\n",result);
}
