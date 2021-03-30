#include "stdafx.h"
#include "CAR.h"

CAR::CAR(void)
{
    m_attack = 0.05;
    m_release = 0.05;
	m_duration = 0.1;
}

CAR::~CAR(void)
{
}

void CAR::Start()
{
	SetSource(m_source);
	m_source->SetSampleRate(GetSampleRate());
	m_source->Start();
	m_time = 0;



}

bool CAR::Generate()
{

	for (int i = 0; i < GetSamplePeriod(); i++, m_time += GetSamplePeriod())
	{
		// Tell the component to generate an audio sample
		m_source->Generate();
		
		if (m_time < m_attack)
		{
			m_release = m_time / m_attack;
		}
		else if (m_time > m_duration - m_release)
		{
			m_release = (m_duration - m_time) / m_release;
		}
		else
		{
			m_release = 1;
		}
		m_frame[0] = m_source->Frame(0) * m_release;
		m_frame[1] = m_source->Frame(1) * m_release;

	}
    

    // We return true until the time reaches the duration.
    return m_time < m_duration;


}