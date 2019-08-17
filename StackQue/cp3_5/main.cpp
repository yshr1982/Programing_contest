#include <iostream>
#include <stdio.h>
#include "../stack.hpp"


// Implement three stack with one array. 
// Array size is 1000

#define ERROR_CODE 99999


#define LIST_NUM (60)
#define MAX_NUMBER (20)

class MyQueue{
    Stack push_stack;
    Stack pop_stack;
public:
    void enqueue(int d){
        this->push_stack.push(d);
    }
    // For efficiency, move push_stack data to pop_stack when pop_stack is empty only.
    int dequeue(void){
        if(this->pop_stack.isEmpty()){
            this->move_data(&this->push_stack,&this->pop_stack);
        }
        return this->pop_stack.pop()->data;
    }
    int peek(void){
        if(this->pop_stack.isEmpty()){
            this->move_data(&this->push_stack,&this->pop_stack);
        }
        return this->pop_stack.peek();
    }
    void show(void){
        this->pop_stack.show();
        this->push_stack.show();
    }
private:
    void move_data(Stack *push,Stack *pop){
        while(!push->isEmpty()){
            pop->push(push->pop()->data);
        }
    }
};

int main(void){
    class MyQueue my_queue;

    for(unsigned int iter = LIST_NUM ; iter > 0 ; iter--){
        my_queue.enqueue(iter);
    }
    my_queue.show();
    my_queue.dequeue();
    my_queue.show();

    return 0;
}