#pragma once
#include "CInstrument.h"
#include "CWavePlayer.h"

class CWaveInstrument :
    public CInstrument
{
public:
    CWaveInstrument(void);
    ~CWaveInstrument(void);

    virtual void Start();
    virtual bool Generate();
    virtual void SetNote(CNote* note);

    CWavePlayer* GetPlayer() { return &m_wavePlayer; }

private:
    CWavePlayer m_wavePlayer;
};

