class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    //sliding window?
    sort(a.begin(),a.end());
    int diff=INT_MAX;
    for(long long i=0;i<n;i++){
         if(i+m-1<n && a[i+m-1]-a[i]<diff){
             diff=a[i+m-1]-a[i];
         }
    }
    return diff;
    
    }   
};
