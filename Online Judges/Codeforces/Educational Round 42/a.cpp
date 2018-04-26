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
	int sum = 0;
	int a[200001];
	scanf("%d",&n);
	for(i=0;i<n;i++){scanf("%d",&a[i]); sum+=a[i];}
	int batas = sum/2;
	if(sum%2==1){batas++;}
	int jumlah = 0;
	for(i=0;i<n;i++){
		jumlah+=a[i];
		if(jumlah>=batas){break;}
	}
	printf("%d\n",i+1);
	return 0;
};