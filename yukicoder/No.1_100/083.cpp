#include<iostream>
using namespace std;

//Tags: 貪欲法
//1連打で実現可能な桁数を求めておく
//各桁について、9, 8, ..., 1の順に、それを置いても残りの桁を埋められるかを見て、置けるなら置く

int used[10]={7,2,6,6,5,6,7,3,6,5};
int main(void){
  int n; cin >> n;
  int d=n/2;
  for(int i=0; i<d; i++){
    for(int j=9; j>=0; j--){
      int nxt=n-used[j];
      int must=2*(d-1-i);
      if(nxt>=must){
        n-=used[j];
        cout << j;
        break;
      }
    }
    if(i==d-1) cout << endl;
  }
  return 0; 
}