#include "CPU.hpp"
CPU::CPU(){reset();}

CPU::~CPU(){}

void CPU::reset(){
    Y=X=Acc=D=Z=ID=0;
    SP=0XFD;
    PC=0x00;
}

//Fetches A byte of Memory
//The Process Takes 1 Cpu Cycle
//Also Increments The Program Counter
CPU::Byte CPU::Fetch(uint32_t& Cycles){
    Byte data=InternalRegister[PC++];
    Cycles--;
    return data;
}

CPU::Byte CPU::FetchLocation(uint32_t& Cycles,uint32_t Address){
    Cycles--;
    return InternalRegister[Address];
}

//Returns The Data From Least Signifcant Byte. Making it Faster
uint16_t CPU::ZeroPage(uint32_t& Cycles){
    return Fetch(Cycles);
}

//Grabs The Address in Zero Page Addressing and Then Adds A offset X to the Address
//The Address wraps around 0xFF
uint16_t CPU::ZeroPageX(uint32_t& Cycles){
    uint16_t data=Fetch(Cycles);
    data+=X;
    data&=0xFF;
    Cycles--;
    return data;
}

//Grabs The Address in Zero Page Addressing and Then Adds A offset Y to the Address
//Again The Address Wraps Around 0xFF
uint16_t CPU::ZeroPageY(uint32_t& Cycles){
    uint16_t data=Fetch(Cycles);
    data+=Y;
    data&=0xFF;
    Cycles--;
    return data;
}
//Not Sure
uint16_t CPU::Relative(uint32_t& Cycles){
    uint16_t data=Fetch(Cycles);
    if(data&0x80){
        data|=0xFF00;
    }
    return 0;
}

//Gives A Full 16Bit Address. Has To Perfome Two Fetch Hence Takes 2 Clock Cycles
uint16_t CPU::Absolute(uint32_t& Cycles){
    uint16_t data=Fetch(Cycles);
    data|=(Fetch(Cycles)<<8);
    return data;
}

//Gives a Full 16Bit Address Stored with an Offset X.
uint16_t CPU::AbsoluteX(uint32_t& Cycles){
    uint16_t data=Absolute(Cycles);
    data+=X;
    return data;
}

//Gives a Full 16Bit Address Stored with an Offset X.
uint16_t CPU::AbsoluteY(uint32_t& Cycles){
    uint16_t data=Absolute(Cycles);
    data+=Y;
    return data;
}

//So Fetches The 16Bit Address And then Runs the Instruction At That Address
//We're not executing Instruction Here though
//The ptr_lo==0xFF is cause when ptr_lo is 0xFF then any increment would cause it to go to 
//Next Page and Hence We're using The Bits In The Most Significant Byte.
uint16_t CPU::Indirect(uint32_t& Cycles){
    uint16_t ptr_lo=Fetch(Cycles),ptr_hi=(Fetch(Cycles)<<8);
    uint16_t ptr=ptr_lo|ptr_hi;
    uint16_t eff;
    if(ptr_lo==0xFF){
        eff=(FetchLocation(Cycles,(ptr&0xFF00))<<8)|FetchLocation(Cycles,ptr);
    }
    else eff=(FetchLocation(Cycles,ptr+1)<<8)|FetchLocation(Cycles,ptr);
    return eff;
}

//Grabs The Zero Page Address and then Adds Offset of X
//It also wraps The Resultant Address after Incrementing
uint16_t CPU::IndirectX(uint32_t& Cycles){
    uint16_t ptrl=(Fetch(Cycles)+X)&0xFF;
    uint16_t ptrr=(ptrl+1)&0xFF;
    uint16_t res=FetchLocation(Cycles,ptrl)|(FetchLocation(Cycles,ptrr)<<8);
    return res;
}

//Grabs The Zero Page Address and Then Fetches the Word at That Location And adds Y as an Offset.
uint16_t CPU::IndirectY(uint32_t& Cycles){
    uint16_t ptr=(Fetch(Cycles));
    uint16_t res=FetchLocation(Cycles,ptr)|(FetchLocation(Cycles,(ptr+1)&0xFF)<<8)+Y;
    return res;
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
    
}