class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    bool static compare(Job j1, Job j2){
        //sort the jobs based on their profit!
        return j1.profit>j2.profit;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        vector<int> ans;
        if(n<=0){
            return ans;
        }
        sort(arr,arr+n,compare);
        int scheduled[n];
        memset(scheduled,0,sizeof(scheduled));
        int num=0;
        int profit=0;
        //for each job we will examine the following
        for(int i=0;i<n;i++){
            //we will find a empty field in the scheduled array 
            //if ans empty value is available we will take that Job
                for(int j=min(n,arr[i].dead-1);j>=0;j--){
                    if(scheduled[j]==0){
                        num++;
                        profit+=arr[i].profit;
                        scheduled[j]=1;
                        break;
                      }
                }
            
        }
       ans.push_back(num);
       ans.push_back(profit);
       return ans;
    } 
};
