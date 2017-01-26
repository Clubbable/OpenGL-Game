#pragma once

#ifndef UTIL_H
#define	UTIL_H


#ifndef WIN32
#include <unistd.h>
#endif

#include <stdlib.h>
#include <stdio.h>

#define ARRAY_SIZE_IN_ELEMENTS(a) (sizeof(a)/sizeof(a[0]))

#ifdef WIN32
#define SNPRINTF _snprintf_s
#else
#define SNPRINTF snprintf
#endif
#define INVALID_OGL_VALUE 0xFFFFFFFF

#define SAFE_DELETE(p) if (p) { delete p; p = NULL; }

#define GLCheckError()  \
{       \
    GLenum Error = glGetError();    \
\
    if (Error != GL_NO_ERROR) { \
        printf("OpenGL error in %s:%d: 0x%x\n", __FILE__, __LINE__, Error);  \
        exit(0);    \
    }   \
}

#endif	/* UTIL_H */

