class MyLinkedList {
    struct Node {
        int val;
        Node* next;
        Node(int x) : val(x), next(nullptr) {}
    };

    Node* head;
    int size;

public:
    MyLinkedList() {
        head = nullptr;
        size = 0;
    }

    int get(int index) {
        if (index < 0 || index >= size) return -1;

        Node* temp = head;
        while (index--) temp = temp->next;

        return temp->val;
    }

    void addAtHead(int val) {
        Node* node = new Node(val);
        node->next = head;
        head = node;
        size++;
    }

    void addAtTail(int val) {
        Node* node = new Node(val);

        if (!head) {
            head = node;
        } else {
            Node* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = node;
        }
        size++;
    }

    void addAtIndex(int index, int val) {
        if (index < 0) index = 0;
        if (index > size) return;

        if (index == 0) {
            addAtHead(val);
            return;
        }

        Node* temp = head;
        for (int i = 0; i < index - 1; i++)
            temp = temp->next;

        Node* node = new Node(val);
        node->next = temp->next;
        temp->next = node;
        size++;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;

        Node* temp = head;

        if (index == 0) {
            head = head->next;
            delete temp;
        } else {
            for (int i = 0; i < index - 1; i++)
                temp = temp->next;

            Node* del = temp->next;
            temp->next = del->next;
            delete del;
        }

        size--;
    }
};