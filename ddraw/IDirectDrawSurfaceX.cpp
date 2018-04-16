/**
* Copyright (C) 2018 Elisha Riedlinger
*
* This software is  provided 'as-is', without any express  or implied  warranty. In no event will the
* authors be held liable for any damages arising from the use of this software.
* Permission  is granted  to anyone  to use  this software  for  any  purpose,  including  commercial
* applications, and to alter it and redistribute it freely, subject to the following restrictions:
*
*   1. The origin of this software must not be misrepresented; you must not claim that you  wrote the
*      original  software. If you use this  software  in a product, an  acknowledgment in the product
*      documentation would be appreciated but is not required.
*   2. Altered source versions must  be plainly  marked as such, and  must not be  misrepresented  as
*      being the original software.
*   3. This notice may not be removed or altered from any source distribution.
*/

#include "ddraw.h"

HRESULT m_IDirectDrawSurfaceX::QueryInterface(REFIID riid, LPVOID FAR * ppvObj)
{
	return ProxyQueryInterface(ProxyInterface, riid, ppvObj, WrapperID, WrapperInterface);
}

ULONG m_IDirectDrawSurfaceX::AddRef()
{
	return ProxyInterface->AddRef();
}

ULONG m_IDirectDrawSurfaceX::Release()
{
	return ProxyInterface->Release();
}

HRESULT m_IDirectDrawSurfaceX::AddAttachedSurface(LPDIRECTDRAWSURFACE7 lpDDSurface)
{
	if (lpDDSurface)
	{
		lpDDSurface = static_cast<m_IDirectDrawSurface7 *>(lpDDSurface)->GetProxyInterface();
	}

	return ProxyInterface->AddAttachedSurface(lpDDSurface);
}

HRESULT m_IDirectDrawSurfaceX::AddOverlayDirtyRect(LPRECT lpRect)
{
	return ProxyInterface->AddOverlayDirtyRect(lpRect);
}

HRESULT m_IDirectDrawSurfaceX::Blt(LPRECT lpDestRect, LPDIRECTDRAWSURFACE7 lpDDSrcSurface, LPRECT lpSrcRect, DWORD dwFlags, LPDDBLTFX lpDDBltFx)
{
	if (lpDDSrcSurface)
	{
		lpDDSrcSurface = static_cast<m_IDirectDrawSurface7 *>(lpDDSrcSurface)->GetProxyInterface();
	}

	if (lpDDBltFx && lpDDBltFx->dwSize > 12 * 8)
	{
		if (lpDDBltFx->dwSize > 21 * 8 && lpDDBltFx->lpDDSAlphaDest)
		{
			lpDDBltFx->lpDDSAlphaDest = static_cast<m_IDirectDrawSurface *>(lpDDBltFx->lpDDSAlphaDest)->GetProxyInterface();
		}
		if (lpDDBltFx->dwSize > 24 * 8 && lpDDBltFx->lpDDSAlphaSrc)
		{
			lpDDBltFx->lpDDSAlphaSrc = static_cast<m_IDirectDrawSurface *>(lpDDBltFx->lpDDSAlphaSrc)->GetProxyInterface();
		}
		if (lpDDBltFx->dwSize > 28 * 8 && lpDDBltFx->lpDDSPattern)
		{
			lpDDBltFx->lpDDSPattern = static_cast<m_IDirectDrawSurface *>(lpDDBltFx->lpDDSPattern)->GetProxyInterface();
		}
		if (lpDDBltFx->dwSize > 12 * 8 && lpDDBltFx->lpDDSZBufferDest)
		{
			lpDDBltFx->lpDDSZBufferDest = static_cast<m_IDirectDrawSurface *>(lpDDBltFx->lpDDSZBufferDest)->GetProxyInterface();
		}
		if (lpDDBltFx->dwSize > 15 * 8 && lpDDBltFx->lpDDSZBufferSrc)
		{
			lpDDBltFx->lpDDSZBufferSrc = static_cast<m_IDirectDrawSurface *>(lpDDBltFx->lpDDSZBufferSrc)->GetProxyInterface();
		}
	}

	return ProxyInterface->Blt(lpDestRect, lpDDSrcSurface, lpSrcRect, dwFlags, lpDDBltFx);
}

