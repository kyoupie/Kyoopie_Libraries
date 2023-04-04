#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(n);i++)//0-indexed

//トポロジカルソート
vector<ll> topological_sort(vector<vector<ll>>& g){//引数はgraphだけでよい
    vector<ll> sorted_vertices,indegree(g.size());
    queue<ll> que;
    rep(i,g.size()){
        for(auto j:g.at(i)){//入次数数え上げ
            indegree.at(j)++;
        }
    }
    rep(i,indegree.size()){
        if(indegree.at(i)==0)que.push(i);
    }
    while(!que.empty()){//BFS
        ll now = que.front();que.pop();
        for(auto i:g.at(now)){
            indegree.at(i)--;
            if(indegree.at(i)==0)que.push(i);//入次数が0になったら追加
        }
        sorted_vertices.push_back(now);//入次数が0になった順に挿入
    }
    return sorted_vertices;//返り値はvector
}