class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> lg;
        vector<int> rg;
        int n=height.size();
        //formula is min(maxL,maxR)-arr[i]
        int maxl=INT_MIN, maxr=INT_MIN;
        for(int i=0;i<n;i++){
            maxl=max(maxl,height[i]);
            lg.push_back(maxl);
            maxr=max(maxr,height[n-i-1]);
            rg.push_back(maxr);
        }
        reverse(rg.begin(),rg.end());
        int area=0;
        for(int i=0;i<n;i++){
            area+=min(lg[i],rg[i])-height[i];
        }
        return area;
    }
};
