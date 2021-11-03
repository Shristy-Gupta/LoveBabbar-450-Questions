class Solution {
public:
//https://youtu.be/oZYMOJHWI9w
    void dfs(vector<vector<int>> &am, vector<bool>& vis,int start, int K, int curr_len,bool &ans){
        if(start>=vis.size() || vis[start]==true){
            return;
        }
        if(curr_len>=K){
            ans=true;
            return;
        }
        if(ans==true){
            return;
        }
        vis[start]=true;
        int V=vis.size();
        for(int i=0;i<V;i++){
            if(am[start][i]!=-1 && vis[i]==false){
                dfs(am,vis,i,K,curr_len+am[start][i],ans);
                if(ans){
                    return;
                }
            }
        }
        vis[start]=false;
        
    }
    
    bool pathMoreThanK(int V, int E, int k, int *a) 
    { 
       //given source will always be 0
       //First we will have adjecency matrix and put weights
       vector<vector<int>> am(V,vector<int>(V,-1));
       vector<bool> vis(V,0);
       int edges=E, i=0;
       while(E--){
           int one=a[i];
           i++;
           int two=a[i];
           i++;
           int w=a[i];
           i++;
           am[one][two]=max(w,am[one][two]);
           am[two][one]=max(w,am[one][two]);
       }
       //print adj matrix
       
    //   for(int i=0;i<V;i++){
    //       for(int j=0;j<V;j++){
    //           cout<<am[i][j]<<" ";
    //       }
    //       cout<<endl;
    //   }
       //Now we will do DFS traversal
       bool ans=false;
       dfs(am,vis,0,k,0,ans);
       return ans;
    } 
};
