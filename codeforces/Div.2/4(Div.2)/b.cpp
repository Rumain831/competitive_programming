#include<iostream>
#include<vector>
using namespace std;

//Tags: 構築
//https://codeforces.com/contest/4/problem/B

int main(void){
  int d, tar; cin >> d >> tar;
  vector<int> mi(d), mx(d), ans(d);
  int l=0, r=0;
  for(int i=0; i<d; i++){
    cin >> mi[i] >> mx[i];
    l+=mi[i], r+=mx[i], ans[i]=mi[i];
  }
  if(tar<l||r<tar){
    cout << "NO" << endl; return 0;
  }
  cout << "YES" << endl;
  tar-=l;
  for(int i=0; i<d; i++){
    int add=min(tar, mx[i]-mi[i]);
    ans[i]+=add, tar-=add;
  }
  for(auto p:ans) cout << p << ' '; cout << endl;
  return 0; 
}