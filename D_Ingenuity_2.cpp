
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
/*--------------------------------------------------------------------------------------------------------------*/
void solve()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll nor = 0, sou = 0, eas = 0, we = 0, r = 0, h = 0;
    map<int, pair<int, int> > mp;
    string ans;
    for (ll i = 0; i < n; i++)
    {
        if (s[i] == 'N')
        {
            nor++;
            if (nor & 1)
            {
                ans += 'R';
                mp[1].second++;
                r++;
            }
            else
            {
                ans += 'H';
                mp[2].second++;
                h++;
            }
        }
        else if (s[i] == 'S')
        {
            sou++;
            if (sou & 1)
            {
                ans += 'R';
                mp[1].second--;
                r++;
            }
            else
            {
                ans += 'H';
                mp[2].second--;
                h++;
            }
        }
        else if (s[i] == 'E')
        {
            eas++;
            if (eas & 1)
            {
                ans += 'H';
                mp[2].first++;
                h++;
            }
            else
            {
                ans += 'R';
                mp[1].first++;
                r++;
            }
        }
        else if (s[i] == 'W')
        {
            we++;
            if (we & 1)
            {
                ans += 'H';
                mp[2].first--;
                h++;
            }
            else
            {
                ans += 'R';
                mp[1].first--;
                r++;
            }
        }
    }

    ll a = abs(nor - sou), b = abs(we - eas);
    if (mp[1].first != mp[2].first || mp[1].second != mp[2].second || r == 0 || h == 0)
    {
        no;
    }
    else
    {
        c(ans);
    }
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