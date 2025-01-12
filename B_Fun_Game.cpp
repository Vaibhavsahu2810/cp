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
/*--------------------------------------------------------------------------------------------------------------*/
void solve()
{
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


bool isConnected(int start, int end, vector<vector<int>> &adj, vector<bool> &visited) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (int child : adj[node])
        {
            if (!visited[child])
            {
                visited[child] = true;
                q.push(child);
            }
            if (child == end)
                return true;
        }
    }
    return false;
};
double perdis(int x1, int y1, int x2, int y2, int cx, int cy) {
    int A = y2 - y1;
    int B = x1 - x2;
    int C = x2 * y1 - x1 * y2;

    double distance = abs(A * cx + B * cy + C) / sqrt(A * A + B * B);
    return distance;
}
bool canReachCorner(int xCorner, int yCorner, vector<vector<int>> &circles)
{
    int n = circles.size();
    vector<vector<int>> adj(n + 4);

    for (int i = 0; i < n; i++)
    {
        int x = circles[i][0], y = circles[i][1], r = circles[i][2];

        if (perdis(0, 0, 0, yCorner, x, y) <= r) {
            adj[n].push_back(i);
            adj[i].push_back(n);
        }
        if (perdis(xCorner, 0, xCorner, yCorner, x, y) <= r) {
            adj[n + 1].push_back(i);
            adj[i].push_back(n + 1);
        }
        if (perdis(0, 0, xCorner, 0, x, y) <= r) {
            adj[n + 2].push_back(i);
            adj[i].push_back(n + 2);
        }
        if (perdis(0, yCorner, xCorner, yCorner, x, y) <= r) {
            adj[n + 3].push_back(i);
            adj[i].push_back(n + 3);
        }

        for (int j = i + 1; j < n; j++)
        {
            int x2 = circles[j][0], y2 = circles[j][1], r2 = circles[j][2];
            int distSq = (x - x2) * (x - x2) + (y - y2) * (y - y2);
            if (distSq <= (r + r2) * (r + r2))
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    for(int i = 1 ; i < n+4 ; i++){
        cout << i << " : ";
        for(auto x : adj[i]){
            cout << x << " ";
        }
        cout << endl;
    }

    vector<bool> visited(n + 4, false);



    if (isConnected(n, n + 1, adj, visited))
        return false; 
    fill(visited.begin(), visited.end(), false);
    if (isConnected(n + 2, n + 3, adj, visited))
        return false; 
    fill(visited.begin(), visited.end(), false);
    if(isConnected(n, n + 2, adj, visited))
        return false;
    fill(visited.begin(), visited.end(), false);
    if(isConnected(n + 1, n + 3, adj, visited))
        return false;
    

    return true;
}

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        for(auto x : nums){
            mp[x]++;
        }
        priority_queue<pair<int,int>> pq;
        for(auto x : mp){
            pq.push({x.second,x.first});
        }   
        vector<int> res;
        while(k--){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};