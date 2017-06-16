/*
 * stack.hpp
 *
 * define your methods in coherence with the following
 * function signatures
 *
 * use the abstraction of linked lists
 * to implement the functionality of stacks
 *
 */

#ifndef STACK_HPP_
#define STACK_HPP_
#include "list.hpp"

  template<class T>
    class stack: public list<T>
    {
      private:
      public:
        /*
         * Constructs a new stack.
         */
        stack(){
            this->head=NULL;
            this->temp=NULL;
            this->len_=0;
        };
        /*
         * Pushes t to on the top of the stack.
         */
        void push(const T& t){
            this->cons(t);
        };
        /*
         * Returns the element at the top of the stack.
         * Also removes the top element from the stack.
         */
        T pop(){
            if(this->head==NULL){
                return -1;
            }
            else{
            T x;
            x=(this->head)->data_;
            this->remove(x);
            return x;
            }
        };
        /*
         * Returns the element at the top of the stack.
         * Does not remove the top element.
         */
        T top(){
            return (this->head)->data_;
        };
        /*
         * Returns the number of elements currently in the stack.
         */
        int size(){
            return this->len_;
        };
        /*
         * Returns a boolean indicating whether the stack is empty or not.
         */
        inline bool empty(){
            if (this->head==NULL){
                return 1;
            }
            else
                return 0;
        };
        /*
         * Destructor
         * Fress the memory occupied by the stack elements.
         */
        ~stack(){
            this->temp=this->head;
            while(this->temp!=NULL){
                this->head=this->head->next;
                delete this->temp;
                this->temp=this->head;
            }
        };

    };

#endif
