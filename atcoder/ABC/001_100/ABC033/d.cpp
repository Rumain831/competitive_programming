#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Tags: 二分探索

int main(void){
  int n, k, c=60; cin >> n >> k;
  vector<double> w(n), p(n);
  for(int i=0; i<n; i++) cin >> w[i] >> p[i];
  double left=0, right=100;
  while(c--){
    double mid=(left+right)/2;
    vector<double> now;
    for(int i=0; i<n; i++) now.push_back(w[i]*(p[i]-mid));
    sort(rbegin(now), rend(now));
    double sum=0;
    for(int i=0; i<k; i++) sum+=now[i];
    if(sum>=0) left=mid;
    else right=mid;
  }
  printf("%.10f\n", left);
  return 0; 
}