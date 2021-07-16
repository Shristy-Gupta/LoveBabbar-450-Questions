class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        int p=1<<n;
        //size of array
        vector<vector<int>> subs(p);
        for(int i=0;i<p;i++){
            for(int j=0;j<n;j++){
                /*
                <0 1 2 3 4 5 6 7>
                <000 001 010 011 100 101 011 111>
                 012
                */
                if((i>>j) & 1){
                    subs[i].push_back(nums[j]);
                }
            }
        }
        return subs;
    }
};
