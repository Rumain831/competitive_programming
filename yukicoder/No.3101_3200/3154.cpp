#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

//Tags: 凸包
//Level: 3

struct Point{
  ll x, y;
  Point(ll x=0, ll y=0):x(x), y(y){}
  bool operator<(const Point& other)const{ //sortに必要
    if(x!=other.x) return x<other.x;
    else return y<other.y;
  }
  bool operator==(const Point& other)const{ //uniqueに必要
    return x==other.x&&y==other.y;
  }
};

ll cross(Point o, Point a, Point b){
  //OA x OB
  return (a.x-o.x)*(b.y-o.y)-(a.y-o.y)*(b.x-o.x);
}

vector<Point> Convex_Hull(vector<Point> tar){
  sort(tar.begin(), tar.end());
  tar.erase(unique(tar.begin(), tar.end()), tar.end());
  int n=tar.size();
  if(n<=1) return tar;
  vector<vector<Point>> down_up(2);
  for(int i=0; i<2; i++){
    for(auto pt:tar){
      while((int)down_up[i].size()>=2){
        Point o=down_up[i][(int)down_up[i].size()-2];
        Point a=down_up[i][(int)down_up[i].size()-1];
        if(cross(o, a, pt)<=0) down_up[i].pop_back(); //一直線も削除
        //if(cross(o, a, pt)<0) down.pop_back(); //直線上の点は残す
        else break;
      }
      down_up[i].push_back(pt);
    }
    reverse(tar.begin(), tar.end());
    down_up[i].pop_back();
  }
  down_up[0].insert(down_up[0].end(), down_up[1].begin(), down_up[1].end());
  return down_up[0];
}

int main(void){
  int n; cin >> n;
  vector<Point> ps;
  for(int i=0; i<n; i++){
    int x, y; cin >> x >> y;
    ps.emplace_back(x, y);
  }
  int k=Convex_Hull(ps).size();
  cout << (k==n?"Yes":"No") << endl;
  return 0;
}