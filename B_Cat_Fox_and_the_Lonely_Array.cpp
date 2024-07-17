
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
#define nota cout << "NO" << endl;

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

inline ll nxt()
{
    ll x;
    cin >> x;
    return x;
}
void create_bit_vector(vector<int> &bit, int x)
{
    int j = 0;
    while (x > 0)
    {
        if (x % 2)
            bit[j]++;
        x /= 2;
        j++;
    }
}

int bit_sum(vector<int> &bit)
{
    int j = 0;
    int no = 0;
    for (auto it : bit)
    {
        if (it > 0)
            no = no + pow(2, j);
        j++;
    }

    return no;
}

void remove_bits(vector<int> &bit, int x)
{
    int j = 0;

    while (x > 0)
    {
        if (x % 2)
            bit[j]--;
        x /= 2;
        j++;
    }
}

bool f(vector<int> &v, int k)
{
    int n = v.size();
    vector<int> bit(20);

    for (int i = 0; i < k; i++)
    {
        create_bit_vector(bit, v[i]);
    }

    for (int i = 1; i <= n - k; i++)
    {
        int no = bit_sum(bit);

        int x = v[i - 1];
        remove_bits(bit, x);

        x = v[i + k - 1];

        create_bit_vector(bit, x);

        int nof = bit_sum(bit);

        if (nof != no)
            return false;
    }

    return true;
}

void solve()
{
    int n;
    cin >> n;

    vector<int> v(n);
    for (auto &it : v)
        cin >> it;

    int start = 1;
    int end = n;
    int mid = start + (end - start) / 2;
    while (start <= end)
    {

        if (f(v, mid))
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }

    cout << mid << endl;
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