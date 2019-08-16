
#ifndef __MY_LINK__
#define __MY_LINK__

class Node {
public:
    int data;
    Node *next;
};
class my_NodeList{
public:
    int length;
    Node *head;
    my_NodeList(void);
    void apendToTail(int d);
    void deletNode(int d);
    void show(void);
};
#endif
