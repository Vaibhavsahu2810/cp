
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
class Solution
{
public:
    int minimumCost(int m, int n, vector<int> &hc, vector<int> &vc)
    {
        int minCost = 0;
        int hor= 1, ver=1,x = n+m-2;
        sort(hc.begin(), hc.end(), greater<int>());
        sort(vc.begin(), vc.end(), greater<int>());
        int i=0,j=0;
        while (i+j<x)
        {
            if(j < n-1 && i < m-1){
                if(hc[i] < vc[j]){
                    minCost += vc[j]*hor;
                    j++;
                    ver++;
                }
                else{
                    minCost += hc[i]*ver;
                    i++;
                    hor++;
                }
            }
            else if(i < m-1){
                minCost += hc[i]*ver;
                i++;
                hor++;
            }
            else if(j < n-1){
                minCost += vc[j]*hor;
                j++;
                ver++;
            }
        }
        return minCost;
        
    }
};