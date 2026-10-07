#include<iostream>
#include<vector>
using namespace std;

//Tags: 候補を絞って全探索
//Level: 2

int main(void){
  int n; cin >> n;
  vector<int> a(n);
  int all=0;
  for(auto&x:a) cin >> x, all+=x;
  int ans=-1, sum=0;
  auto judge=[&](int x){
    int c=0, now=0;
    for(int i=0; i<n; i++){
      now+=a[i];
      if(now>x) return -1;
      if(now==x) c++, now=0;
    }
    if(now) return -1;
    return c;
  };
  for(int i=0; i<n; i++){
    sum+=a[i];
    if(all%sum) continue;
    int x=judge(sum);
    if(x!=-1) ans=max(ans, x);
  }
  cout << ans << endl;
  return 0; 
}