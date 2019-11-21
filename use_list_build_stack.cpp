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

#include <vector>
#include "tool.h"
#include "stlstack.h"
#include "listnode.h"
#include "use_list_build_stack.h"

using std::cout;

#define print(x,y) (std::cout << x << y << "ms\n")


typedef void (std::stack<int>::*ptr_push)(const int&);
int main(){
    // benchmark for stack implemented by listnode.h
    stack2::stack *listnode_stack = new stack2::stack;
    // benchmark for stack implemented by list from standard library
    stlstack::stack *stl_stack = new stlstack::stack;
    // benchmark for stack implemented by stack from standard library(container is list)
    stlstack::stlstack *stl_stack2 = new stlstack::stlstack;
    // benchmark for stack implemented by stack from standard library(container is deque)
    stlstack::realStack *stl_real_stack = new stlstack::realStack;
    std::vector<double> res;
    size_t index = 0;

    print("benchmark_parameters: ", "1000, 100000");
    res.push_back(benchmark(listnode_stack, &stack2::stack::push, &stack2::stack::pop, 1000, 1e5));
    res.push_back(benchmark(stl_stack, &stlstack::stack::push, &stlstack::stack::pop, 1000, 1e5));
    res.push_back(benchmark(stl_stack2, &stlstack::stlstack::push, &stlstack::stlstack::pop, 1000, 1e5));
    res.push_back(benchmark(stl_real_stack, &stlstack::realStack::push, &stlstack::realStack::pop, 1000, 1e5));

    print("[stack in listnode.h] time cost: ", res[index++]);
    print("[stack made by list<int>] time cost: ", res[index++]);
    print("[std::stack contained by list<int>] time cost: ", res[index++]);
    print("[std::stack contained by deque<int>] time cost: ", res[index++]);
    
    
    print("benchmark_parameters: ", "1000000, 100");
    res.push_back(benchmark(listnode_stack, &stack2::stack::push, &stack2::stack::pop, 1e6, 100));
    res.push_back(benchmark(stl_stack, &stlstack::stack::push, &stlstack::stack::pop, 1e6, 100));
    res.push_back(benchmark(stl_stack2, &stlstack::stlstack::push, &stlstack::stlstack::pop, 1e6, 100));
    res.push_back(benchmark(stl_real_stack, &stlstack::realStack::push, &stlstack::realStack::pop, 1e6, 100));
    
    print("[stack in listnode.h] time cost: ", res[index++]);
    print("[stack made by list<int>] time cost: ", res[index++]);
    print("[std::stack contained by list<int>] time cost: ", res[index++]);
    print("[std::stack contained by deque<int>] time cost: ", res[index++]);
    return 0;
}



// #define TEST_TIMES_1 1000
// #define TEST_SIZE_1 1e5
// #define TEST_TIMES_2 1e6
// #define TEST_SIZE_2 100
// using std::cout;
// typedef void (stack2::stack::*ptr_ln_push)(int);
// typedef void (stack2::stack::*ptr_ln_pop)(void);
// ptr_ln_push list_node_push_ptr = &stack2::stack::push;
// ptr_ln_pop list_node_pop_ptr = &stack2::stack::pop;


    /*
    listElt le1(1);
    listElt le2(2);
    listElt le3(3);
    list l;
    l.push_front(le1);
    l.push_front(le2);
    l.push_front(le3);
    print(l.getLen());
    l.show(false); 
    l.show(true); 
    // print(l.pop_front());
    // print(l.pop_front());
    // print(l.pop_front());
    
    stack s(l);
    (s.getData())->show(true);
    
    s.push(1);
    s.push(2);
    s.push(3);
    print((s.getData()->getLen()));
    s.show();
    print(s.pop());
    print(s.pop());
    print(s.pop());
    s.show();

    print("POOL!");
    poolOfListElt pool;
    listElt lep1(1);
    listElt lep2(2);
    listElt lep3(3);
    pool.deallocate(&lep1);
    pool.deallocate(&lep2);
    pool.deallocate(&lep3);
    print(pool.get(0));
    print(pool.get(1));
    print(pool.get(2));

    */
