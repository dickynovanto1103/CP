#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
int LSOne(int i){return (i&(-i));}

class Fenwick {
	private:
		vi ft;
	public:
		Fenwick(int n){ft.assign(n+1,0);}
		int rsq(int b){
			int sum = 0;
			while(b){sum+=ft[b]; b-=LSOne(b);}
			return sum;
		}
		int rsq(int a, int b){
			return rsq(b) - (a==1 ? 0: rsq(a-1));
		}
		void adjust(int k, int v){
			while(k<(int)ft.size()){
				ft[k]+=v;
				k+=LSOne(k);
			}
		}
		void showft(){
			for(int i=0;i<ft.size();i++){
				if(i>0){printf(" ");}
				printf("%d",ft[i]);
			}
			printf("\n");
		}
};

int main(){
	int n, a[100],i;
	scanf("%d",&n);
	for(int i=0;i<n;i++){scanf("%d",&a[i]);}
	
	
	Fenwick f(n);
	for(i=0;i<n;i++){f.adjust(i+1,a[i]);}
	printf("ft pertama\n");
	f.showft();
	int q;
	scanf("%d",&q);
	while(q--){
		int a,b;
		scanf("%d %d",&a,&b);
		printf("RSQ(%d,%d) = %d\n",a,b,f.rsq(a,b));
	}
	int idx, val;
	scanf("%d %d",&idx,&val);
	int v = val-a[idx-1];
	f.adjust(idx,v);
	printf("ft kedua\n");
	f.showft();
	printf("setelah terupdate\n");
	scanf("%d",&q);
	while(q--){
		int a,b;
		scanf("%d %d",&a,&b);
		printf("RSQ(%d,%d) = %d\n",a,b,f.rsq(a,b));
	}

	return 0;
}