#include "Sevens.h"
#include <iostream>
#include <ctime>
#include <stdlib.h>
using namespace std;

void game::setvalue(){
    int i,j;
    for(i=0;i<13;i++){
        for(j=0;j<4;j++){
            card[i][j] = {0};
            central_card[i][j] = {0};
        }
    }
    for(i=0;i<13;i++){
        p1_n[i] = p1_s[i] = p1_cover_n[i] = p1_cover_s[i] ={0};
        p2_n[i] = p2_s[i]= p2_cover_n[i] = p2_cover_s[i] ={0};
        p3_n[i] = p3_s[i] = p3_cover_n[i] = p3_cover_s[i] ={0};
        user_n[i] = user_s[i] = user_cover_n[i] = user_cover_s[i] ={0};
    }
    for(i=0;i<52;i++){
        central_n[i] = central_s[i]={0};
    }
}

void game::shuffle(){
    int i,n,s;
    srand(time(NULL));
    for(i=1;i<=52;i++){
        n = rand()%13;
        s = rand()%4;
        if(card[n][s]==0){
            card[n][s] = i;
        }
        else
            i--;
    }
}

void game::dealcard(){
    int i,j,k;
    for(i=1;i<=13;i++){
        for(j=0;j<13;j++){
            for(k=0;k<4;k++){
                if(card[j][k]==i){
                    p1_n[i-1] = j+1;
                    p1_s[i-1] = k+1;
                }
            }
        }
    }
    for(i=14;i<=26;i++){
        for(j=0;j<13;j++){
            for(k=0;k<4;k++){
                if(card[j][k]==i){
                    p2_n[i-14] = j+1;
                    p2_s[i-14] = k+1;
                }
            }
        }
    }
    for(i=27;i<=39;i++){
        for(j=0;j<13;j++){
            for(k=0;k<4;k++){
                if(card[j][k]==i){
                    p3_n[i-27] = j+1;
                    p3_s[i-27] = k+1;
                }
            }
        }
    }
    for(i=40;i<=52;i++){
        for(j=0;j<13;j++){
            for(k=0;k<4;k++){
                if(card[j][k]==i){
                    user_n[i-40] = j+1;
                    user_s[i-40] = k+1;
                }
            }
        }
    }
}

