#include<bits/stdc++.h>
using namespace std;
vector<int> find(int a[], int n , int x );

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}


// } Driver Code Ends

int binarysearchfirst(int arr[], int x, int start, int end){
    if(start>end){
        return -1;
    }
    int ans=-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(arr[mid]==x){
            ans=mid;
            end--;
        }
        else if(arr[mid]<x){
            start++;
        }
        else{
            end--;
        }
    }
    return ans;
}
int binarysearchsecond(int arr[], int x, int start, int end){
   if(start>end){
        return -1;
    }
    int ans=-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(arr[mid]==x){
            ans=mid;
            start++;
        }
        else if(arr[mid]<x){
            start++;
        }
        else{
            end--;
        }
    }
    return ans;
}
vector<int> find(int arr[], int n , int x )
{
    vector<int> ans;
    // first index
    int first=binarysearchfirst(arr,x,0,n-1);
    //last index
    int last=binarysearchsecond(arr,x,0,n-1);
    if(first!=-1 && last!=-1){
        ans.push_back(first);
        ans.push_back(last);
        return ans;
    }
    else{
        ans.push_back(-1);
        ans.push_back(-1);
        return ans;
    }
}
