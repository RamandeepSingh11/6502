#pragma once
#include<iostream>
#include<array>
class Memory
{
public:
    Memory();
    
    ~Memory();
    
    uint8_t& operator[](uint16_t);
public:
    //CPU Internal Registers
    std::array<uint8_t,64*1024> Registers;
    
};

