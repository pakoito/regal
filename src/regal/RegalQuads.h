/*
  Copyright (c) 2011-2013 NVIDIA Corporation
  Copyright (c) 2011-2012 Cass Everitt
  Copyright (c) 2012 Scott Nations
  Copyright (c) 2012 Mathias Schott
  Copyright (c) 2012 Nigel Stewart
  All rights reserved.

  Redistribution and use in source and binary forms, with or without modification,
  are permitted provided that the following conditions are met:

    Redistributions of source code must retain the above copyright notice, this
    list of conditions and the following disclaimer.

    Redistributions in binary form must reproduce the above copyright notice,
    this list of conditions and the following disclaimer in the documentation
    and/or other materials provided with the distribution.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
  ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
  IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
  INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
  LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
  OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
  OF THE POSSIBILITY OF SUCH DAMAGE.
*/

/*

 Regal GL_QUADs emulation layer
 Scott Nations

 */

#ifndef __REGAL_QUADS_H__
#define __REGAL_QUADS_H__

#include "RegalUtil.h"

#if REGAL_EMULATION

REGAL_GLOBAL_BEGIN

#include <GL/Regal.h>

#include "RegalContext.h"

REGAL_GLOBAL_END

REGAL_NAMESPACE_BEGIN

namespace Emu {

struct Quads
{
  void Init(RegalContext &ctx);
  void Cleanup(RegalContext &ctx);
  bool glDrawArrays(RegalContext *ctx, GLenum mode, GLint first, GLsizei count);

  void glBindBuffer(GLenum target, GLuint buffer );
  void glFrontFace(GLenum mode);
  void glPolygonMode(GLenum face, GLenum mode);
  void glShadeModel(GLenum mode);
  void glProvokingVertex(GLenum mode);
  void glCullFace(GLenum face);
  void glEnable(GLenum cap);
  void glDisable(GLenum cap);

  GLenum windingMode;
  GLenum frontFaceMode;
  GLenum backFaceMode;
  GLenum shadeMode;
  GLenum provokeMode;
  GLenum cullFace;
  GLuint elementArrayBuffer;
  GLuint quadIndexBuffer;
  bool   gl_quads_follow_provoking_vertex_convention : 1;
  bool   cullingFaces : 1;
};

}

REGAL_NAMESPACE_END

#endif // REGAL_EMULATION

#endif // ! __REGAL_QUADS_H__
