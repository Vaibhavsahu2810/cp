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
    ll n,m,k;
    cin>>n>>m>>k;
    ll x;
    cin>>x;
    vec v(x,0);
    for(int i=0;i<x;i++){
        cin>>v[i];
    }
    sort(all(v),greater<int>());
    vec grid;
    for(ll i = 0; i< n;i++){
        ll c = 0;
        for (ll j = 0; j < m; j++)
        {
            ll x = n-1,y=m-1,ver = 0,hor=0;
            c=0;
            ll up = i,dow = x - i,lef = j, rig = y - j;
            if(up == 0 || dow == x){
                c++;
            }
            else{
            if(up < k-1){
                c += up;
            }
            else{
                ver = 1;
                c++;
            }
            
            if(ver){
                c += min(dow,k-1);
            }
            else{
                c++;
            }
            }
            if(lef == 0 || rig == y){
                
            }
            else{
            if(lef < k-1){
                c += lef;
            }
            else{
                hor = 1;
                c++;
            }
            if(hor){
                c += min(rig,k-1);
            }
            else{
                c++;
            }
            }
            grid.push_back(c);
            cout<<c<<" ";
        }
        
        cout<<endl;
    }
    sort(all(grid),greater<int>());
    ll ans = 0;
    for(int i=0;i<x;i++){
        ans += grid[i]*v[i];
    }
    cout<<ans<<endl;
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