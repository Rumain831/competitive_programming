#include<iostream>
using namespace std;

//Tags: 条件分岐

int main(void){
  int n; cin >> n;
  string ans;
  int sum=0, maxi=-1;
  for(int i=0; i<n; i++){
    string s; int p; cin >> s >> p;
    if(maxi<p) maxi=p, ans=s;
    sum+=p; 
  }
  if(maxi>sum-maxi) cout << ans << endl;
  else cout << "atcoder" << endl;
  return 0;
}