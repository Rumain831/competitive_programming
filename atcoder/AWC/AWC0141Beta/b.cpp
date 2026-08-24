#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using P = pair<int, int>;

//Tags: 実装

int main(void){
  int n, k; cin >> n >> k;
  vector<P> st;
  for(int i=0; i<n; i++){
    int s; cin >> s;
    st.emplace_back(s, -(i+1));
  }
  sort(rbegin(st), rend(st));
  cout << -st[k-1].second << endl;
  return 0; 
}