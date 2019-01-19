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

const int maxn = 5003;

int a[maxn], temp[maxn];

bool isUnsorted(int n) {
	int j;
	for(int i=0;i<n;i++){
		bool foundSorted = true;
		for(j=i-1;j>=0;j--){
			if(a[j] > a[i]){foundSorted = false;break;}
		}
		for(j=i+1;j<n;j++){
			if(a[j] < a[i]){foundSorted = false;break;}
		}
		if(foundSorted){return false;}
	}
	return true;
}

int main(){
	int n,i,j;
	int cnt = 0;
	scanf("%d",&n);
	
	for(i=0;i<n;i++){scanf("%d",&a[i]); temp[i] = a[i];}
	sort(a,a+n);
	do{
		if(isUnsorted(n)) {
			cnt++;
			for(i=0;i<n;i++){
				printf("%d ",a[i]);
			}
			printf("\n");	
		}
		
	}while(next_permutation(a,a+n));
	printf("cnt: %d\n",cnt);
	return 0;
};