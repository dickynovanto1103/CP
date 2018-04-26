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
	int i,j,n;
	string kata;
	cin>>kata;
	n = kata.length();
	string word1, word2;

	word1 = kata.substr(0, n/2);
	word2 = kata.substr(n/2, n/2);
	// cout<<word1<< " "<<word2<<endl;
	ll sum = 0;
	for(i=0;i<n/2;i++){
		sum+=(word1[i]-'A');
	}
	// printf("sum: %lld\n",sum);
	for(i=0;i<n/2;i++){
		int bil = word1[i]-'A';
		bil+=sum;
		bil%=26;
		word1[i] = bil;
		// printf("i: %d bil: %d\n",i,bil);
	}

	sum = 0;
	for(i=0;i<n/2;i++){
		sum+=(word2[i]-'A');
	}

	// printf("\n");
	// printf("sum kedua: %lld\n",sum);
	for(i=0;i<n/2;i++){
		int bil = word2[i]-'A';
		bil+=sum;
		bil%=26;
		word2[i] = bil;
		// printf("i: %d bil: %d\n",i,bil);
	}

	for(i=0;i<n/2;i++){
		word1[i] += (word2[i]);
		word1[i]%=26;
	}
	for(i=0;i<n/2;i++){
		printf("%c",word1[i]+'A');
	}
	printf("\n");

	return 0;
};