HRESULT m_IDirectDrawSurfaceX::BltBatch(LPDDBLTBATCH lpDDBltBatch, DWORD dwCount, DWORD dwFlags)
{
	if (lpDDBltBatch)
	{
		if (lpDDBltBatch->lpDDSSrc)
		{
			lpDDBltBatch->lpDDSSrc = static_cast<m_IDirectDrawSurface *>(lpDDBltBatch->lpDDSSrc)->GetProxyInterface();
		}
		if (lpDDBltBatch->lpDDBltFx && lpDDBltBatch->lpDDBltFx->dwSize > 12 * 8)
		{
			if (lpDDBltBatch->lpDDBltFx->dwSize > 21 * 8 && lpDDBltBatch->lpDDBltFx->lpDDSAlphaDest)
			{
				lpDDBltBatch->lpDDBltFx->lpDDSAlphaDest = static_cast<m_IDirectDrawSurface *>(lpDDBltBatch->lpDDBltFx->lpDDSAlphaDest)->GetProxyInterface();
			}
			if (lpDDBltBatch->lpDDBltFx->dwSize > 24 * 8 && lpDDBltBatch->lpDDBltFx->lpDDSAlphaSrc)
			{
				lpDDBltBatch->lpDDBltFx->lpDDSAlphaSrc = static_cast<m_IDirectDrawSurface *>(lpDDBltBatch->lpDDBltFx->lpDDSAlphaSrc)->GetProxyInterface();
			}
			if (lpDDBltBatch->lpDDBltFx->dwSize > 28 * 8 && lpDDBltBatch->lpDDBltFx->lpDDSPattern)
			{
				lpDDBltBatch->lpDDBltFx->lpDDSPattern = static_cast<m_IDirectDrawSurface *>(lpDDBltBatch->lpDDBltFx->lpDDSPattern)->GetProxyInterface();
			}
			if (lpDDBltBatch->lpDDBltFx->dwSize > 12 * 8 && lpDDBltBatch->lpDDBltFx->lpDDSZBufferDest)
			{
				lpDDBltBatch->lpDDBltFx->lpDDSZBufferDest = static_cast<m_IDirectDrawSurface *>(lpDDBltBatch->lpDDBltFx->lpDDSZBufferDest)->GetProxyInterface();
			}
			if (lpDDBltBatch->lpDDBltFx->dwSize > 15 * 8 && lpDDBltBatch->lpDDBltFx->lpDDSZBufferSrc)
			{
				lpDDBltBatch->lpDDBltFx->lpDDSZBufferSrc = static_cast<m_IDirectDrawSurface *>(lpDDBltBatch->lpDDBltFx->lpDDSZBufferSrc)->GetProxyInterface();
			}
		}
	}

	return ProxyInterface->BltBatch(lpDDBltBatch, dwCount, dwFlags);
}

HRESULT m_IDirectDrawSurfaceX::BltFast(DWORD dwX, DWORD dwY, LPDIRECTDRAWSURFACE7 lpDDSrcSurface, LPRECT lpSrcRect, DWORD dwFlags)
{
	if (lpDDSrcSurface)
	{
		lpDDSrcSurface = static_cast<m_IDirectDrawSurface7 *>(lpDDSrcSurface)->GetProxyInterface();
	}
	
	return ProxyInterface->BltFast(dwX, dwY, lpDDSrcSurface, lpSrcRect, dwFlags);
}

HRESULT m_IDirectDrawSurfaceX::DeleteAttachedSurface(DWORD dwFlags, LPDIRECTDRAWSURFACE7 lpDDSAttachedSurface)
{
	if (lpDDSAttachedSurface)
	{
		lpDDSAttachedSurface = static_cast<m_IDirectDrawSurface7 *>(lpDDSAttachedSurface)->GetProxyInterface();
	}

	return ProxyInterface->DeleteAttachedSurface(dwFlags, lpDDSAttachedSurface);
}

template HRESULT m_IDirectDrawSurfaceX::EnumAttachedSurfaces<LPDDENUMSURFACESCALLBACK>(LPVOID, LPDDENUMSURFACESCALLBACK);
template HRESULT m_IDirectDrawSurfaceX::EnumAttachedSurfaces<LPDDENUMSURFACESCALLBACK7>(LPVOID, LPDDENUMSURFACESCALLBACK7);
template <typename T>
HRESULT m_IDirectDrawSurfaceX::EnumAttachedSurfaces(LPVOID lpContext, T lpEnumSurfacesCallback)
{
	ENUMSURFACE CallbackContext;
	CallbackContext.lpContext = lpContext;
	CallbackContext.lpCallback = (LPDDENUMSURFACESCALLBACK7)lpEnumSurfacesCallback;
	CallbackContext.DirectXVersion = DirectXVersion;
	CallbackContext.ProxyDirectXVersion = ProxyDirectXVersion;

	return ProxyInterface->EnumAttachedSurfaces(&CallbackContext, m_IDirectDrawEnumSurface::ConvertCallback);
}

