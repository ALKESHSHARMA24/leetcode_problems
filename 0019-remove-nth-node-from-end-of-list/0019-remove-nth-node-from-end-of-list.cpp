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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        //Two - pointers approach using n fixed length 

        ListNode* slow = head ;
        ListNode* fast = head ;

        // if( n )
        for(int i = 1 ; i <= n ; i ++){
            fast = fast -> next;
        }

        if(fast == NULL ) {
            head = head -> next ;
            return head ;
        }

        while(fast -> next ){
            slow = slow -> next ;
            fast = fast -> next ;
        }
        ListNode* deleteNode = slow -> next ;
        slow -> next = slow -> next -> next ;
        delete(deleteNode);
        return head ;
    }
};