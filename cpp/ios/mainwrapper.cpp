#include "mainwrapper.h"

#include <iostream>

#include <stdio.h>
#include <stdlib.h>
#include <thread>
#include <chrono>

void startThread(const char* commandline);
void stopThread();
std::thread * runThread = NULL;
int argc = 1;
char **argv = NULL;
char* cmd = NULL;

#ifndef ANDROID
  // C++14 feature
  using namespace std::chrono_literals;
#endif

extern "C"
{
    extern int run;
    extern int main(int argc, char *argv[]);

    void STDCALL MosquittoSRV_start(const char* commandline)
    {
      if(!runThread)
        startThread(commandline);
    }

    void STDCALL MosquittoSRV_stop()
    {
      if(runThread)
        stopThread();
    }

};

void stopThread()
{
  run = 0;
#ifndef ANDROID
  std::this_thread::sleep_for(500ms);
#else
  std::this_thread::sleep_for(std::chrono::milliseconds(500));
#endif
  runThread = NULL;
  free(argv);
  free(cmd);
  argv = NULL;
}

void srvFun()
{
  main(argc, argv);
}

void startThread(const char* commandline)
{
  argv = (char**)malloc(sizeof(char *)*16); // 16 max...
  argv[0] = "mosquitto";
  argc = 1;

  //std::cout << "==================== " << commandline << " ======================" << std::endl;

  char* cmd = (char*)malloc(strlen(commandline)+1); cmd[strlen(commandline)] = '\0';
  sprintf(cmd,"%s",commandline);

  //std::cout << "==================== " << cmd << " ======================" << std::endl;
  // parse command line and put in # of arguments + arguments themselves...
  char * pch;
  pch = strtok (cmd," ");
  while (pch != NULL && argc < 15)
  {
    //std::cout << "==== " << pch << " ====" << std::endl;
    argv[argc++] = pch;
    pch = strtok (NULL, " ");
  }
  runThread = new std::thread(srvFun);
}
