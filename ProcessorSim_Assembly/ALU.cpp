#include "ALU.h"

using namespace alu;

ALU::ALU() {}
ALU::~ALU() {}
//Mathematical functions to add subtract, negate, XOR and OR
DWORD64 ALU::AND(DWORD64 src, DWORD64 dest){return (src & dest);}
DWORD64 ALU::ADD(DWORD64 src, DWORD64 dest){return (src + dest);}
DWORD64 ALU::NOT(DWORD64 src, DWORD64 dest){return (~src);}
DWORD64 ALU::OR(DWORD64 src,  DWORD64 dest){return (src | dest);}
DWORD64 ALU::SUB(DWORD64 src, DWORD64 dest){return (src - dest);}
DWORD64 ALU::XOR(DWORD64 src, DWORD64 dest){return (src ^ dest);}

