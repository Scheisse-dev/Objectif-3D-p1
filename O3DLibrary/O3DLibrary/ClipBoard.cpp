#include "ClipBoard.h"
#include "FString.h"
#include "Exception.h"
#include <CoreWindow.h>

void Core::ClipBoard::Copy(const PrimitiveType::FString& _text)
{
	if (!OpenClipboard(nullptr))
		throw Exception("[ClipBoard] => Failed to open clipboard !");
	if (!EmptyClipboard())
		throw Exception("[ClipBoard] => Failed to empty the clipboard");

	std::wstring _str = _text.ToWString();
	const wchar_t* _textWchar = _str.c_str();
	const size_t _length = (std::wcslen(_textWchar) + 1) * sizeof(wchar_t);
	if (const HANDLE _handle = GlobalAlloc(GMEM_MOVEABLE, _length))
	{
		memcpy(GlobalLock(_handle), _textWchar, _length);
		GlobalUnlock(_handle); 
		SetClipboardData(CF_UNICODETEXT, _handle);
	}
	CloseClipboard();
}