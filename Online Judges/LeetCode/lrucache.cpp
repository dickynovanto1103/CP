#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int key, int val) {
        this->key = key;
        this->val = val;
        prev = NULL;
        next = NULL;
    }

};

class LRUCache {
public:
    LRUCache(int capacity) {
        ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
        this->capacity = capacity;
        sz = 0;
        head = tail = NULL;
    }
    
    int get(int key) {
        if(mapper.find(key) == mapper.end()) {
            return -1;
        }

        Node* node = mapper[key];
        removeNode(node);
        putNodeAtTail(node);


        return node->val;
    }
    
    void put(int key, int value) {
        if(mapper.find(key) == mapper.end()) {
            Node* newNode = new Node(key, value);
            mapper[key] = newNode;

            if(sz == capacity) {
                mapper.erase(head->key);
                removeNode(head);
                putNodeAtTail(newNode);

            }else{
                putNodeAtTail(newNode);
            }
        }else{
            //found, then remove node, move node to end
            Node* node = mapper[key];
            removeNode(node);

            node->val = value;
            putNodeAtTail(node);
        }
    }

    void removeNode(Node* node) {
        sz--;
        if(sz == 0) {
            head = NULL;
            tail = NULL;

            return;
        }

        if(node == head) {
            //change head
            Node* nextHead = head->next;
            head->next = NULL;
            nextHead->prev = NULL;
            head = nextHead;

        }else if(node == tail){
            Node* prevTail = tail->prev;
            tail->prev = NULL;
            prevTail->next = NULL;
            tail = prevTail;

        }else{
            node->prev->next = node->next;
            node->next->prev = node->prev;

            node->prev = NULL;
            node->next = NULL;
        }
    }

    void putNodeAtTail(Node* node) {
        sz++;
        if(sz == 1) {
            head = node;
            tail = node;
            return;
        }

        tail->next = node;
        node->prev = tail;
        tail = tail->next;
    }
    
private:
    int capacity;
    int sz;
    Node* head;
    Node* tail;
    unordered_map<int, Node*> mapper;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


int main() {
    int n = 3000;

    LRUCache* obj = new LRUCache(3000);
    for(int i=0;i<=500000;i++) {
        obj->put(i, i);
    }

    printf("%d\n", obj->get(1));
    obj->put(2, 2);
    printf("%d\n", obj->get(2));
    obj->put(1, 1);
    printf("%d\n", obj->get(1));
    obj->put(3, 3);
    printf("%d\n", obj->get(3));
    printf("%d\n", obj->get(2));
    printf("%d\n", obj->get(1));

    // Node* newNode = new Node(23);
    // printf("%d\n", newNode->val);
    return 0;
}