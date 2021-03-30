#pragma once
#include <vector>
using namespace::std;
class CEffect
{
public:
	CEffect();
	virtual ~CEffect();
	void Process(double* frameIn, double* frameOut);

private:

	std::vector<short> m_queue;
	int m_wrloc;
	int m_rdloc;
};
