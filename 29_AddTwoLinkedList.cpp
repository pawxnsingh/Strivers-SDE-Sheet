// This Question has only optimal Solution 
// instead of directly jumping into the optimal solution
// You may tell the interviewer the edge Cases of the solution

Optimal ----------->>>
    Time ------------------>>> O(max(list1,list2)
    Space ------------->>>>>>>>>> O(N) cuz using extra space



    /**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

        Node *addTwoNumbers(Node *num1, Node *num2)
        {
            Node *dummy = new Node();
            Node *temp =  dummy;
            int carry = 0;
            while(num1 != NULL || num2 != NULL || carry)
            {
                int sum = 0;
                if(num1 != NULL)
                {
                    sum += num1 -> data;
                    num1 = num1 -> next;
                }
                if(num2 != NULL)
                {
                    sum += num2 -> data;
                    num2 = num2 -> next;
                }
                sum += carry;
                carry = 0;
                if(sum > 9)
                {
                    carry = sum / 10;
                    sum = sum % 10;
                }
                Node * newNode = new Node(sum);
                temp -> next = newNode;
                temp = temp -> next;
            }
            return dummy -> next;
        }

  


