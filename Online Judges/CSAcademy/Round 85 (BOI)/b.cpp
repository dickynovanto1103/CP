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

int counter[31];
int cur[31];

const int maxn = 1e6 + 6;

int minVal(){
	for(int i=30;i>=1;i--){
		if(cur[i] > counter[i]){return i;}
	}
	return -1;
}

int main(){
	int n,k,i,j;
	scanf("%d %d",&n,&k);
	
	memset(counter, 0, sizeof counter);
	int a[maxn];
	int minim = inf;
	for(i=0;i<n;i++){
		int bil;
		scanf("%d",&bil);
		a[i] = bil;
		counter[bil]++;
		minim = min(minim,bil);
	}

	
	memset(cur, 0, sizeof cur);
	cur[30] = 1;
	int cnt = 1;
	int total = n+k;
	while(cnt<total){
		int idxMin = minVal();
		if(idxMin == -1){break;}
		cnt++;
		cur[idxMin]--;
		cur[idxMin-1]+=2;
		printf("cnt: %d\n",cnt);
		for(i=1;i<=30;i++){
			printf("cur[%d]: %d\n",i,cur[i]);
		}
	}

	for(i=0;i<n;i++){
		if(i){printf(" ");}
		printf("%d",a[i]);;
		cur[a[i]]--;
	}
	for(i=1;i<=30;i++){
		for(j=0;j<cur[i];j++){
			printf(" %d",i);
		}
	}
	printf("\n");
	return 0;
};