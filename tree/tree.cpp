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
void Tree::del(unsigned int k){

}
void Tree::print(void){
    this->preorder(this->top);
    std::cout << std::endl;
    this->inorder(this->top);
    std::cout << std::endl;
    this->postorder(this->top);
    std::cout << std::endl;

}

Node *Tree::search(Node *node,unsigned int key){
    Node *tmp;
    if(node == NULL){return NULL;}
    if(node->key == key){return node;}
    if(node->key >= key){
        tmp = this->search(node->left,key);
    }else{
        tmp = this->search(node->right,key);
    }
    if(tmp == NULL){
        std::cout << "No hit " << " key " << key << std::endl;
    }else{
        std::cout << "search " << tmp->key << " key " << key << std::endl;
    }
    return tmp;



}

unsigned int Tree::getDepth(Node *node){
    unsigned int left_depth = 0;
    unsigned int right_depth = 0;

    if(node == NULL){return 0;}
    left_depth = this->getDepth(node->left);
    right_depth = this->getDepth(node->right);
    if(left_depth > right_depth){
        return left_depth + 1;
    }else{
        return right_depth + 1;
    }
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

/*!
* Depth-first search : postorder
*
*/
void Tree::postorder(Node *n){
    if(n == NULL){return;}
    if(n->left != NULL){this->inorder(n->left);}
    if(n->right != NULL){this->inorder(n->right);}
    std::cout << " " << n->key ;
}