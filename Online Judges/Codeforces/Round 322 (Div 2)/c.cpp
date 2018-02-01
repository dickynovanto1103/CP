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

struct Node{
	int angka, lastDigit;
};

bool cmp(Node a, Node b){
	return a.lastDigit>b.lastDigit;
}

int main(){
	int n,i,j,k;
	scanf("%d %d",&n,&k);
	Node a[maxn];
	for(i=0;i<n;i++){scanf("%d",&a[i].angka); a[i].lastDigit = a[i].angka%10;}
	sort(a,a+n,cmp);
	
	//1 pass dulu abisin k
	bool masihCukup = true;
	bool berprogress = false;
	for(i=0;i<n;i++){
		if(a[i].angka==100){continue;}
		int sisa = 10-a[i].lastDigit;
		if(k<sisa){masihCukup = false;break;}
		a[i].lastDigit = 0;
		a[i].angka+=sisa;
		k-=sisa;
		berprogress = true;
	}
	if(!masihCukup){
		int ans = 0;
		for(i=0;i<n;i++){
			ans+=(a[i].angka/10);
		}
		printf("%d\n",ans); return 0;
	}
	while(true){
		berprogress = false;
		for(i=0;i<n;i++){
			if(a[i].angka==100){continue;}
			int sisa = 10;
			if(k<sisa){masihCukup = false;break;}
			a[i].lastDigit = 0;
			a[i].angka+=sisa;
			k-=sisa;
			berprogress = true;
		}
		if(!berprogress){
			int ans = 0;
			for(i=0;i<n;i++){
				ans+=(a[i].angka/10);
			}
			printf("%d\n",ans); return 0;		
		}
		if(!masihCukup){
			int ans = 0;
			for(i=0;i<n;i++){
				ans+=(a[i].angka/10);
			}
			printf("%d\n",ans); return 0;		
		}
	}
	return 0;
};