#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef long long ll;
int LSOne(int i){return (i&(-i));}
vi ft;

class Fenwick {
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
	int n, a[200010],i, test=1;
	while(scanf("%d",&n),n){
		if(test>1){printf("\n");}
		printf("Case %d:\n",test++);
		for(i=0;i<n;i++){scanf("%d",&a[i]);}
		Fenwick f(n);
		for(i=0;i<n;i++){f.adjust(i+1,a[i]);}
		//cin>>ws;
		string command;
		while(cin>>command && command!="END"){
			//cout<<"command: "<<command<<", n: "<<n<<endl;
			if(command=="M"){
				//printf("test M\n");
				int a,b;
				scanf("%d %d",&a,&b);
				
				printf("%d\n",f.rsq(a,b));
				
			}else{//command R
				//printf("test S\n");
				int idx, val;
				scanf("%d %d",&idx,&val);
				int v = val-a[idx-1];
				f.adjust(idx,v);
				a[idx-1] = val;
			}
		}
		ft.clear();
	}
	

	return 0;
}