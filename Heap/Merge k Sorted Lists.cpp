#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    struct Compare{
        bool operator()(ListNode* a,ListNode* b){
            return a->val > b->val;
        }
    };
    priority_queue<ListNode*,vector<ListNode*>,Compare> pq;
    for(ListNode* curr:lists){
        while(curr!=NULL){
            pq.push(curr);
            curr = curr->next;
        }
    }
    ListNode* temp = new ListNode(-1);
    ListNode* root = temp;
    while(!pq.empty()){
        temp->next = pq.top();
        temp = pq.top();
        pq.pop();
    }
    temp->next = NULL;
    return root->next;
}
ListNode* createList(vector<int> vals) {
    ListNode* head = new ListNode(vals[0]);
    ListNode* curr = head;

    for(int i = 1; i < vals.size(); i++) {
        curr->next = new ListNode(vals[i]);
        curr = curr->next;
    }
    return head;
}
int main()
{
    vector<ListNode*> lists;

    lists.push_back(createList({1,4,7}));
    lists.push_back(createList({2,5,8}));
    lists.push_back(createList({3,6,9}));

    ListNode* merged = mergeKLists(lists);

    while(merged != NULL) {
        cout << merged->val << " ";
        merged = merged->next;
    }

    return 0;
}