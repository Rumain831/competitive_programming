#include<iostream>
#include<vector>
using namespace std;

//Tags: 条件分岐

int main(void){
  int n; cin >> n;
  vector<int> cnt(101);
  for(int i=0; i<n; i++){
    int a; cin >> a;
    cnt[a]++;
  }
  int ans=0;
  for(int i=0; i<=100; i++)if(cnt[i]&1){
    ans+=i;
  }
  cout << ans << endl;
  return 0; 
}