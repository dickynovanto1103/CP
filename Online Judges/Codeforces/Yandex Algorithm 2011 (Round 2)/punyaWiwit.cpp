#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+ 5, M = 1e6+6;

long long ans[N];
int k[M], l[N], r[N], id[N], a[N], s, now;

void add(int v) {
  ans[now] += 1LL*(2*k[v]+1)*v;
  k[v]++;
}

void del(int v) {
  ans[now] -= 1LL*(2*k[v]-1)*v;
  k[v]--;
}

int main () {
  int n, t;
  scanf("%d%d", &n, &t);
  for(int i = 0; i<n; i++)
    scanf("%d", a+i);
  for(int i = 0; i<t; i++)
    scanf("%d%d", l+i, r+i),l[i]--, r[i]--, id[i] = i;
  s = sqrt(n);
  sort(id, id+t, [](const int &a, const int &b) {if(l[a]/s != l[b]/s) return l[a]/s < l[b]/s; return r[a] < r[b]; });
  //printf("test\n");
  int cur_l, cur_r;
  cur_l = cur_r = l[id[0]];
  now = id[0];
  ans[now] = 0;
  add(a[cur_l]);
  for(int i = 0; i<t; i++) {
    now = id[i];
    if(i)
      ans[now] = ans[id[i-1]];
    while(cur_r < r[now]) add(a[++cur_r]);
    while(cur_l > l[now]) add(a[--cur_l]);
    while(cur_r > r[now]) del(a[cur_r--]);
    while(cur_l < l[now]) del(a[cur_l++]);
  }
  for(int i = 0; i<t; i++)
    printf("%I64d\n", ans[i]);
  return 0;
}