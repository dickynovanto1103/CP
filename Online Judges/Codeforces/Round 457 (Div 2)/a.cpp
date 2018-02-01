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

bool isLucky(int h, int m){
	while(h>0){
		int bil = h%10;
		if(bil==7){return true;}
		h/=10;
	}
	while(m>0){
		int bil = m%10;
		if(bil==7){return true;}
		m/=10;
	}
	return false;
}

int main(){
	int x,h,m;
	scanf("%d",&x);
	scanf("%d %d",&h,&m);
	int cnt = 0;
	while(!isLucky(h,m)){
		m-=x;
		if(m<0){m+=60; h--;}
		if(h<0){h+=24;}
		cnt++;
	}
	printf("%d\n",cnt);
	return 0;
};