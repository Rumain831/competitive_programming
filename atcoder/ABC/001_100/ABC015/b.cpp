#include<iostream>
using namespace std;

int main(void){
  int n; cin >> n;
  int sum=0, cnt=0;
  for(int i=0; i<n; i++){
    int a; cin >> a;
    if(a) sum+=a, cnt++;
  }
  cout << (sum+cnt-1)/cnt << endl;
  return 0;
}