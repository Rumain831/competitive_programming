#include<iostream>
#include<vector>
using namespace std;

//Tags: ad-hoc

int main(void){
  int n; cin >> n;
  vector<int> a(n), b(n);
  for(auto&x:a) cin >> x;
  for(auto&x:b) cin >> x;
  if(a==b){
    cout << "Yes" << endl; return 0;
  }
  int l=0, r=n-1;
  while(l<n&&a[l]==b[l]) l++;
  while(r>=0&&a[r]==b[r]) r--;
  {
    int y=a[l];
    vector<int> c=a;
    for(int i=l; i<=r; i++) c[i]=(i!=r?a[i+1]:y);
    if(c==b){
      cout << "Yes" << endl; return 0;
    }
  }
  {
    int y=a[r];
    vector<int> c=a;
    for(int i=l+1; i<=r; i++) c[i]=a[i-1];
    c[l]=y;
    if(c==b){
      cout << "Yes" << endl; return 0;
    }
  }
  
  cout << (a==b?"Yes":"No") << endl;
  return 0; 
}