#pragma once
#include "CAdditiveInstrument.h"


class CAdditiveFactory
{
public:
	CAdditiveFactory();
	~CAdditiveFactory();

	CAdditiveInstrument* CreateInstrument();
	void SetNote(CNote* note);
	bool LoadFile(const char* filename);

	

private:
	std::vector<short> m_wave;
	vector<double> m_harm;
};

