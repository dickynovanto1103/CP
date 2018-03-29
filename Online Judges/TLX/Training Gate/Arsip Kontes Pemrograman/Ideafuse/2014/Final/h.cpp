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

int a[305];

int main(){
	int n, k, c=0;
	scanf("%d %d", &n, &k);
	for(int i=0;i<n;i++){
		scanf("%d", a+i);
		if(a[i]<0)
			c++;
	}
	int sum=0;
	if(k>=c){
		for(int i=0;i<n;i++)
			sum+=abs(a[i]);
		printf("%d\n0 %d\n", sum, n-1);
		return 0;
	}
	int l, r;
	int ma=-3e6;
	for(int i=0;i<n;i++){
		for(int j=n;j>i;j--){
			vector<int> v(a+i, a+j);
			sort(v.begin(), v.end());
			sum = 0;
			for(int id=0, w=k;id<v.size();id++){
				if(w&&v[id]<0){
					v[id] = -v[id];
					w--;
				}
				sum += v[id];
			}
			if(ma < sum){
				ma = sum;
				l = i;
				r = j-1;
			}
		}
	}
	printf("%d\n%d %d\n", ma, l, r);
	return 0;
};