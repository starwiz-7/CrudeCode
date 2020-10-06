#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007
#define f(i, a, b) for (long long i = a; i < b; i++)
#define rep(i, a, b) for (long long i = a; i <= b; i++)
#define fm(i, a, b) for (long long i = a; i > b; i--)
#define repm(i, a, b) for (long long i = a; i >= b; i--)
#define vi vector<int>
#define vl vector<long long>
#define vs vector<string>
#define pqmaxi priority_queue<int>
#define pqmaxl priority_queue<ll>
#define pqmini priority_queue<int, vi, greater<int>>
#define pqminl priority_queue<ll, vl, greater<ll>>
#define all(x) x.begin(), x.end()
#define test     \
    ll test;     \
    cin >> test; \
    while (test--)
#define pb(i) push_back(i)
#define mp(i, j) make_pair(i, j)
#define fast                     \
    ios::sync_with_stdio(false); \
    cin.tie(NULL)
 
int main(){
    fast;
    ll x,n; cin >> x >> n;
    set<ll> s;
    multiset<ll> diff;
    s.insert(0);
    s.insert(x);
    diff.insert(x);
    f(i,0,n){
        ll val; cin >> val;
 
        auto itr=s.lower_bound(val);
        ll d= *itr  -  *(prev(itr));
 
        diff.erase( diff.find(d) );
        diff.insert( val-*(prev(itr)) );
        diff.insert( *itr -val );
 
        s.insert(val);
        auto last= prev(diff.end());
        cout << *last << "\n";
    }
}
