#include <iostream>
#include <stdio.h>
#include "../link.hpp"

#define LIST_NUM (10)
#define MAX_NUMBER (20)

int main(void){
    class my_NodeList temp;
    class my_NodeList result;
    class Node *pNode;
    int *pList;

    // Create a list filled with random numbers.
    for(unsigned int iter = 0 ; iter < LIST_NUM ; iter++){
        temp.apendToTail((rand() % MAX_NUMBER + 1));
    }
    temp.show();
    std::cout << "-----------------" << std::endl;
    
    pNode = temp.head;
    pList = (int *)malloc((sizeof(int)*MAX_NUMBER));
    memset(pList,0,sizeof(int)*MAX_NUMBER);
    while(pNode != NULL){
        if(pList[pNode->data] == 0){
            pList[pNode->data] = 1;
            result.apendToTail(pNode->data);
        }
        pNode = pNode->next;
    }
    result.show();


    return 0;
}