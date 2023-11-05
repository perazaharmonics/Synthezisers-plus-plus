/* ------------------------------------------------------------
name: "untitled", "Josué E. Peraza, B.Sc, M. EngEe"
Code generated with Faust 2.69.0 (https://faust.grame.fr)
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
	
	int iVec2[2];
	int iRec3[2];
	
  public:
	
	int getNumInputsmydspSIG0() {
		return 0;
	}
	int getNumOutputsmydspSIG0() {
		return 1;
	}
	
	void instanceInitmydspSIG0(int sample_rate) {
		for (int l4 = 0; l4 < 2; l4 = l4 + 1) {
			iVec2[l4] = 0;
		}
		for (int l5 = 0; l5 < 2; l5 = l5 + 1) {
			iRec3[l5] = 0;
		}
	}
	
	void fillmydspSIG0(int count, float* table) {
		for (int i1 = 0; i1 < count; i1 = i1 + 1) {
			iVec2[0] = 1;
			iRec3[0] = (iVec2[1] + iRec3[1]) % 65536;
			table[i1] = std::sin(9.58738e-05f * float(iRec3[0]));
			iVec2[1] = iVec2[0];
			iRec3[1] = iRec3[0];
		}
	}

};

static mydspSIG0* newmydspSIG0() { return (mydspSIG0*)new mydspSIG0(); }
static void deletemydspSIG0(mydspSIG0* dsp) { delete dsp; }

static float ftbl0mydspSIG0[65536];

class mydsp : public dsp {
	
 private:
	
	int iVec0[2];
	FAUSTFLOAT fButton0;
	float fVec1[2];
	int iRec1[2];
	int fSampleRate;
	float fConst1;
	float fConst2;
	float fRec2[2];
	float fConst3;
	FAUSTFLOAT fHslider0;
	float fConst4;
	float fRec4[2];
	FAUSTFLOAT fHslider1;
	FAUSTFLOAT fHslider2;
	float fRec5[2];
	FAUSTFLOAT fHslider3;
	int IOTA0;
	float fVec3[4096];
	float fVec4[2];
	FAUSTFLOAT fHslider4;
	float fConst5;
	float fRec0[2];
	FAUSTFLOAT fHslider5;
	float fRec6[2];
	
 public:
	mydsp() {}

	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/tabulateNd", "Copyright (C) 2023 Bart Brouns <bart@magnetophon.nl>");
		m->declare("basics.lib/version", "1.11.1");
		m->declare("compile_options", "-lang cpp -ct 1 -es 1 -mcd 16 -single -ftz 0");
		m->declare("envelopes.lib/adsr:author", "Yann Orlarey and Andrey Bundin");
		m->declare("envelopes.lib/author", "GRAME");
		m->declare("envelopes.lib/copyright", "GRAME");
		m->declare("envelopes.lib/license", "LGPL with exception");
		m->declare("envelopes.lib/name", "Faust Envelope Library");
		m->declare("envelopes.lib/version", "1.3.0");
		m->declare("filename", "untitled.dsp");
		m->declare("filters.lib/highpass:author", "Julius O. Smith III");
		m->declare("filters.lib/highpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/lowpass0_highpass1", "MIT-style STK-4.3 license");
		m->declare("filters.lib/lowpass0_highpass1:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/lowpass:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/tf1:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf1s:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1s:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1s:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/version", "1.3.0");
		m->declare("math.lib/author", "GRAME");
		m->declare("math.lib/copyright", "GRAME");
		m->declare("math.lib/deprecated", "This library is deprecated and is not maintained anymore. It will be removed in August 2017.");
		m->declare("math.lib/license", "LGPL with exception");
		m->declare("math.lib/name", "Math Library");
		m->declare("math.lib/version", "1.0");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.7.0");
		m->declare("music.lib/author", "GRAME");
		m->declare("music.lib/copyright", "GRAME");
		m->declare("music.lib/deprecated", "This library is deprecated and is not maintained anymore. It will be removed in August 2017.");
		m->declare("music.lib/license", "LGPL with exception");
		m->declare("music.lib/name", "Music Library");
		m->declare("music.lib/version", "1.0");
		m->declare("name", "untitled");
		m->declare("oscillators.lib/name", "Faust Oscillator Library");
		m->declare("oscillators.lib/version", "1.4.0");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
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
		fConst1 = std::max<float>(1.0f, 0.01f * fConst0);
		fConst2 = 1.0f / fConst1;
		fConst3 = 1.0f / std::max<float>(1.0f, 0.05f * fConst0);
		fConst4 = 1.0f / fConst0;
		fConst5 = 3.1415927f / fConst0;
	}
	
	virtual void instanceResetUserInterface() {
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider0 = FAUSTFLOAT(1.0f);
		fHslider1 = FAUSTFLOAT(1.0f);
		fHslider2 = FAUSTFLOAT(4.4e+02f);
		fHslider3 = FAUSTFLOAT(0.5f);
		fHslider4 = FAUSTFLOAT(1e+03f);
		fHslider5 = FAUSTFLOAT(5e+03f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = l0 + 1) {
			iVec0[l0] = 0;
		}
		for (int l1 = 0; l1 < 2; l1 = l1 + 1) {
			fVec1[l1] = 0.0f;
		}
		for (int l2 = 0; l2 < 2; l2 = l2 + 1) {
			iRec1[l2] = 0;
		}
		for (int l3 = 0; l3 < 2; l3 = l3 + 1) {
			fRec2[l3] = 0.0f;
		}
		for (int l6 = 0; l6 < 2; l6 = l6 + 1) {
			fRec4[l6] = 0.0f;
		}
		for (int l7 = 0; l7 < 2; l7 = l7 + 1) {
			fRec5[l7] = 0.0f;
		}
		IOTA0 = 0;
		for (int l8 = 0; l8 < 4096; l8 = l8 + 1) {
			fVec3[l8] = 0.0f;
		}
		for (int l9 = 0; l9 < 2; l9 = l9 + 1) {
			fVec4[l9] = 0.0f;
		}
		for (int l10 = 0; l10 < 2; l10 = l10 + 1) {
			fRec0[l10] = 0.0f;
		}
		for (int l11 = 0; l11 < 2; l11 = l11 + 1) {
			fRec6[l11] = 0.0f;
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
		ui_interface->declare(&fHslider2, "0", "");
		ui_interface->declare(&fHslider2, "Carrier Frequency", "");
		ui_interface->addHorizontalSlider("carrierFreq", &fHslider2, FAUSTFLOAT(4.4e+02f), FAUSTFLOAT(2e+01f), FAUSTFLOAT(2e+04f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider5, "0", "");
		ui_interface->declare(&fHslider5, "Reflection Lowpass Cutoff", "");
		ui_interface->addHorizontalSlider("reflection_cutoff", &fHslider5, FAUSTFLOAT(5e+03f), FAUSTFLOAT(2e+01f), FAUSTFLOAT(1e+04f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider0, "1", "");
		ui_interface->declare(&fHslider0, "Modulator Frequency", "");
		ui_interface->addHorizontalSlider("modulatorFreq", &fHslider0, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.1f), FAUSTFLOAT(2e+01f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fHslider4, "1", "");
		ui_interface->declare(&fHslider4, "Radiation highpass Cutoff", "");
		ui_interface->addHorizontalSlider("radiation_cutoff", &fHslider4, FAUSTFLOAT(1e+03f), FAUSTFLOAT(2e+01f), FAUSTFLOAT(5e+03f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider1, "2", "");
		ui_interface->declare(&fHslider1, "Modulation Index", "");
		ui_interface->addHorizontalSlider("modulationIndex", &fHslider1, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1e+01f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fHslider3, "style", "knob");
		ui_interface->addHorizontalSlider("gain", &fHslider3, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.001f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = float(fButton0);
		int iSlow1 = fSlow0 == 0.0f;
		float fSlow2 = fConst4 * float(fHslider0);
		float fSlow3 = float(fHslider1);
		float fSlow4 = float(fHslider2);
		float fSlow5 = fConst4 * fSlow4;
		float fSlow6 = float(fHslider3);
		int iSlow7 = int(4.41e+04f / fSlow4) & 44099;
		float fSlow8 = 1.0f / std::tan(fConst5 * float(fHslider4));
		float fSlow9 = 1.0f - fSlow8;
		float fSlow10 = 1.0f / (fSlow8 + 1.0f);
		float fSlow11 = 1.0f / std::tan(fConst5 * float(fHslider5));
		float fSlow12 = 1.0f - fSlow11;
		float fSlow13 = 1.0f / (fSlow11 + 1.0f);
		for (int i0 = 0; i0 < count; i0 = i0 + 1) {
			iVec0[0] = 1;
			fVec1[0] = fSlow0;
			iRec1[0] = iSlow1 * (iRec1[1] + 1);
			fRec2[0] = fSlow0 + fRec2[1] * float(fVec1[1] >= fSlow0);
			int iTemp0 = 1 - iVec0[1];
			float fTemp1 = ((iTemp0) ? 0.0f : fSlow2 + fRec4[1]);
			fRec4[0] = fTemp1 - std::floor(fTemp1);
			float fTemp2 = ((iTemp0) ? 0.0f : fSlow5 + fRec5[1]);
			fRec5[0] = fTemp2 - std::floor(fTemp2);
			fVec3[IOTA0 & 4095] = fSlow6 * ftbl0mydspSIG0[std::max<int>(0, std::min<int>(int(65536.0f * fRec5[0]), 65535))] * (fSlow3 * ftbl0mydspSIG0[std::max<int>(0, std::min<int>(int(65536.0f * fRec4[0]), 65535))] + 1.0f) * std::max<float>(0.0f, std::min<float>(fConst2 * fRec2[0], std::max<float>(fConst3 * (fConst1 - fRec2[0]) + 1.0f, 0.0f)) * (1.0f - fConst2 * float(iRec1[0])));
			float fTemp3 = fVec3[(IOTA0 - iSlow7) & 4095];
			fVec4[0] = fTemp3;
			fRec0[0] = -(fSlow10 * (fSlow9 * fRec0[1] - fSlow8 * (fTemp3 - fVec4[1])));
			fRec6[0] = -(fSlow13 * (fSlow12 * fRec6[1] - (fTemp3 + fVec4[1])));
			output0[i0] = FAUSTFLOAT(fRec6[0] + fRec0[0]);
			iVec0[1] = iVec0[0];
			fVec1[1] = fVec1[0];
			iRec1[1] = iRec1[0];
			fRec2[1] = fRec2[0];
			fRec4[1] = fRec4[0];
			fRec5[1] = fRec5[0];
			IOTA0 = IOTA0 + 1;
			fVec4[1] = fVec4[0];
			fRec0[1] = fRec0[0];
			fRec6[1] = fRec6[0];
		}
	}

};

#endif
