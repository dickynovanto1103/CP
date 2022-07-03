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
// typedef __int128_t lll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int mod = 1e9 + 7;

class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int ans = 0;

        memset(cnt, 0, sizeof cnt);
        int n = arr.size();
        sort(arr.begin(), arr.end());
        for(int i=0;i<=100;i++){
        	beginEnd[i] = ii(-1,-1);
        }

        for(int i=0;i<n;i++) {
        	int bil = arr[i];
        	if(beginEnd[bil] == ii(-1,-1)) {
        		beginEnd[bil] = ii(i, i);
        	}else{
        		beginEnd[bil] = ii(beginEnd[bil].first, i);
        	}

        	cnt[bil]++;
        }

        for(int i=0;i<n;i++){
        	for(int j=i+1;j<n;j++){
        		int sumNow = arr[i] + arr[j];
        		if(sumNow > target) {
        			break;
        		}
        		
        		int sisa = target - sumNow;
        		if(sisa < arr[j]) {
        			break;
        		}

        		if(beginEnd[i] == ii(-1,-1)) {
        			continue;
        		}

        		if(sisa > arr[j]) {
        			ans += (beginEnd[sisa].second - beginEnd[sisa].first + 1);
        			ans %= mod;
        			continue;
        		}

        		

        		int endIdx = beginEnd[sisa].second;

        		// int idxAwal = lower_bound(arr.begin() + j + 1, arr.end(), sisa) - arr.begin();
        		// int idxAkhir = upper_bound(arr.begin() + j + 1, arr.end(), sisa) - arr.begin();
        		ans += (endIdx - (j+1) + 1);
        		ans %= mod;
        	}
        }

        return ans;
    }
private:
	int cnt[301];
	ii beginEnd[301];
};

int main(){
	int n, target;
	while(cin>>n>>target) {
		vi a(n);
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}

		Solution sol;
		cout<<sol.threeSumMulti(a, target)<<endl;
	}
	
	return 0;
};