BruteForce ------------->>>> 
    Time ------------------->>>>>O(kN)
    Space ----------------->>>>> O(1)

        *TIME LIMIT EXCEEDED*

        Node *rotate(Node *head, int k) 
        {
             if(k == 0) return head;
             if(head == NULL || head -> next == NULL) return head;
             while(k--)
             {
                  Node *tail = head;
                  while(tail -> next -> next != NULL)
                  {
                       tail = tail -> next;
                  }
                  Node *temp = tail -> next;                         
                  tail -> next = NULL;
                  temp -> next = head;
                  head = temp;              
             }
             return head;
        }


Better -------------->>>>
    Time ----------->>>>> O(KN + N) 
    Space ---------->>>> O(1)

        int len(Node *head)
        {
             int count = 0;
             while(head != NULL)
             {
                  count++;
                  head = head -> next;
             }
             return count;
        }

        Node *rotate(Node *head, int k) 
        {
             if(k == 0) return head;
             if(head == NULL || head -> next == NULL) return head;
             k = k%len(head);
             while(k--)
             {
                  Node *tail = head;
                  while(tail -> next -> next != NULL)
                  {
                       tail = tail -> next;
                  }
                  
                  Node *temp = tail -> next;                         
                  tail -> next = NULL;
                  temp -> next = head;
                  head = temp;              
             }
             return head;
        }


Optimized ----------------->>>
    Time ------>>> O(N)
    Space ------->>> O(1)


        Node *rotate(Node *head, int k) {
         if(k==0) return head;
         if(head == NULL || head -> next == NULL) return head;
    
         //compute length
         Node *curr = head;
         int len = 1;
         while(curr -> next){
              curr = curr -> next;
              len++;
         }
         k = k%len;
         k = len - k;
         
         curr -> next = head;
         
         while(k--)
         {
              curr = curr -> next;
         }
         head = curr -> next;
         curr -> next = NULL;
         return head;
    }
    
