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

const int maxn = 1e2 + 2;

string kata[maxn];

bool isPrefix(int idx1, int idx2){
	for(int i=0;i<kata[idx1].length();i++){
		char kar = kata[idx1][i];
		char kar2 = kata[idx2][i];
		if(kar != kar2){return false;}
	}
	return true;
}

ll modPow(ll a, ll b){
	if(b==0){return 1;}
	else{
		if(b%2==1){return a*modPow(a,b-1);}
		else{
			ll temp = modPow(a,b/2);
			return temp*temp;
		}
	}
}

bool cmp(string a, string b){
	return a.length() < b.length();
}

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	int tt = 1;
	while(tc--){
		int n,p;
		scanf("%d %d",&n,&p);
		bool isSkipped[maxn];
		memset(isSkipped, false, sizeof isSkipped);

		for(i=0;i<p;i++){
			cin>>kata[i];
		}
		sort(kata, kata+p, cmp);
		for(i=0;i<p;i++){
			for(j=i+1;j<p;j++){
				
				if(isPrefix(i, j)){
					isSkipped[j] = true;
				}
				
			}
		}
		ll ans = modPow(2, n);
		for(i=0;i<p;i++){
			if(isSkipped[i]){continue;}
			int panjangSisa = n - kata[i].length();
			ans -= modPow(2, panjangSisa);
		}
		printf("Case #%d: %lld\n",tt++, ans);
	}
	return 0;
};