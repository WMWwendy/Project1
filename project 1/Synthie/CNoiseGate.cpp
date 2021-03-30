#include "stdafx.h"
#include "CNoiseGate.h"

CNoiseGate::CNoiseGate(void)
{
}

CNoiseGate::~CNoiseGate(void)
{
}

void CNoiseGate::Process(double* frameIn, double* frameOut)
{
	for (int c = 0; c < 2; c++)
	{

		if (frameIn[c] < 0.0)
		{
			frameOut[c] = frameIn[c] * 2;
		}
		else if (frameIn[c] < 0.001)
		{
			frameOut[c] = 0;
		}
		else if (frameIn[c] > 0.005)
		{
			frameOut[c] = frameIn[c] / 2;
		}
		else
		{
			frameOut[c] = frameIn[c];
		}
	}
}