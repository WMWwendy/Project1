#include "stdafx.h"
#include "CADSRenvelopes.h"

CADSRenvelopes::CADSRenvelopes()
{
	m_duration = 0.1;
	m_attack = 0.05;
	m_release = 0.05;
	m_decay = 0.05;
	m_sustain = 0.05;

}


CADSRenvelopes::~CADSRenvelopes()
{
}

void CADSRenvelopes::Start()
{
	m_source->SetSampleRate(GetSampleRate());
	m_source->Start();
	m_time = 0;
}

bool CADSRenvelopes::Generate()
{
	// Tell the component to generate an audio sample
	m_source->Generate();

	if (m_time < m_attack)
	{
		m_release = m_time / m_attack;
	}
	else if ((m_time > m_attack) && (m_time < m_duration - m_release - m_sustain))
	{
		m_release = (m_duration - m_time - m_sustain) / (m_release + m_decay);

	}
	else if (m_time > m_duration - m_release)
	{
		m_release = (m_duration - m_time) / (m_release + m_decay);
	}
	else
	{
		m_release = 1;

	}

	m_frame[0] = m_source->Frame(0) * m_release;
	m_frame[1] = m_source->Frame(1) * m_release;
	// Update time
	m_time += GetSamplePeriod();

	// We return true until the time reaches the duration.
	return m_time < m_duration;
}
