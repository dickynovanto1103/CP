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

const int maxn = 1e5 + 5;

int main(){
	int n,i,j;
	int a[maxn], temp[maxn];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}

	if(n==2){printf("0\n"); return 0;}

	for(i=0;i<n;i++){
		temp[i] = a[i];
	}	

	int bil1 = a[0], bil2 = a[1], cnt1 = 0, cnt2 = 0;
	int bilangan1, bilangan2;
	for(i=0;i<n;i++){
		if(i%2==0){
			if(a[i]!= bil1){cnt1++;}
			if(a[i]!=bil2){cnt2++;}
		}
	}
	int ans1 = min(cnt1,cnt2);
	if(cnt1 <= cnt2){
		bilangan1 = bil1;
	}else{
		bilangan1 = bil2;
	}
	cnt1 = 0, cnt2 = 0;
	bil1 = a[1], bil2 = a[3];
	for(i=0;i<n;i++){
		if(i%2==1){
			if(a[i]!=bil1){cnt1++;}
			if(a[i]!=bil2){cnt2++;}
		}
	}
	int ans2 = min(cnt1,cnt2);
	if(cnt1 <= cnt2){
		bilangan2 = bil1;
	}else{
		bilangan2 = bil2;
	}
	if(bilangan1!=bilangan2)
	int ans = ans1 + ans2;
	printf("%d\n",ans);
	return 0;
};