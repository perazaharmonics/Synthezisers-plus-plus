/* ------------------------------------------------------------
name: "untitled"
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
	
	int iVec0[2];
	int iRec0[2];
	
  public:
	
	int getNumInputsmydspSIG0() {
		return 0;
	}
	int getNumOutputsmydspSIG0() {
		return 1;
	}
	
	void instanceInitmydspSIG0(int sample_rate) {
		for (int l0 = 0; l0 < 2; l0 = l0 + 1) {
			iVec0[l0] = 0;
		}
		for (int l1 = 0; l1 < 2; l1 = l1 + 1) {
			iRec0[l1] = 0;
		}
	}
	
	void fillmydspSIG0(int count, float* table) {
		for (int i1 = 0; i1 < count; i1 = i1 + 1) {
			iVec0[0] = 1;
			iRec0[0] = (iVec0[1] + iRec0[1]) % 65536;
			table[i1] = std::sin(9.58738e-05f * float(iRec0[0]));
			iVec0[1] = iVec0[0];
			iRec0[1] = iRec0[0];
		}
	}

};

static mydspSIG0* newmydspSIG0() { return (mydspSIG0*)new mydspSIG0(); }
static void deletemydspSIG0(mydspSIG0* dsp) { delete dsp; }

static float ftbl0mydspSIG0[65536];
static float mydsp_faustpower2_f(float value) {
	return value * value;
}

class mydsp : public dsp {
	
 private:
	
	int iVec1[2];
	FAUSTFLOAT fHslider0;
	int fSampleRate;
	float fConst0;
	float fConst1;
	float fRec1[2];
	float fConst2;
	float fRec2[2];
	float fConst3;
	float fRec3[2];
	float fConst4;
	float fRec4[2];
	float fConst5;
	float fRec5[2];
	float fConst6;
	float fRec6[2];
	float fConst7;
	float fRec7[2];
	FAUSTFLOAT fButton0;
	float fVec2[2];
	int iRec8[2];
	FAUSTFLOAT fHslider1;
	float fRec9[2];
	FAUSTFLOAT fHslider2;
	FAUSTFLOAT fHslider3;
	FAUSTFLOAT fHslider4;
	int IOTA0;
	float fVec3[128];
	FAUSTFLOAT fHslider5;
	float fConst8;
	float fRec11[2];
	FAUSTFLOAT fHslider6;
	FAUSTFLOAT fHslider7;
	float fRec12[2];
	FAUSTFLOAT fHslider8;
	float fVec4[16384];
	float fConst9;
	float fVec5[2];
	FAUSTFLOAT fHslider9;
	float fConst10;
	float fRec10[2];
	FAUSTFLOAT fHslider10;
	float fRec13[2];
	FAUSTFLOAT fHslider11;
	FAUSTFLOAT fHslider12;
	float fRec14[2];
	FAUSTFLOAT fHslider13;
	int iConst11;
	
 public:
	mydsp() {}

	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/tabulateNd", "Copyright (C) 2023 Bart Brouns <bart@magnetophon.nl>");
		m->declare("basics.lib/version", "1.11.1");
		m->declare("compile_options", "-lang cpp -ct 1 -es 1 -mcd 16 -single -ftz 0");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "1.1.0");
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
	}

	virtual int getNumInputs() {
		return 0;
	}
	virtual int getNumOutputs() {
		return 2;
	}
	
	static void classInit(int sample_rate) {
		mydspSIG0* sig0 = newmydspSIG0();
		sig0->instanceInitmydspSIG0(sample_rate);
		sig0->fillmydspSIG0(65536, ftbl0mydspSIG0);
		deletemydspSIG0(sig0);
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = std::min<float>(1.92e+05f, std::max<float>(1.0f, float(fSampleRate)));
		fConst1 = 392.0f / fConst0;
		fConst2 = 349.23f / fConst0;
		fConst3 = 329.63f / fConst0;
		fConst4 = 293.66f / fConst0;
		fConst5 = 261.63f / fConst0;
		fConst6 = 493.88f / fConst0;
		fConst7 = 4.4e+02f / fConst0;
		fConst8 = 1.0f / fConst0;
		fConst9 = fConst0 + 1.0f;
		fConst10 = 3.1415927f / fConst0;
		iConst11 = int(0.001f * mydsp_faustpower2_f(fConst0)) + 1;
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(0.0f);
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider1 = FAUSTFLOAT(0.5f);
		fHslider2 = FAUSTFLOAT(0.01f);
		fHslider3 = FAUSTFLOAT(0.1f);
		fHslider4 = FAUSTFLOAT(0.7f);
		fHslider5 = FAUSTFLOAT(1.0f);
		fHslider6 = FAUSTFLOAT(1.0f);
		fHslider7 = FAUSTFLOAT(4.4e+02f);
		fHslider8 = FAUSTFLOAT(0.5f);
		fHslider9 = FAUSTFLOAT(1e+03f);
		fHslider10 = FAUSTFLOAT(5e+03f);
		fHslider11 = FAUSTFLOAT(15.0f);
		fHslider12 = FAUSTFLOAT(1.5f);
		fHslider13 = FAUSTFLOAT(2.0f);
	}
	
	virtual void instanceClear() {
		for (int l2 = 0; l2 < 2; l2 = l2 + 1) {
			iVec1[l2] = 0;
		}
		for (int l3 = 0; l3 < 2; l3 = l3 + 1) {
			fRec1[l3] = 0.0f;
		}
		for (int l4 = 0; l4 < 2; l4 = l4 + 1) {
			fRec2[l4] = 0.0f;
		}
		for (int l5 = 0; l5 < 2; l5 = l5 + 1) {
			fRec3[l5] = 0.0f;
		}
		for (int l6 = 0; l6 < 2; l6 = l6 + 1) {
			fRec4[l6] = 0.0f;
		}
		for (int l7 = 0; l7 < 2; l7 = l7 + 1) {
			fRec5[l7] = 0.0f;
		}
		for (int l8 = 0; l8 < 2; l8 = l8 + 1) {
			fRec6[l8] = 0.0f;
		}
		for (int l9 = 0; l9 < 2; l9 = l9 + 1) {
			fRec7[l9] = 0.0f;
		}
		for (int l10 = 0; l10 < 2; l10 = l10 + 1) {
			fVec2[l10] = 0.0f;
		}
		for (int l11 = 0; l11 < 2; l11 = l11 + 1) {
			iRec8[l11] = 0;
		}
		for (int l12 = 0; l12 < 2; l12 = l12 + 1) {
			fRec9[l12] = 0.0f;
		}
		IOTA0 = 0;
		for (int l13 = 0; l13 < 128; l13 = l13 + 1) {
			fVec3[l13] = 0.0f;
		}
		for (int l14 = 0; l14 < 2; l14 = l14 + 1) {
			fRec11[l14] = 0.0f;
		}
		for (int l15 = 0; l15 < 2; l15 = l15 + 1) {
			fRec12[l15] = 0.0f;
		}
		for (int l16 = 0; l16 < 16384; l16 = l16 + 1) {
			fVec4[l16] = 0.0f;
		}
		for (int l17 = 0; l17 < 2; l17 = l17 + 1) {
			fVec5[l17] = 0.0f;
		}
		for (int l18 = 0; l18 < 2; l18 = l18 + 1) {
			fRec10[l18] = 0.0f;
		}
		for (int l19 = 0; l19 < 2; l19 = l19 + 1) {
			fRec13[l19] = 0.0f;
		}
		for (int l20 = 0; l20 < 2; l20 = l20 + 1) {
			fRec14[l20] = 0.0f;
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
		ui_interface->declare(&fHslider2, "0", "1");
		ui_interface->addHorizontalSlider("Attack", &fHslider2, FAUSTFLOAT(0.01f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider11, "ms", "");
		ui_interface->addHorizontalSlider("Chorus Delay Time", &fHslider11, FAUSTFLOAT(15.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(5e+01f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fHslider13, "ms", "");
		ui_interface->addHorizontalSlider("Chorus Depth", &fHslider13, FAUSTFLOAT(2.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(2e+01f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fHslider12, "Hz", "");
		ui_interface->addHorizontalSlider("Chorus Rate", &fHslider12, FAUSTFLOAT(1.5f), FAUSTFLOAT(0.1f), FAUSTFLOAT(5.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider3, "0", "1");
		ui_interface->addHorizontalSlider("Decay", &fHslider3, FAUSTFLOAT(0.1f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider0, "-3", "3");
		ui_interface->addHorizontalSlider("Octave", &fHslider0, FAUSTFLOAT(0.0f), FAUSTFLOAT(-3.0f), FAUSTFLOAT(3.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider1, "0", "1");
		ui_interface->addHorizontalSlider("Release", &fHslider1, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider4, "0", "1");
		ui_interface->addHorizontalSlider("Sustain", &fHslider4, FAUSTFLOAT(0.7f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider7, "0", "");
		ui_interface->declare(&fHslider7, "Carrier Frequency", "");
		ui_interface->addHorizontalSlider("carrierFreq", &fHslider7, FAUSTFLOAT(4.4e+02f), FAUSTFLOAT(2e+01f), FAUSTFLOAT(2e+04f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider10, "0", "");
		ui_interface->declare(&fHslider10, "Reflection Lowpass Cutoff", "");
		ui_interface->addHorizontalSlider("reflection_cutoff", &fHslider10, FAUSTFLOAT(5e+03f), FAUSTFLOAT(2e+01f), FAUSTFLOAT(1e+04f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider5, "1", "");
		ui_interface->declare(&fHslider5, "Modulator Frequency", "");
		ui_interface->addHorizontalSlider("modulatorFreq", &fHslider5, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.1f), FAUSTFLOAT(2e+01f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fHslider9, "1", "");
		ui_interface->declare(&fHslider9, "Radiation highpass Cutoff", "");
		ui_interface->addHorizontalSlider("radiation_cutoff", &fHslider9, FAUSTFLOAT(1e+03f), FAUSTFLOAT(2e+01f), FAUSTFLOAT(5e+03f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider6, "2", "");
		ui_interface->declare(&fHslider6, "Modulation Index", "");
		ui_interface->addHorizontalSlider("modulationIndex", &fHslider6, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1e+01f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fHslider8, "style", "knob");
		ui_interface->addHorizontalSlider("gain", &fHslider8, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.001f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		float fSlow0 = float(int(std::pow(float(2), float(int(float(fHslider0))))));
		float fSlow1 = fConst1 * fSlow0;
		float fSlow2 = fConst2 * fSlow0;
		float fSlow3 = fConst3 * fSlow0;
		float fSlow4 = fConst4 * fSlow0;
		float fSlow5 = fConst5 * fSlow0;
		float fSlow6 = fConst6 * fSlow0;
		float fSlow7 = fConst7 * fSlow0;
		float fSlow8 = float(fButton0);
		int iSlow9 = fSlow8 == 0.0f;
		float fSlow10 = 1.0f / std::max<float>(1.0f, fConst0 * float(fHslider1));
		float fSlow11 = std::max<float>(1.0f, fConst0 * float(fHslider2));
		float fSlow12 = 1.0f / fSlow11;
		float fSlow13 = float(fHslider4);
		float fSlow14 = (1.0f - fSlow13) / std::max<float>(1.0f, fConst0 * float(fHslider3));
		float fSlow15 = fConst8 * float(fHslider5);
		float fSlow16 = float(fHslider6);
		float fSlow17 = float(fHslider7);
		float fSlow18 = fConst8 * fSlow17;
		float fSlow19 = float(fHslider8);
		int iSlow20 = int(fConst0 / fSlow17);
		int iSlow21 = int(std::min<float>(fConst9, float(std::max<int>(0, iSlow20 + 1))));
		float fSlow22 = float(iSlow20);
		float fSlow23 = std::floor(fSlow22);
		float fSlow24 = fSlow22 - fSlow23;
		int iSlow25 = int(std::min<float>(fConst9, float(std::max<int>(0, iSlow20))));
		float fSlow26 = fSlow23 + (1.0f - fSlow22);
		float fSlow27 = 1.0f / std::tan(fConst10 * float(fHslider9));
		float fSlow28 = 1.0f - fSlow27;
		float fSlow29 = 1.0f / (fSlow27 + 1.0f);
		float fSlow30 = 1.0f / std::tan(fConst10 * float(fHslider10));
		float fSlow31 = 1.0f - fSlow30;
		float fSlow32 = 1.0f / (fSlow30 + 1.0f);
		float fSlow33 = float(fHslider11);
		float fSlow34 = fConst8 * float(fHslider12);
		float fSlow35 = 0.5f * float(fHslider13);
		for (int i0 = 0; i0 < count; i0 = i0 + 1) {
			iVec1[0] = 1;
			int iTemp0 = 1 - iVec1[1];
			float fTemp1 = ((iTemp0) ? 0.0f : fSlow1 + fRec1[1]);
			fRec1[0] = fTemp1 - std::floor(fTemp1);
			float fTemp2 = ((iTemp0) ? 0.0f : fSlow2 + fRec2[1]);
			fRec2[0] = fTemp2 - std::floor(fTemp2);
			float fTemp3 = ((iTemp0) ? 0.0f : fSlow3 + fRec3[1]);
			fRec3[0] = fTemp3 - std::floor(fTemp3);
			float fTemp4 = ((iTemp0) ? 0.0f : fSlow4 + fRec4[1]);
			fRec4[0] = fTemp4 - std::floor(fTemp4);
			float fTemp5 = ((iTemp0) ? 0.0f : fSlow5 + fRec5[1]);
			fRec5[0] = fTemp5 - std::floor(fTemp5);
			float fTemp6 = ((iTemp0) ? 0.0f : fSlow6 + fRec6[1]);
			fRec6[0] = fTemp6 - std::floor(fTemp6);
			float fTemp7 = ((iTemp0) ? 0.0f : fSlow7 + fRec7[1]);
			fRec7[0] = fTemp7 - std::floor(fTemp7);
			fVec2[0] = fSlow8;
			iRec8[0] = iSlow9 * (iRec8[1] + 1);
			fRec9[0] = fSlow8 + fRec9[1] * float(fVec2[1] >= fSlow8);
			float fTemp8 = std::max<float>(0.0f, std::min<float>(fSlow12 * fRec9[0], std::max<float>(fSlow14 * (fSlow11 - fRec9[0]) + 1.0f, fSlow13)) * (1.0f - fSlow10 * float(iRec8[0])));
			float fTemp9 = fTemp8 * (ftbl0mydspSIG0[std::max<int>(0, std::min<int>(int(65536.0f * fRec7[0]), 65535))] + ftbl0mydspSIG0[std::max<int>(0, std::min<int>(int(65536.0f * fRec6[0]), 65535))] + ftbl0mydspSIG0[std::max<int>(0, std::min<int>(int(65536.0f * fRec5[0]), 65535))] + ftbl0mydspSIG0[std::max<int>(0, std::min<int>(int(65536.0f * fRec4[0]), 65535))] + ftbl0mydspSIG0[std::max<int>(0, std::min<int>(int(65536.0f * fRec3[0]), 65535))] + ftbl0mydspSIG0[std::max<int>(0, std::min<int>(int(65536.0f * fRec2[0]), 65535))] + ftbl0mydspSIG0[std::max<int>(0, std::min<int>(int(65536.0f * fRec1[0]), 65535))]);
			fVec3[IOTA0 & 127] = fTemp9;
			float fTemp10 = ((iTemp0) ? 0.0f : fSlow15 + fRec11[1]);
			fRec11[0] = fTemp10 - std::floor(fTemp10);
			float fTemp11 = ((iTemp0) ? 0.0f : fSlow18 + fRec12[1]);
			fRec12[0] = fTemp11 - std::floor(fTemp11);
			float fTemp12 = fSlow19 * fTemp8 * ftbl0mydspSIG0[std::max<int>(0, std::min<int>(int(65536.0f * fRec12[0]), 65535))] * (fSlow16 * ftbl0mydspSIG0[std::max<int>(0, std::min<int>(int(65536.0f * fRec11[0]), 65535))] + 1.0f);
			fVec4[IOTA0 & 16383] = fTemp12;
			float fTemp13 = fSlow26 * fVec4[(IOTA0 - iSlow25) & 16383] + fSlow24 * fVec4[(IOTA0 - iSlow21) & 16383];
			fVec5[0] = fTemp13;
			fRec10[0] = -(fSlow29 * (fSlow28 * fRec10[1] - fSlow27 * (fTemp13 - fVec5[1])));
			fRec13[0] = -(fSlow32 * (fSlow31 * fRec13[1] - (fTemp13 + fVec5[1])));
			float fTemp14 = ((iTemp0) ? 0.0f : fSlow34 + fRec14[1]);
			fRec14[0] = fTemp14 - std::floor(fTemp14);
			float fTemp15 = fSlow35 * (ftbl0mydspSIG0[std::max<int>(0, std::min<int>(int(65536.0f * fRec14[0]), 65535))] + 1.0f);
			float fTemp16 = fSlow33 + fTemp15;
			float fTemp17 = std::floor(fTemp16);
			int iTemp18 = int(fTemp16);
			float fTemp19 = 0.5f * ((fSlow33 + (fTemp15 - fTemp17)) * fVec3[(IOTA0 - std::min<int>(iConst11, std::max<int>(0, iTemp18 + 1))) & 127] + fVec3[(IOTA0 - std::min<int>(iConst11, std::max<int>(0, iTemp18))) & 127] * (fTemp17 + (1.0f - fTemp15) - fSlow33) + fRec13[0] + fRec10[0] + fTemp9);
			output0[i0] = FAUSTFLOAT(fTemp19);
			output1[i0] = FAUSTFLOAT(fTemp19);
			iVec1[1] = iVec1[0];
			fRec1[1] = fRec1[0];
			fRec2[1] = fRec2[0];
			fRec3[1] = fRec3[0];
			fRec4[1] = fRec4[0];
			fRec5[1] = fRec5[0];
			fRec6[1] = fRec6[0];
			fRec7[1] = fRec7[0];
			fVec2[1] = fVec2[0];
			iRec8[1] = iRec8[0];
			fRec9[1] = fRec9[0];
			IOTA0 = IOTA0 + 1;
			fRec11[1] = fRec11[0];
			fRec12[1] = fRec12[0];
			fVec5[1] = fVec5[0];
			fRec10[1] = fRec10[0];
			fRec13[1] = fRec13[0];
			fRec14[1] = fRec14[0];
		}
	}

};

#endif
