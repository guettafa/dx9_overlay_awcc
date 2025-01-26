#include "render.h"

bool Render::CreateDevice()
{
	// Creating Direct3D Object
	mD3d9 = Direct3DCreate9(D3D_SDK_VERSION);

	if (mD3d9 == nullptr)
	{
		ERROR_MSG("Can't init d3d9");
		return false;
	}

	ZeroMemory(&mParametersD3d9, sizeof(mParametersD3d9));

	mParametersD3d9.BackBufferWidth		   = mOverlay.mDisplayDimension[0];
	mParametersD3d9.BackBufferHeight	   = mOverlay.mDisplayDimension[1];
	mParametersD3d9.EnableAutoDepthStencil = TRUE;
	mParametersD3d9.BackBufferFormat	   = D3DFMT_A8R8G8B8;
	mParametersD3d9.PresentationInterval   = D3DPRESENT_INTERVAL_ONE; // Vsync
	mParametersD3d9.Windowed			   = TRUE;
	mParametersD3d9.SwapEffect			   = D3DSWAPEFFECT_DISCARD;

	// May be D3DDEVTYPE_REF instead of ..HAL

	HRESULT res = mD3d9->CreateDevice(
		D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		mOverlay.mHandle,
		D3DCREATE_HARDWARE_VERTEXPROCESSING,
		&mParametersD3d9,
		&mDeviceD3d9
	);
		
	if ( res != D3D_OK)
	{
		ERROR_MSG("Can't create d3d device");
		return false;
	}

	return true;
}

bool Render::InitD3D9()
{
	return false;
}

void Render::InitImGui()
{
}
