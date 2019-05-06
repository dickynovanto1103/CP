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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<double,double> ii;
typedef pair<ii,ii> iiii;
typedef vector<ii> vii;

bool isInside(ii a, iiii b){
	return (a.first >= b.first.first && a.first <= b.second.first) && (a.second >= b.first.second && a.second <= b.second.second);

}

int main(){
	int tc=1,i,j,n,q;
	while(scanf("%d",&n), n){
		if(tc == 2){printf("\n");}
		iiii a[45];
		string ukuran[45];
		for(i=0;i<n;i++){
			scanf("%lf %lf %lf %lf",&a[i].first.first,&a[i].first.second,&a[i].second.first,&a[i].second.second);
			cin>>ukuran[i];
		}
		scanf("%d",&q);
		while(q--){
			ii pas;
			string sz;
			scanf("%lf %lf",&pas.first,&pas.second);
			cin>>sz;
			bool found = false;
			for(i=0;i<n;i++){
				if(isInside(pas, a[i])) {
					if(sz == ukuran[i]){cout<<sz<<" correct"<<endl;}
					else{cout<<sz<<" "<<ukuran[i]<<endl;}
					found = true; break;
				}
			}
			if(!found)
				cout<<sz<<" floor"<<endl;
			
		}
		tc=2;
	}
	return 0;
};