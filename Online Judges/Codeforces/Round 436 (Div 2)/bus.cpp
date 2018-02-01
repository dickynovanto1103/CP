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
	int a,b,f,k;
	scanf("%d %d %d %d",&a,&b,&f,&k);
	double progress = 0.5;
	//if(f>b){printf("-1\n"); return 0;}
	int capacity = b-f;

	if(capacity<0){printf("-1\n"); return 0;}
	int minim1 = 2*f, minim2 = 2*(a-f);
	// if(k>1){
	// 	if((b<minim1 || b<minim2)){printf("-1\n"); return 0;}
	// }
	
	int counter = 0;
	bool keKanan = true;
	// printf("capacity awal: %d\n",capacity);
	// printf("minim1: %d minim2: %d k: %d\n",minim1,minim2,k);
	bool foundSalah = false;
	while(k-progress>0.5){
		if(keKanan){
			if(capacity>=minim2){
				capacity-=minim2;
				// printf("cukup klo dikurangin %d\n",minim2);
				// printf("capacity jd: %d\n",capacity);
			}
			else{
				counter++; capacity=b; capacity-=minim2;
				if(capacity<0){foundSalah = true; break;}
				// printf("counter jd: %d capacity jd: %d\n",counter,capacity);
			}
			keKanan = false;
			progress+=1.0;
		}else{
			if(capacity>=minim1){
				capacity-=minim1;
				// printf("cukup klo dikurangin %d\n",minim1);
				// printf("capacity jd: %d\n",capacity);
			}
			else{
				counter++; capacity=b; capacity-=minim1;
				if(capacity<0){foundSalah = true; break;}
				// printf("counter jd: %d capacity jd: %d\n",counter,capacity);
			}
			keKanan = true;
			progress+=1.0;
		}
		//printf("progress skrg: %.1lf\n",progress);
	}
	if(keKanan){
		if(capacity>=(a-f)){capacity-=(a-f);}
		else{
			counter++; capacity=b; capacity-=(a-f);
			if(capacity<0){foundSalah = true;}
		}
		keKanan = false;
	}else{
		if(capacity>=f){capacity-=f;}
		else{
			counter++; capacity=b; capacity-=f;
			if(capacity<0){foundSalah = true;}
		}

		keKanan = true;
	}
	if(foundSalah){printf("-1\n");}
	else{printf("%d\n",counter);}
	
	return 0;
};