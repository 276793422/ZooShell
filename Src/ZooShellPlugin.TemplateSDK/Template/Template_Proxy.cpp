#include "stdafx.h"
#include "Template.h"
#include "Template_Proxy.h"
#include <stdlib.h>



int MAKE_FUNC_PROXY_FUNCTION(MessageBoxA)(void * L)
{
	int argc = ZooShell_GetParamCount(L);
	ZOO_PVOID h = ZooShell_GetParamTypeUnknow(L, 1);
	ZOO_STRING msg = ZooShell_GetParamTypeString(L, 2);
	ZOO_STRING title = ZooShell_GetParamTypeString(L, 3);
	ZOO_UINT mb = ZooShell_GetParamTypeUInteger(L, 4);
	ZOO_INT ret = (ZOO_INT)MAKE_FUNC_REAL_FUNCTION(MessageBoxA)((HWND)h, (char *)msg, (char *)title, (UINT)mb);
	ZooShell_PushReturnValueInteger(L, ret);
	return 1;
}




static MODULE_FUNCTION_LIST _zoo_mode_func_list =
{
	{ MODULE_FUNCTION_TYPE_INFORM, { SPECIFY_MODE_MODENAME_STRING, NULL, NULL, SPECIFY_MODE_MODENAME_HELP }, 0 },
	{
		{ MODULE_FUNCTION_TYPE_PUBLIC, { "MessageBox", MAKE_FUNC_PROXY_FUNCTION(MessageBoxA), "int MessageBox(HWND, char*, char*, DWORD)", "弹出一个消息窗" }, 0 },
	}
};

static PMODULE_CALL_TABLE _zoo_mode_fun_list_lib = NULL;

UINT GetListFuncCount(void* p)
{
	PMODULE_FUNCTION_LIST pfl = (PMODULE_FUNCTION_LIST)p;
	UINT i;
	for (i = 0;; i++)
	{
		if ((pfl->sModuleList[i].uType == MODULE_FUNCTION_TYPE_UNKNOW) ||
			(pfl->sModuleList[i].info.szName == NULL) ||
			(pfl->sModuleList[i].info.pFunc == NULL) ||
			(pfl->sModuleList[i].info.szSrc == NULL) ||
			(pfl->sModuleList[i].info.szHelp == NULL))
		{
			break;
		}
	}
	return i;
}

static void* MakeModuleCallTable(void* p)
{
	PMODULE_FUNCTION_LIST pList = (PMODULE_FUNCTION_LIST)p;
	UINT uCount = GetListFuncCount(p);
	PMODULE_CALL_TABLE pThis = (PMODULE_CALL_TABLE)malloc(sizeof(MODULE_CALL_TABLE) * (uCount + 1));
	if (pThis == NULL)
	{
		return NULL;
	}
	memset(pThis, 0, sizeof(MODULE_CALL_TABLE) * (uCount + 1));
	PMODULE_FUNCTION_INFO pInfo;
	PMODULE_FUNCTION pModFun;
	DWORD j = 0;
	for (DWORD i = 0;; i++)
	{
		pModFun = &(pList->sModuleList[i]);
		if (pModFun->uType == MODULE_FUNCTION_TYPE_UNKNOW)
		{
			//	函数列表结束，退出
			break;
		}
		if ((pModFun->uType == MODULE_FUNCTION_TYPE_PUBLIC) ||
			(pModFun->uType == MODULE_FUNCTION_TYPE_GBLPLC))
		{
			//	PUBLIC 函数
		}
		else
		{
			//	非 PUBLIC 函数，下一个
			continue;
		}
		pInfo = &(pModFun->info);
		if ((pInfo->szName == NULL) || (pInfo->pFunc == NULL))
		{
			//	确认是GLOBAL 函数，但是两个参数竟然还都为空，当异常退出
			break;
		}
		pThis[j].szName = pInfo->szName;
		pThis[j].pFunc = pInfo->pFunc;
		j++;
	}
	return pThis;
}

void ZooShell_Function_InitEnvironment(void * instance)
{
	_zoo_mode_fun_list_lib = (PMODULE_CALL_TABLE)MakeModuleCallTable(&_zoo_mode_func_list);
	if (_zoo_mode_fun_list_lib)
	{
		g_puf.ZooShell_Type_RegisterLib(instance, SPECIFY_MODE_MODENAME_STRING, _zoo_mode_fun_list_lib, 1 + GetListFuncCount(&_zoo_mode_func_list));
	}
}

void* ZooShell_Function_GetModuleHelp()
{
	return NULL;
}

void* ZooShell_Function_Global(void * instance)
{
	return &_zoo_mode_func_list;
}

void ZooShell_Function_DestroyEnvironment(void * instance)
{
	//	清理整个列表
	free(_zoo_mode_fun_list_lib);
}



#if 0

static PLUGIN_FUNC_LIST _zoo_mode_fun_list_lib[] =
{
	{ "MessageBox", MAKE_FUNC_PROXY_FUNCTION(MessageBoxA) },
	{ NULL, NULL }
};

static MODULE_HELP_INFO _zoo_mode_fun_help_lib =
{
	{ SPECIFY_MODE_MODENAME_STRING, NULL, "TemplateSDK 框架" },
	{
		{ "MessageBox", "int MessageBox(HWND, char*, char*, DWORD)", "弹出一个消息窗" },
	}
};

void ZooShell_Function_InitEnvironment(void * instance)
{
	void * L = instance;
	g_puf.ZooShell_Type_RegisterLib(L, SPECIFY_MODE_MODENAME_STRING, _zoo_mode_fun_list_lib,
		sizeof(_zoo_mode_fun_list_lib) / sizeof(_zoo_mode_fun_list_lib[0]));
}

void* ZooShell_Function_GetModuleHelp()
{
	return (void*)&_zoo_mode_fun_help_lib;
}

void* ZooShell_Function_Global(void * instance)
{
	return NULL;
}

void ZooShell_Function_DestroyEnvironment(void * instance)
{
}

#endif