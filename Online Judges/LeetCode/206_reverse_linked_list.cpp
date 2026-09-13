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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
    	if(head == NULL) {
    		return NULL;
    	}
    	ListNode* cur = head;
    	ListNode* next = cur->next;
    	cur->next = NULL;

    	while(next != NULL) {
    		ListNode* secondNext = next->next;
    		next->next = cur;
    		cur = next;
    		next = secondNext;
    	}

    	return cur;
    }
};

void printListNode(ListNode* list) {
	while(list != NULL) {
		printf("%d ", list->val);
		list = list->next;
	}
	puts("");
}

void solve(){
	Solution sol;
	ListNode* list = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));
	printListNode(sol.reverseList(list));
	list = new ListNode(1, new ListNode(2));
	printListNode(sol.reverseList(list));
	list = new ListNode(1);
	printListNode(sol.reverseList(list));
	printListNode(sol.reverseList(NULL));
}

int main(){
	int tc = 1;
	// scanf("%d",&tc);
	while(tc--){
		solve();
	}

	return 0;
};