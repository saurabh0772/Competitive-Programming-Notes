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
const int M = 20;

// what are coprimes?
// those number from 1 to n, whose gcd with n gives 1 , gcd(i, n) == 1
// Euler totient = phi(n) --> return all the coprimes of n
// Properties : 
// if n == primes : coprimes = n-1;
// if n == power of primes (prime ^ k) : coprimes = (prime ^ k) - (prime^ k-1);
// phi(non primes) = phi(prime) * phi(prime);
// phi(n) = n * (1 - (1/p1)) * (1 - (1/p2)) ...... * (1 - (1/pk))   where p1, p2...pk are the prime factors of the number
// we can stores number of coprimes in the PHI array  


vector<int> phi(M+1, 0);

void precompute(){

    // phi[i] == i means that the number is prime
    iota(phi.begin(), phi.end(), 0);

    for(int i=2; i<=M; i++){
        if(phi[i] == i){
            phi[i] = i-1;
            for(int j=2*i; j<=M; j+=i){
                phi[j] = (phi[j]/i) * (i-1);
            }
        }
    }


}

 
void solve(){
    cout << "Coprimes of " << M << " numbers are  : " << endl;
		for(int i=0; i<=M; i++){
            cout << i << " : " << phi[i] << endl;
        }
}
 
int32_t main(){
	HEHE;
	int t=1;
	// cin >> t;
    precompute();
	while( t-- ) solve();
	return 0;
}