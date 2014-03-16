// LikeMagic C++ Binding Library
// Copyright 2008-2013 Dennis Ferron
// Co-founder DropEcho Studios, LLC.
// Visit our website at dropecho.com.
//
// LikeMagic is BSD-licensed.
// (See the license file in LikeMagic/Licenses.)

#if defined(USE_DLL_BUILD) && (defined _WIN32 || defined __CYGWIN__ || defined __MINGW32__)
  #ifdef BUILDING_BULLET_BINDINGS_DLL
    #ifdef __GNUC__
      #define BULLET_BINDINGS_API __attribute__((dllexport))
    #else
      #define BULLET_BINDINGS_API __declspec(dllexport) // Note: actually gcc seems to also supports this syntax.
    #endif
  #else
    #ifdef __GNUC__
      #define BULLET_BINDINGS_API __attribute__((dllimport))
    #else
      #define BULLET_BINDINGS_API __declspec(dllimport) // Note: actually gcc seems to also supports this syntax.
    #endif
  #endif
#else
    #define BULLET_BINDINGS_API
#endif

#pragma once
