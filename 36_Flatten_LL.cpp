

Time ----------------->>> O(N)
    Space --------->>>>>> O(1)


        Node *mergeTwoLists(Node *list1 ,Node *list2)
        {
        	Node *dummy = new Node(0);
        	Node *temp = dummy;
        	while(list1 != NULL && list2 != NULL)
        	{
        		if(list1 -> data <= list2 -> data)
        		{
        			temp -> bottom =  list1;
        			list1 = list1 -> bottom;
        			temp = temp -> bottom;
        		}
        		else //list2 is smaller
        		{
        			temp -> bottom = list2;
        			list2 = list2 -> bottom;
        			temp = temp -> bottom;
        		}		
        	}
        	if(list1) temp -> bottom = list1;
        	else temp -> bottom = list2;
        	return dummy -> bottom;	
        }
        
        Node* flatten(Node* head) 
        {
        	//Base Case
        	if(head == NULL || head -> next == NULL) return head;
        	Node *sorted =  flatten(head->next);
            head -> next = NULL;
        	//Second Linked list that has to be passed as second list 
        	head = mergeTwoLists(head,sorted);
        	return head;	
        }
