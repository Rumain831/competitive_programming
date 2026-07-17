#include<iostream>
using namespace std;

int main(void){
  int n; cin >> n;
  int ans=0;
  for(int i=0; i<n; i++){
    int a; cin >> a;
    if(a%6==2||a%6==4) ans++;
    else if(a%6==5) ans+=2;
    else if(a%6==0) ans+=3;
  }
  cout << ans << endl;
  return 0;
}