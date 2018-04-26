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

int main(){
	int n,i,j;
	scanf("%d",&n);
	int cnt[5];
	memset(cnt,0,sizeof cnt);
	for(i=0;i<n;i++){
		int bil;
		scanf("%d",&bil);
		cnt[bil]++;
	}
	//4 ke 2 dulu biar jd 3
	int ans = 0;
	halo:
	if(cnt[4] >= cnt[2]){
		if(cnt[2]==0){
			cnt[4]--;
			cnt[3]++;
			cnt[2]++;
			cnt[1]--;
			goto halo;
		}else{
			ans+=cnt[2];
			cnt[2] = 0;
			cnt[4]-=cnt[2];	
			goto halo;
		}
		
	}else{
		ans+=cnt[4];
		cnt[2]-=cnt[4];
		cnt[3]+=cnt[4];
		cnt[4] = 0;
		// printf("masuk sini cnt[%d]: %d\n",2,cnt[2]);
	}
	//1 ke 2 biar jd 3
	if(cnt[1] >= cnt[2]){
		ans+=cnt[2];
		
		cnt[1]-=cnt[2];
		cnt[2] = 0;
		// printf("cnt[%d] jd: %d\n",1,cnt[1]);
	}else{
		ans+=cnt[1];
		cnt[2]-=cnt[1];
		cnt[3]+=cnt[1];
		cnt[1] = 0;
	}

	if(cnt[1]>0){
		if(cnt[1] > cnt[3]){printf("-1\n"); return 0;}
		ans+=cnt[1];
	}

	//dari 2 ke 3
	while(cnt[2]>0){
		ans+=2;
		if(cnt[2]==1){
			if(cnt[3]<2){printf("-1\n");}
			else{cnt[2]--; cnt[3]-=2; cnt[4]+=2;}
		}else if(cnt[2]==2){
			cnt[2]-=2;
			cnt[4]++;
		}else{
			cnt[2]-=3;
			cnt[3]+=2;
		}
		
		
	}
	printf("%d\n",ans);
	return 0;
};