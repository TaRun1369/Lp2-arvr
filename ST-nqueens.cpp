#include <iostream>
#include <vector>
using namespace std;
class branch{
    int n;
public:
    branch(int _n){
        n=_n;
    }
    void print(vector<vector<char>>&board){
        cout<<"--------------------------------------"<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    void bnb(){
        vector<vector<char>>board(n,vector<char>(n,'.'));
        vector<int>rows(n,0);
        vector<int>lower(2*n-1,0);
        vector<int>upper(2*n-1,0);
        bnbsolver(0,board,rows,lower,upper);
    }
    void bnbsolver(int col,vector<vector<char>>&board,vector<int>&rows,vector<int>&lower,vector<int>&upper){
        if(col==n){
            print(board);
            return;
        }

        for(int row=0;row<n;row++){
            if(rows[row]==0 && lower[row+col]==0 && upper[n-1+col-row]==0){
                rows[row]=1;
                lower[row+col]=1;
                upper[n-1+col-row]=1;
                board[row][col]='Q';
                bnbsolver(col+1,board,rows,lower,upper);
                rows[row]=0;
                lower[row+col]=0;
                upper[n-1+col-row]=0;
                board[row][col]='.';

            }
        }
    }
};
int main(){
    int n;
    cout<<"Enter size of board"<<endl;
    cin>>n;
    branch b(n);
    b.bnb();
}