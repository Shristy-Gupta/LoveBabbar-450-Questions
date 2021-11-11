vector<int> Solution::prevSmaller(vector<int> &arr) {
        vector<int> ans;
        stack<int> st;
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(st.empty()){
                ans.push_back(-1);
            }
            else{
                while(!st.empty() and st.top()>=arr[i]){
                    st.pop();
                }
                if(st.empty()){
                  ans.push_back(-1);  
                }
                else if(st.top()<arr[i]){
                    ans.push_back(st.top());
                }
            }
            st.push(arr[i]);
        }
       
        return ans;
}
