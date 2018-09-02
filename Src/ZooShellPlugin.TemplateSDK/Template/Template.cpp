#include "stdafx.h"
#include "Template.h"
#include <windows.h>
#include <stdio.h>

//	TODO：增加真实函数实现

int MAKE_FUNC_REAL_FUNCTION(MessageBoxA)(_In_opt_ HWND hWnd, _In_opt_ LPCSTR lpText, _In_opt_ LPCSTR lpCaption, _In_ UINT uType)
{
	return MessageBoxA(hWnd, lpText, lpCaption, uType);
}
