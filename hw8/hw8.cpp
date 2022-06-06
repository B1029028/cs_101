#include <iostream>

using namespace std;

class Node {

};

class LinkedList {
    private:
        int data;
        struct node* next_node;
        node_t* allocate_node(int data) {
        node_t* p = (node_t*)calloc(1, sizeof(node_t));
        p->data = data;
        p->next_node = NULL;
        return p;
}
};

int main() {
    LinkedList mylink;
    mylink.append_node(0);
    mylink.append_node(1);
    mylink.append_node(2);
    mylink.append_node(3);
    mylink.del_node(1);
    return 0;
}