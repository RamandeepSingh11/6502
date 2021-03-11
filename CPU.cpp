#include "CPU.hpp"
CPU::CPU(){
    for(int i=0;i<256;i++){
        Lookup.push_back({0,nullptr,nullptr});
    }
    Instruction temp;
    
    //Lookup for ADC.....................................................................
    
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
    
    //Lookup for AND.....................................................................
    
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
    
    //Lookup for ASL.....................................................................
    
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
    
    //Lookup for BCC.....................................................................
    
    temp.Cycles=2;
    temp.addr_mode=std::bind(&CPU::Relative,this,std::placeholders::_1);
    temp.operation=std::bind(&CPU::BCC,this,std::placeholders::_1);
    Lookup[0x90]=temp;
    
    //Lookup for BCS.....................................................................
    
    temp.operation=std::bind(&CPU::BCS,this,std::placeholders::_1);
    Lookup[0xB0]=temp;
    
    //Lookup for BEQ.....................................................................
    
    temp.operation=std::bind(&CPU::BEQ,this,std::placeholders::_1);
    Lookup[0xF0]=temp;
    
    //Lookup for BIT.....................................................................
    
    temp.Cycles=3;
    temp.addr_mode=std::bind(&CPU::ZeroPage,this,std::placeholders::_1);
    temp.operation=std::bind(&CPU::BIT,this,std::placeholders::_1);    
    Lookup[0x24]=temp;
    
    temp.Cycles=4;
    temp.addr_mode=std::bind(&CPU::Absolute,this,std::placeholders::_1);
    Lookup[0x2C]=temp;
    
    //Lookup for BMI.....................................................................
    
    temp.Cycles=2;
    temp.addr_mode=std::bind(&CPU::Relative,this,std::placeholders::_1);
    temp.operation=std::bind(&CPU::BMI,this,std::placeholders::_1);
    Lookup[0x30]=temp;
    
    //Lookup for BNE.....................................................................
    
    temp.operation=std::bind(&CPU::BNE,this,std::placeholders::_1);
    Lookup[0xD0]=temp;
    
    //Lookup for BPL.....................................................................
    
    temp.operation=std::bind(&CPU::BPL,this,std::placeholders::_1);
    Lookup[0x10]=temp;
    
    //Lookup for BRK.....................................................................
    
    temp.Cycles=7;
    temp.addr_mode=std::bind(&CPU::Implied,this,std::placeholders::_1);
    temp.operation=std::bind(&CPU::BRK,this,std::placeholders::_1);
    Lookup[0x00]=temp;
    
    //Lookup for BVC.....................................................................
    
    temp.Cycles=2;
    temp.addr_mode=std::bind(&CPU::Relative,this,std::placeholders::_1);
    temp.operation=std::bind(&CPU::BVC,this,std::placeholders::_1);
    Lookup[0x50]=temp;
    
    //Lookup for BVS.....................................................................
    
    temp.operation=std::bind(&CPU::BVS,this,std::placeholders::_1);
    Lookup[0x70]=temp;
    
    //Lookup for CLC.....................................................................
    
    temp.addr_mode=std::bind(&CPU::Implied,this,std::placeholders::_1);
    temp.operation=std::bind(&CPU::CLC,this,std::placeholders::_1);
    Lookup[0x18]=temp;
    
    //Lookup for CLD.....................................................................
    
    temp.operation=std::bind(&CPU::CLD,this,std::placeholders::_1);
    Lookup[0xD8]=temp;
    
    //Lookup for CLI.....................................................................
    
    temp.operation=std::bind(&CPU::CLI,this,std::placeholders::_1);
    Lookup[0x58]=temp;
    
    //Lookup for CLV.....................................................................
    
    temp.operation=std::bind(&CPU::CLV,this,std::placeholders::_1);
    Lookup[0xB8]=temp;
    
    //Lookup for CMP..................................................................... 
    
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
    
    //Lookup for CPX.....................................................................
    
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
    
    //Lookup for CPY.....................................................................
    
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
    
    //Lookup for DEC.....................................................................
    
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
    
    //Lookup for DEX.....................................................................
    
    temp.Cycles=2;
    temp.addr_mode=std::bind(&CPU::Implied,this,std::placeholders::_1);
    temp.operation=std::bind(&CPU::DEX,this,std::placeholders::_1);
    Lookup[0xCA]=temp;
    
    //Lookup for DEY.....................................................................
    
    temp.operation=std::bind(&CPU::DEY,this,std::placeholders::_1);
    Lookup[0x88]=temp;
    
    //Lookup for EOR.....................................................................
    
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
    
    //Lookup for INC.....................................................................
    
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
    temp.addr_mode = std::bind(&CPU::ZeroPageX, this, std::placeholders::_1);
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
    Unused=1;
    SP=0XFD;
    Status=0;
    PC=InternalRegister[ResetVector+1]<<8;
    PC|=InternalRegister[ResetVector];
}

