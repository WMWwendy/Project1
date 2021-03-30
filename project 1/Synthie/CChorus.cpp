#include "stdafx.h"
#include "CChorus.h"

CChorus::CChorus(void)
{
	m_wrloc = 0;
	m_rdloc = 0;
}

CChorus::~CChorus(void)
{
}

void CChorus::Process(double* frameIn, double* frameOut)
{
	const int QUEUESIZE = 200000;


	for (int c = 0; c < 2; c++)
	{
		m_queue[(m_wrloc + c) % QUEUESIZE] = frameIn[c];

	}
	m_rdloc = (m_rdloc + 2) % QUEUESIZE;
	for (int i = 0; i < 2; i++)
	{
		frameOut[i] = frameIn[i] / 2 + m_queue[m_rdloc] / 2;

	}

}