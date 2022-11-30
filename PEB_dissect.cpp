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

using namespace std;

int main()
{
	HMODULE hModule = GetModuleHandle("ntdll.dll");
	cout << GetProcAddress(hModule, "RtlGetCurrentPeb") << endl;
	cout << (short)reinterpret_cast<PPEB>(mw32GetPeb())->BeingDebugged << endl;
	getchar();
	return 0;
}
