#include <iostream>
#include "tree.hpp"
#define STACK_DEPTH 100

/*!
* @fn Node(mydata d) 
* @brief constractor.
*/
Node::Node(unsigned int key){
    this->key = key;
    this->left = NULL;
    this->right = NULL;
    this->parent = NULL;
}

/*!
* @fn Tree(mydata d) 
* @brief constractor.
*/
Tree::Tree(){
    this->top = NULL;
}

void Tree::insert(unsigned int k){
    Node *node;

    if(this->top == NULL){
        this->top = new Node(k);
        return;
    }

    node = this->top;
    while(true){
        if( node->key >= k){
            if(node->left == NULL){
                node->left = new Node(k);
                node->left->parent = node;
                break;
            }
            node = node->left;
        }else{
            if(node->right == NULL){
                node->right = new Node(k);
                node->right->parent = node;
                break;
            }
            node = node->right;
        }
    }

}
void Tree::print(void){
    this->preorder(this->top);
    std::cout << std::endl;
    this->inorder(this->top);
    std::cout << std::endl;

}

void Tree::search(void){

}
void Tree::setNode(Node *n,unsigned int k,Node *right,Node *left){

}

/*!
* Depth-first search : preorder
*
*/
void Tree::preorder(Node *n){
    if(n == NULL){return;}
    std::cout << " " << n->key ;
    if(n->left != NULL){this->preorder(n->left);}
    if(n->right != NULL){this->preorder(n->right);}


}

/*!
* Depth-first search : inorder
*
*/
void Tree::inorder(Node *n){
    if(n == NULL){return;}
    if(n->left != NULL){this->inorder(n->left);}
    std::cout << " " << n->key ;
    if(n->right != NULL){this->inorder(n->right);}

}