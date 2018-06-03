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

const int maxn = 110;

struct ujian{
	int mulai, akhir, waktuBelajar;
	int idx;
};

bool cmp(ujian a, ujian b) {
	return a.akhir < b.akhir;
}

int main(){
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	int ans[maxn];
	memset(ans,0,sizeof ans);
	ujian a[maxn];
	for(i=0;i<m;i++){
		scanf("%d %d %d",&a[i].mulai,&a[i].akhir,&a[i].waktuBelajar);
		a[i].idx = i+1;
	}
	sort(a,a+m,cmp);

	for(i=0;i<m;i++){
		int akhir = a[i].akhir;
		int mulai = a[i].mulai;
		int idx = a[i].idx;
		ans[akhir] = m+1;
		int waktuBelajar = a[i].waktuBelajar;
		int cnt = 0;
		for(j=mulai;j<akhir;j++) {
			if(ans[j] == 0){
				ans[j] = idx;
				cnt++;
				if(cnt==waktuBelajar){break;}
			}
		}
		if(cnt<waktuBelajar) {
			printf("-1\n"); return 0;
		}
	}

	for(i=1;i<=n;i++) {
		if(i>1){printf(" ");}
		printf("%d",ans[i]);
	}
	printf("\n");
	return 0;
};