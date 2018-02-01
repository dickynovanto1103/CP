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
	int tc,i,n,c,r,I,d;
	string kataInput, kata[10010];
	scanf("%d",&tc);
	while(tc--){
		cin>>kataInput;
		
		scanf("%d",&n);

		for(i=0;i<n;i++){cin>>kata[i];}
		/*printf("kata input: "); cout<<kataInput<<endl;
		printf("n: %d\n",n);
		printf("dic\n");*/
		for(i=0;i<n;i++){cout<<kata[i]<<endl;}
		scanf("%d %d %d %d",&c,&r,&I,&d);
		//printf("c: %d r: %d i: %d d: %d\n",c,r,I,d);
	}
	return 0;
}