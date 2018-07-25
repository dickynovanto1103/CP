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
typedef pair<ii,int> iii;
typedef vector<ii> vii;
typedef vector<iii> viii;

const int maxn = 1e5 + 5;

string T; //input string
int n;
int RA[maxn], tempRA[maxn]; // rank array and temp
int SA[maxn], tempSA[maxn]; //suffix array and its temp
int c[maxn]; //for counting radix sort

string P; //the pattern string (for string matching)
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

int compareString(string kata1, string kata2, int bil) {
	int pjg = bil;
	for(int i=0;i<pjg;i++){
		char kar1 = kata1[i], kar2 = kata2[i];
		if(kar1 != kar2){
			return kar1 - kar2;
		}
	}
	return 0;
}

ii stringMatching() {//string matching in O(m log n)
	int lo = 0, hi = n-1, mid = lo; //valid matching = [0..n-1]
	string tempText;

	while(lo < hi) { //find lower bound
		mid = (lo+hi)/2;
		tempText = "";
		for(int i=SA[mid];i<n;i++){
			tempText+=T[i];
		}
		int res = compareString(tempText, P, m);
		if(res >= 0) {hi = mid;}
		else{lo = mid+1;}
	}
	tempText = "";
	for(int i=SA[lo];i<n;i++){
		tempText+=T[i];
	}	
	if(compareString(tempText, P, m) != 0){ return ii(-1,-1);}
	ii ans; ans.first = lo;
	lo = 0; hi = n-1; mid = lo;

	while(lo < hi) {
		mid = (lo+hi) / 2;
		tempText="";
		for(int i=SA[mid];i<n;i++){
			tempText+=T[i];
		}
		int res = compareString(tempText, P, m);
		if(res > 0){ hi = mid;}
		else{lo = mid+1;}
	}
	tempText = "";
	for(int i=SA[hi];i<n;i++){
		tempText+=T[i];
	}
	if(compareString(tempText, P, m) != 0){hi--;} //special case
	ans.second = hi;
	return ans;
} //return the lower/upperboud as first/second item of the pair respectively

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

struct data{
	string kata;
	int label, panjang, urutan;
};

bool cmpUrutKata(data a, data b){
	return a.kata < b.kata;
}

bool cmp(iii a, iii b){
	if(a.first.first == b.first.first) {
		if(a.first.second == b.first.second) {
			return a.second < b.second;
		}else{
			return a.first.second < b.first.second;
		}
	}else{
		return a.first.first < b.first.first;
	}
}

data pas[20010];

viii listAns;

int main(){
	int i,j,q;
	scanf("%d",&n);
	
	int pemilik[maxn];
	j = 0;
	T="";
	for(i=0;i<n;i++){
		string a;
		cin>>a;
		
		pas[i].kata = a;
		
		
		
		pas[i].label = i+1;

		
		pas[i].panjang = a.length();
		
		T+=a;
		T+="$";
		cout<<"T jd: "<<T<<endl;
		
		int idx = j;
		
		for(j=idx;j<(idx+a.length()+1);j++){
			pemilik[j] = i;
		}
		printf("i:%d\n",i);
	}	
	
	n = T.length();

	sort(pas, pas+n, cmpUrutKata);
	for(i=0;i<n;i++){
		pas[i].urutan = i+1;
	}
	
	cout<<"T jd: "<<T<<endl;

	constructSA();
	computeLCP();

	for(i=0;i<T.length();i++){
		printf("%2d\t",SA[i]);
		for(j=SA[i];j<T.length();j++){
			printf("%c",T[j]);
		}
		printf("\n");
	}
	printf("n: %d\n",n);

	scanf("%d",&q);
	while(q--){
		cin>>P;
		m = P.length();
		ii ans = stringMatching();
		printf("ans: %d %d\n",ans.first, ans.second);
		for(i=ans.first;i<=ans.second;i++){
			int idxPemilik = pemilik[SA[i]];
			printf("i: %d SA[%d]: %d idxPemilik: %d\n",i,i, SA[i], idxPemilik);
			int panjang = pas[idxPemilik].panjang;
			int label = pas[idxPemilik].label;
			int urutan = pas[idxPemilik].urutan;
			listAns.pb(make_pair(ii(panjang, urutan), label));
			printf("yang dipush; panjang: %d urutan: %d label: %d\n",panjang, urutan, label);
		}
		sort(listAns.begin(), listAns.end(), cmp);
		if(listAns.size() < 10){
			if(listAns.size() == 0){
				printf("-1\n");
			}else{
				for(i=0;i<listAns.size();i++){
					if(i){printf(" ");}
					printf("%d",listAns[i].second);
				}	
				printf("\n");
			}
			
		}else{
			for(i=0;i<10;i++){
				if(i){printf(" ");}
				printf("%d",listAns[i].second);
			}
			printf("\n");
		}
		listAns.clear();
	}

	return 0;
};