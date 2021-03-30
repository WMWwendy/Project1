#pragma once
#include "CEffect.h"
class CNoiseGate :
	public CEffect
{
public:
	CNoiseGate();
	virtual ~CNoiseGate();
	void Process(double* frameIn, double* frameOut);

};

