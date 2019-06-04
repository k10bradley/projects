#ifndef ___LIST___H__
#define ___LIST___H__
#include <utility>

template<class T> class List{
  class Node;
  Node* head = nullptr, *tail = nullptr;
  public:
  List<T>(){};

  ~List(){
    delete head;
  };

  List<T>(const List<T>& o){
    if ( o.head ){
      head = new Node(*o.head);
    }
    assignTail();
  };

  List<T>(List<T>&& o){
    swap(o);
  };

  List& operator=(const List& o){
    List n = o;
    swap(n);
    return *this;
  };

  List& operator=(List&& o){
    swap(o);
    return *this;
  };

  void insertFront(T elem){
    Node* n = new Node(elem, head);
    head = n;
  };

  void insertBack(T elem){
    Node *n = new Node(elem, nullptr, tail);
    tail = n;
  };

  void remove(T elem){
    if ( head.elem == elem ){
      Node* n = head;
      head = head->next;
      head->prev = nullptr;
      n->next = nullptr;
      delete n;
    } else {
      head->remove(elem);
      assignTail();
    }
  };

  T operator[](int i) const{
    return head->get(i);
  };

  T& operator[](int i){
    return head->get(i);
  };

  class Iterator{
    Node* ptr;

    Iterator(Node* p): ptr{p} {};
    friend List;
    public:
      bool operator==(Iterator& o){
        return ptr == o.ptr;
      }
      bool operator!=(Iterator& o){
        return !(*this == o);
      }
      Iterator& operator++(){
        ptr = ptr->next;
        return *this;
      }
      T& operator*(){
        return ptr->elem;
      }
  };
  
  class ReverseIterator{
    Node* ptr;

    ReverseIterator(Node* p): ptr{p} {};
    friend List;
    public:
      bool operator==(ReverseIterator& o){
        return ptr == o.ptr;
      }
      bool operator!=(ReverseIterator& o){
        return !(*this == o);
      }
      ReverseIterator& operator++(){
        ptr = ptr->prev;
        return *this;
      }
      T& operator*(){
        return ptr->elem;
      }
  };

  Iterator begin(){
    return {head};
  }

  Iterator end(){
    return {nullptr};
  }
  
  ReverseIterator rbegin(){
    return {tail};
  }

  ReverseIterator rend(){
    return {nullptr};
  }

  private:
  struct Node{
    T elem;
    Node* next = nullptr;
    Node* prev = nullptr;

    void swap(Node &other){
      using std::swap;
      swap(elem, other.elem);
      swap(next, other.next);
      swap(prev, other.prev);
    };

    Node(T elem, Node* next = nullptr, Node* prev = nullptr):
      elem{elem}, next{next}, prev{prev} {};

    ~Node(){
      delete next;
    };

    Node(const Node& o): elem{o.elem}, next{o.other?new Node{*o.next}:nullptr}{
      next->prev = this;
    };

    Node(Node&& o) {
      swap(o);
    };

    Node& operator=(const Node& o){
      Node n = o;
      swap(n);

      return *this;
    };

    Node& operator=(Node&& o){
      swap(o);

      return *this;
    };

    void remove(T elem){
      if ( next == nullptr ) return;
      if ( next->elem == elem ){
        Node* temp = next;
        next = temp->next;
        next->prev = this;
        temp->next = nullptr;
        delete temp;
      } else {
        next->remove(elem);
      }
    }

    T get(int i) const{
      if ( i == 0 ){
        return elem;
      }
      // handle exception
      return get(i-1);
    };

    T& get(int i){
      if ( i == 0 ){
        return elem;
      } 
      // handle exception
      return get(i-1);
    }
  };


  void swap(List& o){
    using std::swap;
    swap(head,o.head);
    swap(tail,o.tail);
  };

  void assignTail(){
    tail = head;
    while ( tail->next ){
      tail = tail->next;
    }
  };
};

#endif
