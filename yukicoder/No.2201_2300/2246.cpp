#include<iostream>
#include<vector>
using namespace std;

//Tags: K番目
//小さいものから並べると以下のように周期的に並ぶ
//何周目の何番目か求めれば分かる
//12, 13, ..., 89
//122, 133, ..., 899

int main(void){
  vector<int> two;
  for(int i=1; i<9; i++)for(int j=i+1; j<=9; j++) two.push_back(i*10+j);
  int n; cin >> n; n--;
  int m=two.size();
  int turn=n/m, id=n%m, r=two[id]%10;
  cout << two[id] << string(turn, '0'+r) << endl;
  return 0; 
}