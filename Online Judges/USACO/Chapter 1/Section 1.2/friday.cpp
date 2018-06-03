/*
ID: dickyno1
LANG: C++
TASK: friday
*/

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

bool isLeapYear(int n) {
	if(n%4==0) {
		if(n%100==0){
			if(n%400==0){return true;}
			else{return false;}
		}else{
			return true;
		}
	}else{
		return false;
	}
}

int main() {
	freopen("friday.in", "r", stdin);
	freopen("friday.out", "w", stdout);
	int n,i,j;
	scanf("%d",&n);
	int month[] = {31,28,31,30,31,30,31,31,30,31,30,31};
	int tahun = 1900;
	int bulan = 1;
	int tanggal = 1;
	int ans[7] = {0};
	int idx = 2;
	

	for(i=0;i<n;i++){
		tahun=1900 + i;
		if(isLeapYear(tahun)) {
			month[1] = 29;
		}else{
			month[1] = 28;
		}
		for(j=0;j<12;j++){
			for(int k=1;k<=month[j];k++){
				if(k==13){
					ans[idx]++;
				}
				idx++;
				idx%=7;
			}
		}
	}
	// printf("%d %d",ans[5],ans[6]);
	for(i=0;i<7;i++){
		if(i){printf(" ");}
		printf("%d",ans[i]);
	}
	printf("\n");
	return 0;
}