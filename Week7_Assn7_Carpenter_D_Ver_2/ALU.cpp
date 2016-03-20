#include "ALU.h"

ALU::ALU(){
}

DWORD64 ALU:: and (DWORD64 value, DWORD64 by)
{
	return (value & by);
}

DWORD64 ALU::add(DWORD64 value, DWORD64 by)
{
	return (value + by);
}

DWORD64 ALU::not(DWORD64 value, DWORD64 by)
{
	return(~value);
}

DWORD64 ALU:: or (DWORD64 value, DWORD64 by)
{
	return (value | by);
}

DWORD64 ALU::sub(DWORD64 value, DWORD64 by)
{
	return (value - by);
}

DWORD64 ALU:: xor (DWORD64 value, DWORD64 by)
{
	return (value ^ by);
}

ALU::~ALU(){

}

