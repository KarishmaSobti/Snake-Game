#include<iostream>
#include<cstdlib>
#include<windows.h>
#include<conio.h>
using namespace std;


void gotoXY(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

bool gameover;
const int width=20;
const int height=20;
int X,Y,fruitX,fruitY,score;
int tailX[100],tailY[100];
int ntail;
enum edirection {STOP=0,LEFT,RIGHT,UP,DOWN};
edirection dir;

void setup(){
    gameover=false;
    dir=STOP;
    X=width/2;
    Y=height/2;
    fruitX=rand()%width;
    fruitY=rand()%height;
    score=0;

}
void draw(){
   gotoXY(0, 0);

    for(int i=0;i<width+2;i ++)cout<<"#";
    cout<<endl;
    
    for(int i=0;i<height;i++){
       for(int j=0;j<width;j++){
            if(j==0)cout<<"#";
            if(i==Y && j==X){
                cout<<"O";}
            else if(i==fruitY && j==fruitX){
                cout<<"F";
            }
            
            else{
                bool print=false;
                for(int k=0;k<ntail;k++){
                    
                    if(tailX[k]==j && tailY[k]==i){
                        cout<<"o";
                        print=true;
                        break;
                    }
                }
                if(!print){cout<<" ";
            }
        }
           
                
             if( j==width-1)cout<<"#";
                
           
        
        }
    cout<<endl;
    }



    for(int i=0;i<width+2;i++)cout<<"#";
    cout<<endl;
    cout<<"score="<< score<<endl;

}
void input(){
    if(_kbhit()){
        switch(_getch()){
            case'a':
             dir=LEFT;
             break;
            case'd':
             dir=RIGHT;
             break;
            case'w':
             dir=UP;
             break;
            case's':
             dir=DOWN;
             break;
            case'x':
             gameover=true;
             break;

        }
        
    }
}
void logic(){
int prevX=tailX[0];
int prevY=tailY[0];
int prev2X , prev2Y;
tailX[0]=X;
tailY[0]=Y;
for(int i=1;i<ntail;i++){
prev2X=tailX[i];
prev2Y=tailY[i];
tailX[i]=prevX;
tailY[i]=prevY;
prevX=prev2X;
prevY=prev2Y;
}
switch(dir){
case LEFT:
 X--;
 break;
case RIGHT:
 X++;
 break;
case UP:
 Y--;
 break;
case DOWN:
 Y++;
default:
 break;





}
//if(X>width ||X<0 || Y<0||Y>height)
// gameover=true;
if(X>=width) X=0;else if(X<0)X=width-1;
if (Y>=height)Y=0;else if (Y<0)Y=height-1;
for(int i=0;i<ntail;i++){
 if(tailX[i]==X && tailY[i]==Y){
 gameover=true;
}
}
if(X==fruitX && Y==fruitY){
score=score+10;
fruitX=rand()%width;
fruitY=rand()%height;
ntail++;
}

}
int main(){
   setup();
   while(!gameover){
    draw();
    input();
    logic();
    Sleep(100);
   }

    return 0;
}