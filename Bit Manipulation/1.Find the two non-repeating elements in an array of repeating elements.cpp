#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        vector<int> ans;
        int x=0,y=0;
        int _xor=nums[0];
        for(int i=1;i<nums.size();i++){
            //removes all the repeating numbers
            _xor^=nums[i];
        }
        int set_bit_rightmost_no= _xor & ~(_xor -1);
        
        for(int i=0;i<nums.size();i++){
           if(set_bit_rightmost_no & nums[i]){
               x^=nums[i];
           }
           else{
               y^=nums[i];
           }
        }
        if(x<y){
            ans={x,y};
        }
        else{
            ans={y,x};
        }
        return ans;
    }
};

// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}  // } Driver Code Ends
