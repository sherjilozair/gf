/*
 * Gamedev Framework (gf)
 * Copyright (C) 2016-2018 Julien Bernard
 *
 * This software is provided 'as-is', without any express or implied
 * warranty.  In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 */
#ifndef GF_SERIALIZATION_HEADERS_H
#define GF_SERIALIZATION_HEADERS_H

#include <cstdint>

#include "Portability.h"

namespace gf {
#ifndef DOXYGEN_SHOULD_SKIP_THIS
inline namespace v1 {
#endif
  class Serializer;
  class Deserializer;

  /**
   * @ingroup game
   * @brief A header for array serialization
   */
  struct SerialArrayHeader {
    uint32_t size;  ///< The number of elements in the array
  };

  /**
   * @relates Serializer
   * @brief Serialize an array header with its size
   */
  GF_API Serializer& operator|(Serializer& ar, SerialArrayHeader header);

  /**
   * @relates Deserializer
   * @brief Deserialize an array header
   */
  GF_API Deserializer& operator|(Deserializer& ar, SerialArrayHeader& header);


  /**
   * @ingroup game
   * @brief A header for map serialization
   */
  struct SerialMapHeader {
    uint32_t size;  ///< The number of elements in the map
  };

  /**
   * @relates Serializer
   * @brief Serialize a map header with its size
   */
  GF_API Serializer& operator|(Serializer& ar, SerialMapHeader header);

  /**
   * @relates Deserializer
   * @brief Deserialize a map header
   */
  GF_API Deserializer& operator|(Deserializer& ar, SerialMapHeader& header);

#ifndef DOXYGEN_SHOULD_SKIP_THIS
}
#endif
}

#endif // GF_SERIALIZATION_HEADERS_H