void game::print_card(int *p_n,int *p_s){
    int i,j,k,r;
    for(r=1;r<=11;r++){
            switch(r){
            case 1:
                for(j=1;j<=13;j++){
                    if(p_n[j-1]&&p_s[j-1]!=0){
                        if(j<10)
                            cout<<j<<". ";
                        else if(j>=10)
                            cout<<j<<".";
                        cout<<"¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w"<<"   ";
                    }
                    else
                        cout<<"   "<<"           "<<"   ";
                }
                cout << endl;
                break;
            case 2:
                for(j=0;j<13;j++){
                    if(p_n[j]&&p_s[j]!=0){
                    cout<<"   ";
                    if(p_n[j]>=2&&p_n[j]<10){
                        cout<<"¢j";
                        for(i=0;i<3;i++){
                           cout<<p_n[j]<<" ";
                        }
                        cout<<p_n[j]<<" ¢y";
                        cout<<"  ";
                    }
                    else if(p_n[j] == 10){
                        cout<<"¢j";
                        for(i=0;i<2;i++){
                            cout<<p_n[j]<<" ";
                        }
                        cout<<p_n[j]<<"¢y";
                        cout << "  ";
                    }
                    else if(p_n[j] == 1){
                        cout<<"¢j";
                        for(i=0;i<3;i++){
                            cout<<"A ";
                        }
                        cout<<"A"<<" ¢y";
                        cout<<"  ";
                    }
                    else if(p_n[j] == 11){
                        cout<<"¢j";
                        for(i=0;i<3;i++){
                            cout<<"J ";
                        }
                        cout<<"J"<<" ¢y";
                        cout<<"  ";
                    }
                    else if(p_n[j] == 12){
                        cout<<"¢j";
                        for(i=0;i<3;i++){
                            cout<<"Q ";
                        }
                        cout<<"Q"<<" ¢y";
                        cout<<"  ";
                    }
                    else if(p_n[j] == 13){
                        cout<<"¢j";
                        for(i=0;i<3;i++){
                            cout<<"K ";
                        }
                        cout<<"K"<<" ¢y";
                        cout<<"  ";
                    }
                }
                else
                    cout<<"   "<<"           "<<"   ";
                }
                cout << endl;
                break;
            case 3:
                for(j=0;j<13;j++){
                    cout<<"   ";
                    if(p_n[j]&&p_s[j]!=0){
                        cout<<"¢j        ¢y"<<"  ";
                    }
                    else
                        cout<<"           "<<"   ";
                }
                cout<<endl;
                break;
            case 4:
                for(j=0;j<13;j++){
                    cout<<"   ";
                    if(p_n[j]&&p_s[j]!=0){
                        if(p_s[j]==2){
                            cout<<"¢j *   *  ¢y"<<"  ";
                        }
                        else {
                            cout<<"¢j   *    ¢y"<<"  ";
                        }
                    }
                    else
                        cout<<"           "<<"   ";
                }
                cout <<endl;
                break;
            case 5:
                for(j=0;j<13;j++){
                    cout<<"   ";
                    if(p_n[j]&&p_s[j]!=0){
                    if(p_s[j]==1){
                        cout<<"¢j  * *   ¢y"<<"  ";
                    }
                    else if(p_s[j]==2){
                        cout<<"¢j*  *  * ¢y"<<"  ";
                    }
                    else if(p_s[j]==3){
                        cout<<"¢j  * *   ¢y"<<"  ";
                    }
                    else if(p_s[j]==4){
                        cout<<"¢j* * * * ¢y"<<"  ";
                    }
                    }
                    else
                        cout<<"           "<<"   ";
                }
                cout <<endl;
                break;
            case 6:
                for(j=0;j<13;j++){
                        cout<<"   ";
                    if(p_n[j]&&p_s[j]!=0){
                    if(p_s[j]==1||p_s[j]==2||p_s[j]==3){
                        cout<<"¢j *   *  ¢y"<<"  ";
                    }
                    else if(p_s[j]==4){
                        cout<<"¢j * * *  ¢y"<<"  ";
                    }
                    }
                    else
                        cout<<"           "<<"   ";
                }
                cout <<endl;
                break;
            case 7:
                for(j=0;j<13;j++){
                        cout<<"   ";
                    if(p_n[j]&&p_s[j]!=0){
                    if(p_s[j]==1||p_s[j]==4){
                        cout<<"¢j   *    ¢y"<<"  ";
                    }
                    else if(p_s[j]==2||p_s[j]==3){
                        cout<<"¢j  * *   ¢y"<<"  ";
                    }
                    }
                    else
                        cout<<"           "<<"   ";
                }
                cout <<endl;
                break;
            case 8:
                for(j=0;j<13;j++){
                        cout<<"   ";
                    if(p_n[j]&&p_s[j]!=0){
                    if(p_s[j]==1||p_s[j]==4){
                        cout<<"¢j  ***   ¢y"<<"  ";
                    }
                    else if(p_s[j]==2||p_s[j]==3){
                        cout<<"¢j   *    ¢y"<<"  ";
                    }
                    }
                    else
                        cout<<"           "<<"   ";
                }
                cout <<endl;
                break;
            case 9:
                for(j=0;j<13;j++){
                        cout<<"   ";
                    if(p_n[j]&&p_s[j]!=0){
                    cout<<"¢j        ¢y"<<"  ";
                    }
                    else
                        cout<<"           "<<"   ";
                }
                cout<<endl;
                break;
            case 10:
                for(j=0;j<13;j++){
                        cout<<"   ";
                    if(p_n[j]&&p_s[j]!=0){
                    if(p_n[j]>=2&&p_n[j]<10){
                        cout<<"¢j";
                        for(i=0;i<3;i++){
                           cout<<p_n[j]<<" ";
                        }
                        cout<<p_n[j]<<" ¢y";
                        cout<<"  ";
                    }
                    else if(p_n[j] == 10){
                        cout<<"¢j";
                        for(i=0;i<2;i++){
                            cout<<p_n[j]<<" ";
                        }
                        cout<<p_n[j]<<"¢y";
                        cout << "  ";
                    }
                    else if(p_n[j] == 1){
                        cout<<"¢j";
                        for(i=0;i<3;i++){
                            cout<<"A ";
                        }
                        cout<<"A"<<" ¢y";
                        cout<<"  ";
                    }
                    else if(p_n[j] == 11){
                        cout<<"¢j";
                        for(i=0;i<3;i++){
                            cout<<"J ";
                        }
                        cout<<"J"<<" ¢y";
                        cout<<"  ";
                    }
                    else if(p_n[j] == 12){
                        cout<<"¢j";
                        for(i=0;i<3;i++){
                            cout<<"Q ";
                        }
                        cout<<"Q"<<" ¢y";
                        cout<<"  ";
                    }
                    else if(p_n[j] == 13){
                        cout<<"¢j";
                        for(i=0;i<3;i++){
                            cout<<"K ";
                        }
                        cout<<"K"<<" ¢y";
                        cout<<"  ";
                    }
                    }
                    else
                        cout<<"           "<<"   ";
                }
                cout << endl;
                break;
            case 11:
                for(j=0;j<13;j++){
                        cout<<"   ";
                    if(p_n[j]&&p_s[j]!=0){
                    cout<<"¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w"<<"   ";
                    }
                    else
                        cout<<"           "<<"   ";
                }
                cout << endl;
                break;
            }
        }
        cout<<endl;
}

