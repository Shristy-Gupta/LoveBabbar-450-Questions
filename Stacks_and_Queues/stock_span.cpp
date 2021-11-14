class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    //https://www.youtube.com/watch?v=p9T-fE1g1pU&list=PL_z_8CaSLPWdeOezg68SKkeLN4-T_jNHd&index=6
    vector <int> calculateSpan(int price[], int n)
    {
       // This is variation of largest greater to left
       //rather than taking pair of the number and index in the stack i am just pushing the index
       vector<int> ans;
       stack<int> st;
       for(int i=0;i<n;i++){
           if(st.empty()){
               ans.push_back(-1);
           }
           else{
               while(!st.empty() and price[st.top()]<=price[i]){
                   st.pop();
               }
               if(st.empty()){
                   ans.push_back(-1);
               }
               else{
                   ans.push_back(st.top());
               }
           }
           st.push(i);
       }
       for(int i=0;i<n;i++){
           ans[i]=i-ans[i];
       }
       return ans;
    }
};
