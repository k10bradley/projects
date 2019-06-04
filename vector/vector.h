#ifndef __VECTOR___H__
#define __VECTOR___H__

#include <utility>

template<class T>
class Vector{
  T* arr = nullptr;
  unsigned int size;
  unsigned int capacity;

  void resize(){
    bool change = false;
    if ( capacity == 0 ){
      capacity = 1;
      initArr();
      return;
    }
    if ( size == capacity ){
      capacity *= 2;
      change = true;
    } else if ( size < capacity /2 ){
      while ( size < capacity / 2){
        capacity /= 2;
      }
      change = true;
    }

    if ( change ){
      T* temp = arr;
      initArr();
      copyArr(temp);  
    }
  };

  void deleteArray(){
    delete[] arr;
    arr = nullptr;
  }

  void swap(Vector& o){
    using std::swap;
    swap(size, o.size);
    swap(capacity, o.capacity);
    swap(arr, o.arr);
  }

  void initArr(){
    if ( capacity > 0 ){
      arr = new T[capacity];
    }
  }

  void copyArr(T* other){
    for (int i = 0; i < size; ++i){
      arr[i] = other[i];
    }
  }

 public:
  Vector(unsigned int cap = 0):size(0), capacity(cap){
    initArr();
  };

  ~Vector(){
    deleteArray();
  }

  Vector(const Vector& rhs): size(rhs.size), capacity(rhs.capacity){
    initArr();
    copyArr(rhs.arr);
  }

  Vector(Vector&& rhs): size(rhs.size), capacity(rhs.capacity), arr(rhs.arr){
    rhs.arr = nullptr;
    rhs.size = 0;
    rhs.capacity = 0;
  }

  Vector operator=(const Vector& rhs){
    Vector copy = rhs;
    swap(copy);
    return *this;
  }
  
  Vector operator=(Vector&& rhs){
    swap(rhs);
    return *this;
  }

  void push_back(T elem){
    resize();
    arr[size++] = elem;
  };

  void pop(){
    if ( size > 0 ){
      --size;
      resize();
    }
  };

  T top(){
    return arr[size];
  };

  class Iterator{
    T* ptr;
    Iterator(T* p): ptr{p} {};
   public:
    T& operator*(){
      return *ptr;
    };
    Iterator& operator++(){
      ptr += 1;
      return *this;
    };
    bool operator==(Iterator& rhs){
      return ptr == rhs.ptr;
    };
    bool operator!=(Iterator& rhs){
      return !(*this == rhs);
    };
    friend class Vector;
  };

  Iterator begin(){
    return {arr};
  };

  Iterator end(){
    return {arr+size};
  };
};

#endif
