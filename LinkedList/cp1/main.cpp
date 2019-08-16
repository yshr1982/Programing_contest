#include <iostream>
#include <stdio.h>
#include "../link.hpp"

#define LIST_NUM (10)
#define MAX_NUMBER (20)

//Find Nth element node from the end.
//Using list
int my_NodeList::findTail(int n){
    unsigned int node_num = 0;
    int *pList;
    int result;
    class Node *pTemp = this->head;

    pList = (int *)malloc((sizeof(int)*MAX_NUMBER));
    memset(pList,0,sizeof(int)*MAX_NUMBER);
    if(pTemp == NULL){return -1;}
    while(pTemp != NULL){
        pList[node_num] = pTemp->data;
        node_num++;
        pTemp = pTemp->next;
    }
    result = pList[node_num - n];
    free(pList);
    return result;
}

//Find Nth element node from the end.
//Recursive processing

Node *findNthToTail(Node *head,int find_N,int *node_count){
    if(head == NULL){return NULL;}
    Node *node = findNthToTail(head->next,find_N,node_count);
    *node_count = *node_count + 1;
    if(*node_count == find_N){
        return head;
    }
    
    return node;
}

int main(void){
    class my_NodeList temp;
    int node_count;
    Node *result;

    // Create a list filled with random numbers.
    for(unsigned int iter = 0 ; iter < LIST_NUM ; iter++){
        temp.apendToTail((rand() % MAX_NUMBER + 1));
    }
    temp.show();
    std::cout << "-----------------" << std::endl;
    std::cout << temp.findTail(3) << std::endl;
    result = findNthToTail(temp.head,3,&node_count);
    std::cout << result->data << std::endl;

   for(unsigned int iter = 0 ; iter < LIST_NUM ; iter++){
        temp.deletNode(iter);
    }
    //temp.show();


    return 0;
}