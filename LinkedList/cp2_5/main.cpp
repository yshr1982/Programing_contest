#include <iostream>
#include <stdio.h>
#include "../link.hpp"

#define LIST_NUM (10)
#define MAX_NUMBER (20)

int main(void){
    class my_NodeList temp;

    // Create a list filled with random numbers.
    for(unsigned int iter = 0 ; iter < LIST_NUM ; iter++){
        temp.apendToTail((rand() % MAX_NUMBER + 1));
    }
    temp.show();
    std::cout << "-----------------" << std::endl;
    
    temp.sortNode(20);
    temp.show();


    return 0;
}