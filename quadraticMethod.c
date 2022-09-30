#include <stdio.h>
#include <math.h>

int main()
{
  int a, b, c;
  float d, r1, r2;
  printf("Enter the cefficients in descending order of power.\n");
  scanf("%d%d%d",&a,&b,&c);
  d = b*b-4*a*c;
  if (d > 0)
  {
    printf("The roots are real and different.\n");
    r1 = (-b + pow(d, 0.5))/2*a;
    r2 = (-b - pow(d, 0.5))/2*a;
    printf("First root: %f and Second root: %f.\n",r1, r2);
  }
  else if (d == 0)
  {
    printf("The roots are real and same.\n");
    r1 = (-b + pow(d, 0.5))/2*a;
    printf("Root: %f.\n",r1);
  }
  else printf("The roots are imaginary.\n");
}
