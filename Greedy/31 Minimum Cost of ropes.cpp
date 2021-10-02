class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        if(n<=0){
            return 0;
        }
        priority_queue<long long,vector<long long>,greater<long long>> pq;
        //priority_queue<long long> pq;
        for(int i=0;i<n;i++){
            pq.push(arr[i]);
        }
        long long ans=0;
        while(pq.size()!=1){
            long long a=pq.top();
            pq.pop();
            long long b=pq.top();
            pq.pop();
            ans+=a+b;
            pq.push(a+b);
        }
        return ans;
    }
};
