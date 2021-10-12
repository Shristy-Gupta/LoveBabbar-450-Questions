//https://www.spoj.com/problems/CHOCOLA/
//https://www.geeksforgeeks.org/minimum-cost-cut-board-squares/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
   int t; cin>>t;
   while(t--){
   int m,n;
   cin>>m>>n;
   m--;n--;
   vector<int> horizonatals;
   vector<int> verticals;
	   for(int i=0;i<m;i++){
	   	int x; cin>>x;
	   	horizonatals.push_back(x);
	   }
	   for(int i=0;i<n;i++){
	   	int x; cin>>x;
	   	verticals.push_back(x);
	   }
	sort(horizonatals.begin(),horizonatals.end(),greater<int>());
	sort(verticals.begin(),verticals.end(),greater<int>());
	int h_cuts=1, v_cuts=1,i=0,j=0;
	long long ans=0;
	while(i<m && j<n){
		if(horizonatals[i]>=verticals[j]){
			ans+=horizonatals[i]*h_cuts;
			v_cuts++;
			i++;
		}
		else if(horizonatals[i]<verticals[j]){
			ans+=verticals[j]*v_cuts;
			h_cuts++;
			j++;
		}
	}
	while(i<m){
			ans+=horizonatals[i]*h_cuts;
			i++;
	}
	while(j<n){
			ans+=verticals[j]*v_cuts;
			j++;
	}
	cout<<ans<<endl;
   }
	return 0;
}
