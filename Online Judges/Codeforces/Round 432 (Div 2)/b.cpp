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

double degToRad(int a) {
	return (a/180.0)*pi;
}

ll x[3], y[3];
struct point {
	ll x, y;
};

int main(){
	
	int i,j;
	
	// int derajat[] = {0,30,45,60,90,120,135,150,180,210,225,240,270,300,315,330,360};
	
	for(i=0;i<3;i++){
		scanf("%lld %lld",&x[i],&y[i]);
		
	}
	point vecA, vecB;
	vecA.x = x[1] - x[0]; vecA.y = y[1] - y[0];
	vecB.x = x[2] - x[0]; vecB.y = y[2] - y[0];

	ll cross = vecA.x*vecB.y - vecA.y*vecB.x;

	
	if(cross==0){//collinear
		printf("No\n");
		return 0;
	}
	point vecC;
	vecC.x = x[2] - x[1]; vecC.y = y[2] - y[1];
	ll panjangC = vecC.x*vecC.x+ vecC.y*vecC.y;	
	ll panjangA = vecA.x*vecA.x + vecA.y*vecA.y;
	if(panjangA == panjangC) {
		printf("Yes\n");
	}else{
		printf("No\n");
	}


	return 0;
};