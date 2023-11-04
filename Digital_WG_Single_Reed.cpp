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
	int iRec10[2];
	
  public:
	
	int getNumInputsmydspSIG0() {
		return 0;
	}
	int getNumOutputsmydspSIG0() {
		return 1;
	}
	
	void instanceInitmydspSIG0(int sample_rate) {
		for (int l11 = 0; l11 < 2; l11 = l11 + 1) {
			iVec2[l11] = 0;
		}
		for (int l12 = 0; l12 < 2; l12 = l12 + 1) {
			iRec10[l12] = 0;
		}
	}
	
	void fillmydspSIG0(int count, float* table) {
		for (int i1 = 0; i1 < count; i1 = i1 + 1) {
			iVec2[0] = 1;
			iRec10[0] = (iVec2[1] + iRec10[1]) % 65536;
			table[i1] = std::sin(9.58738e-05f * float(iRec10[0]));
			iVec2[1] = iVec2[0];
			iRec10[1] = iRec10[0];
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
	FAUSTFLOAT fButton0;
	float fRec2[2];
	FAUSTFLOAT fButton1;
	float fRec3[2];
	FAUSTFLOAT fButton2;
	float fRec4[2];
	FAUSTFLOAT fButton3;
	float fRec5[2];
	FAUSTFLOAT fButton4;
	float fRec6[2];
	FAUSTFLOAT fButton5;
	float fRec7[2];
	FAUSTFLOAT fButton6;
	float fRec8[2];
	float fVec1[2];
	int iRec1[2];
	float fConst3;
	float fConst4;
	float fRec9[2];
	float fConst5;
	FAUSTFLOAT fHslider0;
	int IOTA0;
	float fConst6;
	float fRec11[2];
	float fConst7;
	float fRec12[2];
	float fConst8;
	float fRec13[2];
	float fConst9;
	float fRec14[2];
	float fConst10;
	float fRec15[2];
	float fConst11;
	float fRec16[2];
	float fConst12;
	float fRec17[2];
	float fRec0[65536];
	FAUSTFLOAT fHslider1;
	float fRec18[2];
	
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
		m->declare("filters.lib/lowpass0_highpass1", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/name", "Faust Filters Library");
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
		m->declare("signals.lib/name", "Faust Signal Routing Library");
		m->declare("signals.lib/version", "1.5.0");
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
		fConst3 = std::max<float>(1.0f, 0.01f * fConst0);
		fConst4 = 1.0f / fConst3;
		fConst5 = 1.0f / std::max<float>(1.0f, 0.05f * fConst0);
		fConst6 = 392.0f / fConst0;
		fConst7 = 349.23f / fConst0;
		fConst8 = 329.63f / fConst0;
		fConst9 = 293.66f / fConst0;
		fConst10 = 261.63f / fConst0;
		fConst11 = 247.5f / fConst0;
		fConst12 = 2.2e+02f / fConst0;
	}
	
	virtual void instanceResetUserInterface() {
		fButton0 = FAUSTFLOAT(0.0f);
		fButton1 = FAUSTFLOAT(0.0f);
		fButton2 = FAUSTFLOAT(0.0f);
		fButton3 = FAUSTFLOAT(0.0f);
		fButton4 = FAUSTFLOAT(0.0f);
		fButton5 = FAUSTFLOAT(0.0f);
		fButton6 = FAUSTFLOAT(0.0f);
		fHslider0 = FAUSTFLOAT(0.7f);
		fHslider1 = FAUSTFLOAT(0.5f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = l0 + 1) {
			iVec0[l0] = 0;
		}
		for (int l1 = 0; l1 < 2; l1 = l1 + 1) {
			fRec2[l1] = 0.0f;
		}
		for (int l2 = 0; l2 < 2; l2 = l2 + 1) {
			fRec3[l2] = 0.0f;
		}
		for (int l3 = 0; l3 < 2; l3 = l3 + 1) {
			fRec4[l3] = 0.0f;
		}
		for (int l4 = 0; l4 < 2; l4 = l4 + 1) {
			fRec5[l4] = 0.0f;
		}
		for (int l5 = 0; l5 < 2; l5 = l5 + 1) {
			fRec6[l5] = 0.0f;
		}
		for (int l6 = 0; l6 < 2; l6 = l6 + 1) {
			fRec7[l6] = 0.0f;
		}
		for (int l7 = 0; l7 < 2; l7 = l7 + 1) {
			fRec8[l7] = 0.0f;
		}
		for (int l8 = 0; l8 < 2; l8 = l8 + 1) {
			fVec1[l8] = 0.0f;
		}
		for (int l9 = 0; l9 < 2; l9 = l9 + 1) {
			iRec1[l9] = 0;
		}
		for (int l10 = 0; l10 < 2; l10 = l10 + 1) {
			fRec9[l10] = 0.0f;
		}
		IOTA0 = 0;
		for (int l13 = 0; l13 < 2; l13 = l13 + 1) {
			fRec11[l13] = 0.0f;
		}
		for (int l14 = 0; l14 < 2; l14 = l14 + 1) {
			fRec12[l14] = 0.0f;
		}
		for (int l15 = 0; l15 < 2; l15 = l15 + 1) {
			fRec13[l15] = 0.0f;
		}
		for (int l16 = 0; l16 < 2; l16 = l16 + 1) {
			fRec14[l16] = 0.0f;
		}
		for (int l17 = 0; l17 < 2; l17 = l17 + 1) {
			fRec15[l17] = 0.0f;
		}
		for (int l18 = 0; l18 < 2; l18 = l18 + 1) {
			fRec16[l18] = 0.0f;
		}
		for (int l19 = 0; l19 < 2; l19 = l19 + 1) {
			fRec17[l19] = 0.0f;
		}
		for (int l20 = 0; l20 < 65536; l20 = l20 + 1) {
			fRec0[l20] = 0.0f;
		}
		for (int l21 = 0; l21 < 2; l21 = l21 + 1) {
			fRec18[l21] = 0.0f;
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
		ui_interface->addButton("A4", &fButton1);
		ui_interface->addButton("B4", &fButton0);
		ui_interface->addButton("C4", &fButton2);
		ui_interface->addButton("D4", &fButton3);
		ui_interface->addButton("E4", &fButton4);
		ui_interface->addButton("F4", &fButton5);
		ui_interface->addButton("G4", &fButton6);
		ui_interface->declare(&fHslider1, "style", "knob");
		ui_interface->addHorizontalSlider("gain", &fHslider1, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.001f));
		ui_interface->addHorizontalSlider("reed_stiffness", &fHslider0, FAUSTFLOAT(0.7f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = fConst1 * float(fButton0);
		float fSlow1 = fConst1 * float(fButton1);
		float fSlow2 = fConst1 * float(fButton2);
		float fSlow3 = fConst1 * float(fButton3);
		float fSlow4 = fConst1 * float(fButton4);
		float fSlow5 = fConst1 * float(fButton5);
		float fSlow6 = fConst1 * float(fButton6);
		float fSlow7 = float(fHslider0);
		float fSlow8 = float(fHslider1);
		float fSlow9 = 0.7f * fSlow8;
		float fSlow10 = 0.3f * fSlow8;
		for (int i0 = 0; i0 < count; i0 = i0 + 1) {
			iVec0[0] = 1;
			fRec2[0] = fSlow0 + fConst2 * fRec2[1];
			float fTemp0 = fRec2[0] - fRec2[1];
			float fTemp1 = fTemp0 * float(fTemp0 > 0.0f);
			fRec3[0] = fSlow1 + fConst2 * fRec3[1];
			float fTemp2 = fRec3[0] - fRec3[1];
			float fTemp3 = fTemp2 * float(fTemp2 > 0.0f);
			fRec4[0] = fSlow2 + fConst2 * fRec4[1];
			float fTemp4 = fRec4[0] - fRec4[1];
			float fTemp5 = fTemp4 * float(fTemp4 > 0.0f);
			fRec5[0] = fSlow3 + fConst2 * fRec5[1];
			float fTemp6 = fRec5[0] - fRec5[1];
			float fTemp7 = fTemp6 * float(fTemp6 > 0.0f);
			fRec6[0] = fSlow4 + fConst2 * fRec6[1];
			float fTemp8 = fRec6[0] - fRec6[1];
			float fTemp9 = fTemp8 * float(fTemp8 > 0.0f);
			fRec7[0] = fSlow5 + fConst2 * fRec7[1];
			float fTemp10 = fRec7[0] - fRec7[1];
			float fTemp11 = fTemp10 * float(fTemp10 > 0.0f);
			fRec8[0] = fSlow6 + fConst2 * fRec8[1];
			float fTemp12 = fRec8[0] - fRec8[1];
			float fTemp13 = fTemp12 * float(fTemp12 > 0.0f);
			float fTemp14 = fTemp13 + fTemp11 + fTemp9 + fTemp7 + fTemp5 + fTemp3 + fTemp1;
			fVec1[0] = fTemp14;
			iRec1[0] = (iRec1[1] + 1) * (fTemp14 == 0.0f);
			fRec9[0] = fTemp14 + fRec9[1] * float(fVec1[1] >= fTemp14);
			int iTemp15 = 1 - iVec0[1];
			float fTemp16 = ((iTemp15) ? 0.0f : fConst6 + fRec11[1]);
			fRec11[0] = fTemp16 - std::floor(fTemp16);
			float fTemp17 = ((iTemp15) ? 0.0f : fConst7 + fRec12[1]);
			fRec12[0] = fTemp17 - std::floor(fTemp17);
			float fTemp18 = ((iTemp15) ? 0.0f : fConst8 + fRec13[1]);
			fRec13[0] = fTemp18 - std::floor(fTemp18);
			float fTemp19 = ((iTemp15) ? 0.0f : fConst9 + fRec14[1]);
			fRec14[0] = fTemp19 - std::floor(fTemp19);
			float fTemp20 = ((iTemp15) ? 0.0f : fConst10 + fRec15[1]);
			fRec15[0] = fTemp20 - std::floor(fTemp20);
			float fTemp21 = ((iTemp15) ? 0.0f : fConst11 + fRec16[1]);
			fRec16[0] = fTemp21 - std::floor(fTemp21);
			float fTemp22 = ((iTemp15) ? 0.0f : fConst12 + fRec17[1]);
			fRec17[0] = fTemp22 - std::floor(fTemp22);
			float fTemp23 = fTemp3 * ftbl0mydspSIG0[std::max<int>(0, std::min<int>(int(65536.0f * fRec17[0]), 65535))] + fTemp1 * ftbl0mydspSIG0[std::max<int>(0, std::min<int>(int(65536.0f * fRec16[0]), 65535))] + fTemp5 * ftbl0mydspSIG0[std::max<int>(0, std::min<int>(int(65536.0f * fRec15[0]), 65535))] + fTemp7 * ftbl0mydspSIG0[std::max<int>(0, std::min<int>(int(65536.0f * fRec14[0]), 65535))] + fTemp9 * ftbl0mydspSIG0[std::max<int>(0, std::min<int>(int(65536.0f * fRec13[0]), 65535))] + fTemp11 * ftbl0mydspSIG0[std::max<int>(0, std::min<int>(int(65536.0f * fRec12[0]), 65535))] + fTemp13 * ftbl0mydspSIG0[std::max<int>(0, std::min<int>(int(65536.0f * fRec11[0]), 65535))];
			int iTemp24 = int(4.41e+04f / std::max<float>(1.0f, fTemp23));
			float fTemp25 = fTemp23 + -1.499995f;
			int iTemp26 = int(fTemp25);
			float fTemp27 = std::floor(fTemp25);
			float fTemp28 = fTemp23 + (-3.0f - fTemp27);
			float fTemp29 = fTemp23 + (-2.0f - fTemp27);
			float fTemp30 = fTemp23 + (-1.0f - fTemp27);
			float fTemp31 = fTemp23 - fTemp27;
			float fTemp32 = fTemp31 * fTemp30;
			float fTemp33 = fTemp32 * fTemp29;
			fRec0[IOTA0 & 65535] = (fTemp23 + (-4.0f - fTemp27)) * (fTemp28 * (fTemp29 * (0.041666668f * fRec0[(IOTA0 - (std::min<int>(iTemp24, std::max<int>(0, iTemp26)) + 1)) & 65535] * fTemp30 - 0.16666667f * fTemp31 * fRec0[(IOTA0 - (std::min<int>(iTemp24, std::max<int>(0, iTemp26 + 1)) + 1)) & 65535]) + 0.25f * fTemp32 * fRec0[(IOTA0 - (std::min<int>(iTemp24, std::max<int>(0, iTemp26 + 2)) + 1)) & 65535]) - 0.16666667f * fTemp33 * fRec0[(IOTA0 - (std::min<int>(iTemp24, std::max<int>(0, iTemp26 + 3)) + 1)) & 65535]) + 0.041666668f * fTemp33 * fTemp28 * fRec0[(IOTA0 - (std::min<int>(iTemp24, std::max<int>(0, iTemp26 + 4)) + 1)) & 65535] + tanhf(fSlow7 * fTemp14 * std::max<float>(0.0f, std::min<float>(fConst4 * fRec9[0], std::max<float>(fConst5 * (fConst3 - fRec9[0]) + 1.0f, 0.0f)) * (1.0f - fConst4 * float(iRec1[0])))) + 0.7f;
			float fTemp34 = fRec0[IOTA0 & 65535];
			fRec18[0] = fRec18[1] + fSlow10 * fTemp34;
			output0[i0] = FAUSTFLOAT(fRec18[0] + fSlow9 * fTemp34);
			iVec0[1] = iVec0[0];
			fRec2[1] = fRec2[0];
			fRec3[1] = fRec3[0];
			fRec4[1] = fRec4[0];
			fRec5[1] = fRec5[0];
			fRec6[1] = fRec6[0];
			fRec7[1] = fRec7[0];
			fRec8[1] = fRec8[0];
			fVec1[1] = fVec1[0];
			iRec1[1] = iRec1[0];
			fRec9[1] = fRec9[0];
			IOTA0 = IOTA0 + 1;
			fRec11[1] = fRec11[0];
			fRec12[1] = fRec12[0];
			fRec13[1] = fRec13[0];
			fRec14[1] = fRec14[0];
			fRec15[1] = fRec15[0];
			fRec16[1] = fRec16[0];
			fRec17[1] = fRec17[0];
			fRec18[1] = fRec18[0];
		}
	}

};

#endif
