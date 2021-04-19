#include "Eratosthenes.h"

nori::Eratosthenes::Eratosthenes(){
    this->N=10000;
}

nori::Eratosthenes::Eratosthenes(size_t N){
    this->N=N;
}

nori::Eratosthenes::~Eratosthenes(){
    delete this->numberList;
    delete this->removedList;
}

void nori::Eratosthenes::Start(){
    this->numberList=new std::vector<size_t>(N);
    this->removedList=new std::vector<size_t>(N);

    std::iota(this->numberList->begin(),this->numberList->end(),1);
    this->numberList->erase(std::remove_if(
            this->numberList->begin(),
            this->numberList->end(),
            [](size_t x){return x==1;}));

    this->numberList->erase(std::remove_if(
        this->numberList->begin(),
        this->numberList->end(),
        [](size_t x) { return x % 2 == 0; }),
        this->numberList->end());

    this->numberList->push_back(2);
    for(size_t i=3;i<=this->N;i+=2){
        //もしiが未探索の数字なら...
        if(std::find(this->removedList->begin(),this->removedList->end(),i)==this->removedList->end()){
            
            std::copy_if(this->numberList->begin(),this->numberList->end(),std::back_inserter(*this->removedList),[=](size_t x){return x % i==0;});
            
            this->numberList->erase(std::remove_if(
                this->numberList->begin(),
                this->numberList->end(),
                [=](size_t x){return x % i==0;}),
                this->numberList->end()
            );
            this->numberList->push_back(i);

        }
        
    }
    std::sort(this->numberList->begin(),this->numberList->end());
    for(auto& number : *this->numberList){
        std::cout << number << " ";   
    }
    std::cout << std::endl;
    std::cout << "prime Number sum : " << this->numberList->size() << std::endl;
}