#include<bits/stdc++.h>
using namespace std;
int main(){
  int n, head;
  cout<<"Enter the number of disk requests: ";
  cin>>n;
  vector<int> requests(n);
  cout<<"Enter the request sequence: \n";
  for(int i=0;i<n;i++){
      cin>>requests[i];
  }
  cout<<"Enter the initial head position: ";
  cin>>head;
  int totalmovement=0;
  cout<<"\nDisk scheduling order:\n";
  cout<<head;
  for(int i=0;i<n;i++){
      int movement = abs(requests[i]-head);
      totalmovement+= movement;
      head = requests[i];
      cout<<"-> "<<head<<" (moved "<<movement<<")";
   }
   cout<<"\ntotal Cylinder Movement: "<<totalmovement<<endl;
   return 0;
}
  
