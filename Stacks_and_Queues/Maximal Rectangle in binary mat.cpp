class Solution {
public:
    public:
    vector<int> nsr(vector<int> arr){
        vector<int> ans;
       stack<int> st;
    int n=arr.size();
    for(int i=n-1;i>=0;i--){
    //Three conditions, if stack is empty
        if(st.empty()){
            ans.push_back(n);
        }
    //If element in stack is less than the element in question
        else if(st.size()>0 and arr[st.top()]<arr[i]){
            ans.push_back(st.top());
        }
    //If the stack top is greater than the element then simply pop
        else if(st.size()>0 and arr[st.top()]>=arr[i]){
            //pop elements
            while(st.size()>0 and arr[st.top()]>=arr[i]){
                st.pop();
            }
            //Semi-condition after popping the elements if the stack size is 0 then simply push -1
            if(st.size()==0){
                ans.push_back(n);
            }
            //Else remove push top element in the array
            else if(arr[st.top()]<arr[i]){
                ans.push_back(st.top());
            }
            
        }
        st.push(i);
    }
//Need to reverse the array
reverse(ans.begin(),ans.end());
    return ans;

        
    }
    vector<int> nsl(vector<int> &arr){
        vector<int> ans;
        stack<int> st;
        int n=arr.size();
        for(int i=0;i<n;i++){
    //Three conditions, if stack is empty
        if(st.size()==0){
            ans.push_back(-1);
        }
    //If element in stack is less than the element in question
        else if(st.size()>0 and arr[st.top()]<arr[i]){
            ans.push_back(st.top());
        }
    //If the stack top is greater than the element then simply pop
        else if(st.size()>0 and arr[st.top()]>=arr[i]){
            //pop elements
            while(st.size()>0 and arr[st.top()]>=arr[i]){
                st.pop();
            }
            //Semi-condition after popping the elements if the stack size is 0 then simply push -1
            if(st.size()==0){
                ans.push_back(-1);
            }
            //Else remove push top element in the array
            else if(arr[st.top()]<arr[i]){
                ans.push_back(st.top());
            }
            
        }
        st.push(i);
    }
//No need to reverse the array
    return ans;

        
    }
    
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> left_index=nsl(heights);
        vector<int> right_index=nsr(heights);
        vector<int> width;
        //Now calculate the width array
        for(int i=0;i<n;i++){
            width.push_back(right_index[i]-left_index[i]-1);
        }
        int ans=0;
        //calcualte the area
        for(int i=0;i<n;i++){
            ans=max(ans,heights[i]*width[i]);
        }
       return ans; 
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> hist(m,0);
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1'){
                    hist[j]+=1;
                }
                else{
                   hist[j]=0; 
                }
            }
            ans=max(ans,largestRectangleArea(hist));
        }
        return ans;
    }
};
