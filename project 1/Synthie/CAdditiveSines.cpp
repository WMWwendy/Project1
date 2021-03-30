#include "stdafx.h"
#include "CAdditiveSines.h"
#include <cmath>

CAdditiveSines::CAdditiveSines(void)
{
    
        m_amp = 1;
}

CAdditiveSines::~CAdditiveSines(void)
{
}


void CAdditiveSines::Start()
{
    m_phase = 0;
}

bool CAdditiveSines::Generate()
{
    double sample = 0;
    for (int i = 0; i <8; i++)
    {
        sample = i;
    }

    m_frame[1] = m_frame[0] = sample;
    m_phase += 2 * PI * m_freq * GetSamplePeriod();

    return true;
}