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

int gcd(int a, int b){
    if(b == 0)  return a;
    return gcd(b, a % b);
}

void add_divs(unordered_map<int, int>& mp, int n){
    for(int i = 1; i * i <= n; i++){
        if(n % i == 0){
            mp[i]++;
            if(n / i != i)  mp[n / i]++;
        }
    }
}

int f(unordered_map<int, int>& mp, int g, int n){
    int ans = 0;
    for(int i = 1; i * i <= n; i++){
        if(n % i)   continue;
        if(gcd(i, g) == g && i > g) ans = max(ans, mp[i]);
        if(gcd(n / i, g) == g && n / i > g) ans = max(ans, mp[n / i]);
    }
    return ans;
}


void solve() {
   int n; cin >> n;
   vector<int> a(n + 1);
   for(int i = 1; i <= n; i++)  cin >> a[i];
   unordered_map<int, int> div_cnt;
//    vector<int> div_cnt(n + 1, 0);
   vector<int> ans(n + 1);
   ans[1] = 0;
   int pref_gcd = a[1];
   add_divs(div_cnt, a[1]);
   for(int i = 2; i <= n; i++){
    int g = gcd(pref_gcd, a[i]);
    add_divs(div_cnt, a[i]);
    if(g != pref_gcd){
        ans[i] = i - 1;
    }else{
        ans[i] = max(ans[i - 1], f(div_cnt, g, a[i]));
    }
    pref_gcd = g;
   }
   for(int i = 1; i <= n; i++)  cout << ans[i] << ' ';
   cout << endl;
}   

int32_t main() {
    fastio();
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}