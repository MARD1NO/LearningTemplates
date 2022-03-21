#ifndef STACK_HPP
#define STACK_HPP

#include "deque"
#include "stdexcept"
#include "memory"

template<typename T, template<typename ELEM, typename = std::allocator<ELEM> > class CONT=std::deque>
class Stack {

private: 
    CONT<T> elems; 

public: 
    void push(const T&); 
    void pop();
    T top() const; 
    bool empty() const {
        return elems.empty(); 
    }

    template<typename T2, template<typename ELEM2, typename = std::allocator<ELEM2> > class CONT2>
    Stack<T, CONT>& operator=(const Stack<T2, CONT2>&); 

};

template<typename T, template<typename, typename> class CONT>
void Stack<T, CONT>::push (const T& elem){
    elems.push_back(elem); 
}

template<typename T, template<typename, typename> class CONT>
void Stack<T, CONT>::pop (){
    if(elems.empty()){
        throw std::out_of_range("Stack<>::pop(): empty stack!");
    }
    elems.pop_back(); 
}

template<typename T, template<typename, typename> class CONT>
T Stack<T, CONT>::top() const {
    if(elems.empty()){
        throw std::out_of_range("Stack<>::pop(): empty stack!");
    }
    return elems.back(); 
}

template<typename T, template<typename, typename> class CONT>
    template<typename T2, template<typename, typename> class CONT2>
Stack<T, CONT>& Stack<T, CONT>::operator=(const Stack<T2, CONT2> & op2){
    if ((void*)this == (void*)&op2){
        return *this; 
    }
    Stack<T2, CONT2> tmp(op2); 
    elems.clear(); 
    while(!tmp.empty()) {
        elems.push_front(tmp.top()); 
        tmp.pop(); 
    }
    return *this; 
}

#endif // STACK_HPP