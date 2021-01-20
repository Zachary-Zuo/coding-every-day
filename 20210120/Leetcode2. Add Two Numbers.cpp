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
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *result = new ListNode;
        ListNode *head = result;
        int len = 1;
        while (l1 != nullptr && l2 != nullptr)
        {
            result->val += l1->val + l2->val;
            l1 = l1->next;
            l2 = l2->next;
            len++;
            result->next = new ListNode;
            if (result->val >= 10)
            {
                result->val -= 10;
                result->next->val = 1;
            }
            result = result->next;
        }

        while (l1 != nullptr)
        {
            result->next = new ListNode;
            result->val += l1->val;
            if (result->val >= 10)
            {
                result->val -= 10;
                result->next->val = 1;
            }
            result = result->next;
            len++;
            l1 = l1->next;
        }
        while (l2 != nullptr)
        {
            result->next = new ListNode;
            result->val += l2->val;
            if (result->val >= 10)
            {
                result->val -= 10;
                result->next->val = 1;
            }
            result = result->next;
            len++;
            l2 = l2->next;
        }
        if (result->val == 0)
        {
            result = head;
            for (int i = 0; i < len; i++)
            {

                if (i == len - 2)
                {
                    delete result->next;
                    result->next = nullptr;
                    break;
                }
                result = result->next;
            }
        }
        return head;
    }
};