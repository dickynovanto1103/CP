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

const int maxn = 1e3 + 3;

int main(){
	ll c1,c2,c3,c4;
	int n,m,i,j;
	ll a[maxn], b[maxn];
	scanf("%lld %lld %lld %lld",&c1,&c2,&c3,&c4);
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++){scanf("%lld",&a[i]);}
	for(i=0;i<m;i++){scanf("%lld",&b[i]);}
	ll biayaAtas = 0;
	for(i=0;i<n;i++){//bandingin 1 dan 2
		ll biaya1 = c1*a[i];
		ll biaya2 = c2;
		if(biaya1 > biaya2){
			biayaAtas += biaya2;
		}else{
			biayaAtas += biaya1;
		}
	}
	ll biayaBawah = 0;
	for(i=0;i<m;i++){
		ll biaya1 = c1*b[i];
		ll biaya2 = c2;
		if(biaya1 > biaya2){
			biayaBawah += biaya2;
		}else{
			biayaBawah += biaya1;
		}	
	}
	//menghitung biaya minimal antara 2 dan 3
	ll biayaTotal1Dan2 = biayaAtas + biayaBawah;
	ll biaya1 = biayaBawah + c3;
	ll biaya2 = biayaAtas + c3;
	ll biaya3 = c3 + c3;
	ll biayaMinimal = min(biayaTotal1Dan2, min(biaya1, min(biaya2, biaya3)));
	
	ll ans = min(biayaMinimal, c4);
	printf("%lld\n",ans);
	return 0;
};