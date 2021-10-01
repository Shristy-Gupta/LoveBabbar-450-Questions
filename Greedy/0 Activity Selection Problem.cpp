class Solution
{
    public:
    bool static compare(pair<int,int> s1,pair<int,int> s2){
        if(s1.second<s2.second){
            return true;
        }
        else return false;
    }
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        if(n<=1){
            return n;
        }
        pair<int,int> timings[n];
        for(int i=0;i<n;i++){
           timings[i].first=start[i];
           timings[i].second=end[i]; 
        }
        //sort on the basis of start time
        sort(timings,timings+n,compare);
        int last_val=timings[0].second;
        int ans=1;
        for(int i=1;i<n;i++){
            if(timings[i].first>last_val){
                ans++;
                last_val=timings[i].second;
            }
        }
       return ans; 
    }
};
