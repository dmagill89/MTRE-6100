#ifndef CUSTOM_CLASSES
#define CUSTOM_CLASSES

#include <iostream>

class Shape {
    public:
        // constructor 
        Shape();
        Shape(int length, int width);
        ~Shape();
        //operator overloading
        void operator+(Shape);
        Shape operator-(Shape);
        int length;
        int width;
        void print_information();
        Shape operator-(int);
        //friend allows non class member access to all class items.
        friend Shape operator-(int, Shape);
        friend std::ostream &operator<<(std::ostream &, Shape);
        int get_private_variable();
    private:
        int private_variable = 100;
    protected:
        int shared_in_inheritance = 70;
};

class Cube : public Shape{
    public:
        int depth;
        Cube();
        Cube(int, int, int);
        void print_information();
        ~Cube();
    private:
    protected:
};

class Different{
    public:
        int x;
        int y;
        Different() : x(0), y(0) {}
        Different(int x_in, int y_in) : x(x_in), y(y_in) {}
};


#endif