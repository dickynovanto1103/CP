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

const int maxn = 101;

bool cmp(ii a, ii b) {
	if(a.first == b.first){
		return a.second > b.second;
	}
	return a.first < b.first;
}

int main(){
	int n,i,j;
	ii a[maxn],b[maxn];
	bool isVisited1[maxn],isVisited2[maxn];
	memset(isVisited1,false,sizeof isVisited1);
	memset(isVisited2,false,sizeof isVisited2);
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d %d",&a[i].first,&a[i].second);
	}
	for(i=0;i<n;i++){
		scanf("%d %d",&b[i].first,&b[i].second);
	}

	sort(a,a+n,cmp);
	sort(b,b+n,cmp);
	// printf("a\n");
	// for(i=0;i<n;i++){
	// 	printf("%d %d\n",a[i].first, a[i].second);
	// }
	// printf("b\n");
	// for(i=0;i<n;i++){
	// 	printf("%d %d\n",b[i].first, b[i].second);
	// }
	int cnt = 0;
	for(i=0;i<n;i++){
		int minSelisihX = inf, minSelisihY = inf, minSelisih = inf;
		int selisihX, selisihY;
		int idxDiambil = -1;
		for(j=0;j<n;j++){
			if(isVisited2[j]){continue;}
			if(a[i].first < b[j].first && a[i].second < b[j].second){
				// cnt++;
				selisihX = b[j].first - a[i].first; selisihY = b[j].second - a[i].second;
				if(minSelisih > selisihX || minSelisih > selisihY){
					minSelisih = min(minSelisih,min(selisihX,selisihY));
					idxDiambil = j;
				}
				// if(minSelisihX > selisihX || minSelisihY > selisihY){
				// 	if(minSelisihX > selisihX){
				// 		minSelisihX = min(minSelisihX, selisihX);	
				// 	}
				// 	if(minSelisihY > selisihY) {
				// 		minSelisihY = min(minSelisihY, selisihY);
				// 	}
					
					
				// 	idxDiambil = j;
				// }
				// isVisited2[j] = true;
				// isVisited1[i] = true;
				// printf("terbentuk pair %d %d dengan %d %d\n",a[i].first,a[i].second,b[j].first,b[j].second);
				// break;
			}
		}
		if(idxDiambil!=-1){
			cnt++;
			// printf("idxDiambil: %d\n",idxDiambil);
			// printf("terbentuk pair %d %d dengan %d %d\n",a[i].first,a[i].second,b[idxDiambil].first,b[idxDiambil].second);
			isVisited2[idxDiambil] = true;
			isVisited1[i] = true;
		}
	}

	printf("%d\n",cnt);
	return 0;
};