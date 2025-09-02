#include<bits/stdc++.h>
using namespace std;
struct process{
      int id,at,bt,priority,flag=1,ct,tat,wt;
      };
int main(){
      int n;
      cout<<"Enter no of processes: ";
      cin>>n;
      vector<process> p(n);
      cout<<"Enter AT, BT, priority for each process:\n";
      for(int i=0;i<n;i++){
          p[i].id = i+1;
          cin>>p[i].at>>p[i].bt>>p[i].priority;
      }  
      int completed=0,time=0;
      float total_wt = 0, total_tat=0;
      while(completed<n){
          int idx = -1, min_pri=INT_MAX;
          for(int i=0;i<n;i++){
              if(p[i].flag && p[i].at<=time){
                  if(p[i].priority < min_pri){
                      min_pri = p[i].priority;
                      idx=i;
                  }
              }
          }
          time += p[idx].bt;
          p[idx].ct = time;
          p[idx].tat = p[idx].ct - p[idx].at;
          p[idx].wt = p[idx].tat - p[idx].bt;
          total_wt += p[idx].wt;
          total_tat += p[idx].tat;
          p[idx].flag = 0, completed++;
       }
      cout<<"\nPID\tAT\tBT\tPriority\tCT\tTAT\tWT\n";
      for(int i=0;i<n;i++){
          cout<<"P"<<p[i].id<<"\t"<<p[i].at<<"\t"<<p[i].bt<<"\t"<<p[i].priority<<"\t\t"<<p[i].ct<<"\t"<<p[i].tat<<"\t"<<p[i].wt<<"\n";
       }
      cout<<"\nAverage waiting time= "<<(total_wt/n)<<"\nAverage TAT= "<<(total_tat/n)<<"\n";
      return 0;
}
