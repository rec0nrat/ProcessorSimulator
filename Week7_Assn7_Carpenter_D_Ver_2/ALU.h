#include "Include.h"

class ALU
{
private:

public:
	ALU();

	DWORD64 and(DWORD64 value, DWORD64 by);
	DWORD64 add(DWORD64 value, DWORD64 by);
	DWORD64 not(DWORD64 value, DWORD64 by);
	DWORD64 or (DWORD64 value, DWORD64 by);
	DWORD64 sub(DWORD64 value, DWORD64 by);
	DWORD64 xor(DWORD64 value, DWORD64 by);

	~ALU();

};