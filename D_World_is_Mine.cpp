// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

using namespace std;

#define FAST_IO (ios_base::sync_with_stdio(false), cin.tie(NULL));

#define ll long long
#define ull unsigned long long
#define max_3(x, y, z) max(max(x, y), z)
#define max_4(w, x, y, z) max(max(x, y), max(w, z))

#define c(x) cout << x << endl;
#define c2(x, y) cout << x << " " << y << endl;
int vectr;
#define in(a, n)                \
    for (int i = 0; i < n; i++) \
        cin >> a[i];
#define out(a, n)               \
    for (int i = 0; i < n; i++) \
        cout << a[i] << " ";
#define inv(a, n)               \
    for (int i = 0; i < n; i++) \
    {                           \
        cin >> vectr;           \
        a.push_back(vectr);     \
    }

#define ff first
#define ss second
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size();

#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;

#define PI 3.141592653589793238
#define MIN INT_MIN
#define MAX INT_MAX
#define INF LONG_LONG_MAX
#define MOD 1000000007
#define LLM 1000000000000000007

ll setbit(ll x)
{
    return __builtin_popcountll(x);
}
ll bit(ll x)
{
    return ((int)log2(x) + 1);
}
using vec = vector<ll>;
using pii = pair<ll, ll>;
using mapi = map<ll, ll>;
using si = set<ll>;

inline int nxt()
{
    int x;
    cin >> x;
    return x;
}
ll dp[5005][5005];
unordered_map<ll, ll> mp;
/*--------------------------------------------------------------------------------------------------------------*/
ll ff(ll ind, ll steps, vec &v,ll x)
{
    if (ind == x)
    {
        return 0;
    }
    if (dp[ind][steps] != -1)
    {
        return dp[ind][steps];
    }
    ll remain = steps - mp[v[ind]];
    if (remain >= 0)
    {
        return dp[ind][steps] = max(ff(ind + 1, remain, v,x) + 1, ff(ind + 1, steps + 1, v,x));
    }
    else
    {
        return dp[ind][steps] = ff(ind + 1, steps + 1, v,x);
    }
}
void solve()
{
    mp.clear();
    ll n = nxt();
    ll a[n];
    si aa;
    vec v;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
        aa.insert(a[i]);
    }
    for (auto i : aa){
        v.push_back(i);
    }
    for (ll i = 0; i < n+2; i++)
    {
        for (ll j = 0; j < n+2; j++)
        {
            dp[i][j] = -1;
        }
        
    }
    int x = v.size();
    cout << v.size() - ff(0, 0, v,x) << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}