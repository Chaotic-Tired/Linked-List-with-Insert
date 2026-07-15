#include <iostream>
struct Node {
    int data;
    Node* next;

    explicit Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};


Node* insertAtPosition(Node* head, int position, int data)
{
    Node* newNode = new Node(data);

    if (position == 1) {
        newNode->next = head;
        head = newNode;
        return head;
    }

    Node* current = head;
    for (int i = 1; i < position - 1 && current != nullptr;
         ++i) {
        current = current->next;
    }

    if (current == nullptr) {
        std::cout << "Out of bounds." << std::endl;
        return head;
    }

    newNode->next = current->next;
    current->next = newNode;
    return head;
}

void printList(Node* head)
{
    while (head != nullptr) {
        std::cout << " " << head->data;
        head = head->next;
    }
    std::cout << std::endl;
}

int main()
{

    Node* head = new Node(5);
    head->next = new Node(10);
    head->next->next = new Node(20);

    printf("Before insert:");
    printList(head);


    int data = 35, pos = 4;
    head = insertAtPosition(head, pos, data);
    printf("After insert:") ;
    printList(head);

    return 0;
}