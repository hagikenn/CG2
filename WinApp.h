#pragma once
#include <Windows.h>
#include <cstdint>


class WinApp
{
public://静的メンバ関数
	static LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

public:

	void Initialize();

	void Update();

	//クライアント領域のサイズ　横　縦
	static const int32_t kClientWidth = 1280;
	static const int32_t kClientHeight = 720;

	//getter
	HWND GetHwnd() const { return hwnd; }
	HINSTANCE GetHInstance() const { return wc.hInstance; }

	//終了
	void Finalize();

private:
	//ウィンドウハンドル
	HWND hwnd = nullptr;

	//ウィンドウクラスの設定
	WNDCLASS wc{};

};

