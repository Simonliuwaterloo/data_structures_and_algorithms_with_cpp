#include <iostream>
//this is not a copy of code from textbook
//it is my own implementation without looking at book
//3.2 was copied from textbook, that's why I was using both
//camelback and underline naming convention in that :)
class StringNode{
private:
    std::string elem;
    StringNode* prev;
    StringNode* next;
    friend class StringLinkedList;
public:
    const std::string& get_elem();
    const StringNode* get_next() const;
    const StringNode* get_prev() const;
};

const std::string& StringNode::get_elem() {
    return elem;
}

const StringNode* StringNode::get_next() const {
    return next;
}

const StringNode* StringNode::get_prev() const {
    return prev;
}
class StringLinkedList{
private:
    StringNode* header;
    StringNode* trailer;
public:
    StringLinkedList();
    ~StringLinkedList();
    bool empty();
    void remove_front();
    void remove_back();
    void add_front(const std::string& e);
    void add_back(const std::string& e);
    StringNode* front();
    StringNode* back();

protected:
    void insert_after(StringNode* prev_node, const std::string& e);
};

StringLinkedList::StringLinkedList() {
    header = nullptr;
    trailer = nullptr;
}

StringLinkedList::~StringLinkedList() {
    while (!empty()) remove_front();
}

void StringLinkedList::remove_front() {
    if (trailer->prev == header->next) trailer = nullptr;
    StringNode* old = header->next;
    header->next = old->next;
    header->next->prev = header;
    delete old;
}

void StringLinkedList::remove_back() {
    if (trailer->prev == header->next) trailer = nullptr;
    StringNode* old = trailer->prev;
    trailer = old->prev;
    trailer->prev->next = trailer;
    delete old;
}

void StringLinkedList::add_front(const std::string& e) {
    StringNode* old = header->next;
    header->next = new StringNode();
    header->next->elem = e;
    header->next->prev = header;
    header->next->next = old;
    old->prev = header->next;
    if (trailer->prev == nullptr) trailer ->prev = header->next;
}

void StringLinkedList::add_back(const std::string& e) {
    StringNode* old = trailer->prev;
    trailer->prev = new StringNode();
    trailer->prev->elem = e;
    trailer->prev->next = trailer;
    trailer->prev->prev = old;
    old->next = trailer->prev;
    if (header->next == nullptr) header ->next = trailer->prev;
}

StringNode* StringLinkedList::front() {
    if (header != nullptr) {
        return header->next;
    }
    else {
        return nullptr;
    }
}

StringNode* StringLinkedList::back() {
    if (trailer != nullptr) {
        return trailer->prev;
    }
    else {
        return nullptr;
    }
}
void StringLinkedList::insert_after(StringNode *prev_node, const std::string& e) {
    StringNode* inserted_node = new StringNode();
    inserted_node->elem = e;
    if (prev_node == nullptr) throw 1;
    prev_node->next->prev = inserted_node;
    inserted_node->next = prev_node->next;
    inserted_node->prev = prev_node;
    prev_node->next = inserted_node;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}