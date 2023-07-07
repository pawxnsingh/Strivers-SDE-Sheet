Brute ------------------>>> 
    Time ---------------->>>O(2N)
    Space -------------->>> O(1)


/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/


int Len(Node *head)
{
    int count = 0;
    while(head != NULL)
    {
        count++;
        head = head -> next;
    }
    return count;
}

Node* removeKthNode(Node* head, int K)
{
    Node * temp = head;
    int length = Len(head) - K  ;

//Edge Case
    if(length == 0)
    {
        head = head -> next;
        delete temp;
        return head;
    }
    
    int count = 1;

    while(count < length)
    {
        count++;
        temp = temp -> next;
    }
    Node *del = temp -> next;
    

    //Pointing to the next Node
    temp -> next = temp -> next -> next;

    delete del;
    
        
    return head;


    
}




Optimal ---------------------->>> 
    Time -------------->>> O(N)
    Space ------------>>>> O(1)



    Node* removeKthNode(Node* head, int K)
    {
        Node * dummy = new Node();
        dummy -> next = head;
        Node *fast = dummy;
        Node *slow = dummy;
        
        for(int i=1;i<=K;i++){
            fast = fast-> next;
        }
        
        while( fast-> next != NULL)
        {
            slow = slow -> next;
            fast = fast -> next;
        }
    
        Node*del = slow -> next ;
        slow -> next = slow -> next -> next ;
    
        delete del;
        return dummy -> next;
    }














