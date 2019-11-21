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
#include <iostream>
#include <chrono>
#include <random>
#include <string>
#include <sstream> 
#define PY_IMPORT_SCRIPT "import matplotlib.pyplot as plt\n\n"
#define PY_PLOT_SCRIPT   "plt.xlabel(\'test size\')\nplt.ylabel(\'time/milliseconds\')\n"\
                         "plt.xscale(\'log\')\nplt.grid()\nplt.savefig(\"benchmark.png\")\nplt.show()\n"
#define GEN_BENCH(X)     { \
                          cout << #X << " = [";\
                          for(auto && x : (X))\
                             cout << x << ',';\
                          cout << "\b]\n"; }
#define PYPLOT(X,Y)      {cout << "plt.plot(" << #X << ", " << #Y << ")\n"; }
#define ADD_PYLINE(X)    {cout << X << '\n';}


class Stopwatch {
       std::chrono::high_resolution_clock::time_point start_;
       std::chrono::high_resolution_clock::time_point stop_;
public:
       Stopwatch(){}
       void start(){start_=std::chrono::high_resolution_clock::now();}
       void stop(){stop_=std::chrono::high_resolution_clock::now();}

       // The ratio is equal to std::nano, std::micro, std::milli, std::ratio<1> (ie equivalent to seconds),...
       // ATTENTION: there is no rounding mode: just a truncation
       
       template <class ratio>
       int64_t elapsed()const{
              typedef std::chrono::duration<int64_t, ratio> duration_type;
              duration_type et=std::chrono::duration_cast<duration_type>(stop_ - start_);
              return et.count();
       }

       int64_t elapsed_ms()const{return elapsed<std::milli>();}
       int64_t elapsed_us()const{return elapsed<std::micro>();}
       int64_t elapsed_ns()const{return elapsed<std::nano>();}

       double mps(const int64_t numOp)const{ // million per seconds
              double et=static_cast<double>(elapsed<std::nano>());
              return (numOp/et)*1000.;
       }

       Stopwatch& operator+=(const Stopwatch& t){
              stop_ += (t.stop_-t.start_);
              return *this;
       }

};

 

// Random generator : not very good but enough for our purpose

 

struct RandomGenerator {
       static void init(const int seed){srand(static_cast<unsigned>(seed));}
       static void init(){srand(static_cast<unsigned>(time(0)));}
       static int rand_max(){return RAND_MAX;}
       static int random_number(){return rand();} // generates a positive number between 0 and RAND_MAX
       static int64_t random_number_int64(const int64_t lower, const int64_t upper){return int64_t(rand() / (RAND_MAX + 1.0) * (upper - lower) + lower);}
       static void fill_randomly(int64_t* array, const int n, int64_t lower, int64_t upper);
};

template<class T, class push_fun, class pop_fun>
double benchmark(T container, push_fun push, pop_fun pop, int test_times, int test_size){
    RandomGenerator generator;
    int i = 0, j = 0;
    auto beg = std::chrono::steady_clock::now();
    for(i=0; i<test_times; ++i)
        for(j=0; j<test_size; ++j)
            (container->*push)(generator.random_number());
    for(i=0; i<test_times; ++i)
        for(j=0; j<test_size; ++j)
            (container->*pop)();
    auto end = std::chrono::steady_clock::now();
    auto diff = (end-beg);
    return std::chrono::duration<double, std::milli>(diff).count();
}