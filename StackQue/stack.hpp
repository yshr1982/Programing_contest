#ifndef __MY_STACK__
#define __MY_STACK__

class Node {
public:
    int data;
    Node *next;
    Node(int d);
};

class Stack{
    Node *top;
public:
    Node *pop();
    void push(int d);
    int peek();
};

class Queue{
    Node *first,*last;
public:
    void enqueue(int item);
    Node *dequeue(void);
};

#endif