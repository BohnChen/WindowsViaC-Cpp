#include <Windows.h>
#include <iostream>
using namespace std;

// Tell compiler that we need to find the info exported from dll
#pragma comment(lib, "..\\debug\\TestDllMode.dll") 

// 
extern "C" int Add(int nLeft, int nRight);
void StaticUseDll()
{
	int _nTemp1 = 10;
	int _nTemp2 = 20;
	int sum = Add(_nTemp1, _nTemp2);
	cout << "The result of static call is " << sum << endl;
}



void DynamicUseDll()
{
	// Degine a pointer to a function
	typedef int(*AddFunc)(int nLeft, int nRight);

	// 
	HINSTANCE module = LoadLibrary(L"..\\Debug\\TestDllMode.dll");

	// module == nullptr reprents fail
	if (NULL == module)
	{
		cout << " load TestDllMode.dll failed!" << endl;
		return;
	}

	// Get the dll adress for process.
	AddFunc _pAdd = (AddFunc)GetProcAddress(module, "Add");

	// Now, GetProcAddress failed.
	if (_pAdd == NULL)
	{
		cout << "The function pointer is NULL " << endl;
		return;
	}
	 
	int _nTemp1 = 10;
	int _nTemp2 = 20;
	int sum = _pAdd(_nTemp1, _nTemp2);
	cout << "Dynamic call of dll , The sum = " << sum << endl;
}


int main(int argc, char* argv[])
{
	
	StaticUseDll();
	DynamicUseDll();
}