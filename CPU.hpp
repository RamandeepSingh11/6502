#pragma once
#include<iostream>
#include<functional>
#include<Memory.hpp>
#include<vector>
class CPU
{
    using Byte=unsigned char;
public:
    CPU();
    
    ~CPU();
    
    class Instruction{
    public:
        int Cycles;
        std::function<uint16_t(uint32_t&)> addr_mode;
        std::function<void(uint32_t&)> operation;
        bool Illegal=true;
    };
    
    void reset(); void run(); void Execute(uint32_t Cycles=1);
    
    //Fetches The Byte of Memory at Program Counter and Increments it.
    Byte Fetch(uint32_t&);
    
    //Returns The Byte of Memory at A Particular Location.
    Byte FetchLocation(uint32_t&,uint32_t);
    
    //Stores A Byte of Memory in Given Address
    void WriteByte(uint32_t&,uint8_t,uint16_t);
    
    void StackPush(uint32_t&,uint8_t);
    
    uint8_t StackPop(uint32_t&);
    
public:
    //Program Counter Points To next Instruction to Be Executed
    uint16_t PC;
    
    //Stack Pointer Contains a Register that Stores Next Free Location in Stack 
    //Decrements While Pushing and Increments While Pulling
    uint8_t SP; 
    
    //Accumulator Register Used for All Arithmetic and Logical Operations
    uint8_t Acc;
    
    //Index Register X Used for Holding Counters and Offsets for Accessing Memory.
    //And Also Used to Compare Values Stored In Memory.
    //Can Be Used to Retrive The Stack Pointer or Change its Value
    uint8_t X;
    
    //Index Register Y Similar to Register X But Doesn't Allow Copying of StackPointer 
    //and Changing it's value
    uint8_t Y;
    
    //Processor Flags
    uint8_t Status;
    Byte C:1;  //Carry Flag Used on Either Overflow of 7th bit or Underflow of 0th bit
    Byte Z:1;  //Set When Result of Last Operation is Zero
    Byte ID:1; //While This Flag is Active The CPU Will not Respond to Interupts from Connected Devices
    Byte D:1;  //Decimal Flag While On Will obey Rules of Binary Coded Decimal arithmetic for add and sub.
    Byte B:1;  //Break Command Used for Generating An Interupt.
    Byte Unused:1;  //Normally It is Unused 
    Byte O:1;  //OverFlow Flag Used for Indicating if we get an Invalid 2's Complement
    Byte N:1;  //Negative Flag Used When Result of last Operation is Negative
    
    void UpdateStatus();
public:
    //Addressing Modes
    uint16_t Implied(uint32_t&);
    uint16_t Accumulator(uint32_t&);
    uint16_t IMM(uint32_t&);
    uint16_t ZeroPage(uint32_t&);
    uint16_t ZeroPageX(uint32_t&);
    uint16_t ZeroPageY(uint32_t&);
    uint16_t Relative(uint32_t&);
    uint16_t Absolute(uint32_t&);
    uint16_t AbsoluteX(uint32_t&);
    uint16_t AbsoluteY(uint32_t&);
    uint16_t Indirect(uint32_t&);
    uint16_t IndirectY(uint32_t&);
    uint16_t IndirectX(uint32_t&);
public:
    //Load or Store Operations
    void LDA(uint32_t&); void LDX(uint32_t&); void LDY(uint32_t&); void STA(uint32_t&); void STX(uint32_t&); void STY(uint32_t&);
    
    //Register Transfers
    void TAX(uint32_t&); void TAY(uint32_t&); void TXA(uint32_t&); void TYA(uint32_t&);
    
    //Stack Operations
    void TSX(uint32_t&); void TXS(uint32_t&); void PHA(uint32_t&); void PHP(uint32_t&); void PLA(uint32_t&); void PLP(uint32_t&);
    
    //Logical Operations
    void AND(uint32_t&); void EOR(uint32_t&); void ORA(uint32_t&); void BIT(uint32_t&);
    
    //Arithmetic Operations
    void ADC(uint32_t&); void SBC(uint32_t&); void CMP(uint32_t&); void CPX(uint32_t&); void CPY(uint32_t&);
    
    //Increments and Decrements 
    void INC(uint32_t&); void INX(uint32_t&); void INY(uint32_t&); void DEC(uint32_t&); void DEX(uint32_t&); void DEY(uint32_t&);
    
    //Shifts
    void ASL(uint32_t&); void LSR(uint32_t&); void ROL(uint32_t&); void ROR(uint32_t&);
    
    //Jumps and Calls
    void JMP(uint32_t&); void JSR(uint32_t&); void RTS(uint32_t&);
    
    //Branches
    void BCC(uint32_t&); void BCS(uint32_t&); void BEQ(uint32_t&); void BMI(uint32_t&); void BNE(uint32_t&); 
    void BPL(uint32_t&); void BVC(uint32_t&); void BVS(uint32_t&);
    
    //Status Flag Changes
    void CLC(uint32_t&); void CLD(uint32_t&); void CLI(uint32_t&); void CLV(uint32_t&); void SEC(uint32_t&); void SED(uint32_t&);
    void SEI(uint32_t&);
    
    //System Functions
    void BRK(uint32_t&); void NOP(uint32_t&); void RTI(uint32_t&);
public: 
    Memory InternalRegister=Memory();
private:
    std::vector<Instruction> Lookup;
    uint16_t CurrAddr;
    const uint16_t ResetVector=0xFFFC,InterruptVector=0xFFFE;
    bool AddrAcc=0;
};