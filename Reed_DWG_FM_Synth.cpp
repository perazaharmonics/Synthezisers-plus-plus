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

/* link with : "" */
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
	int iRec5[2];
	
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
			iRec5[l5] = 0;
		}
	}
	
	void fillmydspSIG0(int count, float* table) {
		for (int i1 = 0; i1 < count; i1 = i1 + 1) {
			iVec2[0] = 1;
			iRec5[0] = (iVec2[1] + iRec5[1]) % 65536;
			table[i1] = std::sin(9.58738e-05f * float(iRec5[0]));
			iVec2[1] = iVec2[0];
			iRec5[1] = iRec5[0];
		}
	}

};

static mydspSIG0* newmydspSIG0() { return (mydspSIG0*)new mydspSIG0(); }
static void deletemydspSIG0(mydspSIG0* dsp) { delete dsp; }

static float mydsp_faustpower2_f(float value) {
	return value * value;
}
static float ftbl0mydspSIG0[65536];

class mydsp : public dsp {
	
 private:
	
	int iVec0[2];
	FAUSTFLOAT fHslider0;
	int fSampleRate;
	float fConst1;
	FAUSTFLOAT fHslider1;
	FAUSTFLOAT fButton0;
	float fVec1[2];
	int iRec3[2];
	float fConst2;
	float fConst3;
	float fRec4[2];
	float fConst4;
	FAUSTFLOAT fHslider2;
	FAUSTFLOAT fHslider3;
	float fConst5;
	float fRec7[2];
	FAUSTFLOAT fHslider4;
	int iRec8[2];
	FAUSTFLOAT fHslider5;
	float fRec6[2];
	float fRec2[6];
	FAUSTFLOAT fHslider6;
	float fVec3[2];
	float fRec1[2];
	float fRec0[3];
	
