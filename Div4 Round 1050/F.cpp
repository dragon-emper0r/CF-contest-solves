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
   vector<vector<int>> a(n);
   for(int i = 0; i < n; i++){
    int k; cin >> k;
    a[i].resize(k);
    for(auto &ele : a[i])  cin >> ele;
   }
   sort(a.begin(), a.end(), [](vector<int>&p, vector<int>&q){
    return p.size() < q.size();
   });
   int k_max = a.back().size();
   vector<int> ans(k_max, INF);
   vector<int> edit; edit.push_back(0);
   for(auto &v : a){
    int k = v.size();
    for(int i = 0; i < (int)edit.size(); i++){
        int l = edit[i], r = (i + 1 < (int)edit.size()) ? edit[i + 1] : k;
        bool yes = false;
        for(int idx = l; idx <= r; idx++){
            if(v[idx] > ans[idx])   break;
            if(ans[idx] > v[idx]) {yes = true; break;}
        }
        if(yes){
            for(int idx = l; idx < k; idx++){
                ans[idx] = v[idx];
            }
            while(edit.back() > l)  edit.pop_back();
            edit.push_back(k);
            break;
        }
    }
   }
   for(auto &ele : ans)  cout << ele << ' ';
   cout << endl;
}   

int32_t main() {
    fastio();
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}