Simple Problem ----------->>> 
    Time ------------->>>> O(1)
    Space -------------->>> O(1)


        #include <bits/stdc++.h>
        void deleteNode(LinkedListNode<int> * node) {
        
            LinkedListNode<int> *del = node -> next;
        
            node -> data = node -> next -> data;
            node -> next = node -> next -> next;   
        
            delete del;
        }
          
        
        
        
