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

struct pasangan{
	int a,t, idx;
};

const int maxn = 2e5 + 10;

bool cmp(pasangan a, pasangan b){
	return a.t<b.t;
}

int main(){
	int n,t;
	int i,j,k;
	vector<pasangan> pas;
	scanf("%d %d",&n,&t);
	for(i=0;i<n;i++){
		int a,waktu;
		scanf("%d %d",&a,&waktu);
		if(waktu>t){continue;}
		pasangan b;
		b.a = a;
		b.t = waktu;
		b.idx = i+1;
		pas.pb(b);
	}

	sort(pas.begin(),pas.end(),cmp);

	vi listIdxJawab;
	if(pas.empty()){printf("0\n0\n\n"); return 0;}
	//binser
	int kiri = 1, kanan = n, mid;
	int ans;
	while(kiri<=kanan){
		mid = (kiri+kanan)/2;
		int batasWaktu = t;
		int cnt = 0;
		vi listIdx;
		for(i=0;i<pas.size();i++){
			int batas = pas[i].a;
			int time = pas[i].t;
			int idx = pas[i].idx;

			if(batas>=mid){
				if((batasWaktu-time)>=0){
					batasWaktu-=time;
					cnt++;	
					listIdx.pb(idx);
					if(cnt==mid){break;}
				}
			}

		}
		if(cnt==mid){
			ans = mid;
			listIdxJawab = listIdx;
			kiri = mid+1;
		}else{
			kanan = mid-1;
		}
	}
	printf("%d\n%d\n",ans,ans);
	for(i=0;i<ans;i++){
		if(i){printf(" ");}
		printf("%d",listIdxJawab[i]);
	}
	printf("\n");
	return 0;
};