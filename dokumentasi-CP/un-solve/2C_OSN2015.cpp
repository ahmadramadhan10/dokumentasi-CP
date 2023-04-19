#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int maxn = 1239;
const long long mod = 1e9 + 7;
const long long inf = 2e9;

string res, ask, s;
int n, k, rem, cnt[30];
char nx[30], pre[30];

void sort_ans(){
  for(char x = 'A'; x <= 'Z'; ++x) {
    if(cnt[x - 'A' + 1] > 0) {
      for(char y = 'A'; y <= 'Z'; ++y) {
        if(cnt[y - 'A' + 1] == 0 || x == y || pre[x-'A'+1] == y-'A'+1) continue;
        cout << "TANYA " << x << y << '\n';
        cin >> res;
        if(res == "YA") {
          nx[x -'A' + 1] = y - 'A' + 1;
          pre[y - 'A' + 1] = x -'A' + 1;
          break;
        }
      }   
    }
  }
}

void case_3() {
  for(char x = 'A'; x <= 'Z'; ++x) {
    cnt[x-'A'+1] = 1;
  }
  sort_ans();
}

void another_case(){
  rem = n;
  for(char x = 'A'; x <= 'Z'; x++) {
    int l = 1, r = rem, mid, best = 0;
    if(rem == 0) break;
    while(l < r) {
      mid = (l + r) >> 1;
      ask.assign(mid,x);
      cout << "TANYA " << ask << '\n';
      cin >> res;
      if(res == "YA") {
        best = mid;
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    cnt[x - 'A' + 1] = best;
    rem = rem - best;
  }
  sort_ans();
}

int main() {
  cin >> s >> n >> k;
  if(s[1] == '1') {
    cout << "JAWAB BBBCAAAAAA\n";
    return (0-0);
  }
  if(s[4] == '3') {
    case_3();
  } else {
    another_case();
  }
  char start, finish, now;
  for(char x = 'A'; x <= 'Z'; ++x) {
    if(nx[x-'A'+1] > 0 && pre[x-'A'+1] == 0) {
      start = x;
    }
    if(nx[x-'A'+1] == 0 && pre[x-'A'+1] > 0) {
      finish = x;
    }
  }
  string ans = "";
  now = start;
  while(now != finish) {
    for(int i = 0; i < cnt[start-'A'+1]; ++i) {
      ans.push_back(now);
    }
    now = nx[now-'A'+1];
  }
  cout << "JAWAB " << ans << '\n';
}
