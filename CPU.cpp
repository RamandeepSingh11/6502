#include "CPU.hpp"

CPU::CPU(){}

CPU::~CPU(){}

void CPU::reset(){
    
}

//Set Carry Flag
void CPU::SEC(){
    C=1;
}

//Clear Carry Flag
void CPU::CLC(){
    C=0;
}

//Set Interupt disable Flag
void CPU::SEI(){
    ID=1;
}

//Clear Interupt Disable Flag
void CPU::CLI(){
    ID=0;
}

//Set Decimal Mode Flag
void CPU::SED(){
    D=1;
}

//Clear Decimal Mode Flag
void CPU::CLD(){
    D=0;
}

//Clear OverFlow Flag
void CPU::CLV(){
    O=0;
}

void CPU::LDA(){
//    Acc=M[SP];
//    if(Acc==0){
//        Z=0;
//    }
//    if(Acc&(1<<7)){
//        N=1;
//    }
}