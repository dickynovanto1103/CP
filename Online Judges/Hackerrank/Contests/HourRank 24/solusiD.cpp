/**
 *    author:  tourist
 *    created: 02.11.2017 18:09:45       
**/
#include <bits/stdc++.h>

using namespace std;

string to_string(string s) {
  return '"' + s + '"';
}

string to_string(const char* s) {
  return to_string((string) s);
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

template <typename T>
class fenwick {
  public:
  vector<T> fenw;
  int n;

  fenwick(int n) : n (n) {
    fenw.resize(n);
  }

  void modify(int x, T v) {
    while (x < n) {
      fenw[x] += v;
      x |= (x + 1);
    }
  }

  T get(int x) {
    T v{};
    while (x >= 0) {
      v += fenw[x];
      x = (x & (x + 1)) - 1;
    }
    return v;
  }
};

const long long inf = (long long) 1e11;

const int MAX = 200010;

int main() {
  int n, m, x;
  long long k;
  scanf("%d %d %d %lld", &n, &m, &x, &k);
  vector<int> a(n), b(m);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < m; i++) {
    scanf("%d", &b[i]);
  }
  long long low = -inf, high = inf;
  while (low < high) {
    long long mid = low + ((high - low) >> 1);
    long long res = 0;
    fenwick<int> fenw(2 * MAX);
    int j = m;
    for (int i = n - 1; i >= 0; i--) {
      debug("before", i, res);
      while (j - 1 >= i + x) {
        j--;
        fenw.modify(b[j] + MAX, 1);
        debug(i, j);
      }
      if (a[i] > 0) {
        // a[i] * b[j] <= mid
        long long bound = mid / a[i];
        while (a[i] * bound > mid) {
          bound--;
        }
        while (a[i] * (bound + 1) <= mid) {
          bound++;
        }
        if (bound > MAX - 1) {
          bound = MAX - 1;
        }
        debug(i, bound);
        if (bound >= -MAX) {
          res += fenw.get(bound + MAX);
        }
        continue;
      }
      if (a[i] < 0) {
        // a[i] * b[j] <= mid
        long long bound = mid / a[i];
        debug(a[i], mid, bound);
        while (a[i] * bound > mid) {
          bound++;
        }
        while (a[i] * (bound - 1) <= mid) {
          bound--;
        }
        bound--;
        if (bound < -MAX) {
          bound = -MAX;
        }
        debug(i, bound);
        if (bound < MAX) {
          res += fenw.get(2 * MAX - 1) - fenw.get(bound + MAX);
        }
        continue;
      }
      if (0 <= mid) {
        res += fenw.get(2 * MAX - 1);
      }
    }
    debug(mid, res);
    if (res >= k) {
      high = mid;
    } else {
      low = mid + 1;
    }
  }
  cout << low << endl;
  return 0;
}
