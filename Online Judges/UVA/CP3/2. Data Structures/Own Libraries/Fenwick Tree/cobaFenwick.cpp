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

int LSOne(int a){return (a&(-a));}

class FenwickTree{
	private:
		vi ft;
	public:
		FenwickTree(int n){ft.assign(n+1,0);}
		int rsq(int a){
			int ans = 0;
			for(;a;a-=LSOne(a)){ans+=ft[a];}
			return ans;
		}
		int rsq(int a, int b){
			return rsq(b) - rsq(a-1);
		}
		void update(int idx, int value){
			for(; idx<ft.size();idx+=LSOne(idx)){ft[idx]+=value;}
		}
		vi getFT(){return ft;}
};

int main() {
	int n,i,a[100];
	scanf("%d",&n);
	for(i=1;i<=n;i++){scanf("%d",&a[i]);}
	FenwickTree ft(n);
	for(i=1;i<=n;i++){ft.update(i,a[i]);}
	vi ans = ft.getFT();
	int ukuran = ans.size();
	printf("ukuran: %d\n",ukuran);
	for(i=1;i<ukuran;i++){
		if(i){printf(" ");}
		printf("%d",ans[i]);
	}
	printf("\n");
	int idx1,idx2, com;
	while(scanf("%d",&com)!=EOF){
		if(com==1){
			scanf("%d %d",&idx1,&idx2);
			printf("jumlah dari idx %d ke %d = %d\n",idx1,idx2,ft.rsq(idx1,idx2));	
		}else{
			int nilai;
			scanf("%d %d",&idx1,&nilai);
			int selisih = nilai-a[idx1];
			a[idx1] = nilai;
			printf("a[%d] terupdate jd: %d \n",idx1,nilai);
			ft.update(idx1,selisih);
		}
		
	}
	
	return 0;
}