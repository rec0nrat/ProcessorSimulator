#include "Include.h"

namespace alu {
	class ALU
	{

	private:

	public:
		
		DWORD64 AND (DWORD64 value, DWORD64 by);
		DWORD64 add(DWORD64 value, DWORD64 by);
		DWORD64 not (DWORD64 value, DWORD64 by);
		DWORD64 or (DWORD64 value, DWORD64 by);
		DWORD64 sub(DWORD64 value, DWORD64 by);
		DWORD64 xor (DWORD64 value, DWORD64 by);

		ALU();
		~ALU();
	};
}
