#include<iostream>
#include<set>
using namespace std;

//Tags: 全探索

int main(void){
  int a[5]={};
  set<int> ans;
  for(int i=0; i<5; i++) cin >> a[i];
  for(int i=0; i<3; i++)for(int j=i+1; j<4; j++)for(int k=j+1; k<5; k++){
    ans.insert(-(a[i]+a[j]+a[k]));
  }
  auto p=ans.begin();
  advance(p, 2);
  cout << -*p << endl;
  return 0; 
}