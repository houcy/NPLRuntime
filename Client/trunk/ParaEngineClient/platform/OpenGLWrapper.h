

#ifndef OPENGL_Wrapper_H

#define OPENGL_Wrapper_H

#include "ParaPlatformConfig.h"



#if defined(PLATFORM_MAC)

#include "platform/PlatformMacro.h"
#include "platform/mac/CCImage.h"
#include "platform/mac/CCLabel.h"
#include "platform/mac/CCGLProgram.h"
#include "platform/mac/CCTexture2D.h"
#include "Platform/mac/CCFontAtlas.h"

#elif defined(PARAENGINE_MOBILE)
#include "cocos2d.h"
USING_NS_CC;
#elif defined(PARA_PLATFORM_WIN32)

#ifdef APIENTRY
#undef APIENTRY
#endif

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif
#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers

#define STRICT
#define NOMINMAX 
#ifndef WINVER
#define WINVER         0x0500
#endif
#ifndef _WIN32_WINDOWS
#define _WIN32_WINDOWS 0x0410 
#endif
#ifndef _WIN32_WINNT
#define _WIN32_WINNT   0x0500 
#endif

#include <winsock2.h>

#include <windows.h>
#include <windowsx.h>
#include <mmsystem.h>

#ifdef WIN32
#pragma warning( push )
// warning C4819: The file contains a character that cannot be represented in the current code page (936). Save the file in Unicode format to prevent data loss
#pragma warning( disable : 4819 ) 
#endif



#ifdef WIN32
#pragma warning( pop ) 
#endif


/** use direct input 8 interface */
#define DIRECTINPUT_VERSION		0x0800
#include <dinput.h>



//#include "glad/glad.h"
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "PEtypes.h"
#include "win32/GLType.h"
#include "win32/GLProgram.h"
#include "math/ParaMathUtility.h"
#include "win32/GLLabel.h"
#include "win32/GLFontAtlas.h"
#include "win32/GLTexture2D.h"
#include "win32/GLImage.h"





#endif

#endif