void game::print_central_card(){
    int i,j,k,r;
    central_card[6][0] = 1;
    for(i=0;i<13;i++){
        central_n[i] = central_n[i+13] = central_n[i+26] = central_n[i+39] = i+1 ;
    }
    for(i=0;i<13;i++){
        central_s[i] = 1;
    }
    for(i=13;i<26;i++){
        central_s[i] = 2;
    }
    for(i=26;i<39;i++){
        central_s[i] = 3;
    }
    for(i=39;i<52;i++){
        central_s[i] = 4;
    }
    cout << "Central cards:" <<endl;

    for(k=0;k<4;k++){
        for(r=1;r<=11;r++){
            switch(r){
            case 1:
                for(j=0+(13*k);j<13+(13*k);j++){
                    if(central_card[central_n[j]-1][central_s[j]-1]!=0){
                        cout<<"   ";
                        cout<<"¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w"<<"   ";
                    }
                    else
                        cout<<"   "<<"           "<<"   ";
                }
                cout << endl;
                break;
            case 2:
                for(j=0+(13*k);j<13+(13*k);j++){
                    if(central_card[central_n[j]-1][central_s[j]-1]!=0){
                        cout<<"   ";
                        if(central_n[j]>=2&&central_n[j]<10){
                            cout<<"¢j";
                            for(i=0;i<3;i++){
                               cout<<central_n[j]<<" ";
                            }
                            cout<<central_n[j]<<" ¢y";
                            cout<<"  ";
                        }
                        else if(central_n[j] == 10){
                            cout<<"¢j";
                            for(i=0;i<2;i++){
                                cout<<central_n[j]<<" ";
                            }
                            cout<<central_n[j]<<"¢y";
                            cout << "  ";
                        }
                        else if(central_n[j] == 1){
                            cout<<"¢j";
                            for(i=0;i<3;i++){
                                cout<<"A ";
                            }
                            cout<<"A"<<" ¢y";
                            cout<<"  ";
                        }
                        else if(central_n[j] == 11){
                            cout<<"¢j";
                            for(i=0;i<3;i++){
                                cout<<"J ";
                            }
                            cout<<"J"<<" ¢y";
                            cout<<"  ";
                        }
                        else if(central_n[j] == 12){
                            cout<<"¢j";
                            for(i=0;i<3;i++){
                                cout<<"Q ";
                            }
                            cout<<"Q"<<" ¢y";
                            cout<<"  ";
                        }
                        else if(central_n[j] == 13){
                            cout<<"¢j";
                            for(i=0;i<3;i++){
                                cout<<"K ";
                            }
                            cout<<"K"<<" ¢y";
                            cout<<"  ";
                        }
                    }
                    else
                        cout<<"   "<<"           "<<"   ";
                }
                cout << endl;
                break;
            case 3:
                for(j=0+(13*k);j<13+(13*k);j++){
                    if(central_card[central_n[j]-1][central_s[j]-1]!=0){
                        cout<<"   ";
                        cout<<"¢j        ¢y"<<"  ";
                    }
                    else
                        cout<<"   "<<"           "<<"   ";
                }
                cout<<endl;
                break;
            case 4:
                for(j=0+(13*k);j<13+(13*k);j++){
                    if(central_card[central_n[j]-1][central_s[j]-1]!=0){
                        cout<<"   ";
                        if(central_s[j]==2){
                            cout<<"¢j *   *  ¢y"<<"  ";
                        }
                        else {
                            cout<<"¢j   *    ¢y"<<"  ";
                        }
                    }
                    else
                        cout<<"   "<<"           "<<"   ";
                }
                cout <<endl;
                break;
            case 5:
                for(j=0+(13*k);j<13+(13*k);j++){
                    if(central_card[central_n[j]-1][central_s[j]-1]!=0){
                        cout<<"   ";
                        if(central_s[j]==1){
                            cout<<"¢j  * *   ¢y"<<"  ";
                        }
                        else if(central_s[j]==2){
                            cout<<"¢j*  *  * ¢y"<<"  ";
                        }
                        else if(central_s[j]==3){
                            cout<<"¢j  * *   ¢y"<<"  ";
                        }
                        else if(central_s[j]==4){
                            cout<<"¢j* * * * ¢y"<<"  ";
                        }
                    }
                    else
                        cout<<"   "<<"           "<<"   ";
                }
                cout <<endl;
                break;
            case 6:
                for(j=0+(13*k);j<13+(13*k);j++){
                    if(central_card[central_n[j]-1][central_s[j]-1]!=0){
                        cout<<"   ";
                        if(central_s[j]==1||central_s[j]==2||central_s[j]==3){
                            cout<<"¢j *   *  ¢y"<<"  ";
                        }
                        else if(central_s[j]==4){
                            cout<<"¢j * * *  ¢y"<<"  ";
                        }
                    }
                    else
                        cout<<"   "<<"           "<<"   ";
                }
                cout <<endl;
                break;
            case 7:
                for(j=0+(13*k);j<13+(13*k);j++){
                    if(central_card[central_n[j]-1][central_s[j]-1]!=0){
                        cout<<"   ";
                        if(central_s[j]==1||central_s[j]==4){
                            cout<<"¢j   *    ¢y"<<"  ";
                        }
                        else if(central_s[j]==2||central_s[j]==3){
                            cout<<"¢j  * *   ¢y"<<"  ";
                        }
                    }
                    else
                        cout<<"   "<<"           "<<"   ";
                }
                cout <<endl;
                break;
            case 8:
                for(j=0+(13*k);j<13+(13*k);j++){
                    if(central_card[central_n[j]-1][central_s[j]-1]!=0){
                        cout<<"   ";
                        if(central_s[j]==1||central_s[j]==4){
                            cout<<"¢j  ***   ¢y"<<"  ";
                        }
                        else if(central_s[j]==2||central_s[j]==3){
                            cout<<"¢j   *    ¢y"<<"  ";
                        }
                    }
                    else
                        cout<<"   "<<"           "<<"   ";
                }
                cout <<endl;
                break;
            case 9:
                for(j=0+(13*k);j<13+(13*k);j++){
                    if(central_card[central_n[j]-1][central_s[j]-1]!=0){
                        cout<<"   ";
                        cout<<"¢j        ¢y"<<"  ";
                    }
                    else
                        cout<<"   "<<"           "<<"   ";
                }
                cout<<endl;
                break;
            case 10:
                for(j=0+(13*k);j<13+(13*k);j++){
                    if(central_card[central_n[j]-1][central_s[j]-1]!=0){
                        cout<<"   ";
                        if(central_n[j]>=2&&central_n[j]<10){
                            cout<<"¢j";
                            for(i=0;i<3;i++){
                               cout<<central_n[j]<<" ";
                            }
                            cout<<central_n[j]<<" ¢y";
                            cout<<"  ";
                        }
                        else if(central_n[j] == 10){
                            cout<<"¢j";
                            for(i=0;i<2;i++){
                                cout<<central_n[j]<<" ";
                            }
                            cout<<central_n[j]<<"¢y";
                            cout << "  ";
                        }
                        else if(central_n[j] == 1){
                            cout<<"¢j";
                            for(i=0;i<3;i++){
                                cout<<"A ";
                            }
                            cout<<"A"<<" ¢y";
                            cout<<"  ";
                        }
                        else if(central_n[j] == 11){
                            cout<<"¢j";
                            for(i=0;i<3;i++){
                                cout<<"J ";
                            }
                            cout<<"J"<<" ¢y";
                            cout<<"  ";
                        }
                        else if(central_n[j] == 12){
                            cout<<"¢j";
                            for(i=0;i<3;i++){
                                cout<<"Q ";
                            }
                            cout<<"Q"<<" ¢y";
                            cout<<"  ";
                        }
                        else if(central_n[j] == 13){
                            cout<<"¢j";
                            for(i=0;i<3;i++){
                                cout<<"K ";
                            }
                            cout<<"K"<<" ¢y";
                            cout<<"  ";
                        }
                    }
                    else
                        cout<<"   "<<"           "<<"   ";
                }
                cout << endl;
                break;
            case 11:
                for(j=0+(13*k);j<13+(13*k);j++){
                    if(central_card[central_n[j]-1][central_s[j]-1]!=0){
                        cout<<"   ";
                        cout<<"¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w"<<"   ";
                    }
                    else
                        cout<<"   "<<"           "<<"   ";
                }
                cout << endl;
                break;
            }
        }
        cout<<endl;
    }
}

