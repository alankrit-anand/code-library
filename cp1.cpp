//* Author: ShlokG *//
// #pragma GCC optimize("Ofast")  
// #pragma GCC target("avx,avx2,fma") 
// #pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order(k)  returns iterator to kth element starting from 0
// order_of_key(k) returns count of elements strictly smaller than k
#define fix(f,n) std::fixed<<std::setprecision(n)<<f
#define epsi (double)(0.00000000001)
typedef long long int ll;
typedef unsigned long long int ull;
#define vi vector<ll>
#define pii pair<ll,ll>
#define vii vector<pii>
//#define max(a,b) ((a>b)?a:b)
//#define min(a,b) ((a>b)?b:a)
#define min3(a,b,c) min(min(a,b),c)
#define min4(a,b,c,d) min(min(a,b),min(c,d))
#define max3(a,b,c) max(max(a,b),c)
#define max4(a,b,c,d) max(max(a,b),max(c,d))
#define ff(a,b,c) for(int a=b; a<=c; a++)
#define frev(a,b,c) for(int a=c; a>=b; a--)
#define REP(a,b,c) for(int a=b; a<c; a++)
#define pb push_back
#define mp make_pair
#define endl "\n"
#define all(v) v.begin(),v.end()
#define sz(a) (ll)a.size()
#define F first
#define S second
#define ld long double
#define INf 2000000000000000000
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define ub upper_bound
#define lb lower_bound
#define setbits(x) __builtin_popcountll(x)
#define trav(a,x) for(auto &a:x)
#define make_unique(v) v.erase(unique(v.begin(), v.end()), v.end())
#define rev(arr) reverse(all(arr))
#define gcd(a,b) __gcd(a,b);
#define ub  upper_bound // '>'
#define lb  lower_bound // '>='
#define qi queue<ll>
#define si stack<ll>

const long double PI = acos(-1);

mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
    uniform_int_distribution<int> uid(0,lim-1);
    return uid(rang);
}

ll gcdExtended(ll a, ll b, ll *x, ll *y){
    if(a == 0){
        *x = 0;
        *y = 1;
        return b;
    }
    ll x1, y1;
    ll gcd = gcdExtended(b%a, a, &x1, &y1);
    *x = y1 - (b/a) * x1;
    *y = x1;
    return gcd;
}
 
ll modInverse(ll a, ll m){
    ll x, y;
    ll g = gcdExtended(a, m, &x, &y);
        ll res = (x%m + m) % m;
        return res;
}

ll binary_Search(vector<ll>&arr,ll key){
    ll l=0,r=arr.size()-1;
    ll ans;
    while(l<=r){
        ll mid=(l+r)/2;
        ll value=arr[mid];
        if(value>key){
            r=mid-1;
        }else if(value==key){
            return mid;
        }else{
            l=mid+1;
        }
    }
    return -1;
}
 
ll power(ll x,ll y,ll p){
    ll res = 1;
    x = x % p;
    if (x == 0) return 0;
    while (y > 0){  
        if (y & 1){
            res=(res*x)%p;
        }
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}

// bool check(ll x){
//     ll tem=sqrt(x);
//     if((tem*tem)==x){
//         return 1;
//     }
//     return 0;
// }

const ll MAX=1e18+5;
const int N=1e6+5;
vector<int> pr;

ll prime[N+5];
void SieveOfEratosthenes(){ 
    memset(prime, 0, sizeof(prime)); 
    prime[1]=1;
    for(ll p=2 ; p<N ; p++){
        if(prime[p] == 0){
            for(ll i=p ; i<N ; i+=p){
                if(prime[i]==0){
                    prime[i]=p;
                }
            }
        }
    }
    // for(int i=2 ; i<N;  i++){
    //     if(!prime[i]){
    //         pr.pb(i);
    //     }
    // }
}

ll mod=1e9+7;
ll mod1=998244353;

const int INF = 1e9;

void precompute(){

}

struct DSU{
    map<ll,ll> parent;
    DSU(){

    }

    ll find_set(int v){
        if (v==parent[v]){
            return v;
        }
        return parent[v]=find_set(parent[v]);
    }

    void union_sets(ll b,ll a){
        if(parent.find(a)==parent.end()){
            parent[a]=a;
        }
        if(parent.find(b)==parent.end()){
            parent[b]=b;
        }
        int x1=a;
        int x2=b;

        a = find_set(a);
        b = find_set(b);
        assert(a<=x1);
        assert(b<=x2);
        if(a != b){
            if (a>b)
                swap(a, b);
            assert(a<b);
            parent[b] = a;
        }
    }

    ll query(){
        ll ret=0;
        for(auto j:parent){
            ll x=find_set(j.F);
            assert(x<=j.F);
            if(j.F==x){
                ret++;
            }
        }
        return ret;
    }
};

void TEST_CASE(){
    int n;
    cin >> n;
    ll minm=1e9;
    DSU dsu;
    ll ans=0;
    for(int i=0 ; i<n ; i++){
        vi primes;
        ll x;
        cin >> x;
        if(x==1){
            ans++;
            continue;
        }
        assert(x!=1);
        ll min1=1e9;
        while(x!=1){
            primes.pb(prime[x]);
            min1=min(min1,prime[x]);
            x/=prime[x];
        }
        assert(x==1);
        for(auto j:primes){
            dsu.union_sets(min1,j);
        }
        minm=min(minm,min1);
    }
    if(n==1){
        cout << 0 << endl;
        return;
    }
    if(ans==n){
        cout << 2*n << endl;
        return;
    }
    assert(minm<1e7);
    assert(ans<n);
    assert(min(1ll*minm*(1ll*dsu.query()+1ll*ans-1),2*(ans+dsu.query()))<=2*n);
    cout << min(1ll*minm*(1ll*dsu.query()+1ll*ans-1),2*(ans+dsu.query())) << endl;
}

signed main(){
    fast;
    //freopen ("INPUT.txt","r",stdin);
    //freopen ("OUTPUT.txt","w",stdout);
    int test=1,TEST=1;
    precompute();
    SieveOfEratosthenes();
    cin >> test;
    while(test--){
        //cout << "Case #" << TEST++ << ": ";
        TEST_CASE();
    }
    return 0;
}