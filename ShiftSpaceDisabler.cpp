#define _WIN32_WINNT 0x0500
#include <Windows.h>
#include <iostream>
#define HOTKEY_ID 0x53C8

/*
	KeyCode of HotKey at below url  
	https://blog.xuite.net/jack.b6539/vb/12834758-%E9%8D%B5%E7%9B%A4keycode%E5%B0%8D%E6%87%89%E8%A1%A8
*/

using std::cout;
using std::endl;

int main()
{
	
	// hide the window when this app is running
	HWND hWnd = GetConsoleWindow();
	ShowWindow( hWnd, SW_HIDE );
	
	// register 'alt + 5' key press
	if (RegisterHotKey(NULL, HOTKEY_ID, MOD_SHIFT, 0x20))
	{
		cout << "Successfully registered SHIFT + SPACE global hotkey" << endl;
	}

	MSG winMessage = { 0 };

	// perpetually wait until a message is received
	while (GetMessage(&winMessage, NULL, 0, 0))
	{
		if (winMessage.message == WM_HOTKEY)
		{
			cout << "Received hotkey message" << endl;
		}
	}

	// unregister the hotkey
	if (UnregisterHotKey(NULL, HOTKEY_ID))
	{
		cout << "Successfully unregistered hotkey" << endl;
	}

	return 0;
}
