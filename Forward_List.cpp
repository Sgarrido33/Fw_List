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
    Linked_List():head(nullptr),nodes(0){};


    T front(){
        if(!head)
            throw std::out_of_range("La lista esta vacia");
        return head->data;
    }

    T back(){
        if(!head)
            throw std::out_of_range("La lista esta vacia");

        Node* temp = head;
        while(temp->next != nullptr)
            temp = temp->next;
        return temp->data;
    }

    void push_front(T value){
        Node* nodo = new Node;
        nodo->data = value;

        if(!head)
            nodo->next = nullptr;
        else
            nodo->next = head;

        head = nodo;
        nodes++;;
    }

    void push_back(T value){
        Node* nodo = new Node;
        nodo->data = value;

        if(!head){
            nodo->next = nullptr;
        }
        else{
            Node* temp = head;
            while(temp->next != nullptr){
                temp = temp->next;
            }
            temp->next = nodo;
            nodo->next = nullptr;
        }
        nodes++;;
    }

    T pop_front(){
        if(!head)
            throw std::out_of_range("La lista esta vacia");
        Node* temp = head;
        head = temp->next;
        temp->next = nullptr;
        delete temp;
        nodes--;
    }

    T pop_back(){
        if(!head)
            throw std::out_of_range("La lista esta vacia");

        if (!head->next) {
            delete head;
            head = nullptr;
            nodes = 0;
        }

        Node* temp = head;
        while(temp->next->next != nullptr){
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
        nodes--;
    }

    T operator[](int pos){
        if(pos >= nodes or pos < 0)
            throw std::out_of_range("Posicion fuera de rango");

        if(pos == 0)
            return front();

        if(pos == nodes-1)
            return back();

        Node* temp = head;
        for(int i=0;i<pos;i++){
            temp = temp->next;
        }
        return temp->data;
    };

    bool empty(){
        if(!head or nodes == 0)
            return true;
        return false;
    }

    int size(){
        return nodes;
    }

    void clear(){
        while(head!= nullptr)
            pop_front();
    }

    void sort(){
        if (head == nullptr or head->next == nullptr)
            return;

        bool swap;
        Node* temp;
        Node* lasttemp = nullptr;
        do {
            swap = false;
            temp = head;

            while (temp->next != lasttemp) {
                if (temp->data > temp->next->data) {

                    temp = temp->data;
                    temp->data = temp->next->data;
                    temp->next->data = temp;
                    swap = true;
                }
                temp = temp->next;
            }
            lasttemp = temp;
        } while (swap);
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




