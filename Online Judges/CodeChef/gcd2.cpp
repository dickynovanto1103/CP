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

const ll mod = 50000;

int main(){
	int tc,a,i,j;
	string b;
	//printf("%d\n",__gcd(0,1));
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&a); cin>>b;
		if(a==0){cout<<b<<endl; continue;}
		ll sum = 0;
		for(i=0;i<b.length();i++){
			int angka = b[i] - '0';
			sum*=10;
			sum+=angka;
			sum%=(ll)a;
		}
		printf("%lld\n", __gcd((ll)a,sum));
	}
	return 0;
};