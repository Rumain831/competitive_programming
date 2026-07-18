#include<iostream>
using namespace std;

//悪問。T時ちょうどに準備を終えても出発できる。
int main(void){
  int n, s, t; cin >> n >> s >> t;
  if(s==t){
    cout << "No" << endl; return 0;
  }
  int sum=0;
  for(int i=0; i<n; i++){
    int a; cin >> a;
    sum+=a;
  }
  int d=(t-s)*60;
  cout << (sum<=d?"Yes":"No") << endl;
  return 0;
}