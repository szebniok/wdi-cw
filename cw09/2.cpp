/*
 * Zastosowania listy do implementacji tablicy rzadkiej. Proszę napisać 
 * trzy funkcje:
 * - void init(node *&tab) – inicjalizującą tablicę,
 * - int value(node *tab, int n) – zwracającą wartość elementu o indeksie n,
 * - void set(node *&tab, int n, int value) – postawiającą wartość value
 *   pod indeks n.
 */

#include <iostream>

struct node {
    int i;
    int val;
    node *next;
};

void init(node *&tab) {
    tab = nullptr;
}

int value(node *tab, int n) {
    if (tab == nullptr) return -1;
    if (tab->i == n) return tab->val;
    return value(tab->next, n);
}

void set(node *&tab, int n, int value) {
    if (tab == nullptr) {
        tab = new node { n, value, nullptr };
        return;
    }
    if (tab->i == n) {
        tab->val = value;
        return;
    }
    set(tab->next, n, value);
}

int main() {
    node *tab;
    init(tab);
    std::cout << value(tab, 10) << std::endl;
    set(tab, 10, 77);
    std::cout << value(tab, 10) << std::endl;
    std::cout << value(tab, 77) << std::endl;
    set(tab, 77, 42);
    std::cout << value(tab, 77) << std::endl;
}
