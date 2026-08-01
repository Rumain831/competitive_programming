#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Tags: 多項式

int main(void){
  int d; cin >> d;
  int c[4]={1, 0, -1, 0};
  vector<int> a(d+1), ans;
  for(auto&x:a) cin >> x;
  reverse(begin(a), end(a));
  for(int i=0; i+3<d+1; i++){
    int k=a[i]/c[0];
    for(int j=0; j<4; j++){
      a[i+j]-=k*c[j];
    }
  }
  for(int i=0; i<d+1; i++) ans.push_back(a[i]);
  reverse(begin(ans), end(ans));
  while(ans.size()&&ans.back()==0) ans.pop_back();
  int p=ans.size();
  if(p==0){
    cout << 0 << '\n' << 0 << endl; 
  }
  else{
    cout << p-1 << endl;
    for(auto q:ans) cout << q << ' '; cout << endl;
  }
  return 0; 
}