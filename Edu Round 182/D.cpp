// Problem Link : https://codeforces.com/contest/2144/problem/D
// Problem Name : Price Tags
// Since the prices are completely random, we can't apply dp or greedy.
// Even binary search won't work coz the total profit will also depend on
// the availability of the new price tags. (Binary search function is a single variable
// function). So, we have to do a smart brute force. 
// It is easy to see that x = [2, maxC]. 
// If we iterate through all the possible values of x
// and solve for each of them and then maximize, 
// it will give a complexity of O(n ^ 2). So, TLE!

// Idea : Iterate through the produced prices.
// Observe that the range of the produced prices is 
// low. Such as a = [46, 47, 48, 49, 50], if x = 5, all 
// the new prices are 10. 

// Idea : floor(n / x) or ceil(n / x) will be the same for
// a range of numbers. So, variation will be less. VVI;

// for(x = 2 to maxC){for(p = 1 to maxC / x)}
// O(maxC + maxC / 2 + maxC/ 3 + ...) = O(maxC log(maxC))

// Idea: We can simply use prefix sum idea to see how many
// numbers will yield a particular new_price.

// p - 1 < c / x <= p -> c = [x * (p - 1) + 1, p * x];

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
  int n, y; cin>> n >> y;
  vector<int> a(n + 1); int mx = -INF;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
    mx = max(mx, a[i]);
  }
  if(mx == 1){
    cout << n << '\n';
    return;
  }
  vector<int> frq(mx + 5, 0), pref(mx + 5, 0);
  for(int i = 1; i <= n; i++)   frq[a[i]]++;
  for(int i = 1; i <= mx; i++)   pref[i] = pref[i - 1] + frq[i];
  int ans = -INF;
  for(int x = 2; x <= mx; x++){
    int max_p = (mx + x - 1) / x;
    int sum = 0, prev = 0;
    for(int j = 1; j <= max_p; j++){
        int l = (j - 1) * x + 1, r = min(mx, j * x);
        if(l > r)   continue;
        int nums = pref[r] - pref[l - 1];
        sum += nums * j;
        prev += min(frq[j], nums);
    }
    ans = max(ans, sum - (n - prev) * y);
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

// Time Complexity = O(mx * log(mx));