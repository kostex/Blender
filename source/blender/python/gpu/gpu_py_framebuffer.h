/*
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

/** \file
 * \ingroup bpygpu
 */

#pragma once

#include "BLI_compiler_attrs.h"

extern PyTypeObject BPyGPUFrameBuffer_Type;

#define BPyGPUFrameBuffer_Check(v) (Py_TYPE(v) == &BPyGPUFrameBuffer_Type)

typedef struct BPyGPUFrameBuffer {
  PyObject_HEAD struct GPUFrameBuffer *fb;

#ifndef GPU_NO_USE_PY_REFERENCES
  bool shared_reference;
#endif
} BPyGPUFrameBuffer;

PyObject *BPyGPUFrameBuffer_CreatePyObject(struct GPUFrameBuffer *fb, bool shared_reference)
    ATTR_NONNULL(1);
