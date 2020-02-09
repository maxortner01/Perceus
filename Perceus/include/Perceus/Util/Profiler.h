#pragma once

#include "Perceus/Data/Singleton.h"

#include <stdio.h>
#include <cstring>
#include <stdlib.h>

#ifndef WIN32
#include "sys/times.h"
#include "sys/vtimes.h"
#else
#include <windows.h>
#endif

namespace pcs
{
    class Profiler : public Data::Singleton<Profiler>
    {
<<<<<<< HEAD
#ifndef WIN32
        // https://stackoverflow.com/questions/63166/how-to-determine-cpu-and-memory-consumption-from-inside-a-process
        static clock_t lastCPU, lastSysCPU, lastUserCPU;
        static int numProcessors;

        void init() const
        {
            FILE* file;
            struct tms timeSample;
            char line[128];

            lastCPU = times(&timeSample);
            lastSysCPU = timeSample.tms_stime;
            lastUserCPU = timeSample.tms_utime;

            file = fopen("/proc/cpuinfo", "r");
            numProcessors = 0;
            while(fgets(line, 128, file) != NULL){
                if (strncmp(line, "processor", 9) == 0) numProcessors++;
            }
            fclose(file);
        }

        double getCurrentValue() const
        {
            struct tms timeSample;
            clock_t now;
            double percent;

            now = times(&timeSample);
            if (now <= lastCPU || timeSample.tms_stime < lastSysCPU ||
                timeSample.tms_utime < lastUserCPU){
                //Overflow detection. Just skip this value.
                percent = -1.0;
            }
            else{
                percent = (timeSample.tms_stime - lastSysCPU) +
                    (timeSample.tms_utime - lastUserCPU);
                percent /= (now - lastCPU);
                percent /= numProcessors;
                percent *= 100;
            }
            lastCPU = now;
            lastSysCPU = timeSample.tms_stime;
            lastUserCPU = timeSample.tms_utime;

            return percent;
        }
        
        int parseLine(char* line) const
        {
            // This assumes that a digit will be found and the line ends in " Kb".
            int i = strlen(line);
            const char* p = line;
            while (*p <'0' || *p > '9') p++;
            line[i-3] = '\0';
            i = atoi(p);
            return i;
        }

        int getValue() const 
        {
            FILE* file = fopen("/proc/self/status", "r");
            int result = -1;
            char line[128];

            while (fgets(line, 128, file) != NULL){
                if (strncmp(line, "VmSize:", 7) == 0){
                    result = parseLine(line);
                    break;
                }
            }
            fclose(file);
            return result;
        }

#else
        static ULARGE_INTEGER lastCPU, lastSysCPU, lastUserCPU;
        static int numProcessors;
        static HANDLE self;

        void init() const
        {
            SYSTEM_INFO sysInfo;
            FILETIME ftime, fsys, fuser;

            GetSystemInfo(&sysInfo);
            numProcessors = sysInfo.dwNumberOfProcessors;

            GetSystemTimeAsFileTime(&ftime);
            memcpy(&lastCPU, &ftime, sizeof(FILETIME));

            self = GetCurrentProcess();
            GetProcessTimes(self, &ftime, &ftime, &fsys, &fuser);
            memcpy(&lastSysCPU, &fsys, sizeof(FILETIME));
            memcpy(&lastUserCPU, &fuser, sizeof(FILETIME));
        }

        double getCurrentValue() const
        {
            FILETIME ftime, fsys, fuser;
            ULARGE_INTEGER now, sys, user;
            double percent;

            GetSystemTimeAsFileTime(&ftime);
            memcpy(&now, &ftime, sizeof(FILETIME));

            GetProcessTimes(self, &ftime, &ftime, &fsys, &fuser);
            memcpy(&sys, &fsys, sizeof(FILETIME));
            memcpy(&user, &fuser, sizeof(FILETIME));
            percent = (sys.QuadPart - lastSysCPU.QuadPart) +
                (user.QuadPart - lastUserCPU.QuadPart);
            percent /= (now.QuadPart - lastCPU.QuadPart);
            percent /= numProcessors;
            lastCPU = now;
            lastUserCPU = user;
            lastSysCPU = sys;

            return percent * 100;
        }
#endif
=======
#if defined(WIN32) or defined(_WIN32)
        static ULARGE_INTEGER lastCPU, lastSysCPU, lastUserCPU;
        static int numProcessors;
        static HANDLE self;
#else
        static clock_t lastCPU, lastSysCPU, lastUserCPU;
        static int numProcessors;
		
        int getValue() const;
#endif
        void init() const;
        double getCurrentValue() const;
        int parseLine(char* line) const;

>>>>>>> master
    public:
        /**
         * @brief Gets the current memory usage in kilobytes.
         * 
         * @return unsigned int Amount of virtual memory used in kilobytes.
         */
<<<<<<< HEAD
=======
#if !defined(WIN32) or !defined(_WIN32)
>>>>>>> master
        unsigned int getMemoryUsage() const
        {
            return getValue();
        }
<<<<<<< HEAD
=======
#else
		unsigned int getMemoryUsage() const
		{
			return 0;
		}
#endif
>>>>>>> master

        double getCPUPercent() const
        {
            return getCurrentValue();
        }
    };
}