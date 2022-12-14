#include <stdio.h>
#include <math.h>
#include <conio.h>

#define f(x,y) (y-x)/(y+x) //the given equation of the problem

int main()
{
    int I;
    
    while(I!=-1 || I>2)
    {
        printf("Enter -1 to Quit \n");
        printf("Enter your Choice 1. Rungekutta Method [R-K-4] 2. Euler's Method \n\n");
        scanf("%d",&I);
        switch(I)
        {
            case 1:
            {
             float x0, y0, xn, h, yn, k1, k2, k3, k4, k;
             int i, n;
             printf("Enter Initial Condition\n");
             printf("x0 = ");
             scanf("%f", &x0);
             printf("y0 = ");
             scanf("%f", &y0);
             printf("Enter Calculation point xn = ");
             scanf("%f", &xn);
             printf("Enter Number of steps: ");
             scanf("%d", &n);

                    h = (xn-x0)/n; // Calculating step size (h) 

             // Runge Kutta Method 
             printf("\nx0\ty0\tyn\n");
             for(i=0; i < n; i++)
             {
               k1 = h * (f(x0, y0));
               k2 = h * (f((x0+h/2), (y0+k1/2)));
               k3 = h * (f((x0+h/2), (y0+k2/2)));
               k4 = h * (f((x0+h), (y0+k3)));
               k = (k1+2*k2+2*k3+k4)/6;
               yn = y0 + k;
               printf("%0.4f\t%0.4f\t%0.4f\n",x0,y0,yn);
               x0 = x0+h;
               y0 = yn;
             }

            // result of the R-K-4
             printf("\nValue of y at x = %0.2f is %0.3f",xn, yn);
             getch();
             return 0;
            }
            // beginning of Euler's Method
             break;
             case 2:
             {
              float x0, y0, xn, h, yn, slope;
              int i, n;
              printf("Enter Initial Condition\n");
              printf("x0 = ");
              scanf("%f", &x0);
              printf("y0 = ");
              scanf("%f", &y0);
              printf("Enter calculation point xn = ");
              scanf("%f", &xn);
              printf("Enter number of steps: ");
              scanf("%d", &n);

              h = (xn-x0)/n; // Calculating step size (h) 

             //Euler's Method Formula
              printf("\nx0\ty0\tslope\tyn\n");
              printf("------------------------------\n");
              for(i=0; i < n; i++)
              {
                 slope = f(x0, y0);
                 yn = y0 + h * slope;
                 printf("%.4f\t%.4f\t%0.4f\t%.4f\n",x0,y0,slope,yn);
                 y0 = yn;
                 x0 = x0+h;
                }

           // result of the Euler's Method 
              printf("\nValue of y at x = %0.2f is %0.3f",xn, yn);

               getch();
               return 0;

             }
             break;
             default:
             printf("Enter a Number Between 1 and 2 \nInvalued Number \nThe program has come to  end");
             
        }
        break;
    }
    return 0;
    getch();
}



