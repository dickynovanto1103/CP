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

// returns min difference between max
// and min of any K-size subset
int minDifferenceAmongMaxMin(vector<int> arr, int N, int K)
{
    // sort the array so that close
    // elements come together.
    //sort(arr, arr + N);
 
    //  initialize result by a big integer number
    int res = INT_MAX;
 
    // loop over first (N - K) elements
    // of the array only
    for (int i = 0; i <= (N - K); i++)
    {
        //  get difference between max and min of
        // current K-sized segment
        int curSeqDiff = arr[i + K - 1] - arr[i];
        res = min(res, curSeqDiff);
    }
 
    return res;
}

int main(){
	int n,k,i,j;
	vi a;
	set<int> s;
	set<int>::iterator it2;
	vi::iterator it;
	scanf("%d %d",&n,&k);
	for(i=0;i<n;i++){
		int bil;
		scanf("%d",&bil);
		s.insert(bil);
	}
	// sort(a.begin(),a.end());
	// it = unique(a.begin(),a.end());
	// a.resize(distance(a.begin(),it));
	// int ukuranSekarang = a.size();
	for(it2=s.begin();it2!=s.end();it2++){
		int bil = *it2;
		a.pb(bil);
	}
	int ukuranSekarang = a.size();
	for(i=0;i<ukuranSekarang;i++){
		if(i){printf(" ");}
		printf("%d",a[i]);
	}
	printf("\n");
	if(ukuranSekarang<k){printf("0\n"); return 0;}
	int ans = minDifferenceAmongMaxMin(a,ukuranSekarang,k);
	printf("%d\n",ans);
	return 0;
};