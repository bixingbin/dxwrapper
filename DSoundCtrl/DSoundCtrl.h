/**
* Copyright (c) 2003-2007, Arne Bockholdt, github@bockholdt.info
*
* This file is part of Direct Sound Control.
*
* Direct Sound Control is free software: you can redistribute it and/or modify
* it under the terms of the GNU Lesser General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* Direct Sound Control is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public License
* along with Direct Sound Control.  If not, see <http://www.gnu.org/licenses/>.
*
* DSoundCtrl.h : main header file for the DSoundCtrl DLL
*
* Updated 2017 by Elisha Riedlinger
*/

#pragma once

#include "IDirectSoundEx.h"
#include "IDirectSoundBufferEx.h"

#define CDSOUNDCTRLAPP_CLASS_NAME	"CDSoundCtrlApp"

#ifdef _DEBUG
extern void LogMessage(const char* szClassName, void* pInstance, char* szMessage);
#endif //_DEBUG

HMODULE g_hDLL = nullptr;

DWORD g_nNum2DBuffers = 0;
DWORD g_nNum3DBuffers = 0;
bool g_bForceCertification = false;
bool g_bForceSoftwareMixing = false;
bool g_bForceHardwareMixing = false;
bool g_bPreventSpeakerSetup = false;
bool g_bForceExclusiveMode = false;
bool g_bForceHQSoftware3D = false;
bool g_bForceNonStatic = false;
bool g_bForceVoiceManagement = false;
bool g_bForcePrimaryBufferFormat = false;
DWORD g_nPrimaryBufferBits = 16;
DWORD g_nPrimaryBufferSamples = 44100;
DWORD g_nPrimaryBufferChannels = 2;

bool g_bForceSpeakerConfig = false;
DWORD g_nSpeakerConfig = DSSPEAKER_5POINT1;

bool g_bStoppedDriverWorkaround = false;

bool g_bLogSystem = true;
bool g_bLogDirectSound = true;
bool g_bLogDirectSoundBuffer = true;
bool g_bLogDirectSound3DBuffer = true;
bool g_bLogDirectSound3DListener = true;
bool g_bDebugBeep = true;

// CDSoundCtrlApp
// See DSoundCtrl.cpp for the implementation of this class
class CDSoundCtrlApp
{
public:
	CDSoundCtrlApp();
	virtual ~CDSoundCtrlApp();

	// Overrides
public:
	virtual BOOL InitInstance();

#ifdef _DEBUG
	bool EnumCallback(LPGUID  lpGuid, LPCSTR  lpcstrDescription, LPCSTR  lpcstrModule);
#endif // _DEBUG

protected:
	const char* m_cszClassName;
};
