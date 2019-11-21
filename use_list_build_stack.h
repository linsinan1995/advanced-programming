/*
 * @Author: Lin Sinan
 * @Github: https://github.com/linsinan1995
 * @Email: mynameisxiaou@gmail.com
 * @LastEditors: Lin Sinan
 * @Description: 
 *               
 *               
 *               
 */

#ifndef _USE_H
#define _USE_H
#include <iostream>


struct listElt{
    listElt* next = nullptr;
    listElt* prev = nullptr;
    int data;
    listElt(){};
    ~listElt(){};
    listElt(int dat):data(dat)
    {}
};

class list{
    int length = 0;
    listElt* head = nullptr;
    listElt* tail = nullptr;
public:
    list(){};
    ~list(){};
    listElt* getHead(){
        return head;
    }
    void push_front(listElt& node){
        if (head != nullptr){
            listElt* tmp = head;
            head = &node;
            head->prev = tmp;
            tmp->next = head;
            length += 1;
        } else {
            tail = &node;
            head = &node;
            length += 1;
        }
        
    };
    int pop_front(){
        if (length <= 0) throw "error";
        int val = head->data;

        if (length == 1) {
            head = nullptr;
            tail = nullptr;
            return val;
        }
        
        head = head->prev;
        head->next = nullptr;
        length -= 1;
        return val;
    }
    
    int getLen(){
        return length;
    }

    void show(bool reverse){
        if (reverse) {
            listElt* tmp = head;
            for (int i=0; i<length; i++) {
                std::cout << tmp->data << " ";
                tmp = tmp->prev;
            }
            std::cout << "\n";
        } else {
            listElt* tmp = tail;
            for (int i=0; i<length; i++) {
                std::cout << tmp->data << " ";
                tmp = tmp->next;
            }
            std::cout << "\n";
        }
    }
};

class stack{
    list* data;
    int length;
public:
    stack(){
        data = new list();
    };

    stack(list& l): data(&l), length(l.getLen())
    {}
    
    list* getData(){
        return data;
    }
    
    void push(int val){
        listElt* le = new listElt(val);
        data->push_front(*le);
        length ++;
    }

    int pop(){
        return data->pop_front();
    }

    void show(){
        data->show(false);
    }
};

class poolOfListElt{
    listElt* arr;
    int top;
    int capacity;
    void deallocate(listElt* l) { // pop
        if (top > capacity) throw 0;
        arr[top++] = *l;
    }

    listElt* allocate() { // push
        return arr+(--top);
    }
public:
    int get(int index){
        return (arr+index)->data;
    }
    poolOfListElt(const int _capacity = 1000000): top(0), capacity(_capacity)
    {
        arr = new listElt[capacity];
        // std::cout << "SUCC\n" ;
    }
    
    ~poolOfListElt() {delete[] arr;}
    
    void push(int val){
        listElt* l = new listElt(val);
        deallocate(l);
    }

    int pop(){
        listElt* l = allocate();
        return l->data;
    }
    void show_top(){
        std::cout << top << "\n";
    }
};
#endif
