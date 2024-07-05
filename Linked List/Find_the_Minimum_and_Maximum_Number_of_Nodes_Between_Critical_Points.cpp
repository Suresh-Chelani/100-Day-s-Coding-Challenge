#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    bool is_critical(int a, int b, int c)
    {
        if (b < a && b < c)
            return true;
        if (b > a && b > c)
            return true;
        return false;
    }
    vector<int> nodesBetweenCriticalPoints(ListNode *head)
    {
        if (!head || !head->next || !head->next->next)
            return {-1, -1};

        ListNode *curr = head->next;
        ListNode *prv = head;
        ListNode *nxt = curr->next;
        int mx = INT_MIN;
        int mn = INT_MAX;
        int mx_prv = mx;
        int c = 2;
        int mnDiff = INT_MAX;
        while (nxt != nullptr)
        {

            if (is_critical(prv->val, curr->val, nxt->val))
            {
                mn = min(mn, c);
                mx_prv = mx;
                mx = max(mx, c);
                if (mx != mn)
                {
                    mnDiff = min(mnDiff, mx - mx_prv);
                }
            }

            c += 1;

            prv = curr;
            curr = curr->next;
            nxt = nxt->next;
        }
        if (mx_prv != INT_MIN && mx != INT_MIN && mn != INT_MAX)
            return {mnDiff, mx - mn};

        return {-1, -1};
    }
};