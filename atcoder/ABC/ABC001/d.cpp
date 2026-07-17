#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using P = pair<int, int>;
using PP = pair<P, P>;

P change(string t, int bit){
  string p=t.substr(0, 2), q=t.substr(2, 2);
  int h=stoi(p), m=stoi(q);
  int r=m/5;
  if(bit){
    m=(m%5?r*5+5:5*r);
    if(m==60) h++, m=0;
  }
  else m=r*5;
  return P(h, m);
}

string f(P a){
  auto [h, m]=a;
  string ans;
  if(h<10) ans+='0', ans+=(char)('0'+h);
  else ans+=to_string(h);
  if(m<10) ans+='0', ans+=(char)('0'+m);
  else ans+=to_string(m);
  return ans;
}

int main(void){
  int n; cin >> n;
  vector<string> s(n);
  vector<PP> time;
  for(int i=0; i<n; i++){
    cin >> s[i];
    string mae=s[i].substr(0, 4), aft=s[i].substr(5, 4);
    P s=change(mae, 0), e=change(aft, 1);
    time.emplace_back(s, e);
  }
  sort(time.begin(), time.end());
  time.erase(unique(time.begin(), time.end()), time.end());
  vector<PP> use;
  int idx=0;
  n=time.size();
  while(idx<n){
    auto [p, q]=time[idx];
    while(idx+1<n&&q>=time[idx+1].first) idx++, q=max(q, time[idx].second);
    use.emplace_back(p, q);
    idx++;
  }
  for(auto [p, q]:use){
    cout << f(p) << '-' << f(q) << endl;
  }
  return 0;
}
