/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = NULL;
        // 使用指针的指针：为最后一个节点的next指针（初始为head指针）的地址
        ListNode** tmp = &head;
        int carry = 0;
        int sum = 0;
        while (l1 != NULL || l2 != NULL) {
            // 使用一个函数避免各种NULL判断
            int x = getValAndMoveNext(l1);
            int y = getValAndMoveNext(l2);
            sum = carry + x + y;
            carry = sum / 10;
            ListNode* node = new ListNode(sum % 10);
            *tmp = node;
            tmp = &node->next;
        }
        if (carry != 0) {
            ListNode* node = new ListNode(carry);
            *tmp = node;
        }
        return head;
    }
private:
    int getValAndMoveNext(ListNode* &l) {
        if (l == NULL) {
            return 0;
        } else {
            int value = l->val;
            l = l->next;
            return value;
        }
    }
};
