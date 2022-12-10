#include <stdio.h>
#include <math.h>

float f(float x, float y)
{ return 3.0*pow(2.71828183, x)+2.0*y; }

int main()
{
    float x, y, h, target, temp, k, k1, k2, k3, k4;
    printf("Enter the initial condition of x and Y.\n");
    scanf("%f%f",&x,&y);
    printf("Enter the value of x at which you want to calculate y and the value of h.\n");
    scanf("%f%f",&target,&h);
    while (x <= target)
    {
        k1 = h * f(x, y);
        k2 = h * f(x+h/2, y+k1/2);
        k3 = h * f(x+h/2, y+k2/2);
        k4 = h * f(x+h, y+k3);
        k = 0.166666*(k1+2.0*k2+2.0*k3+k4);
        y += k;
        x += h;
        if (x <= target) printf("X: %f and Y: %f.\n",x,y);
    }
}
