#include "Sevens.h"
#include <iostream>
using namespace std;
int main(){
    while(1){
    game g;
    g.setvalue();
    g.shuffle();
    g.dealcard();
    int e=g.findfirst();
    if(e==1){
        for(int i=0;i<13;i++){
            g.player2_move();
            g.player3_move();
            g.user_choose();
            if(i!=12){
                g.player1_move();
            }
        }
    }
    else if(e==2){
        for(int i=0;i<13;i++){
            g.player3_move();
            g.user_choose();
            g.player1_move();
            if(i!=12){
                g.player2_move();
            }
        }
    }
    else if(e==3){
        for(int i=0;i<13;i++){
            g.user_choose();
            g.player1_move();
            g.player2_move();
            if(i!=12){
                g.player3_move();
            }
        }
    }
    else if(e==4){
        for(int i=0;i<13;i++){
            g.player1_move();
            g.player2_move();
            g.player3_move();
            if(i!=12){
                g.user_choose();
            }
        }
    }

    g.find_winer();
    }
}
