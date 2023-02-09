#include <iostream>
#include <vector>
using namespace std;
using ll =long long;
vector<bool> Eratosthenes(ll n){
    vector<bool> is_prime(n+1,true);
    is_prime.at(0)=is_prime.at(1)=false;
    for(ll i=2;i*i<=n;i++){
        if(is_prime.at(i)){
            for(ll j=i*2;j<=n;j+=i){
                is_prime.at(j)=false;
            }
        }
    }
    return is_prime;
}