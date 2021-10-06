#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct node{
    int start;
    int end;
    int index;
};
bool greedy_compare(node n1,node n2){
    return n1.end<n2.end;
}
void maxMeeting(int s[], int f[], int n){
    vector<node> greedy_array;
    for(int i=0;i<n;i++){
       node new_node;
       new_node.start=s[i];
       new_node.end=f[i];
       new_node.index=i;
       greedy_array.push_back(new_node);
    }
    sort(greedy_array.begin(),greedy_array.end(),greedy_compare);
    //pick the first one
    int picked_end_time=greedy_array[0].end;
    cout<<greedy_array[0].index<<" ";
    for(int i=1;i<n;i++){
        if(greedy_array[i].start>picked_end_time){
            cout<<greedy_array[i].index<<" ";
            picked_end_time=greedy_array[i].end;
        }
    }
}
int main() {
// Starting time
    int s[] = { 1, 3, 0, 5, 8, 5 };
     
    // Finish time
    int f[] = { 2, 4, 6, 7, 9, 9 };
     
    // Number of meetings.
    int n = sizeof(s) / sizeof(s[0]);
 
    // Function call
    maxMeeting(s, f, n);
 
    return 0;

}
