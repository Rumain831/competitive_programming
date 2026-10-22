#include<iostream>
#include<vector>
using namespace std;

//Tags: 周期性
//Level: 1.5

int main(void){
  int a, b, c, d, e; cin >> a >> b >> c >> d >> e;
  int p=(a+b)*(c+d);
  vector<int> mv(p+1);
  for(int i=1; i<=p; i+=a+b)for(int j=0; j<a; j++)if(i+j<=p) mv[i+j]++;  
  for(int i=1; i<=p; i+=c+d)for(int j=0; j<c; j++)if(i+j<=p) mv[i+j]++;  
  int x=0, roop=e/p, r=e%p, ans=0;
  for(auto q:mv)if(q==2) x++;
  ans+=x*roop;
  for(int i=1; i<=r; i++) ans+=(mv[i]==2);
  cout << ans << endl;
  return 0; 
}