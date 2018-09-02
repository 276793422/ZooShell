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
	Fp_ZooShell_Type_InitEnvironment ZooShell_Type_InitEnvironment;			//	��ʼ�����������Ϣ
	Fp_ZooShell_Type_GetModuleHelp ZooShell_Type_GetModuleHelp;				//	��ʼ��������ع���
	Fp_ZooShell_Type_GetModuleGlobal ZooShell_Type_GetModuleGlobal;			//	��ʼ��global����
	Fp_ZooShell_Type_DestroyEnvironment ZooShell_Type_DestroyEnvironment;	//	���ٻ��������Ϣ
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
	Fp_ZooShell_Type_GetParamCount ZooShell_Type_GetParamCount;					//	��ȡ��������
	Fp_ZooShell_Type_GetParamValue ZooShell_Type_GetParamValue;					//	��ȡָ��������ֵ
	Fp_ZooShell_Type_SetParamReturnValue ZooShell_Type_SetParamReturnValue;		//	����һ������ֵ
	Fp_ZooShell_Type_RegisterLib ZooShell_Type_RegisterLib;						//	ע��һ���ӿ�
	Fp_ZooShell_Type_ExecScriptString ZooShell_Type_ExecScriptString;					//	ִ��һ���ű�
}PLUGIN_USE_FUNC, *PPLUGIN_USE_FUNC;


//	��������
#define		MODULE_FUNCTION_TYPE_INFORM				(0xFFFFFFFF)		//	��Ϣ
#define		MODULE_FUNCTION_TYPE_UNKNOW				0					//	δ֪����
#define		MODULE_FUNCTION_TYPE_PUBLIC				1					//	ģ���ڲ�����
#define		MODULE_FUNCTION_TYPE_GLOBAL				2					//	ȫ�ֺ���
#define		MODULE_FUNCTION_TYPE_GBLPLC				3					//	ģ���ڲ���ȫ�ֶ�����

//	�Ƿ���GLOBAL����
#define		IsGlobalFunc(X)		(((X) == MODULE_FUNCTION_TYPE_GLOBAL) || ((X) == MODULE_FUNCTION_TYPE_GBLPLC))
//	�Ƿ���PUBLIC����
#define		IsPublicFunc(X)		(((X) == MODULE_FUNCTION_TYPE_PUBLIC) || ((X) == MODULE_FUNCTION_TYPE_GBLPLC))
//	�Ƿ񵽽���
#define		IsListEnd(X)		((X) == MODULE_FUNCTION_TYPE_UNKNOW)
//	ָ����Ч
#define		IsFunValid(X)		((X) != NULL)

//	��д500����
#define MAX_MODULE_FUNCTION_COUNT	511

//	��ǰ��������Ϣ
typedef struct _MODULE_FUNCTION_INFO
{
	const char *szName;			//	��������
	const void *pFunc;			//	������ַ
	const char *szSrc;			//	����ԭ��
	const char *szHelp;			//	��������
}MODULE_FUNCTION_INFO, *PMODULE_FUNCTION_INFO;

typedef struct _MODULE_FUNCTION
{
	UINT uType;					//	��ǰ��������
	MODULE_FUNCTION_INFO info;	//	��ǰ��������Ϣ
	UINT uInstall;				//	�Ƿ��Ѿ���װ
	//	�����������Global���ԣ���ô�����Ǽ�¼�˵�ǰ�����Ƿ�ע��
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









