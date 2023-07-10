// solution to this Problem is
//     1. to use hashing to detect the cycle in the linked list
//     2. or use floyd cycle Detection

Test Case -------->>. 

    1 - 3 - 2 - 4 - 7 - 5 ---
        |                   |
        ---------------------


    1 - 3 - 4 - 5 - 6 - 4 - NULL


Naive -------------------->>>>
    Time ---------------->>>> O(N)
    Space---------------->>> O(N)

    #include<bits/stdc++.h>
    bool detectCycle(Node *head)
    {
        Node *dummy = head;
        map<Node*,int>mpp;
    
        while(dummy != NULL)
        {
            if(mpp.count(dummy))
            {
                return true;
            }
            else
            {
                mpp[dummy]++;   
            }
            dummy = dummy -> next;
        }
        return false;
    }

    
    



Optimal ---------------->>>>>>>>>>
    Time --------------->>>> O(N)
    Space ----------->>>>> O(1)

        bool detectCycle(Node *head)
        {
            Node *fast = head;
            Node *slow = head;
            while(fast && slow && fast -> next)
            {
                fast = fast -> next -> next;
                slow = slow -> next; 
                if(slow == fast) return true;
            }
            return false;
        }

