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
class Solution
{
    int pr(int count,int i,vector<int> &p)
public:
    int maxProfit(vector<int> &p)
    {
        int n = p.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
        for (int i = n-1; i >= 0; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                for (int k = 1; k < 3; k++)
                {
                    int profit;
                    if(j){
                        profit = max(dp[i+1][0][k] - p[i],dp[i+1][1][k]);
                    }
                    else{
                        profit = max(dp[i+1][0][k],dp[i+1][1][k-1]+p[i]);
                    }
                    dp[i][j][k] = profit;
                }
                
            }
            
        }
        return dp[0][1][2];
    }
};
class Solution
{
public:
    int maxProfit(int k, vector<int> &p)
    {
        int n = p.size();
        vector<vector<int>> dp(n+1,vector<int>(2*k+1,0));
        for (int i = n-1; i >=0; i++)
        {
            for (int j = 0; j < 2*k; j++){
                int profit;
                if(j%2==0){
                    profit = max(dp[i+1][j+1] - p[i],dp[i+1][j]);
                }
                else{
                    profit = max(dp[i+1][j],dp[i+1][j+1]+p[i]);
                }
            }
        }
                
    }
    return dp[0][2*k];
};