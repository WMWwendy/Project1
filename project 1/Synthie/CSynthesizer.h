#pragma once
#include "msxml2.h"
#include <list>
#include "CInstrument.h"
#pragma comment(lib, "msxml2.lib")
#include <string>
#include "CNote.h"
#include <vector>
#include "COddSinesFactory.h"
#include "CWaveInstrumentFactory.h"
#include "CAdditiveFactory.h"
#include "CEffect.h"
#include "CChorus.h"
#include "CFlanging.h"
#include "CNoiseGate.h"

using namespace std;

class CSynthesizer
{
public:
    CSynthesizer(void);
    virtual ~CSynthesizer(void);

    //! Number of audio channels
    int GetNumChannels() { return m_channels; }

    //! Sample rate in samples per second
    double GetSampleRate() { return m_sampleRate; }

    //! Sample period in seconds (1/samplerate)
    double GetSamplePeriod() { return m_samplePeriod; }

    //! Set the number of channels
    void SetNumChannels(int n) { m_channels = n; }

    //! Set the sample rate
    void SetSampleRate(double s) { m_sampleRate = s;  m_samplePeriod = 1.0 / s; }


    void Start(void);
    bool Generate(double* frame);

    //! Get the time since we started generating audio
    double GetTime() { return m_time; }

    void Clear(void);

    void OpenScore(CString& filename);


private:
    void XmlLoadScore(IXMLDOMNode* xml);
    void XmlLoadInstrument(IXMLDOMNode* xml);
    void XmlLoadNote(IXMLDOMNode* xml, std::wstring& instrument);
    void XmlLoadEffect(IXMLDOMNode* xml);

    int		m_channels;
    double	m_sampleRate;
    double	m_samplePeriod;
    double m_time;

    double  m_bpm;				//!< Beats per minute
    int     m_beatspermeasure;	//!< Beats per measure
    double  m_secperbeat;		//!< Seconds per beat

    std::list<CInstrument*>  m_instruments;
    std::vector<CNote> m_notes;

    int m_currentNote;          //!< The current note we are playing
    int m_measure;              //!< The current measure
    double m_beat;              //!< The current beat within the measure
    COddSinesFactory m_oddsinesfactory;
    CWaveInstrumentFactory m_waveinstfactory;
    CAdditiveFactory m_additivefactory;

    CEffect m_effect;
    CChorus m_ch;
    CNoiseGate m_nise;
    CFlanging m_fl;
    bool m_noisegating = false;
    bool m_flanging = false;
    bool m_chorus = false;
};

