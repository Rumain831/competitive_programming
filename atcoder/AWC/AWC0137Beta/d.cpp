#include<iostream>
#include<set>
using namespace std;
using P = pair<int, int>;

//Tags: grid

int main(void){
  int h, w, n; cin >> h >> w >> n;
  set<P> ans;
  while(n--){
    int r, c; cin >> r >> c;
    int d=min(r, c);
    r-=d, c-=d;
    ans.emplace(r, c);
  }
  cout << ans.size() << endl;
  return 0; 
}