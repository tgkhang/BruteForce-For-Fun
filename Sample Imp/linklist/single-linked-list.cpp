#include <initializer_list>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <utility>

using namespace std;

template <typename T>
class SinglyLinkedList {
   private:
    struct Node {
        T data;
        unique_ptr<Node> next;

        template <typename U>
        explicit Node(U&& value) : data(forward<U>(value)), next(nullptr) {}
    };
    unique_ptr<Node> head_;
    size_t size_ = 0;

   public:
    SinglyLinkedList() = default;
    SinglyLinkedList(initializer_list<T> init) {
        for (const auto& value : init)
            push_back(value);
    }

    SinglyLinkedList(const SinglyLinkedList&) = delete;
    SinglyLinkedList& operator=(const SinglyLinkedList&) = delete;
    SinglyLinkedList(SinglyLinkedList&&) noexcept = default;
    SinglyLinkedList& operator=(SinglyLinkedList&&) noexcept = default;
    ~SinglyLinkedList() = default;

    [[nodiscard]] std::size_t size() const noexcept { return size_; }
    [[nodiscard]] bool empty() const noexcept { return size_ == 0; }

    template <typename U>
    void push_front(U&& value) {
        auto node = std::make_unique<Node>(std::forward<U>(value));
        node->next = std::move(head_);
        head_ = std::move(node);
        ++size_;
    }

    template <typename U>
    void push_back(U&& value) {
        auto node = std::make_unique<Node>(std::forward<U>(value));
        Node* tail = head_.get();
        if (!tail) {
            head_ = std::move(node);
        } else {
            while (tail->next) tail = tail->next.get();
            tail->next = std::move(node);
        }
        ++size_;
    }

    void pop_front() {
        if (!head_) throw std::out_of_range("pop_front on empty list");
        head_ = std::move(head_->next);
        --size_;
    }

    // Removes first occurrence of value; returns true on success.
    bool remove(const T& value) {
        if (!head_) return false;
        if (head_->data == value) {
            pop_front();
            return true;
        }
        Node* prev = head_.get();
        while (prev->next && !(prev->next->data == value))
            prev = prev->next.get();
        if (!prev->next) return false;
        prev->next = std::move(prev->next->next);
        --size_;
        return true;
    }

    [[nodiscard]] const T& front() const {
        if (!head_) throw std::out_of_range("front on empty list");
        return head_->data;
    }

    [[nodiscard]] bool contains(const T& value) const {
        for (Node* n = head_.get(); n; n = n->next.get())
            if (n->data == value) return true;
        return false;
    }

    // Simple forward iterator
    class iterator {
       public:
        explicit iterator(Node* node) : node_(node) {}
        T& operator*() const { return node_->data; }
        iterator& operator++() {
            node_ = node_->next.get();
            return *this;
        }
        bool operator!=(const iterator& o) const { return node_ != o.node_; }

       private:
        Node* node_;
    };

    iterator begin() { return iterator(head_.get()); }
    iterator end() { return iterator(nullptr); }

    friend std::ostream& operator<<(std::ostream& os, const SinglyLinkedList& list) {
        os << "[";
        for (Node* n = list.head_.get(); n; n = n->next.get()) {
            os << n->data;
            if (n->next) os << " -> ";
        }
        return os << "]";
    }
};

int main() {
    SinglyLinkedList<int> list = {10, 20, 30, 40, 50};

    list.push_front(5);
    list.push_back(60);
    list.remove(30);

    cout << list.size() << endl;
    cout << list << endl;
    cout << list.front() << endl;
    cout << list.contains(20) << endl;
    return 0;
}