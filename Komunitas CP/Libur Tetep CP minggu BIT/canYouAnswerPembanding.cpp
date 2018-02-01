// =====================================================================================
//       Filename:  GSS1.cpp
//    Description:  
//        Created:  05/23/2013 06:41:42 PM
//         Author:  BrOkEN@!
// =====================================================================================
#include<fstream>
#include<iostream>
#include<sstream>
#include<bitset>
#include<deque>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<vector>
#include<algorithm>
#include<iterator>
#include<string>
#include<cassert>
#include<cctype>
#include<climits>
#include<cmath>
#include<cstddef>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
 
#define FOR(i,a,b) for(typeof((a)) i=(a); i <= (b) ; ++i)
#define FOREACH(it,x) for(typeof((x).begin()) it=(x).begin(); it != (x).end() ; ++it)
 
using namespace std;
 
typedef pair<int,int> PI;
typedef vector<PI> VI;
 
inline int max2(int a, int b) {return ((a > b)? a : b);}
inline int max3(int a, int b, int c) {return max2(a, max2(b, c));}
 
const int MAX = 1 << 16;
int a[MAX];
 
struct node
{
    int Sum,bestLeftSum,bestRightSum,bestSum;
     
    node split(node& l, node& r){
    } // No Need of Split Function
     
    node merge(node& l, node& r)
    {
        Sum = l.Sum + r.Sum;
        bestLeftSum = max( l.Sum + r.bestLeftSum , l.bestLeftSum );
        bestRightSum = max( r.Sum + l.bestRightSum , r.bestRightSum );
        bestSum = max( max( l.bestSum , r.bestSum) , l.bestRightSum + r.bestLeftSum );
    }
     
    node setValue(int val){
        Sum = bestLeftSum = bestRightSum = bestSum = val;
    }
};
 
node T[MAX << 1];
 
void init(int Node, int i, int j) {
    if(i==j) { // Initialize Leaf Nodes
        T[Node].setValue(a[i]);
        return;
    }else{ // Summerize Descendant Nodes Nodes
        int m = (i+j)/2;
        init(2*Node, i, m);
        init(2*Node+1, m+1, j);
        T[Node].merge(T[2*Node],T[2*Node+1]);
    }
}
 
void update(int Node, int i, int j,int idx, int val) { 
// Update element with index 'idx' in the range [i,j]
    if(i==j && i == idx) { // Update the LeafNode idx
        T[Node].setValue(val);
        return;
    }else{ // Summerize Descendant Nodes Nodes
        int m = (i+j)/2;
        if(idx <=m)
            update(2*Node, i, m, idx, val);
        else
            update(2*Node+1, m+1, j, idx, val);
        T[Node].merge(T[2*Node],T[2*Node+1]);
    }
}
 
void range_query(node& resultNode,int Node,int i, int j, int L, int R){ // Search for Node having interval info [L,R] in [i,j]; (i<=L<R<=j)
    if(i==L && j==R){
        resultNode = T[Node];
        return;
    }else{
        int m = (i+j)/2;
        if(R<=m)
            range_query(resultNode, 2*Node,  i, m, L, R);
        else if(L>m)
            range_query(resultNode, 2*Node+1, m+1, j, L, R);
        else{
            node left, right;
            range_query(left, 2*Node,  i, m, L, m);
            range_query(right, 2*Node+1, m+1, j, m+1, R);
            resultNode.merge(left,right);
        }
    }
}
 
 
int solve(){
 
    return 0;
}
 
 
int main(){
 
    int N=0,M=0;
    node res;
    scanf("%d",&N);
    FOR(i,0,N-1){
            scanf("%d", &a[i]);
    }
    init(1, 0, N-1);
    scanf("%d",&M);
    int x,y;
    FOR(i,0,M-1){
            scanf("%d%d",&x,&y);
                range_query(res, 1, 0, N-1, --x, --y);
                printf("%d\n", res.bestSum);
    }
 
    return 0;
}