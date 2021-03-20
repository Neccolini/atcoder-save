#include<bits/stdc++.h>
using namespace std;
using ll = int64_t;

inline ll mod_pow(ll x,ll n,ll mod){
    ll res=1;
    while(n>0){
        if(n&1)res=res*x%mod;
        x=x*x%mod;
        n>>=1;
    }
    return res;
}

int main(){
    ll A,B,C;cin>>A>>B>>C;
    A%=10;
    if(A==0 || A==1 || A==5||A==6){
        cout<<A<<endl;
        return 0;
    }
    if(A==4 || A==9){
        ll times = mod_pow(B,C,2);
        if(times==0)times=2;
        cout<<mod_pow(A,times,10)<<endl;
        return 0;
    }
    if(A==2 || A==3||A==7||A==8){
        ll times = mod_pow(B, C, 4);
        if(times==0)times=4;
        cout<<mod_pow(A,times,10)<<endl;
    }
}
