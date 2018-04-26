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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

bool isPalindrome(int n) {
	vi digit;
	while(n>0){
		int bil = n % 10;
		digit.pb(bil);
		n/=10;
	}
	int banyakDigit = digit.size();
	for(int i=0;i<banyakDigit/2;i++) {
		if(digit[i] != digit[banyakDigit-i-1]){return false;}
	}
	return true;
}

int main(){
	int i,j,n;
	int tc;
	// printf("%d\n",isPalindrome(10001));
	vi listAns;
	for(i=100;i<=999;i++){
		for(j=i;j<=999;j++){
			int ans = i*j;
			if(isPalindrome(ans)){
				listAns.pb(ans);
				
			}
		}
	}

	sort(listAns.begin(), listAns.end());
	// printf("%d\n",listAns[listAns.size() - 1]);

	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		int idx = lower_bound(listAns.begin(), listAns.end(), n) - listAns.begin();
		// printf("idx: %d listAns[%d]: %d\n",idx,idx,listAns[idx]);
		printf("%d\n",listAns[idx-1]);
	}
	return 0;
};