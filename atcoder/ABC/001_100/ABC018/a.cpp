#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Tags: 実装

int main(void){
  vector<int> a(3), b(3);
  for(auto&x:a) cin >> x;
  b=a;
  sort(rbegin(b), rend(b));
  for(int i=0; i<3; i++){
    for(int j=0; j<3; j++)if(a[i]==b[j]){
      cout << j+1 << endl;
    }
  }
  return 0; 
}