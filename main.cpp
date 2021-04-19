#include "Eratosthenes.h"

int main(int argc,char** argv){

    if(argc!=2){
        std::cerr << "Usage: eratosthenes_sample N" << std::endl;
        return -1;
    }else{
        size_t N=std::stod(argv[1]);
        nori::Eratosthenes* primeCounter=new nori::Eratosthenes(N);
        primeCounter->Start();
        delete primeCounter;
    }
    return  0;
}