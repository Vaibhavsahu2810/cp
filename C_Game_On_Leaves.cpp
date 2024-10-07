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
    int n,k;
    cin>>n>>k;
    unordered_map<int,int> mp;
    for (ll i = 0; i < n-1; i++)
    {
        int a,b;
        cin>>a>>b;
        mp[a]++;
        mp[b]++;
    }

    if(mp[k] == 1){
        cout<<"Ayush"<<endl;
    }
    else{
        if(mp[k]&1){
            cout<<"Ayush"<<endl;
        }
        else{
            cout<<"Ashish"<<endl;
        }
    }
    
}
signed main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
        solve();
}

class Solution
{
public:
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        vector<int> ans;
        queue<TreeNode *> q;
        q.push(root);
        TreeNode *temp;
        unordered_map<TreeNode *, TreeNode *> parent;
        while (!q.empty())
        {
            TreeNode *temp1 = q.front();
                q.pop();
            if (temp1->left)
            {
                if(temp1 == target){
                    temp = temp1;
                }
                parent[temp1->left] = temp1;
                q.push(temp1->left);
            }
            if (temp1->right)
            {
                if(temp1 == target){
                    temp = temp1;
                }
                parent[temp1->right] = temp1;
                q.push(temp1->right);
            }
        }
        int dist = 0;
        queue<TreeNode *> q1;
        if(!temp){
            return ans;
        }
        q1.push(temp);
        while (!q1.empty())
        {
            int n = q1.size();
            for (int i = 0; i < n; i++)
            {
                TreeNode *temp1 = q1.front();
                q1.pop();
                if (dist == k)
                {
                    ans.push_back(temp1->val);
                }
                if (temp1->left)
                {
                    q1.push(temp1->left);
                }
                if (temp1->right)
                {
                    q1.push(temp1->right);
                }
                if (parent[temp1] && parent[temp1] != temp1)
                {
                    q1.push(parent[temp1]);
                }
            }
            dist++;
            if(dist > k){
                break;
            }
        }
        return ans;
    }
};