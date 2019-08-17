#include <iostream>
#include <stdio.h>
#include "../stack.hpp"


// Implement three stack with one array. 
// Array size is 1000
#define STACK_SIZE_1    300
#define STACK_SIZE_2    400
#define STACK_SIZE_3    300
#define SIZE_ARRAY      (STACK_SIZE_1 + STACK_SIZE_2 + STACK_SIZE_3)

#define LIST_NUM (10)
#define MAX_NUMBER_1 (20)
#define MAX_NUMBER_2 (15)
#define MAX_NUMBER_3 (5)

class StackOneArray{
    Node *top;
    Stack min_data;
public:
    StackOneArray(){
        this->min_data.push(0xffff);
    }
    int pop(void){
        if(this->top == NULL){return -1;}
        Node *ret;
        ret = this->top;
        this->top = this->top->next;
        if(ret->data == this->min()){
            this->min_data.pop();
        }
        return ret->data;
    }
    void push(int d){
        Node *node_add = new Node(d);
        node_add->next = this->top;
        this->top = node_add;
        if(this->min() > d ){
            std::cout << d << std::endl;
            this->min_data.push(d);
        }
        return;
    }
    int peek(void){
        if(this->top == NULL){return -ERROR_CODE;}
        return this->top->data;
    }
    int min(){
        if(this->min_data.peek() == -ERROR_CODE){return ERROR_CODE;}
        return this->min_data.peek();
    }
};

int main(void){
    int *array;
    class StackOneArray *stack[3];

    array = new int[SIZE_ARRAY];
    for(unsigned int iter = 0 ; iter < 3 ; iter ++){
        stack[iter] = new class StackOneArray;
    }

    for(unsigned int iter = 0 ; iter < LIST_NUM ; iter++){
        stack[0]->push((rand() % MAX_NUMBER_1 + 1));
        stack[1]->push((rand() % MAX_NUMBER_2 + 1));
        stack[2]->push((rand() % MAX_NUMBER_3 + 1));
    }

    for(unsigned int j = 0 ; j < 3 ; j++){
        for(unsigned int iter = 0 ; iter < LIST_NUM ; iter++){
            std::cout << "index " << iter << " min " << stack[j]->min() <<" : " << stack[j]->pop() << std::endl;
        }
    }

    delete[] array;


    return 0;
}