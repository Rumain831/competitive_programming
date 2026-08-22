#include<iostream>
using namespace std;

//Tags: 木の直径

int main(void){
  int n; cin >> n;
  int maxi=-1, idx, idx2=0;
  for(int i=1; i<n; i++){
    cout << "? " << 1 << ' ' << i+1 << endl;
    int a; cin >> a;
    if(maxi<a) maxi=a, idx=i;
  }
  for(int i=0; i<n; i++){
    if(i==idx) continue;
    cout << "? " << idx+1 << ' ' << i+1 << endl;
    int a; cin >> a;
    if(maxi<a) maxi=a;
  }
  cout << "! " << maxi << endl;
  return 0;
}