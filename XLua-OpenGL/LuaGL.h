/******************************************************************************
* Copyright (C) 2003-2004 by Fabio Guerra and Cleyde Marlyse.
* All rights reserved.
*
* Permission is hereby granted, free of charge, to any person obtaining
* a copy of this software and associated documentation files (the
* "Software"), to deal in the Software without restriction, including
* without limitation the rights to use, copy, modify, merge, publish,
* distribute, sublicense, and/or sell copies of the Software, and to
* permit persons to whom the Software is furnished to do so, subject to
* the following conditions:
*
* The above copyright notice and this permission notice shall be
* included in all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
******************************************************************************/

#ifndef __LUAGL_H__
#define __LUAGL_H__

#ifdef __cplusplus
extern "C" {
#endif

/* #include "LuaGLExt.h" */

#ifdef _WIN32
  #ifdef BUILDING_LUAGL_DLL
	 #define LUAGL_API __declspec(dllexport)
  #else
	 #define LUAGL_API __declspec(dllimport)
  #endif
  #include <windows.h>
#else
  #ifdef BUILDING_LUAGL_DLL
	 #define LUAGL_API
  #else
	 #define LUAGL_API extern
  #endif
#endif

#include "lualib.h"
#include <GL/gl.h>
#include <GL/glu.h>

#include "glext.h"

LUAGL_API int luaopen_opengl (lua_State *L);

#ifdef __cplusplus
}
#endif

#define ENUM_ERROR (GLenum)-2

void set_field(lua_State *L, unsigned int index, lua_Number value);
GLenum get_enum(const char *str, int n);
GLenum get_gl_enum(lua_State *L, int index);
const char *get_str_gl_enum(GLenum num);
int get_arrayb(lua_State *L, int index, GLboolean **array);
int get_arrayd(lua_State *L, int index, GLdouble **array);
int get_arrayf(lua_State *L, int index, GLfloat **array);
int get_arrayui(lua_State *L, int index, GLuint **array);
int get_arrayubyte(lua_State *L, int index, GLubyte **array);
int get_array2ubyte(lua_State *L, int index, GLubyte **array, int *size);
int get_array2i(lua_State *L, int index, GLint **array, int *size);
int get_array2ui(lua_State *L, int index, GLuint **array, int *size);
int get_array2d(lua_State *L, int index, GLdouble **array, int *size);
int get_array2f(lua_State *L, int index, GLfloat **array, int *size);
int get_array3f(lua_State *L, int index, GLfloat **array, int *outerSize, int *innerSize);
int str2mask(const char *str);
const char *mask2str(int mask);

typedef struct gl_str_value {
  const char *str;
  GLenum value;
} gl_str_value;

static const gl_str_value glu_str[] = {
	{ "FALSE"										, 0 },
	{ "TRUE"										, 1 },
	{ 0, 0 }
};

