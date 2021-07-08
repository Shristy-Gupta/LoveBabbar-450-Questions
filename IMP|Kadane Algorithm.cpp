// largest sum subarray
#include <iostream>
using namespace std;
int kadane(int *arr, int n){
    int curr_sum=0,best_sum=0;
    for(int i=0;i<n;i++){
        curr_sum+=arr[i];
    
    if(best_sum<curr_sum){
        best_sum=curr_sum;
    }
    if(curr_sum<0){
        curr_sum=0;
    }
    }
    return best_sum;
}

int main() {
    // Write C++ code here
    int arr[]={-5,-4,1,2,3};
    cout<<kadane(arr,5)<<endl;

    return 0;
}
