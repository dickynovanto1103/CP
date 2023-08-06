//https://codeforces.com/problemset/problem/476/B
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

int main(){
	string s1, s2;
	while(cin>>s1>>s2){
		int plus = 0, minus = 0;
		for(char c: s1){
			if(c == '+'){plus++;}
			else{minus++;}
		}

		int secPlus = 0, secMinus = 0, q = 0;
		for(char c: s2) {
			if(c == '+'){secPlus++;}
			else if(c=='-'){secMinus++;}
			else{q++;}
		}

		if(secPlus > plus || secMinus > minus) {
			double ans = 0;
			printf("%.11lf\n", ans);
		}else{

			int diffPlus = plus - secPlus;
			int diffMinus = minus - secMinus;

			int cnt = 0;

			for(int i=0;i<(1<<q);i++){
				int satu = 0;
				int dua = 0;
				for(int j=0;j<q;j++){
					if((1<<j) & i) {
						satu++;
					}else{
						dua++;
					}
				}

				if(satu == diffPlus && dua == diffMinus) {
					cnt++;
				}
			}

			printf("%.11lf\n", (double)cnt/(1<<q));
		}
	}
	
	
	return 0;
};