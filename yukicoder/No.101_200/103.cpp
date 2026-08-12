#include<iostream>
#include<vector>
using namespace std;

//Tags: ゲーム, 素因数分解, Nim

int main(void){
  int n; cin >> n;
  int nn=1e4+1;
  vector<int> yakusu(nn+1, -1);
  for(int i=2; i<=nn; i++){
    if(yakusu[i]!=-1) continue;
    int copy=i;
    while(copy<=nn){
      if(yakusu[copy]==-1) yakusu[copy]=i;
      copy+=i;
    }
  }
  int all=0;
  while(n--){
    int m; cin >> m;
    int now=0;
    while(m>1){
      int d=yakusu[m], c=0;
      while(m%d==0){
        c++, m/=d;
      }
      c%=3;
      now^=c;
    }
    all^=now;
  }
  cout << (all?"Alice":"Bob") << endl;
  return 0; 
}