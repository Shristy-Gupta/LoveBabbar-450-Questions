#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


 // } Driver Code Ends

class Solution 
{
    public:
    //Function to find a solved Sudoku. 
    bool ans;
    bool checkrowvalid(int grid[N][N], int x, int y, int val){
     //This function will return true iff there are no element in the row with the val        
       for(int i=0;i<N;i++){
           if(grid[x][i]==val){
               return false;
           }
       }
       return true;
    }
     bool checkcolvalid(int grid[N][N], int x, int y, int val){
     //This function will return true iff there are no element in the col with the val        
       for(int i=0;i<N;i++){
           if(grid[i][y]==val){
               return false;
           }
       }
       return true;
    }
    bool checkgridvalid(int grid[N][N], int x, int y, int val){
     //This function will return true iff there are no element in the 3*3 grid with the val 
     int k1=x/3, k2=y/3;
     int startrow=k1*3,startcol=k2*3;
       for(int i=0;i<3;i++){
           for(int j=0; j<3; j++){
               if(grid[startrow+i][startcol+j]==val){
                   return false;
               }
           }
       }
       return true;
    }
    //Function to print grids of the Sudoku.
    void printGridHelper (int grid[N][N]) 
    {
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cout<<grid[i][j]<<" ";
            }
            //cout<<endl;
        } 
    }
    void SolveSudokuhelper(int grid[N][N], int x, int y){
       if(x==N){
           ans= true;
           printGridHelper(grid);
           return;
       }
       int nextx,nexty;
       
       if(y==N-1){
           nextx=x+1;
           nexty=0;
           
       }
       else{
           nextx=x;
           nexty=y+1;
       }
       if(grid[x][y]!=0){
           return SolveSudokuhelper(grid,nextx,nexty);
       }
       else{
           for(int i=1;i<=9;i++){
               
               if(checkrowvalid(grid,x,y,i) and checkcolvalid(grid,x,y,i) and checkgridvalid(grid,x,y,i)){
                   grid[x][y]=i;
                   SolveSudokuhelper(grid,nextx,nexty);
                   grid[x][y]=0;
               }
           }
          
       }
    }
    bool SolveSudoku(int grid[N][N])  
    { 
      ans=false;    
      SolveSudokuhelper(grid,0,0); 
      return ans;
    }
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        return;
    }
    
};

// { Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}  // } Driver Code Ends
