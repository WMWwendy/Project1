#include "StdAfx.h"
#include "CAdditiveInstrument.h"
#include "Notes.h"
#include <sstream>

CAdditiveInstrument::CAdditiveInstrument(void)
{
	m_freq = 2400;
	m_duration = 0.1;

	m_attack = 0.05;
	m_release = 0.05;
	m_decay = 0.05;
	m_sustain = 0.05;

}



CAdditiveInstrument::~CAdditiveInstrument(void)
{
}

void CAdditiveInstrument::Start(void)
{
	m_sines.SetSampleRate(GetSampleRate());
	m_sines.Start();

	m_time = 0;
	m_adsr.SetSource(&m_sines);
	m_adsr.SetSampleRate(GetSampleRate());
	m_adsr.Start();

	// Tell the AR object it gets its samples from 
	// the sine wave object.

}


bool CAdditiveInstrument::Generate(void)
{

	m_sines.Generate();

	m_frame[0] = 0;
	m_frame[1] = 0;
	m_r1.resize(m_h1.size());
	m_r2.resize(m_h1.size());
	double pi = 3.1415926535897932384626433832795;
	for (int i = 0; i < GetSamplePeriod(); i++, m_time += GetSamplePeriod())
	{

		double f = m_freq * (0.2 * sin(m_r2[i]));
		m_r1[i] += (2 * pi * (m_freq + f) * (i + 1)) / GetSampleRate();
		m_r2[i] += (2 * pi * m_freq * (i + 1)) / GetSampleRate();


		if (i < m_h2.size())
		{
			m_frame[1] = m_frame[0] += ((1 - m_time / m_duration) * m_h1[i] / (i + 1) * sin(m_r1[i])) + ((m_time / m_duration) * m_h2[i] / (i + 1) * sin(m_r1[i]));
		}
		else if (i > m_h2.size())
		{
			m_frame[1] = m_frame[0] += m_h1[i] / (i + 1) * sin(m_r1[i]);
		}

	}

	double frame[2];
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

	m_frame[0] = Frame(0) * m_release;
	m_frame[1] = Frame(1) * m_release;

	m_time += GetSamplePeriod();

	// We return true until the time reaches the duration.
	return m_time < m_duration;
}




void CAdditiveInstrument::SetNote(CNote* note)
{
	// Get a list of all attribute nodes and the
   // length of that list
	CComPtr<IXMLDOMNamedNodeMap> attributes;
	note->Node()->get_attributes(&attributes);
	long len;
	attributes->get_length(&len);

	// Loop over the list of attributes
	for (int i = 0; i < len; i++)
	{
		// Get attribute i
		CComPtr<IXMLDOMNode> attrib;
		attributes->get_item(i, &attrib);

		// Get the name of the attribute
		CComBSTR name;
		attrib->get_nodeName(&name);

		// Get the value of the attribute.  A CComVariant is a variable
		// that can have any type. It loads the attribute value as a
		// string (UNICODE), but we can then change it to an integer 
		// (VT_I4) or double (VT_R8) using the ChangeType function 
		// and then read its integer or double value from a member variable.
		CComVariant value;
		attrib->get_nodeValue(&value);


		if (name == "duration")
		{
			value.ChangeType(VT_R8);
			SetDuration(value.dblVal);
		}
		else if (name == "note")
		{
			SetFreq(NoteToFrequency(value.bstrVal));
		}
		else if (name == "harmonic1")
		{

			wstringstream sstream(value.bstrVal);
			wstring harm;

			while (sstream >> harm)
			{
				m_h1.push_back(stod(harm));
			}

		}
		else if (name == "harmonic2")
		{

			wstringstream sstream(value.bstrVal);
			wstring harm;

			while (sstream >> harm)
			{
				m_h2.push_back(stod(harm));
			}
		}

	}
}