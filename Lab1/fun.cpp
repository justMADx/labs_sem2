#include "fun.h"
#include <iostream>
namespace fun
{
    void swap_pointer(int* ta, int* tb) {
        int tmp = *ta;
        *ta = *tb;
        *tb = tmp;
        std::cout << "Result of swap_pointer: " << std::endl << *ta << " " << *tb;
    }
    void swap_link(int& ta, int& tb) {
        int tmp = ta;
        ta = tb;
        tb = tmp;
        std::cout << "Result of swap_reference: " << std::endl << ta << " " << tb;
    }
    void killfraction_pointer(float* ta) {
        int fr = (int)*ta;
        std::cout << "Number without fraction (pointer): " << std::endl << fr << std::endl;
    }
    void killfraction_link(float& ta) {
        int fr = (int)ta;
        std::cout << "Number without fraction (reference): " << std::endl << fr << std::endl;
    }
    void multiply_link(std::complex<double>& a, float mul) {
        a *= mul;
        std::cout << "Result of multiply_reference: " << std::endl << a << std::endl;
    }
    void multiply_pointer(std::complex<double>* a, float mul) {
        std::complex<double>tmp;
        *a *= mul;
        std::cout << "Result of multiply_pointer: " << std::endl << *a << std::endl;
    }

    void move_circle_link(struct circle& loop, double x, double y) {
        loop.x_c += x;
        loop.y_c += y;
        std::cout << "New circle location(reference): " << std::endl << "(" << loop.x_c << "," << loop.y_c << ")" << std::endl;
    }
    void move_circle_pointer(struct circle* loop, double x, double y) {
        loop->x_c += x;
        loop->y_c += y;
        std::cout << "New circle location(pointer): " << std::endl << "(" << loop->x_c << "," << loop->y_c << ")";
    }
}