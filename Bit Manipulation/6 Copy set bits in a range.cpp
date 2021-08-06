// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution{
    public:
    int setSetBit(int x, int y, int l, int r){
        if(l<1 || r>32){
            return -1;
        }
        int masklength=(1<<(r-l+1))-1;
        masklength=masklength<<(l-1);
        masklength=masklength & y;
        return x|masklength;
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int x, y, l, r;
        cin>>x>>y>>l>>r;
        
        Solution ob;
        cout<<ob.setSetBit(x, y, l, r)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
