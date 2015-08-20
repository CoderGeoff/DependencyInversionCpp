#pragma once
#ifdef SNAKESANDLADDERS_EXPORTS
#    define SNAKESANDLADDERS_API __declspec(dllexport)
#else
#    define SNAKESANDLADDERS_API __declspec(dllimport)
#endif