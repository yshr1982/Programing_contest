#include <iostream>
#include <stdio.h>
#include "../link.hpp"

//ノード加算問題 
// 690 + 310 = 1000という計算を行う。ただし、計算対象の数値は、各桁毎の数値で構成された連結ノードによって表現されている。
// 690 = (0 -> 9 -> 6) , 310 = ( 0 -> 1 -> 3) , 1000 ( 0->0->0->1)
// 連結ノードで与えられた数値を計算し、計算結果を( 0->0->0->1)という連結ノードで表現せよ。

#define NUM_X (305)
#define NUM_Y (867)
#define NUMBER_OF_DIGIT (3)
#define RESULT (NUM_X + NUM_Y)

void calc(Node *x,Node *y,my_NodeList *result){
    unsigned int carry_no = 0;
    unsigned int temp;

    while(x != NULL){
        temp = carry_no + x->data + y->data;
        if( temp >= 10){
            temp = temp -10;
            carry_no = 1;
        }else{
            carry_no = 0;
        }
        result->apendToTail(temp);
        x = x->next;
        y = y->next;
    }
    if(carry_no == 1){
        result->apendToTail(1);
    }
}

int main(void){
    class my_NodeList list_x;
    class my_NodeList list_y;
    class my_NodeList result;
    unsigned int x,y,mod_x,mod_y;

    x = NUM_X;
    y = NUM_Y;
    mod_x = 0;
    mod_y = 0;

    // Make x and y linked list.
    for(unsigned int iter = 0 ; iter < NUMBER_OF_DIGIT; iter ++){
        mod_x = x % 10;
        x = x / 10;
        mod_y = y % 10;
        y = y / 10;
        list_x.apendToTail(mod_x);
        list_y.apendToTail(mod_y);

    }
    list_x.show();
    list_y.show();
    std::cout << "-----------------" << std::endl;
    
    calc(list_x.head,list_y.head,&result);
    result.show();


    return 0;
}