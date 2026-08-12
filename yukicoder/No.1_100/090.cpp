#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

//Tags: 順列全探索

int main(void){
  int n, m; cin >> n >> m;
  vector<int> t(n), p(m), q(m), r(m);
  for(int i=0; i<n; i++) t[i]=i;
  for(int i=0; i<m; i++){
    cin >> p[i] >> q[i] >> r[i];
  }
  ll ans=0;
  do{
    vector<int> turn(n);
    for(int i=0; i<n; i++) turn[t[i]]=i;
    ll now=0;
    for(int i=0; i<m; i++){
      if(turn[p[i]]<turn[q[i]]) now+=r[i];
    }
    ans=max(ans, now);
  }while(next_permutation(begin(t), end(t)));
  cout << ans << endl;
  return 0; 
}