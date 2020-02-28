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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

bool vis[60];

int sisaVisited(int n) {
	int cnt = 0;
	for(int i=0;i<n;i++){
		if(!vis[i]){cnt++;}
	}
	return cnt;
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	int a[60], b[60];
	map<ii, int> mapper;
	for(i=0;i<n;i++){
		scanf("%d %d",&a[i],&b[i]);
		mapper[ii(a[i], b[i])] = i;
		// printf("mapping %d %d ke %d\n",a[i], b[i], i);
	}
	int ans = 0;
	
	memset(vis, false, sizeof vis);
	vi listIdx;
	bool valid = true;
	while(valid){
		int maksCnt = 0;

		for(i=0;i<n;i++){
			if(vis[i]){continue;}
			for(j=i+1;j<n;j++){
				if(vis[j]){continue;}
				if((a[i] - a[j]) == 0  || (b[i] - b[j]) == 0){
					continue;
				}else{
					int selisihX = a[j] - a[i], selisihY = b[j] - b[i];
					bool found = true;
					int x = a[j], y = b[j];
					int cnt = 2;
					vi temp;
					temp.pb(i); temp.pb(j);
					// printf("%d %d => %d %d\n",a[i], b[i], a[j], b[j]);
					do{
						int xbaru = x + selisihX, ybaru = y + selisihY;
						// printf("x: %d y: %d xbaru: %d ybaru: %d\n",x,y,xbaru, ybaru);
						if(mapper.find(ii(xbaru, ybaru)) != mapper.end()) {
							int idx = mapper[ii(xbaru, ybaru)];
							// printf("idx: %d\n",idx);
							if(!vis[idx]){x = xbaru; y = ybaru; cnt++; temp.pb(idx);}
							else{found = false;}
						}else{
							found = false;
						}
					}while(found);
					if(maksCnt < cnt){
						maksCnt = cnt;
						listIdx = temp;
						// printf("cnt: %d\n",cnt);
					}
				}
			}
		}
		if(maksCnt == 0){
			int sisa = sisaVisited(n);
			if(sisa == 1){ans++; break;}
			else if(sisa == 0){break;}
			else{
				ans+=sisa; break;
			}
		}

		for(i=0;i<listIdx.size();i++){
			// printf("%d ",listIdx[i]);
			vis[listIdx[i]] = true;
		}
		// printf("\n");
		ans++;

	}
	printf("%d\n",ans);
	
	return 0;
};