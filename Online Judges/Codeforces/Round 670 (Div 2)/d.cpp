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

int main(){
	//rough idea: 
	// 1. if q = 0, then we can do binary search of the answer and place the answer at the start of C (since C is non-increasing) and at the end of B (since B is non-decreasing)
	// then we can get the value of the other array element, then try simulating by iterating through the array and fill array with one of 2 possibilities (using previous value of B or C), then check whether the condition is still fulfilled
	// if we put the number to be so big, it is always possible to construct arrays B and C

	//the next step is how to get the value faster for each query..should be O(log(n)) / O(1) per query

	
	return 0;
};