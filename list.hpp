/*
 * queue.hpp
 *
 * functionality of a singly linked-list
 *
 * define your methods in coherence with the following
 * function signatures
 *
 *
 */

//Try declaring the struct outside the class


#ifndef LIST_HPP
#define LIST_HPP 1

template<class T>
    class list
    {
    public:
    struct node{
        T data_;
        node * next;
    };
        node *head,*tail,*temp,*temp1;
        int len_;
        /*
         * Primary contructor.
         * Should construct an empty list.
         * Size of the created list should be zero.
         */
        list(){
            head=NULL;
            tail=NULL;
            temp=NULL;
            temp1=NULL;
            len_=0;
        };
        /*
         * Seondary constructor.
         * Creates a new list which is a copy of the provided list.
         */
        list(const list<T> & x){
            head=NULL;
            tail=NULL;
            temp=NULL;
            temp1=NULL;
            len_=0;

            temp=x.head;
            while(temp!=x.tail){
                append(temp->data_);
                temp=temp->next;
            }
            append(temp->data_);
        };
        /*
         * Destructor.
         * Frees all the memory acquired by the list.
         */
        ~list(){
            temp=head;
            while(temp!=NULL){
                head=head->next;
                delete temp;
                temp=head;
            }
            //delete tail;
        };
        /*
         * adds value at the end of the list.
         */
        void append(const T& value){
            if(head==NULL){
                head=new node;
                head->data_=value;
                head->next=NULL;
                tail=head;
            }
            else{
                tail->next=new node;
                tail=tail->next;
                tail->data_=value;
                tail->next=NULL;
            }
            len_++;
        };
        /*
         * Returns the length of the list.
         */
        inline int length(){
            return len_;
        };
        /*
         * Returns a boolean indicating whether the list is empty.
         */
        inline bool empty(){
            if (head==NULL){
                return 1;
            }
            else
                return 0;
        };
        /*
         * Adds a value to the front of the list.
         */
        void cons(const T& value){
            temp= new node;
            temp->next=head;
            temp->data_=value;
            head=temp;
            len_++;
        };
        /*
         * Removes the first occurence of the value from list.
         */
        void remove(const T & x){
            node * temp_pre=NULL;
            if(head==NULL){
                return;
            }
            else if(head->data_==x){
                temp=head;
                head=head->next;
                delete temp;
                len_--;
                return;
            }
            else{
                temp_pre==head;
                temp=head->next;
                while(temp!=NULL){
                    if(temp->data_==x){
                        temp_pre->next=temp->next;
                        delete temp;
                        len_--;
                        return;
                    }
                    else{
                    	temp_pre=temp;
                        temp=temp->next;
                    }
                }
                return;
            }
            
        };
        /*
         * Appends the given list x at the end of the current list.
         */
        void append(list<T>& x){
            int leng =x.length();
            temp=x.head;
            int count=0;
            while(count<leng){
                append(temp->data_);
                temp=temp->next;
                count++;
            }
            return;
        };
    };

#endif
