#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}

 };

void insertAtHead(ListNode*& head, int val) {
    ListNode* newNode = new ListNode(val);
    newNode->next = head;
    head = newNode;
}

void insertAtTail(ListNode*& head, int val) {
    ListNode* newNode = new ListNode(val);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    ListNode* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}


void deleteNode(ListNode*& head, int val) {
    if (head == nullptr) return;

    if (head->val == val) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    ListNode* current = head;
    while (current->next != nullptr && current->next->val != val) {
        current = current->next;
    }

    if (current->next == nullptr) return;

    ListNode* temp = current->next;
    current->next = current->next->next;
    delete temp;
}


bool search(ListNode* head, int val) {
    ListNode* current = head;
    while (current != nullptr) {
        if (current->val == val) {
            return true;
        }
        current = current->next;
    }
    return false;
}


void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->val << " -> ";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;
}

class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_map<int, bool> HashTable;
        for (int num : nums) {
            HashTable[num] = true;
        }

        int rpta = 0;
        bool incomp = false;

        ListNode* temp = head;
        while (temp != nullptr) {
            if (HashTable.find(temp->val) != HashTable.end()) {
                if (!incomp) {
                    rpta++;
                    incomp = true;
                }
            } else {
                incomp = false;
            }
            temp = temp->next;
        }

        return rpta;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head)
            return head;
        if(left == right)
            return head;

        ListNode* temp = new ListNode(0);
        temp->next = head;
        ListNode* prev = temp;
        for (int i = 1; i < left; ++i) {
            prev = prev->next;
        }


        ListNode* temp2 = prev->next;
        ListNode* next = nullptr;
        ListNode* prevSublist = nullptr;
        for (int i = left; i <= right; ++i) {
            next = temp2->next;
            temp2->next = prevSublist;
            prevSublist = temp2;
            temp2 = next;
        }

        prev->next->next = temp2;
        prev->next = prevSublist;

        return temp->next;
    }


};

int main(){
    ListNode* head = nullptr;
    

    insertAtHead(head, 1);
    insertAtHead(head, 2);
    insertAtHead(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);


    printList(head);

    std::cout << "Buscar 3: " << (search(head, 3) ? "Encontrado" : "No encontrado") << std::endl;
    std::cout << "Buscar 5: " << (search(head, 5) ? "Encontrado" : "No encontrado") << std::endl;

    deleteNode(head, 2);
    printList(head);

//    Solution solution;
//    int left = 2, right = 4;
//    head = solution.reverseBetween(head, left, right);
//
//    cout << "Reversed List between " << left << " and " << right << ": ";
//    printList(head);




    return 0;
}
