
#include <iostream>
#include <stdio.h>
#include <string.h>
#include "../stack.hpp"


// Implement three stack with one array. 
// Array size is 1000

#define ERROR_CODE 99999


#define LIST_NUM (10)
#define MAX_NUMBER (20)

class my_animal{
    Queue dog,cat;
    Queue dog_order,cat_order;
    unsigned int order;
public:
    my_animal(void){
        this->order = 0;
    }
    void enqueue(std::string animal,int id){
        this->order++;
        if(animal == "dog"){
            this->dog.enqueue(id);
            this->dog_order.enqueue(this->order);
        }else if(animal == "cat"){
            this->cat.enqueue(id);
            this->cat_order.enqueue(this->order);
        }else{
            this->order--;
            return;
        }
    }
    int dequeueAny(void){
        if((this->dog_order.peek() == NULL)&&(this->cat_order.peek() == NULL)){return -1;}
        if(this->dog_order.peek() == NULL){return this->dequeueCat();}
        if(this->cat_order.peek() == NULL){return this->dequeueDog();}

        if(this->dog_order.peek()->data > this->cat.peek()->data){
            return this->dequeueCat();
        }else{
            return this->dequeueDog();
        }
    }
    int dequeueCat(void){
        if(cat.peek() == NULL){return -1;}
        this->cat_order.dequeue();
        return this->cat.dequeue()->data;
    }
    int dequeueDog(void){
        if(dog.peek() == NULL){return -1;}
        this->dog_order.dequeue();
        return this->dog.dequeue()->data;
    }
    void show(void){
        this->dog.show();
        this->dog_order.show();
        this->cat.show();
        this->cat_order.show();
    }

};


int main(void){
    int data;
    std::string animal;
    class my_animal safari;
    for(unsigned int iter = 0 ; iter < LIST_NUM ; iter++){
        data = (rand() % MAX_NUMBER + 1);
        if(data % 2){
            animal = "dog";
        }else{
            animal = "cat";
        }
        std::cout << animal << " : " << data  << std::endl;
        safari.enqueue(animal,data);
    }
    safari.show();
    for(unsigned int iter = 0 ; iter < LIST_NUM ; iter++){
        data = (rand() % MAX_NUMBER + 1);
        if(data % 2){
            animal = "dog";
            data = safari.dequeueDog();
        }else{
            animal = "cat";
            data = safari.dequeueCat();
        }
        std::cout << animal << " : " << data  << std::endl;

    }


    return 0;
}