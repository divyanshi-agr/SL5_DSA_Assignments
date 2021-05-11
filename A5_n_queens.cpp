#include<iostream>
#include <cmath>
using namespace std;
 int counter = 1;
bool isSafe(int chessboard[][20], int i, int j, int n)
{
    //Check for column
    for (int row = 0; row < i; row++)
    {
        if(chessboard[row][j] == 1) 
            return false;
    }
    //Check for left diagonal
    int x = i;
    int y = j;
    while(x >= 0 && y >= 0)
    {
        if(chessboard[x][y] == 1)
            return false;
        
        x--;
        y--;
    }
    //Check for right diagonal
    x = i;
    y = j;
    while(x >= 0 && y < n)
    {
        if(chessboard[x][y] == 1)
            return false;
        
        x--;
        y++;
    }
    //If safe to place queen
    return true;
}

void print(int chessboard[][20], int n)
{
     for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(chessboard[i][j] == 1)
                    cout << "Q ";

                else
                    cout << "_ ";   
            }
            cout << endl;
        }
        counter++;
}

bool NQueens(int chessboard[][20], int i, int n) //i is the current row
{
    //Base case
    if(i == n)
    {
        cout<<"Solution "<<counter<<" :"<<endl;
       
        print(chessboard, n);
        cout << endl;
        
        return false;
    }

    for(int j = 0; j < n; j++) 
    {
        if(isSafe(chessboard, i, j, n))
        {
            //Place the queen, assuming i,j is right position
            chessboard[i][j] = 1;

            bool canPlaceNextQueen = NQueens(chessboard, i+1, n);
            if(canPlaceNextQueen)
                return true;

            //When i,j not the right position, assumption wrong
            chessboard[i][j] = 0; //backtrack
        }
    }

    //When all positions to place queen in current row are NOT safe
      
    return false;
   
}



int main()
{
    int n, chessboard[20][20] = {0};
    cout << "Enter n (no. of queens to be placed on n x n chessboard): ";
    cin >> n;
    if(n < 4) {
        cout << "No solution to n-queens problem"<<endl;
    } else {
        NQueens(chessboard, 0, n); //starting row is 0th row
    }
    
}