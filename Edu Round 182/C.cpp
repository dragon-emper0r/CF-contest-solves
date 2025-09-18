// Problem Link : https://codeforces.com/contest/2144/problem/C
// Problem Name : Non Descending Arrays
// Idea : There is a big hint in the problem statement itself!
// It says that there exists at least one solution
// So, it's for sure that if we keep the small values on one of the sides
// blindly, we will get a solution! We can keep the smaller values of either
// of the sides. So, minimum ans = 2.
// Idea : We can branch out from the produced answers! 
// Since a and b are sorted, so we can swap (a[i], b[i]) iff
// max(a[i], b[i]) <= min(a[i + 1], b[i + 1]). 2 options-> may swap or may
// not swap. So two valid branches are produced! So the answer becomes double!
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
  vector<int> a(n + 1), b(n + 1);
  for(int i = 1; i <= n; i++) cin >> a[i];
  for(int i = 1; i <= n; i++)   cin >> b[i];
  int ans = 2;
  for(int i = 1; i < n; i++){
    if(max(a[i], b[i]) <= min(a[i + 1], b[i + 1]))  ans = mul(ans, 2);
  }
  cout << ans << '\n';
}

int32_t main() {
    fastio();
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}

// Time Complexity : O(n);