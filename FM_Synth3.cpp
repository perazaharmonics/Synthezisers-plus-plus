/* ------------------------------------------------------------
name: "untitled"
Code generated with Faust 2.69.3 (https://faust.grame.fr)
Compilation options: -lang cpp -ct 1 -es 1 -mcd 16 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __mydsp_H__
#define  __mydsp_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <math.h>

#ifndef FAUSTCLASS 
#define FAUSTCLASS mydsp
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

#if defined(_WIN32)
#define RESTRICT __restrict
#else
#define RESTRICT __restrict__
#endif

class mydspSIG0 {
	
  private:
	
	int iVec1[2];
	int iRec4[2];
	
  public:
	
	int getNumInputsmydspSIG0() {
		return 0;
	}
	int getNumOutputsmydspSIG0() {
		return 1;
	}
	
	void instanceInitmydspSIG0(int sample_rate) {
		for (int l1 = 0; l1 < 2; l1 = l1 + 1) {
			iVec1[l1] = 0;
		}
		for (int l2 = 0; l2 < 2; l2 = l2 + 1) {
			iRec4[l2] = 0;
		}
	}
	
	void fillmydspSIG0(int count, float* table) {
		for (int i1 = 0; i1 < count; i1 = i1 + 1) {
			iVec1[0] = 1;
			iRec4[0] = (iVec1[1] + iRec4[1]) % 65536;
			table[i1] = std::sin(9.58738e-05f * float(iRec4[0]));
			iVec1[1] = iVec1[0];
			iRec4[1] = iRec4[0];
		}
	}

};

static mydspSIG0* newmydspSIG0() { return (mydspSIG0*)new mydspSIG0(); }
static void deletemydspSIG0(mydspSIG0* dsp) { delete dsp; }

static float ftbl0mydspSIG0[65536];

class mydsp : public dsp {
	
 private:
	
	int iVec0[2];
	int fSampleRate;
	float fConst1;
	float fConst2;
	FAUSTFLOAT fHslider0;
	float fConst3;
	float fRec7[2];
	FAUSTFLOAT fHslider1;
	float fRec6[2];
	FAUSTFLOAT fHslider2;
	float fRec5[2];
	FAUSTFLOAT fButton0;
	int IOTA0;
	float fVec2[1024];
	FAUSTFLOAT fHslider3;
	FAUSTFLOAT fHslider4;
	float fRec3[2];
	float fRec1[2];
	float fRec0[2];
	
 public:
	mydsp() {}

	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/tabulateNd", "Copyright (C) 2023 Bart Brouns <bart@magnetophon.nl>");
		m->declare("basics.lib/version", "1.11.1");
		m->declare("compile_options", "-lang cpp -ct 1 -es 1 -mcd 16 -single -ftz 0");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "1.1.0");
		m->declare("envelopes.lib/author", "GRAME");
		m->declare("envelopes.lib/copyright", "GRAME");
		m->declare("envelopes.lib/license", "LGPL with exception");
		m->declare("envelopes.lib/name", "Faust Envelope Library");
		m->declare("envelopes.lib/version", "1.3.0");
		m->declare("filename", "untitled.dsp");
		m->declare("filters.lib/lowpass0_highpass1", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/version", "1.3.0");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.7.0");
		m->declare("name", "untitled");
		m->declare("oscillators.lib/name", "Faust Oscillator Library");
		m->declare("oscillators.lib/version", "1.4.0");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("signals.lib/name", "Faust Signal Routing Library");
		m->declare("signals.lib/version", "1.5.0");
		m->declare("synths.lib/fm:author", "Romain Michon");
		m->declare("synths.lib/name", "Faust Synthesizer Library");
		m->declare("synths.lib/version", "1.1.0");
	}

	virtual int getNumInputs() {
		return 0;
	}
	virtual int getNumOutputs() {
		return 1;
	}
	
	static void classInit(int sample_rate) {
		mydspSIG0* sig0 = newmydspSIG0();
		sig0->instanceInitmydspSIG0(sample_rate);
		sig0->fillmydspSIG0(65536, ftbl0mydspSIG0);
		deletemydspSIG0(sig0);
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		float fConst0 = std::min<float>(1.92e+05f, std::max<float>(1.0f, float(fSampleRate)));
		fConst1 = 44.1f / fConst0;
		fConst2 = 1.0f - fConst1;
		fConst3 = 1.0f / fConst0;
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(34.0f);
		fHslider1 = FAUSTFLOAT(34.0f);
		fHslider2 = FAUSTFLOAT(88.0f);
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider3 = FAUSTFLOAT(1e+03f);
		fHslider4 = FAUSTFLOAT(1e+01f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = l0 + 1) {
			iVec0[l0] = 0;
		}
		for (int l3 = 0; l3 < 2; l3 = l3 + 1) {
			fRec7[l3] = 0.0f;
		}
		for (int l4 = 0; l4 < 2; l4 = l4 + 1) {
			fRec6[l4] = 0.0f;
		}
		for (int l5 = 0; l5 < 2; l5 = l5 + 1) {
			fRec5[l5] = 0.0f;
		}
		IOTA0 = 0;
		for (int l6 = 0; l6 < 1024; l6 = l6 + 1) {
			fVec2[l6] = 0.0f;
		}
		for (int l7 = 0; l7 < 2; l7 = l7 + 1) {
			fRec3[l7] = 0.0f;
		}
		for (int l8 = 0; l8 < 2; l8 = l8 + 1) {
			fRec1[l8] = 0.0f;
		}
		for (int l9 = 0; l9 < 2; l9 = l9 + 1) {
			fRec0[l9] = 0.0f;
		}
	}
	
	virtual void init(int sample_rate) {
		classInit(sample_rate);
		instanceInit(sample_rate);
	}
	
	virtual void instanceInit(int sample_rate) {
		instanceConstants(sample_rate);
		instanceResetUserInterface();
		instanceClear();
	}
	
	virtual mydsp* clone() {
		return new mydsp();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("untitled");
		ui_interface->declare(&fHslider4, "style", "knob");
		ui_interface->addHorizontalSlider("Fractional Delay Length", &fHslider4, FAUSTFLOAT(1e+01f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1e+03f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fHslider3, "style", "knob");
		ui_interface->addHorizontalSlider("Max Delay Length", &fHslider3, FAUSTFLOAT(1e+03f), FAUSTFLOAT(0.0f), FAUSTFLOAT(2e+04f), FAUSTFLOAT(0.01f));
		ui_interface->openHorizontalBox("Synth");
		ui_interface->declare(&fHslider2, "style", "knob");
		ui_interface->addHorizontalSlider("Carrier Freq", &fHslider2, FAUSTFLOAT(88.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(4e+02f), FAUSTFLOAT(0.0001f));
		ui_interface->declare(&fHslider1, "style", "knob");
		ui_interface->addHorizontalSlider("Message Freq 1", &fHslider1, FAUSTFLOAT(34.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1e+03f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fHslider0, "style", "knob");
		ui_interface->addHorizontalSlider("Message Freq 2", &fHslider0, FAUSTFLOAT(34.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(333.0f), FAUSTFLOAT(0.001f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->closeBox();
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = fConst3 * float(fHslider0);
		float fSlow1 = float(fHslider1);
		float fSlow2 = float(fHslider2);
		float fSlow3 = float(fButton0);
		float fSlow4 = 2.0f * fSlow3;
		float fSlow5 = float(fHslider3) + 1.0f;
		float fSlow6 = float(fHslider4);
		int iSlow7 = int(fSlow6);
		int iSlow8 = int(std::min<float>(fSlow5, float(std::max<int>(0, iSlow7))));
		float fSlow9 = std::floor(fSlow6);
		float fSlow10 = fSlow9 + (1.0f - fSlow6);
		int iSlow11 = int(std::min<float>(fSlow5, float(std::max<int>(0, iSlow7 + 1))));
		float fSlow12 = fSlow6 - fSlow9;
		for (int i0 = 0; i0 < count; i0 = i0 + 1) {
			iVec0[0] = 1;
			int iTemp0 = 1 - iVec0[1];
			float fTemp1 = ((iTemp0) ? 0.0f : fSlow0 + fRec7[1]);
			fRec7[0] = fTemp1 - std::floor(fTemp1);
			float fTemp2 = ((iTemp0) ? 0.0f : fRec6[1] + fConst3 * (fSlow1 + 3e+02f * ftbl0mydspSIG0[std::max<int>(0, std::min<int>(int(65536.0f * fRec7[0]), 65535))]));
			fRec6[0] = fTemp2 - std::floor(fTemp2);
			float fTemp3 = ((iTemp0) ? 0.0f : fRec5[1] + fConst3 * (fSlow2 + 2e+01f * ftbl0mydspSIG0[std::max<int>(0, std::min<int>(int(65536.0f * fRec6[0]), 65535))]));
			fRec5[0] = fTemp3 - std::floor(fTemp3);
			float fTemp4 = ftbl0mydspSIG0[std::max<int>(0, std::min<int>(int(65536.0f * fRec5[0]), 65535))];
			float fTemp5 = fSlow3 * fTemp4;
			fVec2[IOTA0 & 1023] = fTemp5;
			fRec3[0] = fSlow12 * fVec2[(IOTA0 - iSlow11) & 1023] + fSlow10 * fVec2[(IOTA0 - iSlow8) & 1023] + 0.44f * fRec3[1] + fSlow4 * fTemp4 - 0.3f * fRec1[1];
			fRec1[0] = fRec3[1];
			float fRec2 = 0.3f * fRec3[0];
			fRec0[0] = fConst1 * (0.6f * fRec1[1] + fRec2 + 0.44f * fRec1[0]) + fConst2 * fRec0[1];
			output0[i0] = FAUSTFLOAT(fRec0[0]);
			iVec0[1] = iVec0[0];
			fRec7[1] = fRec7[0];
			fRec6[1] = fRec6[0];
			fRec5[1] = fRec5[0];
			IOTA0 = IOTA0 + 1;
			fRec3[1] = fRec3[0];
			fRec1[1] = fRec1[0];
			fRec0[1] = fRec0[0];
		}
	}

};

#endif
