#include <iostream>
#include <windows.h>

using std::string;
using std::cout;
using std::endl;
using std::runtime_error;

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
HINSTANCE hInstance;

// Добавление первого комментария.
// Добавление второго комментария.

int main() {
	
	try
	{
		hInstance = GetModuleHandle(nullptr);

		WNDCLASSEX windowClassCreateInfo;
		windowClassCreateInfo.cbSize = sizeof(WNDCLASSEX);
		windowClassCreateInfo.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
		windowClassCreateInfo.cbClsExtra = 0;
		windowClassCreateInfo.cbWndExtra = 0;
		windowClassCreateInfo.hInstance = hInstance;
		windowClassCreateInfo.hIcon = LoadIcon(hInstance, IDI_APPLICATION);
		windowClassCreateInfo.hIconSm = LoadIcon(hInstance, IDI_APPLICATION);
		windowClassCreateInfo.hCursor = LoadCursor(nullptr, IDC_ARROW);
		windowClassCreateInfo.hbrBackground = CreateSolidBrush(RGB(240, 240, 240));
		windowClassCreateInfo.lpszMenuName = nullptr;
		windowClassCreateInfo.lpszClassName = TEXT("AppWindowClass");
		windowClassCreateInfo.lpfnWndProc = WndProc;

		if (!RegisterClassEx(&windowClassCreateInfo)) throw runtime_error("Can't to create Window Class");

		HWND hWnd = CreateWindow(TEXT("AppWindowClass"), TEXT("Quartz"), WS_OVERLAPPEDWINDOW, 0, 0, 640, 480, nullptr, nullptr, hInstance, nullptr);

		if (hWnd == 0) throw runtime_error("Can't to create Window Handle.");

		ShowWindow(hWnd, SW_SHOWNORMAL);

		MSG message = {};

		while (true) {
			if (PeekMessage(&message, nullptr, 0, 0, PM_REMOVE))
			{
				DispatchMessage(&message);
				if (message.message == WM_QUIT) break;
			}
		}

		return 0;
	}
	catch (std::runtime_error& err)
	{
		cout << err.what() << endl;
		system("pause");
	}
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		// Уничтожение окна
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}

	return 0;
}