template HRESULT m_IDirectDrawSurfaceX::EnumOverlayZOrders<LPDDENUMSURFACESCALLBACK>(DWORD, LPVOID, LPDDENUMSURFACESCALLBACK);
template HRESULT m_IDirectDrawSurfaceX::EnumOverlayZOrders<LPDDENUMSURFACESCALLBACK7>(DWORD, LPVOID, LPDDENUMSURFACESCALLBACK7);
template <typename T>
HRESULT m_IDirectDrawSurfaceX::EnumOverlayZOrders(DWORD dwFlags, LPVOID lpContext, T lpfnCallback)
{
	ENUMSURFACE CallbackContext;
	CallbackContext.lpContext = lpContext;
	CallbackContext.lpCallback = (LPDDENUMSURFACESCALLBACK7)lpfnCallback;
	CallbackContext.DirectXVersion = DirectXVersion;
	CallbackContext.ProxyDirectXVersion = ProxyDirectXVersion;

	return ProxyInterface->EnumOverlayZOrders(dwFlags, &CallbackContext, m_IDirectDrawEnumSurface::ConvertCallback);
}

HRESULT m_IDirectDrawSurfaceX::Flip(LPDIRECTDRAWSURFACE7 lpDDSurfaceTargetOverride, DWORD dwFlags)
{
	if (lpDDSurfaceTargetOverride)
	{
		lpDDSurfaceTargetOverride = static_cast<m_IDirectDrawSurface7 *>(lpDDSurfaceTargetOverride)->GetProxyInterface();
	}

	return ProxyInterface->Flip(lpDDSurfaceTargetOverride, dwFlags);
}

template HRESULT m_IDirectDrawSurfaceX::GetAttachedSurface<LPDDSCAPS>(LPDDSCAPS, LPDIRECTDRAWSURFACE7 FAR *);
template HRESULT m_IDirectDrawSurfaceX::GetAttachedSurface<LPDDSCAPS2>(LPDDSCAPS2, LPDIRECTDRAWSURFACE7 FAR *);
template <typename T>
HRESULT m_IDirectDrawSurfaceX::GetAttachedSurface(T lpDDSCaps, LPDIRECTDRAWSURFACE7 FAR * lplpDDAttachedSurface)
{
	DDSCAPS2 Caps2;
	if (lpDDSCaps && ProxyDirectXVersion > 3 && DirectXVersion < 4)
	{
		ConvertCaps(Caps2, *lpDDSCaps);
		lpDDSCaps = (T)&Caps2;
	}

	HRESULT hr = ProxyInterface->GetAttachedSurface((LPDDSCAPS2)lpDDSCaps, lplpDDAttachedSurface);

	if (SUCCEEDED(hr) && lplpDDAttachedSurface)
	{
		*lplpDDAttachedSurface = ProxyAddressLookupTable.FindAddress<m_IDirectDrawSurface7>(*lplpDDAttachedSurface, DirectXVersion);
	}

	return hr;
}

HRESULT m_IDirectDrawSurfaceX::GetBltStatus(DWORD dwFlags)
{
	return ProxyInterface->GetBltStatus(dwFlags);
}

template HRESULT m_IDirectDrawSurfaceX::GetCaps<LPDDSCAPS>(LPDDSCAPS);
template HRESULT m_IDirectDrawSurfaceX::GetCaps<LPDDSCAPS2>(LPDDSCAPS2);
template <typename T>
HRESULT m_IDirectDrawSurfaceX::GetCaps(T lpDDSCaps)
{
	T lpDDSCaps_tmp = lpDDSCaps;
	DDSCAPS2 Caps2;
	if (lpDDSCaps && ProxyDirectXVersion > 3 && DirectXVersion < 4)
	{
		ConvertCaps(Caps2, *lpDDSCaps);
		lpDDSCaps = (T)&Caps2;
	}

	HRESULT hr = ProxyInterface->GetCaps((LPDDSCAPS2)lpDDSCaps);

	if (SUCCEEDED(hr) && lpDDSCaps_tmp && ProxyDirectXVersion > 3 && DirectXVersion < 4)
	{
		lpDDSCaps = lpDDSCaps_tmp;
		ConvertCaps(*lpDDSCaps, Caps2);
	}

	return hr;
}

