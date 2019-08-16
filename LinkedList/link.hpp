
#ifndef __MY_LINK__
#define __MY_LINK__

class Node {
public:
    int data;
    Node *next;
    Node();
    ~Node();
};
class my_NodeList{
public:
    int length;
    Node *head;
    my_NodeList(void);
    void apendToTail(int d);
    Node *deletNode(int d);
    int findTail(int n);
    void show(void);
};
#endif
