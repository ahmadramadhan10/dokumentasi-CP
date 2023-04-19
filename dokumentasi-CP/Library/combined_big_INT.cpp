const int MAXN = 2e5 + 9;
const long long mod = 1e9 + 7;

long long fc[MAXN], ifc[MAXN];

long long modpow(long long a, long long b){
	long long res = 1;
	while(b > 0){
		if(b & 1) res = res * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return res;
}

long long mod_inv(long long x){
	return modpow(x, mod - 2);
}

void pre_comp(int N) {
	fc[0] = 1;
	for(int i = 1; i <= N; ++i) {
		fc[i] = fc[i - 1] * i % mod;
	}
	ifc[N] = mod_inv(fc[N]);
	for(int i = N - 1; i >= 0; i--){
		ifc[i] = (i + 1) * ifc[i + 1] % mod;
	}
}

long long C(int x, int y){
	return fc[x] * ifc[x-y] % mod * ifc[y] % mod;
}
