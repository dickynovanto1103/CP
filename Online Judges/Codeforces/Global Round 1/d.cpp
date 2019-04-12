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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 1e6 + 6;
int cnt[maxn];
int temp[maxn];

int main(){
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	int bil;
	
	for(i=0;i<n;i++){
		scanf("%d",&bil);
		cnt[bil]++;
		temp[bil]++;
	}
	int ans1 = 0, ans2 = 0;
	for(i=1;i<=m-2;i++){
		int minim = min(cnt[i], min(cnt[i+1], cnt[i+2]));
		ans1 += minim;
		cnt[i] -= minim; cnt[i+1] -= minim; cnt[i+2] -= minim;
	}
	for(i=1;i<=m;i++){cnt[i] = temp[i];}
	for(i=1;i<=m;i++){
		ans1 += cnt[i]/3;
	}
	for(i=m;i>=3;i--){
		int minim = min(cnt[i], min(cnt[i-1], cnt[i-2]));
		ans2 += minim;
		printf("i: %d minim: %d\n",i,minim);
		printf("ans2: %d\n",ans2);
		cnt[i] -= minim; cnt[i-1] -= minim; cnt[i-2] -= minim;	
	}
	for(i=1;i<=m;i++){
		ans2 += cnt[i]/3;
	}

	printf("%d\n",max(ans1, ans2));

	return 0;
};