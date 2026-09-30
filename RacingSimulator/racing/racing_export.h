#pragma once

#ifdef _WIN32

#ifdef RACINGLIBRARYDYNAMIC_EXPORTS
#define RACINGLIBRARY __declspec(dllexport)
#else
#define RACINGLIBRARY __declspec(dllimport)
#endif

#else

#define RACINGLIBRARY

#endif