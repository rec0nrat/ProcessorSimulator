#include "Include.h"

namespace alu {

	class ALU
	{

	private:

	public:
		
		DWORD64 AND (DWORD64 src, DWORD64 dest);
		DWORD64 ADD(DWORD64 src, DWORD64 dest);
		DWORD64 NOT (DWORD64 src, DWORD64 dest);
		DWORD64 OR (DWORD64 src, DWORD64 dest);
		DWORD64 SUB(DWORD64 src, DWORD64 dest);
		DWORD64 XOR (DWORD64 src, DWORD64 dest);

		ALU();
		~ALU();
	};
}
