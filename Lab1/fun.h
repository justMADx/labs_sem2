#pragma once
#include <complex>
namespace fun {
    struct circle
    {
        double x_c = 0., y_c = 0.;
    };
    /* struct vec_tor{
         double x1;
         double y1;
     };*/

    void swap_pointer(int*, int*);
    void swap_link(int&, int&);

    void killfraction_pointer(float*);
    void killfraction_link(float&);

    void multiply_link(std::complex<double>&, float);
    void multiply_pointer(std::complex<double>*, float);

    void move_circle_link(struct circle&, double x, double y);
    void move_circle_pointer(struct circle* loop, double x, double y);
}