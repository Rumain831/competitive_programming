#include<iostream>
using namespace std;

//Tags: 貪欲法, 硬貨交換
//Level: 1

int main(void){
  int p[3]={100, 25, 1};
  int cnt[3]; cin >> cnt[0] >> cnt[1] >> cnt[2];
  int sum=0;
  for(int i=0; i<3; i++) sum+=cnt[i]*p[i];
  sum-=sum/1000*1000;
  int ans=0;
  for(int i=0; i<3; i++){
    int d=sum/p[i];
    ans+=d, sum-=p[i]*d;
  }
  cout << ans << endl;
  return 0; 
}