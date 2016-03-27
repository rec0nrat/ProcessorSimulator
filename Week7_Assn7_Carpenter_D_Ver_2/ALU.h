#include "Include.h"

namespace alu {

	class ALU
	{

	private:

	public:
		
		DWORD64 AND (DWORD64 value, DWORD64 by);
		DWORD64 ADD(DWORD64 value, DWORD64 by);
		DWORD64 NOT (DWORD64 value, DWORD64 by);
		DWORD64 OR (DWORD64 value, DWORD64 by);
		DWORD64 SUB(DWORD64 value, DWORD64 by);
		DWORD64 XOR (DWORD64 value, DWORD64 by);

		ALU();
		~ALU();
	};
}
