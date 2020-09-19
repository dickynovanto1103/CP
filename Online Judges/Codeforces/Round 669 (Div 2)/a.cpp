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
	int tc,n,i,j;
	scanf("%d",&tc);
	int a[1001];
	while(tc--){
		scanf("%d",&n);
		int cnt1 = 0, cnt0 = 0;
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
			if(a[i]){cnt1++;}
			else{cnt0++;}
		}
		if(cnt1 <= cnt0) {
			printf("%d\n",cnt0);
			for(i=0;i<cnt0;i++){
				if(i){printf(" ");}
				printf("0");
			}
			printf("\n");
		}else if(cnt1 > cnt0) {
			if(cnt1 % 2 == 1){
				cnt1--;
			}
			printf("%d\n",cnt1);
			for(i=0;i<cnt1;i++){
				if(i){printf(" ");}	
				printf("1");
			}
			printf("\n");
		}
	}
	
	return 0;
};