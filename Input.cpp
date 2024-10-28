#include "Input.h"
#include "Input.h"
#include<cassert>
#include<wrl.h>
using namespace Microsoft::WRL;
#define DIRECTNPUT_VERSION 0x800//DirectInputのバージョン指定
#include<dinput.h>
#pragma comment(lib,"dinput8.lib")
#pragma comment(lib,"dxguid.lib")
#include<windows.h>



void Input::Initialize(HINSTANCE hInstance, HWND hwnd)
{
	//DirectInputの初期化
	HRESULT result;
	IDirectInput8* directInput = nullptr;
	result = DirectInput8Create(hInstance,
		DIRECTINPUT_VERSION, IID_IDirectInput8,
		(void**)&directInput, nullptr);
	assert(SUCCEEDED(result));

	//キーボードデバイスの生成
	IDirectInputDevice8* keyboard = nullptr;
	result = directInput->CreateDevice(GUID_SysKeyboard, &keyboard, NULL);
	assert(SUCCEEDED(result));

	//入力データ形式のセット
	result = keyboard->SetDataFormat(&c_dfDIKeyboard);//標準形式
	assert(SUCCEEDED(result));

	//排他制御レベルのセット
	result = keyboard->SetCooperativeLevel(
		hwnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE | DISCL_NOWINKEY);
	assert(SUCCEEDED(result));
}

void Input::Update()
{
}
