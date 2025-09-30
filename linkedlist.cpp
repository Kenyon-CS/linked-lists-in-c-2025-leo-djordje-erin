#include <iostream>

template <typename T>
class node {
  public:
    T data;           // Data of generic type T
    node* next;       // Pointer to the next node in the list

    node(T val) : data(val), next(nullptr) {}
};

template <typename T>
class LinkedList {
  private:
    node<T>* head;  // Pointer to the first node of the list

  public:
    LinkedList() : head(nullptr) {}

    // Insert at the end
    void append(T value) {
        node<T>* newNode = new node<T>(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            node<T>* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Insert at the beginning
    void prepend(T value) {
        node<T>* newNode = new node<T>(value);
        newNode->next = head;
        head = newNode;
    }

    //delete first node, then return data of first node
    T lfirst() {
        if (head == nullptr) {
            cerr << List is empty! << endl;
            return;
        }
        node<T>* temp = head;
        head = head->next;
        T firstData = temp->data;
        delete temp;
        return firstData;
    }

    //delete last node, then return its data
    T last() {
        if (head == nullptr) {
            cerr << List is empty! << endl;
            return;
        }

        //Head is only element:
        if (head-> next == nullptr) {
            T lastData = head->data;
            delete head;
            head = nullptr;
            return lastData;
        }

        node<T>* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        T lastData = temp->next->data;
        delete temp->next;
        temp->next = nullptr;
        return lastData;
    }

    //add element in sorted order
    bool addOrder(T value) {
        node<T>* element = new node<T>(value);

        //element's value <= head's value, OR, list is empty
        if (head == nullptr || value <= head->data) {
            element->next = head;
            head = element;
            return true;
        }

        node<T>* temp = head;

        //element's data is > head
        while (temp->next != nullptr) {
            temp = temp->next;
            if (value <= temp->next->data) {
                element->next = temp->next;
                temp->next = element;
                return true;
            }
        }
        
        return false;
    }

    // Remove first occurrence of value
    void remove(T value) {
        if (head == nullptr) return;

        if (head->data == value) {
            node<T>* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        node<T>* temp = head;
        while (temp->next != nullptr && temp->next->data != value) {
            temp = temp->next;
        }

        if (temp->next == nullptr) return;

        node<T>* nodeToRemove = temp->next;
        temp->next = temp->next->next;
        delete nodeToRemove;
    }

    // Print the list
    void print() {
        node<T>* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "nullptr" << std::endl;
    }

    // Destructor to clean up memory
    ~LinkedList() {
        while (head != nullptr) {
            node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList<int> list;

    list.append(1);
    list.append(2);
    list.append(3);
    list.prepend(0);

    std::cout << "Linked List: ";
    list.print();

    list.remove(2);
    std::cout << "After removing 2: ";
    list.print();

    return 0;
}
