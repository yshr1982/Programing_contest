#include <iostream>
#include <stdio.h>
#include "../stack.hpp"


// Implement three stack with one array. 
// Array size is 1000

#define STACK_SIZE_1    300
#define STACK_SIZE_2    400
#define STACK_SIZE_3    300
#define SIZE_ARRAY      (STACK_SIZE_1 + STACK_SIZE_2 + STACK_SIZE_3)
#define ERROR_CODE 99999


#define LIST_NUM (10)
#define MAX_NUMBER_1 (20)
#define MAX_NUMBER_2 (15)
#define MAX_NUMBER_3 (5)

class StackOneArray{
    int *top;
    int index;
    int max;
public:
    StackOneArray(int *data,int size){
        this->top = data;
        this->index = size;
        this->max = size;
    }
    int pop(void){
        int ret;
        if(this->top == NULL){return -ERROR_CODE;}
        if(this->index >= this->max){return -ERROR_CODE;}

        ret = this->top[this->index];
        this->index++;
        return ret;
    }
    void push(int data){
        if(this->top == NULL){return ;}
        if(this->index - 1 < 0){return;}
        this->index--;
        this->top[this->index] = data;
    }
    int peek(void){
        if(this->top == NULL){return -ERROR_CODE;}
        if(this->index >= this->max){return -ERROR_CODE;}
        return this->top[this->index];
    }
};


struct stack_info{
    int offset;
    int stact_size;
};

struct stack_info info[3] = {
    {0                              ,   STACK_SIZE_1 },
    {STACK_SIZE_1                   ,   STACK_SIZE_2 },
    {STACK_SIZE_1 + STACK_SIZE_2    ,   STACK_SIZE_3 }
};

int main(void){
    unsigned int node_num = 0;
    int *array;
    class StackOneArray *stack[3];

    array = new int[SIZE_ARRAY];
    for(unsigned int iter = 0 ; iter < 3 ; iter ++){
        stack[iter] = new class StackOneArray(&array[info[iter].offset],info[iter].stact_size);
    }

    for(unsigned int iter = 0 ; iter < LIST_NUM ; iter++){
        stack[0]->push((rand() % MAX_NUMBER_1 + 1));
        stack[1]->push((rand() % MAX_NUMBER_2 + 1));
        stack[2]->push((rand() % MAX_NUMBER_3 + 1));
    }

    for(unsigned int j = 0 ; j < 3 ; j++){
        for(unsigned int iter = 0 ; iter < LIST_NUM ; iter++){
            std::cout << "index " << iter << " : " << stack[j]->pop() << std::endl;
        }
    }

    delete[] array;


    return 0;
}