/**
 * Jia Jun Liu
 * 100353218
 * 2021-05-18
 * This .h file contains a queue class implemented using a singly linked list.
 */

#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

template<typename T>
class Queue {
private:
    struct Node {
        T data_;
        Node *next_;
    };
    Node *head_;
    Node *tail_;
    int size_;

    /**
     * A helper function that remove all nodes from the linked list
     * @param p The head_ of the linked list
     * @return a nullptr
     */
    Node *delete_list(Node *p) {
        while (p != nullptr) {
            Node *temp = p->next_;
            p = p->next_;
            delete temp;
        }
        return p;
    }

    /**
     * A helper function that copy all nodes from the linked list
     * @param p The head_ of the linked list to be copy
     * @return A head_ of a new linked list that be copied to
     */
    Node *copy_list(Node *p) {
        if (p == nullptr) {
            return p;
        }
        return new Node{p->data_, copy_list(p->next_)};
    }

public:
    /**
     * Constructor
     */
    Queue() {
        head_ = nullptr;
        tail_ = nullptr;
        size_ = 0;
    }

    /**
     * Destructor
     */
    ~Queue() {
        head_ = delete_list(head_);
    }

    /**
     * Copy constructor
     * @param q
     */
    Queue(const Queue &q) {
        head_ = copy_list(q.head_);
        size_ = q.size_;
    }

    /**
     * Assignment operator
     * @param q The queue that to be assigned
     * @return A queue that be assigned to
     */
    Queue &operator=(const Queue *q) {
        if (this != q) {
            head_ = delete_list(head_);
            head_ = copy_list(q);
        }
        return *this;
    }

    /**
     * A function that checks if the queue is empty
     * @return True if it is empty; false if not
     */
    bool isEmpty() {
        return head_ == nullptr;
    }

    /**
     * A function the add a Node with the data_ ax to the end of the queue
     * @param x The data_ that to be add to the queue
     */
    void enqueue(T x) {
        if (isEmpty()) {
            tail_ = new Node{x, nullptr};
            head_ = tail_;
        } else {
            tail_->next_ = new Node{x, nullptr};
            tail_ = tail_->next_;
        }
        size_++;
    }

    /**
     * A function that remove a Node from the beginning of the stack and return it
     * @return The data_ saved in the removed Node
     */
    T dequeue() {
        T temp_data = front();
        Node *temp = head_->next_;
        delete head_;
        head_ = temp;
        if (head_ == nullptr) {
            tail_ = head_;
        }
        size_--;
        return temp_data;
    }

    /**
     * A function that check the data_ stored at the beginning of the queue
     * @return The data_ saved in the queue at the beginning of the queue
     */
    T front() {
        if (isEmpty()) {
            std::cerr << "The queue is empty" << std::endl;
            exit(1);
        }
        return head_->data_;
    }

    /**
     * A function that return the number of the Nodes in the Queue.
     * @return numbers of Nodes
     */
    int getSize() {
        return size_;
    }
};

#endif //QUEUE_H
