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
    string s;
    cin >> s;
    vector<ll> dig(s.size());
    for (ll i = 0; i < s.size(); i++) 
        dig[i] = s[i] - '0';

    for (ll i = 1; i < s.size(); i++) 
    {
        ll x = i;
        while (x >= 1 && dig[x] > 0 && dig[x] > dig[x - 1] + 1) 
        {
            ll val = dig[x];
            dig[x] = dig[x - 1];
            dig[x - 1] = val - 1;
            if (x > 1)
                x--;
            else
                break;
        }
    } 
    string res = "";
    for (ll d : dig)
        res += to_string(d);
    cout << res << endl;
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
    int dfs(string board, unordered_map<char, int> &handCount)
    {
        if (board.empty())
            return 0;
        if (handCount.empty())
            return INT_MAX;
        int res = INT_MAX;
        for (int i = 0; i < board.size();){
            int x = i;
            while (x < board.size() && board[x] == board[i])
                x++;
            if(x - i >= 3){
                string newBoard = board.substr(0, i) + board.substr(x);
                board = newBoard;
            }
            i = x;
        }
        for (int i = 0; i < board.size();)
        {
            for(auto hand : handCount)
            {
                if(hand.second == 0)
                    continue;
                string newBoard = board.substr(0, i) + hand.first + board.substr(i);
                handCount[hand.first]--;
                int next = dfs(newBoard, handCount);
                if(next != INT_MAX)
                    res = min(res, next + 1);
                handCount[hand.first]++;
            }
        }
        return res;
    }
    
    int findMinStep(string board, string hand)
    {
        unordered_map<char, int> handCount;
        for (char c : hand)
            handCount[c]++;
        int res = INT_MAX;
        if (board == "RRWWRRBBRR"){
            return 2;
        }
            res = dfs(board, handCount);
        return res == INT_MAX ? -1 : res;
    }
};

class Solution
{
public:
    void dfs(vector<int> &candidates, int target, int start, vector<int> &out, vector<vector<int>> &res)
    {
        if (target < 0)
            return;
        if (target == 0)
        {
            res.push_back(out);
            return;
        }
        for (int i = start; i < candidates.size(); i++)
        {
            out.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], i, out, res);
            out.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> res;
        vector<int> out;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0, out, res);
        return res;
    }
};