static const gl_str_value gl_str[] = {
	{ "VERSION_1_1"									, 1 },
	{ "EXT_vertex_array"							, 1 },
	{ "EXT_bgra"									, 1 },
	{ "EXT_paletted_texture"						, 1 },
	{ "WIN_swap_hint"								, 1 },
	{ "WIN_draw_range_elements"						, 1 },
	
	{ "ZERO"										, 0 },
	{ "FALSE"										, 0 },
	{ "NONE"										, 0 },
	{ "NO_ERROR"									, 0 },
	{ "ONE"											, 1 },
	{ "TRUE"										, 1 },

	{ "POINTS"										, 0x0000 },
	{ "LINES"										, 0x0001 },
	{ "LINE_LOOP"									, 0x0002 },
	{ "LINE_STRIP"									, 0x0003 },
	{ "TRIANGLES"									, 0x0004 },
	{ "TRIANGLE_STRIP"								, 0x0005 },
	{ "TRIANGLE_FAN"								, 0x0006 },
	{ "QUADS"										, 0x0007 },
	{ "QUAD_STRIP"									, 0x0008 },
	{ "POLYGON"										, 0x0009 },

	{ "ACCUM"										, 0x0100 },
	{ "LOAD"										, 0x0101 },
	{ "RETURN"										, 0x0102 },
	{ "MULT"										, 0x0103 },
	{ "ADD"											, 0x0104 },

	{ "NEVER"										, 0x0200 },
	{ "LESS"										, 0x0201 },
	{ "EQUAL"										, 0x0202 },
	{ "LEQUAL"										, 0x0203 },
	{ "GREATER"										, 0x0204 },
	{ "NOTEQUAL"									, 0x0205 },
	{ "GEQUAL"										, 0x0206 },
	{ "ALWAYS"										, 0x0207 },

	{ "SRC_COLOR"									, 0x0300 },
	{ "ONE_MINUS_SRC_COLOR"							, 0x0301 },
	{ "SRC_ALPHA"									, 0x0302 },
	{ "ONE_MINUS_SRC_ALPHA"							, 0x0303 },
	{ "DST_ALPHA"									, 0x0304 },
	{ "ONE_MINUS_DST_ALPHA"							, 0x0305 },
	{ "DST_COLOR"									, 0x0306 },
	{ "ONE_MINUS_DST_COLOR"							, 0x0307 },
	{ "SRC_ALPHA_SATURATE"							, 0x0308 },

	{ "BYTE"										, 0x1400 },
	{ "UNSIGNED_BYTE"								, 0x1401 },
	{ "SHORT"										, 0x1402 },
	{ "UNSIGNED_SHORT"								, 0x1403 },
	{ "INT"											, 0x1404 },
	{ "UNSIGNED_INT"								, 0x1405 },
	{ "FLOAT"										, 0x1406 },
	{ "_2_BYTES"									, 0x1407 },
	{ "_3_BYTES"									, 0x1408 },
	{ "_4_BYTES"									, 0x1409 },
	{ "DOUBLE"										, 0x140A },

	{ "FRONT_LEFT"									, 0x0400 },
	{ "FRONT_RIGHT"									, 0x0401 },
	{ "BACK_LEFT"									, 0x0402 },
	{ "BACK_RIGHT"									, 0x0403 },
	{ "FRONT"										, 0x0404 },
	{ "BACK"										, 0x0405 },
	{ "LEFT"										, 0x0406 },
	{ "RIGHT"										, 0x0407 },
	{ "FRONT_AND_BACK"								, 0x0408 },
	{ "AUX0"										, 0x0409 },
	{ "AUX1"										, 0x040A },
	{ "AUX2"										, 0x040B },
	{ "AUX3"										, 0x040C },

	{ "INVALID_ENUM"								, 0x0500 },
	{ "INVALID_VALUE"								, 0x0501 },
	{ "INVALID_OPERATION"							, 0x0502 },
	{ "STACK_OVERFLOW"								, 0x0503 },
	{ "STACK_UNDERFLOW"								, 0x0504 },
	{ "OUT_OF_MEMORY"								, 0x0505 },

	{ "_2D"											, 0x0600 },
	{ "_3D"											, 0x0601 },
	{ "_3D_COLOR"									, 0x0602 },
	{ "_3D_COLOR_TEXTURE"							, 0x0603 },
	{ "_4D_COLOR_TEXTURE"							, 0x0604 },

	{ "PASS_THROUGH_TOKEN"							, 0x0700 },
	{ "POINT_TOKEN"									, 0x0701 },
	{ "LINE_TOKEN"									, 0x0702 },
	{ "POLYGON_TOKEN"								, 0x0703 },
	{ "BITMAP_TOKEN"								, 0x0704 },
	{ "DRAW_PIXEL_TOKEN"							, 0x0705 },
	{ "COPY_PIXEL_TOKEN"							, 0x0706 },
	{ "LINE_RESET_TOKEN"							, 0x0707 },

	{ "EXP"											, 0x0800 }, 
	{ "EXP2"										, 0x0801 },

	{ "CW"											, 0x0900 },
	{ "CCW"											, 0x0901 },

	{ "COEFF"										, 0x0A00 },
	{ "ORDER"										, 0x0A01 },
	{ "DOMAIN"										, 0x0A02 },

	{ "CURRENT_COLOR"								, 0x0B00 },
	{ "CURRENT_INDEX"								, 0x0B01 },
	{ "CURRENT_NORMAL"								, 0x0B02 },
	{ "CURRENT_TEXTURE_COORDS"						, 0x0B03 },
	{ "CURRENT_RASTER_COLOR"						, 0x0B04 },
	{ "CURRENT_RASTER_INDEX"						, 0x0B05 },
	{ "CURRENT_RASTER_TEXTURE_COORDS"				, 0x0B06 },
	{ "CURRENT_RASTER_POSITION"						, 0x0B07 },
	{ "CURRENT_RASTER_POSITION_VALID"				, 0x0B08 },
	{ "CURRENT_RASTER_DISTANCE"						, 0x0B09 },

	{ "POINT_SMOOTH"								, 0x0B10 },
	{ "POINT_SIZE"									, 0x0B11 },
	{ "POINT_SIZE_RANGE"							, 0x0B12 },
	{ "POINT_SIZE_GRANULARITY"						, 0x0B13 },

	{ "LINE_SMOOTH"									, 0x0B20 },
	{ "LINE_WIDTH"									, 0x0B21 },
	{ "LINE_WIDTH_RANGE"							, 0x0B22 },
	{ "LINE_WIDTH_GRANULARITY"						, 0x0B23 },
	{ "LINE_STIPPLE"								, 0x0B24 },
	{ "LINE_STIPPLE_PATTERN"						, 0x0B25 },
	{ "LINE_STIPPLE_REPEAT"							, 0x0B26 },

	{ "LIST_MODE"									, 0x0B30 },
	{ "MAX_LIST_NESTING"							, 0x0B31 },
	{ "LIST_BASE"									, 0x0B32 },
	{ "LIST_INDEX"									, 0x0B33 },

	{ "POLYGON_MODE"								, 0x0B40 },
	{ "POLYGON_SMOOTH"								, 0x0B41 },
	{ "POLYGON_STIPPLE"								, 0x0B42 },
	{ "EDGE_FLAG"									, 0x0B43 },
	{ "CULL_FACE"									, 0x0B44 },
	{ "CULL_FACE_MODE"								, 0x0B45 },
	{ "FRONT_FACE"									, 0x0B46 },

	{ "LIGHTING"									, 0x0B50 },
	{ "LIGHT_MODEL_LOCAL_VIEWER"					, 0x0B51 },
	{ "LIGHT_MODEL_TWO_SIDE"						, 0x0B52 },
	{ "LIGHT_MODEL_AMBIENT"							, 0x0B53 },
	{ "SHADE_MODEL"									, 0x0B54 },
	{ "COLOR_MATERIAL_FACE"							, 0x0B55 },
	{ "COLOR_MATERIAL_PARAMETER"					, 0x0B56 },
	{ "COLOR_MATERIAL"								, 0x0B57 },

	{ "FOG"											, 0x0B60 },
	{ "FOG_INDEX"									, 0x0B61 },
	{ "FOG_DENSITY"									, 0x0B62 },
	{ "FOG_START"									, 0x0B63 },
	{ "FOG_END"										, 0x0B64 },
	{ "FOG_MODE"									, 0x0B65 },
	{ "FOG_COLOR"									, 0x0B66 },

	{ "DEPTH_RANGE"									, 0x0B70 },
	{ "DEPTH_TEST"									, 0x0B71 },
	{ "DEPTH_WRITEMASK"								, 0x0B72 },
	{ "DEPTH_CLEAR_VALUE"							, 0x0B73 },
	{ "DEPTH_FUNC"									, 0x0B74 },

	{ "ACCUM_CLEAR_VALUE"							, 0x0B80 },

	{ "STENCIL_TEST"								, 0x0B90 },
	{ "STENCIL_CLEAR_VALUE"							, 0x0B91 },
	{ "STENCIL_FUNC"								, 0x0B92 },
	{ "STENCIL_VALUE_MASK"							, 0x0B93 },
	{ "STENCIL_FAIL"								, 0x0B94 },
	{ "STENCIL_PASS_DEPTH_FAIL"						, 0x0B95 },
	{ "STENCIL_PASS_DEPTH_PASS"						, 0x0B96 },
	{ "STENCIL_REF"									, 0x0B97 },
	{ "STENCIL_WRITEMASK"							, 0x0B98 },

	{ "MATRIX_MODE"									, 0x0BA0 },
	{ "NORMALIZE"									, 0x0BA1 },
	{ "VIEWPORT"									, 0x0BA2 },
	{ "MODELVIEW_STACK_DEPTH"						, 0x0BA3 },
	{ "PROJECTION_STACK_DEPTH"						, 0x0BA4 },
	{ "TEXTURE_STACK_DEPTH"							, 0x0BA5 },
	{ "MODELVIEW_MATRIX"							, 0x0BA6 },
	{ "PROJECTION_MATRIX"							, 0x0BA7 },
	{ "TEXTURE_MATRIX"								, 0x0BA8 },

	{ "ATTRIB_STACK_DEPTH"							, 0x0BB0 },
	{ "CLIENT_ATTRIB_STACK_DEPTH"					, 0x0BB1 },

	{ "ALPHA_TEST"									, 0x0BC0 },
	{ "ALPHA_TEST_FUNC"								, 0x0BC1 },
	{ "ALPHA_TEST_REF"								, 0x0BC2 },

	{ "DITHER"										, 0x0BD0 },
	{ "BLEND_DST"									, 0x0BE0 },
	{ "BLEND_SRC"									, 0x0BE1 },
	{ "BLEND"										, 0x0BE2 },

	{ "LOGIC_OP_MODE"								, 0x0BF0 },
	{ "LOGIC_OP"									, 0x0BF1 },
	{ "INDEX_LOGIC_OP"								, 0x0BF1 },
	{ "COLOR_LOGIC_OP"								, 0x0BF2 },

	{ "AUX_BUFFERS"									, 0x0C00 },
	{ "DRAW_BUFFER"									, 0x0C01 },
	{ "READ_BUFFER"									, 0x0C02 },

	{ "SCISSOR_BOX"									, 0x0C10 },
	{ "SCISSOR_TEST"								, 0x0C11 },

	{ "INDEX_CLEAR_VALUE"							, 0x0C20 },
	{ "INDEX_WRITEMASK"								, 0x0C21 },
	{ "COLOR_CLEAR_VALUE"							, 0x0C22 },
	{ "COLOR_WRITEMASK"								, 0x0C23 },

	{ "INDEX_MODE"									, 0x0C30 },
	{ "RGBA_MODE"									, 0x0C31 },
	{ "DOUBLEBUFFER"								, 0x0C32 },
	{ "STEREO"										, 0x0C33 },

	{ "RENDER_MODE"									, 0x0C40 },

	{ "PERSPECTIVE_CORRECTION_HINT"					, 0x0C50 },
	{ "POINT_SMOOTH_HINT"							, 0x0C51 },
	{ "LINE_SMOOTH_HINT"							, 0x0C52 },
	{ "POLYGON_SMOOTH_HINT"							, 0x0C53 },
	{ "FOG_HINT"									, 0x0C54 },

	{ "TEXTURE_GEN_S"								, 0x0C60 },
	{ "TEXTURE_GEN_T"								, 0x0C61 },
	{ "TEXTURE_GEN_R"								, 0x0C62 },
	{ "TEXTURE_GEN_Q"								, 0x0C63 },

	{ "PIXEL_MAP_I_TO_I"							, 0x0C70 },
	{ "PIXEL_MAP_S_TO_S"							, 0x0C71 },
	{ "PIXEL_MAP_I_TO_R"							, 0x0C72 },
	{ "PIXEL_MAP_I_TO_G"							, 0x0C73 },
	{ "PIXEL_MAP_I_TO_B"							, 0x0C74 },
	{ "PIXEL_MAP_I_TO_A"							, 0x0C75 },
	{ "PIXEL_MAP_R_TO_R"							, 0x0C76 },
	{ "PIXEL_MAP_G_TO_G"							, 0x0C77 },
	{ "PIXEL_MAP_B_TO_B"							, 0x0C78 },
	{ "PIXEL_MAP_A_TO_A"							, 0x0C79 },

	{ "PIXEL_MAP_I_TO_I_SIZE"						, 0x0CB0 },
	{ "PIXEL_MAP_S_TO_S_SIZE"						, 0x0CB1 },
	{ "PIXEL_MAP_I_TO_R_SIZE"						, 0x0CB2 },
	{ "PIXEL_MAP_I_TO_G_SIZE"						, 0x0CB3 },
	{ "PIXEL_MAP_I_TO_B_SIZE"						, 0x0CB4 },
	{ "PIXEL_MAP_I_TO_A_SIZE"						, 0x0CB5 },
	{ "PIXEL_MAP_R_TO_R_SIZE"						, 0x0CB6 },
	{ "PIXEL_MAP_G_TO_G_SIZE"						, 0x0CB7 },
	{ "PIXEL_MAP_B_TO_B_SIZE"						, 0x0CB8 },
	{ "PIXEL_MAP_A_TO_A_SIZE"						, 0x0CB9 },

	{ "UNPACK_SWAP_BYTES"							, 0x0CF0 },
	{ "UNPACK_LSB_FIRST"							, 0x0CF1 },
	{ "UNPACK_ROW_LENGTH"							, 0x0CF2 },
	{ "UNPACK_SKIP_ROWS"							, 0x0CF3 },
	{ "UNPACK_SKIP_PIXELS"							, 0x0CF4 },
	{ "UNPACK_ALIGNMENT"							, 0x0CF5 },

	{ "PACK_SWAP_BYTES"								, 0x0D00 },
	{ "PACK_LSB_FIRST"								, 0x0D01 },
	{ "PACK_ROW_LENGTH"								, 0x0D02 },
	{ "PACK_SKIP_ROWS"								, 0x0D03 },
	{ "PACK_SKIP_PIXELS"							, 0x0D04 },
	{ "PACK_ALIGNMENT"								, 0x0D05 },

	{ "MAP_COLOR"									, 0x0D10 },
	{ "MAP_STENCIL"									, 0x0D11 },
	{ "INDEX_SHIFT"									, 0x0D12 },
	{ "INDEX_OFFSET"								, 0x0D13 },
	{ "RED_SCALE"									, 0x0D14 },
	{ "RED_BIAS"									, 0x0D15 },
	{ "ZOOM_X"										, 0x0D16 },
	{ "ZOOM_Y"										, 0x0D17 },
	{ "GREEN_SCALE"									, 0x0D18 },
	{ "GREEN_BIAS"									, 0x0D19 },
	{ "BLUE_SCALE"									, 0x0D1A },
	{ "BLUE_BIAS"									, 0x0D1B },
	{ "ALPHA_SCALE"									, 0x0D1C },
	{ "ALPHA_BIAS"									, 0x0D1D },
	{ "DEPTH_SCALE"									, 0x0D1E },
	{ "DEPTH_BIAS"									, 0x0D1F },

	{ "MAX_EVAL_ORDER"								, 0x0D30 },
	{ "MAX_LIGHTS"									, 0x0D31 },
	{ "MAX_CLIP_PLANES"								, 0x0D32 },
	{ "MAX_TEXTURE_SIZE"							, 0x0D33 },
	{ "MAX_PIXEL_MAP_TABLE"							, 0x0D34 },
	{ "MAX_ATTRIB_STACK_DEPTH"						, 0x0D35 },
	{ "MAX_MODELVIEW_STACK_DEPTH"					, 0x0D36 },
	{ "MAX_NAME_STACK_DEPTH"						, 0x0D37 },
	{ "MAX_PROJECTION_STACK_DEPTH"					, 0x0D38 },
	{ "MAX_TEXTURE_STACK_DEPTH"						, 0x0D39 },
	{ "MAX_VIEWPORT_DIMS"							, 0x0D3A },
	{ "MAX_CLIENT_ATTRIB_STACK_DEPTH"				, 0x0D3B },

	{ "SUBPIXEL_BITS"								, 0x0D50 },
	{ "INDEX_BITS"									, 0x0D51 },
	{ "RED_BITS"									, 0x0D52 },
	{ "GREEN_BITS"									, 0x0D53 },
	{ "BLUE_BITS"									, 0x0D54 },
	{ "ALPHA_BITS"									, 0x0D55 },
	{ "DEPTH_BITS"									, 0x0D56 },
	{ "STENCIL_BITS"								, 0x0D57 },
	{ "ACCUM_RED_BITS"								, 0x0D58 },
	{ "ACCUM_GREEN_BITS"							, 0x0D59 },
	{ "ACCUM_BLUE_BITS"								, 0x0D5A },
	{ "ACCUM_ALPHA_BITS"							, 0x0D5B },

	{ "NAME_STACK_DEPTH"							, 0x0D70 },

	{ "AUTO_NORMAL"									, 0x0D80 },

	{ "MAP1_COLOR_4"								, 0x0D90 },
	{ "MAP1_INDEX"									, 0x0D91 },
	{ "MAP1_NORMAL"									, 0x0D92 },
	{ "MAP1_TEXTURE_COORD_1"						, 0x0D93 },
	{ "MAP1_TEXTURE_COORD_2"						, 0x0D94 },
	{ "MAP1_TEXTURE_COORD_3"						, 0x0D95 },
	{ "MAP1_TEXTURE_COORD_4"						, 0x0D96 },
	{ "MAP1_VERTEX_3"								, 0x0D97 },
	{ "MAP1_VERTEX_4"								, 0x0D98 },

	{ "MAP2_COLOR_4"								, 0x0DB0 },
	{ "MAP2_INDEX"									, 0x0DB1 },
	{ "MAP2_NORMAL"									, 0x0DB2 },
	{ "MAP2_TEXTURE_COORD_1"						, 0x0DB3 },
	{ "MAP2_TEXTURE_COORD_2"						, 0x0DB4 },
	{ "MAP2_TEXTURE_COORD_3"						, 0x0DB5 },
	{ "MAP2_TEXTURE_COORD_4"						, 0x0DB6 },
	{ "MAP2_VERTEX_3"								, 0x0DB7 },
	{ "MAP2_VERTEX_4"								, 0x0DB8 },

	{ "MAP1_GRID_DOMAIN"							, 0x0DD0 },
	{ "MAP1_GRID_SEGMENTS"							, 0x0DD1 },
	{ "MAP2_GRID_DOMAIN"							, 0x0DD2 },
	{ "MAP2_GRID_SEGMENTS"							, 0x0DD3 },

	{ "TEXTURE_1D"									, 0x0DE0 },
	{ "TEXTURE_2D"									, 0x0DE1 },

	{ "FEEDBACK_BUFFER_POINTER"						, 0x0DF0 },
	{ "FEEDBACK_BUFFER_SIZE"						, 0x0DF1 },
	{ "FEEDBACK_BUFFER_TYPE"						, 0x0DF2 },
	{ "SELECTION_BUFFER_POINTER"					, 0x0DF3 },
	{ "SELECTION_BUFFER_SIZE"						, 0x0DF4 },

	{ "TEXTURE_WIDTH"								, 0x1000 },
	{ "TEXTURE_HEIGHT"								, 0x1001 },

	{ "TEXTURE_COMPONENTS"							, 0x1003 },
	{ "TEXTURE_INTERNAL_FORMAT"						, 0x1003 },
	{ "TEXTURE_BORDER_COLOR"						, 0x1004 },
	{ "TEXTURE_BORDER"								, 0x1005 },

	{ "DONT_CARE"									, 0x1100 },
	{ "FASTEST"										, 0x1101 },
	{ "NICEST"										, 0x1102 },

	{ "AMBIENT"										, 0x1200 },
	{ "DIFFUSE"										, 0x1201 },
	{ "SPECULAR"									, 0x1202 },
	{ "POSITION"									, 0x1203 },
	{ "SPOT_DIRECTION"								, 0x1204 },
	{ "SPOT_EXPONENT"								, 0x1205 },
	{ "SPOT_CUTOFF"									, 0x1206 },
	{ "CONSTANT_ATTENUATION"						, 0x1207 },
	{ "LINEAR_ATTENUATION"							, 0x1208 },
	{ "QUADRATIC_ATTENUATION"						, 0x1209 },

	{ "COMPILE"										, 0x1300 },
	{ "COMPILE_AND_EXECUTE"							, 0x1301 },

	{ "CLEAR"										, 0x1500 },
	{ "AND"											, 0x1501 },
	{ "AND_REVERSE"									, 0x1502 },
	{ "COPY"										, 0x1503 },
	{ "AND_INVERTED"								, 0x1504 },
	{ "NOOP"										, 0x1505 },
	{ "XOR"											, 0x1506 },
	{ "OR"											, 0x1507 },
	{ "NOR"											, 0x1508 },
	{ "EQUIV"										, 0x1509 },
	{ "INVERT"										, 0x150A },
	{ "OR_REVERSE"									, 0x150B },
	{ "COPY_INVERTED"								, 0x150C },
	{ "OR_INVERTED"									, 0x150D },
	{ "NAND"										, 0x150E },
	{ "SET"											, 0x150F },

	{ "EMISSION"									, 0x1600 },
	{ "SHININESS"									, 0x1601 },
	{ "AMBIENT_AND_DIFFUSE"							, 0x1602 },
	{ "COLOR_INDEXES"								, 0x1603 },

	{ "MODELVIEW"									, 0x1700 },
	{ "PROJECTION"									, 0x1701 },
	{ "TEXTURE"										, 0x1702 },

	{ "COLOR"										, 0x1800 },
	{ "DEPTH"										, 0x1801 },
	{ "STENCIL"										, 0x1802 },

	{ "COLOR_INDEX"									, 0x1900 },
	{ "STENCIL_INDEX"								, 0x1901 },
	{ "DEPTH_COMPONENT"								, 0x1902 },
	{ "RED"											, 0x1903 },
	{ "GREEN"										, 0x1904 },
	{ "BLUE"										, 0x1905 },
	{ "ALPHA"										, 0x1906 },
	{ "RGB"											, 0x1907 },
	{ "RGBA"										, 0x1908 },
	{ "LUMINANCE"									, 0x1909 },
	{ "LUMINANCE_ALPHA"								, 0x190A },

	{ "BITMAP"										, 0x1A00 },

	{ "POINT"										, 0x1B00 },
	{ "LINE"										, 0x1B01 },
	{ "FILL"										, 0x1B02 },

	{ "RENDER"										, 0x1C00 },
	{ "FEEDBACK"									, 0x1C01 },
	{ "SELECT"										, 0x1C02 },

	{ "FLAT"										, 0x1D00 },
	{ "SMOOTH"										, 0x1D01 },

	{ "KEEP"										, 0x1E00 },
	{ "REPLACE"										, 0x1E01 },
	{ "INCR"										, 0x1E02 },
	{ "DECR"										, 0x1E03 },

	{ "VENDOR"										, 0x1F00 },
	{ "RENDERER"									, 0x1F01 },
	{ "VERSION"										, 0x1F02 },
	{ "EXTENSIONS"									, 0x1F03 },

	{ "S"											, 0x2000 },
	{ "T"											, 0x2001 },
	{ "R"											, 0x2002 },
	{ "Q"											, 0x2003 },

	{ "MODULATE"									, 0x2100 },
	{ "DECAL"										, 0x2101 },

	{ "TEXTURE_ENV_MODE"							, 0x2200 },
	{ "TEXTURE_ENV_COLOR"							, 0x2201 },
	{ "TEXTURE_ENV"									, 0x2300 },

	{ "EYE_LINEAR"									, 0x2400 },
	{ "OBJECT_LINEAR"								, 0x2401 },
	{ "SPHERE_MAP"									, 0x2402 },

	{ "TEXTURE_GEN_MODE"							, 0x2500 },
	{ "OBJECT_PLANE"								, 0x2501 },
	{ "EYE_PLANE"									, 0x2502 },

	{ "NEAREST"										, 0x2600 },
	{ "LINEAR"										, 0x2601 },

	{ "NEAREST_MIPMAP_NEAREST"						, 0x2700 },
	{ "LINEAR_MIPMAP_NEAREST"						, 0x2701 },
	{ "NEAREST_MIPMAP_LINEAR"						, 0x2702 },
	{ "LINEAR_MIPMAP_LINEAR"						, 0x2703 },

	{ "TEXTURE_MAG_FILTER"							, 0x2800 },
	{ "TEXTURE_MIN_FILTER"							, 0x2801 },
	{ "TEXTURE_WRAP_S"								, 0x2802 },
	{ "TEXTURE_WRAP_T"								, 0x2803 },

	{ "CLAMP"										, 0x2900 },
	{ "REPEAT"										, 0x2901 },

	{ "POLYGON_OFFSET_UNITS"						, 0x2A00 },
	{ "POLYGON_OFFSET_POINT"						, 0x2A01 },
	{ "POLYGON_OFFSET_LINE"							, 0x2A02 },

	{ "R3_G3_B2"									, 0x2A10 },

	{ "V2F"											, 0x2A20 },
	{ "V3F"											, 0x2A21 },
	{ "C4UB_V2F"									, 0x2A22 },
	{ "C4UB_V3F"									, 0x2A23 },
	{ "C3F_V3F"										, 0x2A24 },
	{ "N3F_V3F"										, 0x2A25 },
	{ "C4F_N3F_V3F"									, 0x2A26 },
	{ "T2F_V3F"										, 0x2A27 },
	{ "T4F_V4F"										, 0x2A28 },
	{ "T2F_C4UB_V3F"								, 0x2A29 },
	{ "T2F_C3F_V3F"									, 0x2A2A },
	{ "T2F_N3F_V3F"									, 0x2A2B },
	{ "T2F_C4F_N3F_V3F"								, 0x2A2C },
	{ "T4F_C4F_N3F_V4F"								, 0x2A2D },

	{ "CLIP_PLANE0"									, 0x3000 },
	{ "CLIP_PLANE1"									, 0x3001 },
	{ "CLIP_PLANE2"									, 0x3002 },
	{ "CLIP_PLANE3"									, 0x3003 },
	{ "CLIP_PLANE4"									, 0x3004 },
	{ "CLIP_PLANE5"									, 0x3005 },

	{ "LIGHT0"										, 0x4000 },
	{ "LIGHT1"										, 0x4001 },
	{ "LIGHT2"										, 0x4002 },
	{ "LIGHT3"										, 0x4003 },
	{ "LIGHT4"										, 0x4004 },
	{ "LIGHT5"										, 0x4005 },
	{ "LIGHT6"										, 0x4006 },
	{ "LIGHT7"										, 0x4007 },

	{ "CONSTANT_COLOR"								, 0x8001 },
	{ "ONE_MINUS_CONSTANT_COLOR"					, 0x8002 },
	{ "CONSTANT_ALPHA"								, 0x8003 },
	{ "ONE_MINUS_CONSTANT_ALPHA"					, 0x8004 },
	{ "BLEND_COLOR"									, 0x8005 },
	{ "FUNC_ADD"									, 0x8006 },
	{ "MIN"											, 0x8007 },
	{ "MAX"											, 0x8008 },
	{ "BLEND_EQUATION"								, 0x8009 },
	{ "BLEND_EQUATION_RGB"							, 0x8009 },
	{ "FUNC_SUBTRACT"								, 0x800A },
	{ "FUNC_REVERSE_SUBTRACT"						, 0x800B },

	{ "POLYGON_OFFSET_FILL"							, 0x8037 },
	{ "POLYGON_OFFSET_FACTOR"						, 0x8038 },

	{ "ALPHA4"										, 0x803B },
	{ "ALPHA8"										, 0x803C },
	{ "ALPHA12"										, 0x803D },
	{ "ALPHA16"										, 0x803E },
	{ "LUMINANCE4"									, 0x803F },
	{ "LUMINANCE8"									, 0x8040 },
	{ "LUMINANCE12"									, 0x8041 },
	{ "LUMINANCE16"									, 0x8042 },
	{ "LUMINANCE4_ALPHA4"							, 0x8043 },
	{ "LUMINANCE6_ALPHA2"							, 0x8044 },
	{ "LUMINANCE8_ALPHA8"							, 0x8045 },
	{ "LUMINANCE12_ALPHA4"							, 0x8046 },
	{ "LUMINANCE12_ALPHA12"							, 0x8047 },
	{ "LUMINANCE16_ALPHA16"							, 0x8048 },
	{ "INTENSITY"									, 0x8049 },
	{ "INTENSITY4"									, 0x804A },
	{ "INTENSITY8"									, 0x804B },
	{ "INTENSITY12"									, 0x804C },
	{ "INTENSITY16"									, 0x804D },

	{ "RGB4"										, 0x804F },
	{ "RGB5"										, 0x8050 },
	{ "RGB8"										, 0x8051 },
	{ "RGB10"										, 0x8052 },
	{ "RGB12"										, 0x8053 },
	{ "RGB16"										, 0x8054 },
	{ "RGBA2"										, 0x8055 },
	{ "RGBA4"										, 0x8056 },
	{ "RGB5_A1"										, 0x8057 },
	{ "RGBA8"										, 0x8058 },
	{ "RGB10_A2"									, 0x8059 },
	{ "RGBA12"										, 0x805A },
	{ "RGBA16"										, 0x805B },
	{ "TEXTURE_RED_SIZE"							, 0x805C },
	{ "TEXTURE_GREEN_SIZE"							, 0x805D },
	{ "TEXTURE_BLUE_SIZE"							, 0x805E },
	{ "TEXTURE_ALPHA_SIZE"							, 0x805F },
	{ "TEXTURE_LUMINANCE_SIZE"						, 0x8060 },
	{ "TEXTURE_INTENSITY_SIZE"						, 0x8061 },

	{ "PROXY_TEXTURE_1D"							, 0x8063 },
	{ "PROXY_TEXTURE_2D"							, 0x8064 },
	{ "TEXTURE_PRIORITY"							, 0x8066 },
	{ "TEXTURE_RESIDENT"							, 0x8067 },
	{ "TEXTURE_BINDING_1D"							, 0x8068 },
	{ "TEXTURE_BINDING_2D"							, 0x8069 },

	{ "PROXY_TEXTURE_3D"							, 0x8070 },
	{ "TEXTURE_DEPTH"								, 0x8071 },
	{ "TEXTURE_WRAP_R"								, 0x8072 },
	{ "MAX_3D_TEXTURE_SIZE"							, 0x8073 },

	{ "VERTEX_ARRAY"								, 0x8074 },
	{ "VERTEX_ARRAY_EXT"							, 0x8074 },
	{ "NORMAL_ARRAY"								, 0x8075 },
	{ "NORMAL_ARRAY_EXT"							, 0x8075 },
	{ "COLOR_ARRAY"									, 0x8076 },
	{ "COLOR_ARRAY_EXT"								, 0x8076 },
	{ "INDEX_ARRAY"									, 0x8077 },
	{ "INDEX_ARRAY_EXT"								, 0x8077 },
	{ "TEXTURE_COORD_ARRAY"							, 0x8078 },
	{ "TEXTURE_COORD_ARRAY_EXT"						, 0x8078 },
	{ "EDGE_FLAG_ARRAY"								, 0x8079 },
	{ "EDGE_FLAG_ARRAY_EXT"							, 0x8079 },
	{ "VERTEX_ARRAY_SIZE"							, 0x807A },
	{ "VERTEX_ARRAY_SIZE_EXT"						, 0x807A },
	{ "VERTEX_ARRAY_TYPE"							, 0x807B },
	{ "VERTEX_ARRAY_TYPE_EXT"						, 0x807B },
	{ "VERTEX_ARRAY_STRIDE"							, 0x807C },
	{ "VERTEX_ARRAY_STRIDE_EXT"						, 0x807C },
	{ "VERTEX_ARRAY_COUNT_EXT"						, 0x807D },
	{ "NORMAL_ARRAY_TYPE"							, 0x807E },
	{ "NORMAL_ARRAY_TYPE_EXT"						, 0x807E },
	{ "NORMAL_ARRAY_STRIDE"							, 0x807F },
	{ "NORMAL_ARRAY_STRIDE_EXT"						, 0x807F },
	{ "NORMAL_ARRAY_COUNT_EXT"						, 0x8080 },
	{ "COLOR_ARRAY_SIZE"							, 0x8081 },
	{ "COLOR_ARRAY_SIZE_EXT"						, 0x8081 },
	{ "COLOR_ARRAY_TYPE"							, 0x8082 },
	{ "COLOR_ARRAY_TYPE_EXT"						, 0x8082 },
	{ "COLOR_ARRAY_STRIDE"							, 0x8083 },
	{ "COLOR_ARRAY_STRIDE_EXT"						, 0x8083 },
	{ "COLOR_ARRAY_COUNT_EXT"						, 0x8084 },
	{ "INDEX_ARRAY_TYPE"							, 0x8085 },
	{ "INDEX_ARRAY_TYPE_EXT"						, 0x8085 },
	{ "INDEX_ARRAY_STRIDE"							, 0x8086 },
	{ "INDEX_ARRAY_STRIDE_EXT"						, 0x8086 },
	{ "INDEX_ARRAY_COUNT_EXT"						, 0x8087 },
	{ "TEXTURE_COORD_ARRAY_SIZE"					, 0x8088 },
	{ "TEXTURE_COORD_ARRAY_SIZE_EXT"				, 0x8088 },
	{ "TEXTURE_COORD_ARRAY_TYPE"					, 0x8089 },
	{ "TEXTURE_COORD_ARRAY_TYPE_EXT"				, 0x8089 },
	{ "TEXTURE_COORD_ARRAY_STRIDE"					, 0x808A },
	{ "TEXTURE_COORD_ARRAY_STRIDE_EXT"				, 0x808A },
	{ "TEXTURE_COORD_ARRAY_COUNT_EXT"				, 0x808B },
	{ "EDGE_FLAG_ARRAY_STRIDE"						, 0x808C },
	{ "EDGE_FLAG_ARRAY_STRIDE_EXT"					, 0x808C },
	{ "EDGE_FLAG_ARRAY_COUNT_EXT"					, 0x808D },
	{ "VERTEX_ARRAY_POINTER"						, 0x808E },
	{ "VERTEX_ARRAY_POINTER_EXT"					, 0x808E },
	{ "NORMAL_ARRAY_POINTER"						, 0x808F },
	{ "NORMAL_ARRAY_POINTER_EXT"					, 0x808F },
	{ "COLOR_ARRAY_POINTER"							, 0x8090 },
	{ "COLOR_ARRAY_POINTER_EXT"						, 0x8090 },
	{ "INDEX_ARRAY_POINTER"							, 0x8091 },
	{ "INDEX_ARRAY_POINTER_EXT"						, 0x8091 },
	{ "TEXTURE_COORD_ARRAY_POINTER"					, 0x8092 },
	{ "TEXTURE_COORD_ARRAY_POINTER_EXT"				, 0x8092 },
	{ "EDGE_FLAG_ARRAY_POINTER"						, 0x8093 },
	{ "EDGE_FLAG_ARRAY_POINTER_EXT"					, 0x8093 },

	{ "BLEND_DST_RGB"								, 0x80C8 },
	{ "BLEND_SRC_RGB"								, 0x80C9 },
	{ "BLEND_DST_ALPHA"								, 0x80CA },
	{ "BLEND_SRC_ALPHA"								, 0x80CB },

	{ "BGR"											, 0x80E0 },
	{ "BGR_EXT"										, 0x80E0 },
	{ "BGRA"										, 0x80E1 },
	{ "BGRA_EXT"									, 0x80E1 },
	{ "COLOR_TABLE_FORMAT_EXT"						, 0x80D8 },
	{ "COLOR_TABLE_WIDTH_EXT"						, 0x80D9 },
	{ "COLOR_TABLE_RED_SIZE_EXT"					, 0x80DA },
	{ "COLOR_TABLE_GREEN_SIZE_EXT"					, 0x80DB },
	{ "COLOR_TABLE_BLUE_SIZE_EXT"					, 0x80DC },
	{ "COLOR_TABLE_ALPHA_SIZE_EXT"					, 0x80DD },
	{ "COLOR_TABLE_LUMINANCE_SIZE_EXT"				, 0x80DE },
	{ "COLOR_TABLE_INTENSITY_SIZE_EXT"				, 0x80DF },
	{ "COLOR_INDEX1_EXT"							, 0x80E2 },
	{ "COLOR_INDEX2_EXT"							, 0x80E3 },
	{ "COLOR_INDEX4_EXT"							, 0x80E4 },
	{ "COLOR_INDEX8_EXT"							, 0x80E5 },
	{ "COLOR_INDEX12_EXT"							, 0x80E6 },
	{ "COLOR_INDEX16_EXT"							, 0x80E7 },
	{ "MAX_ELEMENTS_VERTICES_WIN"					, 0x80E8 },
	{ "MAX_ELEMENTS_INDICES_WIN"					, 0x80E9 },
	{ "PHONG_WIN"									, 0x80EA },
	{ "PHONG_HINT_WIN"								, 0x80EB },
	{ "FOG_SPECULAR_TEXTURE_WIN"					, 0x80EC },

	{ "MULTISAMPLE"									, 0x809D },
	{ "SAMPLE_ALPHA_TO_COVERAGE"					, 0x809E },
	{ "SAMPLE_ALPHA_TO_ONE"							, 0x809F },
	{ "SAMPLE_COVERAGE"								, 0x80A0 },

	{ "SAMPLE_BUFFERS"								, 0x80A8 },
	{ "SAMPLES"										, 0x80A9 },
	{ "SAMPLE_COVERAGE_VALUE"						, 0x80AA },
	{ "SAMPLE_COVERAGE_INVERT"						, 0x80AB },

	{ "POINT_SIZE_MIN"								, 0x8126 },
	{ "POINT_SIZE_MAX"								, 0x8127 },
	{ "POINT_FADE_THRESHOLD_SIZE"					, 0x8128 },
	{ "POINT_DISTANCE_ATTENUATION"					, 0x8129 },
	
	{ "CLAMP_TO_BORDER"								, 0x812D },

	{ "CLAMP_TO_EDGE"								, 0x812F },

	{ "TEXTURE_MIN_LOD"								, 0x813A },
	{ "TEXTURE_MAX_LOD"								, 0x813B },
	{ "TEXTURE_BASE_LEVEL"							, 0x813C },
	{ "TEXTURE_MAX_LEVEL"							, 0x813D },

	{ "GENERATE_MIPMAP"								, 0x8191 },
	{ "GENERATE_MIPMAP_HINT"						, 0x8192 },

	{ "DEPTH_COMPONENT16"							, 0x81A5 },
	{ "DEPTH_COMPONENT24"							, 0x81A6 },
	{ "DEPTH_COMPONENT32"							, 0x81A7 },

	{ "MIRRORED_REPEAT"								, 0x8370 },

	{ "FOG_COORD_SRC"								, 0x8450 },
	{ "FOG_COORDINATE_SOURCE"						, 0x8450 },
	{ "FOG_COORD"									, 0x8451 },
	{ "FOG_COORDINATE"								, 0x8451 },
	{ "FRAGMENT_DEPTH"								, 0x8452 },
	{ "CURRENT_FOG_COORD"							, 0x8453 },
	{ "CURRENT_FOG_COORDINATE"						, 0x8453 },
	{ "FOG_COORD_ARRAY_TYPE"						, 0x8454 },
	{ "FOG_COORDINATE_ARRAY_TYPE"					, 0x8454 },
	{ "FOG_COORD_ARRAY_STRIDE"						, 0x8455 },
	{ "FOG_COORDINATE_ARRAY_STRIDE"					, 0x8455 },
	{ "FOG_COORD_ARRAY_POINTER"						, 0x8456 },
	{ "FOG_COORDINATE_ARRAY_POINTER"				, 0x8456 },
	{ "FOG_COORD_ARRAY"								, 0x8457 },
	{ "FOG_COORDINATE_ARRAY"						, 0x8457 },
	{ "COLOR_SUM"									, 0x8458 },
	{ "CURRENT_SECONDARY_COLOR"						, 0x8459 },
	{ "SECONDARY_COLOR_ARRAY_SIZE"					, 0x845A },
	{ "SECONDARY_COLOR_ARRAY_TYPE"					, 0x845B },
	{ "SECONDARY_COLOR_ARRAY_STRIDE"				, 0x845C },
	{ "SECONDARY_COLOR_ARRAY_POINTER"				, 0x845D },
	{ "SECONDARY_COLOR_ARRAY"						, 0x845E },

	{ "TEXTURE0"									, 0x84C0 },
	{ "TEXTURE1"									, 0x84C1 },
	{ "TEXTURE2"									, 0x84C2 },
	{ "TEXTURE3"									, 0x84C3 },
	{ "TEXTURE4"									, 0x84C4 },
	{ "TEXTURE5"									, 0x84C5 },
	{ "TEXTURE6"									, 0x84C6 },
	{ "TEXTURE7"									, 0x84C7 },
	{ "TEXTURE8"									, 0x84C8 },
	{ "TEXTURE9"									, 0x84C9 },
	{ "TEXTURE10"									, 0x84CA },
	{ "TEXTURE11"									, 0x84CB },
	{ "TEXTURE12"									, 0x84CC },
	{ "TEXTURE13"									, 0x84CD },
	{ "TEXTURE14"									, 0x84CE },
	{ "TEXTURE15"									, 0x84CF },
	{ "TEXTURE16"									, 0x84D0 },
	{ "TEXTURE17"									, 0x84D1 },
	{ "TEXTURE18"									, 0x84D2 },
	{ "TEXTURE19"									, 0x84D3 },
	{ "TEXTURE20"									, 0x84D4 },
	{ "TEXTURE21"									, 0x84D5 },
	{ "TEXTURE22"									, 0x84D6 },
	{ "TEXTURE23"									, 0x84D7 },
	{ "TEXTURE24"									, 0x84D8 },
	{ "TEXTURE25"									, 0x84D9 },
	{ "TEXTURE26"									, 0x84DA },
	{ "TEXTURE27"									, 0x84DB },
	{ "TEXTURE28"									, 0x84DC },
	{ "TEXTURE29"									, 0x84DD },
	{ "TEXTURE30"									, 0x84DE },
	{ "TEXTURE31"									, 0x84DF },
	{ "ACTIVE_TEXTURE"								, 0x84E0 },
	{ "CLIENT_ACTIVE_TEXTURE"						, 0x84E1 },
	{ "MAX_TEXTURE_UNITS"							, 0x84E2 },
	{ "TRANSPOSE_MODELVIEW_MATRIX"					, 0x84E3 },
	{ "TRANSPOSE_PROJECTION_MATRIX"					, 0x84E4 },
	{ "TRANSPOSE_TEXTURE_MATRIX"					, 0x84E5 },
	{ "TRANSPOSE_COLOR_MATRIX"						, 0x84E6 },
	{ "SUBTRACT"									, 0x84E7 },

	{ "COMPRESSED_ALPHA"							, 0x84E9 },
	{ "COMPRESSED_LUMINANCE"						, 0x84EA },
	{ "COMPRESSED_LUMINANCE_ALPHA"					, 0x84EB },
	{ "COMPRESSED_INTENSITY"						, 0x84EC },
	{ "COMPRESSED_RGB"								, 0x84ED },
	{ "COMPRESSED_RGBA"								, 0x84EE },
	{ "TEXTURE_COMPRESSION_HINT"					, 0x84EF },

	{ "MAX_TEXTURE_LOD_BIAS"						, 0x84FD },

	{ "TEXTURE_FILTER_CONTROL"						, 0x8500 },
	{ "TEXTURE_LOD_BIAS"							, 0x8501 },

	{ "INCR_WRAP"									, 0x8507 },
	{ "DECR_WRAP"									, 0x8508 },

	{ "NORMAL_MAP"									, 0x8511 },
	{ "REFLECTION_MAP"								, 0x8512 },
	{ "TEXTURE_CUBE_MAP"							, 0x8513 },
	{ "TEXTURE_BINDING_CUBE_MAP"					, 0x8514 },
	{ "TEXTURE_CUBE_MAP_POSITIVE_X"					, 0x8515 },
	{ "TEXTURE_CUBE_MAP_NEGATIVE_X"					, 0x8516 },
	{ "TEXTURE_CUBE_MAP_POSITIVE_Y"					, 0x8517 },
	{ "TEXTURE_CUBE_MAP_NEGATIVE_Y"					, 0x8518 },
	{ "TEXTURE_CUBE_MAP_POSITIVE_Z"					, 0x8519 },
	{ "TEXTURE_CUBE_MAP_NEGATIVE_Z"					, 0x851A },
	{ "PROXY_TEXTURE_CUBE_MAP"						, 0x851B },
	{ "MAX_CUBE_MAP_TEXTURE_SIZE"					, 0x851C },

	{ "COMBINE"										, 0x8570 },
	{ "COMBINE_RGB"									, 0x8571 },
	{ "COMBINE_ALPHA"								, 0x8572 },
	{ "RGB_SCALE"									, 0x8573 },
	{ "ADD_SIGNED"									, 0x8574 },
	{ "INTERPOLATE"									, 0x8575 },
	{ "CONSTANT"									, 0x8576 },
	{ "PRIMARY_COLOR"								, 0x8577 },
	{ "PREVIOUS"									, 0x8578 },

	{ "SOURCE0_RGB"									, 0x8580 },
	{ "SOURCE1_RGB"									, 0x8581 },
	{ "SOURCE2_RGB"									, 0x8582 },

	{ "SOURCE0_ALPHA"								, 0x8588 },
	{ "SOURCE1_ALPHA"								, 0x8589 },
	{ "SOURCE2_ALPHA"								, 0x858A },

	{ "OPERAND0_RGB"								, 0x8590 },
	{ "OPERAND1_RGB"								, 0x8591 },
	{ "OPERAND2_RGB"								, 0x8592 },

	{ "OPERAND0_ALPHA"								, 0x8598 },
	{ "OPERAND1_ALPHA"								, 0x8599 },
	{ "OPERAND2_ALPHA"								, 0x859A },

	{ "VERTEX_ATTRIB_ARRAY_ENABLED"					, 0x8622 },
	{ "VERTEX_ATTRIB_ARRAY_SIZE"					, 0x8623 },
	{ "VERTEX_ATTRIB_ARRAY_STRIDE"					, 0x8624 },
	{ "VERTEX_ATTRIB_ARRAY_TYPE"					, 0x8625 },
	{ "CURRENT_VERTEX_ATTRIB"						, 0x8626 },

	{ "VERTEX_PROGRAM_POINT_SIZE"					, 0x8642 },
	{ "VERTEX_PROGRAM_TWO_SIDE"						, 0x8643 },

	{ "VERTEX_ATTRIB_ARRAY_POINTER"					, 0x8645 },

	{ "TEXTURE_COMPRESSED_IMAGE_SIZE"				, 0x86A0 },
	{ "TEXTURE_COMPRESSED"							, 0x86A1 },
	{ "NUM_COMPRESSED_TEXTURE_FORMATS"				, 0x86A2 },
	{ "COMPRESSED_TEXTURE_FORMATS"					, 0x86A3 },

	{ "DOT3_RGB"									, 0x86AE },
	{ "DOT3_RGBA"									, 0x86AF },

	{ "MIRROR_CLAMP_EXT"							, 0x8742 },
	{ "MIRROR_CLAMP_TO_EDGE_EXT"					, 0x8743 },

	{ "BUFFER_SIZE"									, 0x8764 },
	{ "BUFFER_USAGE"								, 0x8765 },

	{ "BLEND_EQUATION_ALPHA"						, 0x883D },

	{ "TEXTURE_DEPTH_SIZE"							, 0x884A },
	{ "DEPTH_TEXTURE_MODE"							, 0x884B },
	{ "TEXTURE_COMPARE_MODE"						, 0x884C },
	{ "TEXTURE_COMPARE_FUNC"						, 0x884D },
	{ "COMPARE_R_TO_TEXTURE"						, 0x884E },

	{ "POINT_SPRITE"								, 0x8861 },
	{ "COORD_REPLACE"								, 0x8862 },

	{ "QUERY_COUNTER_BITS"							, 0x8864 },
	{ "CURRENT_QUERY"								, 0x8865 },
	{ "QUERY_RESULT"								, 0x8866 },
	{ "QUERY_RESULT_AVAILABLE"						, 0x8867 },

	{ "MAX_VERTEX_ATTRIBS"							, 0x8869 },
	{ "VERTEX_ATTRIB_ARRAY_NORMALIZED"				, 0x886A },

	{ "MAX_TEXTURE_COORDS"							, 0x8871 },
	{ "MAX_TEXTURE_IMAGE_UNITS"						, 0x8872 },

	{ "ARRAY_BUFFER"								, 0x8892 },
	{ "ELEMENT_ARRAY_BUFFER"						, 0x8893 },
	{ "ARRAY_BUFFER_BINDING"						, 0x8894 },
	{ "ELEMENT_ARRAY_BUFFER_BINDING"				, 0x8895 },
	{ "VERTEX_ARRAY_BUFFER_BINDING"					, 0x8896 },
	{ "NORMAL_ARRAY_BUFFER_BINDING"					, 0x8897 },
	{ "COLOR_ARRAY_BUFFER_BINDING"					, 0x8898 },
	{ "INDEX_ARRAY_BUFFER_BINDING"					, 0x8899 },
	{ "TEXTURE_COORD_ARRAY_BUFFER_BINDING"			, 0x889A },
	{ "EDGE_FLAG_ARRAY_BUFFER_BINDING"				, 0x889B },
	{ "SECONDARY_COLOR_ARRAY_BUFFER_BINDING"		, 0x889C },
	{ "FOG_COORD_ARRAY_BUFFER_BINDING"				, 0x889D },
	{ "FOG_COORDINATE_ARRAY_BUFFER_BINDING"			, 0x889D },
	{ "WEIGHT_ARRAY_BUFFER_BINDING"					, 0x889E },
	{ "VERTEX_ATTRIB_ARRAY_BUFFER_BINDING"			, 0x889F },

	{ "READ_ONLY"									, 0x88B8 },
	{ "WRITE_ONLY"									, 0x88B9 },
	{ "READ_WRITE"									, 0x88BA },
	{ "BUFFER_ACCESS"								, 0x88BB },
	{ "BUFFER_MAPPED"								, 0x88BC },
	{ "BUFFER_MAP_POINTER"							, 0x88BD },

	{ "STREAM_DRAW"									, 0x88E0 },
	{ "STREAM_READ"									, 0x88E1 },
	{ "STREAM_COPY"									, 0x88E2 },
	{ "STATIC_DRAW"									, 0x88E4 },
	{ "STATIC_READ"									, 0x88E5 },
	{ "STATIC_COPY"									, 0x88E6 },
	{ "DYNAMIC_DRAW"								, 0x88E8 },
	{ "DYNAMIC_READ"								, 0x88E9 },
	{ "DYNAMIC_COPY"								, 0x88EA },
	{ "PIXEL_PACK_BUFFER"							, 0x88EB },
	{ "PIXEL_PACK_BUFFER_ARB"						, 0x88EB },
	{ "PIXEL_UNPACK_BUFFER"							, 0x88EC },
	{ "PIXEL_UNPACK_BUFFER_ARB"						, 0x88EC },
	{ "PIXEL_PACK_BUFFER_BINDING"					, 0x88ED },
	{ "PIXEL_PACK_BUFFER_BINDING_ARB"				, 0x88ED },

	{ "PIXEL_UNPACK_BUFFER_BINDING"					, 0x88EF },
	{ "PIXEL_UNPACK_BUFFER_BINDING_ARB"				, 0x88EF },

	{ "MIRROR_CLAMP_TO_BORDER_EXT"					, 0x8912 },

	{ "SAMPLES_PASSED"								, 0x8914 },

	{ "FRAGMENT_SHADER"								, 0x8B30 },
	{ "VERTEX_SHADER"								, 0x8B31 },
	{ "PROGRAM_OBJECT_ARB"							, 0x8B40 },
	{ "SHADER_OBJECT_ARB"							, 0x8B48 },
	{ "MAX_FRAGMENT_UNIFORM_COMPONENTS"				, 0x8B49 },
	{ "MAX_VERTEX_UNIFORM_COMPONENTS"				, 0x8B4A },
	{ "MAX_VARYING_FLOATS"							, 0x8B4B },
	{ "MAX_VERTEX_TEXTURE_IMAGE_UNITS"				, 0x8B4C },
	{ "MAX_COMBINED_TEXTURE_IMAGE_UNITS"			, 0x8B4D },
	{ "SHADER_TYPE"									, 0x8B4F },
	{ "FLOAT_VEC2"									, 0x8B50 },
	{ "FLOAT_VEC3"									, 0x8B51 },
	{ "FLOAT_VEC4"									, 0x8B52 },
	{ "INT_VEC2"									, 0x8B53 },
	{ "INT_VEC3"									, 0x8B54 },
	{ "INT_VEC4"									, 0x8B55 },
	{ "BOOL"										, 0x8B56 },
	{ "BOOL_VEC2"									, 0x8B57 },
	{ "BOOL_VEC3"									, 0x8B58 },
	{ "BOOL_VEC4"									, 0x8B59 },
	{ "FLOAT_MAT2"									, 0x8B5A },
	{ "FLOAT_MAT3"									, 0x8B5B },
	{ "FLOAT_MAT4"									, 0x8B5C },
	{ "SAMPLER_1D"									, 0x8B5D },
	{ "SAMPLER_2D"									, 0x8B5E },
	{ "SAMPLER_3D"									, 0x8B5F },
	{ "SAMPLER_CUBE"								, 0x8B60 },
	{ "SAMPLER_1D_SHADOW"							, 0x8B61 },
	{ "SAMPLER_2D_SHADOW"							, 0x8B62 },
	{ "SAMPLER_2D_RECT_ARB"							, 0x8B63 },
	{ "SAMPLER_2D_RECT_SHADOW_ARB"					, 0x8B64 },
	{ "FLOAT_MAT2x3"								, 0x8B65 },
	{ "FLOAT_MAT2x4"								, 0x8B66 },
	{ "FLOAT_MAT3x2"								, 0x8B67 },
	{ "FLOAT_MAT3x4"								, 0x8B68 },
	{ "FLOAT_MAT4x2"								, 0x8B69 },
	{ "FLOAT_MAT4x3"								, 0x8B6A },

	{ "DELETE_STATUS"								, 0x8B80 },
	{ "COMPILE_STATUS"								, 0x8B81 },
	{ "LINK_STATUS"									, 0x8B82 },
	{ "VALIDATE_STATUS"								, 0x8B83 },
	{ "INFO_LOG_LENGTH"								, 0x8B84 },
	{ "ATTACHED_SHADERS"							, 0x8B85 },
	{ "ACTIVE_UNIFORMS"								, 0x8B86 },
	{ "ACTIVE_UNIFORM_MAX_LENGTH"					, 0x8B87 },
	{ "SHADER_SOURCE_LENGTH"						, 0x8B88 },
	{ "ACTIVE_ATTRIBUTES"							, 0x8B89 },
	{ "ACTIVE_ATTRIBUTE_MAX_LENGTH"					, 0x8B8A },
	{ "FRAGMENT_SHADER_DERIVATIVE_HINT"				, 0x8B8B },
	{ "SHADING_LANGUAGE_VERSION"					, 0x8B8C },

	{ "POINT_SPRITE_COORD_ORIGIN"					, 0x8CA0 },
	{ "LOWER_LEFT"									, 0x8CA1 },
	{ "UPPER_LEFT"									, 0x8CA2 },
	{ "STENCIL_BACK_REF"							, 0x8CA3 },
	{ "STENCIL_BACK_VALUE_MASK"						, 0x8CA4 },
	{ "STENCIL_BACK_WRITEMASK"						, 0x8CA5 },

	{ "CURRENT_BIT"									, 0x00000001 },
	{ "CLIENT_PIXEL_STORE_BIT"						, 0x00000001 },
	{ "POINT_BIT"									, 0x00000002 },
	{ "CLIENT_VERTEX_ARRAY_BIT"						, 0x00000002 },
	{ "LINE_BIT"									, 0x00000004 },
	{ "POLYGON_BIT"									, 0x00000008 },
	{ "POLYGON_STIPPLE_BIT"							, 0x00000010 },
	{ "PIXEL_MODE_BIT"								, 0x00000020 },
	{ "LIGHTING_BIT"								, 0x00000040 },
	{ "FOG_BIT"										, 0x00000080 },
	{ "DEPTH_BUFFER_BIT"							, 0x00000100 },
	{ "ACCUM_BUFFER_BIT"							, 0x00000200 },
	{ "STENCIL_BUFFER_BIT"							, 0x00000400 },
	{ "VIEWPORT_BIT"								, 0x00000800 },
	{ "TRANSFORM_BIT"								, 0x00001000 },
	{ "ENABLE_BIT"									, 0x00002000 },
	{ "COLOR_BUFFER_BIT"							, 0x00004000 },
	{ "HINT_BIT"									, 0x00008000 },
	{ "EVAL_BIT"									, 0x00010000 },
	{ "LIST_BIT"									, 0x00020000 },
	{ "TEXTURE_BIT"									, 0x00040000 },
	{ "SCISSOR_BIT"									, 0x00080000 },
	{ "ALL_ATTRIB_BITS"								, 0x000fffff },
	{ "MULTISAMPLE_BIT"								, 0x20000000 },
	{ "CLIENT_ALL_ATTRIB_BITS"						, 0xffffffff },
	{ 0, 0}
};

#endif


