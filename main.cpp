#include <iostream>
#include <windows.h>
#include <conio.h>

#define Num1 49
#define Num2 50
#define Num3 51
#define Num4 52
#define Num5 53
#define Num6 54
#define Num7 55
#define Num8 56
#define Num9 57

using namespace std;

//Function Prototype

void drawShape();
int OddEven (int);
void XOChar(int x, int y);
void putChar ();
int Winner (int arr[18][9],int Num);
void xyPosition (int &, int &);
//Global Variables
int sign = 0;

const int row = 10, col = 21;
//int xNum1
int xArr [18][9] = {0};
int oArr [18][9] = {0};
int keyArr [9]= {0};

int arrayOne [row][col] =
{
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0,1},
    {1,0,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0,1},
    {1,0,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0,1},
    {1,0,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
};

int main()
{
    cout<<"Hello In Tic - Tac - Toe "<<endl;
    cout<<"First Player is X and Second Player Is O"<<endl;
    drawShape();

    putChar();

    system("pause");

    /*XOChar(00,20);
    for(int i = 0; i < 18; i++)
    {
        for(int k = 0; k < 9; k++)
        {
            cout<<xArr[i][k]<<" ";
        }
        cout<<endl;
    }

    cout<<endl;

    for(int i = 0; i < 18; i++)
    {
        for(int k = 0; k < 9; k++)
        {
            cout<<oArr[i][k]<<" ";
        }
        cout<<endl;
    }*/
    return 0;
}

void drawShape()
{
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            switch(arrayOne[i][j])
            {
            case 0:
                cout<<" ";
                break;
            case 1:
                cout<<char(219);
                break;
            default:
                cout<<" ";
            }
        }
        cout<<" "<<endl;
    }
}

void XOChar(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void putChar ()
{
    int x = 12, y = 5;
    int chr = 1;
    int win = 0;
    while(true)
    {
        while(true)
        {
            int sFlag = 0;
            sign = getch();
            for(int k = 0; k < 9; k++)
            {
                if(keyArr[k] == sign)
                {
                    XOChar(25,7);
                    cout<<"\a\a Please ReEnter the position"<<endl;
                    sFlag = 1;
                }
            }
            if(sFlag == 1)
                continue;
            else
            {
                keyArr[chr-1] = sign;
                break;
            }
        }

        xyPosition(x,y);

        if(OddEven(chr) == 1)
            xArr[x][y] = 1;
        else if(OddEven(chr) == 2)
            oArr[x][y] = 2;
        //cout<<OddEven(chr);
        XOChar(x,y+2);

        if(OddEven(chr) == 2)
        {
            cout<<"O";
            if(chr >= 5)
               win = Winner(oArr,2) +9;
               //cout<<win<<endl;
        }

        else
        {
            cout<<"X";
            if(chr >= 5)
                win = Winner(xArr,1) + 4;
                //cout<<win<<endl;
        }

        if(win == 10)
        {
            XOChar(0,12);
            cout<<"Player 2 (O) win"<<endl;
            break;
        }
        else if(win == 5)
        {
            XOChar(00,12);
            cout<<"Player 1 (X) win"<<endl;
            break;
        }
        else
            chr++;
        if(chr >9)
        {
            XOChar(0,15);
            break;
        }
        //cout<<sign<<endl;
    }
}

int OddEven (int num)
{
    //cout<<"ODDEVEN"<<endl;
    if(num % 2 == 0)
    {
        return 2;
        cout<<2<<endl;
    }
    else if(num % 2 != 0)
    {
        return 1;
        cout<<1<<endl;
    }
}

int Winner(int arr[18][9],int Num)
{
    if(arr[2][2] == arr[10][2] && arr[2][2] == arr[17][2] && arr[2][2] == Num)
        return 1;
    else if(arr[2][5] == arr[10][5] && arr[17][5] == arr[2][5] && arr[2][5] == Num)
        return 1;
    else if(arr[2][8] == arr[10][8] && arr[17][8] == arr[2][8] && arr[2][8] == Num)
        return 1;
    else if(arr[2][2] == arr[2][5] && arr[2][2] == arr[2][8] && arr[2][2] == Num)
        return 1;
    else if(arr[10][2] == arr[10][5] && arr[10][2] == arr[10][8] && arr[10][2] == Num)
        return 1;
    else if(arr[17][2] == arr[17][5] && arr[17][2] == arr[17][8] && arr[17][2] == Num)
        return 1;
    else if(arr[2][2] == arr[10][5] && arr[2][2] == arr[17][8] && arr[2][2] == Num)
        return 1;
    else if(arr[2][8] == arr[10][5] && arr[2][8] == arr[17][2] && arr[2][8] == Num)
        return 1;
    else
        return 0;
}

void xyPosition (int &x, int &y)
{
    if(sign == Num1)
        {
            x = 2;
            y = 8;
        }
        else if(sign == Num2)
        {
            x = 10;
            y = 8;
        }
        else if(sign == Num3)
        {
            x = 17;
            y = 8;
        }
        else if(sign == Num4)
        {
            x = 2;
            y = 5;
        }
        else if(sign == Num5)
        {
            x = 10;
            y = 5;
        }
        else if(sign == Num6)
        {
            x = 17;
            y = 5;
        }
        else if(sign == Num7)
        {
            x = 2;
            y = 2;
        }
        else if(sign == Num8)
        {
            //cout<<"H";
            x = 10;
            y = 2;
        }
        else if(sign == Num9)
        {
            x = 17;
            y = 2;
        }
}
