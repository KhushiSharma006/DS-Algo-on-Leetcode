class Solution {
public:
    Node* copyRandomList(Node* head) {

        if(head == NULL)
            return NULL;

        Node* temp = head;

        // Step 1: Insert copy nodes
        while(temp != NULL){
            Node* copyNode = new Node(temp->val);

            copyNode->next = temp->next;
            temp->next = copyNode;

            temp = copyNode->next;
        }

        // Step 2: Copy random pointers
        temp = head;

        while(temp != NULL){

            if(temp->random != NULL)
                temp->next->random = temp->random->next;

            temp = temp->next->next;
        }

        // Step 3: Separate both lists
        temp = head;

        Node* dummy = new Node(-1);
        Node* copy = dummy;

        while(temp != NULL){

            copy->next = temp->next;
            copy = copy->next;

            temp->next = temp->next->next;

            temp = temp->next;
        }

        return dummy->next;
    }
};