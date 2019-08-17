#include <iostream>
#include <stdio.h>
#include "../link.hpp"

//Check Palindrome
// Make bidirection list

#define LIST_NUM (10)
#define MAX_NUMBER (20)

unsigned int calc_node_num(Node *node){
    unsigned int ret = 0;

    while(node != NULL){
        node = node->next;
        ret++;
    }
    std::cout << "len " <<  ret << std::endl;
    return ret;
}
bool check_palindrome(Node *node,int length){
    unsigned int val; 

    if(length < 1){ return true;}
    if( check_palindrome(node->next,length-2) == false){
        return false;
    }
    val = node->data;
    while(length > 0){
        node = node->next;
        length--;
    }
    std::cout << val << " / " << node->data << std::endl;
    return (val == node->data);
}

int main(void){
    class my_NodeList temp;
    bool result;

    // Create a list filled with random numbers.
    //for(unsigned int iter = 0 ; iter < LIST_NUM ; iter++){
    //    temp.apendToTail((rand() % MAX_NUMBER + 1));
    //}
    temp.apendToTail(1);
    temp.apendToTail(2);
    temp.apendToTail(4);
    temp.apendToTail(5);
    temp.apendToTail(8);
    temp.apendToTail(8);
    temp.apendToTail(5);
    temp.apendToTail(4);
    temp.apendToTail(2);
    temp.apendToTail(1);
    temp.show();
    std::cout << "-----------------" << std::endl;

    result = check_palindrome(temp.head,calc_node_num(temp.head)-1);

    std::cout << result << std::endl;

    return 0;
}