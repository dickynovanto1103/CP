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

const int maxn = 12;

ii player[maxn];
ii lain[maxn];
int start[maxn];

int main(){
	int i;
	for(i=0;i<10;i++){
		scanf("%d %d",&player[i].first,&player[i].second);
	}
	for(i=0;i<10;i++){
		scanf("%d %d %d",&lain[i].first,&lain[i].first, &start[i]);
	}
	int iterasi,j;
	ll waktu[11];
	memset(waktu,0,sizeof waktu);
	ll cur = 0;
	for(iterasi=0;iterasi<3;iterasi++) {
		for(j=0;j<10;j++){
			if(cur>waktu[i]) {//proses dulu waktunya sampe mendekati cur
				if(iterasi==0){
					waktu[i] = start[i];	
				}
				if(waktu[i]<cur) {
					waktu[i]+=lain[j].first;
					if(waktu[i]<cur){
						int selisih = cur - waktu[i];
						int totalDipakaiOrangLain = (lain[j].first + lain[j].second);
						int iterasi = selisih/totalDipakaiOrangLain;
						waktu[i]+=(iterasi*totalDipakaiOrangLain);
						if(waktu[i]<cur){
							waktu[i]+=
						}
					}

					
				}
				
			}
		}
	}
	return 0;
};