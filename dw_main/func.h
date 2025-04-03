#pragma once
#include <iostream>
#include <vector>
#include <Windows.h>
#include <string>
#include "TCHAR.h"
#include "pdh.h"
#include <cmath>

#ifdef _WIN32
#include <Lmcons.h>
#else
#include <unistd.h>
#include <pwd.h>
#include <sys/types.h>
#endif

static PDH_HQUERY cpuQuery;
static PDH_HCOUNTER cpuTotal;

void init() {
    PdhOpenQuery(NULL, NULL, &cpuQuery);
    PdhAddCounter(cpuQuery, L"\\Processor(_Total)\\% Processor Time", NULL, &cpuTotal);
    PdhCollectQueryData(cpuQuery);
}

double getCurrentValue() {
    PDH_FMT_COUNTERVALUE counterVal;

    PdhCollectQueryData(cpuQuery);
    PdhGetFormattedCounterValue(cpuTotal, PDH_FMT_DOUBLE, NULL, &counterVal);
    return counterVal.doubleValue;
}

#ifndef FUNC_H
#define FUNC_H

DWORD GetPointerAddress(HWND hwnd, DWORD address, std::vector<DWORD> offsets);
int getValueInt(HWND hwnd, DWORD address);
float getValueFloat(HWND hwnd, DWORD address);
void addrptrToValue(DWORD pmvar);
 
#endif // 주요 함수 정의 
 