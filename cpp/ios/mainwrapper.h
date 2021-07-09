#ifndef _MAINWRAPPER_H_INCLUDED_
#define _MAINWRAPPER_H_INCLUDED_

#if defined(WIN32) || defined(WINAPI_FAMILY)
#define STDCALL __cdecl
#ifdef _WINDLL
  #define DECLDIR __declspec(dllexport)
#else
  #define DECLDIR __declspec(dllimport)
#endif
#else
#define STDCALL
#define DECLDIR __attribute__ ((visibility("default")))
#endif

extern "C" {

  // returns a list of AV devices on the native side
  DECLDIR void STDCALL MosquittoSRV_start(const char* commandline);

  DECLDIR void STDCALL MosquittoSRV_stop();

}; //extern "C"


#endif // _MAINWRAPPER_H_INCLUDED_