void game::user_choose(){
    int i,j,choose,a,b,c,e;
    print_central_card();
    cout<<endl;
    cout<<"Your cards¡G"<<endl;
    print_card(user_n,user_s);
    cout<<"Your cover cards:"<<endl;
    print_cover_card(user_cover_n,user_cover_s);
    if(check_cover_or_through_out_card(user_n,user_s)==1){
        cout<<"Please choose which one you want to through out?";
        cin>>choose;
        if(choose>0&&choose<14&&user_n[choose-1]!=0&&user_s[choose-1]!=0){
            if(through_out_card(choose,user_n,user_s)==0){
                cout<<"Now you can't through out this card,please choose again.";
                user_choose();
            }
        }
        else{
            cout<<"Please enter the right number.";
            user_choose();
        }
    }
    else if(check_cover_or_through_out_card(user_n,user_s)==0){
        cout<<"Now you have to cover card. Please choose which one you want to cover:";
        cin>>c;
        if(user_n[c-1]==0){
            cout<<"you can't cover this card,please choose again."<<endl;
            user_choose();
        }
        else if(c<1||c>13){
            cout<<"Please enter the right number."<<endl;
            user_choose();
        }
        else{
            cover_card(c,user_n,user_s,user_cover_n,user_cover_s);
        }
    }

}

