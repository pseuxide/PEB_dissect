#include <iostream>

#include "PEB_dissect.h"

// handy func.
LPVOID mw32GetPeb() {
#if defined(_WIN64)
	UINT64 uiPeb = __readgsqword(0x60);
	return (LPVOID) (UINT_PTR) uiPeb;
#else
	UINT32 uiPeb = __readfsdword(0x30);
	return (LPVOID) (UINT_PTR) uiPeb;
#endif
}

int main()
{
	// Using this would let u grab PEB easily, but more bratant.
	HMODULE hModule = GetModuleHandle("ntdll.dll");
	std::cout << "RtlGetCurrentPeb --> " << GetProcAddress(hModule, "RtlGetCurrentPeb") << std::endl;

	// Prints ImagePathName
	std::cout << reinterpret_cast<PPEB>(mw32GetPeb())->ProcessParameters->ImagePathName.Buffer << std::endl;

	getchar();
	return 0;
}
