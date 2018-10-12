#include "GLWrapper.h"
#include "OpenGL.h"
#include <cassert>
using namespace ParaEngine;

#define  MAX_TEXTURE_SLOT 16

static int s_texture_cache[MAX_TEXTURE_SLOT] = { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1 };
static int s_current_program = -1;

void LibGL::BindTexture2D(int slot, int texture)
{
	if (slot<0 || slot>MAX_TEXTURE_SLOT) return;
	if (s_texture_cache[slot] == texture) {
		return;
	}
	glActiveTexture(GL_TEXTURE0+ slot);
	glBindTexture(GL_TEXTURE_2D,texture);
	s_texture_cache[slot] = texture;
}

void LibGL::ClearCache()
{
	memset(s_texture_cache, 0, sizeof(s_texture_cache));
	s_current_program = -1;
}

void ParaEngine::LibGL::UseProgram(int program)
{
	if (s_current_program == program) return;
	glUseProgram(program);
	s_current_program = program;
}