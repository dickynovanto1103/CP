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

const int maxn = 1e5 + 5;
char T[maxn]; //input string
int n;
int RA[maxn], tempRA[maxn]; // rank array and temp
int SA[maxn], tempSA[maxn]; //suffix array and its temp
int c[maxn]; //for counting radix sort

void countingSort(int k) {
	int i,sum,maxi = max(300,n); //up to 255 ASCII number
	memset(c,0,sizeof c);
	for(i=0;i<n;i++) {
		if(i + k < n){c[RA[i+k]]++;}
		else{c[0]++;}
	}
	for
}

int main(){

	return 0;
};