void game::print_cover_card(int *p_n,int *p_s){
    int i,j,k,r;
        for(r=1;r<=11;r++){
            switch(r){
            case 1:
                for(j=1;j<=13;j++){
                    if(p_n[j-1]&&p_s[j-1]!=0){
                            cout<<"   ";
                        cout<<"¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w"<<"   ";
                    }
                    else
                        cout<<"   "<<"           "<<"   ";
                }
                cout << endl;
                break;
            case 2:
                for(j=0;j<13;j++){
                    if(p_n[j]&&p_s[j]!=0){
                    cout<<"   ";
                    if(p_n[j]>=2&&p_n[j]<10){
                        cout<<"¢j";
                        for(i=0;i<3;i++){
                           cout<<p_n[j]<<" ";
                        }
                        cout<<p_n[j]<<" ¢y";
                        cout<<"  ";
                    }
                    else if(p_n[j] == 10){
                        cout<<"¢j";
                        for(i=0;i<2;i++){
                            cout<<p_n[j]<<" ";
                        }
                        cout<<p_n[j]<<"¢y";
                        cout << "  ";
                    }
                    else if(p_n[j] == 1){
                        cout<<"¢j";
                        for(i=0;i<3;i++){
                            cout<<"A ";
                        }
                        cout<<"A"<<" ¢y";
                        cout<<"  ";
                    }
                    else if(p_n[j] == 11){
                        cout<<"¢j";
                        for(i=0;i<3;i++){
                            cout<<"J ";
                        }
                        cout<<"J"<<" ¢y";
                        cout<<"  ";
                    }
                    else if(p_n[j] == 12){
                        cout<<"¢j";
                        for(i=0;i<3;i++){
                            cout<<"Q ";
                        }
                        cout<<"Q"<<" ¢y";
                        cout<<"  ";
                    }
                    else if(p_n[j] == 13){
                        cout<<"¢j";
                        for(i=0;i<3;i++){
                            cout<<"K ";
                        }
                        cout<<"K"<<" ¢y";
                        cout<<"  ";
                    }
                }
                else
                    cout<<"   "<<"           "<<"   ";
                }
                cout << endl;
                break;
            case 3:
                for(j=0;j<13;j++){
                    cout<<"   ";
                    if(p_n[j]&&p_s[j]!=0){
                        cout<<"¢j        ¢y"<<"  ";
                    }
                    else
                        cout<<"           "<<"   ";
                }
                cout<<endl;
                break;
            case 4:
                for(j=0;j<13;j++){
                    cout<<"   ";
                    if(p_n[j]&&p_s[j]!=0){
                        if(p_s[j]==2){
                            cout<<"¢j *   *  ¢y"<<"  ";
                        }
                        else {
                            cout<<"¢j   *    ¢y"<<"  ";
                        }
                    }
                    else
                        cout<<"           "<<"   ";
                }
                cout <<endl;
                break;
            case 5:
                for(j=0;j<13;j++){
                    cout<<"   ";
                    if(p_n[j]&&p_s[j]!=0){
                    if(p_s[j]==1){
                        cout<<"¢j  * *   ¢y"<<"  ";
                    }
                    else if(p_s[j]==2){
                        cout<<"¢j*  *  * ¢y"<<"  ";
                    }
                    else if(p_s[j]==3){
                        cout<<"¢j  * *   ¢y"<<"  ";
                    }
                    else if(p_s[j]==4){
                        cout<<"¢j* * * * ¢y"<<"  ";
                    }
                    }
                    else
                        cout<<"           "<<"   ";
                }
                cout <<endl;
                break;
            case 6:
                for(j=0;j<13;j++){
                        cout<<"   ";
                    if(p_n[j]&&p_s[j]!=0){
                    if(p_s[j]==1||p_s[j]==2||p_s[j]==3){
                        cout<<"¢j *   *  ¢y"<<"  ";
                    }
                    else if(p_s[j]==4){
                        cout<<"¢j * * *  ¢y"<<"  ";
                    }
                    }
                    else
                        cout<<"           "<<"   ";
                }
                cout <<endl;
                break;
            case 7:
                for(j=0;j<13;j++){
                        cout<<"   ";
                    if(p_n[j]&&p_s[j]!=0){
                    if(p_s[j]==1||p_s[j]==4){
                        cout<<"¢j   *    ¢y"<<"  ";
                    }
                    else if(p_s[j]==2||p_s[j]==3){
                        cout<<"¢j  * *   ¢y"<<"  ";
                    }
                    }
                    else
                        cout<<"           "<<"   ";
                }
                cout <<endl;
                break;
            case 8:
                for(j=0;j<13;j++){
                        cout<<"   ";
                    if(p_n[j]&&p_s[j]!=0){
                    if(p_s[j]==1||p_s[j]==4){
                        cout<<"¢j  ***   ¢y"<<"  ";
                    }
                    else if(p_s[j]==2||p_s[j]==3){
                        cout<<"¢j   *    ¢y"<<"  ";
                    }
                    }
                    else
                        cout<<"           "<<"   ";
                }
                cout <<endl;
                break;
            case 9:
                for(j=0;j<13;j++){
                        cout<<"   ";
                    if(p_n[j]&&p_s[j]!=0){
                    cout<<"¢j        ¢y"<<"  ";
                    }
                    else
                        cout<<"           "<<"   ";
                }
                cout<<endl;
                break;
            case 10:
                for(j=0;j<13;j++){
                        cout<<"   ";
                    if(p_n[j]&&p_s[j]!=0){
                    if(p_n[j]>=2&&p_n[j]<10){
                        cout<<"¢j";
                        for(i=0;i<3;i++){
                           cout<<p_n[j]<<" ";
                        }
                        cout<<p_n[j]<<" ¢y";
                        cout<<"  ";
                    }
                    else if(p_n[j] == 10){
                        cout<<"¢j";
                        for(i=0;i<2;i++){
                            cout<<p_n[j]<<" ";
                        }
                        cout<<p_n[j]<<"¢y";
                        cout << "  ";
                    }
                    else if(p_n[j] == 1){
                        cout<<"¢j";
                        for(i=0;i<3;i++){
                            cout<<"A ";
                        }
                        cout<<"A"<<" ¢y";
                        cout<<"  ";
                    }
                    else if(p_n[j] == 11){
                        cout<<"¢j";
                        for(i=0;i<3;i++){
                            cout<<"J ";
                        }
                        cout<<"J"<<" ¢y";
                        cout<<"  ";
                    }
                    else if(p_n[j] == 12){
                        cout<<"¢j";
                        for(i=0;i<3;i++){
                            cout<<"Q ";
                        }
                        cout<<"Q"<<" ¢y";
                        cout<<"  ";
                    }
                    else if(p_n[j] == 13){
                        cout<<"¢j";
                        for(i=0;i<3;i++){
                            cout<<"K ";
                        }
                        cout<<"K"<<" ¢y";
                        cout<<"  ";
                    }
                    }
                    else
                        cout<<"           "<<"   ";
                }
                cout << endl;
                break;
            case 11:
                for(j=0;j<13;j++){
                        cout<<"   ";
                    if(p_n[j]&&p_s[j]!=0){
                    cout<<"¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w"<<"   ";
                    }
                    else
                        cout<<"           "<<"   ";
                }
                cout << endl;
                break;
            }
        }
        cout<<endl;
}

