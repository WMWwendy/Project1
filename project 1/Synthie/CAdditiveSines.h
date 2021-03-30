#pragma once
#include "CAudioNode.h"
#include <vector>
using namespace std;

class CAdditiveSines :
    public CAudioNode
{

public:
    CAdditiveSines(void);
    ~CAdditiveSines(void);

public:
    virtual void Start();
    virtual bool Generate();

    void SetFreq(double f) { m_freq = f; }
    void SetAmplitude(int i, double a) { m_amp = a; }


private:
    double m_freq;
    double m_phase;
    double m_amp;
    double m_duration;
    double m_time;
    
};

