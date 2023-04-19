// mp, singkatan dari modpow
ll mp(ll a, ll b) {
  ll res = 1;
  while(b){
    if(b&1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
/*
jangan lupa define long long jadi ll
jangan lupa deklarasi mod, dan nilai mod sesuai dengan soal
*/
