class Solution{
    public:
    vector<string> ans;
    
    void findPathHelper(vector<vector<int>> &arr,int n,int x, int y,string res){
        if(x<0 || y<0 || x>=n || y>=n || arr[x][y]==0){
            return;
        }
        if(x==n-1 && y==n-1){
            ans.push_back(res);
            return;
        }
        arr[x][y]=0;
        findPathHelper(arr,n,x+1,y,res+"D");
        findPathHelper(arr,n,x,y-1,res+"L");
        findPathHelper(arr,n,x,y+1,res+"R");
        findPathHelper(arr,n,x-1,y,res+"U");
        
        arr[x][y]=1;
        
    }
    vector<string> findPath(vector<vector<int>> &arr, int n) {
        
        if(n<=0  || arr[0][0]==0 || arr[n-1][n-1]==0){
            return ans;
        }
     
       findPathHelper(arr,n,0,0,"");
       return ans;
    }
};
