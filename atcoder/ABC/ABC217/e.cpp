#include<iostream>
#include<queue>
using namespace std;

int main(void){
  int q; cin >> q;
  priority_queue<int, vector<int>, greater<int>> pri;
  queue<int> pre;
  while(q--){
    int t; cin >> t;
    if(t==1){
      int x; cin >> x;
      pre.push(x);
    }
    else if(t==2){
      if(pri.size()){
        cout << pri.top() << '\n'; pri.pop();
      }
      else{
        cout << pre.front() << '\n'; pre.pop();
      }
    }
    else{
      while(pre.size()){
        int p=pre.front(); pre.pop();
        pri.push(p);
      }
    }
  }
  return 0;
}