HRESULT m_IDirectDrawSurfaceX::GetClipper(LPDIRECTDRAWCLIPPER FAR * lplpDDClipper)
{
	HRESULT hr = ProxyInterface->GetClipper(lplpDDClipper);

	if (SUCCEEDED(hr) && lplpDDClipper)
	{
		*lplpDDClipper = ProxyAddressLookupTable.FindAddress<m_IDirectDrawClipper>(*lplpDDClipper);
	}

	return hr;
}

HRESULT m_IDirectDrawSurfaceX::GetColorKey(DWORD dwFlags, LPDDCOLORKEY lpDDColorKey)
{
	return ProxyInterface->GetColorKey(dwFlags, lpDDColorKey);
}

HRESULT m_IDirectDrawSurfaceX::GetDC(HDC FAR * lphDC)
{
	return ProxyInterface->GetDC(lphDC);
}

HRESULT m_IDirectDrawSurfaceX::GetFlipStatus(DWORD dwFlags)
{
	return ProxyInterface->GetFlipStatus(dwFlags);
}

HRESULT m_IDirectDrawSurfaceX::GetOverlayPosition(LPLONG lplX, LPLONG lplY)
{
	return ProxyInterface->GetOverlayPosition(lplX, lplY);
}

HRESULT m_IDirectDrawSurfaceX::GetPalette(LPDIRECTDRAWPALETTE FAR * lplpDDPalette)
{
	HRESULT hr = ProxyInterface->GetPalette(lplpDDPalette);

	if (SUCCEEDED(hr) && lplpDDPalette)
	{
		*lplpDDPalette = ProxyAddressLookupTable.FindAddress<m_IDirectDrawPalette>(*lplpDDPalette);
	}

	return hr;
}

HRESULT m_IDirectDrawSurfaceX::GetPixelFormat(LPDDPIXELFORMAT lpDDPixelFormat)
{
	return ProxyInterface->GetPixelFormat(lpDDPixelFormat);
}

template HRESULT m_IDirectDrawSurfaceX::GetSurfaceDesc<LPDDSURFACEDESC>(LPDDSURFACEDESC);
template HRESULT m_IDirectDrawSurfaceX::GetSurfaceDesc<LPDDSURFACEDESC2>(LPDDSURFACEDESC2);
template <typename T>
HRESULT m_IDirectDrawSurfaceX::GetSurfaceDesc(T lpDDSurfaceDesc)
{
	T lpDDSurfaceDesc_tmp = lpDDSurfaceDesc;
	DDSURFACEDESC2 Desc2;
	if (lpDDSurfaceDesc && ProxyDirectXVersion > 3 && DirectXVersion < 4)
	{
		ConvertSurfaceDesc(Desc2, *lpDDSurfaceDesc);
		lpDDSurfaceDesc = (T)&Desc2;
	}

	HRESULT hr = ProxyInterface->GetSurfaceDesc((LPDDSURFACEDESC2)lpDDSurfaceDesc);

	if (SUCCEEDED(hr) && lpDDSurfaceDesc_tmp && ProxyDirectXVersion > 3 && DirectXVersion < 4)
	{
		lpDDSurfaceDesc = lpDDSurfaceDesc_tmp;
		ConvertSurfaceDesc(*lpDDSurfaceDesc, Desc2);
	}

	return hr;
}

template HRESULT m_IDirectDrawSurfaceX::Initialize<LPDDSURFACEDESC>(LPDIRECTDRAW, LPDDSURFACEDESC);
template HRESULT m_IDirectDrawSurfaceX::Initialize<LPDDSURFACEDESC2>(LPDIRECTDRAW, LPDDSURFACEDESC2);
template <typename T>
HRESULT m_IDirectDrawSurfaceX::Initialize(LPDIRECTDRAW lpDD, T lpDDSurfaceDesc)
{
	DDSURFACEDESC2 Desc2;
	if (lpDDSurfaceDesc && ProxyDirectXVersion > 3 && DirectXVersion < 4)
	{
		ConvertSurfaceDesc(Desc2, *lpDDSurfaceDesc);
		lpDDSurfaceDesc = (T)&Desc2;
	}

	if (lpDD)
	{
		lpDD = static_cast<m_IDirectDraw *>(lpDD)->GetProxyInterface();
	}

	return ProxyInterface->Initialize(lpDD, (LPDDSURFACEDESC2)lpDDSurfaceDesc);
}

