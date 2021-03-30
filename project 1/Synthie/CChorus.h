#pragma once
#include "CEffect.h"
#include <vector>
class CChorus :
	public CEffect
{
public:
	CChorus();
	virtual ~CChorus();
	void Process(double* frameIn, double* frameOut);

private:
	std::vector<short> m_queue;
	int m_wrloc;
	int m_rdloc;
};

