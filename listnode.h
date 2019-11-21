#ifndef _USE_Node_H
#define _USE_Node_H
#include <iostream>

namespace stack2{
    struct Node
    {
    Node* next;
    Node* prev;
    int data;
    };

    class list
    {
        Node head;    //空的头节点
        size_t size;        //节点个数
    public:
        list();
        ~list();
        size_t getSize(){return size;}
        void insertHead(int);  
        void insertTail(int); 
        void pop();
        void show()const;      
    };

    class stack{
        list* data;
        size_t length;
    public:
        stack(){data = new list();};
        stack(list& l): data(&l), length(l.getSize())
        {}
        list* getData(){return data;}
        void push(int val){
            data->insertHead(val);
            length ++;
        }
        void pop(){data->pop();}
        void show(){data->show();}
    };
};
inline
stack2::list::list()
{
    //初始化头部空节点
    head.next = &head;
    head.prev = &head;
    size = 0;
}

inline
stack2::list::~list()
{
    Node* p = head.next;    //头节点指针
    while (p != &head) {//没有走回到空节点
        p = p->next;    //指向下一个
        delete p->prev;    //删除前驱
    }
    head.next = &head;
    head.prev = &head;
    size = 0;
}

inline
void stack2::list::insertHead(int val)
{
    Node* node = new Node;    //new 的时候一定要带类型
    node->data = val;    //保存数据
    node->next = head.next;    //后继是原头节点
    node->prev = &head;        //前驱是空节点
    head.next = node;        //空节点的后继是新的头节点
    node->next->prev = node;    //原头节点的前驱是新头节点
    size += 1;
}

inline
void stack2::list::insertTail(int val)
{
    Node* node = new Node;
    node->data = val;    //保存数据
    node->next = &head;    //后继是空节点
    node->prev = head.prev;    //前驱是原尾节点
    head.prev = node;    //指向新的最后的节点
    node->prev->next = node;    //原本的最后节点的下一个指向新的尾节点
    size += 1;
}

inline
void stack2::list::show() const
{

    Node* p = head.prev;    //尾节点指针
    while (p != &head) {//没有走回到空节点
        std::cout << p->data << " <==> ";
        p = p->prev;    //前驱
    }
    std::cout << " head" << std::endl;
}

inline
void stack2::list::pop()
{
    //auto tmp = head.next;
    head.next = head.next->next;
    head.next->next->prev = &head;
    head.next = head.next->next;
    size -= 1;
    //tmp->prev = nullptr;
    //tmp->next = nullptr;
    //delete tmp;
}






#endif