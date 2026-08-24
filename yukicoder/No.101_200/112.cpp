#include<iostream>
#include<vector>
using namespace std;

//Tags: 算数
//Level: 1.5

int main(void){
  int n; cin >> n;
  int sum=0;
  vector<int> a(n);
  for(auto&x:a) cin >> x, sum+=x;
  sum/=n-1;
  int two=0, four=0;
  for(int i=0; i<n; i++){
    if(sum-a[i]==2) two++;
    else four++;
  }
  cout << two << ' ' << four << endl;
  return 0; 
}