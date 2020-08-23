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
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int tc,i,j,n,a,b,c;
	scanf("%d",&tc);
	int ar[101];
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ",tt);
		scanf("%d %d %d %d",&n,&a,&b,&c);

		if(n == 1){printf("1\n"); continue;}
		if(n == 2) {
			if(c == 2){printf("1 1\n");}
			else if(c==1){
				if(a == 1 && b == 1){printf("IMPOSSIBLE\n");}
				if(a == 1 && b == 2){printf("2 1\n");}
				else if(a == 2 && b == 1){printf("1 2\n");}
				else if(a == 2 && b == 2){printf("IMPOSSIBLE\n");}
			}
			continue;
		}

		for(i=0;i<n;i++){ar[i] = 1;}
		bool samaA = false, samaB = false;
		if(a == c) {
			ar[0] = n;
			a--; b--;
			samaA = true;
		}
		if(b == c){
			ar[n-1] = n;
			b--;
			samaB = true;
		}
		if(c < 0){printf("IMPOSSIBLE\n"); return 0;}
		
		int banyakA = (samaA ? a : (a - c));
		int banyakB = (samaB ? b : (b - c));
		if(samaA || samaB){
			c = 0;
		}
		printf("banyakA: %d banyakB: %d\n",banyakA, banyakB);
		for(i=(samaA ? 1 : 0);i<n;i++){
			if(banyakA <= 0){
				// printf("halo i:%d a[i]: %d\n", i, ar[i]);
				break;
			}
			if(samaA) {
				ar[i] = n;	
				c = 0;
			}else{
				ar[i] = n-1;
				printf("ar[%d]: %d\n",i, ar[i]);
			}
			
			banyakA--;
		}
		for(i=(samaB ? n-2 : n-1);i>=0;i--){
			if(banyakB <= 0){
				break;
			}
			if(samaB){
				ar[i] = n;
				c = 0;
			}else{
				ar[i] = n-1;
			}
			
			banyakB--;
		}
		int cnt1 = 0;
		for(i=0;i<n;i++){
			if(ar[i] == 1){
				cnt1++;
			} 
		}
		if(cnt1 < c){
			printf("IMPOSSIBLE\n");
		}else{
			for(i=0;i<n;i++){
				if(ar[i] == 1){
					if(c <= 0){break;}
					ar[i] = n;
					// printf("i: %d\n",i);
					c--;
				}
			}
			for(i=0;i<n;i++){
				if(i){printf(" ");}
				printf("%d",ar[i]);
			}
			printf("\n");
		}
	}
	
	return 0;
};