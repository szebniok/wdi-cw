/*
 * Zaimplementuj zbiór mnogościowy liczb naturalnych korzystając ze struktury
   listy.
   - czy element należy do zbioru
   - dodanie elementu do zbioru
   - usunięcie elementu ze zbioru
 */

#include <iostream>

struct node {
    int val;
    node *next;
};

bool contains(node *head, int val) {
    if (head == nullptr) return false;
    return head->val == val || contains(head->next, val);
}

void add(node *&head, int val) {
    if (head == nullptr) {
        head = new node {val, nullptr};
    } else {
        if (head->val == val) return;
        add(head->next, val);
    }
}

void remove(node *&head, int val) {
    if (head == nullptr) return;
    if (head->val == val) {
        head = head->next;
        return;
    }
    remove(head->next, val);
}

int main() {
    node *set = nullptr;

    std::cout << contains(set, 1) << std::endl;
    add(set, 1);
    std::cout << contains(set, 1) << std::endl;
    std::cout << contains(set, 2) << std::endl;
    add(set, 2);
    std::cout << contains(set, 2) << std::endl;
    remove(set, 1);
    std::cout << contains(set, 1) << std::endl;
    std::cout << contains(set, 2) << std::endl;
}
