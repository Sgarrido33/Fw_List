
// Double
template<typename T>
class Double_Linked_List{
private:
    struct Node{
        T data;
        Node* next;
        Node* prev;
    };

    Node* head;
    Node* tail;
    int nodes;

public:
    Double_Linked_List(): head(nullptr), tail(nullptr), nodes(0) {}

    ~Double_Linked_List() {
        clear();
    }

    T front() const {
        if(!head)
            throw std::out_of_range("La lista está vacía");
        return head->data;
    }

    T back() const {
        if(!tail)
            throw std::out_of_range("La lista está vacía");
        return tail->data;
    }

    void push_front(T value){
        Node* nodo = new Node{value, head, nullptr};
        if(head) {
            head->prev = nodo;
        } else {
            tail = nodo;
        }
        head = nodo;
        nodes++;
    }

    void push_back(T value){
        Node* nodo = new Node{value, nullptr, tail};
        if(tail) {
            tail->next = nodo;
        } else {
            head = nodo;
        }
        tail = nodo;
        nodes++;
    }

    void pop_front(){
        if(!head)
            throw std::out_of_range("La lista está vacía");
        Node* temp = head;
        head = head->next;
        if(head) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
        nodes--;
    }

    void pop_back(){
        if(!tail)
            throw std::out_of_range("La lista está vacía");
        Node* temp = tail;
        tail = tail->prev;
        if(tail) {
            tail->next = nullptr;
        } else {
            head = nullptr;
        }
        delete temp;
        nodes--;
    }

    T operator[](int pos) const {
        if(pos >= nodes or pos < 0)
            throw std::out_of_range("Posición fuera de rango");

        Node* temp;
        if(pos < nodes / 2) {
            temp = head;
            for(int i = 0; i < pos; i++) {
                temp = temp->next;
            }
        } else {
            temp = tail;
            for(int i = nodes - 1; i > pos; i--) {
                temp = temp->prev;
            }
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

        Node* current = head;
        Node* temp = nullptr;

        while (current != nullptr) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }

        if (temp != nullptr) {
            head = temp->prev;
        }
    }
};

int main() {

    Linked_List<int> single_list;

    // Insertar elementos
    single_list.push_front(3);
    single_list.push_front(2);
    single_list.push_front(1);
    single_list.push_back(4);
    single_list.push_back(5);


    std::cout << "Contenido de Linked_List:" << std::endl;
    for (int i = 0; i < single_list.size(); ++i) {
        std::cout << single_list[i] << " ";
    }
    std::cout << std::endl;


    single_list.pop_front();
    single_list.pop_back();



    Double_Linked_List<int> double_list;

    double_list.push_front(3);
    double_list.push_front(2);
    double_list.push_front(1);
    double_list.push_back(4);
    double_list.push_back(5);

    std::cout << "Contenido de Double_Linked_List:" << std::endl;
    for (int i = 0; i < double_list.size(); ++i) {
        std::cout << double_list[i] << " ";
    }
    std::cout << std::endl;


    double_list.pop_front();
    double_list.pop_back();


    std::cout << "Contenido de Double_Linked_List después de eliminar:" << std::endl;
    for (int i = 0; i < double_list.size(); ++i) {
        std::cout << double_list[i] << " ";
    }
    std::cout << std::endl;


    double_list.push_back(10);
    double_list.push_back(7);
    double_list.push_back(8);
    double_list.sort();


    std::cout << std::endl;

    return 0;
}
