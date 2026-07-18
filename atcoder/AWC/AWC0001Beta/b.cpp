#include<iostream>
#include<vector>
using namespace std;

int main(void){
  int n, l, r; cin >> n >> l >> r;
  vector<int> p(n);
  for(auto&x:p) cin >> x;
  int mx=-1, id=-1;
  for(int i=0; i<n; i++){
    if(p[i]>=l&&p[i]<=r&&mx<p[i]){
      mx=p[i];
      id=i+1;
    }
  }
  cout << (id==-1?-1:id) << endl;
  return 0;
}