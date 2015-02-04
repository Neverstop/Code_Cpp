#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

template <typename Function, typename Container, typename... RestArgs>
auto apply(Function func, Container &c, RestArgs &&...args)->decltype(func(std::begin(c), std::end(c), args...))
{
    return func(std::begin(c), std::end(c), std::forward<RestArgs>(args)...);
}

template<typename _IIter, typename _Funct>
using Func_pointer = _Funct (*)(_IIter, _IIter, _Funct);

using Func = std::function<void(int)> ;

int main()
{
    std::vector<int> vec{1, 2, 3, 4, 5};

    apply(static_cast<Func_pointer<vector<int>::iterator,Func>>(std::for_each), vec, [](const int& a) {std::cout << a << std::endl;});

}
