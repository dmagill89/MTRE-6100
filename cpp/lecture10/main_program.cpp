#include <iostream>
#include "custom_classes.h"

int main(int argc, char ** argv){
    // std::cout << "We Are In Out Main Program" << std::endl;
    // Shape object1;
    // Shape object2(2, 3);
    // object1 + object2;
    // Shape object3 = object1 - object2;
    // object3.print_information();
    // Shape object4 = object1 - 10;
    // object4.print_information();
    // Shape object5 = 10 - object1;
    // object5.print_information();

    // std::cout << object5 << std::endl;

    // std::cout << object5.get_private_variable() << std::endl;

    Cube object6(2, 3, 4);
    object6.print_information();
    
    Different object7(2, 3);
    std::cout << object7.x << "," << object7.y << std::endl;

    return 0;
}