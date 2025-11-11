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
  vector<bool> visited(n,false);
  int totalmovement=0, current=head;
  cout<<"\nDisk scheduling order:\n";
  cout<<current;
  for(int i=0;i<n;i++){
      int nearest = -1;
      int minDistance = INT_MAX;
      for(int j=0;j<n;j++){
          if(!visited[j]){
              int dist = abs(current-requests[j]);
              if(dist < minDistance){
                  minDistance  = dist;
                  nearest = j;
               }
           }
        }
      visited[nearest] = true;
      totalmovement+= minDistance;
      current = requests[nearest];
      cout<<"-> "<<current<<" (moved "<<minDistance<<")";
   }
   cout<<"\ntotal Cylinder Movement: "<<totalmovement<<endl;
   cout<<"Average seek time: "<<(float)totalmovement/n<<endl;
   return 0;
}
  
