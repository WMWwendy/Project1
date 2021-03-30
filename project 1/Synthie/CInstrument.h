#pragma once
#include "CAudioNode.h"
#include "CNote.h"

class CInstrument :
	public CAudioNode
{
public:
	CInstrument(void);
	virtual ~CInstrument(void);
	virtual void SetNote(CNote* note) = 0;
};


