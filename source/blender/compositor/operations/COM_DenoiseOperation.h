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
 *
 * Copyright 2019, Blender Foundation.
 */

#pragma once

#include "COM_SingleThreadedOperation.h"
#include "DNA_node_types.h"

namespace blender::compositor {

class DenoiseOperation : public SingleThreadedOperation {
 private:
  /**
   * \brief Cached reference to the input programs
   */
  SocketReader *m_inputProgramColor;
  SocketReader *m_inputProgramAlbedo;
  SocketReader *m_inputProgramNormal;

  /**
   * \brief settings of the denoise node.
   */
  NodeDenoise *m_settings;

  bool output_rendered_;

 public:
  DenoiseOperation();
  /**
   * Initialize the execution
   */
  void initExecution() override;

  /**
   * Deinitialize the execution
   */
  void deinitExecution() override;

  void setDenoiseSettings(NodeDenoise *settings)
  {
    this->m_settings = settings;
  }
  bool determineDependingAreaOfInterest(rcti *input,
                                        ReadBufferOperation *readOperation,
                                        rcti *output) override;

  void get_area_of_interest(int input_idx, const rcti &output_area, rcti &r_input_area) override;
  void update_memory_buffer(MemoryBuffer *output,
                            const rcti &area,
                            Span<MemoryBuffer *> inputs) override;

 protected:
  void generateDenoise(MemoryBuffer *output,
                       MemoryBuffer *input_color,
                       MemoryBuffer *input_normal,
                       MemoryBuffer *input_albedo,
                       NodeDenoise *settings);

  MemoryBuffer *createMemoryBuffer(rcti *rect) override;
};

}  // namespace blender::compositor
