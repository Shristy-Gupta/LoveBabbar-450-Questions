//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    //https://www.youtube.com/watch?v=g6OxU-hRGtY
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int largestpowerof2(int n){
        int p=0;
        while((1<<p)<=n){
            p++;
        }
        return p-1;
    }
    
    int countSetBits(int n)
    {
        int count1=0;
        if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        int p=largestpowerof2(n);
        count1=p*(1<<p-1)+n-(1<<p)+1;
        //count1=pow(2,p-1)*p+n-pow(2,p)+1;
       
        return count1+countSetBits(n-(1<<p));
    }
};


// { Driver Code Starts.

// Driver code
int main()
{
	 int t;
	 cin>>t;// input testcases
	 while(t--) //while testcases exist
	 {
	       int n;
	       cin>>n; //input n
	       Solution ob;
	       cout << ob.countSetBits(n) << endl;// print the answer
	  }
	  return 0;
}
  // } Driver Code Ends
