#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

//Tags: 整数
//https://codeforces.com/contest/2227/problem/C

//2の倍数だが3の倍数でない その他 3の倍数だが2の倍数でない 6の倍数 の順に並べたら通った
void solve(){
  int n; cin >> n;
  vector<int> no, a, b, six;
  for(int i=0; i<n; i++){
    int x; cin >> x;
    if(x%6==0) six.push_back(x);
    else if(x%2==0) a.push_back(x);
    else if(x%3==0) b.push_back(x);
    else no.push_back(x);
  }
  if((int)a.size()<(int)b.size()) swap(a, b);
  for(auto p:a) cout << p << ' ';
  for(auto p:no) cout << p << ' ';
  for(auto p:b) cout << p << ' ';
  for(auto p:six) cout << p << ' '; cout << endl;
}

int main(void){
  int t; cin >> t;
  while(t--){
    solve();
  }
  return 0;
}
