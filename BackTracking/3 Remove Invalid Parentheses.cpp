class Solution {
public:
    vector<string> ans;
    int checkParentheses(string s){
        int n=s.length();

        stack<char> st;
        for(int i=0;i<n;i++){
          if(s[i]=='('){  
                st.push(s[i]);
           }
          else if(s[i]==')'){
              if(st.empty()){
                  st.push(')');
              }
              else if(st.top()=='('){
                  st.pop();
              }
              else{
                 st.push(')'); 
              }
          }  
        }
        return st.size();
    } 
    void calculate(string s, int max_all_remo, unordered_set<string> &hashset){
        if(max_all_remo == 0){
            if(checkParentheses(s)==0 && hashset.find(s)==hashset.end()){
                ans.push_back(s);
                hashset.insert(s);
            }
            return;
        }
        int n=s.length();
        for(int i=0;i<n;i++){
            string left=s.substr(0,i);
            string right=s.substr(i+1);
            if(hashset.find(left+right)==hashset.end()){
                calculate(left+right,max_all_remo-1,hashset);
                hashset.insert(left+right);    
            }
            
        }
        
    }
    vector<string> removeInvalidParentheses(string s) {
        int n = s.length();
        if(n==0){
            return ans;
        }
        //First we need to check minimum numbers of parantheses we need to delete
        //Second we need to make a recursive call and remove the brackets one by one 
        //Chcek if thats a correct ans 
        //Check if that is not present in our hashset and then add in ans;
        int mra=checkParentheses(s);
        
        unordered_set<string> hashset;
        calculate(s,mra,hashset);
        return ans;
    }
};
