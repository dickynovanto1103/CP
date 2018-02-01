#include <cstdio>

using namespace std;

const int MAX = 1000001;
 
// Create an array for memoization
int f[MAX] = {0};
int m;
// Returns n'th fuibonacci number using table f[]
int fib(int n)
{
    // Base cases
    if (n == 0)
        return 0;
    if (n == 1)
        return (f[n] = 1);
 
    // If fib(n) is already computed
    if (f[n])
        return f[n];
 
    int k = (n & 1)? (n+1)/2 : n/2;
 
    // Applyting above formula [Note value n&1 is 1
    // if n is odd, else 0.
    f[n] = (n & 1)? ((fib(k)*fib(k) + fib(k-1)*fib(k-1)) + n-1)%m
           : ((2*fib(k-1) + fib(k))*fib(k)+ n-1)%m;
 
    return f[n];
}

int main(){
	int tc,n,i;
	scanf("%d",&tc);

	while(tc--){
		scanf("%d %d",&n,&m);
		printf("%d\n",fib(n));
		/*printf("array:");
		for(i=0;i<=n;i++){printf(" %d",a[i]);}*/
		printf("\n");
	}
	return 0;
}