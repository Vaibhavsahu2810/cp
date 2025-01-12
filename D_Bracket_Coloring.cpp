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

#include <iomanip>
#define int int64_t
#define vi vector<int>
#define vii vector<pair<int, int>>
#define vs vector<string>
#define vc vector<char>
#define vb vector<bool>
#define pb push_back
#define vvi vector<vector<int>>
#define pii pair<int, int>
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define vin(x, v)     \
    for (auto &x : v) \
        cin >> x;
#define vout(x, v)   \
    for (auto x : v) \
        cout << x << " ";
#define MEM(a, b) memset(a, (b), sizeof(a))
#define forl for (int i = 0; i < n; i++)
#define loop(i, j, k) for (int i = j; i < k; i += 1)
#define rloop(i, j, k) for (int i = j; i >= k; i -= 1)
#define MP make_pair
#define endl "\n"
#define INF (int)1e18
#define EPS 1e-18
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define MODD 998244353
#define isortarr(arr, n) sort(arr, arr + n)
#define dsortarr(arr, n) sort(arr, arr + n, greater<int>())
#define isortvect(v) sort(v.begin(), v.end())
#define dsortvect(v) sort(v.begin(), v.end(), greater<>());
#define isortstrng(str) sort(str.begin(), str.end())
#define dsortstrng(str) sort(str.begin(), str.end(), greater<char>())
#define ltransfr(str) transform(str.begin(), str.end(), str.begin(), ::tolower)
#define utransfr(str) transform(str.begin(), str.end(), str.begin(), ::toupper)
#define ct(x) cout << x
#define cn(x) cin >> x
#define deb(x) cout << #x << " = " << x << endl
#define debb(x, y) cout << #x << " = " << x << " , " << #y << " = " << y << endl
#define cp(t) \
    int t;    \
    cin >> t; \
    while (t--)
// srand(time(0));
// x = rand()%XYZ
//  cout<<fixed<<setprecision(15)<<
using namespace std;
int zero = 0;
int nxtn()
{
    int x;
    cin >> x;
    return x;
}

string nxts()
{
    string x;
    cin >> x;
    return x;
}

void printYesNo(bool f, string s1, string s2)
{
    if (f)
        cout << s1 << endl;
    else
        cout << s2 << endl;
}
bool chk(string str)
{
    stack<char> s;
    for (auto x : str)
    {
        if (x == '(')
        {
            s.push(x);
        }
        else
        {
            if (s.empty())
            {
                return false;
            }
            else
            {
                s.pop();
            }
        }
    }
    return s.empty();
}
signed main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cp(t)
    {
        int n;
        cin >> n;
        string str;
        cin >> str;
        int op = 0, cl = 0;
        for (auto x : str)
        {
            op += (x == '(');
            cl += (x == ')');
        }
        if (op != cl)
        {
            cout << -1 << endl;
        }
        else
        {
            int c = 0, o = 0;
            string tmp = str;
            reverse(tmp.begin(), tmp.end());
            if ((chk(str)) || (chk(tmp)))
            {
                cout << 1 << endl;
                forl
                {
                    cout << 1 << " ";
                }
                cout << endl;
                continue;
            }

            for (int i = 0; i < n / 2; i++)
            {
                if (str[i] == '(')
                    o++;
            }
            for (int i = n / 2; i < n; i++)
            {
                if (str[i] == ')')
                    c++;
            }
            int x = min(o, c);
            o = 0;
            cout << 2 << endl;
            for (int i = 0; i < n / 2; i++)
            {
                if (str[i] == '(')
                {
                    o++;
                    if (o <= x)
                    {
                        cout << 1 << " ";
                    }
                    else
                    {
                        cout << 2 << " ";
                    }
                }
                else
                {
                    cout << 2 << " ";
                }
            }
            for (int i = n / 2; i < n; i++)
            {
                if (str[i] == ')')
                {
                    if (x > 0)
                    {
                        cout << 1 << " ";
                        x--;
                    }
                    else
                    {
                        cout << 2 << " ";
                    }
                }
                else
                {
                    cout << 2 << " ";
                }
            }
            cout << endl;
        }
    }

    return 0;
}