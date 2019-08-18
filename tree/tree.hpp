#ifndef __MY_STACK__
#define __MY_STACK__

#define ERROR_CODE 99999

class Node {
public:
    unsigned int key;
    Node *parent;
    Node *left;
    Node *right;
    Node(unsigned int key);
};

class Tree{
    Node *top;
public:
    Tree();
    void insert(unsigned int k);
    void print(void);
private:
    void search(void);
    void setNode(Node *n,unsigned int k,Node *right,Node *left);
    void preorder(Node *n);
    void inorder(Node *n);
};


#endif