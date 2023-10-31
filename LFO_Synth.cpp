/* ------------------------------------------------------------
name: "untitled"
Code generated with Faust 2.68.1 (https://faust.grame.fr)
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
			iVec1[l4] = 0;
		}
		for (int l5 = 0; l5 < 2; l5 = l5 + 1) {
			iRec3[l5] = 0;
		}
	}
	
	void fillmydspSIG0(int count, float* table) {
		for (int i1 = 0; i1 < count; i1 = i1 + 1) {
			iVec1[0] = 1;
			iRec3[0] = (iVec1[1] + iRec3[1]) % 65536;
			table[i1] = std::sin(9.58738e-05f * float(iRec3[0]));
			iVec1[1] = iVec1[0];
			iRec3[1] = iRec3[0];
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
	
	int iVec0[2];
	int fSampleRate;
	float fConst1;
	float fConst2;
	FAUSTFLOAT fHslider0;
	float fRec0[2];
	FAUSTFLOAT fHslider1;
	FAUSTFLOAT fHslider2;
	float fRec1[2];
	FAUSTFLOAT fButton0;
	FAUSTFLOAT fHslider3;
	float fRec2[2];
	FAUSTFLOAT fHslider4;
	float fConst3;
	float fRec4[2];
	FAUSTFLOAT fButton1;
	float fConst4;
	float fRec5[2];
	FAUSTFLOAT fButton2;
	float fConst5;
	float fRec6[2];
	FAUSTFLOAT fButton3;
	float fConst6;
	float fRec7[2];
	FAUSTFLOAT fButton4;
	float fConst7;
	float fRec8[2];
	FAUSTFLOAT fButton5;
	float fConst8;
	float fRec9[2];
	FAUSTFLOAT fButton6;
	float fConst9;
	float fRec10[2];
	int IOTA0;
	float fVec2[16384];
	FAUSTFLOAT fHslider5;
	float fConst10;
	float fRec11[2];
	FAUSTFLOAT fHslider6;
	FAUSTFLOAT fHslider7;
	float fConst11;
	
 public:
	mydsp() {}

	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/tabulateNd", "Copyright (C) 2023 Bart Brouns <bart@magnetophon.nl>");
		m->declare("basics.lib/version", "1.11.1");
		m->declare("compile_options", "-lang cpp -ct 1 -es 1 -mcd 16 -single -ftz 0");
		m->declare("filename", "untitled.dsp");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.6.0");
		m->declare("name", "untitled");
		m->declare("oscillators.lib/name", "Faust Oscillator Library");
		m->declare("oscillators.lib/version", "1.4.0");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("signals.lib/name", "Faust Signal Routing Library");
		m->declare("signals.lib/version", "1.3.0");
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
		float fConst0 = std::min<float>(1.92e+05f, std::max<float>(1.0f, float(fSampleRate)));
		fConst1 = 44.1f / fConst0;
		fConst2 = 1.0f - fConst1;
		fConst3 = 392.0f / fConst0;
		fConst4 = 349.23f / fConst0;
		fConst5 = 329.63f / fConst0;
		fConst6 = 293.66f / fConst0;
		fConst7 = 261.63f / fConst0;
		fConst8 = 493.88f / fConst0;
		fConst9 = 4.4e+02f / fConst0;
		fConst10 = 1.0f / fConst0;
		fConst11 = 0.001f * fConst0;
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(0.1f);
		fHslider1 = FAUSTFLOAT(0.7f);
		fHslider2 = FAUSTFLOAT(0.01f);
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider3 = FAUSTFLOAT(0.5f);
		fHslider4 = FAUSTFLOAT(0.0f);
		fButton1 = FAUSTFLOAT(0.0f);
		fButton2 = FAUSTFLOAT(0.0f);
		fButton3 = FAUSTFLOAT(0.0f);
		fButton4 = FAUSTFLOAT(0.0f);
		fButton5 = FAUSTFLOAT(0.0f);
		fButton6 = FAUSTFLOAT(0.0f);
		fHslider5 = FAUSTFLOAT(1.5f);
		fHslider6 = FAUSTFLOAT(2.0f);
		fHslider7 = FAUSTFLOAT(15.0f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = l0 + 1) {
			iVec0[l0] = 0;
		}
		for (int l1 = 0; l1 < 2; l1 = l1 + 1) {
			fRec0[l1] = 0.0f;
		}
		for (int l2 = 0; l2 < 2; l2 = l2 + 1) {
			fRec1[l2] = 0.0f;
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
		for (int l8 = 0; l8 < 2; l8 = l8 + 1) {
			fRec6[l8] = 0.0f;
		}
		for (int l9 = 0; l9 < 2; l9 = l9 + 1) {
			fRec7[l9] = 0.0f;
		}
		for (int l10 = 0; l10 < 2; l10 = l10 + 1) {
			fRec8[l10] = 0.0f;
		}
		for (int l11 = 0; l11 < 2; l11 = l11 + 1) {
			fRec9[l11] = 0.0f;
		}
		for (int l12 = 0; l12 < 2; l12 = l12 + 1) {
			fRec10[l12] = 0.0f;
		}
		IOTA0 = 0;
		for (int l13 = 0; l13 < 16384; l13 = l13 + 1) {
			fVec2[l13] = 0.0f;
		}
		for (int l14 = 0; l14 < 2; l14 = l14 + 1) {
			fRec11[l14] = 0.0f;
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
		ui_interface->declare(&fHslider7, "ms", "");
		ui_interface->addHorizontalSlider("Chorus Delay Time", &fHslider7, FAUSTFLOAT(15.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(5e+01f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fHslider6, "ms", "");
		ui_interface->addHorizontalSlider("Chorus Depth", &fHslider6, FAUSTFLOAT(2.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(2e+01f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fHslider5, "Hz", "");
		ui_interface->addHorizontalSlider("Chorus Rate", &fHslider5, FAUSTFLOAT(1.5f), FAUSTFLOAT(0.1f), FAUSTFLOAT(5.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider0, "0", "1");
		ui_interface->addHorizontalSlider("Decay", &fHslider0, FAUSTFLOAT(0.1f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider4, "-3", "3");
		ui_interface->addHorizontalSlider("Octave", &fHslider4, FAUSTFLOAT(0.0f), FAUSTFLOAT(-3.0f), FAUSTFLOAT(3.0f), FAUSTFLOAT(1.0f));
		ui_interface->addButton("Play A", &fButton6);
		ui_interface->addButton("Play B", &fButton5);
		ui_interface->addButton("Play C", &fButton4);
		ui_interface->addButton("Play D", &fButton3);
		ui_interface->addButton("Play E", &fButton2);
		ui_interface->addButton("Play F", &fButton1);
		ui_interface->addButton("Play G", &fButton0);
		ui_interface->declare(&fHslider3, "0", "1");
		ui_interface->addHorizontalSlider("Release", &fHslider3, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider1, "0", "1");
		ui_interface->addHorizontalSlider("Sustain", &fHslider1, FAUSTFLOAT(0.7f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		float fSlow0 = fConst1 * float(fHslider0);
		float fSlow1 = float(fHslider1);
		float fSlow2 = 1.0f - fSlow1;
		float fSlow3 = fConst1 * float(fHslider2);
		float fSlow4 = float(fButton0);
		float fSlow5 = fSlow4 * (1.0f - fSlow4);
		float fSlow6 = fConst1 * float(fHslider3);
		float fSlow7 = float(int(std::pow(float(2), float(int(float(fHslider4))))));
		float fSlow8 = fConst3 * fSlow7;
		float fSlow9 = mydsp_faustpower2_f(fSlow4);
		float fSlow10 = float(fButton1);
		float fSlow11 = fSlow10 * (1.0f - fSlow10);
		float fSlow12 = fConst4 * fSlow7;
		float fSlow13 = mydsp_faustpower2_f(fSlow10);
		float fSlow14 = float(fButton2);
		float fSlow15 = fSlow14 * (1.0f - fSlow14);
		float fSlow16 = fConst5 * fSlow7;
		float fSlow17 = mydsp_faustpower2_f(fSlow14);
		float fSlow18 = float(fButton3);
		float fSlow19 = fSlow18 * (1.0f - fSlow18);
		float fSlow20 = fConst6 * fSlow7;
		float fSlow21 = mydsp_faustpower2_f(fSlow18);
		float fSlow22 = float(fButton4);
		float fSlow23 = fSlow22 * (1.0f - fSlow22);
		float fSlow24 = fConst7 * fSlow7;
		float fSlow25 = mydsp_faustpower2_f(fSlow22);
		float fSlow26 = float(fButton5);
		float fSlow27 = fSlow26 * (1.0f - fSlow26);
		float fSlow28 = fConst8 * fSlow7;
		float fSlow29 = mydsp_faustpower2_f(fSlow26);
		float fSlow30 = float(fButton6);
		float fSlow31 = fSlow30 * (1.0f - fSlow30);
		float fSlow32 = fConst9 * fSlow7;
		float fSlow33 = mydsp_faustpower2_f(fSlow30);
		float fSlow34 = fConst10 * float(fHslider5);
		float fSlow35 = 0.5f * float(fHslider6);
		float fSlow36 = float(fHslider7);
		for (int i0 = 0; i0 < count; i0 = i0 + 1) {
			iVec0[0] = 1;
			fRec0[0] = fSlow0 + fConst2 * fRec0[1];
			fRec1[0] = fSlow3 + fConst2 * fRec1[1];
			float fTemp0 = fSlow1 + (fRec1[0] - fSlow2 * fRec0[0]);
			fRec2[0] = fSlow6 + fConst2 * fRec2[1];
			float fTemp1 = fSlow1 * fRec2[0];
			int iTemp2 = 1 - iVec0[1];
			float fTemp3 = ((iTemp2) ? 0.0f : fSlow8 + fRec4[1]);
			fRec4[0] = fTemp3 - std::floor(fTemp3);
			float fTemp4 = ((iTemp2) ? 0.0f : fSlow12 + fRec5[1]);
			fRec5[0] = fTemp4 - std::floor(fTemp4);
			float fTemp5 = ((iTemp2) ? 0.0f : fSlow16 + fRec6[1]);
			fRec6[0] = fTemp5 - std::floor(fTemp5);
			float fTemp6 = ((iTemp2) ? 0.0f : fSlow20 + fRec7[1]);
			fRec7[0] = fTemp6 - std::floor(fTemp6);
			float fTemp7 = ((iTemp2) ? 0.0f : fSlow24 + fRec8[1]);
			fRec8[0] = fTemp7 - std::floor(fTemp7);
			float fTemp8 = ((iTemp2) ? 0.0f : fSlow28 + fRec9[1]);
			fRec9[0] = fTemp8 - std::floor(fTemp8);
			float fTemp9 = ((iTemp2) ? 0.0f : fSlow32 + fRec10[1]);
			fRec10[0] = fTemp9 - std::floor(fTemp9);
			float fTemp10 = fSlow33 * ftbl0mydspSIG0[std::max<int>(0, std::min<int>(int(65536.0f * fRec10[0]), 65535))] * (fSlow31 * fTemp0 + fTemp1) + fSlow29 * ftbl0mydspSIG0[std::max<int>(0, std::min<int>(int(65536.0f * fRec9[0]), 65535))] * (fTemp1 + fSlow27 * fTemp0) + fSlow25 * ftbl0mydspSIG0[std::max<int>(0, std::min<int>(int(65536.0f * fRec8[0]), 65535))] * (fTemp1 + fSlow23 * fTemp0) + fSlow21 * ftbl0mydspSIG0[std::max<int>(0, std::min<int>(int(65536.0f * fRec7[0]), 65535))] * (fTemp1 + fSlow19 * fTemp0) + fSlow17 * ftbl0mydspSIG0[std::max<int>(0, std::min<int>(int(65536.0f * fRec6[0]), 65535))] * (fTemp1 + fSlow15 * fTemp0) + fSlow13 * ftbl0mydspSIG0[std::max<int>(0, std::min<int>(int(65536.0f * fRec5[0]), 65535))] * (fTemp1 + fSlow11 * fTemp0) + fSlow9 * ftbl0mydspSIG0[std::max<int>(0, std::min<int>(int(65536.0f * fRec4[0]), 65535))] * (fTemp1 + fSlow5 * fTemp0);
			fVec2[IOTA0 & 16383] = fTemp10;
			float fTemp11 = ((iTemp2) ? 0.0f : fSlow34 + fRec11[1]);
			fRec11[0] = fTemp11 - std::floor(fTemp11);
			float fTemp12 = 0.14f * (fTemp10 + fVec2[(IOTA0 - int(fConst11 * (fSlow36 + fSlow35 * (ftbl0mydspSIG0[std::max<int>(0, std::min<int>(int(65536.0f * fRec11[0]), 65535))] + 1.0f)))) & 16383]);
			output0[i0] = FAUSTFLOAT(fTemp12);
			output1[i0] = FAUSTFLOAT(fTemp12);
			iVec0[1] = iVec0[0];
			fRec0[1] = fRec0[0];
			fRec1[1] = fRec1[0];
			fRec2[1] = fRec2[0];
			fRec4[1] = fRec4[0];
			fRec5[1] = fRec5[0];
			fRec6[1] = fRec6[0];
			fRec7[1] = fRec7[0];
			fRec8[1] = fRec8[0];
			fRec9[1] = fRec9[0];
			fRec10[1] = fRec10[0];
			IOTA0 = IOTA0 + 1;
			fRec11[1] = fRec11[0];
		}
	}

};

#endif
