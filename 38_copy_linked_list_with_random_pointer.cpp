better ----------->>>>
    Time -------->>> O(N)
    Space ---------->> O(N) using map data Structure


        LinkedListNode<int> *insertAtTail(LinkedListNode<int>* &cloneHead,LinkedListNode<int>* &cloneTail, int data)
        {
            LinkedListNode<int> *newNode = new LinkedListNode<int>(data);
            if(cloneHead == NULL && cloneTail == NULL)
            {
                cloneHead = newNode;
                cloneTail = newNode;
            }
            else
            {
                cloneTail -> next = newNode;
                cloneTail = newNode;
            }
        }
        LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
        {
            LinkedListNode<int> *cloneHead = NULL;
            LinkedListNode<int> *cloneTail = NULL;
            //Deep Copy of linked list using next pointer]
            LinkedListNode<int> *temp = head;
            while(temp != NULL)
            {
                insertAtTail(cloneHead,cloneTail,temp -> data);
                temp = temp -> next;
            }
            //Mapping of the element in both the linked list 
            //in a map data stucture 
            map<LinkedListNode<int>*,LinkedListNode<int>*>Mapping;
            LinkedListNode<int> *originalNode = head;
            LinkedListNode<int> *cloneNode = cloneHead;
            while(originalNode && cloneNode)
            {
                Mapping[originalNode] = cloneNode;
                originalNode = originalNode -> next;
                cloneNode = cloneNode -> next;
            }
            originalNode = head;
            cloneNode = cloneHead;
            while(originalNode && cloneNode)
            {
                cloneNode -> random = Mapping[originalNode -> random];
                originalNode = originalNode -> next;
                cloneNode = cloneNode -> next;
            }
            return cloneHead;
        }



optimised ------------>>>
    Time --------->>> O(N)
    Space --------->>>> O(1)
    
        void insertAtTail(LinkedListNode<int>* &cloneHead,LinkedListNode<int>* &cloneTail, int data)
        {
            LinkedListNode<int> *newNode = new LinkedListNode<int>(data);
            if(cloneHead == NULL)
            {
                cloneHead = newNode;
                cloneTail = newNode;
                return;
            }
            else
            {
                cloneTail -> next = newNode;
                cloneTail = newNode;
            }
        }
        LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
        {
            LinkedListNode<int> *cloneHead = NULL;
            LinkedListNode<int> *cloneTail = NULL;
            //Deep Copy of linked list using next pointer]
            LinkedListNode<int> *temp = head;
            while(temp != NULL)
            {
                insertAtTail(cloneHead,cloneTail,temp -> data);
                temp = temp -> next;
            }
            // mapping the two linked list manually 
            // by breaking the next pointer of originalnode and pointing it to cloneNode
            // placing clone node in-between the original Node 
            LinkedListNode<int>*originalNode = head;
            LinkedListNode<int>*cloneNode = cloneHead;
            while(originalNode != NULL && cloneNode != NULL)
            {
                LinkedListNode<int>*next = originalNode -> next;
                originalNode -> next = cloneNode ;
                originalNode = next;     
                next = cloneNode -> next;
                cloneNode -> next = originalNode;
                cloneNode = next;
            }
            // marking the random pointer in linked list
            temp = head;
            while(temp != NULL)
            {
                if(temp -> next != NULL)
                {
                    // temp -> next -> random = temp -> random ? temp -> random -> next : temp -> random;
                    if(temp -> random != NULL)
                    {
                        temp -> next -> random = temp -> random -> next;
                    }
                    else
                    {
                        temp -> next -> random = temp -> random;
                    }
                }
                temp = temp -> next -> next;
            }

            originalNode = head;
            cloneNode = cloneHead;
            while(originalNode && cloneNode)
            {
                originalNode -> next = cloneNode -> next;
                originalNode = originalNode -> next;
                if(originalNode != NULL)
                    cloneNode -> next = originalNode -> next;
                cloneNode = cloneNode -> next;
            }
            return cloneHead;
        }



    



