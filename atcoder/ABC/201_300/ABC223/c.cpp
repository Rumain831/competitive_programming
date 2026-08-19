#include<iostream>
#include<vector>
using namespace std;

//Tags: Simulation

int main(void){
  int n; cin >> n;
  double all=0, half;
  vector<int> a(n), b(n);
  for(int i=0; i<n; i++){
    cin >> a[i] >> b[i];
    all+=(double)a[i]/b[i];
  }
  half=all*0.5;
  double nowt=0, dist=0;
  for(int i=0; i<n; i++){
    double add=(double)a[i]/b[i];
    if(nowt+add<half) nowt+=add, dist+=a[i];
    else{
      double rem=half-nowt;
      double ans=dist+rem*b[i];
      printf("%.10lf\n", ans);
      return 0;
    }
  }
  return 0;
}