int game::check_cover_or_through_out_card(int *p_n,int *p_s){
    int i,n,s,flag;
    flag = 0;
    for(i=0;i<13;i++){
        n = p_n[i]-1;
        s = p_s[i]-1;

        if(n<0||s<0){
            continue;
        }

        if(n==0){
            if(central_card[n+1][s]==1||central_card[n][0]==1||central_card[n][1]==1||central_card[n][2]==1||central_card[n][3]==1){
                flag = 1;
            }
        }
        else if(n==12){
            if(central_card[n-1][s]==1||central_card[n][0]==1||central_card[n][1]==1||central_card[n][2]==1||central_card[n][3]==1){
                flag = 1;
            }
        }
        else{
            if(central_card[n+1][s]==1||central_card[n-1][s]==1||central_card[n][0]==1||central_card[n][1]==1||central_card[n][2]==1||central_card[n][3]==1){
                flag = 1;
            }
        }
    }
    return flag;
}

void game::cover_card(int c,int *p_n,int *p_s,int *p_cover_n,int *p_cover_s){
    p_cover_n[c-1] = p_n[c-1];
    p_cover_s[c-1] = p_s[c-1];
    p_n[c-1] = p_s[c-1] = 0;
}

int game::through_out_card(int c,int *p_n,int *p_s){
    int n,s;
    n = p_n[c-1]-1;
    s = p_s[c-1]-1;

    if(n==0){
        if(central_card[n+1][s]==1||central_card[n][0]==1||central_card[n][1]==1||central_card[n][2]==1||central_card[n][3]==1){
            central_card[n][s] = 1;
            p_n[c-1] = p_s[c-1] = 0;
            return 1;
        }
        else{
            return 0;
        }
    }
    else if(n==12){
        if(central_card[n-1][s]==1||central_card[n][0]==1||central_card[n][1]==1||central_card[n][2]==1||central_card[n][3]==1){
            central_card[n][s] = 1;
            p_n[c-1] = p_s[c-1] = 0;
            return 1;
        }
        else{
            return 0;
        }
    }
    else{
        if(central_card[n+1][s]==1||central_card[n-1][s]==1||central_card[n][0]==1||central_card[n][1]==1||central_card[n][2]==1||central_card[n][3]==1){
            central_card[n][s] = 1;
            p_n[c-1] = p_s[c-1] = 0;
            return 1;
        }
        else{
            return 0;
        }
    }
}

