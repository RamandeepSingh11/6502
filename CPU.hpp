#pragma once
#include<iostream>
class CPU
{
    using Byte=unsigned char;
public:
    CPU();
    
    ~CPU();
    //Unknown
    void reset();
    
    //Load or Store Operations
    void LDA(); void LDX(); void LDY(); void STA(); void STX(); void STY();
    
    //Register Transfers
    void TAX(); void TAY(); void TXA(); void TYA();
    
    //Stack Operations
    void TSX(); void TXS(); void PHA(); void PHP(); void PLA(); void PLP();
    
    //Logical Operations
    void AND(); void EOR(); void ORA(); void BIT();
    
    //Arithmetic Operations
    void ADC(); void SBC(); void CMP(); void CPX(); void CPY();
    
    //Increments and Decrements 
    void INC(); void INX(); void INY(); void DEC(); void DEX(); void DEY();
    
    //Shifts
    void ASL(); void LSR(); void ROL(); void ROR();
    
    //Jumps and Calls
    void JMP(); void JSR(); void RTS();
    
    //Branches
    void BCC(); void BCS(); void BEQ(); void BMI(); void BNE(); void BPL(); void BVC(); void BVS();
    
    //Status Flag Changes
    void CLC(); void CLD(); void CLI(); void CLV(); void SEC(); void SED(); void SEI();
    
    //System Functions
    void BRK(); void NOP(); void RTI();
    
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
    Byte C:1;  //Carry Flag Used on Either Overflow of 7th bit or Underflow of 0th bit
    Byte Z:1;  //Set When Result of Last Operation is Zero
    Byte ID:1; //While This Flag is Active The CPU Will not Respond to Interupts from Connected Devices
    Byte D:1;  //Decimal Flag While On Will obey Rules of Binary Coded Decimal arithmetic for add and sub.
    Byte B:1;  //Break Command Used for Generating An Interupt.
    Byte O:1;  //OverFlow Flag Used for Indicating if we get an Invalid 2's Complement
    Byte N:1;  //Negative Flag Used When Result of last Operation is Negative
};
