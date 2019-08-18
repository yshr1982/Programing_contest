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
public:
    Node *top;
    Tree();
    void insert(unsigned int k);
    void del(unsigned int k);
    void print(void);
    Node *search(Node *node,unsigned int key);
    unsigned int getDepth(Node *node);
private:
    void setNode(Node *n,unsigned int k,Node *right,Node *left);
    void preorder(Node *n);
    void inorder(Node *n);
    void postorder(Node *n);
};


#endif