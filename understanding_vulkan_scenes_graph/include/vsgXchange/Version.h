/* <editor-fold desc="MIT License">

Copyright(c) 2021 Robert Osfield

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

</editor-fold> */

#pragma once

#include <vsgXchange/Export.h>
#include <vsg/core/Version.h>

#ifdef __cplusplus
extern "C"
{
#endif

    #define VSGXCHANGE_VERSION_MAJOR    1
    #define VSGXCHANGE_VERSION_MINOR    1
    #define VSGXCHANGE_VERSION_PATCH    4
    #define VSGXCHANGE_SOVERSION        1

    #define VSGXCHANGE_VERSION_STRING   "1.1.4"
    #define VSGXCHANGE_SOVERSION_STRING "1"

    extern VSGXCHANGE_DECLSPEC struct VsgVersion vsgXchangeGetVersion();
    extern VSGXCHANGE_DECLSPEC const char* vsgXchangeGetVersionString();
    extern VSGXCHANGE_DECLSPEC const char* vsgXchangeGetSOVersionString();

    /// return 0 if the linked vsgXchange was built as static library (default), 1 if the linked vsgXchange library was built as shared/dynamic library.
    /// When building against a shared library, to ensure the correct selection of VSGXCHANGE_DECLSPEC (provided in vsgXchange/Export.h) one must compile with the define VSGXCHANGE_SHARED_LIBRARY
    extern VSGXCHANGE_DECLSPEC int vsgXchangeBuiltAsSharedLibrary();

    /// standard Features
    #define vsgXchange_all
    #define vsgXchange_images
    #define vsgXchange_models
    #define vsgXchange_stbi
    #define vsgXchange_dds
    #define vsgXchange_ktx
    #define vsgXchange_spv
    #define vsgXchange_cpp

    /// optional Features
    #define vsgXchange_curl
    #define vsgXchange_openexr
    #define vsgXchange_freetype
    #define vsgXchange_assimp
/* #undef vsgXchange_GDAL */
/* #undef vsgXchange_OSG */

#ifdef __cplusplus
}
#endif
