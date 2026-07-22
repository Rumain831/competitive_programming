#include<iostream>
#include<vector>
using namespace std;

//Tags: グラフ

int main(void){
  int n; cin >> n;
  vector<int> deg(n);
  for(int i=0; i<n-1; i++){
    int a, b; cin >> a >> b; a--, b--;
    deg[a]++, deg[b]++;
  }
  int one=0;
  for(int i=0; i<n; i++){
    if(deg[i]==1) one++;
  }
  cout << (one==n-1?"Yes":"No") << endl;
  return 0;
}