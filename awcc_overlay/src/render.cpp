#include "render.h"

bool Render::CreateDevice()
{
	// Creating Direct3D Object
	mD3d9 = Direct3DCreate9(D3D_SDK_VERSION);

	if (mD3d9 == nullptr)
	{
		LOG("Can't init d3d9");
		return false;
	}

	ZeroMemory(&mParametersD3d9, sizeof(mParametersD3d9));

	mParametersD3d9.Windowed				   = TRUE;
	mParametersD3d9.BackBufferFormat	       = D3DFMT_UNKNOWN;
	mParametersD3d9.BackBufferCount			   = 1;
	mParametersD3d9.EnableAutoDepthStencil     = TRUE;
	mParametersD3d9.AutoDepthStencilFormat     = D3DFMT_D16;
	mParametersD3d9.hDeviceWindow		       = mOverlay.mHandle;
	mParametersD3d9.SwapEffect			       = D3DSWAPEFFECT_DISCARD;
	mParametersD3d9.PresentationInterval       = D3DPRESENT_INTERVAL_ONE;

	// May be D3DDEVTYPE_REF instead of ..HAL

	HRESULT res = mD3d9->CreateDevice(
		D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		mOverlay.mHandle,
		D3DCREATE_HARDWARE_VERTEXPROCESSING,
		&mParametersD3d9,
		&mDeviceD3d9
	);
		
	if (res != S_OK)
	{
		LOG("Can't create d3d device");
		return false;
	}

	return true;
}

void Render::CleanDevice()
{
	if (mDeviceD3d9) { mDeviceD3d9->Release(); mDeviceD3d9 = nullptr; }
	if (mD3d9)		 { mD3d9->Release();	   mD3d9       = nullptr; }
}

bool Render::InitImGui()
{
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	
	ImGui::StyleColorsDark();

	if (!ImGui_ImplWin32_Init(mOverlay.mHandle))
	{
		LOG("Can't init ImGui Win32")
		return false;
	}
	if (!ImGui_ImplDX9_Init(mDeviceD3d9))
	{
		LOG("Can't init ImGui Dx9")
		return false;
	}
}

bool Render::InitRendering()
{
	// Init d3d9
	if (!CreateDevice())
	{
		LOG("Can't init d3d9");
		CleanDevice();
		return false;
	}

	// Init ImGui
	InitImGui();
}

void Render::Loop(const std::function<void()>& func)
{
	bool over = false;
	MSG msg{};

	// ImGui Default bg Color
	ImVec4 clear_color = ImVec4(0.0f, 0.0f, 0.0f, 0.0f);

	while (!over)
	{
		// Polls Events
		while (PeekMessage(&msg, mOverlay.mHandle, 0U, 0U, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);

			if (msg.message == WM_QUIT) 
				over = true;
		}

		ImGui_ImplDX9_NewFrame();
		
		// So the ImGui Window can be interactable
		POINT p;
		GetCursorPos(&p);
		ScreenToClient(mOverlay.mHandle, &p);

		ImGuiIO& io = ImGui::GetIO();
		io.MousePos = ImVec2(p.x, p.y);
		io.MouseDown[0] = (GetKeyState(VK_LBUTTON) & 0x8000) != 0;
		io.MouseDown[1] = (GetKeyState(VK_RBUTTON) & 0x8000) != 0;

		ImGui_ImplWin32_NewFrame();
		ImGui::NewFrame();

		func();

		ImGui::EndFrame();

		mDeviceD3d9->SetRenderState(D3DRS_ZENABLE,		     FALSE);
		mDeviceD3d9->SetRenderState(D3DRS_ALPHABLENDENABLE,  FALSE);
		mDeviceD3d9->SetRenderState(D3DRS_SCISSORTESTENABLE, FALSE);

		
		D3DCOLOR clear_col_dx = D3DCOLOR_RGBA((int)(clear_color.x * clear_color.w * 255.0f), (int)(clear_color.y * clear_color.w * 255.0f), (int)(clear_color.z * clear_color.w * 255.0f), (int)(clear_color.w * 255.0f));
		mDeviceD3d9->Clear(0, nullptr, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, clear_col_dx, 1.0f, 0);
		if (mDeviceD3d9->BeginScene() >= 0)
		{
			ImGui::Render();
			ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
			mDeviceD3d9->EndScene();
		}
		HRESULT res = mDeviceD3d9->Present(nullptr, nullptr, nullptr, nullptr);
	}

	ImGui_ImplDX9_Shutdown();
	ImGui_ImplWin32_Shutdown();
	ImGui::DestroyContext();

	CleanDevice();

	DestroyWindow(mOverlay.mHandle);
}