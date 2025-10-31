//
struct Node{
    int data;
    Node *next;
    Node(int d){
        data = d;
        next = nullptr;
    }
};

struct SinglyLinkedList{
    Node* head;
    Node* tail;
    SinglyLinkedList(){
        head = nullptr;
        tail = nullptr;
    }
    ~SinglyLinkedList(){
    Node* cur = head;
    while(cur){
        Node* nxt = cur->next;
        delete cur;
        cur = nxt;
    }
    head = tail = nullptr;
}
};


Node* search(const SinglyLinkedList& root, int x){
    Node* node = root.head;
    while(node != nullptr){
        if(node -> data == x)
            return node;
        node = node -> next;
    }
    return nullptr;
}


Node* nodeAt(const SinglyLinkedList& root, int index){
    Node* node = root.head;
    int count = 0;
    while(node != nullptr){
        if(count == index)
            return node;
        count++;
        node = node -> next;
    }
    return nullptr;
}


void pushFront(SinglyLinkedList& root, int x){
    Node* node = new Node(x);
    if(root.head == nullptr)
        root.head = root.tail = node;
    else{
        node -> next = root.head;
        root.head = node;
    }
}

void pushBack(SinglyLinkedList& root, int x){
    Node* node = new Node(x);
    if(root.head == nullptr)
        root.head = root.tail = node;
    else{
        root.tail -> next = node;
        root.tail = node;
    }
}

void insert(Node* prev, int x){
    if(prev == nullptr)
        return;
    Node* node = new Node(x);
    node -> next = prev -> next;
    prev -> next = node;
}


void eraseNode(SinglyLinkedList& root, Node* x){
    if(root.head == nullptr || x == nullptr) return;

    if(root.head == x){
        root.head = root.head->next;
        if(root.tail == x) root.tail = nullptr; 
        delete x;
        return;
    }

    Node* prev = root.head;
    while(prev->next != nullptr && prev->next != x){
        prev = prev->next;
    }
    if(prev->next == x){
        prev->next = x->next;
        if(root.tail == x) root.tail = prev; 
        delete x;
    }
}