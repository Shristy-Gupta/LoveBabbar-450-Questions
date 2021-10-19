#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	long long int t; cin>>t;
	while(t--){
		//Here we are taking 3 values as input width height and number of 
		long long int w,h,n;
		cin>>w>>h>>n;
		//we take the inpur x and y in vector array
		vector<long long int> x;
		vector<long long int> y;
		// we iterate the array to get all the coordinates
		while(n--){
			int ax,ay;
			cin>>ax>>ay;
			x.push_back(ax);
			y.push_back(ay);
		}
		//we push the last width and height this is because width at w is of w+1 see image
		x.push_back(w+1);
		y.push_back(h+1);
		//sort them to get maximum difference
		sort(x.begin(),x.end());
		sort(y.begin(),y.end());
		long long int xdiff=x[0]-1,ydiff=y[0]-1;
		int s1=x.size(), s2=y.size();
		for(int i=1;i<s1;i++){
			//Here we get the maximum difference 
			xdiff=max(xdiff,x[i]-x[i-1]-1);
			ydiff=max(ydiff,y[i]-y[i-1]-1);
		}
		//area is mul of both the vals
		cout<<xdiff*ydiff<<endl;
	}

	return 0;
}
