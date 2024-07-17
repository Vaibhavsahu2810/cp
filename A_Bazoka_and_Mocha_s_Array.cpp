
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
 
#define FAST_IO             (ios_base:: sync_with_stdio(false),cin.tie(NULL));
 
 
#define ll                  long long
#define ull                 unsigned long long
#define max_3(x,y,z)        max(max(x,y),z)
#define max_4(w,x,y,z)      max(max(x,y),max(w,z))
 
#define c(x)                cout<<x<<endl;
#define c2(x,y)             cout<<x<<" "<<y<<endl;
int vectr;
#define in(a,n)           for(int i=0;i<n;i++) cin>>a[i];
#define out(a,n)          for(int i=0;i<n;i++) cout<<a[i]<<" ";
#define inv(a,n)          for(int i=0;i<n;i++) {cin>>vectr; a.push_back(vectr);}
 
#define ff                  first
#define ss                  second 
#define pb                  push_back
#define all(x)              x.begin(), x.end()
#define sz(x)               (int)(x).size();
 
#define yes                 cout<<"Yes"<<endl;
#define no                  cout<<"No"<<endl;
 
#define PI                  3.141592653589793238
#define MIN                 INT_MIN
#define MAX                 INT_MAX
#define INF                 LONG_LONG_MAX
#define MOD                 1000000007
#define LLM                 1000000000000000007
 
ll setbit(ll x){
    return __builtin_popcountll(x);
}
ll bit(ll x){
    return ((int)log2(x) + 1);
}
using vec = vector<ll>;
using pii=pair<ll,ll>;
using mapi=map<ll,ll>;
using si=set<ll>;
 
inline ll nxt() {
    ll x;
    cin >> x;
    return x;
}
/*--------------------------------------------------------------------------------------------------------------*/
void solve(){
    ll n=0,count=0;
    cin>>n;
    vec v(n);
    in(v,n);
    vec v1,v2;
    ll prev=0,flag=1;
    for (ll i = 0; i < n; i++)
    {
        if(prev <= v[i] && count == 0){
            v1.pb(v[i]);
        }
        else if(prev <= v[i] && count == 1){
            v2.pb(v[i]);
        }
        else if(prev > v[i]){
            count++;
        }
        prev = v[i];
        if(count > 1){
            flag=0;
            break;
        }
    }
    sort(all(v1));
    sort(all(v2));
    if(flag){
        if(count){
            if(v1[0] >= v2[0] && v1[v1.size()-1] >= v2[v2.size()-1]){
                yes;
            }
            else{
                no;
            }
        }
        else{
            yes;
        }
    }
    else{
        no;
    }
    
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
     solve();   
    }
return 0;
}