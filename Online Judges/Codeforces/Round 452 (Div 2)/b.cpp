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
	int n,i,j;
	int kombinasi1[] = {31,28,31,30,31,30,31,31,30,31,30,31, 31,28,31,30,31,30,31,31,30,31,30,31, 31,28,31,30,31,30,31,31,30,31,30,31, 31,29,31,30,31,30,31,31,30,31,30,31};
	int kombinasi2[] = {31,28,31,30,31,30,31,31,30,31,30,31, 31,28,31,30,31,30,31,31,30,31,30,31, 31,29,31,30,31,30,31,31,30,31,30,31, 31,28,31,30,31,30,31,31,30,31,30,31};
	int kombinasi3[] = {31,28,31,30,31,30,31,31,30,31,30,31, 31,29,31,30,31,30,31,31,30,31,30,31, 31,28,31,30,31,30,31,31,30,31,30,31, 31,28,31,30,31,30,31,31,30,31,30,31};
	int kombinasi4[] = {31,29,31,30,31,30,31,31,30,31,30,31, 31,28,31,30,31,30,31,31,30,31,30,31, 31,28,31,30,31,30,31,31,30,31,30,31, 31,28,31,30,31,30,31,31,30,31,30,31};
	int kombinasi5[] = {31,28,31,30,31,30,31,31,30,31,30,31, 31,28,31,30,31,30,31,31,30,31,30,31, 31,28,31,30,31,30,31,31,30,31,30,31, 31,28,31,30,31,30,31,31,30,31,30,31};
	
	scanf("%d",&n);
	int a[100];
	for(i=0;i<n;i++){scanf("%d",&a[i]);}
	int found = false;
	for(i=0;i<48-n;i++){
		j = 0;
		while(j<n && kombinasi1[i+j]==a[j]){
			j++;
		}
		if(j==n){printf("YES\n"); return 0;}
	}
	for(i=0;i<48-n;i++){
		j = 0;
		while(j<n && kombinasi2[i+j]==a[j]){
			j++;
		}
		if(j==n){printf("YES\n"); return 0;}
	}
	for(i=0;i<48-n;i++){
		j = 0;
		while(j<n && kombinasi3[i+j]==a[j]){
			j++;
		}
		if(j==n){printf("YES\n"); return 0;}
	}
	for(i=0;i<48-n;i++){
		j = 0;
		while(j<n && kombinasi4[i+j]==a[j]){
			j++;
		}
		if(j==n){printf("YES\n"); return 0;}
	}
	for(i=0;i<48-n;i++){
		j = 0;
		while(j<n && kombinasi5[i+j]==a[j]){
			j++;
		}
		if(j==n){printf("YES\n"); return 0;}
	}

	printf("NO\n");
	return 0;
};