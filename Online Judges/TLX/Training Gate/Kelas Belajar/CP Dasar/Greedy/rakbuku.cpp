#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

bool acompare(int a, int b){return a>b;}

int main() {
	int n,tinggi,i,a[20010];
	scanf("%d %d",&n,&tinggi);
	for(i=0;i<n;i++){scanf("%d",&a[i]);}
	sort(a,a+n,acompare);
	//for(i=0;i<n;i++){printf("%d\n",a[i]);}
	int total = 0, cnt = 0;
	i=0;
	while(total<tinggi){
		total+=a[i];
		cnt++;
		i++;
	}
	printf("%d\n",cnt);
	return 0;
}