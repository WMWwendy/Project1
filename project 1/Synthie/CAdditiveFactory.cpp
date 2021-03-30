#include "stdafx.h"
#include "CAdditiveFactory.h"
#include <cmath>
#include "audio/DirSoundSource.h"
#include "CAdditiveInstrument.h"

CAdditiveFactory::CAdditiveFactory()
{
    for (double time = 0; time < 2; time += 1. / 44100.)
    {
        m_wave.push_back(short(3267 * sin(2 * 3.1415 * 1000 * time)));
    }
}

CAdditiveFactory::~CAdditiveFactory()
{
}

CAdditiveInstrument* CAdditiveFactory::CreateInstrument()
{
    CAdditiveInstrument* instrument = new CAdditiveInstrument();
    return instrument;
}


void CAdditiveFactory::SetNote(CNote* note)
{
    // Get a list of all attribute nodes and the
    // length of that list
    CComPtr<IXMLDOMNamedNodeMap> attributes;
    note->Node()->get_attributes(&attributes);
    long len;
    attributes->get_length(&len);

    // Loop over the list of attributes
    for (int i = 0; i < len; i++)
    {
        // Get attribute i
        CComPtr<IXMLDOMNode> attrib;
        attributes->get_item(i, &attrib);

        // Get the name of the attribute
        CComBSTR name;
        attrib->get_nodeName(&name);

        CComVariant value;
        attrib->get_nodeValue(&value);

    }

}
