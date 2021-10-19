#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int n; cin>>n;
	while(n){
		vector<pair<int,int>> buy;
		vector<pair<int,int>> sell;
		for(int i=0;i<n;i++){
			int x; cin>>x;
			if(x>0)buy.push_back({x,i});
			else sell.push_back({x,i});
		}
		int i=0,j=0;
		long long int ans=0;
		int sb=buy.size(), ss=sell.size();
		while(i<sb and j<ss){
			int trade =min(buy[i].first,-sell[j].first);
			buy[i].first-=trade;
			sell[j].first+=trade;
			int diff=abs(buy[i].second-sell[j].second);
			ans+=(diff*trade);
			if(buy[i].first==0){i++;}
			if(sell[j].first==0){j++;}
		}
		cout<<ans<<endl;
		cin>>n;
		
	}
	return 0;
}
