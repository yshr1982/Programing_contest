#ifndef __MY_STACK__
#define __MY_STACK__

#define ERROR_CODE 99999
class Node {
public:
    int data;
    Node *next;
    Node(int d);
};

class Stack{
    Node *top;
    unsigned int depth; 
public:
    Stack();
    Node *pop();
    void push(int d);
    int peek();
    bool isEmpty();
    bool isFull();
};

class Queue{
    Node *first,*last;
public:
    void enqueue(int item);
    Node *dequeue(void);
};

#endif