// User function template for C++
/*

                      ℍ𝕒𝕡𝕡𝕪 𝕚𝕟𝕕𝕖𝕡𝕖𝕟𝕕𝕖𝕟𝕔𝕖 𝕕𝕒𝕪


*/
// 1 -> 2 -> 3 -> 4 -> 5 -> null
#include <iostream>

using namespace std;
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};


class Solution {
  public:
    Node* reverse(Node* h1){
        Node* prv = nullptr;
        Node* curr = h1;
        Node* nxt = nullptr;
        while (curr != nullptr){
            nxt = curr -> next;
            curr -> next = prv;
            prv = curr;
            curr = nxt;
        }
        
        return prv;
    }
    Node* addOne(Node* head) {
       Node* revLink = reverse(head);
       
       Node* trv = revLink;
       Node* prv = nullptr;
       int carry = 0;
       while (trv != nullptr){
           if (trv->data + 1 > 9){
               carry = 1;
               trv->data = 0;
           }
           else{
               trv -> data += 1;
               carry = 0;
               break;
           }
           prv = trv;
           trv = trv->next;
       }
       if (carry){
           Node* node = new Node(carry);
           prv -> next = node;
           node -> next = nullptr;
       }
       
       return reverse(revLink);
    }
};