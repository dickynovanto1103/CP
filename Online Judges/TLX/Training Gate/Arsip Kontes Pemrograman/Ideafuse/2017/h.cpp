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

const int maxn = 50010;

ii pas[maxn];
int pointCounter[maxn];
map<ii, int> mapper;
map<ii, int>::iterator it;
map<int,int> xMapper, yMapper;
map<int,int>::iterator it2;


int cntX[maxn], cntY[maxn];

int main(){
	int tc,i,j,n;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ",tt);
		scanf("%d",&n);
		int cnt = 0;
		memset(pointCounter,0,sizeof pointCounter);
		memset(cntX,0,sizeof cntX); memset(cntY,0,sizeof cntY);
		int counterX = 0, counterY = 0;
		int listIdx[maxn], listIdxX[maxn], listIdxY[maxn];
		for(i=0;i<n;i++){
			int x,y;
			scanf("%d %d",&x,&y);
			pas[i].first = x; pas[i].second = y;
			//mapping point
			it = mapper.find(ii(x,y));
			if(it==mapper.end()){
				pointCounter[cnt] = 1;
				mapper[ii(x,y)] = cnt;
				listIdx[i] = cnt;
				cnt++;
			}else{
				int idx = mapper[ii(x,y)];
				pointCounter[idx]++;
				listIdx[i] = idx;
			}
			//mapping x,y

			it2 = xMapper.find(x);
			if(it2==xMapper.end()){
				cntX[counterX]++;
				xMapper[x] = counterX;
				listIdxX[i] = counterX++;
			}else{
				int idx = xMapper[x];
				cntX[idx]++;
				listIdxX[i] = idx;
			}

			it2 = yMapper.find(y);
			if(it2==yMapper.end()){
				cntY[counterY]++;
				yMapper[y] = counterY;
				listIdxY[i] = counterY++;
			}else{
				int idx = yMapper[y];
				cntY[idx]++;
				listIdxY[i] = idx;
			}
		}
		
		int maks = 0;

		for(i=0;i<n;i++){
			int x = pas[i].first, y = pas[i].second;
			int idx1 = listIdxX[i], idx2 = listIdxY[i];
			int banyakPointSekarang = pointCounter[listIdx[i]];

			int jawab = cntX[idx1] + cntY[idx2] - banyakPointSekarang*2;
			// printf("i: %d jawab: %d cntX[%d]: %d cntY[%d]: %d banyakPointSekarang*2 = %d\n",i,jawab,idx1,cntX[idx1], idx2, cntY[idx2], banyakPointSekarang*2);
			// int jawab = max(banyakDariY, banyakDariX);
			maks = max(maks, jawab);
		}
		
		printf("%d\n",maks);
		xMapper.clear(); yMapper.clear(); mapper.clear();
	}
	
	return 0;
};