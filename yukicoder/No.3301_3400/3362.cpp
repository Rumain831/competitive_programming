#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;
using i128 = __int128_t;

//Tags: 数学, 四則演算, 多倍長整数

struct frac{
  i128 bunsi, bumbo;
  frac(i128 a, i128 b=1):bunsi(a), bumbo(b){
    normalize();
  }

  i128 gcd(i128 a, i128 b){
    if(b==0) return a;
    else return gcd(b, a%b);
  }

  void normalize(){
    if(bumbo<0) bunsi*=-1, bumbo*=-1;
    i128 g=gcd(max(bunsi, -bunsi), max(bumbo, -bumbo));
    bunsi/=g, bumbo/=g;
  }
  
  frac& operator+=(const frac& other){
    bunsi=bunsi*other.bumbo+other.bunsi*bumbo;
    bumbo*=other.bumbo;
    normalize();
    return *this;
  }
  frac& operator-=(const frac& other){
    bunsi=bunsi*other.bumbo-other.bunsi*bumbo;
    bumbo*=other.bumbo;
    normalize();
    return *this;
  }
  frac& operator*=(const frac& other){
    bunsi*=other.bunsi;
    bumbo*=other.bumbo;
    normalize();
    return *this;
  }
  frac& operator/=(const frac& other){
    bunsi*=other.bumbo;
    bumbo*=other.bunsi;
    normalize();
    return *this;
  }

  frac operator+()const{
    return *this;
  }
  frac operator-()const{
    return frac(-bunsi, bumbo);
  }

  frac operator+(const frac& other)const{
    frac ans=*this;
    return ans+=other;
  }
  frac operator-(const frac& other)const{
    frac ans=*this;
    return ans-=other;
  }
  frac operator*(const frac& other)const{
    frac ans=*this;
    return ans*=other;
  }
  frac operator/(const frac& other)const{
    frac ans=*this;
    return ans/=other;
  }

  bool operator==(const frac& other)const{
    return bunsi==other.bunsi&&bumbo==other.bumbo;
  }
  bool operator!=(const frac& other)const{
    return !(*this==other);
  }
  bool operator<(const frac& other)const{
    return (__int128)bunsi*other.bumbo<(__int128)other.bunsi*bumbo;
  }
  bool operator>(const frac& other) const {
    return other<*this;
  }
  bool operator<=(const frac& other)const{
    return !(*this>other);
  }
  bool operator>=(const frac& other)const{
    return !(*this<other);
  }

};

i128 f(i128 p, i128 q){
  if(p>=0) return p/q;
  else{
    i128 pp=-p;
    return -(pp+q-1)/q;
  }
}

string to_string_128(i128 x){
  if(x==0) return "0";
  bool neg=false;
  if(x<0) neg=true, x=-x;
  string ans;
  while(x>0){
    int p=x%10;
    ans.push_back((char)('0'+p));
    x/=10;
  }
  if(neg) ans.push_back('-');
  reverse(ans.begin(), ans.end());
  return ans;
}
//i128用の入力オーバーロード
istream& operator>>(istream& is, i128& x){
  string s; cin >> s;
  bool neg=false;
  int i=0;
  if(s[0]=='-') neg=true, i++;
  i128 val=0;
  for(; i<s.size(); i++){
    int p=s[i]-'0';
    val=(val)*10+p;
  }
  x=(neg?-val:val);
  return is;
}
//i128用の出力オーバーロード
ostream& operator<<(ostream& os, i128 x){
  return os << to_string_128(x);
}

int main(void){
  int n, a, b; cin >> n >> a >> b;
  vector<i128> k(n+1), pa(n+2, 1), pb(n+2, 1);
  for(auto&x:k) cin >> x;
  for(int i=1; i<n+2; i++) pa[i]=pa[i-1]*a, pb[i]=pb[i-1]*b;
  frac ans(0, 1);
  for(int i=0; i<=n; i++){
    frac now(k[i]*(pb[i+1]-pa[i+1]), i+1);
    ans+=now;
  }
  i128 p=ans.bunsi, q=ans.bumbo;
  cout << f(p, q) << endl;
  return 0; 
}