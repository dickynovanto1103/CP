#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
const int mod = 1e9 + 7;
int arr[100010];
ll counter[100010];

ll countSub(int n)
{
    // count[] array is used to store all sub-
    // sequences possible using that digit
    // count[] array covers all the digit
    // from 0 to 9
    memset(counter,0,sizeof counter);
 
    // scan each digit in arr[]
    for (int i=0; i<n; i++)
    {
        // count all possible sub-sequences by
        // the digits less than arr[i] digit
        for (int j=arr[i]-1; j>=0; j--)
            counter[arr[i]] += counter[j];
        	counter[arr[i]]%=mod;
 
        // store sum of all sub-sequences plus
        // 1 in count[] array
        counter[arr[i]]++;
    }
 
    // now sum up the all sequences possible in
    // count[] array
    ll result = 0;
    for (int i=0; i<10; i++)
        result += counter[i];
    	if(result > mod){result%=mod;}
 
    return result;
}

int main() {
	int n,i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++){scanf("%d",&arr[i]);}
	ll ans = countSub(n) + 1;
	if(ans>=mod){ans%=mod;}
	cout<<ans<<endl;
	return 0;
}