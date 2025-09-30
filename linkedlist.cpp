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

    //delete head after function runs
    node<T>* lfirst() {
        node<T>* temp = head;
            head = head->next;
            return temp;
        }
    }

    //delete last after function runs
    node<T>* last() {
        node<T>* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        return temp;
    }

    //add element in sorted order
    void addOrder() {

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
