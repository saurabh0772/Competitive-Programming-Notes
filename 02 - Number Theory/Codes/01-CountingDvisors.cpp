// Author: Saurabh
// Problem: Counting Divisors
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1713/
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
 
using namespace std;
 
#define int long long
#define srt(a) sort(a.begin(), a.end())
#define all(x) x.begin(), x.end()
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define endl "\n"
#define HEHE ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
typedef long long ll;
const int M = 1e6;
vector<int> sieve(M+1, 0);

void precompute(){
	
	for(int i=2; i<=M; i++){
		if(sieve[i] == 0){
			for(int j=i; j<=M; j+=i){
				if(sieve[j] == 0) sieve[j] = i; 
			}
		}
	}
	
}
 
 
void solve(){
	int n; cin >> n;
	
	int res = 1;
	while(sieve[n] != 0){
		int alpha = 1, spf = sieve[n];
		
		while(n % spf == 0){
			alpha++;
			n /= spf;
		}
		
		res *= alpha;
	}
	
	cout << res << endl;
}
 
int32_t main(){
	HEHE;
	int t=1;
	cin >> t;
	
	precompute();
	
	while( t-- ) solve();
	return 0;
}