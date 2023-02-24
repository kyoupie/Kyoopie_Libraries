#include<iostream>
#include<vector>
using namespace std;
using ll=long long;


vector<pair<ll,ll>> prime_factorize(ll n){
    vector<pair<ll,ll>> res;
    for(ll p=2;p*p<=n;p++){
        if(n%p!=0)continue;

        ll e=0;
        while(n%p==0){
            e++;
            n/=p;
        }
        res.emplace_back(p,e);
    }
    if(n!=1){
        res.emplace_back(n,1);
    }
    return res;
}