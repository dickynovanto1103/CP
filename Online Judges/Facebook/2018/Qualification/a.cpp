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

struct pas{
	string kata;
	int idx;
};

bool cmp(pas a, pas b){
	return a.idx < b.idx;
}

int main(){
	int tc,i,j;

	ll v,n,k;
	scanf("%d",&tc);

	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ",tt);
		scanf("%lld %lld %lld",&n,&k,&v);
		pas pasangan[60];
		vector<pas> a;
		for(i=0;i<n;i++){
			cin>>pasangan[i].kata;
			pasangan[i].idx = i;
		}
		ll banyakDiambil = k*(v-1);
		ll start = banyakDiambil%n;
		while(k>0){

			a.pb(pasangan[start]);
			start++;
			k--;
			if(start==n){start = 0;}
		}
		sort(a.begin(), a.end(), cmp);
		for(i=0;i<a.size();i++){
			if(i){printf(" ");}
			cout<<a[i].kata;
		}
		printf("\n");

	}
	return 0;
};