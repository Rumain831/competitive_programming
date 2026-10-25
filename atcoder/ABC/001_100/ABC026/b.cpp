#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;

//Tags: 幾何

int main(void){
  int n; cin >> n;
  int pre=0;
  double sum[2]={}, PI=atan2(1, 1)*4.0;
  vector<int> R(n);
  for(int i=0; i<n; i++) cin >> R[i];
  sort(R.begin(), R.end());
  for(int i=0; i<n; i++){
    int r=R[i];
    sum[i%2]+=r*r-pre*pre;
    pre=r;
  }
  printf("%.10f\n", sum[(n%2)^1]*PI);
  return 0;
}