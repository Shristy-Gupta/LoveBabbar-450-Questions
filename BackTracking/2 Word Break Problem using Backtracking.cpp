class Solution{
public:
    vector<string> ans;
    void wordBreakHelper(string given, vector<string>& dict, string k){
       int n=given.length();
       if(n==0){
           ans.push_back(k);
           return;
       }
      for(int i=0;i<n;i++){
          string prefix=given.substr(0,i+1);
          if(find(dict.begin(),dict.end(),prefix)!=dict.end()){
              string suffix=given.substr(i+1);
              if(i<n-1)
              wordBreakHelper(suffix,dict,k+prefix+" ");
              else
              wordBreakHelper(suffix,dict,k+prefix);
          }
      }
    }
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
       string a="";    
       wordBreakHelper(s,dict,a);
       return ans;
    }
};
