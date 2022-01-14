/*
ID: dickyno1
LANG: C++14
TASK: crypt1
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

int a[10], n;
map<int, bool> mapper;

bool isGood(int num, int expectedDigit) {
	int cntDigit = 0;
	while(num) {
		int digit = num % 10;
		if(!mapper[digit]) {
			return false;
		}
		num /= 10;
		cntDigit++;
	}
	if(expectedDigit == -1){
		return true;
	}
	return cntDigit == expectedDigit;
}

int main(){
	freopen("crypt1.in", "r", stdin);
	freopen("crypt1.out", "w", stdout);

	int i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		mapper[a[i]] = true;
	}

	int cnt = 0;

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				int num1 = a[i] * 100 + a[j] * 10 + a[k];

				for(int tt=0;tt<n;tt++){
					for(int vv=0;vv<n;vv++){
						int num2 = a[tt] * 10 + a[vv];
						if(isGood(a[tt] * num1, 3) && isGood(a[vv] * num1, 3) && isGood(num1 * num2, -1)) {
							// printf("num1: %d num2: %d\n", num1, num2);
							cnt++;
						}
					}
				}
			}
		}
	}

	printf("%d\n", cnt);
	return 0;
};