#define TASK2

#ifdef TASK1

#include "DynArray.hpp"

int main() {
    DynArray<int> arr;
    for(int i = 0; i < 10; i++) {
        arr.push_back(i);
    }
    arr.printData();
}

#endif

#ifdef TASK2
#include "classA.hpp"
#include <vector>

#define Exercise6

#ifdef Exercise1
int main() {  
    A a1{3};
    return 0;
}
#endif

#ifdef Exercise2
int main() {  
    A a1{3};
    A a2{a1};
    A a3{A{4}};
    return 0;
}
#endif

#ifdef Exercise3
int main() {  
    std::vector<A> v;
    v.push_back(A{5});
    return 0;
}
#endif

#ifdef Exercise4
int main() {  
    A a5{7};
    A a6{8};
    a6 = a5;
    return 0;
}
#endif

#ifdef Exercise5
int main() {  
    A a7{9};
    a7 = A{10};
    return 0;
}
#endif

#ifdef Exercise6
int main() {  
    A a8{11};
    A a9{std::move(a8)};
    return 0;
}
#endif

#endif