#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef pair<long, int> P;
const long long INF = 1LL << 60;
struct Edge{
    int to;
    long long cost;
}
using Graph = vector<vector<Edge>>;
void dijkstra(Graph &G, int s, vector<long long> &d){
    int N = G.size();
    d.resize(N, INF);
    priority_queue<P, vector<P>, greater<P>> que;
    d[s] = 0;
    que.push(P(0, s));
    while(!que.empty()){
        P p = que.top();
        que.pop();
        int v = p.second;
        if (d[v] < p.first) continue;
        for(P e : G[p.second]){
            if(d[e.to] > d[p.second] + e.cost){
                d[e.to] = d[p.second] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}

