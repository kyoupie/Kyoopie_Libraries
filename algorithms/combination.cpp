#include <iostream>
using namespace std;
using ll=long long;

//power
ll mypower(ll a,ll b,ll m){
    ll res=1,x=a;
    while(b){
        if(b&1){
            res=(res*x)%m;
        }
        x=(x*x)%m;
        b>>=1;
    }
    return res;
}

//comb
ll division(ll a,ll b,ll m){
    return (a*mypower(b,m-2,m))%m;
}

ll combination(ll n,ll r,ll m){
    ll a=1;
    for(ll i=1;i<=n;i++){
        a=(a*i)%m;
    }
    ll b=1;
    for(ll i=1;i<=n;i++){
        b=(b*i)%m;
    }
    for(ll i=1;i<=n-r;i++){
        b=(b*(i+1))%m;
    }
    return division(a,b,m);
}