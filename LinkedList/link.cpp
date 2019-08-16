#include <iostream>
#include "link.hpp"


Node::Node(){std::cout << "constructor Node" << std::endl;}
Node::~Node(){std::cout << "destructor Node" << std::endl;}

/*!
* @fn my_NodeList(void) 
*/
my_NodeList::my_NodeList(void){
    this->head = NULL;
}
/*!
* @fn apendToTail(int d) 
* @param d Want to add data.
*/
void my_NodeList::apendToTail(int d){
    Node *next_node = new Node();
    Node *temp_node = this->head;
    next_node->data = d;
    next_node->next = NULL;
    
    if(this->head == NULL)
    {
        this->head = next_node;
        return;
    }

    while(temp_node->next != NULL){
        temp_node = temp_node->next;
    }
    temp_node->next = next_node;
}
/*!
* @fn deletNode(int d) 
* @param del_node Want to erase node address.
*/
Node * my_NodeList::deletNode(int d){ 
    Node *temp_node = this->head;
    if(temp_node == NULL){goto FIN;}
    if(temp_node->data == d){
        this->head = temp_node->next;
        goto FIN;
    }
    while(temp_node->next != NULL){
        if(temp_node->next->data == d){
            temp_node->next = temp_node->next->next;
            goto FIN;
        }
        temp_node = temp_node->next;
    }

FIN:
    return this->head;
}
/*!
* @fn show(show) 
* @brief show current node list.if node is null, no show.
*/
void my_NodeList::show(void){
    Node *temp_node = this->head ;
    if(temp_node == NULL){return;}
    while(temp_node->next != NULL){
        std::cout << temp_node->data << std::endl;
        temp_node = temp_node->next;
    }
    std::cout << temp_node->data << std::endl;
}

#if 0 
int main(void){
    class my_NodeList temp;
    Node *temp_node;

    temp.apendToTail(10);
    temp.apendToTail(11);
    temp.apendToTail(12);
    temp.apendToTail(13);
    temp.apendToTail(14);
    temp.show();
    temp.deletNode(13);
    temp.show();
    temp.deletNode(10);
    temp.show();


    return 0;
}
#endif