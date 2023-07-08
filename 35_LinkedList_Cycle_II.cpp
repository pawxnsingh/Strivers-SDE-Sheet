intuition ---------->>>>
    slow = l1 + l2
    fast = l1 + l2 + nC
    fast pointer travel twice the slow pointer

    2(L1+L2) = L1 + L2 + NC
    L1 + L2 = nC
        L1 = nC - L2
        Rest of the distance can be covered by l1
    






BruteForce-------------->>>>>>>>
    Time -------------->>>> O(N)
    Space ------------->>>> O(N)


        #include<bits/stdc++.h>
        Node *firstNode(Node *head)
        {   
            Node *dummy = head;
            map<Node*,int>mpp;
            while(dummy != NULL)
            {
                if(mpp.count(dummy))
                {
                    return dummy;
                }
                else
                {
                    mpp[dummy]++;
                }
                dummy = dummy -> next;
            }
            return NULL;
        }



Optimal --------------------->>>>>
    Time -------------->>>> O(N)
    Space ---------------->>>> O(1)


        Node *firstNode(Node *head)
        {
            if(head == NULL || head -> next == NULL) return NULL;   
            
            Node *slow = head;
            Node *fast = head;
            Node *entry = head;

            
            while(slow != NULL && fast != NULL && fast-> next != NULL)
            {
                slow = slow -> next;
                fast = fast -> next -> next;
                if(fast == slow){
                    while(entry != slow)
                    {
                        slow = slow-> next;
                        entry = entry -> next;
                    }
                }
                return entry;
            }
            return NULL;
        }
