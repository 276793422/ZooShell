// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             //  �� Windows ͷ�ļ����ų�����ʹ�õ���Ϣ
// Windows ͷ�ļ�: 
#include <windows.h>



// TODO:  �ڴ˴����ó�����Ҫ������ͷ�ļ�

typedef long long			lua_Integer;
typedef unsigned long long	lua_Unsigned;
typedef lua_Unsigned		lua_Unsigned;

typedef void				lua_State;
#include "common.h"

extern PLUGIN_USE_FUNC g_puf;

#define ZooShell_GetParamCount					(int)g_puf.ZooShell_Type_GetParamCount

#define ZooShell_GetParamTypeUnknow(_L, _I)		(ZOO_PVOID)g_puf.ZooShell_Type_GetParamValue(_L, _I, ZOOSHELL_PARAM_TYPE_UNKNOW)
#define	ZooShell_GetParamTypeString(_L, _I)		(ZOO_STRING)g_puf.ZooShell_Type_GetParamValue(_L, _I, ZOOSHELL_PARAM_TYPE_STRING)
#define	ZooShell_GetParamTypeInteger(_L, _I)	(ZOO_UINT)g_puf.ZooShell_Type_GetParamValue(_L, _I, ZOOSHELL_PARAM_TYPE_INTEGER)
#define	ZooShell_GetParamTypeUInteger(_L, _I)	(ZOO_UINT)g_puf.ZooShell_Type_GetParamValue(_L, _I, ZOOSHELL_PARAM_TYPE_UINTEGER)
#define	ZooShell_GetParamTypeBuffer(_L, _I)		(ZOO_PVOID)g_puf.ZooShell_Type_GetParamValue(_L, _I, ZOOSHELL_PARAM_TYPE_BUFFER)

#define ZooShell_PushReturnValueInteger(_L, _V)		g_puf.ZooShell_Type_SetParamReturnValue(_L, (void *)_V, ZOOSHELL_PARAM_TYPE_INTEGER);
#define ZooShell_PushReturnValueString(_L, _V)		g_puf.ZooShell_Type_SetParamReturnValue(_L, (void *)_V, ZOOSHELL_PARAM_TYPE_STRING);
#define ZooShell_PushReturnValueUInteger(_L, _V)	g_puf.ZooShell_Type_SetParamReturnValue(_L, (void *)_V, ZOOSHELL_PARAM_TYPE_UINTEGER);
#define ZooShell_PushReturnValueBuffer(_L, _V)		g_puf.ZooShell_Type_SetParamReturnValue(_L, (void *)_V, ZOOSHELL_PARAM_TYPE_BUFFER);




