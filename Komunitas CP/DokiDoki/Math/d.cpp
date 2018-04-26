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

const int maxn = 1e3 + 3;
struct point{
	int a[5];
};

struct vec{
	int a[5];
};

int dot(vec a, vec b){
	int sum = 0,i;
	for(i=0;i<5;i++){
		sum+=(a.a[i] * b.a[i]);
	}
	return sum;
}

vec selisih(point a, point b){
	vec c;
	for(int i=0;i<5;i++){
		c.a[i]=(b.a[i] - a.a[i]);
	}
	return c;
}

point p[maxn];

void printPoint(point a){
	for(int i=0;i<5;i++){
		if(i){printf(" ");}
		printf("%d",a.a[i]);
	}
	printf("\n");
}
void printVector(vec a){
	for(int i=0;i<5;i++){
		if(i){printf(" ");}
		printf("%d",a.a[i]);
	}
	printf("\n");
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		for(j=0;j<5;j++){scanf("%d",&p[i].a[j]);}
	}

	if(n>11){printf("0\n"); return 0;}
	vi listIdx;
	
	for(i=0;i<n;i++){
		int cnt = 0;
		bool isValid = true;
		for(j=0;j<n;j++){
			if(i==j){continue;}
			vec hasil1 = selisih(p[i], p[j]);
			
			for(int k=0;k<n;k++){
				// printf("k: %d\n",k);
				if(k==i || k==j){continue;}
				// printf("point 1 p[%d]\n",i);
				// printPoint(p[i]); 
				// printf("point 2 p[%d]\n",j);
				// printPoint(p[j]); 
				// printf("point 3 p[%d]\n",k);
				// printPoint(p[k]);
				vec hasil2 = selisih(p[i], p[k]);
				// printf("vector1:\n");
				// printVector(hasil1);
				// printf("vector2:\n");
				// printVector(hasil2);
				int hasilDot = dot(hasil1, hasil2);
				// printf("hasilDot: %d\n",hasilDot);
				
				if(hasilDot>0){
					isValid = false;
					break;
				}
			}
			if(isValid){break;}
		}
		if(isValid){listIdx.pb(i+1);}
	}
	int banyak = listIdx.size();
	printf("%d\n",banyak);
	for(i=0;i<banyak;i++){
		printf("%d\n",listIdx[i]);
	}
	return 0;
};