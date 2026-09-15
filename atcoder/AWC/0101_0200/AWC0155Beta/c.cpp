#include<iostream>
#include<set>
using namespace std;

//Tags: 貪欲法

int judge(multiset<int> a, multiset<int> b){
  int m=b.size(), ans=0;
  auto now=end(b); now--;
  while(1){
    auto it=a.lower_bound(*now);
    if(it==end(a)) return -1;
    if((*now)==(*it)) ans++;
    a.erase(it);
    if(now==begin(b)) break;
    now--;
  }
  return ans;
}

int main(void){
  int n, m; cin >> n >> m;
  multiset<int> a, b;
  for(int i=0; i<n; i++){int x; cin >> x; a.insert(x);}
  for(int i=0; i<m; i++){int x; cin >> x; b.insert(x);}
  cout << judge(a, b) << endl;
  return 0; 
}