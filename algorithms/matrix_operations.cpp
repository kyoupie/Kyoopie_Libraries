#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)//0-indexed
using namespace std;
using ll = long long;

//行列積　ほんとはO(N^3)らしいが、行と列がそんなに長くない場合は定数倍なので無視できる
vector<vector<ll>> mat_mul(vector<vector<ll>>&a,vector<vector<ll>>&b,ll mod){
    vector<vector<ll>> res(a.size(),vector<ll>(b.at(0).size()));
    rep(i,a.size()){
        rep(j,b.at(0).size()){
            rep(k,b.size()){
                (res.at(i).at(j)+=a.at(i).at(k)*b.at(k).at(j))%=mod;
            }
        }
    }
    return res;
}

//行列累乗 O(logN)で動作
vector<vector<ll>> mat_pow(vector<vector<ll>>a,ll n,ll mod){
    vector<vector<ll>> res(a.size(),vector<ll>(a.size()));
    rep(i,a.size()) res.at(i).at(i)=1;

    while(n>0){
        if(n&1)res=mat_mul(a,res,mod);
        a=mat_mul(a,a,mod);
        n>>=1;
    }
    return res;
}