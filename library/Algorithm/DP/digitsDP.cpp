#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long LL;
typedef long double ld;
typedef vector<ll>VI;
typedef pair<int,int>P;
#define VV(T) vector<vector<T>>
#define sz(x) int(x.size())
#define PI 3.1415926535897932384626433832795
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)
#define reprev(i,n) for (ll i=(ll)n-1;i>=0;i--)
#define ALL(a)  (a).begin(),(a).end()
#define rALL(a) (a).rbegin(),(a).rend()
#define c_max(a,b) (((ll)a)>((ll)b)?(a):(b))
#define c_min(a,b) (((ll)a)<((ll)b)?(a):(b))
#define chmax(x,a) x=c_max(x,a)
#define chmin(x,a) x=c_min(x,a)
#define vmax(v) *max_element(ALL(v))
#define vmin(v) *min_element(ALL(v))
#define $(x) {cout<<#x<<" = " <<(x)<<endl;}
#define fi first
#define se second
#define MAX 100100//5
#define MAX2 200100
#define MAX6 1001001//6
#define MAX7 10010010//7
#define SENTINEL 2000000000//9
#define INF 1<<30
#define INFTY 1LL<<61
#define MAX_INT INT_MAX
#define MAX_LL LLONG_MAX
#define Endl '\n'
#define CLR(mat) memset(mat, 0, sizeof(mat))
inline ll GCD(ll a,ll b){return b?GCD(b,a%b):a;}//最大公約数
inline ll lcm(ll a,ll b){return a*b/GCD(a,b);}//最小公倍数
template<class T> bool contain(const std::string& s, const T& v) {
   return s.find(v) != std::string::npos;
}
const int MOD = 1000000007;
inline ll mod_add(ll a,ll b){return (a+b)%MOD;}
inline ll mod_sub(ll a,ll b){return (a+MOD-b)%MOD;}
inline ll mod_mul(ll a,ll b){return ((a%MOD)*(b%MOD))%MOD;}
inline ll mod_pow(ll x,ll n,ll mod=(ll)MOD){ll res=1;while(n>0){
if(n&1)res=res*x%mod;
x=x*x%mod;n>>=1;}return res;}
inline ll mod_inv(ll x){return mod_pow(x,MOD-2);}
inline ll mod_div(ll a, ll b){return mod_mul(a,mod_inv(b));}
//const int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
// vector型から重複を削除 list.erase(unique(ALL(list)),list.end());
// g++ -o a a.cpp -Wall -lm -std=c++17
//push_back -> emplace_back
//using Graph=vector<vector<ll>>;


//Nは桁数が大きい場合があるので文字列として受け取る
string N;
vector<int> n;  //Nの各桁の数字を格納するベクター
const int dp_i=100100,dp_j=12; //dp_iはNの長さ, dp_jは状態の数
ll dp[dp_i][2][dp_j]; // 2はsmallerフラグ

int main(){
  cin>>N;

  //ベクターnを構成
  for(auto a : N){
    n.push_back(a-'0');
  }
  int l = N.size();  //nの長さ
   CLR(dp);
  dp[0][0][0] = 1;  //初期条件。他は0で初期化されている
  for(int i = 0; i < l; i++){
    for(int smaller = 0; smaller < 2; smaller++){
      for(int j = 0; j < dp_j; j++){
        for(int x = 0; x <= (smaller ? 9 : n[i]); x++){
            /* 書き換えるのはここだけ */
          if(x==1)dp[i + 1][smaller || x < n[i]][j+1] += dp[i][smaller][j];
          else dp[i+1][smaller || x<n[i]][j]+=dp[i][smaller][j];
        }
      }
    }
  }
   ll ans=0;
   rep(i,11){
      ans+=i*(dp[l][0][i]+dp[l][1][i]);
   }
   cout<<ans<<endl;
  return 0;
}