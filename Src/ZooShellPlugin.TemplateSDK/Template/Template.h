#pragma once

//	TODO���޸�ģ�����ֵȵ�һϵ����Ϣ

//	ģ������
#define SPECIFY_MODE_MODENAME					TemplateSDK
//	�ַ���ģ������
#define SPECIFY_MODE_MODENAME_STRING			"TemplateSDK"
//	ģ�����
#define SPECIFY_MODE_MODENAME_HELP				"TemplateSDK ���"

//
#define MAKE_FUNC_REAL_NAME(_MODE_, _FUNC_NAME_) ZooShell_ ## _MODE_ ## _ ## _FUNC_NAME_

//	����ִ�е�C��������
#define MAKE_FUNC_REAL_FUNCTION(_FUNC_NAME_)	MAKE_FUNC_REAL_NAME(Template, _FUNC_NAME_)

//	����������
#define MAKE_FUNC_PROXY_FUNCTION(_FUNC_NAME_)	MAKE_FUNC_PROXY_NAME(Template, _FUNC_NAME_)


int MAKE_FUNC_REAL_FUNCTION(MessageBoxA)(_In_opt_ HWND hWnd, _In_opt_ LPCSTR lpText, _In_opt_ LPCSTR lpCaption, _In_ UINT uType);