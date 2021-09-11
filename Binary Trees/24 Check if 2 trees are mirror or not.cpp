class Solution {
  public:
    int checkMirrorTree(int n, int e, int A[], int B[]) {
       //given n-ary tree, // e are the number of edges ans size of A and B are 
       //simply the two vertex pairs
       
       unordered_map<int,stack<int>> mp;
       for(int i=0;i<2*e;i+=2){
           mp[A[i]].push(A[i+1]);
       }
       //checking the result from the another tree
       for(int i=0;i<2*e;i+=2){
           if(mp[B[i]].top()!=B[i+1]){
               return false;
           }
           else{
               mp[B[i]].pop();
           }
       }
       return true;
    }
};
