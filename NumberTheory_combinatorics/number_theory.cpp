#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define pb push_back


const int N = 1e5 + 5;
const int mod = (int)(1e9) + 7;

ll powmod(ll a, ll b){
	a %= mod;
	ll res = 1;
	while(b){
		if(b & 1)
			res = res * a % mod;
		(a *= a)%=mod;
		b >>= 1;
	}
	return res;
}

ll fact[N+1],invf[N+1];
void factorials(){
	fact[0] = 1;
	for(int i = 1;i <= N;i++)
		fact[i] = fact[i-1] * i % mod;
	invf[N] = powmod(fact[N], mod - 2);
	for(int i = N - 1; i >= 0; i--)
		invf[i] = invf[i+1] * (i + 1) % mod;
}

ll choose(int n, int r){
	if(n < r)
		return 0;
	return fact[n] * invf[r] % mod * invf[n-r] % mod;
}

ll is_prime[N+1];
void sieve(){
	for(int i = 2; i <= N; i++)
		is_prime[i] = 1;
	// 0 1 not prime
	for(int i = 2; i <=N; i++){
		if(is_prime[i]){
			for(int j = 2*i; j <= N; j+=i)
				is_prime[j] = 0;
		}
	}
}

vector<int> dv[N+1];
void divisors(){
	for(int i = 1; i <= N; i++){
		for(int j = i; j <= N; j+=i){
			dv[j].pb(i);
		}
	}
}


vector<int> PHI;
vector<int> phi_1_n(int n){
	vector<int> phi(n+1);
	phi[0]=1;
	phi[1]=1;
	for(int i = 2;i <= n; i++)phi[i] = i;

	for(int i = 2;i <= n; i++){
		if(phi[i] == i){
			for(int j = i; j <= n; j += i)
				phi[j] -= phi[j]/i;
		}
	}

	return phi;
}

int phi(int n){
	int res = n;
	for(int i = 2; 1LL*i*i <= n; i++){
		if(n % i == 0){
			while(n % i == 0)
				n /= i;
			res -= res/i;
		}
	}
	if(n > 1)
		res -= res / n;
	return res;
}

void precalc(){
	factorials();
	sieve();
	divisors();
	PHI = phi_1_n(N);
}

int main(){
	precalc();

}