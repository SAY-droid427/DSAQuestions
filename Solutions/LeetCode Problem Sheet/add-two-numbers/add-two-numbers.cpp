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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        //Declare a Empty Resultant Head Pointer
        ListNode* res = NULL;
        ListNode* prev = NULL;
        
        //Declare a Temp Node
        ListNode* temp;
        
        //Variables to Store Sum & Carry Value
        int sum;
        int carry = 0;
        
        
        //While None of the Lists Are Empty
        while(l1!=NULL || l2!=NULL)
        {
            //Add the Values of l1 & l2 to sum
            sum = carry + (l1?l1->val:0) + (l2?l2->val:0);
            
            //Calculate Carry as 1 or 0
            carry = (sum>=10)?1:0;
            
            //Bring Sum within 10
            sum = sum%10;
            
            //Declare a New Node with Sum as Value
            temp = new ListNode(sum);
            
            //Initialize Resultant Linked List with
            //Temp as Head Pointer
            if(res == NULL)
                res = temp;
            
            //If Already Initialized
            //Make prev point to temp
            //as next value
            else
                prev->next = temp;
            //Assign Temp as prev's
            //value
            prev = temp;
            
            
            //Proceed to Next Values
            if(l1)
                l1 = l1->next;
            if(l2)
                l2 = l2->next;
            
        }
        
        //If Carry is 1 initialize a new node to
        //Temp with value Carry
        if(carry>0)
            temp->next = new ListNode(carry);
        
        
        return res;
    }
};