void CPU::UpdateStatus(){
    Status=0;
    Unused=1;
    Status|=C;
    Status|=(Z<<1);
    Status|=(ID<<2);
    Status|=(D<<3);
    Status|=(1<<4);
    Status|=(Unused<<5);
    Status|=(O<<6);
    Status|=(N<<7);
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

void CPU::WriteByte(uint32_t& Cycles,uint8_t Data,uint16_t Address){
    InternalRegister[Address]=Data;
    Cycles--;
}

void CPU::StackPush(uint32_t& Cycles,uint8_t Data){
    WriteByte(Cycles,Data,0x100+SP);
    if(SP==0)SP=0xFF;
    else SP--;
}

uint8_t CPU::StackPop(uint32_t& Cycles){
    if(SP==0xFF)SP=0x00;
    else ++SP;
    return InternalRegister[0x100+SP];
}

uint16_t CPU::Accumulator(uint32_t& Cycles){
    AddrAcc=true;
    return 0;
}
uint16_t CPU::Implied(uint32_t& Cycles){
    AddrAcc=false;
    return 0;
}
uint16_t CPU::IMM(uint32_t& Cycles){
    AddrAcc=false;
    return PC++;
}
//Returns The Data From Least Signifcant Byte. Making it Faster
uint16_t CPU::ZeroPage(uint32_t& Cycles){
    AddrAcc=false;
    return Fetch(Cycles);
}

//Grabs The Address in Zero Page Addressing and Then Adds A offset X to the Address
//The Address wraps around 0xFF
uint16_t CPU::ZeroPageX(uint32_t& Cycles){
    AddrAcc=false;
    uint16_t data=Fetch(Cycles);
    data+=X;
    data&=0xFF;
    Cycles--;
    return data;
}

//Grabs The Address in Zero Page Addressing and Then Adds A offset Y to the Address
//Again The Address Wraps Around 0xFF
uint16_t CPU::ZeroPageY(uint32_t& Cycles){
    AddrAcc=false;
    uint16_t data=Fetch(Cycles);
    data+=Y;
    data&=0xFF;
    Cycles--;
    return data;
}
//Not Sure
uint16_t CPU::Relative(uint32_t& Cycles){
    AddrAcc=false;
    uint16_t data=Fetch(Cycles);
    if(data&0x80){
        data|=0xFF00;
    }
    return data+PC;
}

//Gives A Full 16Bit Address. Has To Perfome Two Fetch Hence Takes 2 Clock Cycles
uint16_t CPU::Absolute(uint32_t& Cycles){
    AddrAcc=false;
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
    AddrAcc=false;
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
    AddrAcc=false;
    uint16_t ptrl=(Fetch(Cycles)+X)&0xFF;
    Cycles--;
    uint16_t ptrr=(ptrl+1)&0xFF;
    uint16_t res=FetchLocation(Cycles,ptrl)|(FetchLocation(Cycles,ptrr)<<8);
    return res;
}

//Grabs The Zero Page Address and Then Fetches the Word at That Location And adds Y as an Offset.
uint16_t CPU::IndirectY(uint32_t& Cycles){
    AddrAcc=false;
    uint16_t ptr=(Fetch(Cycles));
    uint16_t res=(FetchLocation(Cycles,ptr)|(FetchLocation(Cycles,(ptr+1)&0xFF)<<8))+Y;
    return res;
}

//Operations

//Set Carry Flag
void CPU::SEC(uint32_t& Cycles){
    C=1;
}

//Clear Carry Flag
void CPU::CLC(uint32_t& Cycles){
    C=0;
}

//Set Interupt disable Flag
void CPU::SEI(uint32_t& Cycles){
    ID=1;
}

//Clear Interupt Disable Flag
void CPU::CLI(uint32_t& Cycles){
    ID=0;
}

//Set Decimal Mode Flag
void CPU::SED(uint32_t& Cycles){
    D=1;
}

//Clear Decimal Mode Flag
void CPU::CLD(uint32_t& Cycles){
    D=0;
}

//Clear OverFlow Flag
void CPU::CLV(uint32_t& Cycles){
    O=0;
}

void CPU::LDA(uint32_t& Cycles){
    Acc=FetchLocation(Cycles,CurrAddr);
    Z=(Acc==0);
    N=(Acc&0x80)>0;
}

void CPU::LDX(uint32_t& Cycles){
    X=FetchLocation(Cycles,CurrAddr);
    Z=(X==0);
    N=(X&0x80)>0;
}

void CPU::LDY(uint32_t& Cycles){
    Y=FetchLocation(Cycles,CurrAddr);
    Z=(Y==0);
    N=(Y&0x80)>0;
}

void CPU::STA(uint32_t& Cycles){
    WriteByte(Cycles,Acc,CurrAddr);
}

void CPU::STX(uint32_t& Cycles){
    WriteByte(Cycles,X,CurrAddr);
}

void CPU::STY(uint32_t& Cycles){
    WriteByte(Cycles,Y,CurrAddr);
}

void CPU::TAX(uint32_t& Cycles){
    X=Acc;
    Z=(X==0);
    N=(X&0x80)>0;
}

void CPU::TAY(uint32_t& Cycles){
    Y=Acc;
    Z=(Y==0);
    N=(Y&0x80)>0;
}

void CPU::TXA(uint32_t& Cycles){
    Acc=X;
    Z=(Acc==0);
    N=(Acc&0x80)>0;
}

void CPU::TYA(uint32_t& Cycles){
    Acc=Y;
    Z=(Acc==0);
    N=(Acc&0x80)>0;
}

void CPU::TSX(uint32_t& Cycles){
    X=SP;
    Z=(X==0);
    N=(X&0x80)>0;
}

void CPU::TXS(uint32_t& Cycles){
    SP=X;
}

void CPU::PHA(uint32_t& Cycles){
    StackPush(Cycles,Acc);
}

void CPU::PHP(uint32_t& Cycles){
    UpdateStatus();
    StackPush(Cycles,Status);
}

void CPU::PLA(uint32_t& Cycles){
    Acc=StackPop(Cycles);
    Z=(Acc==0);
    N=(Acc&0x80)>0;
}

void CPU::PLP(uint32_t& Cycles){
    uint8_t temp=StackPop(Cycles);
    C=temp&1;
    Z=temp&(1<<1);
    ID=temp&(1<<2);
    D=temp&(1<<3);
    B=temp&(1<<4);
    Unused=1;
    O=temp&(1<<6);
    N=temp&(1<<7);
}

void CPU::AND(uint32_t& Cycles){
    Acc&=FetchLocation(Cycles,CurrAddr);
    Z=(Acc==0);
    N=(Acc&0x80)>0;
}

void CPU::EOR(uint32_t& Cycles){
    Acc^=FetchLocation(Cycles,CurrAddr);
    Z=(Acc==0);
    N=(Acc&0x80)>0;
}

void CPU::ORA(uint32_t& Cycles){
    Acc|=FetchLocation(Cycles,CurrAddr);
    Z=(Acc==0);
    N=(Acc&0x80)>0;
}

void CPU::BIT(uint32_t& Cycles){
    uint8_t data=FetchLocation(Cycles,CurrAddr),temp=data&Acc;
    Z=(temp==0);
    N=(data&(1<<7))>0;
    O=(data&(1<<6))>0;
}

//Arithmetic Operations

void CPU::ADC(uint32_t& Cycles){
    //Decimal Mode Not Implemented
    uint16_t data=FetchLocation(Cycles,CurrAddr),temp=data;
    data+=Acc+C;
    Z=((data&0x00FF)==0);
    C=(data>0x00FF);
    N=(data&0x0080)>0;
    O=((!((Acc^temp)&0x80)) & ((Acc^data)&0x80));
    Acc=data&0x00FF;
}

void CPU::SBC(uint32_t& Cycles){
    uint16_t data=FetchLocation(Cycles,CurrAddr)^0x00FF,temp=data;
    data=data+Acc+C;
    C=(data>0x00FF);
    N=(data&0x0080)>0;
    Z=((data&0x00FF)==0);
    O=((!((Acc^temp)&0x80)) && ((Acc^data)&0x80));
    Acc=data&0x00FF;
    
}

void CPU::CMP(uint32_t& Cycles){
    uint16_t data=(uint16_t)Acc-(uint16_t)FetchLocation(Cycles,CurrAddr);
    Z=(!(data&0xFF));
    //Cause If The Fetched Byte is Greater Than Acc then the Value will wrap around and we'll get 0xFFxx
    //So if The Value is Smaller the The 0x100 that ensures that The Result has not Wrapped around and Fetched Data is
    //Smaller than Acc
    C=(data<0x100);
    N=(data&0x80);
}

void CPU::CPX(uint32_t& Cycles){
    uint16_t data=(uint16_t)X-(uint16_t)FetchLocation(Cycles,CurrAddr);
    Z=(!(data&0xFF));
    //Cause If The Fetched Byte is Greater Than X then the Value will wrap around and we'll get 0xFFxx
    //So if The Value is Smaller the The 0x100 that ensures that The Result has not Wrapped around and Fetched Data is
    //Smaller than X
    C=(data<0x100);
    N=(data&0x80);
}

void CPU::CPY(uint32_t& Cycles){
    uint16_t data=(uint16_t)Y-(uint16_t)FetchLocation(Cycles,CurrAddr);
    Z=(!(data&0xFF));
    //Cause If The Fetched Byte is Greater Than Y then the Value will wrap around and we'll get 0xFFxx
    //So if The Value is Smaller the The 0x100 that ensures that The Result has not Wrapped around and Fetched Data is
    //Smaller than Y
    C=(data<0x100);
    N=(data&0x80);
}

//Increment Operations

void CPU::INC(uint32_t& Cycles){
    uint8_t data=FetchLocation(Cycles,CurrAddr);
    data=(data+1)&0xFF;
    WriteByte(Cycles,data,CurrAddr);
    Z=(data==0);
    N=(data&0x80)>0;
}

void CPU::INX(uint32_t& Cycles){
    X++;
    Z=(X==0);
    N=(X&0x80)>0;
}

void CPU::INY(uint32_t& Cycles){
    Y++;
    Z=(Y==0);
    N=(Y&0x80)>0;
}

void CPU::DEC(uint32_t& Cycles){
    uint8_t data=FetchLocation(Cycles,CurrAddr);
    data=(data-1)&0xFF;
    WriteByte(Cycles,data,CurrAddr);
    Z=(data==0);
    N=(data&0x80)>0;
}

void CPU::DEX(uint32_t& Cycles){
    X--;
    Z=(X==0);
    N=(X&0x80)>0;
}

void CPU::DEY(uint32_t& Cycles){
    Y--;
    Z=(Y==0);
    N=(Y&0x80)>0;
}

//Shift Operations

void CPU::ASL(uint32_t& Cycles){
    uint8_t data;
    if(AddrAcc)data=Acc;
    else data=FetchLocation(Cycles,CurrAddr);
    C=(data&0x80)>1;
    data<<=1;
    data&=0xFF;
    Z=(data==0);
    N=(data&0x80)>1;
    if(AddrAcc)Acc=data;
    else WriteByte(Cycles,data,CurrAddr);
    AddrAcc=false;
}

void CPU::LSR(uint32_t& Cycles){
    uint8_t data;
    if(AddrAcc)data=Acc;
    else data=FetchLocation(Cycles,CurrAddr);
    C=(data&0x01)>1;
    data>>=1;
    Z=(data==0);
    N=(data&0x80)>1;
    if(AddrAcc)Acc=data;
    else WriteByte(Cycles,data,CurrAddr);
    AddrAcc=false;
}

void CPU::ROL(uint32_t& Cycles){
    uint16_t data;
    if(AddrAcc)data=Acc;
    else data=FetchLocation(Cycles,CurrAddr);
    data<<=1;
    data=data|C;
    C=data>0xFF;
    data&=0xFF;
    Z=(data==0);
    N=(data&0x80)>1;
    if(AddrAcc)Acc=data;
    else WriteByte(Cycles,data,CurrAddr);
    AddrAcc=false;
}

void CPU::ROR(uint32_t& Cycles){
    uint16_t data;
    if(AddrAcc)data=Acc;
    else FetchLocation(Cycles,CurrAddr);
    data=data|(C<<8);
    C=(data&0x01)>1;
    data>>=1;
    data&=0xFF;
    Z=(data==0);
    N=(data&0x80)>1;
    if(AddrAcc)Acc=data;
    else WriteByte(Cycles,data,CurrAddr);
    AddrAcc=false;
}

void CPU::JMP(uint32_t& Cycles){
    PC=CurrAddr;
}

void CPU::JSR(uint32_t& Cycles){
    PC--;
    StackPush(Cycles,PC>>8);
    StackPush(Cycles,PC&0xFF);
    PC=CurrAddr;
}

void CPU::RTS(uint32_t& Cycles){
    PC=StackPop(Cycles);
    PC|=StackPop(Cycles)<<8;
    PC++;
}

void CPU::BCC(uint32_t& Cycles){
    if(C==0)PC=CurrAddr;
}

void CPU::BCS(uint32_t& Cycles){
    if(C)PC=CurrAddr;
}

void CPU::BEQ(uint32_t& Cycles){
    if(Z)PC=CurrAddr;
}

void CPU::BMI(uint32_t& Cycles){
    if(N)PC=CurrAddr;
}

void CPU::BNE(uint32_t& Cycles){
    if(!Z)PC=CurrAddr;
}

void CPU::BPL(uint32_t& Cycles){
    if(!N)PC=CurrAddr;
}

void CPU::BVC(uint32_t& Cycles){
    if(!O)PC=CurrAddr;
}

void CPU::BVS(uint32_t& Cycles){
    if(O)PC=CurrAddr;
}


//Still in Progress CHECK.........................................
void CPU::BRK(uint32_t& Cycles){
    B=1;
    PC++;
    StackPush(Cycles,PC>>8);
    StackPush(Cycles,PC&0xFF);
    UpdateStatus();
    StackPush(Cycles,Status);
    ID=1;
    PC=FetchLocation(Cycles,InterruptVector);
    PC|=FetchLocation(Cycles,InterruptVector+1)<<8;
}

void CPU::NOP(uint32_t& Cycles){
    return;
}

//Execution
void CPU::Execute(uint32_t Cycles){
    uint8_t opcode=Fetch(Cycles);
    const Instruction& temp=Lookup[opcode];
    if(!temp.Illegal){
        Cycles=temp.Cycles-1;
        CurrAddr=temp.addr_mode(Cycles);
        temp.operation(Cycles);
    }
    if(Cycles!=0){
        std::cout<<"Something Went Wrong With Opcode: "<<opcode<<std::endl;
    }
}