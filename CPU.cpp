#include "CPU.hpp"
CPU::CPU(){
    for(int i=0;i<256;i++){
        Lookup.push_back({0,nullptr,nullptr});
    }
    Instruction temp;
    
    temp.Cycles=2;
    temp.addr_mode=std::bind(&CPU::IMM,this,std::placeholders::_1);
    temp.operation=std::bind(&CPU::ADC,this,std::placeholders::_1);
    temp.Illegal=false;
    Lookup[0x69]=temp;
    
    temp.Cycles=3;
    temp.addr_mode=std::bind(&CPU::ZeroPage,this,std::placeholders::_1);
    Lookup[0x65]=temp;
    
    temp.Cycles=4;
    temp.addr_mode=std::bind(&CPU::ZeroPageX,this,std::placeholders::_1);
    Lookup[0x75]=temp;
    
    temp.addr_mode=std::bind(&CPU::Absolute,this,std::placeholders::_1);
    Lookup[0x6D]=temp;
    
    temp.addr_mode=std::bind(&CPU::AbsoluteX,this,std::placeholders::_1);
    Lookup[0x7D]=temp;
    
    temp.addr_mode=std::bind(&CPU::AbsoluteY,this,std::placeholders::_1);
    Lookup[0x79]=temp;
    
    temp.Cycles=6;
    temp.addr_mode=std::bind(&CPU::IndirectX,this,std::placeholders::_1);
    Lookup[0x61]=temp;
    
    temp.Cycles=5;
    temp.addr_mode=std::bind(&CPU::IndirectY,this,std::placeholders::_1);
    Lookup[0x71]=temp;
    
    temp.Cycles=2;
    temp.addr_mode=std::bind(&CPU::IMM,this,std::placeholders::_1);
    temp.operation=std::bind(&CPU::AND,this,std::placeholders::_1);
    Lookup[0x29]=temp;
    
    temp.Cycles=3;
    temp.addr_mode=std::bind(&CPU::ZeroPage,this,std::placeholders::_1);
    Lookup[0x25]=temp;
    
    temp.Cycles=4;
    temp.addr_mode=std::bind(&CPU::ZeroPageX,this,std::placeholders::_1);
    Lookup[0x35]=temp;
    
    temp.addr_mode=std::bind(&CPU::Absolute,this,std::placeholders::_1);
    Lookup[0x2D]=temp;
    
    temp.addr_mode=std::bind(&CPU::AbsoluteX,this,std::placeholders::_1);
    Lookup[0x3D]=temp;
    
    temp.addr_mode=std::bind(&CPU::AbsoluteY,this,std::placeholders::_1);
    Lookup[0x39]=temp;
    
    temp.Cycles=6;
    temp.addr_mode=std::bind(&CPU::IndirectX,this,std::placeholders::_1);
    Lookup[0x21]=temp;
    
    temp.Cycles=5;
    temp.addr_mode=std::bind(&CPU::IndirectY,this,std::placeholders::_1);
    Lookup[0x31]=temp;
    
    temp.Cycles=2;
    temp.addr_mode=std::bind(&CPU::Accumulator,this,std::placeholders::_1);
    temp.operation=std::bind(&CPU::ASL,this,std::placeholders::_1);
    Lookup[0x0A]=temp;
    
    temp.Cycles=5;
    temp.addr_mode=std::bind(&CPU::ZeroPage,this,std::placeholders::_1);
    Lookup[0x06]=temp;
    
    temp.Cycles=6;
    temp.addr_mode=std::bind(&CPU::ZeroPageX,this,std::placeholders::_1);
    Lookup[0x16]=temp;
    
    temp.addr_mode=std::bind(&CPU::Absolute,this,std::placeholders::_1);
    Lookup[0x0E]=temp;
    
    temp.Cycles=7;
    temp.addr_mode=std::bind(&CPU::AbsoluteX,this,std::placeholders::_1);
    Lookup[0x1E]=temp;
    
    temp.Cycles=2;
    temp.addr_mode=std::bind(&CPU::Relative,this,std::placeholders::_1);
    temp.operation=std::bind(&CPU::BCC,this,std::placeholders::_1);
    Lookup[0x90]=temp;
    
    temp.operation=std::bind(&CPU::BCS,this,std::placeholders::_1);
    Lookup[0xB0]=temp;
    
    temp.operation=std::bind(&CPU::BEQ,this,std::placeholders::_1);
    Lookup[0xF0]=temp;
    
    temp.Cycles=3;
    temp.addr_mode=std::bind(&CPU::ZeroPage,this,std::placeholders::_1);
    temp.operation=std::bind(&CPU::BIT,this,std::placeholders::_1);    
    Lookup[0x24]=temp;
    
    temp.Cycles=4;
    temp.addr_mode=std::bind(&CPU::Absolute,this,std::placeholders::_1);
    Lookup[0x2C]=temp;
    
    temp.Cycles=2;
    temp.addr_mode=std::bind(&CPU::Relative,this,std::placeholders::_1);
    temp.operation=std::bind(&CPU::BMI,this,std::placeholders::_1);
    Lookup[0x30]=temp;
    
    temp.operation=std::bind(&CPU::Relative,this,std::placeholders::_1);
    Lookup[0xD0]=temp;
    
    temp.operation=std::bind(&CPU::BPL,this,std::placeholders::_1);
    Lookup[0x10]=temp;
    
    temp.Cycles=7;
    temp.addr_mode=std::bind(&CPU::Implied,this,std::placeholders::_1);
    temp.operation=std::bind(&CPU::BRK,this,std::placeholders::_1);
    Lookup[0x00]=temp;
    
    temp.Cycles=2;
    temp.addr_mode=std::bind(&CPU::Relative,this,std::placeholders::_1);
    temp.operation=std::bind(&CPU::BVC,this,std::placeholders::_1);
    Lookup[0x50]=temp;
    
    temp.operation=std::bind(&CPU::BVS,this,std::placeholders::_1);
    Lookup[0x70]=temp;
    
    temp.addr_mode=std::bind(&CPU::Implied,this,std::placeholders::_1);
    temp.operation=std::bind(&CPU::CLC,this,std::placeholders::_1);
    Lookup[0x18]=temp;
    
    temp.operation=std::bind(&CPU::CLD,this,std::placeholders::_1);
    Lookup[0xD8]=temp;
    
    temp.operation=std::bind(&CPU::CLI,this,std::placeholders::_1);
    Lookup[0x58]=temp;
    
    temp.operation=std::bind(&CPU::CLV,this,std::placeholders::_1);
    Lookup[0xB8]=temp;
    
    temp.Cycles=2;
    temp.addr_mode=std::bind(&CPU::IMM,this,std::placeholders::_1);
    temp.operation=std::bind(&CPU::CMP,this,std::placeholders::_1);
    Lookup[0xC9]=temp;
    
    temp.Cycles=3;
    temp.addr_mode=std::bind(&CPU::ZeroPage,this,std::placeholders::_1);
    Lookup[0xC5]=temp;
    
    temp.Cycles=4;
    temp.addr_mode=std::bind(&CPU::ZeroPageX,this,std::placeholders::_1);
    Lookup[0xD5]=temp;
    
    temp.addr_mode=std::bind(&CPU::Absolute,this,std::placeholders::_1);
    Lookup[0xCD]=temp;
    
    temp.addr_mode=std::bind(&CPU::AbsoluteX,this,std::placeholders::_1);
    Lookup[0xDD]=temp;
    
    temp.addr_mode=std::bind(&CPU::AbsoluteY,this,std::placeholders::_1);
    Lookup[0xD9]=temp;
    
    temp.Cycles=6;
    temp.addr_mode=std::bind(&CPU::IndirectX,this,std::placeholders::_1);
    Lookup[0xC1]=temp;
    
    temp.Cycles=5;
    temp.addr_mode=std::bind(&CPU::IndirectY,this,std::placeholders::_1);
    Lookup[0xD1]=temp;
    
    temp.Cycles=2;
    temp.addr_mode=std::bind(&CPU::IMM,this,std::placeholders::_1);
    temp.operation=std::bind(&CPU::CPX,this,std::placeholders::_1);
    Lookup[0xE0]=temp;
    
    temp.Cycles=3;
    temp.addr_mode=std::bind(&CPU::ZeroPage,this,std::placeholders::_1);
    Lookup[0xE4]=temp;
    
    temp.Cycles=4;
    temp.addr_mode=std::bind(&CPU::Absolute,this,std::placeholders::_1);
    Lookup[0xEC]=temp;
    
    temp.Cycles=2;
    temp.addr_mode=std::bind(&CPU::IMM,this,std::placeholders::_1);
    temp.operation=std::bind(&CPU::CPY,this,std::placeholders::_1);
    Lookup[0xC0]=temp;
    
    temp.Cycles=3;
    temp.addr_mode=std::bind(&CPU::ZeroPage,this,std::placeholders::_1);
    Lookup[0xC4]=temp;
    
    temp.Cycles=4;
    temp.addr_mode=std::bind(&CPU::Absolute,this,std::placeholders::_1);
    Lookup[0xCC]=temp;
    
    temp.Cycles=5;
    temp.addr_mode=std::bind(&CPU::ZeroPage,this,std::placeholders::_1);
    temp.operation=std::bind(&CPU::DEC,this,std::placeholders::_1);
    Lookup[0xC6]=temp;
    
    temp.Cycles=6;
    temp.addr_mode=std::bind(&CPU::ZeroPageX,this,std::placeholders::_1);
    Lookup[0xD6]=temp;
    
    temp.addr_mode=std::bind(&CPU::Absolute,this,std::placeholders::_1);
    Lookup[0xCE]=temp;
    
    temp.Cycles=7;
    temp.addr_mode=std::bind(&CPU::AbsoluteX,this,std::placeholders::_1);
    Lookup[0xDE]=temp;
    
    temp.Cycles=2;
    temp.addr_mode=std::bind(&CPU::Implied,this,std::placeholders::_1);
    temp.operation=std::bind(&CPU::DEX,this,std::placeholders::_1);
    Lookup[0xCA]=temp;
    
    temp.operation=std::bind(&CPU::DEY,this,std::placeholders::_1);
    Lookup[0x88]=temp;
    
    temp.addr_mode=std::bind(&CPU::IMM,this,std::placeholders::_1);
    temp.operation=std::bind(&CPU::EOR,this,std::placeholders::_1);
    Lookup[0x49]=temp;
    
    temp.Cycles=3;
    temp.addr_mode=std::bind(&CPU::ZeroPage,this,std::placeholders::_1);
    Lookup[0x45]=temp;
    
    temp.Cycles=4;
    temp.addr_mode=std::bind(&CPU::ZeroPageX,this,std::placeholders::_1);
    Lookup[0x55]=temp;
    
    temp.addr_mode=std::bind(&CPU::Absolute,this,std::placeholders::_1);
    Lookup[0x4D]=temp;
    
    temp.addr_mode=std::bind(&CPU::AbsoluteX,this,std::placeholders::_1);
    Lookup[0x5D]=temp;
    
    temp.addr_mode=std::bind(&CPU::AbsoluteY,this,std::placeholders::_1);
    Lookup[0x59]=temp;
    
    temp.Cycles=6;
    temp.addr_mode=std::bind(&CPU::IndirectX,this,std::placeholders::_1);
    Lookup[0x41]=temp;
    
    temp.Cycles=5;
    temp.addr_mode=std::bind(&CPU::IndirectY,this,std::placeholders::_1);
    Lookup[0x51]=temp;
    
    temp.addr_mode=std::bind(&CPU::ZeroPage,this,std::placeholders::_1);
    temp.operation=std::bind(&CPU::INC,this,std::placeholders::_1);
    Lookup[0xE6]=temp;
    
    temp.Cycles=6;
    temp.addr_mode=std::bind(&CPU::ZeroPageX,this,std::placeholders::_1);
    Lookup[0xF6]=temp;
    
    temp.addr_mode=std::bind(&CPU::Absolute,this,std::placeholders::_1);
    Lookup[0xEE]=temp;
    
    temp.Cycles=7;
    temp.addr_mode=std::bind(&CPU::AbsoluteX,this,std::placeholders::_1);
    Lookup[0xFE]=temp;
    
    //Lookup for INX.....................................................................

    temp.Cycles = 2;
    temp.addr_mode = std::bind(&CPU::Implied, this, std::placeholders::_1);
    temp.operation = std::bind(&CPU::INX, this, std::placeholders::_1);
    Lookup[0xE8] = temp;

    //Lookup for INY.....................................................................

    temp.Cycles = 2;
    temp.addr_mode = std::bind(&CPU::Implied, this, std::placeholders::_1);
    temp.operation = std::bind(&CPU::INY, this, std::placeholders::_1);
    Lookup[0xC8] = temp;

    //Lookup for JMP.....................................................................

    temp.Cycles = 3;
    temp.addr_mode = std::bind(&CPU::Absolute, this, std::placeholders::_1);
    temp.operation = std::bind(&CPU::JMP, this, std::placeholders::_1);
    Lookup[0x4C] = temp;

    temp.Cycles = 5;
    temp.addr_mode = std::bind(&CPU::Indirect, this, std::placeholders::_1);
    Lookup[0x6C] = temp;

    //Lookup for JSR.....................................................................

    temp.Cycles = 6;
    temp.addr_mode = std::bind(&CPU::Absolute, this, std::placeholders::_1);
    temp.operation = std::bind(&CPU::JSR, this, std::placeholders::_1);
    Lookup[0x20] = temp;

    //Lookup for LDA.....................................................................

    temp.Cycles = 2;
    temp.addr_mode = std::bind(&CPU::IMM, this, std::placeholders::_1);
    temp.operation = std::bind(&CPU::LDA, this, std::placeholders::_1);
    Lookup[0xA9] = temp;

    temp.Cycles = 3;
    temp.addr_mode = std::bind(&CPU::ZeroPage, this, std::placeholders::_1);
    Lookup[0xA5] = temp;

    temp.Cycles = 4;
    temp.addr_mode = std::bind(&CPU::ZeroPageX, this, std::placeholders::_1);
    Lookup[0xB5] = temp;

    temp.addr_mode = std::bind(&CPU::Absolute, this, std::placeholders::_1);
    Lookup[0xAD] = temp;

    temp.addr_mode = std::bind(&CPU::AbsoluteX, this, std::placeholders::_1);
    Lookup[0xBD] = temp;

    temp.addr_mode = std::bind(&CPU::AbsoluteY, this, std::placeholders::_1);
    Lookup[0xB9] = temp;

    temp.Cycles = 6;
    temp.addr_mode = std::bind(&CPU::IndirectX, this, std::placeholders::_1);
    Lookup[0xA1] = temp;

    temp.Cycles = 5;
    temp.addr_mode = std::bind(&CPU::IndirectY, this, std::placeholders::_1);
    Lookup[0xB1] = temp;

    //Lookup for LDX.....................................................................

    temp.Cycles = 2;
    temp.addr_mode = std::bind(&CPU::IMM, this, std::placeholders::_1);
    temp.operation = std::bind(&CPU::LDX, this, std::placeholders::_1);
    Lookup[0xA2] = temp;

    temp.Cycles = 3;
    temp.addr_mode = std::bind(&CPU::ZeroPage, this, std::placeholders::_1);
    Lookup[0xA6] = temp;

    temp.Cycles = 4;
    temp.addr_mode = std::bind(&CPU::ZeroPageY, this, std::placeholders::_1);
    Lookup[0xB6] = temp;

    temp.addr_mode = std::bind(&CPU::Absolute, this, std::placeholders::_1);
    Lookup[0xAE] = temp;

    temp.addr_mode = std::bind(&CPU::AbsoluteY, this, std::placeholders::_1);
    Lookup[0xBE] = temp;

    //Lookup for LDY.....................................................................

    temp.Cycles = 2;
    temp.addr_mode = std::bind(&CPU::IMM, this, std::placeholders::_1);
    temp.operation = std::bind(&CPU::LDY, this, std::placeholders::_1);
    Lookup[0xA0] = temp;

    temp.Cycles = 3;
    temp.addr_mode = std::bind(&CPU::ZeroPage, this, std::placeholders::_1);
    Lookup[0xA4] = temp;

    temp.Cycles = 4;
    temp.addr_mode = std::bind(&CPU::ZeroPageX, this, std::placeholders::_1);
    Lookup[0xB4] = temp;

    temp.addr_mode = std::bind(&CPU::Absolute, this, std::placeholders::_1);
    Lookup[0xAC] = temp;

    temp.addr_mode = std::bind(&CPU::AbsoluteX, this, std::placeholders::_1);
    Lookup[0xBC] = temp;

    //Lookup for LSR.....................................................................

    temp.Cycles = 2;
    temp.addr_mode = std::bind(&CPU::Accumulator, this, std::placeholders::_1);
    temp.operation = std::bind(&CPU::LSR, this, std::placeholders::_1);
    Lookup[0x4A] = temp;

    temp.Cycles = 5;
    temp.addr_mode = std::bind(&CPU::ZeroPage, this, std::placeholders::_1);
    Lookup[0x46] = temp;

    temp.Cycles = 6;
    temp.addr_mode = std::bind(&CPU::ZeroPageX, this, std::placeholders::_1);
    Lookup[0x56] = temp;

    temp.addr_mode = std::bind(&CPU::Absolute, this, std::placeholders::_1);
    Lookup[0x4E] = temp;

    temp.Cycles = 7;
    temp.addr_mode = std::bind(&CPU::AbsoluteX, this, std::placeholders::_1);
    Lookup[0x5E] = temp;

    //Lookup for NOP.....................................................................

    temp.Cycles = 2;
    temp.addr_mode = std::bind(&CPU::Implied, this, std::placeholders::_1);
    temp.operation = std::bind(&CPU::NOP, this, std::placeholders::_1);
    Lookup[0xEA] = temp;

    //Lookup for ORA............................................................

    temp.Cycles = 2;
    temp.addr_mode = std::bind(&CPU::IMM, this, std::placeholders::_1);
    temp.operation = std::bind(&CPU::ORA, this, std::placeholders::_1);
    Lookup[0x09] = temp;

    temp.Cycles = 3;
    temp.addr_mode = std::bind(&CPU::ZeroPage, this, std::placeholders::_1);
    Lookup[0x05] = temp;

    temp.Cycles = 4;
    temp.addr_mode = std::bind(&CPU::ZeroPageX, this, std::placeholders::_1);
    Lookup[0x15] = temp;

    temp.addr_mode = std::bind(&CPU::Absolute, this, std::placeholders::_1);
    Lookup[0x0D] = temp;

    temp.addr_mode = std::bind(&CPU::AbsoluteX, this, std::placeholders::_1);
    Lookup[0x1D] = temp;

    temp.addr_mode = std::bind(&CPU::AbsoluteY, this, std::placeholders::_1);
    Lookup[0x19] = temp;

    temp.Cycles = 6;
    temp.addr_mode = std::bind(&CPU::IndirectX, this, std::placeholders::_1);
    Lookup[0x01] = temp;

    temp.Cycles = 5;
    temp.addr_mode = std::bind(&CPU::IndirectY, this, std::placeholders::_1);
    Lookup[0x11] = temp;

    //Lookup for PHA.....................................................................

    temp.Cycles = 3;
    temp.addr_mode = std::bind(&CPU::Implied, this, std::placeholders::_1);
    temp.operation = std::bind(&CPU::PHA, this, std::placeholders::_1);
    Lookup[0x48] = temp;

    //Lookup for PHP.....................................................................

    temp.Cycles = 3;
    temp.addr_mode = std::bind(&CPU::Implied, this, std::placeholders::_1);
    temp.operation = std::bind(&CPU::PHP, this, std::placeholders::_1);
    Lookup[0x08] = temp;

    //Lookup for PLA.....................................................................

    temp.Cycles = 4;
    temp.addr_mode = std::bind(&CPU::Implied, this, std::placeholders::_1);
    temp.operation = std::bind(&CPU::PLA, this, std::placeholders::_1);
    Lookup[0x68] = temp;

    //Lookup for PLP.....................................................................

    temp.Cycles = 4;
    temp.addr_mode = std::bind(&CPU::Implied, this, std::placeholders::_1);
    temp.operation = std::bind(&CPU::PLP, this, std::placeholders::_1);
    Lookup[0x28] = temp;

    //Lookup for ROL............................................................

    temp.Cycles = 2;
    temp.addr_mode = std::bind(&CPU::Accumulator, this, std::placeholders::_1);
    temp.operation = std::bind(&CPU::ROL, this, std::placeholders::_1);
    Lookup[0x2A] = temp;

    temp.Cycles = 5;
    temp.addr_mode = std::bind(&CPU::ZeroPage, this, std::placeholders::_1);
    Lookup[0x26] = temp;

    temp.Cycles = 6;
    temp.addr_mode = std::bind(&CPU::ZeroPageX, this, std::placeholders::_1);
    Lookup[0x36] = temp;

    temp.addr_mode = std::bind(&CPU::Absolute, this, std::placeholders::_1);
    Lookup[0x2E] = temp;

    temp.Cycles = 7;
    temp.addr_mode = std::bind(&CPU::AbsoluteX, this, std::placeholders::_1);
    Lookup[0x3E] = temp;

    //Lookup for ROR............................................................
  
    temp.Cycles = 2;
    temp.addr_mode= std::bind(&CPU::Accumulator, this, std::placeholders::_1);
    temp.operation = std::bind(&CPU::ROR, this, std::placeholders::_1);
    Lookup[0x6A] = temp;

    temp.Cycles = 5; 
    temp.addr_mode = std::bind(&CPU::ZeroPage, this, std::placeholders::_1);
    Lookup[0x66] = temp;

    temp.Cycles = 6;
    temp.addr_mode = std::bind(&CPU::ZeroPageX, this, std::placeholders::_1);
    Lookup[0x76] = temp;

    temp.addr_mode = std::bind(&CPU::Absolute, this, std::placeholders::_1);
    Lookup[0x6E] = temp;

    temp.Cycles = 7;
    temp.addr_mode = std::bind(&CPU::AbsoluteX, this, std::placeholders::_1);
    Lookup[0x7E] = temp;

    //Lookup for RTI.....................................................................

    temp.Cycles = 6;
    temp.addr_mode = std::bind(&CPU::Implied, this, std::placeholders::_1);
    temp.operation = std::bind(&CPU::RTI, this, std::placeholders::_1);
    Lookup[0x40] = temp;

    //Lookup for RTS.....................................................................

    temp.Cycles = 6;
    temp.addr_mode = std::bind(&CPU::Implied, this, std::placeholders::_1);
    temp.operation = std::bind(&CPU::RTS, this, std::placeholders::_1);
    Lookup[0x60] = temp;

    //Lookup for SBC............................................................

    temp.Cycles = 2;
    temp.addr_mode = std::bind(&CPU::IMM, this, std::placeholders::_1);
    temp.operation = std::bind(&CPU::SBC, this, std::placeholders::_1);
    Lookup[0xE9] = temp;

    temp.Cycles = 3;
    temp.addr_mode = std::bind(&CPU::ZeroPage, this, std::placeholders::_1);    
    Lookup[0xE5] = temp;

    temp.Cycles = 4;
    temp.addr_mode = std::bind(&CPU::ZeroPageX, this, std::placeholders::_1);
    Lookup[0xF5] = temp;

    temp.addr_mode = std::bind(&CPU::Absolute, this, std::placeholders::_1);
    Lookup[0xED] = temp;

    temp.addr_mode = std::bind(&CPU::AbsoluteX, this, std::placeholders::_1);
    Lookup[0xFD] = temp;

    temp.addr_mode = std::bind(&CPU::AbsoluteY, this, std::placeholders::_1);
    Lookup[0xF9] = temp;

    temp.Cycles = 6;
    temp.addr_mode = std::bind(&CPU::IndirectX, this, std::placeholders::_1);
    Lookup[0xE1] = temp;

    temp.Cycles = 5;
    temp.addr_mode = std::bind(&CPU::IndirectY, this, std::placeholders::_1);
    Lookup[0xF1] = temp;


    //Lookup for SEC.....................................................................

    temp.Cycles = 2;
    temp.addr_mode = std::bind(&CPU::Implied, this, std::placeholders::_1);
    temp.operation = std::bind(&CPU::SEC, this, std::placeholders::_1);
    Lookup[0x38] = temp;

    //Lookup for SED.....................................................................

    temp.Cycles = 2;
    temp.addr_mode = std::bind(&CPU::Implied, this, std::placeholders::_1);
    temp.operation = std::bind(&CPU::SED, this, std::placeholders::_1);
    Lookup[0xF8] = temp;

    //Lookup for SEI.....................................................................

    temp.Cycles = 2;
    temp.addr_mode = std::bind(&CPU::Implied, this, std::placeholders::_1);
    temp.operation = std::bind(&CPU::SEI, this, std::placeholders::_1);
    Lookup[0x78] = temp;

    //Lookup for STA.............................................................
    
    temp.Cycles = 3;
    temp.addr_mode = std::bind(&CPU::ZeroPage, this, std::placeholders::_1);
    temp.operation = std::bind(&CPU::STA, this, std::placeholders::_1);
    Lookup[0x85] = temp;

    temp.Cycles = 4;
    temp.addr_mode = std::bind(&CPU::ZeroPageY, this, std::placeholders::_1);
    Lookup[0x95] = temp;

    temp.addr_mode = std::bind(&CPU::Absolute, this, std::placeholders::_1);
    Lookup[0x8D] = temp;

    temp.Cycles = 5;
    temp.addr_mode = std::bind(&CPU::AbsoluteX, this, std::placeholders::_1);
    Lookup[0x9D] = temp;

    temp.addr_mode = std::bind(&CPU::AbsoluteY, this, std::placeholders::_1);
    Lookup[0x99] = temp;

    temp.Cycles = 6;
    temp.addr_mode = std::bind(&CPU::IndirectX, this, std::placeholders::_1);
    Lookup[0x81] = temp;

    temp.addr_mode = std::bind(&CPU::IndirectY, this, std::placeholders::_1);
    Lookup[0x91] = temp;
    
    //Lookup for STX................................................................
    
    temp.Cycles = 3;
    temp.addr_mode = std::bind(&CPU::ZeroPage, this, std::placeholders::_1);
    temp.operation = std::bind(&CPU::STX, this, std::placeholders::_1);
    Lookup[0x86] = temp;

    temp.Cycles = 4;
    temp.addr_mode = std::bind(&CPU::ZeroPageY, this, std::placeholders::_1);
    Lookup[0x96] = temp;

    temp.addr_mode = std::bind(&CPU::Absolute, this, std::placeholders::_1);
    Lookup[0x8E] = temp;
    
    //Lookup for STY................................................................

    temp.Cycles = 3;
    temp.addr_mode=std::bind(&CPU::ZeroPage, this, std::placeholders::_1);
    temp.operation = std::bind(&CPU::STY, this, std::placeholders::_1);
    Lookup[0x84] = temp;
 
    temp.Cycles = 4;
    temp.addr_mode=std::bind(&CPU::ZeroPageX, this, std::placeholders::_1);
    Lookup[0x94] = temp;
    
    temp.addr_mode = std::bind(&CPU::Absolute, this, std::placeholders::_1);
    Lookup[0x8C] = temp;

    //Lookup for TAX.....................................................................

    temp.Cycles = 2;
    temp.addr_mode = std::bind(&CPU::Implied, this, std::placeholders::_1);
    temp.operation = std::bind(&CPU::TAX, this, std::placeholders::_1);
    Lookup[0xAA] = temp;

    //Lookup for TAY.....................................................................

    temp.Cycles = 2;
    temp.addr_mode = std::bind(&CPU::Implied, this, std::placeholders::_1);
    temp.operation = std::bind(&CPU::TAY, this, std::placeholders::_1);
    Lookup[0xA8] = temp;

    //Lookup for TSX.....................................................................

    temp.Cycles = 2;
    temp.addr_mode = std::bind(&CPU::Implied, this, std::placeholders::_1);
    temp.operation = std::bind(&CPU::TSX, this, std::placeholders::_1);
    Lookup[0xBA] = temp;

    //Lookup for TXA.....................................................................

    temp.Cycles = 2;
    temp.addr_mode = std::bind(&CPU::Implied, this, std::placeholders::_1);
    temp.operation = std::bind(&CPU::TXA, this, std::placeholders::_1);
    Lookup[0x8A] = temp;

    //Lookup for TXS.....................................................................

    temp.Cycles = 2;
    temp.addr_mode = std::bind(&CPU::Implied, this, std::placeholders::_1);
    temp.operation = std::bind(&CPU::TXS, this, std::placeholders::_1);
    Lookup[0x9A] = temp;

    //Lookup for TYA.....................................................................

    temp.Cycles = 2;
    temp.addr_mode = std::bind(&CPU::Implied, this, std::placeholders::_1);
    temp.operation = std::bind(&CPU::TYA, this, std::placeholders::_1);
    Lookup[0x98] = temp;
    
    reset();
}
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

uint16_t CPU::Accumulator(uint32_t& Cycles){
    Cycles--;
    return Acc;
}
uint16_t CPU::Implied(uint32_t& Cycles){
    --Cycles;
    return 0;
}
uint16_t CPU::IMM(uint32_t& Cycles){
    return PC++;
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
    return data+PC;
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
void CPU::SEC(uint32_t& Cycles){
    C=1;
    Cycles--;
}

//Clear Carry Flag
void CPU::CLC(uint32_t& Cycles){
    C=0;
    Cycles--;
}

//Set Interupt disable Flag
void CPU::SEI(uint32_t& Cycles){
    ID=1;
    Cycles--;
}

//Clear Interupt Disable Flag
void CPU::CLI(uint32_t& Cycles){
    ID=0;
    Cycles--;
}

//Set Decimal Mode Flag
void CPU::SED(uint32_t& Cycles){
    D=1;
    Cycles--;
}

//Clear Decimal Mode Flag
void CPU::CLD(uint32_t& Cycles){
    D=0;
    Cycles--;
}

//Clear OverFlow Flag
void CPU::CLV(uint32_t& Cycles){
    O=0;
    Cycles--;
}

void CPU::LDA(uint32_t& Cycles){
    return;
}