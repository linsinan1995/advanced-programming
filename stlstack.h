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
#pragma once
#include <list>
#include <stack>
namespace stlstack{
    class stack{
    public:
        stack(){
            data = new std::list<int>;
        }
        ~stack(){
            // delete &head;
            // delete &data; 不然当stack空了就被优化了
        }
        void push(int);
        void pop();
        void show();
        size_t size();
    private:
        std::list<int> *data;
    };

    inline
    void stack::push(int val){
        data->emplace_front(std::move(val));
    }

    inline
    void stack::pop(){
        data->pop_front();
    }

    inline
    void stack::show(){
        for(auto && item:*data){
            std::cout << item << " ";
        }
        std::cout << "\n";
    }

    inline
    size_t stack::size(){
        return data->size();
    }

    class stlstack{
    public:
        stlstack(){}
        ~stlstack(){}
        void push(int val){
            data.push(std::move(val));
        }
        void pop(){
            data.pop();
        }
        
    private:
        std::stack<int,std::list<int>> data;
    };

    class realStack{
    public:
        realStack(){}
        ~realStack(){}
        void push(int val){
            data.push(val);
        }
        void pop(){
            data.pop();
        }
        
    private:
        std::stack<int> data;
    };
}
// std::stack<int,std::list<int>> stlstack_v2;

/*  
    Test tool:
    stlstack::stack s;
    for (int i=0; i<10; i++) s.push(i);
    print(s.size());
    s.show();
    for (int i=0; i<10; i++) s.pop();
    print(s.size());
    s.show();
*/