#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 100010;

bool isvisited[1000010];
int main(){
	int tc,tt,i,j;
	int a[maxn],b[maxn], c[maxn];
	scanf("%d",&tc);
	for(tt=1;tt<=tc;tt++){
		printf("Case #%d: ", tt);
		int n;
		scanf("%d",&n);
		memset(isvisited,false,sizeof isvisited);
		// set<int> satuan;
		// set<ii> gabungan;
		// set<ii>::iterator it;
		// satuan.clear(); gabungan.clear();
		int cnt = 2;
		set<int> listDiambil;
		for(i=0;i<n;i++){
			scanf("%d %d %d",&a[i],&b[i],&c[i]);
			
			/*satuan.insert(a[i]);
			gabungan.insert(ii(b[i],c[i]));
			printf("masuk %d %d\n",b[i],c[i]);*/
		}
		for(i=0;i<n;i++){
			listDiambil.insert(a[i]);
			isvisited[a[i]] = true;
		}
		
		for(i=1;i<n;i++){
			
		}

		//if(n==1){printf("2\n"); continue;}
		printf("%d\n",cnt);
		/*printf("nilai gabungan\n");
		for(it=gabungan.begin(); it!=gabungan.end();it++){
			ii front = *it;
			printf("%d %d\n",front.first, front.second);
		}*/



	}

	return 0;
};