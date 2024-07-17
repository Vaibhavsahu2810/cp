
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
#include <numeric>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif

using namespace std;

#define FAST_IO (ios_base::sync_with_stdio(false), cin.tie(NULL));

#define ll long long
#define ull unsigned long long
#define endl "\n"
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

inline ll nxt()
{
    ll x;
    cin >> x;
    return x;
}
bool check(vector<int> &v)
{
    int i, l = v.size();
    for (i = 0; i < l - 1; i++)
    {
        if (v[i] > v[i + 1])
            return false;
    }
    return true;
}
/*--------------------------------------------------------------------------------------------------------------*/
void solve()
{
    int n;
    cin >> n;
    int arr[n];
    vector<int> brr(n - 1);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    for (int i = 0; i < n - 1; ++i)
        brr[i] = __gcd(arr[i], arr[i + 1]);
    int ind = -1;
    for (int i = 0; i < n - 2; ++i)
    {
        if (brr[i] > brr[i + 1])
        {
            ind = i;
            break;
        }
    }
    if (ind == -1)
    {
        cout << "YES\n";
        return;
    }
    vector<int> v1, v2, v3;
    for (int i = 0; i < n; ++i)
    {
        if (i != ind + 1)
            v1.push_back(arr[i]);
        if (i != ind + 2)
            v2.push_back(arr[i]);
        if (i != ind)
            v3.push_back(arr[i]);
    }
    vector<int> l1(v1.size() - 1), l2(v2.size() - 1), l3(v3.size() - 1);
    for (int i = 0; i < v1.size() - 1; ++i)
        l1[i] = __gcd(v1[i], v1[i + 1]);
    for (int i = 0; i < v2.size() - 1; ++i)
        l2[i] = __gcd(v2[i], v2[i + 1]);
    for (int i = 0; i < v3.size() - 1; ++i)
        l3[i] = __gcd(v3[i], v3[i + 1]);

    if (!check(l1) && !check(l2) && !check(l3))
        cout << "NO\n";
    else
        cout << "YES\n";
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