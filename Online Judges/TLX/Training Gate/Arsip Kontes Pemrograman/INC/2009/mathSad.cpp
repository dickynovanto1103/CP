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

int power(int a, int b){
	if(b==0){return 1;}
	else{
		if(b%2==1){return a*power(a,b-1);}
		else{
			int temp = power(a,b/2);
			return temp*temp;
		}
	}
}

int main(){
	int a,b,c,d;
	int x,y,z,i,j;
	while(scanf("%d %d %d %d",&a,&b,&c,&d)!=EOF){
		//cari x;
		// printf("a: %d b: %d c: %d d: %d\n",a,b,c,d);
		bool found = false;
		for(i=0;;i++){
			x = i;
			y = x*x-d;
			if(y<0){continue;}
			if(y>=(1<<16)){
				break;
			}
			if((power(x+y,b) + y)==c){
				z = a - x*x - y*y;
				if(z<0){continue;}
				printf("%d %d %d\n",x,y,z);
				found = true;
				break;
			}
			if(found){break;}
		}
		if(!found){printf("No solution\n");}
	}
	return 0;
};