#include <stdio.h>

float f(float x, float y)
{ return (x+y); }

int main()
{
    float x, y, h, target, temp;
    int n;
    printf("Enter the initial condition of x and Y.\n");
    scanf("%f%f",&x,&y);
    printf("Enter the number of intervals.\n");
    scanf("%d",&n);
    printf("Enter the value of x at which you want to calculate y.\n");
    scanf("%f",&target);
    h = (target)/(n*1.0);
    target = target - x*h;
    while (x < target)
    {
      if (x < target) printf("X: %f and Y: %f.\n",x,y);
      y = y + h * f(x, y);
      x += h;
    }
}
