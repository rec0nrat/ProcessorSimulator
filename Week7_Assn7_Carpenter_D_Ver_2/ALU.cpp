#include "ALU.h"
using namespace alu;

ALU::ALU() {}
ALU::~ALU() {}

DWORD64 ALU::AND(DWORD64 value, DWORD64 by){return (value & by);}
DWORD64 ALU::ADD(DWORD64 value, DWORD64 by){return (value + by);}
DWORD64 ALU::NOT(DWORD64 value, DWORD64 by){return (~value);}
DWORD64 ALU::OR(DWORD64 value, DWORD64 by) {return (value | by);}
DWORD64 ALU::SUB(DWORD64 value, DWORD64 by){return (value - by);}
DWORD64 ALU::XOR(DWORD64 value, DWORD64 by){return (value ^ by);}

