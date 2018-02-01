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

const int maxn = 5e3 + 3;
ii a[maxn];

bool cmp(ii a, ii b){
	if(a.first==b.first){return a.second < b.second;}
	return a.first < b.first;
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++){scanf("%d %d",&a[i].first,&a[i].second);}
	sort(a,a+n,cmp);
	
	int waktu = 0;
	for(i=0;i<n;i++){
		if(waktu>a[i].second){
			waktu = a[i].first;
		}else{
			waktu = a[i].second;
		}
		
	}
	printf("%d\n",waktu);
	return 0;
};