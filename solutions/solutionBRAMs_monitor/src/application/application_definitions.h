#ifndef APPLICATION_DEFINITIONS_H
#define APPLICATION_DEFINITIONS_H

/**
 * @file application_definitions.h
 *
 * This header is, by default, included in the header of all user-created
 * SpaceStudio modules and devices. This is often used to provide
 * application-wide definitions (global typedefs and macros, definitions
 * of message types, etc.).
 *
 * You may freely modify this file, and/or remove any
 * #include "application_definitions.h" that is in the Module or Device's
 * header. However, if you have both software and hardware module instances,
 * keep in mind that this header will be included in them, so be careful about
 * adding platform-specific code here, such as including OS/HLS-specific
 * headers or using platform-specific data and functions.
 *
 * To control the visibility of code depending on the mapping of the
 * corresponding instance, use the "#if MAPPING == SW_MAPPING" and
 * "#if MAPPING == HW_MAPPING" directives.
 *
 * It is also possible, and somewhat common, to use HLS-specific definitions
 * here, e.g.:
 *
 * @code
 * #if defined(SPACE_VERSION_INCLUDED) && SPACE_BYPASS_TO_CATAPULT >= SPACE_CATAPULT_VER_2022_1
 * #include "ac_fixed.h"
 * typedef ::ac_fixed<16, 7, false> tensor_elem_t;
 * #elif defined(SPACE_VERSION_INCLUDED) && SPACE_BYPASS_TO_VITIS >= SPACE_VIVADO_VER_2018_3
 * #include "ap_fixed.h"
 * typedef ::ap_ufixed<16, 7, AP_RND, AP_SAT> tensor_elem_t;
 * #else
 * #include "some-third-party/fixed.hpp"
 * typedef ::somethirdparty::fixed<16, 16 - 7> tensor_elem_t;
 * #endif
 * @endcode
 *
 * See the definition of the SPACE_BYPASS_* macros (by writing one outside a
 * comment, then CTRL+clicking on it in the SpaceStudio GUI) for more details
 * and pitfalls.
 */

#define IMAGE_IN_OFFSET_REG		0
#define IMAGE_OUT_OFFSET_REG	1
#define IMAGE_SIZE_REG			2

/* register for serialization */
#define START_REG	0x0
#define DONE_REG	0x4
#define PIXEL_REG 	0x8
#endif
