#include <iostream>
#include <stdio.h>
#include "../tree.hpp"

#define MAX_NUMBER    100
#define LIST_NUM (10)


int main(void){
    class Tree tree;
    unsigned int key;

    for(unsigned int iter = 0 ; iter < LIST_NUM ; iter++){
        key = (rand() % MAX_NUMBER + 1);
        tree.insert(key);
        std::cout << key << " "<< std::endl;
    }
    tree.print();


    return 0;
}