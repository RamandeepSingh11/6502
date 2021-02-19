#include "Memory.hpp"

Memory::Memory()
{
    for(uint8_t &i:Registers){
        i=0x0000;
    }
}
Memory::~Memory(){}

uint8_t& Memory::operator[](uint16_t Read_Location){
    return Registers[Read_Location]; 
}










//uint8_t Memory::read(uint16_t read_location){
//    return Registers[read_location];
//}
//void Memory::write(uint16_t write_location,uint8_t data){
//    Registers[write_location]=data;
//}