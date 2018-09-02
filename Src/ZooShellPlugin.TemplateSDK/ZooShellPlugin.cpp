// ZooShellPlugin.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "ZooShellPlugin.h"
#include "Template\Template_Proxy.h"

PLUGIN_INTERFACE g_pi;

PLUGIN_USE_FUNC g_puf;

short szVersion[4] = { 0, 0, 0, 0 };

// 这是导出函数的一个示例。

extern "C"
{
ZOOSHELLPLUGIN_API PPLUGIN_INTERFACE GetInterface(void *p)
{
	g_puf = *(PPLUGIN_USE_FUNC)p;
	//	存在版本号
	if (szVersion[0] & szVersion[1] & szVersion[2] & szVersion[3])
	{
		//	如果Shell版本号小于插件版本号，那么插件加载失败
		if (!((g_puf.szVersion[0] >= szVersion[0]) &&
			(g_puf.szVersion[1] >= szVersion[1]) &&
			(g_puf.szVersion[2] >= szVersion[2]) &&
			(g_puf.szVersion[3] >= szVersion[3])))
		{
			return NULL;
		}
	}
	if (g_puf.ZooShell_Type_GetParamCount == NULL ||
		g_puf.ZooShell_Type_GetParamValue == NULL ||
		g_puf.ZooShell_Type_RegisterLib == NULL ||
		g_puf.ZooShell_Type_SetParamReturnValue == NULL ||
		g_puf.ZooShell_Type_ExecScriptString == NULL)
	{
		return NULL;
	}
	g_pi.ZooShell_Type_GetModuleHelp = ZooShell_Function_GetModuleHelp;
	g_pi.ZooShell_Type_InitEnvironment = ZooShell_Function_InitEnvironment;
	g_pi.ZooShell_Type_GetModuleGlobal = ZooShell_Function_Global;
	g_pi.ZooShell_Type_DestroyEnvironment = ZooShell_Function_DestroyEnvironment;
	return &g_pi;
}
};
