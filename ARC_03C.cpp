#include<bits/stdc++.h>
using namespace std;
using ll = int64_t;
using LL = uint64_t;
typedef vector<ll> VI;
typedef pair<ll,ll> P;
#define sz(x) int(x.size())
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define For(i,l,r) for (int i = (int)l; i < (int)r; i++)
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
const int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
// g++ -o a a.cpp -Wall -lm -std=c++17
// emplace_back
// scanf("%s", &m[i][0]);

int N,M;
int sy,sx,gy,gx;
char m[510][510];
int t_limit[510][510];
int min_dist[510][510];
bool visited[510][510];//for dfs();
const double base = log((double)0.99);
int char2num(char s){
    if('0' <= s && s <= '9')return s - '0';
    else return 0;
}

void shortest(){
    rep(i,N)rep(j,M)min_dist[i][j] = INF;
    queue<P> que;
    que.push(P(sy,sx));
    min_dist[sy][sx]=0;
    while(!que.empty()){
        P p = que.front();que.pop();
        rep(i,4){
            int ny = p.fi + dy[i], nx = p.se + dx[i];
            if(min_dist[ny][nx] != INF)continue;
            if(ny < 0 || nx < 0 || ny >= N || nx >= M)continue;
            min_dist[ny][nx] = min_dist[p.fi][p.se] + 1;
        }
    }
}
void dfs(int y,int x){
    visited[y][x]=true;
    rep(i,4){
        int ny = y + dy[i], nx = x + dx[i];
        if(visited[ny][nx])continue;
        if(ny == gy && nx == gx){
            visited[gy][gx] = true;
            return;
        }
        if(ny < 0 || nx < 0 || ny >= N || nx >= M)continue;
        if(min_dist[ny][nx] > t_limit[ny][nx]){
            visited[ny][nx] = true;
            continue;
        }
        dfs(ny, nx);
    }
}
bool check(double x){
    rep(i, N)rep(j,M){
        int num;
        if((num = char2num(m[i][j])) != 0){
            t_limit[i][j]=round(log(x/(double)num)/base);
        }
    }
    //cout<<"A"<<endl;
    //rep(i,N){rep(j,M)cout<<t_limit[i][j]<<" ";cout<<endl;}
    memset(visited, 0, sizeof(visited));
    dfs(sy, sx);

    return visited[gy][gx];
}

double solve(){
    //最短経路を求める
    shortest();
    //二分探索
    double left = -1.0, right =  11.0, mid;
    while(right - left > 1e-9){
        mid = left + (right - left) / 2.0;
        if(check(mid))mid = left;
        else mid=right;
    }
    return left;
}

int main(){
    cin>>N>>M;
    rep(i,N)rep(j,M){
        cin>>m[i][j];
        if(m[i][j]=='s')sy=i,sx=j;
        else if(m[i][j]=='g')gy=i,gx=j;
    }
    double ans = solve();
    printf("%.12lf\n", ans);
}