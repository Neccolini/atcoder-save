#include<bits/stdc++.h>
using namespace std;
using ll = int64_t;
using LL = uint64_t;
typedef vector<ll>VI;
typedef pair<ll,ll>P;
#define VV(T) vector<vector<T>>
#define sz(x) int(x.size())
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ALL(a)  (a).begin(),(a).end()
#define rALL(a) (a).rbegin(),(a).rend()
#define c_max(a,b) (((ll)a)>((ll)b)?(a):(b))
#define c_min(a,b) (((ll)a)<((ll)b)?(a):(b))
#define vmax(v) *max_element(ALL(v))
#define vmin(v) *min_element(ALL(v))
#define $(x) {cout<<#x<<" = " <<(x)<<endl;}
#define fi first
#define se second
#define MAX 100100
#define MAX6 1001001
#define MAX7 10010010
#define INF 1<<30
#define INFTY 1LL<<61
#define MAX_INT INT_MAX
#define MAX_LL LLONG_MAX
#define CLR(mat) memset(mat, 0, sizeof(mat))
#define DDP(v) v.erase(unique(v.begin(),v.end()), v.end()) //ソートされたvector vから重複を削除
template<class T, class U> inline bool chmax(T& a, U b) { if (a < b) { a = b; return 1; } return 0; }
template<class T, class U> inline bool chmin(T& a, U b) { if (a > b) { a = b; return 1; } return 0; }
#define MOD 1000000007
//const ll inf=1e18;
//const int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
// g++ -o a a.cpp -Wall -lm -std=c++17
// emplace_back
// scanf("%s", &m[i][0]);

ll dp[1010][5000]; //dp[i][j]:=鍵をi個目まで見て状態jであるときの費用の最小値
int main(){
    int N,M;cin>>N>>M;
    VI A(M);
    vector<vector<int>> C(M);
    rep(i,M){
        int b;cin>>A[i]>>b;
        rep(j,b){
            int x;cin>>x;x--;
            C[i].emplace_back(x);
        }
    }
    rep(i,M+1)rep(j,5000)dp[i][j]=INFTY;
    dp[0][0]=0;
    rep(i,M)for(int bit=0;bit<(1<<N);bit++){
        int n_bit=bit;
        for(auto v:C[i])n_bit|=(1<<v);
        chmin(dp[i+1][n_bit],dp[i][bit]+A[i]);

    }
    ll ans=INFTY;
    rep(i,M+1)chmin(ans,dp[i][(1<<N)-1]);
    if(ans==INFTY)ans=-1;
    cout<<ans<<endl;
}