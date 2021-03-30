#pragma once
#include "CInstrument.h"
#include "CAR.h"
#include "CAdditiveSines.h"
#include <vector>
#include "CADSRenvelopes.h"


class CAdditiveInstrument :
	public CInstrument
{
public:
	CAdditiveInstrument(void);
	~CAdditiveInstrument(void);

	virtual void Start();
	virtual bool Generate();

	void SetNote(CNote* note);
	void SetFreq(double freq) { m_freq = freq; }


	void SetDuration(double dur) { m_duration = dur; }
	double GetDuration() { return m_duration; }

	void SetTime(double time) { m_time = time; }
	double GetTime() { return m_time; }




private:

	CADSRenvelopes m_adsr;
	CAdditiveSines   m_sines;
	double m_duration;
	double m_time;
	double m_freq;


	std::vector<double> m_h1;
	std::vector<double> m_h2;

	std::vector<double> m_r1;
	std::vector<double> m_r2;

	double m_attack;
	double m_decay;
	double m_sustain;
	double m_release;


};

