#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD1=1e9+7,MOD2=1e9+9,p1=29,p2=37;
ll inv1,inv2;
int N,K,Ans;
string S;
int A[100000],B[100000];
unordered_set<ll> Set1,Set2;
ll my_pow(ll a,ll b,ll mod){
    ll ret=1;
    while (b){
        if (b&1)
            ret=ret*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    inv1=my_pow(p1,MOD1-2,MOD1);
    inv2=my_pow(p2,MOD2-2,MOD2);
    cin>>N>>K>>S;
    for (int i=0; i<N; i++)
        A[i]=S[i]-'0';
    cin>>S;
    for (int i=0; i<N; i++)
        B[i]=S[i]-'0';
    ll val1=0,val2=0,tmp1=1,tmp2=1;
    for (int i=0; i<K; i++){
        val1=(val1+A[i]*tmp1)%MOD1;
        val2=(val2+A[i]*tmp2)%MOD2;
        tmp1=tmp1*p1%MOD1;
        tmp2=tmp2*p2%MOD2;
    }
    Set1.insert(val1*MOD2+val2);
    for (int i=K; i<N; i++){
        val1=((val1-A[i-K])%MOD1+A[i]*tmp1%MOD1)%MOD1*inv1%MOD1;
        val2=((val2-A[i-K])%MOD2+A[i]*tmp2%MOD2)%MOD2*inv2%MOD2;
        Set1.insert(val1*MOD2+val2);
    }
    val1=val2=0;
    tmp1=tmp2=1;
    for (int i=0; i<K; i++){
        val1=(val1+B[i]*tmp1)%MOD1;
        val2=(val2+B[i]*tmp2)%MOD2;
        tmp1=tmp1*p1%MOD1;
        tmp2=tmp2*p2%MOD2;
    }
    Set2.insert(val1*MOD2+val2);
    for (int i=K; i<N; i++){
        val1=((val1-B[i-K])%MOD1+B[i]*tmp1%MOD1)%MOD1*inv1%MOD1;
        val2=((val2-B[i-K])%MOD2+B[i]*tmp2%MOD2)%MOD2*inv2%MOD2;
        Set2.insert(val1*MOD2+val2);
    }
    for (ll i:Set2)
        Ans+=(Set1.find(i)!=Set1.end());
    cout<<Ans;
    return 0;
}