int game::findfirst(){
    int a = card [6][0] ;
    int i;
    central_card[6][0] = 1;
    cout<<endl;
    if(a>=1&&a<=13){
        central_card[6][0] = 1;
        for(i=0;i<13;i++){
            if(p1_n[i]==7&&p1_s[i]==1){
                p1_n[i] = p1_s[i] = 0;
                return 1;
                break;
            }
        }
    }
    else if(a>=14&&a<=26){
        central_card[6][0] = 1;
        for(i=0;i<13;i++){
            if(p2_n[i]==7&&p2_s[i]==1){
                p2_n[i] = p2_s[i] = 0;
                return 2;
                break;
            }
        }
    }
    else if(a>=27&&a<=39){
        central_card[6][0] = 1;
        for(i=0;i<13;i++){
            if(p3_n[i]==7&&p3_s[i]==1){
                p3_n[i] = p3_s[i] = 0;
                return 3;
                break;
            }
        }
    }
    else if(a>=40&&a<=52){
        central_card[6][0] = 1;
        for(i=0;i<13;i++){
            if(user_n[i]==7&&user_s[i]==1){
                user_n[i] = user_s[i] = 0;
                return 4;
                break;
            }
        }
    }
}

void game::player1_move(){
    int i,j,choose,a,b,c;
    if(check_cover_or_through_out_card(p1_n,p1_s)==1){
        choose = (rand()%13)+1;
        if(choose>0&&choose<14&&p1_n[choose-1]!=0&&p1_s[choose-1]!=0){
            if(through_out_card(choose,p1_n,p1_s)==0){
                player1_move();
            }
        }
        else{
            player1_move();
        }
    }
    else if(check_cover_or_through_out_card(p1_n,p1_s)==0){
        c = (rand()%13)+1;
        if(p1_n[c-1]==0){
            player1_move();
        }
        else if(c<1||c>13){
            player1_move();
        }
        else{
            cover_card(c,p1_n,p1_s,p1_cover_n,p1_cover_s);
        }
    }
}

