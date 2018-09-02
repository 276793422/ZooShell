#pragma once

//	TODO:	修改以下两个宏的名字

#define ZooShell_Function_InitEnvironment		ZooShell_Template_InitEnvironment
#define ZooShell_Function_GetModuleHelp			ZooShell_Template_GetModuleHelp
#define ZooShell_Function_Global				ZooShell_Template_Global
#define ZooShell_Function_DestroyEnvironment	ZooShell_Template_DestroyEnvironment




void ZooShell_Function_InitEnvironment(void * instance);

void* ZooShell_Function_GetModuleHelp();

void* ZooShell_Function_Global(void * instance);

void ZooShell_Function_DestroyEnvironment(void * instance);
