#include <iostream>
#include <stdio.h>
#include "../link.hpp"

//循環ノード検出問題(Detect circular node)
// A->B->C->D->E->C->D->E ... という循環ノードからCを検出する.

#define LIST_NUM (10)
#define MAX_NUMBER (20)

Node *search_duplicate_link_node(Node *node){
    unsigned int position = 0;
    unsigned int iter = 0 ;
    Node *probe_node;
    Node *search_node;
    int isHit = 0;

    probe_node = node;
    while(isHit == 0){
        probe_node = probe_node->next;
        position++;
        search_node = node;
        for(iter = 0 ; iter < position;iter++){
            if(search_node == probe_node){

                isHit = 1;
                break;
            }else{
                search_node = search_node->next;
            }
        }
    } 
    return search_node;
}

int main(void){
    class my_NodeList temp;
    Node *make_circular_node;
    Node *end_node,*result;

    // Create a list filled with random numbers.
    for(unsigned int iter = 0 ; iter < LIST_NUM ; iter++){
        temp.apendToTail((rand() % MAX_NUMBER + 1));
    }
    temp.show();
    std::cout << "-----------------" << std::endl;
    
    make_circular_node = temp.head;
    for(unsigned int iter = 0 ; iter < LIST_NUM/5 ; iter++){
        make_circular_node = make_circular_node->next;
    }
    end_node = temp.head;
    while(end_node->next != NULL){
        std::cout << "list addr : " << end_node << std::endl;
        end_node = end_node->next;
    }
        std::cout << "Lined addr : " << make_circular_node << std::endl;
    end_node->next = make_circular_node;

    std::cout << "-----------------" << std::endl;

    result = search_duplicate_link_node(temp.head);
    std::cout << "result " << result << " value = " << result->data << std::endl;

    return 0;
}