// England, Devin   CS230 Spring 2026 #10989
// Completed: March 3, 2026
// Environment: Visual Studio 2022 Community Edition

#include <iostream>
#include <ctime>
#include <intrin.h>

int primeCount, lastPrime;

int main()
{
    clock_t startTime, endTime;
    time_t time1, time2;
    int i = 0, j = 0, primeLimit = 0;
    bool isPrime = true;

    std::cout << "Student last name: England" << std::endl << std::endl;

    do {
        std::cout << "Enter prime number limit:";
        std::cin >> primeLimit;
        std::cout << std::endl;
    } while (primeLimit < 1);

    startTime = clock();
    time1 = time(NULL);

    primeCount = 0;
    lastPrime = 2;

    unsigned int auxLoopStart = 0, auxLoopEnd = 0;
    __int64 loopStartCycles = __rdtscp(&auxLoopStart);

    bool firstPrimeFound = false;
    int firstPrimeNumber = -1;
    __int64 firstPrimeCycles = 0;
    unsigned int firstPrimeAuxStart = 0;

    int lastPrimeNumberMeasured = -1;
    __int64 lastPrimeCycles = 0;
    unsigned int lastPrimeAuxStart = 0;

    const int MAX_CHANGES = 2000;
    int firstAuxMsgs[MAX_CHANGES];
    int firstAuxMsgCount = 0;

    int lastAuxMsgs[MAX_CHANGES];
    int lastAuxMsgCount = 0;

    int myCount = 0, myLast = 2;
    for (i = 2; i < primeLimit; i++) {

        unsigned int auxStart = 0, auxEnd = 0;
        __int64 startCycles = __rdtscp(&auxStart);

        unsigned int lastAux12 = (auxStart & 0xFFF);
        int auxMsgsThisI[MAX_CHANGES];
        int auxMsgCountThisI = 0;

        isPrime = true;

        for (j = 2; j < i; j++) {
            if (i % j == 0) {
                isPrime = false;
                break;
            }

            unsigned int auxNow = 0;
            __rdtscp(&auxNow);
            unsigned int aux12 = (auxNow & 0xFFF);

            if (aux12 != lastAux12) {
                if (auxMsgCountThisI < MAX_CHANGES) {
                    auxMsgsThisI[auxMsgCountThisI] = (int)aux12;
                    auxMsgCountThisI++;
                }
                lastAux12 = aux12;
            }
        }

        __int64 endCycles = __rdtscp(&auxEnd);
        __int64 deltaCycles = endCycles - startCycles;

        if (isPrime) {
            primeCount++;
            lastPrime = i;

            if (!firstPrimeFound) {
                firstPrimeFound = true;
                firstPrimeNumber = i;
                firstPrimeCycles = deltaCycles;
                firstPrimeAuxStart = (auxStart & 0xFFF);

                firstAuxMsgCount = auxMsgCountThisI;
                for (int k = 0; k < firstAuxMsgCount; k++)
                    firstAuxMsgs[k] = auxMsgsThisI[k];
            }

            lastPrimeNumberMeasured = i;
            lastPrimeCycles = deltaCycles;
            lastPrimeAuxStart = (auxStart & 0xFFF);

            lastAuxMsgCount = auxMsgCountThisI;
            for (int k = 0; k < lastAuxMsgCount; k++)
                lastAuxMsgs[k] = auxMsgsThisI[k];
        }
    }

    __int64 loopEndCycles = __rdtscp(&auxLoopEnd);
    __int64 totalLoopCycles = loopEndCycles - loopStartCycles;

    endTime = clock();
    clock_t timeUsed = endTime - startTime;
    float fCPUtime = (timeUsed * 1.0f) / CLOCKS_PER_SEC;
    time2 = time(NULL);

    std::cout << "... ended, " << primeCount << " primes, highest was " << lastPrime << std::endl;
    std::cout << "Clock ticks:" << timeUsed << '\n';
    std::cout << "CPU Time : " << fCPUtime << '\n';
    std::cout << "Elapsed time:" << difftime(time2, time1) << " seconds\n\n";
    std::cout << "Total loop cycles: " << totalLoopCycles << "\n\n";

    if (firstPrimeFound) {
        std::cout << "First prime check cycles (" << firstPrimeNumber << "): " << firstPrimeCycles << "\n";
        std::cout << "IA23_TSC_AUX: " << (firstPrimeAuxStart & 0xFFF) << " for number: " << firstPrimeNumber << "\n";
        for (int k = 0; k < firstAuxMsgCount; k++) {
            std::cout << "IA23_TSC_AUX: " << (firstAuxMsgs[k] & 0xFFF) << " for number: " << firstPrimeNumber << "\n";
        }
        std::cout << "\n";
    }

    if (lastPrimeNumberMeasured != -1) {
        std::cout << "Last prime check cycles (" << lastPrimeNumberMeasured << "): " << lastPrimeCycles << "\n";
        std::cout << "IA23_TSC_AUX: " << (lastPrimeAuxStart & 0xFFF) << " for number: " << lastPrimeNumberMeasured << "\n";
        for (int k = 0; k < lastAuxMsgCount; k++) {
            std::cout << "IA23_TSC_AUX: " << (lastAuxMsgs[k] & 0xFFF) << " for number: " << lastPrimeNumberMeasured << "\n";
        }
        std::cout << "\n";
    }
    return 0;
}