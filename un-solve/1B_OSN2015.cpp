#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int maxn = 1239;
const long long mod = 1e9 + 7;
const long long inf = 2e9;

string s;
ll n, m, q;
ll grid[maxn][maxn];
ll d1[maxn][maxn], d2[maxn][maxn], d3[maxn][maxn], d4[maxn][maxn];
ll d5[maxn][maxn], d6[maxn][maxn];
bool do1[maxn][maxn], do2[maxn][maxn], do3[maxn][maxn], do4[maxn][maxn];
bool do5[maxn][maxn], do6[maxn][maxn];

int main() {
  cin >> s >> n >> m >> q;
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= m; ++j) {
      cin >> grid[i][j];
    }
  }
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= m; ++j) {
      d1[i][j] = d1[i-1][j] + d1[i][j-1] - d1[i-1][j-1];
      d2[i][j] = d2[i-1][j] + d2[i][j-1] - d2[i-1][j-1];
      d3[i][j] = d3[i-1][j] + d3[i][j-1] - d3[i-1][j-1];
      d4[i][j] = d4[i-1][j] + d4[i][j-1] - d4[i-1][j-1];
      d5[i][j] = d5[i-1][j] + d5[i][j-1] - d5[i-1][j-1];
      d6[i][j] = d6[i-1][j] + d6[i][j-1] - d6[i-1][j-1];
      if(d1[i][j] >= d1[i + 1][j] && d1[i][j] >= d1[i][j + 1] && d1[i][j] >= d1[i-1][j] && d1[i][j] >= d1[i][j-1]) {
        d1[i][j]++;
        do1[i][j] = true;
      }
      if(d2[i][j] >= d2[i + 1][j] && d2[i][j] >= d2[i][j + 1] && d2[i][j] < d2[i-1][j] && d2[i][j] >= d2[i][j-1]){ 
        d2[i][j]++;
        do2[i][j] = true;
      }
      if(d3[i][j] >= d3[i + 1][j] && d3[i][j] >= d3[i][j + 1] && d3[i][j] >= d3[i-1][j] && d3[i][j] < d3[i][j-1]){ 
        d3[i][j]++;
        do3[i][j] = true;
      }
      if(d4[i][j] < d4[i + 1][j] && d4[i][j] >= d4[i][j + 1] && d4[i][j] >= d4[i-1][j] && d4[i][j] >= d4[i][j-1]){ 
        d4[i][j]++;
        do3[i][j] = true;
      }
      if(d5[i][j] >= d5[i + 1][j] && d5[i][j] < d5[i][j + 1] && d5[i][j] >= d5[i-1][j] && d5[i][j] >= d5[i][j-1]){ 
        d5[i][j]++;
        do5[i][j] = true;
      }
      if(d6[i][j] >= d6[i][j + 1] && d6[i][j] >= d6[i][j-1]){ 
        d6[i][j]++;
        do6[i][j] = true;
      }
    }
  }
  while(q--) {
    int a, b, c, d;
    ll tot = 0;
    cin >> a >> b >> c >> d;
    if(a == c) {
      tot = d6[c][d] + d6[a-1][b-1] - d6[a][b-1] - d6[c-1][d];
      if(tot != 0) {
        cout << "Tidak mungkin";
      } else {
        if(do6[a][b]) cout << "Kiri Atas";
        else if(do6[c][d]) cout << "Kanan Bawah";
        else cout << "Tidak Mungkin";
      }
    } else {
      ll t1 = d1[a][b] + d1[c-1][d-1] - d1[a][d-1] - d1[c-1][b];
      ll t2 = d2[a][d-1] + d2[a-1][b] - d2[a][d-1] - d2[a][b];
    }
    cout << '\n';
  }
}
