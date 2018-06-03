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

const int maxn = 1e5 + 5;

int main(){
	int n,k,l;
	int i,j;
	scanf("%d %d %d",&n,&k,&l);
	int a[maxn];
	int minim = inf;
	for(i=0;i<(n*k);i++){
		scanf("%d",&a[i]);
		minim = min(minim, a[i]);
	}
	priority_queue<int> bawah,atas;
	int batasMaks = minim+l;
	
	for(i=0;i<(n*k);i++){
		
		if(a[i] <= batasMaks) {bawah.push(a[i]);}
		else{atas.push(a[i]); }
	}

	
	
	//ambil sebanyak k-1 kali dari yg atas..terus ambil yg paling besar dari yg paling bawah
	ll ans = 0;
	while(true) {
		int cnt = 0;
		if(!atas.empty()){
			while(cnt<(k-1)){
				atas.pop();
				cnt++;
				if(atas.empty()){break;}
			}	
			//ambil dari yg bawah
			ll bil = 0;
			while(cnt<k) {
				if(bawah.empty()){printf("0\n"); return 0;} //ga mungkin
				else{
					bil = bawah.top();bawah.pop();
				}	
				cnt++;
			}
			ans+=bil;
			
		}else{
			//ambil sebanyak k dari bawah
			ll bil = 0;
			while(cnt<k){
				bil = bawah.top(); bawah.pop();
				cnt++;
				if(bawah.empty()){break;}
			}
			ans+=bil;
		}
		if(bawah.empty() && atas.empty()){break;}
		
	}
	
	printf("%lld\n",ans);


	return 0;
};