#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: 構築, 最小公倍数
//Level: 2.5

int main(void){
  int n; cin >> n;
  vector<ll> ten={2, 3, 5, 7, 11, 13, 17, 19, 23};
  vector<ll> test;
  ll all=1;
  for(int i=0; i<n-1; i++) all*=ten[i];
  for(int i=0; i<n-1; i++) cout << all/ten[i] << ' ';
  cout << all << endl;
  return 0;
}