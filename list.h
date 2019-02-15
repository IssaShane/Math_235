#ifndef LIST_H
#define LIST_H

#include <iostream>

template <typename T> class List {
  struct Node{
    T data;
    Node *next;
  };

  private:
    Node *root;
    int length = 0;

  public:
    List() {
      //std::cout << "default constructor called" << std::endl;
      root = nullptr;
    }

    void add(Node* element) {
      length++;
      if (root == nullptr) {
        root = element;
        return;
      }
      Node *curnode = root;
      while (curnode != nullptr) curnode = curnode->next;
      curnode = element;
    }

    void add(T *elem) {
      length++;
      Node *element = new Node;
      element->data = *elem;
      element->next = nullptr;
      if (root == nullptr) {
        root = element;
        return;
      }
      Node *curnode = root;
      while (curnode != nullptr) curnode = curnode->next;
      curnode = element;
    }
    void add(T elem) {
      length++;
      Node *element = new Node;
      element->data = elem;
      element->next = nullptr;
      if (root == nullptr) {
        root = element;
        return;
      }
      Node *curnode = root;
      while (curnode->next != nullptr) {
        curnode = curnode->next;
      }
      curnode->next = element;
    }

    List(const List &other) {
      //std::cout << "copy constructor" << std::endl;
      root = nullptr;
      Node *o_curnode = other.root;
      while (o_curnode != nullptr) {
        add(o_curnode->data);
        //new_node->next = o_curnode->next;
        o_curnode = o_curnode->next;
      }
    }

    List ( List && other ) : root{other.root} {
      //std::cout << "move constructor" << std::endl;
      other.root = nullptr;
    }

    ~List() {
      //std::cout << "destructor called" << std::endl;
      if (root == nullptr) return;
      Node *curnode = root;
      while (curnode->next != nullptr){
        Node *temp = curnode;
        delete temp;
        curnode = curnode->next;
      }
      delete curnode;
    }

    T getAt(int i) const {
      Node *curnode = root;
      int j = 0;
      while (curnode!=nullptr) {
        if (j == i) return curnode->data;
        curnode = curnode->next;
        j++;
      }
      return root->data;
    }

    void setAt(int i, T data) {
      //std::cout << "setAt" << std::endl;
      //std::cout << "data: " << std::endl << data << std::endl;
      Node *curnode = root;
      for (int j = 0; curnode !=nullptr; j++) {
        //std::cout << "in for loop" << std::endl;
        if (j == i) break;
        curnode = curnode->next;
      }
      //std::cout << "after for loop" << std::endl;
      if (curnode != nullptr) {
        //std::cout << "valid i" << std::endl;
        //std::cout << "curnode: " << std::endl << curnode->data << std::endl;
        curnode->data = data;
      }
      else std::cout << "invalid i" << std::endl;
      //std::cout << "after setting data" << std::endl;
    }

    void remove(int i) {
      length --;
      if (root == nullptr) return;
      Node *curnode = root;
      Node *prevnode = nullptr;
      if (i == 0 && root->next != nullptr) {
        Node *temp = root;
        root = root->next;
        delete temp;
        return;
      }
      else if (i == 0 && root->next == nullptr) {
        Node *temp = root;
        root = nullptr;
        delete temp;
        return;
      }
      for (int j = 0; j < i && curnode->next != nullptr; j++) {
        prevnode = curnode;
        curnode = curnode->next;
      }
      if (curnode->next!= nullptr) {
        Node *temp = curnode;
        prevnode->next = curnode->next;
        delete temp;
      }
      else {
        Node *temp = curnode;
        prevnode->next = nullptr;
        delete temp;
      }
    }
    void print(std::ostream & out) {
      Node *curnode = root;
      while(curnode!=nullptr) {
        out << curnode->data << " ";
        curnode = curnode->next;
      }
    }

    int getSize() const { return length; }

    List & operator = (const List & other) {
      //std::cout << "copy assignment operator" << std::endl;
      List<T> *new_list = new List(other);
      return *new_list;
    }

    List & operator = (List && other) {
      //std::cout << "move assignment operator" << std::endl;
      List<T> *new_list = new List(other);
      return *new_list;
    }
};


#endif
