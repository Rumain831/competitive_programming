#include<iostream>
using namespace std;

int main(void){
  int n; cin >> n;
  int now, sum=0;
  for(int i=1; i<=n; i++){
    now=i*10000; sum+=now;
  }
  printf("%.10f\n", (double)sum/n);
  return 0;
}