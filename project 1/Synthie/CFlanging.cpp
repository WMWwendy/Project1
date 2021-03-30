#include "stdafx.h"
#include "CFlanging.h"

CFlanging::CFlanging(void)
{
	m_wrloc = 0;
	m_rdloc = 0;
}

CFlanging::~CFlanging(void)
{
}

void CFlanging::Process(double* frameIn, double* frameOut)
{
	const int QUEUESIZE = 200000;

	for (int c = 0; c < 2; c++)
	{
		m_queue[(m_wrloc + 1) % QUEUESIZE] = frameIn[c];
	}

	m_rdloc = (m_rdloc + QUEUESIZE) % QUEUESIZE;

	for (int i = 0; i < 2; i++)
	{
		frameOut[i] = frameIn[i] / 3 + m_queue[m_rdloc] / 3;
	}

}
