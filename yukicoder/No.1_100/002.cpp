#include<iostream>
#include<vector>
using namespace std;

//Tags: Nim, 素因数分解
//Level: 3

int main(void){
  int n; cin >> n;
  vector<int> yakusu(1e4+1, -1);
  int copy=n;
  vector<int> ps;
  for(int i=2; i*i<=n; i++){
    if(yakusu[i]==-1) yakusu[i]=i;
    else continue;
    int cnt=0;
    while(copy%i==0) cnt++, copy/=i;
    if(cnt) ps.push_back(cnt);
    int co=i;
    while(co<=1e4){
      if(yakusu[co]==-1) yakusu[co]=i;
      co+=i;
    }
  }
  if(copy>1) ps.push_back(1);
  int xo=0;
  for(auto p:ps) xo^=p;
  if(xo) cout << "Alice" << endl;
  else cout << "Bob" << endl;
  return 0;
}