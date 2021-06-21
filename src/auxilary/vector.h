#ifndef ABC_VECTOR_H
#define ABC_VECTOR_H


#include <vector>


namespace abc
{

template<typename T>
std::vector<T> operator + (const std::vector<T>& a, const std::vector<T>& b)
{
    std::vector<T> res(a);

    res.insert(res.end(), b.begin(), b.end());

    return res;
}

}

#endif
