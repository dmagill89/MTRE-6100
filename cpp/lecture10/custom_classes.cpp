#include "custom_classes.h"

Shape::Shape(){
    std::cout << "Object Default Constructor Called" << std::endl;
    length = 1;
    width = 1;
}

Shape::Shape(int l, int w){
    std::cout << "Object Overloaded Constructor Called" << std::endl;
    length = l;
    width = w;
}

Shape::~Shape(){
    std::cout << "Object Destructor Called" << std::endl;
}

//RHS = Right Hand Side of the operator
void Shape::operator+(Shape RHS){
    std::cout << "You tried to add the objects together, which is not allowed" << std::endl;
}

Shape Shape::operator-(Shape RHS){
    Shape tmp_shape_object;
    tmp_shape_object.length = this->length - RHS.length;
    tmp_shape_object.width = this->width - RHS.width;
    return tmp_shape_object;
}

Shape Shape::operator-(int RHS){
    Shape tmp_shape_object;
    tmp_shape_object.length = this->length - RHS;
    return tmp_shape_object;
}

void Shape::print_information(){
    std::cout << "Length: " << length << " Width: " << width << std::endl;
}

Shape operator-(int LHS, Shape RHS){
    Shape tmp_shape_object;
    tmp_shape_object.width = LHS - RHS.width;
    return tmp_shape_object;
}

std::ostream &operator<<(std::ostream &out, Shape RHS){
    return out << "Length: " << RHS.length << " Width: " << RHS.width << std::endl;
}

int Shape::get_private_variable(){
    return private_variable;
}

void Cube::print_information(){
    std::cout << "Length: " << length 
              << " Width: " << width 
              << " Depth: " << depth 
              << std::endl;
}

Cube::Cube(){
    depth = 1;
}

Cube::Cube(int l, int w, int d){
    std::cout << "Cube Overloaded Constructor Called" << std::endl;
    length = l;
    width = w;
    depth = d;
}

Cube::~Cube(){
    std::cout << "Cube Destructor Called" << std::endl;    
}