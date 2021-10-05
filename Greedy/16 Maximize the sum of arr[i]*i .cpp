class Solution{
    public:
    int Maximize(int a[],int n)
    {
        long long int MOD=1000000007;
        long long int ans=0;
        sort(a,a+n);
        for(long long int i=0;i<n;i++){
            ans=(ans % MOD + ( (a[i] % MOD) * (i % MOD) ) % MOD ) % MOD;
        }
        return ans % MOD;
    }
};
