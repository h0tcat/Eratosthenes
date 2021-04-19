#ifndef __ERATOSTHENES_H__
#define __ERATOSTHENES_H__

#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <string>

namespace nori{
    class Eratosthenes{
       private:
            size_t N;
            std::vector<size_t>* numberList,*removedList;

        public:
            Eratosthenes();
            Eratosthenes(size_t N);
            ~Eratosthenes();
            void Start();
    };
};

#endif