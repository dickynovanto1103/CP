#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main() {
	int tc,n,i;
	string kota;
	int a[25];
	scanf("%d",&tc);
	string dum;
	while(tc--){
		memset(a,0,sizeof a);
		map<string,int> mapper;
		map<string,int>::iterator it;
		scanf("%d",&n);
		int cnt = 0;
		for(i=0;i<n;i++){
			int banyak;
			cin>>kota>>banyak>>dum;
			it = mapper.find(kota);
			if(it==mapper.end()){
				mapper[kota] = cnt;
				a[cnt] = banyak;
			//	printf("a[%d]: %d\n",cnt,a[cnt]);
				cnt++;
			}else{
				int idx = mapper[kota];
				a[idx]+=banyak;
			//	printf("a[%d]: jd %d\n",idx,a[idx]);
			}
		}
		sort(a,a+n);
		reverse(a,a+n);
		int tot = 0;
		/*for(i=0;i<n;i++){
			printf("%d\n",a[i]);
		}*/
		for(i=2;i<n;i++){
		
			tot+=a[i];
		}
		printf("%d Juta\n",tot);
	}
	return 0;
}