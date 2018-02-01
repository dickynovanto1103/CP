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

const int maxn = 2e5 + 5;
int a[maxn];
struct node{
	int jarakKeKuadrat, jarakTidakKuadrat;
};

node nilai[maxn];

bool cmpKuadrat(node a, node b){
	return a.jarakKeKuadrat < b.jarakKeKuadrat;
}
bool cmpTidakKuadrat(node a, node b){
	return a.jarakTidakKuadrat < b.jarakTidakKuadrat;
}

int main(){
	int n,i;
	vi listKuadrat;
	for(i=0;;i++){
		
		listKuadrat.pb(i*i);
		if(i*i>inf){break;}
	}
	//printf("listKuadrat: %d\n",listKuadrat[4]);
	//printf("banyak: %d\n",cnt);
	scanf("%d",&n);
	vi listAngkaKuadrat;
	vi listAngkaTidakKuadrat;
	vi listJarakKuadrat, listJarakTidakKuadrat;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		nilai[i].jarakTidakKuadrat = inf;
		nilai[i].jarakKeKuadrat = inf;
		if(binary_search(listKuadrat.begin(),listKuadrat.end(),a[i])){
			listAngkaKuadrat.pb(a[i]);
			if(a[i]==0 || a[i]==1){
				
				if(a[i]==0){nilai[i].jarakTidakKuadrat = 2; listJarakTidakKuadrat.pb(2);}
				else{nilai[i].jarakTidakKuadrat = 1; listJarakTidakKuadrat.pb(1);}
			}else{
				nilai[i].jarakTidakKuadrat = 1;
				listJarakTidakKuadrat.pb(1);
			}
		}else{
			listAngkaTidakKuadrat.pb(a[i]);
			int idx = lower_bound(listKuadrat.begin(),listKuadrat.end(),a[i]) - listKuadrat.begin();
			if(idx==listKuadrat.size()){idx--;}
			//printf("%d sama %d\n",listKuadrat[idx],listKuadrat[idx-1]);
			nilai[i].jarakKeKuadrat = min(abs(a[i]-listKuadrat[idx]),abs(a[i]-listKuadrat[idx-1]));
			listJarakKuadrat.pb(min(abs(a[i]-listKuadrat[idx]),abs(a[i]-listKuadrat[idx-1])));
		}
	}
	int jumlahKuadrat=listAngkaKuadrat.size();
	int jumlahTidakKuadrat = listAngkaTidakKuadrat.size();
	if(jumlahKuadrat==jumlahTidakKuadrat){
		printf("0\n");
	}else{
		int butuh = abs(jumlahTidakKuadrat-jumlahKuadrat)/2;
		ll ans = 0;
		sort(listJarakTidakKuadrat.begin(),listJarakTidakKuadrat.end());
		sort(listJarakKuadrat.begin(),listJarakKuadrat.end());
		if(jumlahKuadrat>jumlahTidakKuadrat){
			//yang diubah yang jumlahTidakKuadrat
			//sort(nilai,nilai+n,cmpTidakKuadrat);	

			for(i=0;i<butuh;i++){ans+=(ll)listJarakTidakKuadrat[i];}
		}else{
			//sort(nilai,nilai+n,cmpKuadrat);	
			for(i=0;i<butuh;i++){ans+=(ll)listJarakKuadrat[i];}
		}
		printf("%lld\n",ans);
	}
	return 0;
};