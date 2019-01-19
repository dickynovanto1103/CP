#include <stdio.h>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
#define LL long long

int n;
char s[100005];
LL dp[100005][1<<4];
int a[100005];

int bmChar( char c ){
    if ( c == 'h' ) return (1<<1);
    if ( c == 'a' ) return (1<<2);
    if ( c == 'r' ) return (1<<3);
    if ( c == 'd' ) return (1<<4);
    return 0;
}

LL rek( int pos, int bm ){
    if ( bm & (1<<4) ) return 1e18;
    if ( pos == n ) return 0;

    LL &res = dp[pos][bm];
    if ( res != -1 ) return res;
    res = 1e18;

    res = min(res, rek(pos+1,((bm<<1) & bmChar(s[pos])) | bm));
    res = min(res, rek(pos+1,bm) + a[pos]);

    return res;
}

int main(){

    scanf("%d",&n);
    scanf("%s",&s);
    for ( int i = 0; i < n; i++ ) {
        scanf("%d",&a[i]);
        for ( int j = 0; j < (1<<4); j++ ) dp[i][j] = -1;
    }

    cout << rek(0,1) << endl;

    return 0;
}
