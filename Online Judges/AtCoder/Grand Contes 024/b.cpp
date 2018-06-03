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

const int maxn = 2e5 + 5;

int main(){
	int n,i,j;
	int a[maxn];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int expected1 = n;
	for(i=n-1;i>=0;i--){
		if(a[i] == expected1){
			expected1--;
		}
	}
	int expected2=1;
	for(i=0;i<n;i++){
		if(a[i] == expected2){
			expected2++;
		}
	}
	expected2--;
	expected2 = n-expected2;
	// printf("expected1: %d expected2: %d\n",expected1, expected2);
	int expected = min(expected2, expected1);

	printf("%d\n",expected);
	return 0;
};