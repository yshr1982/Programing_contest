#include <iostream>
#include "stack.hpp"
#define ERROR_CODE 99999

/*!
* @fn Node(void) 
*/
Node::Node(int d){
    this->data = d;
    this->next = NULL;
}


/*!
* @fn pop(void) 
* @brief if stack data is no data, this function return NULL.
*/
Node *Stack::pop(void){
    if(this->top == NULL){return NULL;}
    Node *ret;
    ret = this->top;
    this->top = this->top->next;
    return ret;
}

/*!
* @fn push(int d) 
* @brief Add data to top .
*/
void Stack::push(int d){
    Node *node_add = new Node(d);
    node_add->next = this->top;
    this->top = node_add;
    return;
}

/*!
* @fn peek(void) 
* @brief return top data.
*/
int Stack::peek(void){
    if(this->top == NULL){return -ERROR_CODE;}
    return this->top->data;
}

/*!
* @fn enqueue(int d) 
* @param d Want to add data.
*/
void Queue::enqueue(int d){
    if(this->first == NULL){
        this->last = new Node(d);
        this->first = this->last;
    }else{
        this->last->next = new Node(d);
        this->last = this->last->next; 
    }
}
/*!
* @fn dequeue(void) 
* @param del_node Want to erase node address.
*/
Node * Queue::dequeue(void){ 
    if(this->first == NULL){return NULL;}
    Node *ret = this->first;
    this->first = this->first->next;
    return ret;
}