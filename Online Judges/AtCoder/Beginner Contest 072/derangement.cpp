#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int n,i,a[100010], idx[100010];
	scanf("%d",&n);
	for(i=1;i<=n;i++){scanf("%d",&a[i]); idx[a[i]] = i;}
	int counter = 0;
	for(i=1;i<=n;i++){
		if(idx[i]==i){counter++; break;}
	}
	if(counter==0){printf("0\n"); return 0;}
	int cnt = 0;
	for(i=1;i<=n-1;i++){
		int bil1 = a[i], bil2 = a[i+1];
		
		if(idx[bil1]==bil1 && idx[bil2]==bil2){
			swap(idx[bil1],idx[bil2]);
			cnt++;
		}
	}
	for(i=1;i<=n-1;i++){
		int bil1 = a[i], bil2 = a[i+1];
		if(i==1){
			if(idx[bil1]==bil1){
				swap(idx[bil1],idx[bil2]);
				cnt++;	
			}
			
		}else{
			if(idx[bil2]==bil2){
				swap(idx[bil1],idx[bil2]);
				cnt++;
			}
		}
	}
	printf("%d\n",cnt);
	return 0;
};