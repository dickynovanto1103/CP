#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main() {
	int i,j,n,m;
	string a,b;
	scanf("%d %d",&n,&m);
	cin>>a>>b;
	/*printf("n: %d m: %d\n",n,m);
	cout<<a<<" "<<b<<endl;*/
	vi temp, ans;
	int counter = inf;
	for(i=0;i<=m-n;i++){
		int cnt = 0;
		int tempidx = i;
		for(j=0;j<n;j++){
			//if(i==m){cnt = inf; temp.clear(); break;}
			if(b[tempidx]!=a[j]){cnt++; temp.pb(j+1);}
			/*printf("b[%d] = %c a[%d] = %c\n",tempidx,b[tempidx],j,a[j]);
			printf("cnt jd: %d\n",cnt);*/
			tempidx++;
		}
		if(counter>cnt){counter = cnt; ans = temp; }
		//printf("counter jadi: %d\n",counter);

		temp.clear();
	}
	printf("%d\n",counter);
	for(i=0;i<counter;i++){
		if(i){printf(" ");}
		printf("%d",ans[i]);
	}
	printf("\n");
	return 0;
}