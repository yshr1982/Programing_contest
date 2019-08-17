#include <iostream>
#include <stdio.h>
#include "../stack.hpp"


// Implement three stack with one array. 
// Array size is 1000

#define ERROR_CODE 99999


#define LIST_NUM (60)
#define MAX_NUMBER (20)

class SetOfStacks{
    Stack *top[20];
    unsigned int stack_index;
public:
    SetOfStacks(){
        top[this->stack_index] = new Stack();
        this->stack_index = 0;
    }
    int pop(void){
        Node *ret;
        if(this->top[this->stack_index]->isEmpty()){
            if(this->stack_index == 0){return -ERROR_CODE;}
            delete this->top[this->stack_index];
            this->stack_index--;
        }
        ret = this->top[this->stack_index]->pop();
        return ret->data;
    }
    void push(int d){
        if(this->top[this->stack_index]->isFull()){
            this->stack_index++;
            this->top[this->stack_index] = new Stack();
        }
        this->top[this->stack_index]->push(d);
        return;
    }
    int peek(void){
        return this->top[this->stack_index]->peek();
    }
    void show(void){
        for(int iter = this->stack_index ; iter >= 0 ; iter --){
            std::cout << "----------- " << iter << " -----------"  << std::endl;
            this->top[iter]->show();
        }
    }
};

int main(void){
    class SetOfStacks *stacks;

    stacks = new SetOfStacks();
    for(unsigned int iter = 0 ; iter < LIST_NUM ; iter++){
        stacks->push((rand() % MAX_NUMBER + 1));
    }
    stacks->show();
    for(unsigned int iter = 0 ; iter < LIST_NUM ; iter++){
        std::cout << "index " << iter << " val " << stacks->pop() << std::endl;
    }


    return 0;
}