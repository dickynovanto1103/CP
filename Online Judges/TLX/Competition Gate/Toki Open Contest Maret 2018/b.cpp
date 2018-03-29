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
	string ans = "";
	int n,a,b;
	scanf("%d %d %d",&n,&a,&b);
	if(n > (a+b)/2){printf("TIDAK MUNGKIN\n"); return 0;}
	if(n < (a+b)/3){printf("TIDAK MUNGKIN\n"); return 0;}
	//simulasi
	bool valid = true;
	while(true) {
		if(n==0) {break;}
		if(a < 0 || b < 0){valid = false; break;}
		if(n>(a+b)/2){
			//ambil 3
			// printf("halo n: %d\n",n);
			if(a>b){
				a-=2;
				b--;
				ans+="SRS";
			}else {
				b-=2;
				a--;
				ans+="RSR";
			}
			// printf("a jadi: %d b jd: %d\n",a,b);
			n--;
		}else{
			// if(n<(a+b)/2){valid = false; break;}
			if((a+b)%2==0){
				if(n==(a+b)/2) {
					if(a>b) {
						a-=2;
						ans+="SS";
					}else{
						b-=2;
						ans+="RR";
					}
					n--;
				}else{
					valid = false; break;
				}
			}else{
				if(a>b){
					a-=2;
					b--;
					ans+="SRS";
				}else{
					b-=2;
					a--;
					ans+="RSR";
				}
				n--;
			}
		}
	}
	if(a==0 && b==0){valid = true;}
	else{
		// printf("masuk sini\n");
		valid = false;
	}
	if(valid){cout<<ans<<endl;}
	else{printf("TIDAK MUNGKIN\n");}

	return 0;
};