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

int main(){
	int n,i,j;
	int a[110];
	scanf("%d",&n);
	for(i=0;i<n;i++){scanf("%d",&a[i]);}
	set<int> s;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			int jumlah = a[i] + a[j];
			s.insert(jumlah);
		}
	}
	printf("%d\n",(int)s.size());
	return 0;
};