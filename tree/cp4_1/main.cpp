#include <iostream>
#include <stdio.h>
#include "../tree.hpp"

#define MAX_NUMBER    20
#define LIST_NUM    (3)
class my_tree : public Tree{
public:
    bool is_TreeDepth_same(Node *node){
        unsigned int left_depth,right_depth;
        bool left_bool,right_bool;
        if(node == NULL){ return true;}
        left_depth = this->getDepth(node->left);
        right_depth = this->getDepth(node->right);
        std::cout << " key : " << node->key << " : left " << left_depth << " : right " << right_depth << std::endl;
        if(left_depth != right_depth){
            return false;
        }else{
            left_bool = is_TreeDepth_same(node->left);
            right_bool = is_TreeDepth_same(node->right);
        }
        return (left_bool&&right_bool);

    }
};

int main(void){
    class my_tree tree;
    unsigned int key;
#if 0 
    for(unsigned int iter = 0 ; iter < LIST_NUM ; iter++){
        key = (rand() % MAX_NUMBER + 1);
        tree.insert(key);
        std::cout << key << " "<< std::endl;
    }
#endif
    // make Balanced tree.
    tree.insert(3);
    tree.insert(1);
    tree.insert(2);
    tree.insert(0);
    tree.insert(6);
    tree.insert(4);
    tree.insert(8);

    tree.print();
    tree.search(tree.top,8);
    
    std::cout << tree.is_TreeDepth_same(tree.top) << std::endl;


    return 0;
}