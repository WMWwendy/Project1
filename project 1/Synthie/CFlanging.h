#pragma once
#include "CEffect.h"
class CFlanging :
	public CEffect
{

public:
	CFlanging();
	virtual ~CFlanging();
	void Process(double* frameIn, double* frameOut);

private:
	std::vector<short> m_queue;
	int m_wrloc;
	int m_rdloc;
};
