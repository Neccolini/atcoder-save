struct graph{
   ll V;
   vector<vector<edge> >G;
   vector<ll>d;
   graph(ll n){
      init(n);
   }
   void init(ll n){
      V=n;
      G.resize(V);
      d.resize(V);
      rep(i,V)d[i]=INFTY;
   }
   void add_edge(ll s, ll t, ll cost=1){ // 一方の向きだけなのに注意
      edge e;
      e.to=t, e.cost=cost;
      G[s].push_back(e);
   }
   void dijkstra(ll s){
      //rep(i,V)d[i]=INFTY;
      d[s]=0;
      priority_queue<P,vector<P>,greater<P> >que; // firstは距離, secondはノードの番号
      que.push(P(0,s));
      while(que.size()){
         P p=que.top();que.pop();
         ll v=p.second;
         if(d[v]<p.first)continue; // 探索済みなら
         for(auto e:G[v]){
            if(d[e.to]>d[v]+e.cost){ //vにつながるノードで距離を更新できるなら
               d[e.to]=d[v]+e.cost; //更新する
               que.push(P(d[e.to],e.to));
            }
         }
      }
   }

   bool bellman_ford(ll s){//あってるかな
       d[s]=0;
       rep(i,V){
           rep(v,V){
               for(auto e:G[v]){
                   if(d[v]!=INFTY && d[e.to]>d[v]+e.cost){
                       d[e.to]=d[v]+e.cost;
                       if(i==V-1)return true;
                   }
               }
           }
       }
       return false;
   }
};
