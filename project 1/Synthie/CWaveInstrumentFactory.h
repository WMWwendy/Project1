#pragma once
#include "CWaveInstrument.h"
#include <vector>

class CWaveInstrumentFactory
{
public:
    CWaveInstrumentFactory(void);
    ~CWaveInstrumentFactory(void);

    void SetNote(CNote* note);
    CWaveInstrument* CreateInstrument();
    bool LoadFile(const char* filename);

private:
    std::vector<short> m_wave;
};