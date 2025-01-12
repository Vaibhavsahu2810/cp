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
const int dir = 4;
const int dx[dir] = {-1, 1, 0, 0};
const int dy[dir] = {0, 0, -1, 1};

struct Node
{
    int x, y, side;
};

bool isValid(int x, int y, int n, int m)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}

int dfs(vector<string> &grid, vector<vector<vector<bool>>> &vis, Node start, int mir)
{
    int n = grid.size(), m = grid[0].size();
    queue<Node> q;
    q.push(start);
    vis[start.x][start.y][start.side] = true;

    int count = 0; 
    while (!q.empty())
    {
        Node curr = q.front();
        q.pop();
        int x = curr.x, y = curr.y, side = curr.side;

        if (grid[x][y] == '/' || grid[x][y] == '\\')
        {
            count++;
        }

        if (grid[x][y] == '/')
        {
            if (side == 0)
                side = 2; 
            else if (side == 1)
                side = 3; 
            else if (side == 2)
                side = 0; 
            else if (side == 3)
                side = 1; 
        }
        else if (grid[x][y] == '\\')
        {
            if (side == 0)
                side = 3; 
            else if (side == 1)
                side = 2; 
            else if (side == 2)
                side = 1; 
            else if (side == 3)
                side = 0; 
        }

        int nx = x + dx[side];
        int ny = y + dy[side];
        if (isValid(nx, ny, n, m) && !vis[nx][ny][side])
        {
            vis[nx][ny][side] = true;
            q.push({nx, ny, side});
        }
    }

    return count == mir; 
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
    }

    int mir = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '/' || grid[i][j] == '\\')
            {
                mir++;
            }
        }
    }

    vector<string> ans;
    vector<vector<vector<bool>>> vis(n, vector<vector<bool>>(m, vector<bool>(4, false)));

    for (int i = 0; i < n; i++)
    {
        if (!vis[i][0][2] && dfs(grid, vis, {i, 0, 2}, mir))
        {
            ans.push_back("W" + to_string(i + 1));
        }
        if (!vis[i][m - 1][3] && dfs(grid, vis, {i, m - 1, 3}, mir))
        {
            ans.push_back("E" + to_string(i + 1));
        }
    }
    for (int j = 0; j < m; j++)
    {
        if (!vis[0][j][0] && dfs(grid, vis, {0, j, 0}, mir))
        {
            ans.push_back("N" + to_string(j + 1));
        }
        if (!vis[n - 1][j][1] && dfs(grid, vis, {n - 1, j, 1}, mir))
        {
            ans.push_back("S" + to_string(j + 1));
        }
    }

    cout << ans.size() << endl;
    for (const string &res : ans)
    {
        cout << res << " ";
    }
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    t=1;
    while (t--)
    {
        solve();
    }
    return 0;
}
class Solution
{
public:
    int numDistinct(string s, string t)
    {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for(int i = 0; i <= n; i++)
        {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s[i - 1] == t[j - 1])
                {
                    dp[i][j] += dp[i - 1][j - 1];
                    dp[i][j] += dp[i][j - 1];
                }
                else
                {
                    dp[i][j] = (dp[i][j - 1]);
                }
            }
        }
        return dp[n][m];
    }
};