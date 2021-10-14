class Solution
{
	public:
	vector<string> ans;
	    void permutations(string s, int n, int index){
	       
	        if(index==n-1){
	            ans.push_back(s);
	            return;
	        }
	        for(int i=index; i<n; i++){
	            swap(s[i],s[index]);
	            permutations(s,n,index+1);
	            swap(s[i],s[index]);
	        }
	        
	    }
		vector<string>find_permutation(string S)
		{
		    int n=S.length();
		    if(n==0){
		        return ans;
		    }
		    permutations(S,n,0);
		    return ans;
		    
		}
};
