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

class FibonacciDiv2{
	public:
		int fib[100];
		int idxMaks;
		int find(int N){	
			if(N==1){return 0;}
			generateFib();
			//printf("idxMaks: %d\n",idxMaks);
			int idx = lower_bound(fib,fib+idxMaks,N) - fib;
			int bil1 = fib[idx];
			int bil2 = fib[idx-1];
			//printf("bil1: %d bil2: %d\n",bil1,bil2);
			return min(abs(bil1-N),abs(bil2-N));
		}
		void generateFib(){
			fib[0] = 0;
			fib[1] = 1;
			int i;
			for(i=2;;i++){
				fib[i] = fib[i-1] + fib[i-2];
				if(fib[i]>1000000){break;}
			}
			idxMaks = i;
		}
};

int main(){
	FibonacciDiv2 a;
	int ans = a.find(5);
	printf("%d\n",ans);
	return 0;
}