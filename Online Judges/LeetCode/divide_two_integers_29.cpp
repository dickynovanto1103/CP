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

const long long minInt32 = -2147483648;
const long long maxInt32 = 2147483647;

class Solution {
public:
    int divide(int dividendd, int divisorr) {
        int cntNeg = 0;
        long long dividend = dividendd;
        long long divisor = divisorr;
        if(dividend < 0) {dividend = -dividend; cntNeg++;}
        if(divisor < 0) {divisor = -divisor; cntNeg++;}

        if(dividend < divisor) {return 0;}
        else{
            int leftShift = getMaxLeftShift(dividend, divisor);
            // printf("leftShift: %d\n", leftShift);
            long long ans = 0;
            for(int i=leftShift;i>=0;i--){
                if((dividend - (divisor << i)) >= 0) {
                    dividend -= (divisor << i);
                    ans += (1LL<<i);
                }
            }

            long long finalAns = (cntNeg % 2 == 1 ? -ans : ans);
            printf("final ans: %lld\n", finalAns);
            if(finalAns < minInt32) {return minInt32;}
            else if(finalAns > maxInt32) {return maxInt32;}
            else return finalAns;
        }
    }

    int getMaxLeftShift(long long dividend, long long divisor) {
        // printf("dividend: %lld divisor: %lld\n", dividend, divisor);
        int ans = 0;
        for(int i=0;;i++){
            if((divisor << i) > dividend) {
                return ans;
            }
            ans = i;
        }

        return ans;
    }
};

int main() {
    Solution s;
    printf("%d\n", s.divide(minInt32, -1));

    return 0;
}