#include<iostream>
using namespace std;

//Tags: ゲーム, Grundy数
//g(x)をxが渡ったときのGrundy数とする。
//g(N)=0, g(N-1)=1, ..., g(N-K)=K
//g(N-K-1)=0, ... と周期的になることが分かる

int main(void){
  int p; cin >> p;
  while(p--){
    int n, k; cin >> n >> k;
    cout << ((n-1)%(k+1)?"Win":"Lose") << endl;
  }
  return 0;
}