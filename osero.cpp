#include <iostream>
#include <iomanip>
using namespace std;

#define BOARD_WIDTH 8
#define BOARD_HEIGHT 8

const int player1 = 1;
const int player2 = 2;

char board[BOARD_HEIGHT][BOARD_WIDTH] ={};

void initialize()//盤面初期化
{
     for(int i=0;i<BOARD_HEIGHT;i++)
    {
        for(int j=0;j<BOARD_WIDTH;j++)
        {
            board[i][j] = '.';
            if(i==3)
            {
                if(j==3){board[i][j] = '@';}
                if(j==4){board[i][j] = '$';}                                
            }
            if(i==4)
            {
                if(j==3){board[i][j] = '$';}
                if(j==4){board[i][j] = '@';}                                
            }
        }
    }
}

void print()//盤面表示
{
    system("cls");
    cout<<" ";
    for(int i=0;i<BOARD_WIDTH;i++)
    {
        cout<<setw(3)<<i+1;
    }
    cout<<endl;
    for(int i=0;i<BOARD_HEIGHT;i++)
    {
        cout<<i+1;
        for(int j=0;j<BOARD_WIDTH;j++)
        {
            cout<<setw(3)<<board[i][j];
        }
        cout<<endl;
    }
}

void input(int player)//入力
{
    int h,w;
    cout<<"height,width : ";
    while(cin>>h>>w,board[h-1][w-1]!='.')
    {
        cout<<"height,width : ";
    }
    if(player==player1){board[h-1][w-1] = '@';}
    else{board[h-1][w-1] = '$';}
}

int check(int h,int w)//オセロがおけるかチェックする
{

}

void start()
{
    initialize();//盤面初期化
    int player = player1;
    int turn = 1;
    while(true)
    {
        print();//盤面表示
        input(player);
        if(turn%2==0){player=player1;}
        else{player=player2;}
        turn++;
    }
}
int main()
{
    start();
}