#include <iostream>
#include <vector>
using ll =long long;
using namespace std;
//UnionFind
struct UnionFind{
    vector<ll> par,rank,siz;
    UnionFind(ll n): par(n,-1),rank(n,0),siz(n,-1){ }

    ll root(ll x){
        if(par.at(x)==-1)return x;
        else return par.at(x)=root(par.at(x));
    }

    bool issame(ll x,ll y){
        return root(x)==root(y);
    }

    bool unite(ll x,ll y){
        ll rx=root(x),ry=root(y);

        if(rx==ry) return false;
        if(rank.at(rx)>rank.at(ry)) swap(rx,ry);//大小関係は固定

        par.at(ry)=rx;//ry(デカいほう)にrx(小さいほう)を結合

        if(rank.at(rx)==rank.at(ry)) rank.at(rx)++;

        siz.at(rx)+=siz.at(ry);
        return true;
    }

    ll size(ll x){
        return siz.at(root(x));
    }
};