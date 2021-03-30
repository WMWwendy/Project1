#include "stdafx.h"
#include "CEffect.h"

CEffect::CEffect(void)
{
	m_wrloc = 0;
	m_rdloc = 0;
}

CEffect::~CEffect(void)
{
}

void CEffect::Process(double* frameIn, double* frameOut)
{

	// Loop over the channels
	for (int c = 0; c < 2; c++)
	{
		m_queue[m_wrloc + c] = frameIn[c];

		// Add output of the queue to the current input
		frameOut[c] = frameIn[c] + m_queue[m_rdloc + c];
	}

}