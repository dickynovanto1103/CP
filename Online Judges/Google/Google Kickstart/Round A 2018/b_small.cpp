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

const int maxn = 2e4 + 5;

int main(){
	int tc,i,j,n;
	int a[maxn], counter[maxn], bilangan[maxn];
	scanf("%d",&tc);
	map<int,int> mapper;
	
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ",tt);
		memset(counter,0,sizeof counter);
		memset(bilangan,0,sizeof bilangan);
		int k, maks = -inf;
		scanf("%d %d",&n,&k);
		int idx = 0;
		for(i=0;i<n;i++){
			scanf("%d",&a[i]); maks = max(maks, a[i]); 
			if(mapper.find(a[i]) == mapper.end()) {
				mapper[a[i]] = idx;
				bilangan[idx] = a[i];
				counter[idx] = 1;
				idx++;
			}else{
				int indeks = mapper[a[i]];
				counter[indeks]++;
			}
		}
		if(k==0){
			ll sum = 0;
			for(i=0;i<n;i++){
				sum+=(ll)a[i];
			}
			printf("%.8lf\n",(double)sum / (double)n);
			mapper.clear();
			continue;
		}
		double ex = 0, totalPeluang = 0;

		for(i=0;i<idx;i++){
			if(counter[i]==0){continue;}
			int bil = bilangan[i];
			// printf("counter[%d]: %d\n",bil,counter[i]);
			if(bil==maks){continue;}
			double peluang = ((double)counter[i]*(double)counter[i]) / ((double)n*n);
			// printf("peluang pertama: %.8lf\n",peluang);
			// peluang = peluang*peluang;
			ex += (peluang*(double)bil);
			
			totalPeluang+=peluang;
			// printf("peluang: %.8lf ex: %.8lf\n",peluang,ex);
			// printf("totalPeluang: %.8lf\n",totalPeluang);
		}
		double peluangMaks = 1.0-totalPeluang;

		ex += (peluangMaks*maks);
		printf("%.8lf\n",ex);
		mapper.clear();

	}

	return 0;
};