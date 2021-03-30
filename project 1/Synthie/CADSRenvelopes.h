#pragma once
#include "CAudioNode.h"
class CADSRenvelopes :
    public CAudioNode
{
public:
	CADSRenvelopes();
	~CADSRenvelopes();


	void SetSource(CAudioNode* const& source) { m_source = source; }
	void SetDuration(double d) { m_duration = d; }
	virtual void Start();
	virtual bool Generate();

private:
	double m_duration;
	double m_time;
	CAudioNode* m_source;
	double m_attack;
	double m_decay;
	double m_sustain;
	double m_release;
};

