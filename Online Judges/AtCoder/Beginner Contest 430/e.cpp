// 10100011010001
// 1000110

/*
void kmpPreprocess() {                           // call this first
  int i = 0, j = -1; b[0] = -1;                  // starting values
  while (i < m) {                                // pre-process P
    while ((j >= 0) && (P[i] != P[j])) j = b[j]; // different, reset j
    ++i; ++j;                                    // same, advance both
    b[i] = j;
  }
}

int kmpSearch() {                               // similar as above
  int freq = 0;
  int i = 0, j = 0;                              // starting values
  while (i < n) {                                // search through T
    while ((j >= 0) && (T[i] != P[j])) j = b[j]; // if different, reset j
    ++i; ++j;                                    // if same, advance both
    if (j == m) {                                // a match is found
      ++freq;
      // printf("P is found at index %d in T\n", i-j);
      j = b[j];                                  // prepare j for the next
    }
  }
  return freq;
}
*/

#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define mp make_pair
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define debug if(true)
typedef long long ll;
// typedef __int128_t lll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 1e6 + 6;

int b[maxn];
string T, P;
int n,m;

void kmpPreprocess() {                           // call this first
  int i = 0, j = -1; b[0] = -1;                  // starting values
  while (i < m) {                                // pre-process P
    while ((j >= 0) && (P[i] != P[j])) j = b[j]; // different, reset j
    ++i; ++j;                                    // same, advance both
    b[i] = j;
  }
}

vi kmpSearch() {                               // similar as above
	vi matches;
  int freq = 0;
  int i = 0, j = 0;                              // starting values
  while (i < n) {                                // search through T
    while ((j >= 0) && (T[i] != P[j])) j = b[j]; // if different, reset j
    ++i; ++j;                                    // if same, advance both
    if (j == m) {                                // a match is found
      ++freq;
      matches.pb(i-j);
      // printf("P is found at index %d in T\n", i-j);
      j = b[j];                                  // prepare j for the next
    }
  }
  return matches;
}

void solve(){
	cin>>T>>P;
	T += T;
	n = T.size();
	m = P.size();
	kmpPreprocess();
	vi matches = kmpSearch();
	if(matches.size() == 0) {
		puts("-1");
	}else{
		printf("%d\n", matches[0]);
	}
}	

int main(){
	int tc = 1;
	scanf("%d",&tc);
	while(tc--){
		solve();
	}

	return 0;
};