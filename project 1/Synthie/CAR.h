#pragma once
#include "CAudioNode.h"
class CAR :
    public CAudioNode
{
public:
    CAR(void);
    virtual ~CAR(void);
    
    virtual void Start();
    virtual bool Generate();
    
    void SetDuration(double d) { m_duration = d; }
    void SetSource(CAudioNode *s) { m_source = s; }
    void SetAttack(double a) { m_attack = a; }
    void SetRelease(double r) { m_release = r; }

private:
    double m_attack;
    double m_release;
    double m_duration;
    double m_time;
    CAudioNode *m_source;
};

