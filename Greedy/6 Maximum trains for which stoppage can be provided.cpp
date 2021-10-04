//sort in descending order
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool comp(const vector<int> &arr1, const vector<int> &arr2){
        return arr1[1]<arr2[1]; 
    }
   
int maxtop(vector<vector<int>> arr,int n, int m){
    //sort thr array based on departure time
    sort(arr.begin(),arr.end(), comp);
    int ans_arr[n+1];
    memset(ans_arr,-1,sizeof(ans_arr));
    int ans=0;
    //checking each element of the arr
    for(int i=0;i<m;i++){
        int index=arr[i][2];
        if(ans_arr[index]==-1){
            ans++;
            ans_arr[index]=arr[i][1];
        }
        else if(ans_arr[index]<=arr[i][0]){
           ans_arr[index]=arr[i][1];
           ans++;
        }
    }
    return ans;
}
int main() {
    int n=3, m=6;
    //N is number of platforms and m is number of trains
    //Array has arrival time, departure time and platform number
     vector<vector<int>> arr={
        {1000,1030,1},
        {1010,1030,1},
        {1000,1020,2},
        {1030,1200,2},
        {1200,1230,3},
        {900,1005,1}
        
    };
    cout<<maxtop(arr,n,m)<<endl;

    return 0;
}
