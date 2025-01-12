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

#define debug(x...)                          \
    {                                        \
        cout << "(" << #x << ")" << " = ( "; \
        Print(x);                            \
    }
template <typename T1>
void Print(T1 t1)
{
    cout << t1 << " )" << endl;
}
template <typename T1, typename... T2>
void Print(T1 t1, T2... t2)
{
    cout << t1 << " , ";
    Print(t2...);
}
#define FAST_IO (ios_base::sync_with_stdio(false), cin.tie(NULL));
#define ll long long
#define ull unsigned long long
#define max_3(x, y, z) max(max(x, y), z)
#define max_4(w, x, y, z) max(max(x, y), max(w, z))
#define c(x) cout << x << endl;
#define c2(x, y) cout << x << " " << y << endl;
#define in(a, n)                \
    for (int i = 0; i < n; i++) \
        cin >> a[i];
#define out(a, n)               \
    for (int i = 0; i < n; i++) \
        cout << a[i] << " ";
#define f(i, n) for (int i = 0; i < n; i++)
#define fr(i, n) for (int i = n - 1; i >= 0; i--)
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
ll factorial(ll n)
{
    if (n == 0)
        return 1;
    ll res = 1;
    for (ll i = 2; i <= n; i++)
        res = res * i;
    return res;
}
ll nPr(ll n, ll r)
{
    return factorial(n) / factorial(n - r);
}
ll nCr(ll n, ll r)
{
    return factorial(n) / (factorial(r) * factorial(n - r));
}
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b)
{
    return (a * b) / gcd(a, b);
}
ull mypow(ull a, ull b)
{
    ull ans = 1;
    a %= MOD;
    while (b)
    {
        if (b & 1)
            ans = (ans * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ans;
}
bool isPrime(ll n)
{
    if (n <= 1)
        return false;
    for (ll i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}
int binarySearch(int arr[], int l, int r, int x)
{
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (arr[m] == x)
            return m;
        if (arr[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}
int iseven(int n)
{
    return !(n & 1);
}
#define $ 1000000
vector<int> prime(1000000, 1);
void blackbox()
{
    prime[0] = prime[1] = 0;
    for (ll i = 2; i * i < $; i++)
    {
        if (prime[i] == 1)
        {
            for (ll j = 2 * i; j < $; j += i)
            {
                prime[j] = 0;
            }
        }
    }
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
ll sqrrt(ll x)
{
    long long lo = 0, hi = 2e9, mid;
    while (hi - lo > 1)
    {
        mid = (hi + lo) / 2;
        if (mid * mid <= x)
            lo = mid;
        else
            hi = mid;
    }
    return lo;
}
/*--------------------------------------------------------------------------------------------------------------*/

void solve()
{
    ll n;
    cin >> n;
    vec a(n);
    in(a, n);
    vec hash(n + 1, 0);
    for (ll i = 1; i <= n; i++)
    {
        hash[i] = hash[i - 1] + a[i - 1];
    }
    set<ll> s;
    ll ans = 0, cnt = 0;
    for (ll i = 1; i <= n; i++)
    {
        if (hash[i] == 0 && cnt == 0)
        {
            ans += 1;
            cnt++;
        }
        if (s.find(hash[i]) == s.end())
        {
            s.insert(hash[i]);
        }
        else
        {
            ans += 1;
            cnt++;
            s.clear();
        }
        // cout << hash[i] << " ";
    }
    //  cout << endl;
    cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll tt;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}

class Solution
{
public:
    int check(string s, int i, int j, vector<vector<int>> &dp, vector<vector<bool>> &isPalindrome)
    {
        if (i >= j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        
        if (isPalindrome[i][j])
            return 0;
        int ans = INT_MAX;
        for (int k = i; k < j; k++)
        {
            int temp = check(s, i, k,dp,isPalindrome) + check(s, k + 1, j,dp,isPalindrome) + 1;
            ans = min(ans, temp);
        }
        return dp[i][j] = ans;
    }
    int minCut(string s)
    {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        vector<vector<bool>> isPalindrome(n, vector<bool>(n, true));
        for (int i = n - 1; i >= 0; --i)
        {
            for (int end = i + 1; end < n; ++end)
            {
                isPalindrome[i][end] = (s[i] == s[end]) && isPalindrome[i + 1][end - 1];
            }
        }
        vector<int> cuts(n);
        for (int i = 0; i < n; ++i)
        {
            cuts[i] = i;
        }

        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j <= i; ++j)
            {
                if (isPalindrome[j][i])
                {
                    cuts[i] = (j == 0) ? 0 : min(cuts[i], 1 + cuts[j - 1]);
                }
            }
        }
        return cuts[n - 1];
    }
};

class Solution
{
public:
    int maxCoins(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> arr(n + 2);
        arr[0] = arr[n + 1] = 1;
        for (int i = 1; i <= n; i++)
        {
            arr[i] = nums[i - 1];
        }
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        for (int len = 1; len <= n; len++)
        {
            for (int i = 1; i <= n - len + 1; i++)
            {
                int j = i + len - 1;
                for (int k = i; k <= j; k++)
                {
                    dp[i][j] = max(dp[i][j], dp[i][k - 1] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j + 1]);
                }
            }
        }
        return dp[1][n];
    }
};

class Solution
{
public:
    vector<int> leftmostBuildingQueries(vector<int> &heights, vector<vector<int>> &queries)
    {
        ll n = heights.size();
        vector<pair<ll, ll>> pq;
        vector<int> ans(queries.size(), -1);
        for (int i = 0; i < queries.size(); i++)
        {
            int l = queries[i][0];
            int r = queries[i][1];
            if(l > r){
                swap(l,r);
            }
            if(height[r] > height[l]){
                ans[i] = r;
            }
            else{
                pq.push_back({heights[l], i});
            }
        }
        stack<int> st;
        for (int i = n-1; i >= 0; i--)
        {
           pair<ll,ll> p = pq.top();
           if(p.first == i){
               
           }
           else{
               
           }
        }
    }
};