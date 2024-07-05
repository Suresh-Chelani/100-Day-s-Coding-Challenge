#include <iostream>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

 class Solution
 {
 public:
     ListNode *mergeNodes(ListNode *head)
     {
         if (head->val == 0)
             head = head->next;
         if (!head->next)
             return new ListNode(head->val);

         ListNode *ans = new ListNode(0);
         ListNode *start = ans;
         int curr_sum = 0;
         while (head != nullptr)
         {
             if (head->val != 0)
             {
                 curr_sum += head->val;
             }
             else
             {
                 ListNode *node = new ListNode(curr_sum);
                 ans->next = node;
                 ans = ans->next;
                 ans->next = nullptr;
                 curr_sum = 0;
             }
             head = head->next;
         }
         return start->next;
     }
 };
