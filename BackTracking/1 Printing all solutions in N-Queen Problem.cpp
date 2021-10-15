#include<bits/stdc++.h>
using namespace std;
int board[11][11];

bool can_be_placed(int n,int row, int col){
    //check above
    for(int i=row-1;i>=0;i--){
        if(board[i][col]==1){
            return false;
        }
    }
    //check right diagonal
    for(int i=row-1, j=col+1; i>=0 && j<n; i--, j++){
        if(board[i][j]==1){
            return false;
        }
    }
    //check left diagonal
    for(int i=row-1,j=col-1;i>=0 && j>=0 ; i--, j--){
        if(board[i][j]==1){
            return false;
        }
    }
    return true;
}
void nqueenshelper(int n,int row){
    if(row==n){
        //print
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<board[i][j]<<" ";
            }
        }
        cout<<endl;
    }
    for(int col=0;col<n;col++){
        if(can_be_placed(n,row,col)){
            board[row][col]=1;
            nqueenshelper(n, row+1);
            board[row][col]=0;
        }
    }
    
}

void nqueens(int n){
    memset(board, 0, sizeof(board));
    if(n==0){
        return;
    }
    return nqueenshelper(n,0);
}
int main(){
    int n; cin>>n;
    nqueens(n);
    return 0;
}
