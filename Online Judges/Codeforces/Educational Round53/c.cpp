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
int prefX[maxn], suffX[maxn], prefY[maxn], suffY[maxn]; 
int n;
int x,y;

bool can(int pjg){
	int i,j;
	int kiri = 0, kanan = pjg-1;
	int iterasi = n-pjg+1;
	if(pjg == n){
		int butuh = abs(x)+abs(y);
		if(butuh%2 == pjg%2){
			return true;
		}else{
			return false;
		}
	}
	// printf("iterasi; %d pjg: %d n:%d\n",iterasi,pjg,n);

	for(i=0;i<iterasi;i++){
		int xKiri, yKiri, xKanan, yKanan, xTotal, yTotal;
		// printf("i: %d kiri: %d kanan: %d\n",i,kiri,kanan);
		if(kiri == 0){
			// printf("masuk\n");
			xKiri = 0, yKiri = 0;
			xKanan = suffX[kanan+1];
			yKanan = suffY[kanan+1];
		}else if(kanan == (n-1)){
			xKiri = prefX[kiri-1], yKiri = prefY[kiri-1];
			xKanan = 0;
			yKanan = 0;

		}else{
			xKiri = prefX[kiri-1], yKiri = prefY[kiri-1];
			xKanan = suffX[kanan+1];
			yKanan = suffY[kanan+1];			
		}
		xTotal = xKiri + xKanan, yTotal = yKanan + yKiri;
		int butuh = abs(xTotal - x) + abs(yTotal - y);
		if(butuh > pjg){
			kiri++; kanan++;
			continue; //ga bs
		}else{
			if(butuh%2 == pjg%2){
				return true;
			}
		}
		
		kiri++; kanan++;

	}
	return false;
}

int main(){
	int i,j;
	string kata;
	
	scanf("%d",&n);
	cin>>kata;
	scanf("%d %d",&x,&y);
	if((x+y) > n){printf("-1\n");return 0;}
	
	for(i=0;i<n;i++){
		char kar = kata[i];
		if(kar == 'L'){
			prefX[i] = -1;
			suffX[i] = -1;
		}
		else if(kar == 'R'){
			prefX[i] = 1;
			suffX[i] = 1;
		}
		else if(kar == 'U'){
			prefY[i] = 1;
			suffY[i] = 1;
		}
		else{
			prefY[i] = -1;
			suffY[i] = -1;
		}
	}
	for(i=1;i<n;i++){
		prefX[i] += prefX[i-1];
		prefY[i] += prefY[i-1];
	}
	for(i=n-2;i>=0;i--){
		suffX[i] += suffX[i+1];
		suffY[i] += suffY[i+1];
	}

	if(prefX[n-1] == x && prefY[n-1] == y){printf("0\n"); return 0;}
	int butuh = (abs(x) + abs(y));
	if(butuh > n){printf("-1\n"); return 0;}
	if(butuh%2 != n%2){printf("-1\n"); return 0;}
	
	int kiri = 0, kanan = n, mid, ans = -1;
	while(kiri <= kanan){
		int mid = (kiri+kanan)/2;
		
		if(can(mid)){
			ans = mid;
			kanan = mid-1;
		}else{
			kiri = mid+1;
		}
	}
	
	printf("%d\n",ans);

	return 0;
};