long long C[N + 1][N + 1];

void pre(int N){
	C[0][0] = 1;
	for(int i = 1; i <= N; ++i){
		C[0][i] = C[i][i] = 1;
		for(int j = 1; j < i; ++j){
			C[i][j] = (C[i-1][j] + C[i-1][j-1]) % mod;
		}
	}
}
