#include<bits/stdc++.h>
using namespace std;
 
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x<<" "; _print(x); cerr << endl;
#else
#define debug(x);
#endif
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key
 
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
 
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
 
#define fast_io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define lli long long int
#define mod 1000000007
#define PB push_back
#define PPB pop_back
#define MP make_pair
#define vi vector<int>
#define vli vector<lli>
#define uos unordered_set<int>
#define min_heap priority_queue<int,vector<int>,greater<int>>
#define max_heap priority_queue<int>
#define pii pair<int,int>
#define F first
#define S second
#define loop(a,b) for(lli i=a;i<=b;i++)
#define endl '\n'
 
int getbestcandidates(map<int,int>& candidates, int v)
{
	auto it = candidates.lower_bound(v);
	if(it == candidates.begin())
		return 0;
	it--;
	return it->second;
}
 
void insert(map<int,int>& candidates, int v, int adv)
{
	if(candidates[v] > adv)
		return;
 
	candidates[v] = adv;
	auto it = candidates.find(v);
	it++;
 
	while(it != candidates.end() && it->second <= adv){
 
		auto temp = it;
		it++;
		candidates.erase(temp);	
	}
}
 
int LIS(vi &v,int n)
{
	int dp[n];
	map<int,int> candidates;
 
	dp[0] = 1;
	candidates[ v[0] ] = dp[0];
 
	for(int i = 1; i<n; i++)
	{
		dp[i] = 1 + getbestcandidates(candidates,v[i]);
		insert(candidates,v[i],dp[i]);
	}
	return *max_element(dp,dp+n);
}
 
void solve()
{
	vi arr;
	int n;
	cin>>n;
	int temp;
 
	while(n--)
	{
		cin>>temp;
		arr.PB(temp);
	}
 
	cout<<LIS(arr,arr.size());
}
 
int main()
{
	fast_io;
 
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
#endif
 
	solve();
 
	return 0;
}