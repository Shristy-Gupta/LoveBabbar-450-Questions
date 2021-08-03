#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int findPosition(int N) {
        if(N==0){
            return -1;
        }
        else if(N%2==1){
            if(N==1){
                return 1;
            }
            else{
                return -1;
            }
        }
        else{
            //N has to be power of 2
            int rmsb=N & -N;
            if(N-rmsb>0){
                return -1;
            }
            else{
                int count1=0;
                while(rmsb){
                  rmsb=rmsb>>1;
                  count1++;
                }
                return count1;
            }
        }
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;

        cin>>N;

        Solution ob;
        cout << ob.findPosition(N) << endl;
    }
    return 0;
}  // } Driver Code Ends