 public:
	mydsp() {}

	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/tabulateNd", "Copyright (C) 2023 Bart Brouns <bart@magnetophon.nl>");
		m->declare("basics.lib/version", "1.11.1");
		m->declare("compile_options", "-lang cpp -ct 1 -es 1 -mcd 16 -single -ftz 0");
		m->declare("delays.lib/fdelay4:author", "Julius O. Smith III");
		m->declare("delays.lib/fdelayltv:author", "Julius O. Smith III");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "1.1.0");
		m->declare("envelopes.lib/adsr:author", "Yann Orlarey and Andrey Bundin");
		m->declare("envelopes.lib/author", "GRAME");
		m->declare("envelopes.lib/copyright", "GRAME");
		m->declare("envelopes.lib/license", "LGPL with exception");
		m->declare("envelopes.lib/name", "Faust Envelope Library");
		m->declare("envelopes.lib/version", "1.3.0");
		m->declare("filename", "untitled.dsp");
		m->declare("filters.lib/fir:author", "Julius O. Smith III");
		m->declare("filters.lib/fir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/fir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/highpass:author", "Julius O. Smith III");
		m->declare("filters.lib/highpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/iir:author", "Julius O. Smith III");
		m->declare("filters.lib/iir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/iir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/lowpass0_highpass1", "MIT-style STK-4.3 license");
		m->declare("filters.lib/lowpass0_highpass1:author", "Julius O. Smith III");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/tf1:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf1s:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1s:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1s:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf2:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf2s:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2s:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2s:license", "MIT-style STK-4.3 license");
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
		fConst1 = 3.1415927f / fConst0;
		fConst2 = std::max<float>(1.0f, 0.01f * fConst0);
		fConst3 = 1.0f / fConst2;
		fConst4 = 1.0f / std::max<float>(1.0f, 0.05f * fConst0);
		fConst5 = 1.0f / fConst0;
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(4e+02f);
		fHslider1 = FAUSTFLOAT(0.0f);
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider2 = FAUSTFLOAT(0.7f);
		fHslider3 = FAUSTFLOAT(2.2e+02f);
		fHslider4 = FAUSTFLOAT(0.0f);
		fHslider5 = FAUSTFLOAT(4.4e+02f);
		fHslider6 = FAUSTFLOAT(0.5f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = l0 + 1) {
			iVec0[l0] = 0;
		}
		for (int l1 = 0; l1 < 2; l1 = l1 + 1) {
			fVec1[l1] = 0.0f;
		}
		for (int l2 = 0; l2 < 2; l2 = l2 + 1) {
			iRec3[l2] = 0;
		}
		for (int l3 = 0; l3 < 2; l3 = l3 + 1) {
			fRec4[l3] = 0.0f;
		}
		for (int l6 = 0; l6 < 2; l6 = l6 + 1) {
			fRec7[l6] = 0.0f;
		}
		for (int l7 = 0; l7 < 2; l7 = l7 + 1) {
			iRec8[l7] = 0;
		}
		for (int l8 = 0; l8 < 2; l8 = l8 + 1) {
			fRec6[l8] = 0.0f;
		}
		for (int l9 = 0; l9 < 6; l9 = l9 + 1) {
			fRec2[l9] = 0.0f;
		}
		for (int l10 = 0; l10 < 2; l10 = l10 + 1) {
			fVec3[l10] = 0.0f;
		}
		for (int l11 = 0; l11 < 2; l11 = l11 + 1) {
			fRec1[l11] = 0.0f;
		}
		for (int l12 = 0; l12 < 3; l12 = l12 + 1) {
			fRec0[l12] = 0.0f;
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
		ui_interface->addHorizontalSlider("carrierFreq", &fHslider5, FAUSTFLOAT(4.4e+02f), FAUSTFLOAT(2e+01f), FAUSTFLOAT(2e+04f), FAUSTFLOAT(1.0f));
		ui_interface->addHorizontalSlider("embouchure_offset", &fHslider1, FAUSTFLOAT(0.0f), FAUSTFLOAT(-1.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider6, "style", "knob");
		ui_interface->addHorizontalSlider("gain", &fHslider6, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.001f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("lowfreq", &fHslider0, FAUSTFLOAT(4e+02f), FAUSTFLOAT(2e+01f), FAUSTFLOAT(2e+04f), FAUSTFLOAT(1.0f));
		ui_interface->addHorizontalSlider("modulatorFreq", &fHslider3, FAUSTFLOAT(2.2e+02f), FAUSTFLOAT(2e+01f), FAUSTFLOAT(2e+04f), FAUSTFLOAT(1.0f));
		ui_interface->addHorizontalSlider("reed_stiffness", &fHslider2, FAUSTFLOAT(0.7f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->addHorizontalSlider("wave_position", &fHslider4, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.001f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = std::tan(fConst1 * float(fHslider0));
		float fSlow1 = mydsp_faustpower2_f(fSlow0);
		float fSlow2 = 2.0f * (1.0f - 1.0f / fSlow1);
		float fSlow3 = 1.0f / fSlow0;
		float fSlow4 = (fSlow3 + -1.0f) / fSlow0 + 1.0f;
		float fSlow5 = (fSlow3 + 1.0f) / fSlow0 + 1.0f;
		float fSlow6 = 1.0f / fSlow5;
		float fSlow7 = float(fHslider1);
		float fSlow8 = float(fButton0);
		int iSlow9 = fSlow8 == 0.0f;
		float fSlow10 = float(fHslider2);
		float fSlow11 = fConst5 * float(fHslider3);
		int iSlow12 = int(4095.0f * float(fHslider4) + -1.0f);
		float fSlow13 = float(fHslider5);
		float fSlow14 = float(fHslider6);
		float fSlow15 = 1.0f - fSlow3;
		float fSlow16 = 1.0f / (fSlow3 + 1.0f);
		float fSlow17 = 1.0f / (fSlow1 * fSlow5);
		for (int i0 = 0; i0 < count; i0 = i0 + 1) {
			iVec0[0] = 1;
			fVec1[0] = fSlow8;
			iRec3[0] = iSlow9 * (iRec3[1] + 1);
			fRec4[0] = fSlow8 + fRec4[1] * float(fVec1[1] >= fSlow8);
			int iTemp0 = 1 - iVec0[1];
			float fTemp1 = ((iTemp0) ? 0.0f : fSlow11 + fRec7[1]);
			fRec7[0] = fTemp1 - std::floor(fTemp1);
			iRec8[0] = (iRec8[1] + 1) & iSlow12;
			float fTemp2 = ((iTemp0) ? 0.0f : fRec6[1] + fConst5 * (fSlow13 + float(iRec8[0]) * ftbl0mydspSIG0[std::max<int>(0, std::min<int>(int(65536.0f * fRec7[0]), 65535))]));
			fRec6[0] = fTemp2 - std::floor(fTemp2);
			float fTemp3 = ftbl0mydspSIG0[std::max<int>(0, std::min<int>(int(65536.0f * fRec6[0]), 65535))];
			int iTemp4 = int(4.41e+04f / std::max<float>(1.0f, fTemp3));
			float fTemp5 = fTemp3 + -1.499995f;
			int iTemp6 = int(fTemp5);
			float fTemp7 = std::floor(fTemp5);
			float fTemp8 = fTemp3 + (-3.0f - fTemp7);
			float fTemp9 = fTemp3 + (-2.0f - fTemp7);
			float fTemp10 = fTemp3 + (-1.0f - fTemp7);
			float fTemp11 = fTemp3 - fTemp7;
			float fTemp12 = fTemp11 * fTemp10;
			float fTemp13 = fTemp12 * fTemp9;
			fRec2[0] = (fTemp3 + (-4.0f - fTemp7)) * (fTemp8 * (fTemp9 * (0.041666668f * fRec2[std::min<int>(iTemp4, std::max<int>(0, iTemp6)) + 1] * fTemp10 - 0.16666667f * fTemp11 * fRec2[std::min<int>(iTemp4, std::max<int>(0, iTemp6 + 1)) + 1]) + 0.25f * fTemp12 * fRec2[std::min<int>(iTemp4, std::max<int>(0, iTemp6 + 2)) + 1]) - 0.16666667f * fTemp13 * fRec2[std::min<int>(iTemp4, std::max<int>(0, iTemp6 + 3)) + 1]) + 0.041666668f * fTemp13 * fTemp8 * fRec2[std::min<int>(iTemp4, std::max<int>(0, iTemp6 + 4)) + 1] + tanhf(fSlow10 * (fSlow8 * std::max<float>(0.0f, std::min<float>(fConst3 * fRec4[0], std::max<float>(fConst4 * (fConst2 - fRec4[0]) + 1.0f, 0.0f)) * (1.0f - fConst3 * float(iRec3[0]))) - fSlow7)) + 0.3f;
			float fTemp14 = fSlow14 * fRec2[0];
			fVec3[0] = fTemp14;
			fRec1[0] = -(fSlow16 * (fSlow15 * fRec1[1] - fSlow3 * (fTemp14 - fVec3[1])));
			fRec0[0] = fRec1[0] - fSlow6 * (fSlow4 * fRec0[2] + fSlow2 * fRec0[1]);
			output0[i0] = FAUSTFLOAT(fSlow17 * (fRec0[0] + fRec0[2] - 2.0f * fRec0[1]));
			iVec0[1] = iVec0[0];
			fVec1[1] = fVec1[0];
			iRec3[1] = iRec3[0];
			fRec4[1] = fRec4[0];
			fRec7[1] = fRec7[0];
			iRec8[1] = iRec8[0];
			fRec6[1] = fRec6[0];
			for (int j0 = 5; j0 > 0; j0 = j0 - 1) {
				fRec2[j0] = fRec2[j0 - 1];
			}
			fVec3[1] = fVec3[0];
			fRec1[1] = fRec1[0];
			fRec0[2] = fRec0[1];
			fRec0[1] = fRec0[0];
		}
	}

};

#endif