HRESULT m_IDirectDrawSurfaceX::IsLost()
{
	return ProxyInterface->IsLost();
}

template HRESULT m_IDirectDrawSurfaceX::Lock<LPDDSURFACEDESC>(LPRECT, LPDDSURFACEDESC, DWORD, HANDLE);
template HRESULT m_IDirectDrawSurfaceX::Lock<LPDDSURFACEDESC2>(LPRECT, LPDDSURFACEDESC2, DWORD, HANDLE);
template <typename T>
HRESULT m_IDirectDrawSurfaceX::Lock(LPRECT lpDestRect, T lpDDSurfaceDesc, DWORD dwFlags, HANDLE hEvent)
{
	T lpDDSurfaceDesc_tmp = lpDDSurfaceDesc;
	DDSURFACEDESC2 Desc2;
	if (lpDDSurfaceDesc && ProxyDirectXVersion > 3 && DirectXVersion < 4)
	{
		ConvertSurfaceDesc(Desc2, *lpDDSurfaceDesc);
		lpDDSurfaceDesc = (T)&Desc2;
	}

	HRESULT hr = ProxyInterface->Lock(lpDestRect, (LPDDSURFACEDESC2)lpDDSurfaceDesc, dwFlags, hEvent);

	if (SUCCEEDED(hr) && lpDDSurfaceDesc_tmp && ProxyDirectXVersion > 3 && DirectXVersion < 4)
	{
		lpDDSurfaceDesc = lpDDSurfaceDesc_tmp;
		ConvertSurfaceDesc(*lpDDSurfaceDesc, Desc2);
	}

	return hr;
}

HRESULT m_IDirectDrawSurfaceX::ReleaseDC(HDC hDC)
{
	return ProxyInterface->ReleaseDC(hDC);
}

HRESULT m_IDirectDrawSurfaceX::Restore()
{
	return ProxyInterface->Restore();
}

HRESULT m_IDirectDrawSurfaceX::SetClipper(LPDIRECTDRAWCLIPPER lpDDClipper)
{
	if (lpDDClipper)
	{
		lpDDClipper = static_cast<m_IDirectDrawClipper *>(lpDDClipper)->GetProxyInterface();
	}

	return ProxyInterface->SetClipper(lpDDClipper);
}

HRESULT m_IDirectDrawSurfaceX::SetColorKey(DWORD dwFlags, LPDDCOLORKEY lpDDColorKey)
{
	return ProxyInterface->SetColorKey(dwFlags, lpDDColorKey);
}

HRESULT m_IDirectDrawSurfaceX::SetOverlayPosition(LONG lX, LONG lY)
{
	return ProxyInterface->SetOverlayPosition(lX, lY);
}

HRESULT m_IDirectDrawSurfaceX::SetPalette(LPDIRECTDRAWPALETTE lpDDPalette)
{
	if (lpDDPalette)
	{
		lpDDPalette = static_cast<m_IDirectDrawPalette *>(lpDDPalette)->GetProxyInterface();
	}

	return ProxyInterface->SetPalette(lpDDPalette);
}

HRESULT m_IDirectDrawSurfaceX::Unlock(LPRECT lpRect)
{
	return ProxyInterface->Unlock(lpRect);
}

HRESULT m_IDirectDrawSurfaceX::UpdateOverlay(LPRECT lpSrcRect, LPDIRECTDRAWSURFACE7 lpDDDestSurface, LPRECT lpDestRect, DWORD dwFlags, LPDDOVERLAYFX lpDDOverlayFx)
{
	if (lpDDDestSurface)
	{
		lpDDDestSurface = static_cast<m_IDirectDrawSurface7 *>(lpDDDestSurface)->GetProxyInterface();
	}

	if (lpDDOverlayFx && lpDDOverlayFx->dwSize > 7 * 8)
	{
		if (lpDDOverlayFx->dwSize > 7 * 8 && lpDDOverlayFx->lpDDSAlphaSrc)
		{
			lpDDOverlayFx->lpDDSAlphaSrc = static_cast<m_IDirectDrawSurface *>(lpDDOverlayFx->lpDDSAlphaSrc)->GetProxyInterface();
		}
		if (lpDDOverlayFx->dwSize > 10 * 8 && lpDDOverlayFx->lpDDSAlphaDest)
		{
			lpDDOverlayFx->lpDDSAlphaDest = static_cast<m_IDirectDrawSurface *>(lpDDOverlayFx->lpDDSAlphaDest)->GetProxyInterface();
		}
	}

	return ProxyInterface->UpdateOverlay(lpSrcRect, lpDDDestSurface, lpDestRect, dwFlags, lpDDOverlayFx);
}

