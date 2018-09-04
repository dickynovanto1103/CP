// A C++ Program to find length of the Longest Common
// Increasing Subsequence (LCIS)
#include<bits/stdc++.h>
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

 
// Returns the length and the LCIS of two
// arrays arr1[0..n-1] and arr2[0..m-1] and
// prints LCIS

const int maxn = 503;

ll arr1[maxn], arr2[maxn];

ll lcis[maxn];

int LCIS(int n,int m)
{
    // table[j] is going to store length of LCIS
    // ending with arr2[j]. We initialize it as 0,
    int table[maxn], parent[maxn];
    for (int j=0; j<m; j++)
        table[j] = 0;
 
    // Traverse all elements of arr1[]
    for (int i=0; i<n; i++)
    {
        // Initialize current length of LCIS
        int current = 0, last = -1;
 
        // For each element of arr1[], trvarse all
        // elements of arr2[].
        for (int j=0; j<m; j++)
        {
            // If both the array have same elements.
            // Note that we don't break the loop here.
            if (arr1[i] == arr2[j])
            {
                if (current + 1 > table[j])
                {
                    table[j] = current + 1;
                    parent[j] = last;
                }
            }
 
            /* Now seek for previous smaller common
               element for current element of arr1 */
            if (arr1[i] > arr2[j])
            {
                if (table[j] > current)
                {
                    current = table[j];
                    last = j;
                }
            }
        }
    }
 
    // The maximum value in table[] is out result
    int result = 0, index = -1;
    for (int i=0; i<m; i++)
    {
        if (table[i] > result)
        {
           result = table[i];
           index = i;
        }
    }
 
    // LCIS is going to store elements of LCIS
    
    for (int i=0; index != -1; i++)
    {
        lcis[i] = arr2[index];
        index = parent[index];
    }
 
    // cout << "The LCIS is : ";
     
    return result;
}

int main() {
    freopen("gcis.in", "r", stdin);
    freopen("gcis.out", "w", stdout);

    int n,m,i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%lld",&arr1[i]);
    }
    scanf("%d",&m);
    for(i=0;i<m;i++){
        scanf("%lld",&arr2[i]);
    }

    int pjg = LCIS(n,m);
    printf("%d\n", pjg);
    for(i=pjg-1;i>=0;i--){
        if(i < (pjg-1)){printf(" ");}
        printf("%lld", lcis[i]);
    }
    printf("\n");
    return 0;
}