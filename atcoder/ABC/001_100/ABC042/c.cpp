#include<iostream>
#include<vector>
using namespace std;

//Tags: 愚直

int main(void){
  int n, k; cin >> n >> k;
  vector<int> ng(10);
  for(int i=0; i<k; i++){
    int d; cin >> d;
    ng[d]=1;
  }

  auto check=[&](int i){
    bool ok=true;
    while(i>0){
      if(ng[i%10]){
        ok=false; break;
      }
      i/=10;
    }
    return ok;
  };

  for(int i=n;;i++){
    if(check(i)){
      cout << i << endl; return 0;
    }
  }
}