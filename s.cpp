#include<bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i, n) for (int i = 0; i < (int)n; i++)

const ll M = 10000000000;
int main(){
   int N;cin>>N;
   string T;cin>>T;
   bool flag;
   ll ans = 0;
   rep(i, 3) {
      flag = true;
      ll a = (T.size() + i + 2) / 3;
      ll add = M - a + 1;
      rep(j,N){
         char s = ((i+j)%3==2 ? '0' : '1');
         flag &= (T[j] == s);
      }
      if(flag){
         ans += add;
      }
   }
   cout<<ans<<endl;
}