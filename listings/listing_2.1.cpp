

#include <thread>  // C++ Standard Library


void do_something(int& i) {  // Argument is a reference (another name for the argument variable).
    ++i;  // Pre-increment of referenced variable "i".
};


struct func {

    int& i;  // Reference variable.

    func( int& i_ ):i( i_ ){}

    void operator()() {

        for (unsigned j = 0;j < 1000000;++j) {
            do_something(i);
        };

    };

};  // End:  struct func {


void oops() {

    int some_local_state = 0;

    func my_func(some_local_state);

    std::thread my_thread(my_func);
      my_thread.detach();
};


int main() {
    oops();
};



