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
	int n,a[100010],i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++){scanf("%d",&a[i]);}
	sort(a,a+n);
	reverse(a,a+n);
	int ans = 0;
	j=n;
	for(i=0;i<n;i++){
		
		int banyak = a[i];
		if(banyak==-1){break;}
		ans++;
		while(banyak--){
			j--;
			a[j] = -1;

		}
		//printf("j sekarang di: %d\n",j);
	}
	
	printf("%d\n",ans);
	return 0;
};