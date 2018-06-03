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
typedef pair<double, ii> dii;
typedef vector<ii> vii;

const int maxn = 2e5 + 5;

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ",tt);
		int n,m;
		scanf("%d %d",&n,&m);
		int a[maxn];
		priority_queue<dii> pq;
		ll sum = 0;
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
			sum+=a[i];

		}
		int mAwal = m;
		double avg = (double)sum/(double)m;
		for(i=0;i<n;i++){
			
			double contributeSekarang = (a[i] - avg)*(a[i] - avg);
			double contributeNanti = (a[i]/2.0 - avg)*(a[i]/2.0 - avg)*2;
			double selisih = contributeSekarang - contributeNanti;
			// printf("a[%d]: %d selisih: %lf\n",i,a[i], selisih);
			pq.push(make_pair(selisih, ii(a[i], 1)));
		}

		// printf("avg: %lf\n",avg);
		m-=n;
		while(m>0) {
			dii front = pq.top(); pq.pop();
			double selisih = front.first;
			int elemenArray = front.second.first, banyak = front.second.second;
			// printf("selisih: %lf elemenArray: %d banyak: %d\n",selisih, elemenArray, banyak);
			banyak++;

			double contributeSekarang = (elemenArray/(double)(banyak) - avg)*(elemenArray/(double)(banyak) - avg)*(banyak);
			double contributeNanti = (elemenArray/(double)(banyak+1) - avg)*(elemenArray/(double)(banyak+1) - avg) * (banyak+1);
			selisih = contributeSekarang - contributeNanti;
			pq.push(make_pair(selisih, ii(elemenArray, banyak)));
			m--;
		}

		double ans = 0;
		while(!pq.empty()) {
			dii front = pq.top(); pq.pop();
			double selisih = front.first;
			int elemenArray = front.second.first, banyak = front.second.second;
			double bil = (double)elemenArray / (double)banyak;
			// printf("bil: %lf elemenArray: %d banyak: %d\n",bil,elemenArray,banyak);
			double contributeSekarang = (bil - avg)*(bil - avg)*banyak;
			ans+=contributeSekarang;
			// printf("contributeSekarang: %lf ans jd: %lf\n",contributeSekarang, ans);
		}	
		
		printf("%.10lf\n",ans/(double)mAwal);


	}
	return 0;
};