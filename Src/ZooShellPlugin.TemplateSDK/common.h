#pragma once

#include <Windows.h>

typedef long long			ZOO_INT;
typedef unsigned long long	ZOO_UINT;
typedef unsigned long long	ZOO_DWORD;

typedef char *				ZOO_NSTRING;
typedef const char *		ZOO_STRING;
typedef unsigned char *		ZOO_BUFFER;
typedef unsigned char *		ZOO_PUCHAR;

typedef void *				ZOO_PVOID;
typedef const void *		ZOO_CPVOID;


#define MAKE_FUNC_REAL_NAME(_MODE_, _FUNC_NAME_)		ZooShell_ ## _MODE_ ## _ ## _FUNC_NAME_
#define MAKE_FUNC_PROXY_NAME(_MODE_, _FUNC_NAME_)		_lua_zoo_ ## _MODE_ ## _ ## _FUNC_NAME_
#define MAKE_LIBRARY_NAME(_MODE_)						_zoo_ ## _MODE_ ## _lib
#define MSG_NEXT_LINE			"\n             "


typedef void (*Fp_ZooShell_Type_InitEnvironment)(void * instance);
typedef void* (*Fp_ZooShell_Type_GetModuleHelp)();
typedef void* (*Fp_ZooShell_Type_GetModuleGlobal)(void * instance);
typedef void (*Fp_ZooShell_Type_DestroyEnvironment)(void * instance);

typedef struct _PLUGIN_INTERFACE
{
	Fp_ZooShell_Type_InitEnvironment ZooShell_Type_InitEnvironment;			//	初始化环境相关信息
	Fp_ZooShell_Type_GetModuleHelp ZooShell_Type_GetModuleHelp;				//	初始化帮助相关功能
	Fp_ZooShell_Type_GetModuleGlobal ZooShell_Type_GetModuleGlobal;			//	初始化global函数
	Fp_ZooShell_Type_DestroyEnvironment ZooShell_Type_DestroyEnvironment;	//	销毁环境相关信息
} PLUGIN_INTERFACE, *PPLUGIN_INTERFACE;

#define ZOOSHELL_PARAM_TYPE_UNKNOW		0
#define ZOOSHELL_PARAM_TYPE_INTEGER		1
#define ZOOSHELL_PARAM_TYPE_STRING		2
#define ZOOSHELL_PARAM_TYPE_BUFFER		3
#define ZOOSHELL_PARAM_TYPE_UINTEGER	4

typedef int(*Fp_ZooShell_Type_GetParamCount)(void *L);
typedef void* (*Fp_ZooShell_Type_GetParamValue)(void *L, int index, DWORD dwType);
typedef void (*Fp_ZooShell_Type_SetParamReturnValue)(void *L, void *p, DWORD dwType);
typedef void(*Fp_ZooShell_Type_RegisterLib)(void *L, void *mod, void *lib, DWORD count);
typedef int(*Fp_ZooShell_Type_ExecScriptString)(void *L, char *szLua);
typedef struct _PLUGIN_USE_FUNC
{
	short szVersion[4];
	Fp_ZooShell_Type_GetParamCount ZooShell_Type_GetParamCount;					//	获取参数个数
	Fp_ZooShell_Type_GetParamValue ZooShell_Type_GetParamValue;					//	获取指定参数的值
	Fp_ZooShell_Type_SetParamReturnValue ZooShell_Type_SetParamReturnValue;		//	设置一个返回值
	Fp_ZooShell_Type_RegisterLib ZooShell_Type_RegisterLib;						//	注册一个接口
	Fp_ZooShell_Type_ExecScriptString ZooShell_Type_ExecScriptString;					//	执行一个脚本
}PLUGIN_USE_FUNC, *PPLUGIN_USE_FUNC;


//	函数类型
#define		MODULE_FUNCTION_TYPE_INFORM				(0xFFFFFFFF)		//	信息
#define		MODULE_FUNCTION_TYPE_UNKNOW				0					//	未知类型
#define		MODULE_FUNCTION_TYPE_PUBLIC				1					//	模块内部函数
#define		MODULE_FUNCTION_TYPE_GLOBAL				2					//	全局函数
#define		MODULE_FUNCTION_TYPE_GBLPLC				3					//	模块内部和全局都存在

//	是否是GLOBAL函数
#define		IsGlobalFunc(X)		(((X) == MODULE_FUNCTION_TYPE_GLOBAL) || ((X) == MODULE_FUNCTION_TYPE_GBLPLC))
//	是否是PUBLIC函数
#define		IsPublicFunc(X)		(((X) == MODULE_FUNCTION_TYPE_PUBLIC) || ((X) == MODULE_FUNCTION_TYPE_GBLPLC))
//	是否到结束
#define		IsListEnd(X)		((X) == MODULE_FUNCTION_TYPE_UNKNOW)
//	指针有效
#define		IsFunValid(X)		((X) != NULL)

//	先写500个吧
#define MAX_MODULE_FUNCTION_COUNT	511

//	当前函数的信息
typedef struct _MODULE_FUNCTION_INFO
{
	const char *szName;			//	函数名字
	const void *pFunc;			//	函数地址
	const char *szSrc;			//	函数原型
	const char *szHelp;			//	函数帮助
}MODULE_FUNCTION_INFO, *PMODULE_FUNCTION_INFO;

typedef struct _MODULE_FUNCTION
{
	UINT uType;					//	当前函数类型
	MODULE_FUNCTION_INFO info;	//	当前函数的信息
	UINT uInstall;				//	是否已经安装
	//	如果函数包含Global属性，那么这个标记纪录了当前函数是否被注册
}MODULE_FUNCTION, *PMODULE_FUNCTION;

typedef struct _MODULE_FUNCTION_LIST
{
	MODULE_FUNCTION		sModuleInfo;
	MODULE_FUNCTION		sModuleList[MAX_MODULE_FUNCTION_COUNT];
}MODULE_FUNCTION_LIST, *PMODULE_FUNCTION_LIST;

typedef struct _MODULE_CALL_TABLE
{
	const char *szName;
	const void *pFunc;
}MODULE_CALL_TABLE, *PMODULE_CALL_TABLE;









