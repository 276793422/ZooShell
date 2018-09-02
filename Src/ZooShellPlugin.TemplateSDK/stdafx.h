// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             //  从 Windows 头文件中排除极少使用的信息
// Windows 头文件: 
#include <windows.h>



// TODO:  在此处引用程序需要的其他头文件

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




