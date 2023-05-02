//
// Created by 26236 on 2023/4/30.
//
#include <stdio.h>
#include <stdlib.h>
using namespace std;
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

struct listNode{
    int val;
    listNode *next;
    listNode(){
        this->val = 0;
        this->next = nullptr;
    }
    listNode(int x){
        this->val = x;
        this->next = nullptr;
    }
    listNode(int x, listNode* next){
        this->val = x;
        this->next = next;
    }
};

typedef struct listNode ListNode;
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2);
void printList(ListNode* list);

int main(){
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(4);
    node1->next = node2;
    node2->next = node3;
    ListNode* list1 = node1;

    ListNode* node4 = new ListNode(1);
    ListNode* node5 = new ListNode(3);
    ListNode* node6 = new ListNode(4);
    node4->next = node5;
    node5->next = node6;
    ListNode* list2 = node4;

    ListNode* my_merged = mergeTwoLists(list1, list2);
    printList(my_merged);
}

void printList(ListNode* list){
    while (list != nullptr){
        printf("%d ", list->val);
        list = list->next;
    }
    printf("\n");
}

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* curr1;
    ListNode* curr2;
    ListNode* res = nullptr;
    ListNode* head = nullptr;
    if (list1 == nullptr && list2 == nullptr){
        return nullptr;
    }
    else if (list1 == nullptr && list2 != nullptr){
        return list2;
    }
    else if (list1 != nullptr && list2 == nullptr){
        return list1;
    }
    else{
        //two lists are not empty
        curr1 = list1;
        curr2 = list2;
        while (curr1 != nullptr && curr2 != nullptr){
            if (curr1->val <= curr2->val){
                //then curr1 goes to the final list, and move on
                ListNode* Node_new = new ListNode(curr1->val);
                if (res == nullptr){
                    res = Node_new;
                    head = res;
                }
                else{
                    res->next = Node_new;
                    res = res->next;
                }
                curr1 = curr1->next;
            }
            else if (curr1->val > curr2->val){
                //then curr2 goes to the final list, and move on
                ListNode* Node_new = new ListNode (curr2->val);
                if (res == nullptr){
                    res = Node_new;
                    head = res;
                }
                else{
                    res->next = Node_new;
                    res = res->next;
                }
                curr2 = curr2->next;
            }
        }
        // one of them is exhausted
        if (curr1 == nullptr && curr2 != nullptr){
            // chain all the second list
            res->next = curr2;
        }
        else if (curr2 == nullptr && curr1 != nullptr){
            res->next = curr1;
        }
    }
    return head;
}