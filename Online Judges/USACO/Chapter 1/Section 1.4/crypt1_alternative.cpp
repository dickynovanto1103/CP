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

bool goodDigits[10];

bool isGood(int num, int expectedDigit = -1) {
	int cntDigit = 0;
	while(num) {
		int digit = num % 10;
		if(!goodDigits[digit]) {
			return false;
		}
		num /= 10;
		cntDigit++;
	}
	
	return expectedDigit == -1 || cntDigit == expectedDigit;
}

int main(){
	freopen("crypt1.in", "r", stdin);
	freopen("crypt1.out", "w", stdout);

	memset(goodDigits, false, sizeof goodDigits);
	int i,j;
	int n;
	scanf("%d",&n);
	int bil;
	for(i=0;i<n;i++){
		scanf("%d",&bil);
		goodDigits[bil] = true;
	}

	int cnt = 0;

	for(int i=100;i<1000;i++) {
		for(int j=10;j<100;j++) {
			if(isGood(i, 3) && isGood(j, 2) && isGood(i * j)) {
				int digit1 = j % 10;
				int angkaLain = j / 10;

				int digit2 = angkaLain;
				if(isGood(i * digit1, 3) && isGood(i * digit2, 3)) {
					cnt++;
				}
			}
		}
	}

	printf("%d\n", cnt);
	return 0;
};