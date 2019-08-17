#include <iostream>
#include <stdio.h>
#include "../stack.hpp"


// Implement three stack with one array. 
// Array size is 1000

#define ERROR_CODE 99999


#define LIST_NUM (20)
#define MAX_NUMBER (20)

class HanoiTower{
    Stack *tower;
public:
    HanoiTower(){
        tower = new Stack();
    }
    void add(int disk_no){
        tower->push(disk_no);
    }
    int pickup(void){
        return this->tower->pop()->data;
    }
    int peek(void){
        return this->tower->peek();
    }
    int move_disk(HanoiTower *t){
        if(t->peek() != -ERROR_CODE){
            if(t->peek() < this->peek()){
                std::cout << "Error. Targer Tower's top Disk is smaller than my tower's top disk."  << std::endl;
                return -1;
            }
        }
        int disk = this->pickup();
        t->add(disk);
        return 0;
    }
    int move_all_disk(int disk_num,HanoiTower *target_tower , HanoiTower *buffer_tower){
        if(disk_num <= 0){return -1;}
        this->move_all_disk(disk_num-1,buffer_tower,target_tower);
        this->move_disk(target_tower);
        buffer_tower->move_all_disk(disk_num-1,target_tower,this);
        //this->show();
        //target_tower->show();
        //buffer_tower->show();
        return 0;
    }
    void show(void){
        this->tower->show();
    }
};

int main(void){
    class HanoiTower *tower[3];

    for(unsigned int iter = 0 ; iter < 3 ; iter++){
        tower[iter] = new HanoiTower();
    }
    for(unsigned int iter = LIST_NUM ; iter > 0 ; iter--){
        tower[0]->add(iter);
    }
    tower[0]->show();
    tower[0]->move_all_disk(LIST_NUM,tower[2],tower[1]);

    for(unsigned int iter = 0 ; iter < 3 ; iter++){
        tower[iter]->show();
    }
    return 0;
}