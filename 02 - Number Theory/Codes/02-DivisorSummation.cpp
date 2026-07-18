// Author: Saurabh
// Problem: Divisor Summation
// Contest: SPOJ - Tutorial
// URL: https://www.spoj.com/problems/DIVSUM/
// Memory Limit: 1536 MB
// Time Limit: 3000 ms
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
const int M = 5 * 1e6;
vector<int> sieve(M+1, 0);

// 1. Create a sieve storing the Smallest Prime Factor (SPF) for every number.
// 2. Prime factorize n using the SPF array and find the exponent (alpha) of each prime.
// 3. For each prime p^alpha, compute its divisor-sum contribution using the GP formula:
//      1 + p + p² + ... + p^alpha = (p^(alpha+1) - 1) / (p - 1)
// 4. Multiply the contribution of all prime factors to get the sum of all divisors,
//    then subtract n to obtain the sum of proper divisors.

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
		int res = 1, t = n;
		
		while(sieve[n] != 0){
			int alpha = 1, spf = sieve[n];
			
			while(n % spf == 0){
				alpha++;
				n /= spf;
			}
			
			res *= (pow(spf, alpha) - 1)/ (spf - 1);
		}
		
		cout << res - t << endl;
}
 
int32_t main(){
	HEHE;
	int t=1;
	cin >> t;
	precompute();
	while( t-- ) solve();
	return 0;
}