void game::player2_move(){
    int i,j,choose,a,b,c,e;
    if(check_cover_or_through_out_card(p2_n,p2_s)==1){
        choose = (rand()%13)+1;
        if(choose>0&&choose<14&&p2_n[choose-1]!=0&&p2_s[choose-1]!=0){
            if(through_out_card(choose,p2_n,p2_s)==0){
                player2_move();
            }
        }
        else{
            player2_move();
        }
    }
    else if(check_cover_or_through_out_card(p2_n,p2_s)==0){
        c = (rand()%13)+1;
        if(p2_n[c-1]==0){
            player2_move();
        }
        else if(c<1||c>13){
            player2_move();
        }
        else{
            cover_card(c,p2_n,p2_s,p2_cover_n,p2_cover_s);
        }
    }
}

void game::player3_move(){
    int i,j,choose,a,b,c,e;
    if(check_cover_or_through_out_card(p3_n,p3_s)==1){
        choose = (rand()%13)+1;
        if(choose>0&&choose<14&&p3_n[choose-1]!=0&&p3_s[choose-1]!=0){
            if(through_out_card(choose,p3_n,p3_s)==0){
                player3_move();
            }
        }
        else{
            player3_move();
        }
    }
    else if(check_cover_or_through_out_card(p3_n,p3_s)==0){
        c = (rand()%13)+1;
        if(p3_n[c-1]==0){
            player3_move();
        }
        else if(c<1||c>13){
            player3_move();
        }
        else{
            cover_card(c,p3_n,p3_s,p3_cover_n,p3_cover_s);
        }
    }
}


void game::find_winer(){
    int i,p1=0,p2=0,p3=0,user=0;
    for(i=0;i<13;i++){
        p1 = p1+p1_cover_n[i];
    }
    for(i=0;i<13;i++){
        p2 = p2+p2_cover_n[i];
    }
    for(i=0;i<13;i++){
        p3 = p3+p3_cover_n[i];
    }
    for(i=0;i<13;i++){
        user = user+user_cover_n[i];
    }
    cout<<endl;
    cout<<"GAME OVER!!!!"<<endl;
    cout<<"Player1's points is:"<<p1<<endl;
    cout<<"Player2's points is:"<<p2<<endl;
    cout<<"Player3's points is:"<<p3<<endl;
    cout<<"Your points is:"<<user<<endl;
    cout<<endl;

    if(p1<p2&&p1<p3&&p1<user){
        cout<<"Winer is Player1! You are lose~"<<endl;
        cout<<endl;
    }
    if(p2<p1&&p2<p3&&p2<user){
        cout<<"Winer is Player2! You are lose~"<<endl;
        cout<<endl;
    }
    if(p3<p1&&p3<p2&&p3<user){
        cout<<"Winer is Player3! You are lose~"<<endl;
        cout<<endl;
    }
    if(user<p1&&user<p2&&user<p3){
        cout<<"You are win!"<<endl;
        cout<<endl;
    }

    if(p1==p2&&p1<p3&&p1<user){
        cout<<"Winer is Player1 and Player2! You are lose~"<<endl;
        cout<<endl;
    }
    if(p1==p3&&p1<p2&&p1<user){
        cout<<"Winer is Player1 and Player3! You are lose~"<<endl;
        cout<<endl;
    }
    if(p1==user&&p1<p3&&p1<p2){
        cout<<"You are win!"<<endl;
        cout<<endl;
    }
    if(p2==p3&&p2<p1&&p2<user){
        cout<<"Winer is Player2 and Player3! You are lose~"<<endl;
        cout<<endl;
    }
    if(p2==user&&p2<p3&&p2<p1){
        cout<<"You are win!"<<endl;
        cout<<endl;
    }
    if(p3==user&&p3<p1&&p3<p2){
        cout<<"You are win!"<<endl;
        cout<<endl;
    }

    if(p1==p2&&p2==p3&&p1<user){
        cout<<"You are lose~"<<endl;
        cout<<endl;
    }
    if(user==p2&&user==p3&&user<p1){
        cout<<"You are win!"<<endl;
        cout<<endl;
    }
    if(p1==user&&p1==p3&&user<p2){
        cout<<"You are win!"<<endl;
        cout<<endl;
    }
    if(p1==p2&&p1==user && user<p3){
        cout<<"You are win!"<<endl;
        cout<<endl;
    }

    if(p1==p2&&p2==p3&&p3==user){
        cout<<"No one is winer~~~"<<endl;
        cout<<endl;
    }
}



