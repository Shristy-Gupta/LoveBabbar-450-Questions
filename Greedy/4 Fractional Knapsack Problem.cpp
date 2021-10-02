class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    struct comp{
        bool operator()(Item i1, Item i2){
            double r1=double(i1.value)/(i1.weight);
            double r2=double(i2.value)/(i2.weight);
            return r1<r2;
        }
    };
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        priority_queue<Item,vector<Item>,comp> pq;
        for(int i=0;i<n;i++){
            pq.push(arr[i]);
        }
        double ans=0.0;
        while(W!=0 && !pq.empty()){
            Item curr=pq.top();
            pq.pop();
            if(curr.weight<=W){
                W-=curr.weight;
                ans+=curr.value;
            }
            else if(curr.weight>W && W!=0){
                ans+=((double)curr.value/curr.weight)*W;
                W=0;
                break;
            }
        }
        return ans;
    }
        
};
