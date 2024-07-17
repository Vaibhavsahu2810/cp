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
    ll n = nxt();
    vector<vector<ll> > a(3,vector<ll>(n));
    ll sum = 0;
    for (int i = 0; i < 3; i++){
        sum=0;
        for (int j = 0; j < n; j++){
            cin >> a[i][j];
            sum += a[i][j];
        }
    }
    ll ans = (sum + 2) / 3;
    bool flag = true;
    vector<vector<ll> > fin(3,vector<ll>(2));
    vec test;
    for (int i = 0; i < 3; i++){
        test.pb(i);
    }
    do
    {
        unordered_map<int,int> mp;
        ll i = 0, k = 0,count=0;
        for (ll j = 0; j < 3; j++){
            while(i < n){
                count += a[test[j]][i];
                if (count >= ans){
                    mp[test[j]] = 1;
                    count = 0;
                    fin[test[j]][0] = k+1;
                    fin[test[j]][1] = i+1;
                    i++;
                    break;
                }
                i++;
            }
            k = i;
            count=0;
        }
        flag = true;
        for (ll i=0 ; i<3;i++){
            if (mp[i] == 0){
                flag = false;
            }
        }
        if (flag){
            break;
        }
    }
    while (next_permutation(test.begin(),test.end()));
    if(flag){
        for (ll i = 0; i < 3; i++){
            cout << fin[i][0] << " " << fin[i][1] << " ";
        }
        cout<<endl;
    }
    else{
        cout << -1 << endl;
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