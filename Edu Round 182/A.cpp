// Problem Link : https://codeforces.com/contest/2144/problem/A
// Problem Name : Cut the Array
// Idea : s1 + s2 + s3 = (all same) -> x(mod 3) + x(mod 3) + x (mod 3)
// -> 3 * x (mod 3) = 0(mod 3).
// if all different s1 + s2 + s3 = 0(mod 3) + 1(mod 3) + 2(mod 3) = 0(mod 3)
// The solution exists if sum % 3 == 0;
// Also when the solution exists, we can make any partition, it will satisfy
// if a[1] % 3 == 1 and a[2] % 3 == 0 then the rest will become % 3 = 2 automatically
// if a[1] % 3 == 1 and a[2] % 3  == 1 then the rest will become % 3 = 1 automatically;
// Same analogy for the other cases!
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
   int n; cin >> n; int sum = 0;
   for(int i = 1; i <= n; i++){
    int x; cin >> x;
    sum += x;
   }
   if(sum % 3 != 0) cout << 0 << ' ' << 0 << '\n';
   else cout << 1 << ' ' << 2 << '\n';
}

int32_t main() {
    fastio();
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}

// Time Complexity = O(n);
