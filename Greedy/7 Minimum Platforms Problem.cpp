class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	//Sort both the arrays:
    	sort(arr,arr+n);
    	sort(dep,dep+n);
    	int ans=1;
    	int i=1,j=0;
    	//Here i represents the arrival of the train and the j points to the departure 
    	while(i<n){
    	    if(arr[i]<=dep[j]){
    	        //if arrival of a train is less than departure of min train then we need
    	        //to introduce a platform
    	        ans++;
    	    }
    	    else{
    	        //Here we increment dept time because that train is alredy departured
    	        j++;
    	    }
    	    //This is when we increment the i value irrespective of above cond
    	    i++;
    	}
    	return ans;
    }
};
