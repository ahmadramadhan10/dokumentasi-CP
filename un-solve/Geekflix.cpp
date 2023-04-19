#include<bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const long long mod = 998244353;

long long n, m , a[209], b[209], val[209][1009], dp[209][1009];
long long cnt[209];

// O(N^2 * M)

long long DP(int now, int k){
	if(k > m) return 0;
	if(now > n) now = 1;
	if(now < 1) now = n;
	if(dp[now][k] != -1) return dp[now][k];
	
	++cnt[now];
	//cout << cnt[now] << ' ' << now << '\n';
	long long best = DP(now + 1, k + 1); //next
	best = max(best, DP(now, k + 1)); // stay
	best = max(best, DP(now - 1, k + 1)); // prev
	best += max(a[now] - ((cnt[now] - 1) * b[now]) , 0LL);
	--cnt[now];
	return dp[now][k] = best;
	
}
void solve(int tc) {
	memset(dp,-1,sizeof dp);
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	for(int i = 1; i <= n; ++i) cin >> b[i];
	cout << DP(1,1) << '\n';	
	//	/*
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; j++)
			cout << dp[i][j] << " ";
		cout << '\n';
	}
	//	*/
}

int main() {
  ios_base::sync_with_stdio(0);

  int TT = 1;
  //cin >> TT;
  for(int tc = 1; tc <= TT; ++tc) {
    solve(tc);
  }

  return 0;
}
