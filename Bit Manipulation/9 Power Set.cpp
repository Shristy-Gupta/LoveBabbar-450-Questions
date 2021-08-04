#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
		    int size=s.length();
		    vector<string> result;
		    unsigned int powerset=1<<size;
		    for(int i=0;i<powerset;i++){
		        string val="";
		        for(int j=0;j<size;j++){
		            if(i & (1<<j)){
		                val+=s[j];
		            }
		        }
		        if(val!=""){
		            result.push_back(val);
		        }
		    }
		    return result;
		}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}  // } Driver Code Ends
