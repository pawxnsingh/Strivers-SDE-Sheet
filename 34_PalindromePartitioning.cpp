Optimal Solution  ------------------>>>
    Time ------------------->>> O(N)
    Space ----------------->>> O(1)

    LinkedListNode<int>* Middle(LinkedListNode<int> *head)
    {
        LinkedListNode<int> *slow = head;
        LinkedListNode<int> *fast = head;
        while(fast != NULL && fast -> next != NULL)
        {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
    }
    bool isPalindrome(LinkedListNode<int> *head)
    {
        if(head == NULL || head -> next == NULL) return true;
        // find the Middle Element
        LinkedListNode<int> *MidNode = Middle(head);
        // do the reverse of the half of the linked list
        LinkedListNode<int> *prev = NULL;
        LinkedListNode<int> *curr = MidNode;
        LinkedListNode<int> * temp = NULL;
        while(curr != NULL)
        {
            temp = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = temp;
        }
        LinkedListNode<int> *right = prev;
        LinkedListNode<int> *left = head;
        while(right != NULL)
        {
            if(left -> data != right -> data){
                return false;
            }
            left = left -> next;
            right = right -> next;
        }
        return true;
    }
  
