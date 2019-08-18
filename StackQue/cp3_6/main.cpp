#include <iostream>
#include <stdio.h>
#include "../stack.hpp"


// Implement three stack with one array. 
// Array size is 1000

#define ERROR_CODE 99999


#define LIST_NUM (10)
#define MAX_NUMBER (20)



int main(void){
    class Stack target;
    class Stack smaller;
    class Stack bigger;
    class Stack result;


    for(unsigned int iter = LIST_NUM ; iter > 0 ; iter--){
        target.push((rand() % MAX_NUMBER + 1));
    }
    target.show();
    
    // bubble sort.
    while(!target.isEmpty()){
        smaller.push(target.pop()->data);
        while(!target.isEmpty()){
            if(target.peek() >= smaller.peek() ){
                bigger.push(target.pop()->data);
            }else{
                bigger.push(smaller.pop()->data);
                smaller.push(target.pop()->data);
            }
        }
        while(!bigger.isEmpty()){
            target.push(bigger.pop()->data);
        }
        smaller.show();
    }

    return 0;
}
