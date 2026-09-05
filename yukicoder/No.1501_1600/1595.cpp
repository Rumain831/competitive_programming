#include<iostream>
#include<vector>
using namespace std;
using ll = long long;
ll mod=10;

//Tags: 漸化式, 行列累乗
//Level: 2.5

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

int main(void){
  int p, q, r; ll k; cin >> p >> q >> r >> k;
  Matrix A(3, 3);
  A.a={{1, 1, 1}, {1, 0, 0}, {0, 1, 0}};
  auto B=pow(A, k-3);
  auto v=B.mul_vec({r, q, p});
  cout << v[0] << endl;
  return 0; 
}