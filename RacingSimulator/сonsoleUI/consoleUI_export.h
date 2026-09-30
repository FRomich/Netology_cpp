#pragma once

#ifdef _WIN32

#ifdef CONSOLEUILIBRARYDYNAMIC_EXPORTS
#define CONSOLEUILIBRARY __declspec(dllexport)
#else
#define CONSOLEUILIBRARY __declspec(dllimport)
#endif

#else

#define CONSOLEUILIBRARY

#endif