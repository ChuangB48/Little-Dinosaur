#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
int score=0,player_dir=25,speed=30,jumphight[6]={0};
bool isFinished=false;
void finish();
void record(){
    system("cls");
    cout << "\033[1mRECORDS\n\nScore:" << score << "\n";
    for(int a=0;a<6;a++){
        if(a==0){
            cout << a+1 << " block of obstacles:" << jumphight[a];
        }
        else{
            cout << a+1 << " blocks of obstacles:" << jumphight[a];
        }
        cout << "\n";
    }
    cout << "Speed:" << 30-speed << "\033[25;70HPerss esc to go back.";
    while(true){
        if(GetAsyncKeyState(0x1B)&0x8000){
            finish();
            break;
        }
    }
}
void finish(){
    Sleep(620);
    cout << "\033[30;41m";
    system("cls");
    cout << "\033[0;0H\033[37;41m\033[1mGAME OVER!\n\n> records <\n  quit\n";
    int select=0;
    while(true){
        if(GetAsyncKeyState(0x0D)&0x8000){
            if(select==0){
                record();
                break;
            }
            if(select==1) break;
        }
        if(GetAsyncKeyState(0x26)&0x8000&&select==1){
            select=0;
            cout << "\033[4;0H \033[4;11H \033[3;0H>\033[3;11H<";
        }
        if(GetAsyncKeyState(0x28)&0x8000&&select==0){
            select=1;
            cout << "\033[4;0H>\033[4;11H<\033[3;0H \033[3;11H ";
        }
    }
}
void tree(){
    srand(time(NULL));
    while(!isFinished){
        int tall=rand()%6+1;
        for(int a=100;a>=0;a--){
            if(a==20){
                if(player_dir>=26-tall){
                    finish();
                    isFinished=true;
                    break;
                }
            }
            for(int b=0;b<tall;b++){
                string tree_locate="\033["+to_string(25-b)+";"+to_string(a)+"H\033[36;40m ";
                if(a==0){
                    if(speed>1) speed--;
                    tree_locate="\033["+to_string(25-b)+";"+to_string(a)+"H\033[30;46m ";
                }
                else if(a!=100) tree_locate+="\033[36;46m ";
                cout << tree_locate;
            }
            if(a==18){
                jumphight[tall-1]++;
                score++;
                cout << "\033[0;0H\033[30;46mscore:"+to_string(score);
            }
            Sleep(speed);
        }
    }
}
void player(){
    cout << "\033[25;20H\033[30;41m ";
    while(!isFinished){
        if(GetAsyncKeyState(0x20)&0x8000){
            int high=5,time=2;
            for(int a=0;a<=high;a++){
                Sleep(time);
                player_dir=24-a;
                cout << "\033["+to_string(24-a)+";20H\033[30;41m \033["+to_string(25-a)+";20H\033[30;46m ";
                time<<=1;
            }
            for(int a=high;a>=0;a--){
                Sleep(time);
                player_dir=25-a;
                cout << "\033["+to_string(25-a)+";20H\033[30;41m \033["+to_string(24-a)+";20H\033[30;46m ";
                time>>=1;
            }
        }
    }
}
void screen(){
    cout << "\033[30;46m";
    system("cls");
    cout << "\033[0;0H\033[30;46mscore:" << score << "\033[30;43m\033[2;82H  \033[4;80H      \033[3;76H  \033[3;88H  \033[5;78H          \033[6;74H  \033[6;78H          \033[6;90H  \033[7;78H          \033[8;80H      \033[9;76H  \033[9;88H  \033[10;82H  \033[30;47m\033[5;20H    \033[6;18H       \033[6;29H   \033[7;16H                  \033[8;15H                    \033[9;47H     \033[9;55H  \033[10;45H              \033[11;46H            \033[26;0H";
    for(int a=0;a<100;a++){
        cout << "\033[30;45m ";
    }
    thread obstacle(tree);
    obstacle.detach();
    player();
}
void start();
void rule(){
    system("cls");
    cout << "\033[1mRULES\n\nUse space to jump to dodge obstacles.\nDodge as more obstacles as you can.\nAnd, LET'S GO!!!\033[25;70HPerss esc to go back.";
    while(true){
        if(GetAsyncKeyState(0x1B)&0x8000){
            start();
            break;
        }
    }
}
void start(){
    system("cls");
    cout << "\033[5;30H/\\\033[5;70H/\\\033[6;29H/  \\____________________________________/  \\\033[7;29H|\033[7;72H|\033[8;29H|\033[8;72H|\033[9;29H|\033[9;33H____________________________________\033[9;72H|\033[10;29H\\  /\033[10;69H\\  /\033[11;30H\\/\033[11;70H\\/\033[8;43HLittle Dinosaur\033[12;46H>\033[12;48HSTART\033[12;54H<\033[14;48HRULES";
    int select=0;
    while(!isFinished){
        if(GetAsyncKeyState(0x0D)&0x8000){
            if(select==0){
                screen();
                break;
            }
            if(select==1){
                rule();
                break;
            }
        }
        if(GetAsyncKeyState(0x26)&0x8000&&select==1){
            select=0;
            cout << "\033[12;46H>\033[12;54H<\033[14;46H \033[14;54H ";
        }
        if(GetAsyncKeyState(0x28)&0x8000&&select==0){
            select=1;
            cout << "\033[14;46H>\033[14;54H<\033[12;46H \033[12;54H ";
        }
    }
}
int main(){
    cout << "\033[?25l";
    start();
    return 0;
}
