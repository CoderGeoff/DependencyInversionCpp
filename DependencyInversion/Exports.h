#pragma once
#ifdef DEPENDENCYINVERSION_EXPORTS
#    define DEPENDENCYINVERSION_API __declspec(dllexport)
#else
#    define DEPENDENCYINVERSION_API __declspec(dllimport)
#endif