#include<iostream>
#include<vector>
using namespace std;

//Tags: ゲーム, 整数

int main(void){
  int a, b, c, d; cin >> a >> b >> c >> d;
  vector<int> yakusu(202, -1);
  for(int i=2; i<202; i++){
    if(yakusu[i]!=-1) continue;
    yakusu[i]=i;
    int copy=i;
    while(copy<202){
      if(yakusu[copy]==-1) yakusu[copy]=i;
      copy+=i;
    }
  }

  auto f=[&](int i){
    for(int j=c; j<=d; j++){
      if(yakusu[i+j]==i+j) return false;
    }
    return true;
  };

  for(int i=a; i<=b; i++){
    if(f(i)){
      cout << "Takahashi" << endl; return 0;
    }
  }
  cout << "Aoki" << endl;
  return 0;
}