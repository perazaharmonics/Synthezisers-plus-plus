/* ------------------------------------------------------------
name: "untitled", "Josue Enrique Peraza Velazquez, B.Sc.EE, M.Eng.EE, M.Eng.EE"
Code generated with Faust 2.70.4 (https://faust.grame.fr)
Compilation options: -lang cpp -ct 1 -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0
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

static float mydsp_faustpower2_f(float value) {
	return value * value;
}

class mydsp : public dsp {
	
 private:
	
	int iVec0[2];
	int fSampleRate;
	float fConst1;
	float fConst2;
	FAUSTFLOAT fEntry0;
	float fRec1[2];
	FAUSTFLOAT fHslider0;
	float fRec3[2];
	float fRec2[2];
	FAUSTFLOAT fHslider1;
	float fRec4[2];
	FAUSTFLOAT fHslider2;
	float fRec5[2];
	FAUSTFLOAT fHslider3;
	float fConst3;
	float fRec6[2];
	float fRec7[2];
	int IOTA0;
	FAUSTFLOAT fHslider4;
	float fRec9[2];
	FAUSTFLOAT fHslider5;
	float fRec10[2];
	float fRec8[131072];
	float fRec0[2];
	FAUSTFLOAT fButton0;
	
 public:
	mydsp() {}

	void metadata(Meta* m) { 
		m->declare("compile_options", "-lang cpp -ct 1 -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0");
		m->declare("filename", "untitled.dsp");
		m->declare("filter.lib/author", "Julius O. Smith (jos at ccrma.stanford.edu)");
		m->declare("filter.lib/copyright", "Julius O. Smith III");
		m->declare("filter.lib/deprecated", "This library is deprecated and is not maintained anymore. It will be removed in August 2017.");
		m->declare("filter.lib/license", "STK-4.3");
		m->declare("filter.lib/name", "Faust Filter Library");
		m->declare("filter.lib/reference", "https://ccrma.stanford.edu/~jos/filters/");
		m->declare("filter.lib/version", "1.29");
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
		m->declare("oscillators.lib/version", "1.5.0");
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
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		float fConst0 = std::min<float>(1.92e+05f, std::max<float>(1.0f, float(fSampleRate)));
		fConst1 = 44.1f / fConst0;
		fConst2 = 1.0f - fConst1;
		fConst3 = 3.1415927f / fConst0;
	}
	
	virtual void instanceResetUserInterface() {
		fEntry0 = FAUSTFLOAT(0.1f);
		fHslider0 = FAUSTFLOAT(5.0f);
		fHslider1 = FAUSTFLOAT(0.0f);
		fHslider2 = FAUSTFLOAT(1.0f);
		fHslider3 = FAUSTFLOAT(1.0f);
		fHslider4 = FAUSTFLOAT(2.5e+02f);
		fHslider5 = FAUSTFLOAT(0.0f);
		fButton0 = FAUSTFLOAT(0.0f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = l0 + 1) {
			iVec0[l0] = 0;
		}
		for (int l1 = 0; l1 < 2; l1 = l1 + 1) {
			fRec1[l1] = 0.0f;
		}
		for (int l2 = 0; l2 < 2; l2 = l2 + 1) {
			fRec3[l2] = 0.0f;
		}
		for (int l3 = 0; l3 < 2; l3 = l3 + 1) {
			fRec2[l3] = 0.0f;
		}
		for (int l4 = 0; l4 < 2; l4 = l4 + 1) {
			fRec4[l4] = 0.0f;
		}
		for (int l5 = 0; l5 < 2; l5 = l5 + 1) {
			fRec5[l5] = 0.0f;
		}
		for (int l6 = 0; l6 < 2; l6 = l6 + 1) {
			fRec6[l6] = 0.0f;
		}
		for (int l7 = 0; l7 < 2; l7 = l7 + 1) {
			fRec7[l7] = 0.0f;
		}
		IOTA0 = 0;
		for (int l8 = 0; l8 < 2; l8 = l8 + 1) {
			fRec9[l8] = 0.0f;
		}
		for (int l9 = 0; l9 < 2; l9 = l9 + 1) {
			fRec10[l9] = 0.0f;
		}
		for (int l10 = 0; l10 < 131072; l10 = l10 + 1) {
			fRec8[l10] = 0.0f;
		}
		for (int l11 = 0; l11 < 2; l11 = l11 + 1) {
			fRec0[l11] = 0.0f;
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
		ui_interface->openHorizontalBox("Ring Modulation");
		ui_interface->addButton("Gate", &fButton0);
		ui_interface->declare(&fHslider3, "style", "knob");
		ui_interface->declare(&fHslider3, "units", "linear");
		ui_interface->addHorizontalSlider("Osc", &fHslider3, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.1f), FAUSTFLOAT(2e+01f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fEntry0, "2", "");
		ui_interface->declare(&fEntry0, "style", "knob");
		ui_interface->addNumEntry("a1", &fEntry0, FAUSTFLOAT(0.1f), FAUSTFLOAT(-0.93f), FAUSTFLOAT(0.93f), FAUSTFLOAT(0.0001f));
		ui_interface->declare(&fHslider1, "3", "");
		ui_interface->declare(&fHslider1, "style", "knob");
		ui_interface->addHorizontalSlider("Depth", &fHslider1, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider0, "4", "");
		ui_interface->declare(&fHslider0, "style", "knob");
		ui_interface->addHorizontalSlider("Freq", &fHslider0, FAUSTFLOAT(5.0f), FAUSTFLOAT(0.01f), FAUSTFLOAT(1e+03f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider4, "7", "");
		ui_interface->declare(&fHslider4, "style", "knob");
		ui_interface->addHorizontalSlider("Time (ms)", &fHslider4, FAUSTFLOAT(2.5e+02f), FAUSTFLOAT(0.1f), FAUSTFLOAT(1e+03f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fHslider5, "8", "");
		ui_interface->declare(&fHslider5, "style", "knob");
		ui_interface->addHorizontalSlider("Feedback", &fHslider5, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0001f));
		ui_interface->declare(&fHslider2, "9", "");
		ui_interface->declare(&fHslider2, "style", "knob");
		ui_interface->addHorizontalSlider("Dry", &fHslider2, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = fConst1 * float(fEntry0);
		float fSlow1 = 0.001f * float(fHslider0);
		float fSlow2 = 0.001f * float(fHslider1);
		float fSlow3 = fConst1 * float(fHslider2);
		float fSlow4 = std::tan(fConst3 * float(fHslider3));
		float fSlow5 = 2.0f * (fSlow4 / (mydsp_faustpower2_f(fSlow4) + 1.0f));
		float fSlow6 = 0.0441f * float(fHslider4);
		float fSlow7 = fConst1 * float(fHslider5);
		float fSlow8 = float(fButton0);
		for (int i0 = 0; i0 < count; i0 = i0 + 1) {
			iVec0[0] = 1;
			fRec1[0] = fSlow0 + fConst2 * fRec1[1];
			fRec3[0] = fSlow1 + 0.999f * fRec3[1];
			fRec2[0] = std::fmod(fRec2[1] + 1.0f, fRec3[0]);
			fRec4[0] = fSlow2 + 0.999f * fRec4[1];
			float fTemp0 = fRec4[0] * fRec2[0];
			float fTemp1 = fTemp0 + (1.0f - fTemp0);
			fRec5[0] = fSlow3 + fConst2 * fRec5[1];
			float fTemp2 = fRec7[1] + fSlow5 * (fRec6[1] - fSlow4 * fRec7[1]);
			fRec6[0] = ((iVec0[1]) ? fRec6[1] - fSlow4 * (fRec7[1] + fTemp2) : 1.0f);
			fRec7[0] = fTemp2;
			float fTemp3 = fRec6[0] + fRec7[0];
			fRec9[0] = fSlow6 + fConst2 * fRec9[1];
			int iTemp4 = int(fRec9[0]);
			float fTemp5 = float(iTemp4);
			fRec10[0] = fSlow7 + fConst2 * fRec10[1];
			fRec8[IOTA0 & 131071] = fTemp3 * fTemp1 - fRec10[0] * (fRec8[(IOTA0 - ((iTemp4 & 65535) + 1)) & 131071] * (fTemp5 + (1.0f - fRec9[0])) + (fRec9[0] - fTemp5) * fRec8[(IOTA0 - (((iTemp4 + 1) & 65535) + 1)) & 131071]);
			fRec0[0] = fRec8[IOTA0 & 131071] * (1.0f - fRec5[0]) + fTemp3 * fRec5[0] * fTemp1 - fRec1[0] * fRec0[1];
			output0[i0] = FAUSTFLOAT(fSlow8 * fRec0[0]);
			iVec0[1] = iVec0[0];
			fRec1[1] = fRec1[0];
			fRec3[1] = fRec3[0];
			fRec2[1] = fRec2[0];
			fRec4[1] = fRec4[0];
			fRec5[1] = fRec5[0];
			fRec6[1] = fRec6[0];
			fRec7[1] = fRec7[0];
			IOTA0 = IOTA0 + 1;
			fRec9[1] = fRec9[0];
			fRec10[1] = fRec10[0];
			fRec0[1] = fRec0[0];
		}
	}

};

#endif
