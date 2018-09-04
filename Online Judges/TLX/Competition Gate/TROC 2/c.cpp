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

const int maxn = 2010;

int a[maxn];
int h[maxn];

int main(){
	ll p,t,v,d;
	int n;
	
	int i,j;
	scanf("%d %lld %lld %lld %lld",&n,&p,&t,&v,&d);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(i=1;i<=n;i++){
		scanf("%d",&h[i]);
	}
	a[n+1] = inf*2;
	h[n+1] = inf;
	h[0]=inf;
	
	int depan = 0;
	double ans = 0;
	// printf("n: %d\n",n);
	int belakang = 0-p;
	int nextBelakang = 1, nextDepan = 1;
	while(!(nextDepan == (n+1) && nextBelakang == (n+1))){
		
	}
	queue<ii> q;
	for(i=0;i<=n;i++){
		int selisihJarak = a[i+1] - a[i];
		if(q.empty()){//maju aja
			depan = a[i+1];
			belakang = depan - p;
			if(h[i] > p){
				q.push(ii(a[i],h[i]));
			}
		}
	}

	for(i=0;i<n;i++){
		int selisihJarak = a[i+1] - a[i];
		if(batasTinggiBuntut[i] != inf){
			if(selisihJarak < p)
		}else{

		}
		ll selisihTinggi = t - h[i];
		// printf("selisihTinggi: %lld selisihJarak: %d\n",selisihTinggi,selisihJarak);
		double waktu,biaya;
		if(selisihJarak < p){
			if(h[i + 1] <= h[i]){
				waktu = (double)selisihJarak/(double)v;
				biaya = (double)d*(double)(selisihTinggi)*(double)waktu;
				ans += biaya;	
				buntut += selisihJarak;
			}else{

			}

		}else{
			waktu = (double)p/(double)v;
			biaya = (double)d*(double)(selisihTinggi)*(double)waktu;
			ans += biaya;
		}
		// printf("waktu: %lf biaya: %lf\n",waktu,biaya);
	}
	printf("%.9lf\n",ans);
	return 0;
};