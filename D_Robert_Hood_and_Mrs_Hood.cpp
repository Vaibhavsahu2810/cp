#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 5;
int t;
int n, a[N], b[N], v, w;
int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= n; i++)
            cin >> b[i];
        sort(a + 1, a + n + 1);
        sort(b + 1, b + n + 1);
        v = 0;
        for (int i = 0; i < n; i++)
        {
            w = 1e9;
            for (int j = 1; j <= n; j++)
                w = min(w, abs(a[j] - b[(j - 1 + i) % n + 1]));
            v = max(v, w);
        }
        cout << v << '\n';
    }
    return 0;
}