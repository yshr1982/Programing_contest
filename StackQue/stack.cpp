#include <iostream>
#include "stack.hpp"
#define STACK_DEPTH 10
/*!
* @fn Node(void) 
*/
Node::Node(int d){
    this->data = d;
    this->next = NULL;
}

Stack::Stack(){
    this->top = NULL;
    this->depth = -1;
}
/*!
* @fn pop(void) 
* @brief if stack data is no data, this function return NULL.
*/
Node *Stack::pop(void){
    if(this->isEmpty() != false){return NULL;} 
    Node *ret;
    ret = this->top;
    this->top = this->top->next;
    this->depth--;
    return ret;
}

/*!
* @fn push(int d) 
* @brief Add data to top .
*/
void Stack::push(int d){
    if(this->isFull() != false){return;} 
    Node *node_add = new Node(d);
    node_add->next = this->top;
    this->top = node_add;
    this->depth++;
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
* @fn isEmpty(void) 
* @brief return empty state. 
*/
bool Stack::isEmpty(void){
    return (this->depth == -1 );
}

/*!
* @fn isFull(void) 
* @brief return full state.
*/
bool Stack::isFull(void){
    return (this->depth + 1 >= STACK_DEPTH );
}

/*!
* @fn show(void) 
* @brief show current stack .
*/
void Stack::show(void){
    Node *temp_node = this->top ;
    if(temp_node == NULL){return;}
    while(temp_node->next != NULL){
        std::cout << temp_node->data << std::endl;
        temp_node = temp_node->next;
    }
    std::cout << temp_node->data << std::endl;
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