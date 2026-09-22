#include<iostream>
using namespace std;

//Tags: 数学
//Level: 2
//A1>0なら十分大きな実数Mでf(M)>0となる。f(0)=-1<0より、中間値の定理から正の実数解が存在する。
//A1=0とする。A2>0なら上と同様に解が存在。
//A1=A2=0とする。以下同様。
//結局、Ai>0なるiがあれば解が存在。A1=...=AN=0ならf(x)=-1となり、解は存在しない。

int main(void){
  int n; cin >> n;
  for(int i=0; i<n; i++){
    int x; cin >> x;
    if(x>0){
      cout << "Yes" << endl; return 0;
    }
  }
  cout << "No" << endl;
  return 0; 
}