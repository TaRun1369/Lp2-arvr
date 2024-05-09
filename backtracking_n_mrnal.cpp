#include<iostream>
#include <vector>
using namespace std;

class NQueen
{

int n;
public:
NQueen(int val){n=val;}

bool isSafe(int row,int col,vector<vector<char>> board,int n){
    int duprow=row;
    int dupcol=col;
    while(row>=0 && col>=0){
        if(board[row][col]=='Q') return false;
        row--;
        col--;
    }
    row=duprow;
    col=dupcol;
    while (col>=0)
    {
        if(board[row][col]=='Q') return false;
        col--;
    }
    col=dupcol;
    row=duprow;
    while (row<n && col>=0)
    {
        if(board[row][col]=='Q') return false;
        row++;
        col--;
    }
    return true;
}
void display(vector<vector<char>>&board)
{
    cout<<"----------------------------------------------------------"<<endl;
    for(int i = 0 ; i<n;i++)
    {
        for(int j = 0 ; j<n;j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"----------------------------------------------------------"<<endl;
}

void bnb()
{
     vector<vector<char>>board(n , vector<char>(n , '.'));

    return bnbSolver(0  , board );
   
}

void bnbSolver(int col , vector<vector<char>> &board)
{ 
 if(col==n)
    {
        display(board);
        return;
        
    }
    for(int row = 0 ; row<n;row++)
    {
        if(isSafe(row,col,board,n))
        {
            board[row][col] = 'Q';
            bnbSolver(col + 1 , board);
             board[row][col] = '.';        
        }
    }
  
}
};




int main()
{
    cout<<"Enter the number of queens : ";
    int n;
    cin>>n;
    if(n==2 || n==3) cout<<"terminal states"<<endl;
    NQueen obj(n);
    // obj.backtracking();
    // return 0;
    obj.bnb();
}