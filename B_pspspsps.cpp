#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
//---- Debugger ---- //
#ifndef ONLINE_JUDGE
#define debarr(a, n)            \
    cout << #a << " : ";        \
    for (int i = 0; i < n; i++) \
        cout << a[i] << " ";    \
    cout << endl;
#define debmat(mat, row, col)         \
    cout << #mat << " :\n";           \
    for (int i = 0; i < row; i++)     \
    {                                 \
        for (int j = 0; j < col; j++) \
            cout << mat[i][j] << " "; \
        cout << endl;                 \
    }
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class S, class T>
ostream &operator<<(ostream &os, const pair<S, T> &p) { return os << "(" << p.first << ", " << p.second << ")"; }
template <class T>
ostream &operator<<(ostream &os, const vector<T> &p)
{
    os << "[ ";
    for (auto &it : p)
        os << it << " ";
    return os << "]";
}
template <class T>
ostream &operator<<(ostream &os, const unordered_set<T> &p)
{
    os << "[ ";
    for (auto &it : p)
        os << it << " ";
    return os << "]";
}
template <class S, class T>
ostream &operator<<(ostream &os, const unordered_map<S, T> &p)
{
    os << "[ ";
    for (auto &it : p)
        os << it << " ";
    return os << "]";
}
template <class T>
ostream &operator<<(ostream &os, const set<T> &p)
{
    os << "[ ";
    for (auto &it : p)
        os << it << " ";
    return os << "]";
}
template <class T>
ostream &operator<<(ostream &os, const multiset<T> &p)
{
    os << "[ ";
    for (auto &it : p)
        os << it << " ";
    return os << "]";
}
template <class S, class T>
ostream &operator<<(ostream &os, const map<S, T> &p)
{
    os << "[ ";
    for (auto &it : p)
        os << it << " ";
    return os << "]";
}
template <class T>
void dbs(string str, T t) { cout << str << " : " << t << "\n"; }
template <class T, class... S>
void dbs(string str, T t, S... s)
{
    int idx = str.find(',');
    cout << str.substr(0, idx) << " : " << t << ",";
    dbs(str.substr(idx + 1), s...);
}
template <class T>
void prc(T a, T b)
{
    cout << "[";
    for (T i = a; i != b; ++i)
    {
        if (i != a)
            cout << ", ";
        cout << *i;
    }
    cout << "]\n";
}
//----------------- //
#else
#define pr(...) \
    {           \
    }
#define debarr(a, n) \
    {                \
    }
#define debmat(mat, row, col) \
    {                         \
    }
#endif

#define ll long long
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);
#define nl cout << '\n'
#define ppb pop_back
#define pb push_back
#define rep(i, a, b) for (ll i = a; i < b; i++)
#define repr(i, a, b) for (ll i = a; i >= b; i--)
#define fr for (int i = 0; i < n; i++)
#define all(a) a.begin(), a.end()
#define yes cout << "YES"
#define no cout << "NO"
#define sortt(ar) sort(ar.begin(), ar.end())
#define int long long
#define vi vector<int>
#define vpi vector<pair<int, int>>
#define spi set<pair<int, int>>
#define printans(ans)   \
    for (auto it : ans) \
        cout << it << " ";
#define endl '\n'
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int flag = 0;
    int flg2 = 0;
    int cntp = 0;
    int dt = 0;
    int pp = 0, ss = 0;
    rep(i, 0, n)
    {
        if (s[i] == 's')
        {
            ss++;
            if (flg2 == 1)
            {
                no;
                nl;
                return;
            }
        }
        else if (s[i] == 'p')
        {
            pp++;
            flg2 = 1;
        }
        if (s[i] == '.')
            dt++;
    }
    if (dt == n || pp == n || ss == n || (ss > 0 && dt > 0 && pp == 0) || (pp > 0 && dt > 0 && ss == 0))
    {
        yes;
        nl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 's')
        {
            flag = n - i;
            dt = 0;
        }
        if (s[i] == '.')
            dt++;
        if (s[i] == 'p')
        {
            if (dt + 2 >= flag || dt + 2 >= i + 1)
            {
                yes;
                nl;
                return;
            }
            break;
            dt = 0;
        }
    }
    no;
    nl;
    return;
}
signed main()
{
    fast int t;
    cin >> t;
    for (int i = 0; i < t; i++)
        solve();
}