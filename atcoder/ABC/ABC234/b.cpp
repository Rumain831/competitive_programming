#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
int sq(int x, int y){return x*x+y*y;}

//Tags: 全探索, 幾何

int main(void){
  int n; cin >> n;
  vector<int> x(n), y(n);
  for(int i=0; i<n; i++) cin >> x[i] >> y[i];
  int ans=0;
  for(int i=0; i<n-1; i++)for(int j=i+1; j<n; j++){
    ans=max(ans, sq(x[i]-x[j], y[i]-y[j]));
  }  
  printf("%.10f\n", (double)sqrt(ans));
  return 0; 
}