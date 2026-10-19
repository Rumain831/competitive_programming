#include<iostream>
#include<vector>
using namespace std;

//Tags: グラフ

int main(void){
  int n; cin >> n;
  int a, b; cin >> a >> b; a--, b--;
  int k; cin >> k;
  vector<int> seen(n), p(k);
  for(int i=0; i<k; i++) cin >> p[i], p[i]--;
  for(int i=0; i<k; i++){
    if(seen[p[i]]){
      cout << "NO" << endl; return 0;
    }
    seen[p[i]]=1;
  }
  if(!seen[a]&&!seen[b]) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}