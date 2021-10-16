class Solution {
public:
    int uniquePath(int m, int n,int**dp, int x, int y){
        if(x<0 ||y<0 ||x>=m ||y>=n){
            return 0;
        }
        if(x==m-1 && y==n-1){
            return 1;
        }
        if(dp[x][y]!=-1){return dp[x][y];}
        int right=0,down=0;
        if(y+1<n && dp[x][y+1]!=-1){
            right=dp[x][y+1];
        }
        else if(y+1 <n && dp[x][y+1]==-1){
            dp[x][y+1]=uniquePath(m,n,dp,x,y+1);
            right=dp[x][y+1];
        }
        if(x+1<m && dp[x+1][y]!=-1){
            down=dp[x+1][y];
        }
        else if(x+1<m && dp[x+1][y]==-1){
            dp[x+1][y]=uniquePath(m,n,dp,x+1,y);
            down=dp[x+1][y];
        }
        dp[x][y]=right+down;
        return dp[x][y];
    }
    int uniquePaths(int m, int n) {
        if(m==0 || n==0){
            return 1;
        }
        int** dp=new int*[m];
        for(int i=0;i<m;i++){
            dp[i]=new int[n];
            for(int j=0;j<n;j++){
                dp[i][j]=-1;
            }
        }
        return uniquePath(m,n,dp,0,0);
        
    }
};
