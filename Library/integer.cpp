#include<bits/stdc++.h>
using namespace std;
using ll = long long;

//桁数を求める
int digit(ll x){
  int ans=1;
  while(x/10){
    ans++; x/=10;
  }
  return ans;
}

//べき乗 a^b を愚直に求める。(大きな桁数の数字を扱うときのpowは信用ならない！！)
ll power(ll a, ll b){
  ll ans=1;
  for(int i=0; i<b; i++){
    ans*=a;
  }
  return ans;
}

//最大公約数を求める。
ll gcd(ll a, ll b){
  if(b==0) return a;
  return gcd(b, a%b);
}

ll extgcd(ll a, ll b, ll& x, ll& y){
  if(b==0){
    x=1, y=0; return a;
  }
  ll x1, y1;
  ll gcd=extgcd(b, a%b, x1, y1);
  x=y1; y=x1-(a/b)*y1;
  return gcd;
}

//a^b % pを求める。998244353の逆元など。 逆元はpが素数なときにのみ使える(cf. fermatの小定理)
//mod=998244353の逆元は、modpow(a, mod-2, mod).  ちなみに2の逆元は499122177
ll modpow(ll a, ll b, ll p){
  a%=p;
  ll ans=1;
  while(b>0){
    if(b%2==1) ans=(ans*a)%p;
    b/=2;
    a=(a*a)%p;
  }
  return ans;
}

//Eulerのphi関数　任意の正整数aに対し, aと互いに素な任意の正整数bを取ると、a^phi(b)=1 (mod b)
ll phi(ll n){
  ll r=n;
  for(ll i=2; i*i<=n;i++){
    if(n%i==0){
      r-=r/i;
      while(n%i==0){
        n/=i;
      }
    }
  }
  if(n>1){
    r-=(r/n);
  }
  return r;
}
//

//Eulerのphi関数の列挙(線形) 
vector<ll> EulerPhi(int n){
  vector<ll> ans(n+1), prime;
  ans[1]=1;
  for(int i=2; i<=n; i++){
    if(ans[i]==0){
      prime.push_back(i);
      ans[i]=i-1;
    }
    for(auto p:prime){
      if((ll)i*p>n) break;
      ans[i*p]=ans[i]*(p-(i%p?1:0));
      if(i%p==0) break;
    }
  }
  return ans;
}

ll intsqrt(ll x){ //floor(\sqrt(x))
  ll left=0, right=1e9;
  while(right-left>1){
    ll mid=(left+right)/2;
    if(mid*mid<=x) left=mid;
    else right=mid;
  }
  return left;
}

//メビウス変換のmu(線形)
vector<int> mobius(int n){
  vector<int> prime, mu(n+1);
  vector<bool> pq(n+1, false);
  mu[1]=1;
  for(int i=2; i<=n; i++){
    if(!pq[i]){
      prime.push_back(i);
      mu[i]=-1;
    }
    for(auto p:prime){
      ll m=(ll)i*p;
      if(m>n) break;
      pq[m]=true;
      if(i%p) mu[m]=-mu[i];
      else{mu[m]=0; break;}
    }
  }
  return mu;
}

using i128 = __int128_t; 
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

//combination
vector<vector<ll>> comb(int n, ll mod){
  vector nck(n+1, vector<ll>(n+1));
  for(int i=0; i<=n; i++)for(int j=0; j<=i; j++){
    if(j==0||j==i) nck[i][j]=1;
    else nck[i][j]=nck[i-1][j-1]+nck[i-1][j], nck[i][j]%=mod;
  }
  return nck;
}

//階乗計算, nCkに使える
pair<vector<ll>, vector<ll>> factorial(int n, ll mod){
  vector<ll> fact(n+1, 1), invfact(n+1, 1);
  for(ll i=2; i<=n; i++) fact[i]=fact[i-1]*i%mod;
  invfact[n]=modpow(fact[n], mod-2, mod);
  for(ll i=n-1; i>=1; i--) invfact[i]=invfact[i+1]*(i+1)%mod;
  return {fact, invfact};
}