HRESULT m_IDirectDrawSurfaceX::UpdateOverlayDisplay(DWORD dwFlags)
{
	return ProxyInterface->UpdateOverlayDisplay(dwFlags);
}

HRESULT m_IDirectDrawSurfaceX::UpdateOverlayZOrder(DWORD dwFlags, LPDIRECTDRAWSURFACE7 lpDDSReference)
{
	if (lpDDSReference)
	{
		lpDDSReference = static_cast<m_IDirectDrawSurface7 *>(lpDDSReference)->GetProxyInterface();
	}

	return ProxyInterface->UpdateOverlayZOrder(dwFlags, lpDDSReference);
}

HRESULT m_IDirectDrawSurfaceX::GetDDInterface(LPVOID FAR * lplpDD)
{
	HRESULT hr = ProxyInterface->GetDDInterface(lplpDD);

	if (SUCCEEDED(hr) && lplpDD)
	{
		*lplpDD = ProxyAddressLookupTable.FindAddress<m_IDirectDraw7>(*lplpDD, DirectXVersion);
	}

	return hr;
}

HRESULT m_IDirectDrawSurfaceX::PageLock(DWORD dwFlags)
{
	return ProxyInterface->PageLock(dwFlags);
}

HRESULT m_IDirectDrawSurfaceX::PageUnlock(DWORD dwFlags)
{
	return ProxyInterface->PageUnlock(dwFlags);
}

template HRESULT m_IDirectDrawSurfaceX::SetSurfaceDesc<LPDDSURFACEDESC>(LPDDSURFACEDESC, DWORD);
template HRESULT m_IDirectDrawSurfaceX::SetSurfaceDesc<LPDDSURFACEDESC2>(LPDDSURFACEDESC2, DWORD);
template <typename T>
HRESULT m_IDirectDrawSurfaceX::SetSurfaceDesc(T lpDDsd2, DWORD dwFlags)
{
	DDSURFACEDESC2 Desc2;
	if (lpDDsd2 && ProxyDirectXVersion > 3 && DirectXVersion < 4)
	{
		ConvertSurfaceDesc(Desc2, *lpDDsd2);
		lpDDsd2 = (T)&Desc2;
	}

	return ProxyInterface->SetSurfaceDesc((LPDDSURFACEDESC2)lpDDsd2, dwFlags);
}

HRESULT m_IDirectDrawSurfaceX::SetPrivateData(REFGUID guidTag, LPVOID lpData, DWORD cbSize, DWORD dwFlags)
{
	return ProxyInterface->SetPrivateData(guidTag, lpData, cbSize, dwFlags);
}

HRESULT m_IDirectDrawSurfaceX::GetPrivateData(REFGUID guidTag, LPVOID lpBuffer, LPDWORD lpcbBufferSize)
{
	return ProxyInterface->GetPrivateData(guidTag, lpBuffer, lpcbBufferSize);
}

HRESULT m_IDirectDrawSurfaceX::FreePrivateData(REFGUID guidTag)
{
	return ProxyInterface->FreePrivateData(guidTag);
}

HRESULT m_IDirectDrawSurfaceX::GetUniquenessValue(LPDWORD lpValue)
{
	return ProxyInterface->GetUniquenessValue(lpValue);
}

HRESULT m_IDirectDrawSurfaceX::ChangeUniquenessValue()
{
	return ProxyInterface->ChangeUniquenessValue();
}

HRESULT m_IDirectDrawSurfaceX::SetPriority(DWORD dwPriority)
{
	return ProxyInterface->SetPriority(dwPriority);
}

HRESULT m_IDirectDrawSurfaceX::GetPriority(LPDWORD lpdwPriority)
{
	return ProxyInterface->GetPriority(lpdwPriority);
}

HRESULT m_IDirectDrawSurfaceX::SetLOD(DWORD dwMaxLOD)
{
	return ProxyInterface->SetLOD(dwMaxLOD);
}

HRESULT m_IDirectDrawSurfaceX::GetLOD(LPDWORD lpdwMaxLOD)
{
	return ProxyInterface->GetLOD(lpdwMaxLOD);
}
