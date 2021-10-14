// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int no_of_jobs=3;
class Job{
    public:
    int jobid;
    int at;//arrival time
    int bt;//burst time;
    int ct;//completion time; at+ bt
    int tt;//Turn around time; ct-at;
    int wt;//waiting time; tt-bt;
    Job(int id,int a,int b){
        this->jobid=id;
        this->at=a;
        this->bt=b;
        ct=0;
        tt=0;
        wt=0;
    }
};
vector<Job> jobs;
bool comp(Job const & v1, Job const & v2){
    if(v1.at<v2.at){
        return true;
    }
    if(v1.at==v2.at && v1.bt<v2.bt){
        return true;
    }
    if(v1.at==v2.at && v1.bt==v2.bt && v1.jobid <v2.jobid){
        return true;
    }
    return false;
}
void shortestjobfirst(){
    int completion_time, val,burst_time;
    //because job 0 will be picked no matter what
    jobs[0].ct=jobs[0].at+jobs[0].bt;
    //Turn around time is completion time - narrival time
    jobs[0].tt=jobs[0].ct-jobs[0].at;
    //waiting time is turnaround time - burst time
    jobs[0].wt=jobs[0].tt-jobs[0].bt;
    for(int i=1;i<no_of_jobs;i++){
        completion_time=jobs[i-1].ct;
        burst_time=jobs[i].bt;
        val=i;
        for(int j=i+1;j<no_of_jobs;j++){
            if(jobs[j].at<=completion_time && jobs[j].bt<burst_time){
                burst_time=jobs[j].bt;
                val=j;
            }
        }
if(val<no_of_jobs){

    jobs[val].ct=completion_time+jobs[val].bt;
    //Turn around time is completion time - arrival time
    jobs[val].tt=jobs[val].ct-jobs[val].at;
    //waiting time is turnaround time - burst time
    jobs[val].wt=jobs[val].tt-jobs[val].bt;
    swap(jobs[val],jobs[i]);
}    
    }
}
int main() {
    for(int i=0;i<no_of_jobs;i++){
        int a,b;
        cout << "...Process " << i + 1 <<endl;
        cout << "Enter Arrival Time: "<<endl;
        cin >> a;
        cout << "Enter Burst Time: "<<endl;
        cin >> b;
        jobs.push_back(Job(i+1,a,b));
    }
cout << "Before Arrange...\n";
    cout << "Process ID\tArrival Time\tBurst Time\n";
    for (int i = 0; i < no_of_jobs; i++) {
        cout << jobs[i].jobid << "\t\t\t\t" << jobs[i].at << "\t\t\t\t"
             << jobs[i].bt << "\n";
    }
    sort(jobs.begin(),jobs.end(),comp);
    shortestjobfirst();
    cout << "Final Result...\n";
    cout << "Process ID\tArrival Time\tBurst Time\tCompleting "
            "Time\tTurnaround Time\n";
    for (int i = 0; i < no_of_jobs; i++) {
        cout << jobs[i].jobid << "\t\t\t\t" << jobs[i].at << "\t\t\t\t"
             << jobs[i].bt << "\t\t\t\t" << jobs[i].ct << "\t\t\t\t"
             << jobs[i].tt << "\n";
    }
    return 0;
}