//ax≡b mod m (0, -1):解なし, (0, 1):任意
pair<ll, ll> crt1(ll a, ll b, ll m){
  if(m==0) return {0, -1};
  b=(b%m+m)%m;
  if(a==0) return (b==0?make_pair(0, 1):make_pair(0, -1));
  ll x, y, g=extgcd(a, m, x, y);
  if(b%g) return {0, -1};
  a/=g, b/=g, m/=g;
  extgcd(a, m, x, y);
  ll r=b*x%m; r=(r+m)%m;
  return make_pair(r, m);
}

//ax≡b mod m1, cx≡d mod m2
pair<ll, ll> crt2(ll a, ll b, ll m1, ll c, ll d, ll m2){
  auto [r1, n1]=crt1(a, b, m1); // x≡r1 mod n1
  auto [r2, n2]=crt1(c, d, m2); // x≡r2 mod n2
  if(n1==-1||n2==-1) return {0, -1};
  r1=(r1%n1+n1)%n1, r2=(r2%n2+n2)%n2;
  if(n1==1) return {r2, n2};
  if(n2==1) return {r1, n1};
  ll x, y;
  ll g=extgcd(n1, n2, x, y);
  if(r1%g!=r2%g) return {0, -1};
  ll D=(r2-r1)/g;
  ll n2g=n2/g, inv=(x%n2g+n2g)%n2g;
  ll t=(ll)((__int128)D*inv%n2g); t=(t+n2g)%n2g;
  __int128 lcm=(__int128)(n1/g)*n2;
  __int128 ans=r1+(__int128)n1*t; ans=((ans%lcm)+lcm)%lcm;
  return {ans, lcm};
}

//高速な素数判定法
bool Miller_Rabin(ll n){ //少なくともn<=10^18では有効らしい
  using I128 = __int128_t;
  auto Modpow=[](I128 a, ll b, ll p){
    a%=p;
    I128 ans=1;
    while(b){
      if(b&1) ans=(ans*a)%p;
      b/=2;
      a=(a*a)%p;
    }
    return (ll)ans;
  };
  if(n<2) return false;
  if(n==2) return true;
  if(n%2==0) return false;
  ll test[]={2,325,9375,28178,450775,9780504,1795265022};
  ll x=n-1, s=0;
  while(x%2==0) x/=2, s++;
  for(auto a:test){
    if(a%n==0) continue;
    ll base=Modpow(a, x, n);
    if(base==1) continue;
    for(int j=0; j<=s-1; j++){
      if(base==n-1) break;
      if(j==s-1) return false;
      base=I128(base)*base%n;
    }
  }
  return true;
}


int main(void){
  //for(int i=1; i<=10; i++)
  cout << modpow(6, 998244351, 998244353) << endl;
    
  //n以下の最小の約数をもつ配列 yakusu[1]=1, yakusu[3]=3, yakusu[6]=2
  int n; cin >> n;

  int nn=n;
  vector<int> yakusu(nn+1, -1), prime;
  for(int i=2; i<=nn; i++){
    if(yakusu[i]!=-1) continue;
    int copy=i;
    prime.push_back(i);
    while(copy<=nn){
      if(yakusu[copy]==-1) yakusu[copy]=i;
      copy+=i;
    }
  }
  for(int i=0; i<n+1; i++) cout << yakusu[i] << ' ';
  //-----------------

  //------階乗, 逆元計算
  int facn=n;
  ll facmod=998244353;
  vector<ll> fact(facn+1, 1), invfact(facn+1, 1);
  for(ll i=2; i<=facn; i++) fact[i]=fact[i-1]*i%facmod;
  invfact[facn]=modpow(fact[facn], facmod-2, facmod);
  for(ll i=facn-1; i>=2; i--) invfact[i]=invfact[i+1]*(i+1)%facmod;
  //------------------

  //普通の素因数分解
  int n; cin >> n;
  cout << n << ':';
  int i=2;
  while(i*i<=n){
    while(n%i==0){
      cout << ' ' << i;
      n/=i; 
    }
    i+=1;
  }
  if(n!=1) cout << ' ' << n;
  //-------------

  return 0;
}