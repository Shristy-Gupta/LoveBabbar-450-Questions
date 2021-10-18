#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		if(n==0){
			continue;
		}
		vector<int> amp;
		int count1=0;
		for(int i=0;i<n;i++){
			int x;
			cin>> x;
			if(x==1){
			count1++;	
			}
			amp.push_back(x);
		}
		sort(amp.begin(),amp.end(),greater<int>());
		for(int i=0;i<count1;i++){
			cout<<1<<" ";
		}
		if((n-count1)==2 and amp[0]==3 and amp[1]==2){
			cout<<2<<" "<<3<<endl;
		}
		else
		for(int i=0;i<n-count1;i++){
		    cout<<amp[i]<<" ";
			
		}
		cout<<endl;
		
	}
	return 0;
}
