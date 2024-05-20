#include <iostream>
#include <stdexcept>

using namespace std;

template<typename T>
class Linked_List{
private:
    struct Node{
        T data;
        Node* next;
    };

    Node* head;
    int nodes;
public:
    Linked_List():head(nullptr),nodes(0){}

    ~Linked_List() {
        clear();
    }

    T front() const {
        if(!head)
            throw std::out_of_range("La lista está vacía");
        return head->data;
    }

    T back() const {
        if(!head)
            throw std::out_of_range("La lista está vacía");

        Node* temp = head;
        while(temp->next != nullptr)
            temp = temp->next;
        return temp->data;
    }

    void push_front(T value){
        Node* nodo = new Node{value, head};
        head = nodo;
        nodes++;
    }

    void push_back(T value){
        Node* nodo = new Node{value, nullptr};
        if(!head){
            head = nodo;
        } else {
            Node* temp = head;
            while(temp->next != nullptr){
                temp = temp->next;
            }
            temp->next = nodo;
        }
        nodes++;
    }

    void pop_front(){
        if(!head)
            throw std::out_of_range("La lista está vacía");
        Node* temp = head;
        head = head->next;
        delete temp;
        nodes--;
    }

    void pop_back(){
        if(!head)
            throw std::out_of_range("La lista está vacía");

        if (!head->next) {
            delete head;
            head = nullptr;
        } else {
            Node* temp = head;
            while(temp->next->next != nullptr){
                temp = temp->next;
            }
            delete temp->next;
            temp->next = nullptr;
        }
        nodes--;
    }

    T operator[](int pos) const {
        if(pos >= nodes or pos < 0)
            throw std::out_of_range("Posición fuera de rango");

        Node* temp = head;
        for(int i = 0; i < pos; i++){
            temp = temp->next;
        }
        return temp->data;
    }

    bool empty() const {
        return head == nullptr;
    }

    int size() const {
        return nodes;
    }

    void clear(){
        while(head != nullptr)
            pop_front();
    }

    void sort(){
        if (head == nullptr or head->next == nullptr)
            return;

        bool swapped;
        Node* temp;
        Node* last = nullptr;
        do {
            swapped = false;
            temp = head;

            while (temp->next != last) {
                if (temp->data > temp->next->data) {
                    std::swap(temp->data, temp->next->data);
                    swapped = true;
                }
                temp = temp->next;
            }
            last = temp;
        } while (swapped);
    }

    void reverse(){
        if (head == nullptr or head->next == nullptr)
            return;

        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;

        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev;
    }
};
