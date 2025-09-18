// Problem Link : https://codeforces.com/contest/2144/problem/B
// Problem Name : Maximum Cost Permutation
// We have to sort the part [i, j] where i is the least idx such that a[i] != i
// and j is the max idx such that a[j] != j;
// if we get some 0's we will put the missiing values there in desceding order.
// This will ensure the cost to be maximum. After that we just find r - l + 1;
#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt") // Optional
#define int long long
#define ll long long
#define pb push_back
#define ff first
#define sf second
#define endl "\n"
#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr);
const int INF = (int)1e18;
const int MOD = 998244353;
const int MAXN = (int)2e6 + 10;
ll fact[MAXN], invfact[MAXN];

inline ll add(ll a, ll b, ll m=MOD) { return (a + b) % m; }
inline ll sub(ll a, ll b, ll m=MOD) { return (a - b + m) % m; }
inline ll mul(ll a, ll b, ll m=MOD) { return (a * b) % m; }
 
ll modexp(ll a, ll e, ll m=MOD) {
    ll r = 1; a %= m;
    while (e) {
        if (e & 1) r = (r * a) % m;
        a = (a * a) % m;
        e >>= 1;
    }
    return r;
}
 
ll inv(ll a, ll m=MOD) { return modexp(a, m - 2, m); }

ll ncr(int n, int r, ll m=MOD) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invfact[r] % m * invfact[n-r] % m;
}

void precompute_factorials(int n=MAXN-1, ll m=MOD) {
    fact[0] = 1;
    for (int i = 1; i <= n; i++) fact[i] = (fact[i-1] * i) % m;
    invfact[n] = inv(fact[n], m);
    for (int i = n-1; i >= 0; i--) invfact[i] = (invfact[i+1] * (i+1)) % m;
}


void solve() {
   int n; cin >> n;
   vector<int> a(n + 1), vis(n + 1, 0);
   for(int i = 1; i <= n; i++){
    cin >> a[i];
    vis[a[i]] = 1;
   }
   vector<int> m;
   for(int i = 1; i <= n; i++){
    if(!vis[i]) m.push_back(i);
   }
   int j = (int)m.size() - 1;
   for(int i = 1; i <=n; i++){
    if(!a[i])   a[i] = m[j--];
   }
   int r = 1, l = n, yes = 0;
   for(int i = 1; i <= n; i++){
    if(a[i] != i){
        yes = 1;
        l = min(l, i);
        r = max(r, i);
    }
   }
   if(!yes) cout << 0 << '\n';
   else cout << r - l + 1 << '\n';
}   

int32_t main() {
    fastio();
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}

// Time Complexity : O(n);