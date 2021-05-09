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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define debug if(true)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

double squareRoot(double n) {
	double guess = 1;
	for(int i=0;i<100;i++){
		guess = (guess + (n / guess)) / 2.0;
		printf("guess: %lf\n", guess);
	}
	return guess;
}

bool checkEqual(double a, double b){
	return fabs(a - b) < eps;
}

int main(){
	printf("Input one number: ");
	int n;
	scanf("%d",&n);

	printf("%lf\n", sqrt(n));
	printf("sqrt sendiri: %lf\n", squareRoot(n));
	if(!checkEqual(sqrt(n), squareRoot(n))) {
		assert(false);
	}
	
	return 0;
};