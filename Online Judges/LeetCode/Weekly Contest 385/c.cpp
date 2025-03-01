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

// bool isprime[10000001];

int dr[] = {-1,-1,0,1,1,1,0,-1};
int dc[] = {0,1,1,1,0,-1,-1,-1};

class Solution {
public:
    vector<vector<int>> mat;
    int n,m;

    unordered_map<int, int> cnt;
    unordered_map<int, int>::iterator it;

    int mostFrequentPrime(vector<vector<int>>& mat) {
        // sieve(10000000);
        // int cntPrime = 0;
        // for(int i=0;i<=100;i++){
        //     if(isprime[i]) {
        //         cntPrime++;
        //     }
        // }

        // printf("cntPrime until 100: %d\n", cntPrime);
        this->mat = mat;
        
        n = mat.size();
        m = mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) {
                for(int k=0;k<8;k++){
                    formNum(i, j, dr[k], dc[k]);
                }
            }
        }

        int maksCnt = 0;
        int maksNum = -1;
        for(it=cnt.begin();it!=cnt.end();it++){
            if(maksCnt < it->second) {
                maksCnt = it->second;
                maksNum = it->first;
            }else if(maksCnt == it->second && maksNum < it->first) {
                maksNum = it->first;
            }
        }

        return maksNum;
    }

    void formNum(int startRow, int startCol, int dirRow, int dirCol) {
        int num = 0;
        while(startRow >= 0 && startRow < n && startCol >= 0 && startCol < m) {
            num *= 10;
            num += mat[startRow][startCol];
            if(num > 10 && checkIsPrime(num)) {
                cnt[num]++;
            }

            startRow += dirRow;
            startCol += dirCol;
        }
    }

    bool checkIsPrime(int num) {
        for(int i=2;i*i<=num;i++){
            if(num % i == 0) {
                return false;
            }
        }

        return true;
    }
};

void solve(){

}

int main(){
	// int tc = 1;
	// // scanf("%d",&tc);
	// while(tc--){
	// 	solve();
	// }

    int n,m;
    while(scanf("%d %d",&n,&m) != EOF) {
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                scanf("%d",&mat[i][j]);
                // printf("%d ", mat[i][j]);
            }
            // puts("");
        }

        Solution s;
        int ans = s.mostFrequentPrime(mat);
        printf("%d\n", ans);
    }

	return 0;
};