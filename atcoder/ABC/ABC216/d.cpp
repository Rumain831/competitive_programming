#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(void){
  int n, m; cin >> n >> m;
  vector<queue<int>> tube(m);
  vector<vector<int>> top(n);
  for(int i=0; i<m; i++){
    int k; cin >> k;
    for(int j=0; j<k; j++){
      int a; cin >> a; a--;
      tube[i].push(a);
    }
    top[tube[i].front()].push_back(i);
  }
  int rem=2*n;
  queue<int> erase;
  for(int i=0; i<n; i++)if(top[i].size()==2) erase.push(i);
  while(erase.size()){
    int col=erase.front(); erase.pop();
    for(auto idx:top[col]){
      tube[idx].pop(); rem--;
      if(tube[idx].size()){
        int ncol=tube[idx].front();
        top[ncol].push_back(idx);
        if(top[ncol].size()==2) erase.push(ncol);
      }
    }
  }
  cout << (rem==0?"Yes":"No") << endl;
  return 0;
}