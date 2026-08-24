#include<iostream>
#include<set>
using namespace std;
using ll = long long;

//Tags: 数え上げ, 包除原理
//Level: 2

int main(void){
  ll w, h, n; cin >> w >> h >> n;
  set<int> mark, num;
  for(int i=0; i<n; i++){
    int s, k; cin >> s >> k;
    mark.insert(s);
    num.insert(k);
  }
  ll ans=h*mark.size()+w*num.size()-(ll)mark.size()*num.size()-n;
  cout << ans << endl;
  return 0;
}