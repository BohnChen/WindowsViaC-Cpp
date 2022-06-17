#include <windows.h>

int main() 
{
	DWORD dwError = GetDlgItemInt(hwnd, IDC_ERRORCODE, NULL, FALSE);
	return 0;
}
