class Solution {
  public:
  vector<vector<int>> ans;

  void solve(vector<int> &A,vector<int> &sans, int B, int index){
      if(index>=A.size()){
          return;
      }
      if(B<0){
          return;
      }
      if(B==0){
          //Here we also need to check if the set already contains in oyr ans vector
          //Make string of vectors
          if(sans.size()!=0){
              ans.push_back(sans);
              //sans.clear();

          }
          return ;
      }
      if(B>=A[index]){
          sans.push_back(A[index]);
          solve(A,sans,B-A[index],index);
          sans.pop_back();
      }
      solve(A,sans,B,index+1);
      
  }
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        // Your code here
        //This looks combination of 0-1 Unbound knapsack and the way we need to print
        //We can make it print but thats tricly!
        //First we should sort the array
        unordered_set<int> s(A.begin(),A.end());
        vector<int> K;
        K.insert(K.end(), s.begin(), s.end());
        sort(K.begin(),K.end());
        vector<int> sans;
        solve(K,sans,B,0);
        return ans;
    }
};
