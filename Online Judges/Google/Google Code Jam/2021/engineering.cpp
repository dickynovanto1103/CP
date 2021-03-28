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

int minVal[101], maksVal[102];

void computeMinAndMaksVal() {
	minVal[2] = 1; maksVal[2] = 2;
	int selisih = 3;
	for(int i=3;i<=100;i++){
		minVal[i] = i-1;
		maksVal[i] = maksVal[i-1] + selisih;
		selisih++;
	}
}

struct pas{
	int idx, val;
};

bool cmp(pas a, pas b){
	return a.idx < b.idx;
}

int main(){
	int tc,i,j,n,c;
	scanf("%d",&tc);
	computeMinAndMaksVal();
	pas pasangan[101];

	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ",tt);
		scanf("%d %d",&n,&c);
		if(minVal[n] <= c && c <= maksVal[n]) {
			for(i=0;i<n;i++){
				pasangan[i].idx = i;
				pasangan[i].val = -1;
			}
			int sisa = c;
			int allocation[101];
			for(i=0;i<n-1;i++){
				allocation[i] = 1;
				sisa--;
			}
			int maksVal = n;
			for(i=0;i<n-1;i++){
				if(sisa == 0){break;}
				while(allocation[i] < maksVal && sisa > 0) {
					allocation[i]++;
					sisa--;
				}
				maksVal--;
			}
			// for(i=0;i<n-1;i++){
			// 	printf("allocation[%d]: %d\n",i, allocation[i]);
			// }
			int curNum = 1;
			for(i=0;i<n-1;i++){
				int allo = allocation[i];
				pasangan[i+allo-1].val = curNum++;
				reverse(pasangan+i, pasangan + i + allo);
			}
			int cnt = 0;
			for(i=0;i<n;i++){
				if(pasangan[i].val == -1){
					cnt++;
					pasangan[i].val = curNum;
				}
			}
			assert(cnt == 1);
			sort(pasangan, pasangan + n, cmp);
			for(i=0;i<n;i++){
				if(i){printf(" ");}
				printf("%d",pasangan[i].val);
			}
			printf("\n");


		}else{
			printf("IMPOSSIBLE\n");
		}
	}
	
	return 0;
};