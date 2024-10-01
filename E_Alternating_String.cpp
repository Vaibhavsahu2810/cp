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

bool check(const std::vector<int> &arr, int k, int minm)
{
    int c = 1;
    int sum = 0;
    for (int it : arr)
    {
        if (it > minm)
        {
            return false;
        }
        if (sum + it > minm)
        {
            c++;
            sum = it;
        }
        else
        {
            sum += it;
        }
        
        if (c > k)
        {
            
            return false;
        }
        
    }
    return true;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int left = *min_element(arr.begin(), arr.end());
    int right = accumulate(arr.begin(), arr.end(), 0);

    int ans = 0;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
       
        if (check(arr, m, mid))
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    cout << right;
    return 0;
}