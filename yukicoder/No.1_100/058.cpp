#include<iostream>
using namespace std;

//Tags: 全探索
//Level: 2

int n, k;
int cnt[2][61];
int a[2][6]={{1,2,3,4,5,6}, {4,4,5,5,6,6}};

void dfs(int step, int sum, int t){
  if(step==n){
    cnt[t][sum]++; return;
  }
  for(int i=0; i<6; i++){
    if(t&&step<k) dfs(step+1, sum+a[1][i], t);
    else dfs(step+1, sum+a[0][i], t);
  }
  return;
}

int main(void){
  cin >> n >> k;
  dfs(0, 0, 0);
  dfs(0, 0, 1);
  for(int i=1; i<=60; i++) cnt[0][i]+=cnt[0][i-1];
  double ans=0, p=1.0/cnt[0][60];
  for(int i=1; i<=60; i++) ans+=p*cnt[1][i]*p*cnt[0][i-1];
  printf("%.10f\n", ans);
  return 0; 
}