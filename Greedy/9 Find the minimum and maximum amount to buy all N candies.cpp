class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        //will have min amount and max amount
        if(K>N){
            return {0,0};
        }
        vector<int> ans;
        sort(candies,candies+N);
        
        int min_val=0,max_val=0,total_sum=0;
        for(int i=0;i<N;i++){
            if (i<ceil((double)N/(K+1)))
           { min_val+=candies[i];
             max_val+=candies[N-i-1];  
           }
           else{
               break;
           }
            
        }
        ans.push_back(min_val);
        ans.push_back(max_val);
        return ans;
    }
};
