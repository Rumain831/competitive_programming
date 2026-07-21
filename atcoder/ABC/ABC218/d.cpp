#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
using P = pair<int, int>;

//Tags: 数え上げ

int main(void){
  int n; cin >> n;
  vector<P> point;
  set<P> st;
  for(int i=0; i<n; i++){
    int x, y; cin >> x >> y;
    point.emplace_back(x, y);
    st.emplace(x, y);
  }
  sort(begin(point), end(point));
  int ans=0;
  for(int i=0; i<n-1; i++)for(int j=i+1; j<n; j++){
    auto [x1, y1]=point[i];
    auto [x2, y2]=point[j];
    if(x1==x2||y1==y2) continue;
    if(st.count(P(x1, y2))&&st.count(P(x2, y1))) ans++;
  }
  //(左上, 右下)と(左下, 右上)で2回数えてしまう
  cout << ans/2 << endl;
  return 0;
}