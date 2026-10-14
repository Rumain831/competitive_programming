#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//Tags: Simulation, 貪欲法

int main(void){
  int n; cin >> n;
  vector<vector<int>> task(n);
  for(int i=0; i<n; i++){
    int a, b; cin >> a >> b; a--;
    task[a].push_back(b);
  }
  priority_queue<int> pri;
  int ans=0;
  for(int i=0; i<n; i++){
    for(auto x:task[i]) pri.push(x);
    ans+=pri.top(); pri.pop();
    cout << ans << '\n';
  }
  return 0;
}