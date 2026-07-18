// Author: Saurabh
// Problem: Common Divisors
// Contest: CSES - Algoritmit ongelmanratkaisussa
// URL: https://cses.fi/alon/task/1081
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
const int M = 16;

 
 
void solve(){
	int n; cin >> n;
	vector<int> arr(n, 0);
	for(int i=0; i<n; i++) cin >> arr[i];
	
	int maxx = *max_element(arr.begin(), arr.end());
	
	vector<int> freq(maxx+1, 0);
	
	for(int i=0; i<n; i++){
		freq[arr[i]]++;
	}
	
	for(int i=maxx; i>0; i--){
		int  cnt = 0;
		for(int multiple = i; multiple <= maxx; multiple += i){
			cnt += freq[multiple];
			if(cnt >= 2){
				cout << i << endl;
				return;
			}
		}
	}	
	cout << "1\n";
}
 
int32_t main(){
	HEHE;
	int t=1;
	// cin >> t;
	while( t-- ) solve();
	return 0;
}