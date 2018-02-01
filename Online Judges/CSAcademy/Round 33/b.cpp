#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

struct pas{
	int idx,nilai;
};

bool acompare(pas a, pas b){return a.nilai > b.nilai;}
bool bcompare(pas a, pas b){return a.idx < b.idx;}


int main() {
	int n,a[110][110],i,j,k,l;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
		sort(a[i],a[i]+n);
	}
	pas pasangan[110];
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			pasangan[i].idx = i;
			pasangan[j].idx = j;
			int minim = inf,maks = -1;
			for(k=0;k<n;k++){
				int bil = a[i][k];
				for(l=0;l<n;l++){
					if(bil==a[j][l]){minim = min(minim,bil); maks = max(maks,bil); break;}
				}

			}
			//printf("i: %d j: %d minim: %d maks: %d\n",i,j,minim,maks);
			int cnt1 = 0, cnt2 = 0;
			for(k=0;k<n;k++){
				if(a[i][k]<minim || a[i][k]>maks){cnt1++;}
				if(a[j][k]<minim || a[j][k]>maks){cnt2++;}
			}
			if(cnt1>cnt2){pasangan[i].nilai+=2;}
			else if(cnt1==cnt2){pasangan[i].nilai++; pasangan[j].nilai++;}
			else{pasangan[j].nilai+=2;}
			//printf("player %d dan %d nilai jd: %d %d\n",i,j,pasangan[i].nilai,pasangan[j].nilai);
		}

	}
	sort(pasangan,pasangan+n,acompare);
	int idx = 0, curnilai = pasangan[0].nilai;
	for(i=0;i<n;i++){
		if(curnilai > pasangan[i].nilai){sort(pasangan+idx,pasangan+i,bcompare); idx = i; curnilai = pasangan[i].nilai;}
	}
	sort(pasangan+idx,pasangan+n,bcompare);
	for(i=0;i<n;i++){
		printf("%d\n",pasangan[i].idx+1);
	}
	return 0;
}