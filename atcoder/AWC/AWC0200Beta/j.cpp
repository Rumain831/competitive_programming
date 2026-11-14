#include<iostream>
#include<map>
#include<set>
using namespace std;
using ll = long long;

//Tags: 経路圧縮

map<int, int> l, r;
set<int> dis;

int fr(int x){
  if(dis.count(x)==0) return x;
  if(r.count(x)) return r[x]=fr(r[x]);
  return r[x]=fr(x+1);
}

int fl(int x){
  if(dis.count(x)==0) return x;
  if(l.count(x)) return l[x]=fl(l[x]);
  return l[x]=fl(x-1);
}

int main(void){
  int n; cin >> n;
  ll now=0;
  while(n--){
    int x; cin >> x; dis.insert(x);
    if(x==now){
      ll nr=fr(x);
      ll nl=fl(x);
      ll d1=abs(nl-x);
      ll d2=abs(nr-x);
      ll nxt=(d1<d2?nl:nr);
      now=nxt;
    }
  }
  cout << now << endl;
  return 0; 
}