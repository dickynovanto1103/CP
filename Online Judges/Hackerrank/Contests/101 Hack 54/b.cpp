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

const int maxn = 150010;

int main(){
	int n,i,j;
	ll x[maxn];
	int q;
	scanf("%d",&n);
	for(i=0;i<n;i++){scanf("%lld",&x[i]);}
	ll w,v;
	scanf("%lld %lld",&w,&v);
	double waktuSampaiBus[maxn];
	for(i=0;i<n;i++){
		waktuSampaiBus[i] = (double)x[i] / (double)v;
	}
	scanf("%d",&q);
	while(q--){
		ll p,t,u;
		scanf("%lld %lld %lld",&p,&t,&u);
		//cari index paling dekat dengan p
		int idx = lower_bound(x,x+n,p) - x;
		double minWaktu = (((double)x[n-1] - (double)p) / (double)u) + (double)t;
		
		//jalan dulu ke i..tunggu sampe bus dateng
		// printf("i: %d\n",i);
		double waktuJalan = (double)(abs(x[idx] - p)) / (double)u;
		// printf("waktuJalan: %.9lf \n",waktuJalan);
		double waktuSampai = (double)t + waktuJalan;
		// printf("waktuSampai: %.9lf\n",waktuSampai);
		ll loop = (ll)ceil(waktuSampai / waktuSampaiBus[idx]);
		if(( waktuSampaiBus[idx] - waktuSampai) > eps || fabs(waktuSampaiBus[idx] - waktuSampai) < eps){
			loop = 0;
		}else{
			double selisih = waktuSampai - waktuSampaiBus[idx];
			loop = (ll)ceil(selisih/w);
		}
		double waktuBusSampai = waktuSampaiBus[idx] + loop*w;
		// printf("waktuBusSampai: %.9lf\n",waktuBusSampai);
		double waktuTunggu = waktuBusSampai - waktuSampai;
		double waktuJalanBus = ((double)x[n-1] - (double)x[idx]) / (double)v;
		minWaktu = min(minWaktu, waktuSampai + waktuTunggu + waktuJalanBus);
		if(idx>0){
			int idxSebelum = idx-1;
			//jalan dulu ke i..tunggu sampe bus dateng
			// printf("i: %d\n",i);
			double waktuJalan = (double)(abs(x[idxSebelum] - p)) / (double)u;
			// printf("waktuJalan: %.9lf \n",waktuJalan);
			double waktuSampai = (double)t + waktuJalan;
			// printf("waktuSampai: %.9lf\n",waktuSampai);
			ll loop = (ll)ceil(waktuSampai / waktuSampaiBus[idxSebelum]);
			if(( waktuSampaiBus[idxSebelum] - waktuSampai) > eps || fabs(waktuSampaiBus[idxSebelum] - waktuSampai) < eps){
				loop = 0;
			}else{
				double selisih = waktuSampai - waktuSampaiBus[idxSebelum];
				loop = (ll)ceil(selisih/w);
			}
			double waktuBusSampai = waktuSampaiBus[idxSebelum] + loop*w;
			// printf("waktuBusSampai: %.9lf\n",waktuBusSampai);
			double waktuTunggu = waktuBusSampai - waktuSampai;
			double waktuJalanBus = ((double)x[n-1] - (double)x[idxSebelum]) / (double)v;
			minWaktu = min(minWaktu, waktuSampai + waktuTunggu + waktuJalanBus);
		}
		
		// printf("minWaktu: %.9lf\n",minWaktu);
		// for(i=0;i<n;i++){
		// 	//jalan dulu ke i..tunggu sampe bus dateng
		// 	// printf("i: %d\n",i);
		// 	double waktuJalan = (double)(abs(x[i] - p)) / (double)u;
		// 	// printf("waktuJalan: %.9lf \n",waktuJalan);
		// 	double waktuSampai = (double)t + waktuJalan;
		// 	// printf("waktuSampai: %.9lf\n",waktuSampai);
		// 	ll loop = (ll)ceil(waktuSampai / waktuSampaiBus[i]);
		// 	if(( waktuSampaiBus[i] - waktuSampai) > eps || fabs(waktuSampaiBus[i] - waktuSampai) < eps){
		// 		loop = 0;
		// 	}else{
		// 		double selisih = waktuSampai - waktuSampaiBus[i];
		// 		loop = (ll)ceil(selisih/w);
		// 	}
		// 	double waktuBusSampai = waktuSampaiBus[i] + loop*w;
		// 	// printf("waktuBusSampai: %.9lf\n",waktuBusSampai);
		// 	double waktuTunggu = waktuBusSampai - waktuSampai;
		// 	double waktuJalanBus = ((double)x[n-1] - (double)x[i]) / (double)v;
		// 	minWaktu = min(minWaktu, waktuSampai + waktuTunggu + waktuJalanBus);
		// }
		printf("%.9lf\n",minWaktu);
	}
	return 0;
};