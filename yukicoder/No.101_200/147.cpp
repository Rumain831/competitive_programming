#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: 行列累乗, dp, 数え上げ
//Level: 3

ll mod = 1e9+7;

struct Matrix{
  int r, c;
  vector<vector<ll>> a;
  Matrix(int r, int c) :r(r), c(c), a(r, vector<ll>(c, 0)){}
  
  static Matrix iden(int n){ //正方行列限定
    Matrix I(n, n);
    for(int i=0; i<n; i++) I.a[i][i]=1;
    return I;
  }

  // --- 加算・減算 ---
  Matrix& operator+=(const Matrix& rhs) {
    //assert(r==rhs.r&&c==rhs.c);
    for(int i=0; i<r; i++)for(int j=0; j<c; j++){
      a[i][j]+=rhs.a[i][j];
      if(a[i][j]>=mod) a[i][j]-=mod;
    }
    return *this;
  }
  Matrix& operator-=(const Matrix& rhs) {
    //assert(r==rhs.r&&c==rhs.c);
    for(int i=0; i<r; i++)for(int j=0; j<c; j++){
      a[i][j]-=rhs.a[i][j];
      if(a[i][j]<0) a[i][j]+=mod;
    }
    return *this;
  }
  friend Matrix operator+(Matrix lhs, const Matrix& rhs){return lhs+=rhs;}
  friend Matrix operator-(Matrix lhs, const Matrix& rhs){return lhs-=rhs;}

  Matrix operator*(const Matrix& rhs) const { //base*rhs
    //assert(c==rhs.r);
    Matrix ans(r, rhs.c);
    for(int i=0; i<r; i++){
      for(int k=0; k<c; k++){
        if(a[i][k]==0) continue;
        for(int j=0; j<rhs.c; j++){
          ans.a[i][j]+=a[i][k]*rhs.a[k][j];
          ans.a[i][j]=(ans.a[i][j]%mod+mod)%mod;
        }
      }
    }
    return ans;
  }

  Matrix& operator*=(const Matrix& rhs){return *this=(*this)*rhs;}

  // --- ベクトルとの積 (列ベクトル) ---
  vector<ll> mul_vec(const vector<ll>& v) const {
    //assert(c == (int)v.size());
    vector<ll> res(r, 0);
    for(int i=0;i<r;i++){
      __int128 acc = 0;
      for(int j=0;j<c;j++){
        acc += (__int128)a[i][j] * v[j];
      }
      res[i] = (ll)(acc % mod);
    }
    return res;
  }

  // --- 転置 ---
  Matrix transpose() const {
    Matrix t(c, r);
    for(int i=0;i<r;i++)for(int j=0;j<c;j++) t.a[j][i] = a[i][j];
    return t;
  }

  friend ostream& operator<<(ostream& os, const Matrix& M){
    for(int i=0;i<M.r;i++){
      for(int j=0;j<M.c;j++){
        os << M.a[i][j] << (j+1==M.c?'\n':' ');
      }
    }
    return os;
  }
};

Matrix pow(Matrix A, ll k){
  Matrix R(A.r, A.r);
  R=R.iden(A.r);
  while(k){
    if(k&1) R=A*R;
    A=A*A;
    k>>=1;
  }
  return R;
}

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


int main(void){
  int n; cin >> n;
  ll ans=1, m=mod-1;
  Matrix A(2, 2);
  A.a={{1, 1}, {1, 0}};
  vector<ll> v={1, 0};
  while(n--){
    ll c; cin >> c;
    string d; cin >> d;
    ll r=0;
    for(auto p:d){
      int now=p-'0';
      r=(r*10+now)%m;
    }
    auto B=pow(A, c);
    auto u=B.mul_vec(v);
    ll x=u[0]+u[1]; x%=mod;
    if(x) ans*=modpow(x, r, mod), ans%=mod;
    else ans=0;
  }
  cout << ans << endl;
  return 0; 
}