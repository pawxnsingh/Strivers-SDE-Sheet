BruteForce -------------------->>>>
    Time --------------->>>> O(N*M)
    Space --------------->>> O(1)


    Node* findIntersection(Node *firstHead, Node *secondHead)
    { 
        while(firstHead != NULL)
        {
            while(secondHead != NULL)
            {   
                if(secondHead == firstHead)
                {
                    return secondHead;
                } 
            }
            firstHead = firstHead -> next;
        }
        return NULL;
    }


Better ---------------->>>
    Time------------->>>> o(2n+m)
    Space ---------->>>>


    Node* findIntersection(Node *firstHead, Node *secondHead)
    {
        map<Node*,int>st;
        while(firstHead != NULL){
            st[firstHead]++;
            firstHead = firstHead -> next;
        }
        while(secondHead != NULL){
            st[secondHead]++;
            secondHead = secondHead -> next;
        }
        for(auto it : st)
        {
            if(it.second > 1)
            {
                return it.first;
            }
        }
        return NULL;
    }


More Better ------------------->>>
    Time -------------------->>> O(N+M)
    Space ---------------->>>>> O(N)

    Node* findIntersection(Node *firstHead, Node *secondHead)
    {
        map<Node*,int>st;
        while(firstHead != NULL){
            st[firstHead]++;
            firstHead = firstHead -> next;
        }
        while(secondHead != NULL){
            if(st.count(secondHead))
            {
                return secondHead;
            }
            // st[secondHead]++;
            secondHead = secondHead -> next;
        }
        return NULL;
    }



Optimal ---------->>>>
    Time -------------->>> O(N) + O(M) + O(M-N) + O(N) = O(max(n,m))
    Space ------------->>>> O(1)

    
    int Len(Node *head)
    {
        int count = 0;
        while(head != NULL)
        {
            count ++;
            head = head-> next;
        }
        return count;
    }
    
    Node* findIntersection(Node *firstHead, Node *secondHead)
    {
        int lenfirst = Len(firstHead);
        int lenSecond = Len(secondHead);
    
        if(lenfirst < lenSecond)
        {
            int len = lenSecond - lenfirst;
            while(len != 0)
            {
                secondHead = secondHead -> next;
                len--;
            }
        }
        else //lenFirst > lenSecond
        {
            int len = lenfirst - lenSecond;
            while(len != 0)
            {
                firstHead = firstHead -> next;
                len--;
            }
        }
    
    
        while(firstHead != NULL && secondHead != NULL)
        {
            if(firstHead == secondHead)
            {
                return firstHead;
            }
            firstHead = firstHead -> next;
            secondHead = secondHead -> next;
        }    
        
        return NULL;
    }



Optimal Solution(but Code is small and crisp)
    Time ----------------------->>> O()
    Space ------------------->>>>>> O()

    Node* findIntersection(Node *firstHead, Node *secondHead)
    {
        Node *dummy1 = firstHead;
        Node *dummy2 = secondHead;
        while(dummy1 != dummy2)
        {
            if(dummy1 == NULL)
            {
                dummy1 = secondHead;
            }        
            if(dummy2 == NULL)
            {
                dummy2 = firstHead;
            }   
            dummy1 = dummy1 -> next;
            dummy2 = dummy2 -> next;
        }
        return dummy1;    
    }








