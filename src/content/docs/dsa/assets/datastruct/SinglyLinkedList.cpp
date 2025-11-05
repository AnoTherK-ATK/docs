struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};

struct SinglyLinkedList {
    Node* head;
    Node* tail;
    int cnt;

    SinglyLinkedList() : head(nullptr), tail(nullptr), cnt(0) {}

    //tự viết cách gán để đỡ lỗi
    SinglyLinkedList(const SinglyLinkedList&) = delete;
    SinglyLinkedList& operator=(const SinglyLinkedList&) = delete;

    ~SinglyLinkedList() {
        Node* cur = head;
        while (cur) {
            Node* nxt = cur->next;
            delete cur;
            cur = nxt;
        }
        head = tail = nullptr;
        cnt = 0;
    }
};

// --- Các hàm chỉ đọc: dùng const& và trả con trỏ const ---
Node* search(const SinglyLinkedList& root, int x) {
    Node* node = root.head;
    while (node) {
        if (node->data == x) return node;
        node = node->next;
    }
    return nullptr;
}

Node* nodeAt(const SinglyLinkedList& root, int index) {
    //không tồn tại index đó
    if (index >= root.cnt || index < 0) return nullptr;
    Node* node = root.head;
    while (index--) node = node->next;
    return node;
}

void pushFront(SinglyLinkedList& root, int x) {
    Node* node = new Node(x);
    if (!root.head) {
        root.head = root.tail = node;
    } else {
        node->next = root.head;
        root.head = node;
    }
    ++root.cnt;
}

void pushBack(SinglyLinkedList& root, int x) {
    Node* node = new Node(x);
    if (!root.tail) {
        root.head = root.tail = node;
    } else {
        root.tail->next = node;
        root.tail = node;
    }
    ++root.cnt;
}

// insert-after `prev`
void insert(SinglyLinkedList& root, Node* prev, int x) {
    if (!prev) return;
    Node* node = new Node(x);
    node->next = prev->next;
    prev->next = node;
    if (root.tail == prev) root.tail = node; // cập nhật tail
    ++root.cnt;
}

void eraseNode(SinglyLinkedList& root, Node* x) {
    if (!root.head || !x) return;

    if (root.head == x) {
        root.head = root.head->next;
        if (root.tail == x) root.tail = nullptr;
        delete x;
        --root.cnt;
        return;
    }

    Node* prev = root.head;
    while (prev->next && prev->next != x) {
        prev = prev->next;
    }
    if (prev->next == x) {
        prev->next = x->next;
        if (root.tail == x) root.tail = prev;
        delete x;
        --root.cnt;
    }
}
