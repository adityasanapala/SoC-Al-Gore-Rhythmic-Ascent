#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//-------------------------------------iteratively----------------------------------------------------
ListNode* reverseList_iteratively(ListNode* head) {
    if(head == nullptr) return head;
    ListNode* a = head->next;
    head->next = nullptr;
    while(a != nullptr){
        ListNode* tmp = a;
        a = a->next;
        tmp->next = head;
        head = tmp;
    }
    return head;
    }

//------------------------------------------recursively---------------------------------------------
ListNode* reverseList_recursively(ListNode* head) {
    if(head == nullptr) return head;
    ListNode* tmp = reverseList_recursively(head->next);
    if(tmp == nullptr) return head;
    else{
    ListNode* ans = tmp;
    while(tmp->next != nullptr){tmp = tmp->next;}
    tmp->next = head;
    head->next = nullptr;
    return ans;}
}

void printlist(ListNode* head){
    while(head != nullptr){
        cout << head->val << " ";
        head = head->next;
    }
    cout << "\n";}

int main()
{
ios::sync_with_stdio(0);
cin.tie(0);

int n;
cin >> n;
ListNode* head = nullptr;

while(n != -1){
    ListNode* x = new ListNode(n);
    if(head == nullptr) head =x;
    else{ x->next = head;head = x;}
    cin >> n;
}

printlist(head);
head = reverseList_recursively(head);
printlist(head);
}