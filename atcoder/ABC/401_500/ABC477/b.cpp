#include<iostream>
#include<vector>
using namespace std;

//Tags: 愚直

int main(void){
  int n, d; cin >> n >> d;
  vector<int> x(n), ans;
  for(auto&y:x) cin >> y;
  for(int i=0; i<n; i++){
    bool ok=true;
    for(int j=0; j<n; j++)if(i!=j){
      int y=abs(x[i]-x[j]);
      if(y<d){
        ok=false; break;
      }
    }
    if(ok) ans.push_back(i+1);
  }
  cout << ans.size() << endl;
  for(auto p:ans) cout << p << ' ';
  return 0; 
}