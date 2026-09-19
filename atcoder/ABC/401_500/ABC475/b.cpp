#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: 硬貨交換

int main(void){
  int n; cin >> n;
  vector<int> cnt(3), p={1, 10, 100};
  while(n--){
    int a; cin >> a;
    int pay=(a+1000-1)/1000*1000;
    int x=pay-a;
    for(int i=2; i>=0; i--){
      int add=x/p[i];
      cnt[i]+=add;
      x-=p[i]*add;
    }
  }
  for(auto p:cnt) cout << p << ' ';
  return 0; 
}