#pragma once

//	TODO：修改模块名字等等一系列信息

//	模块名字
#define SPECIFY_MODE_MODENAME					TemplateSDK
//	字符串模块名字
#define SPECIFY_MODE_MODENAME_STRING			"TemplateSDK"
//	模块帮助
#define SPECIFY_MODE_MODENAME_HELP				"TemplateSDK 框架"

//
#define MAKE_FUNC_REAL_NAME(_MODE_, _FUNC_NAME_) ZooShell_ ## _MODE_ ## _ ## _FUNC_NAME_

//	最终执行的C函数名字
#define MAKE_FUNC_REAL_FUNCTION(_FUNC_NAME_)	MAKE_FUNC_REAL_NAME(Template, _FUNC_NAME_)

//	代理函数名字
#define MAKE_FUNC_PROXY_FUNCTION(_FUNC_NAME_)	MAKE_FUNC_PROXY_NAME(Template, _FUNC_NAME_)


int MAKE_FUNC_REAL_FUNCTION(MessageBoxA)(_In_opt_ HWND hWnd, _In_opt_ LPCSTR lpText, _In_opt_ LPCSTR lpCaption, _In_ UINT uType);