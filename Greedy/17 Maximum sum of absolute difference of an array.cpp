#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int MaxSumDifference(int a[], int n)
{
    vector<int> new_Array;
    sort(a,a+n);
    int start=0,end=n-1;
    while(start<end){
        new_Array.push_back(a[start]);
        new_Array.push_back(a[end]);
        start++;
        end--;
    }
    if(start==end){
        new_Array.push_back(a[start]);
    }
    //now calculate the difference:
    int max_diff=0;
    for(int i=0;i<n-1;i++){
        max_diff+=abs(new_Array[i+1]-new_Array[i]);
    }
    max_diff+=abs(new_Array[n-1]-new_Array[0]);
    return max_diff;
}
int main() {
    //Maximum sum of absolute difference of any permutation
    //Tricky part is to understand its a Greedy problem
    //By nature this is also a dp problem
    int a[] = { 1, 2, 4, 8 };
    int n = sizeof(a) / sizeof(a[0]);
 
    cout << MaxSumDifference(a, n) << endl;

    return 0;
}
