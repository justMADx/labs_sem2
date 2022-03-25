#include <iostream>
#include <complex>
#include "fun.h"
using namespace std;
using namespace fun;

int main()
{
    /* //first task
     int a,b;
     cout<<"First for swap: ";
     cin>>a;
     cout<<"Second for swap: ";
     cin>>b;
        swap_pointer(&a,&b);
        swap_link(a,b);*/
        /* //secondtask
         float a;
         a=7.6;
         float b=3.9;
         killfraction_pointer(&a);
         killfraction_link(b);
             //3task
             double re,im;
             float mul;
             cin>>re>>im>>mul;
             complex<double>a(re,im);
             multiply_link(a,mul);
             multiply_pointer(&a,&mul);*/

             //4task
             circle loop;
             double x = 2,y = 3;

               move_circle_link(loop,x,y);
               move_circle_pointer(&loop, x, y);
    return 0;
}
