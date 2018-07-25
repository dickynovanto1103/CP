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

int main() {
	int n,m,i,j,a[1010],b[1010];
	bool visit[1010];
	memset(visit,false,sizeof visit);
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++){scanf("%d",&a[i]);}
	for(i=0;i<m;i++){scanf("%d",&b[i]);}
	sort(b,b+m);
	sort(a,a+n);
	/*printf("a:\n");
	for(i=0;i<n;i++){printf("%d\n",a[i]);}
	printf("b:\n");
	for(i=0;i<m;i++){printf("%d\n",b[i]);}*/
	int cnt = 0;
	for(i=0;i<n;i++){
		int bil = a[i];
		for(j=0;j<m;j++){
			if((bil == b[j] || bil+1 == b[j]) && !visit[j]){
				visit[j] = true; cnt++;
				//printf("i: %d ditambahkan ketika bil: %d dan b[%d] = %d\n",i,bil,j,b[j]);
				break;
			}else if(b[j] > bil+1){break;}
		}
	}
	printf("%d\n",cnt);
	return 0;
}