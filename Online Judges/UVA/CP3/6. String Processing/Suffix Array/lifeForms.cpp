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

char P[maxn]; //the pattern string (for string matching)
int m; //length of pattern

int Phi[maxn]; //for computing longest common prefix
int PLCP[maxn]; 
int LCP[maxn]; //LCP[i] stores the LCP between previous suffix T+SA[i-1] and current suffix T+SA[I]

void countingSort(int k) {
	int i,sum,maxi = max(300,n); //up to 255 ASCII number
	memset(c,0,sizeof c);
	for(i=0;i<n;i++) { //count the frequency of each integer rank
		if(i + k < n){c[RA[i+k]]++;}
		else{c[0]++;}
	}
	for(i=sum=0;i<maxi;i++) {
		int t = c[i]; c[i] = sum; sum+=t;
	}
	for(i=0;i<n;i++){//shuffle the suffix array if necessary
		tempSA[c[SA[i]+k < n? RA[SA[i]+k] : 0]++] = SA[i];
	}
	for(i=0;i<n;i++){//update the suffix array SA
		SA[i] = tempSA[i];
	}
}

void constructSA() {
	int i,k,r;
	for(i=0;i<n;i++){// initial ranking
		RA[i] = T[i];
	}
	for(i=0;i<n;i++){//initial suffix array 0..n-1
		SA[i] = i;
	}
	for(k=1;k<n;k<<=1) {//repeat sorting process log n times
		countingSort(k); //actually radix sort: sort based on the second item
		countingSort(0); //then (stable) sort based on the first item
		tempRA[SA[0]] = r = 0; //reranking; start from rank r = 0
		for(i=1;i<n;i++){//compare adjacent suffixes
			tempRA[SA[i]] = (RA[SA[i]] == RA[SA[i-1]] && RA[SA[i] + k] == RA[SA[i-1] + k]) ? r : ++r;
			//if same pair -> same rank r; otherwise increase r
		}
		for(i=0;i<n;i++){//update the rank array RA with tempRA
			RA[i] = tempRA[i];
		}
		if(RA[SA[n-1]] == n-1){break;} //just optimization
	}
}

void computeLCP() {
	int i,L;
	Phi[SA[0]] = -1; //default value
	for(i=1;i<n;i++){//compute Phi in O(n)
		Phi[SA[i]] = SA[i-1]; //remember which suffix is behind this suffix
	}
	for(i=L=0; i<n;i++) {//compute Permuted LCP in O(n)
		if(Phi[i] == -1){PLCP[i] = 0; continue;}//special case
		while(T[i+L] == T[Phi[i] + L]){
			L++; //L increased max n times
		}
		PLCP[i] = L;
		L = max(L-1,0); // L decreased max n times
	}
	for(i=0;i<n;i++){//compute LCP in O(n)
		LCP[i] = PLCP[SA[i]];//put the permuted LCP to the correct possition
	}
}

ii stringMatching() {//string matching in O(m log n)
	int lo = 0, hi = n-1, mid = lo; //valid matching = [0..n-1]
	while(lo < hi) { //find lower bound
		mid = (lo+hi)/2;
		int res = strncmp(T + SA[mid], P, m);
		if(res >= 0) {hi = mid;}
		else{lo = mid+1;}
	}

	if(strncmp(T + SA[lo], P, m) != 0){ return ii(-1,-1);}
	ii ans; ans.first = lo;
	lo = 0; hi = n-1; mid = lo;
	while(lo < hi) {
		mid = (lo+hi) / 2;
		int res = strncmp(T+SA[mid], P, m);
		if(res > 0){ hi = mid;}
		else{lo = mid+1;}
	}
	if(strncmp(T + SA[hi], P, m) != 0){hi--;} //special case
	ans.second = hi;
	return ans;
} //return the lower/upperboud as first/second item of the pair respectively

ii LRS() {//return a pair (the LRS length and its index)
	int i, idx = 0, maxLCP = -1;
	for(i=1;i<n;i++) {
		if(LCP[i] > maxLCP) {
			maxLCP = LCP[i], idx = i;
		}
	}
	return ii(maxLCP, idx);
}

int owner(int idx) {return (idx< n-m-1) ? 1: 2;}

ii LCS() { //return pair lcs length and its index
	int i, idx = 0, maxLCP = -1;
	for(i=1;i<n;i++){
		if(owner(SA[i]) != owner(SA[i-1]) && LCP[i] > maxLCP) {
			maxLCP = LCP[i], idx = i;
		}
	}
	return ii(maxLCP, idx);
}


int main(){
	int n,i,j;

	int pemilik[maxn];

	while(scanf("%d",&n), n){
		char delimiter = 0;
		memset(T, 0, sizeof T);
		for(i=0;i<n;i++){
			printf("i: %d\n",i);
			char temp[1000];
			scanf("%s",temp);
			for(j=0;j<strlen(temp);j++){
				temp[j]+=5;
			}
			printf("T sekarang: %s temp: %s\n",T, temp);
			strcat(T, temp);
			printf("T jadi: %s\n",T);
			char kar[1];
			kar[0] = delimiter;
			strcat(T, kar);
			
			printf("T akhir jadi: %s\n",T);
			delimiter++;

			

			
		}	
		n = strlen(T);
		constructSA();
		for(i=0;i<strlen(T);i++){
			printf("%2d\t",SA[i]);
			for(j=SA[i];j<strlen(T);j++){
				printf("%c",T[j]);
			}
			printf("\n");
		}
	}

	
	
	return 0;
};