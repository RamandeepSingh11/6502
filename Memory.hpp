#pragma once
#include<iostream>
#include<array>
class Memory
{
public:
    Memory();
    
    ~Memory();
    
//    //Writes the data At Specified Location
//    //Setter
//    void write(uint16_t ,uint8_t );
//    
//    //Reads The Data From Specified Location
//    //Getter
//    uint8_t read(uint16_t);
    
    uint8_t& operator[](uint16_t);
public:
    //CPU Internal Registers
    std::array<uint8_t,64*1024> Registers;
    
};

