/*
 * queue.hpp
 *
 * define your methods in coherence with the following
 * function signatures
 *
 * use the abstraction of linked lists
 * to implement the functionality of queues
 *
 */

#ifndef QUEUE_HPP_
#define QUEUE_HPP_
#include "list.hpp"

  template <class T>
    class queue: public list<T>
    {
      public:
        /*
         * Constructs a new queue.
         */
        queue(){
            this->head=NULL;
            this->tail=NULL;
            this->temp=NULL;
            this->len_=0;
        };
        /*
         * Pushes t to at the back of the queue.
         */
        void push(const T& t){
            this->append(t);
            return;
        };
        /*
         * Returns the element at the front of the queue.
         * Also removes the front element from the queue.
         */
        T pop(){
            if (this->head==NULL)
            {
                return -1;
            }
            else if ((this->head)==(this->tail))
            {
                T x=this->head->data_;
                delete this->head;
                this->head=this->tail=NULL;
                (this->len_)--;
                return x;
            }
            else{
            T x=(this->head)->data_;
            this->remove(x);
            return x;
            }
        };
        /*
         * Returns the element at the front of the queue.
         * Does not remove the front element.
         */
        T front(){
            if(this->head==NULL){
                return -1;
            }
            return (this->head)->data_;
        };
        /*
         * Returns the number of elements currently in the queue.
         */
        inline int size(){
            return this->len_;
        };
        /*
         * Returns a boolean indicating whether the queue is empty or not.
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
         * Frees the memory occupied by the queue elements.
         */
        ~queue(){
            this->temp=this->head;
            while(this->temp!=NULL){
                this->head=this->head->next;
                delete this->temp;
                this->temp=this->head;
            }
        };
    };
#endif
