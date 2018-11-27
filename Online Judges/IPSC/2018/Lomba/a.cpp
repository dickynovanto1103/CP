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

int banyakDigit(int n){
	int cnt = 0;
	while(n>0){
		n/=10;
		cnt++;
	}
	return cnt;
}

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	const int maxn = 1010;
	while(tc--){
		int n;
		scanf("%d",&n);
		int a[maxn];
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
			int cntDigit = banyakDigit(a[i]);
			int bil = 1;
			for(j=0;j<(cntDigit-1);j++){
				bil*=10;
			}
			if(i){printf(" ");}
			if(i == (n-1)){
				bil = 1;
			}
			printf("%d",bil);
		}
		printf("\n");
	}
	return 0;
};