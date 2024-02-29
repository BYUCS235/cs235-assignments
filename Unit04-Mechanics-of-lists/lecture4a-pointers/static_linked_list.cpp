
template<class T>
class LinkedList {
    struct Node {
        Node next;
        T value;
    };
    
    Node head;

    public:
    LinkedList() : head() {}
};

int main() {
    LinkedList<int> items;
}