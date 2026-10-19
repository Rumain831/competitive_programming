#include<iostream>
#include<set>
using namespace std;

//Tags: set
//Nが小さいのでvectorを使って出現したかを管理してもいい

int main(void){
  int n; cin >> n;
  int ans=0;
  set<int> seen;
  for(int i=0; i<n; i++){
    int a; cin >> a;
    if(seen.count(a)) ans++;
    else seen.insert(a);
  }
  cout << ans << endl;
  return 0;
}