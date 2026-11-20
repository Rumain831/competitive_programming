#include<iostream>
#include<vector>
using namespace std;

//Tags: 期待値, 転倒数
//解説URL: https://twitter.com/e869120/status/1404571956700008448

int main(void){
  int n; cin >> n;
  double ans=0;
  vector<int> l(n), r(n);
  for(int i=-0; i<n; i++) cin >> l[i] >> r[i];
  for(int i=0; i<n-1; i++){
    for(int j=i+1; j<n; j++){
      int pat=0;
      for(int k=l[i]; k<=r[i]; k++){
        pat+=max(0, min(k-1, r[j])-l[j]+1);
      }
      ans+=(double)pat/((r[i]-l[i]+1)*(r[j]-l[j]+1));
    }
  }
  printf("%.10f\n", ans);
  return 0;
}