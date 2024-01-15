/* ------------------------------------------------------------
name: "untitled"
Code generated with Faust 2.69.9 (https://faust.grame.fr)
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

static float mydsp_faustpower2_f(float value) {
	return value * value;
}

class mydsp : public dsp {
	
 private:
	
	FAUSTFLOAT fVslider0;
	FAUSTFLOAT fHslider0;
	int fSampleRate;
	float fConst1;
	FAUSTFLOAT fHslider1;
	float fConst2;
	FAUSTFLOAT fVslider1;
	FAUSTFLOAT fHslider2;
	FAUSTFLOAT fHslider3;
	FAUSTFLOAT fVslider2;
	FAUSTFLOAT fHslider4;
	FAUSTFLOAT fHslider5;
	FAUSTFLOAT fVslider3;
	FAUSTFLOAT fHslider6;
	FAUSTFLOAT fHslider7;
	FAUSTFLOAT fVslider4;
	FAUSTFLOAT fHslider8;
	FAUSTFLOAT fHslider9;
	FAUSTFLOAT fVslider5;
	FAUSTFLOAT fHslider10;
	FAUSTFLOAT fHslider11;
	FAUSTFLOAT fVslider6;
	FAUSTFLOAT fHslider12;
	FAUSTFLOAT fHslider13;
	FAUSTFLOAT fVslider7;
	FAUSTFLOAT fHslider14;
	FAUSTFLOAT fHslider15;
	FAUSTFLOAT fVslider8;
	FAUSTFLOAT fHslider16;
	FAUSTFLOAT fHslider17;
	FAUSTFLOAT fVslider9;
	FAUSTFLOAT fHslider18;
	FAUSTFLOAT fHslider19;
	float fRec9[3];
	float fRec8[3];
	float fRec7[3];
	float fRec6[3];
	float fRec5[3];
	float fRec4[3];
	float fRec3[3];
	float fRec2[3];
	float fRec1[3];
	float fRec0[3];
	
 public:
	mydsp() {}

	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/tabulateNd", "Copyright (C) 2023 Bart Brouns <bart@magnetophon.nl>");
		m->declare("basics.lib/version", "1.11.1");
		m->declare("compile_options", "-lang cpp -ct 1 -es 1 -mcd 16 -single -ftz 0");
		m->declare("filename", "untitled.dsp");
		m->declare("filters.lib/fir:author", "Julius O. Smith III");
		m->declare("filters.lib/fir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/fir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/iir:author", "Julius O. Smith III");
		m->declare("filters.lib/iir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/iir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/lowpass0_highpass1", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/peak_eq:author", "Julius O. Smith III");
		m->declare("filters.lib/peak_eq:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/peak_eq:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf2:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf2s:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2s:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2s:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/version", "1.3.0");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.7.0");
		m->declare("name", "untitled");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
	}

	virtual int getNumInputs() {
		return 1;
	}
	virtual int getNumOutputs() {
		return 1;
	}
	
	static void classInit(int sample_rate) {
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		float fConst0 = std::min<float>(1.92e+05f, std::max<float>(1.0f, float(fSampleRate)));
		fConst1 = 6.2831855f / fConst0;
		fConst2 = 3.1415927f / fConst0;
	}
	
	virtual void instanceResetUserInterface() {
		fVslider0 = FAUSTFLOAT(0.0f);
		fHslider0 = FAUSTFLOAT(1e+04f);
		fHslider1 = FAUSTFLOAT(1e+02f);
		fVslider1 = FAUSTFLOAT(0.0f);
		fHslider2 = FAUSTFLOAT(9e+03f);
		fHslider3 = FAUSTFLOAT(1e+02f);
		fVslider2 = FAUSTFLOAT(0.0f);
		fHslider4 = FAUSTFLOAT(8e+03f);
		fHslider5 = FAUSTFLOAT(1e+02f);
		fVslider3 = FAUSTFLOAT(0.0f);
		fHslider6 = FAUSTFLOAT(7e+03f);
		fHslider7 = FAUSTFLOAT(1e+02f);
		fVslider4 = FAUSTFLOAT(0.0f);
		fHslider8 = FAUSTFLOAT(6e+03f);
		fHslider9 = FAUSTFLOAT(1e+02f);
		fVslider5 = FAUSTFLOAT(0.0f);
		fHslider10 = FAUSTFLOAT(5e+03f);
		fHslider11 = FAUSTFLOAT(1e+02f);
		fVslider6 = FAUSTFLOAT(0.0f);
		fHslider12 = FAUSTFLOAT(4e+03f);
		fHslider13 = FAUSTFLOAT(1e+02f);
		fVslider7 = FAUSTFLOAT(0.0f);
		fHslider14 = FAUSTFLOAT(3e+03f);
		fHslider15 = FAUSTFLOAT(1e+02f);
		fVslider8 = FAUSTFLOAT(0.0f);
		fHslider16 = FAUSTFLOAT(2e+03f);
		fHslider17 = FAUSTFLOAT(1e+02f);
		fVslider9 = FAUSTFLOAT(0.0f);
		fHslider18 = FAUSTFLOAT(1e+03f);
		fHslider19 = FAUSTFLOAT(1e+02f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 3; l0 = l0 + 1) {
			fRec9[l0] = 0.0f;
		}
		for (int l1 = 0; l1 < 3; l1 = l1 + 1) {
			fRec8[l1] = 0.0f;
		}
		for (int l2 = 0; l2 < 3; l2 = l2 + 1) {
			fRec7[l2] = 0.0f;
		}
		for (int l3 = 0; l3 < 3; l3 = l3 + 1) {
			fRec6[l3] = 0.0f;
		}
		for (int l4 = 0; l4 < 3; l4 = l4 + 1) {
			fRec5[l4] = 0.0f;
		}
		for (int l5 = 0; l5 < 3; l5 = l5 + 1) {
			fRec4[l5] = 0.0f;
		}
		for (int l6 = 0; l6 < 3; l6 = l6 + 1) {
			fRec3[l6] = 0.0f;
		}
		for (int l7 = 0; l7 < 3; l7 = l7 + 1) {
			fRec2[l7] = 0.0f;
		}
		for (int l8 = 0; l8 < 3; l8 = l8 + 1) {
			fRec1[l8] = 0.0f;
		}
		for (int l9 = 0; l9 < 3; l9 = l9 + 1) {
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
		ui_interface->openHorizontalBox("Parametric EQ");
		ui_interface->openHorizontalBox("Band- 0");
		ui_interface->declare(&fHslider18, "1", "");
		ui_interface->declare(&fHslider18, "style", "knob");
		ui_interface->addHorizontalSlider("Freq", &fHslider18, FAUSTFLOAT(1e+03f), FAUSTFLOAT(0.0f), FAUSTFLOAT(2e+04f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fHslider19, "2", "");
		ui_interface->declare(&fHslider19, "style", "knob");
		ui_interface->addHorizontalSlider("Q factor", &fHslider19, FAUSTFLOAT(1e+02f), FAUSTFLOAT(1.0f), FAUSTFLOAT(4.41e+04f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fVslider9, "3", "");
		ui_interface->addVerticalSlider("Peak / Notch", &fVslider9, FAUSTFLOAT(0.0f), FAUSTFLOAT(-6e+01f), FAUSTFLOAT(1e+01f), FAUSTFLOAT(0.1f));
		ui_interface->closeBox();
		ui_interface->openHorizontalBox("Band- 1");
		ui_interface->declare(&fHslider16, "1", "");
		ui_interface->declare(&fHslider16, "style", "knob");
		ui_interface->addHorizontalSlider("Freq", &fHslider16, FAUSTFLOAT(2e+03f), FAUSTFLOAT(0.0f), FAUSTFLOAT(2e+04f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fHslider17, "2", "");
		ui_interface->declare(&fHslider17, "style", "knob");
		ui_interface->addHorizontalSlider("Q factor", &fHslider17, FAUSTFLOAT(1e+02f), FAUSTFLOAT(1.0f), FAUSTFLOAT(4.41e+04f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fVslider8, "3", "");
		ui_interface->addVerticalSlider("Peak / Notch", &fVslider8, FAUSTFLOAT(0.0f), FAUSTFLOAT(-6e+01f), FAUSTFLOAT(1e+01f), FAUSTFLOAT(0.1f));
		ui_interface->closeBox();
		ui_interface->openHorizontalBox("Band- 2");
		ui_interface->declare(&fHslider14, "1", "");
		ui_interface->declare(&fHslider14, "style", "knob");
		ui_interface->addHorizontalSlider("Freq", &fHslider14, FAUSTFLOAT(3e+03f), FAUSTFLOAT(0.0f), FAUSTFLOAT(2e+04f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fHslider15, "2", "");
		ui_interface->declare(&fHslider15, "style", "knob");
		ui_interface->addHorizontalSlider("Q factor", &fHslider15, FAUSTFLOAT(1e+02f), FAUSTFLOAT(1.0f), FAUSTFLOAT(4.41e+04f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fVslider7, "3", "");
		ui_interface->addVerticalSlider("Peak / Notch", &fVslider7, FAUSTFLOAT(0.0f), FAUSTFLOAT(-6e+01f), FAUSTFLOAT(1e+01f), FAUSTFLOAT(0.1f));
		ui_interface->closeBox();
		ui_interface->openHorizontalBox("Band- 3");
		ui_interface->declare(&fHslider12, "1", "");
		ui_interface->declare(&fHslider12, "style", "knob");
		ui_interface->addHorizontalSlider("Freq", &fHslider12, FAUSTFLOAT(4e+03f), FAUSTFLOAT(0.0f), FAUSTFLOAT(2e+04f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fHslider13, "2", "");
		ui_interface->declare(&fHslider13, "style", "knob");
		ui_interface->addHorizontalSlider("Q factor", &fHslider13, FAUSTFLOAT(1e+02f), FAUSTFLOAT(1.0f), FAUSTFLOAT(4.41e+04f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fVslider6, "3", "");
		ui_interface->addVerticalSlider("Peak / Notch", &fVslider6, FAUSTFLOAT(0.0f), FAUSTFLOAT(-6e+01f), FAUSTFLOAT(1e+01f), FAUSTFLOAT(0.1f));
		ui_interface->closeBox();
		ui_interface->openHorizontalBox("Band- 4");
		ui_interface->declare(&fHslider10, "1", "");
		ui_interface->declare(&fHslider10, "style", "knob");
		ui_interface->addHorizontalSlider("Freq", &fHslider10, FAUSTFLOAT(5e+03f), FAUSTFLOAT(0.0f), FAUSTFLOAT(2e+04f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fHslider11, "2", "");
		ui_interface->declare(&fHslider11, "style", "knob");
		ui_interface->addHorizontalSlider("Q factor", &fHslider11, FAUSTFLOAT(1e+02f), FAUSTFLOAT(1.0f), FAUSTFLOAT(4.41e+04f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fVslider5, "3", "");
		ui_interface->addVerticalSlider("Peak / Notch", &fVslider5, FAUSTFLOAT(0.0f), FAUSTFLOAT(-6e+01f), FAUSTFLOAT(1e+01f), FAUSTFLOAT(0.1f));
		ui_interface->closeBox();
		ui_interface->openHorizontalBox("Band- 5");
		ui_interface->declare(&fHslider8, "1", "");
		ui_interface->declare(&fHslider8, "style", "knob");
		ui_interface->addHorizontalSlider("Freq", &fHslider8, FAUSTFLOAT(6e+03f), FAUSTFLOAT(0.0f), FAUSTFLOAT(2e+04f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fHslider9, "2", "");
		ui_interface->declare(&fHslider9, "style", "knob");
		ui_interface->addHorizontalSlider("Q factor", &fHslider9, FAUSTFLOAT(1e+02f), FAUSTFLOAT(1.0f), FAUSTFLOAT(4.41e+04f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fVslider4, "3", "");
		ui_interface->addVerticalSlider("Peak / Notch", &fVslider4, FAUSTFLOAT(0.0f), FAUSTFLOAT(-6e+01f), FAUSTFLOAT(1e+01f), FAUSTFLOAT(0.1f));
		ui_interface->closeBox();
		ui_interface->openHorizontalBox("Band- 6");
		ui_interface->declare(&fHslider6, "1", "");
		ui_interface->declare(&fHslider6, "style", "knob");
		ui_interface->addHorizontalSlider("Freq", &fHslider6, FAUSTFLOAT(7e+03f), FAUSTFLOAT(0.0f), FAUSTFLOAT(2e+04f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fHslider7, "2", "");
		ui_interface->declare(&fHslider7, "style", "knob");
		ui_interface->addHorizontalSlider("Q factor", &fHslider7, FAUSTFLOAT(1e+02f), FAUSTFLOAT(1.0f), FAUSTFLOAT(4.41e+04f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fVslider3, "3", "");
		ui_interface->addVerticalSlider("Peak / Notch", &fVslider3, FAUSTFLOAT(0.0f), FAUSTFLOAT(-6e+01f), FAUSTFLOAT(1e+01f), FAUSTFLOAT(0.1f));
		ui_interface->closeBox();
		ui_interface->openHorizontalBox("Band- 7");
		ui_interface->declare(&fHslider4, "1", "");
		ui_interface->declare(&fHslider4, "style", "knob");
		ui_interface->addHorizontalSlider("Freq", &fHslider4, FAUSTFLOAT(8e+03f), FAUSTFLOAT(0.0f), FAUSTFLOAT(2e+04f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fHslider5, "2", "");
		ui_interface->declare(&fHslider5, "style", "knob");
		ui_interface->addHorizontalSlider("Q factor", &fHslider5, FAUSTFLOAT(1e+02f), FAUSTFLOAT(1.0f), FAUSTFLOAT(4.41e+04f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fVslider2, "3", "");
		ui_interface->addVerticalSlider("Peak / Notch", &fVslider2, FAUSTFLOAT(0.0f), FAUSTFLOAT(-6e+01f), FAUSTFLOAT(1e+01f), FAUSTFLOAT(0.1f));
		ui_interface->closeBox();
		ui_interface->openHorizontalBox("Band- 8");
		ui_interface->declare(&fHslider2, "1", "");
		ui_interface->declare(&fHslider2, "style", "knob");
		ui_interface->addHorizontalSlider("Freq", &fHslider2, FAUSTFLOAT(9e+03f), FAUSTFLOAT(0.0f), FAUSTFLOAT(2e+04f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fHslider3, "2", "");
		ui_interface->declare(&fHslider3, "style", "knob");
		ui_interface->addHorizontalSlider("Q factor", &fHslider3, FAUSTFLOAT(1e+02f), FAUSTFLOAT(1.0f), FAUSTFLOAT(4.41e+04f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fVslider1, "3", "");
		ui_interface->addVerticalSlider("Peak / Notch", &fVslider1, FAUSTFLOAT(0.0f), FAUSTFLOAT(-6e+01f), FAUSTFLOAT(1e+01f), FAUSTFLOAT(0.1f));
		ui_interface->closeBox();
		ui_interface->openHorizontalBox("Band- 9");
		ui_interface->declare(&fHslider0, "1", "");
		ui_interface->declare(&fHslider0, "style", "knob");
		ui_interface->addHorizontalSlider("Freq", &fHslider0, FAUSTFLOAT(1e+04f), FAUSTFLOAT(0.0f), FAUSTFLOAT(2e+04f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fHslider1, "2", "");
		ui_interface->declare(&fHslider1, "style", "knob");
		ui_interface->addHorizontalSlider("Q factor", &fHslider1, FAUSTFLOAT(1e+02f), FAUSTFLOAT(1.0f), FAUSTFLOAT(4.41e+04f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fVslider0, "3", "");
		ui_interface->addVerticalSlider("Peak / Notch", &fVslider0, FAUSTFLOAT(0.0f), FAUSTFLOAT(-6e+01f), FAUSTFLOAT(1e+01f), FAUSTFLOAT(0.1f));
		ui_interface->closeBox();
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = float(fVslider0);
		int iSlow1 = fSlow0 > 0.0f;
		float fSlow2 = float(fHslider0);
		float fSlow3 = std::sin(fConst1 * fSlow2);
		float fSlow4 = float(fHslider1);
		float fSlow5 = fConst2 * (fSlow4 * std::pow(1e+01f, 0.05f * std::fabs(fSlow0)) / fSlow3);
		float fSlow6 = fConst2 * (fSlow4 / fSlow3);
		float fSlow7 = ((iSlow1) ? fSlow6 : fSlow5);
		float fSlow8 = std::tan(fConst2 * fSlow2);
		float fSlow9 = 1.0f / fSlow8;
		float fSlow10 = fSlow9 * (fSlow9 + fSlow7) + 1.0f;
		float fSlow11 = ((iSlow1) ? fSlow5 : fSlow6);
		float fSlow12 = fSlow9 * (fSlow9 - fSlow11) + 1.0f;
		float fSlow13 = 2.0f * (1.0f - 1.0f / mydsp_faustpower2_f(fSlow8));
		float fSlow14 = fSlow9 * (fSlow9 - fSlow7) + 1.0f;
		float fSlow15 = float(fVslider1);
		int iSlow16 = fSlow15 > 0.0f;
		float fSlow17 = float(fHslider2);
		float fSlow18 = std::sin(fConst1 * fSlow17);
		float fSlow19 = float(fHslider3);
		float fSlow20 = fConst2 * (fSlow19 * std::pow(1e+01f, 0.05f * std::fabs(fSlow15)) / fSlow18);
		float fSlow21 = fConst2 * (fSlow19 / fSlow18);
		float fSlow22 = ((iSlow16) ? fSlow21 : fSlow20);
		float fSlow23 = std::tan(fConst2 * fSlow17);
		float fSlow24 = 1.0f / fSlow23;
		float fSlow25 = fSlow24 * (fSlow24 + fSlow22) + 1.0f;
		float fSlow26 = ((iSlow16) ? fSlow20 : fSlow21);
		float fSlow27 = fSlow24 * (fSlow24 - fSlow26) + 1.0f;
		float fSlow28 = 2.0f * (1.0f - 1.0f / mydsp_faustpower2_f(fSlow23));
		float fSlow29 = fSlow24 * (fSlow24 - fSlow22) + 1.0f;
		float fSlow30 = float(fVslider2);
		int iSlow31 = fSlow30 > 0.0f;
		float fSlow32 = float(fHslider4);
		float fSlow33 = std::sin(fConst1 * fSlow32);
		float fSlow34 = float(fHslider5);
		float fSlow35 = fConst2 * (fSlow34 * std::pow(1e+01f, 0.05f * std::fabs(fSlow30)) / fSlow33);
		float fSlow36 = fConst2 * (fSlow34 / fSlow33);
		float fSlow37 = ((iSlow31) ? fSlow36 : fSlow35);
		float fSlow38 = std::tan(fConst2 * fSlow32);
		float fSlow39 = 1.0f / fSlow38;
		float fSlow40 = fSlow39 * (fSlow39 + fSlow37) + 1.0f;
		float fSlow41 = ((iSlow31) ? fSlow35 : fSlow36);
		float fSlow42 = fSlow39 * (fSlow39 - fSlow41) + 1.0f;
		float fSlow43 = 2.0f * (1.0f - 1.0f / mydsp_faustpower2_f(fSlow38));
		float fSlow44 = fSlow39 * (fSlow39 - fSlow37) + 1.0f;
		float fSlow45 = float(fVslider3);
		int iSlow46 = fSlow45 > 0.0f;
		float fSlow47 = float(fHslider6);
		float fSlow48 = std::sin(fConst1 * fSlow47);
		float fSlow49 = float(fHslider7);
		float fSlow50 = fConst2 * (fSlow49 * std::pow(1e+01f, 0.05f * std::fabs(fSlow45)) / fSlow48);
		float fSlow51 = fConst2 * (fSlow49 / fSlow48);
		float fSlow52 = ((iSlow46) ? fSlow51 : fSlow50);
		float fSlow53 = std::tan(fConst2 * fSlow47);
		float fSlow54 = 1.0f / fSlow53;
		float fSlow55 = fSlow54 * (fSlow54 + fSlow52) + 1.0f;
		float fSlow56 = ((iSlow46) ? fSlow50 : fSlow51);
		float fSlow57 = fSlow54 * (fSlow54 - fSlow56) + 1.0f;
		float fSlow58 = 2.0f * (1.0f - 1.0f / mydsp_faustpower2_f(fSlow53));
		float fSlow59 = fSlow54 * (fSlow54 - fSlow52) + 1.0f;
		float fSlow60 = float(fVslider4);
		int iSlow61 = fSlow60 > 0.0f;
		float fSlow62 = float(fHslider8);
		float fSlow63 = std::sin(fConst1 * fSlow62);
		float fSlow64 = float(fHslider9);
		float fSlow65 = fConst2 * (fSlow64 * std::pow(1e+01f, 0.05f * std::fabs(fSlow60)) / fSlow63);
		float fSlow66 = fConst2 * (fSlow64 / fSlow63);
		float fSlow67 = ((iSlow61) ? fSlow66 : fSlow65);
		float fSlow68 = std::tan(fConst2 * fSlow62);
		float fSlow69 = 1.0f / fSlow68;
		float fSlow70 = fSlow69 * (fSlow69 + fSlow67) + 1.0f;
		float fSlow71 = ((iSlow61) ? fSlow65 : fSlow66);
		float fSlow72 = fSlow69 * (fSlow69 - fSlow71) + 1.0f;
		float fSlow73 = 2.0f * (1.0f - 1.0f / mydsp_faustpower2_f(fSlow68));
		float fSlow74 = fSlow69 * (fSlow69 - fSlow67) + 1.0f;
		float fSlow75 = float(fVslider5);
		int iSlow76 = fSlow75 > 0.0f;
		float fSlow77 = float(fHslider10);
		float fSlow78 = std::sin(fConst1 * fSlow77);
		float fSlow79 = float(fHslider11);
		float fSlow80 = fConst2 * (fSlow79 * std::pow(1e+01f, 0.05f * std::fabs(fSlow75)) / fSlow78);
		float fSlow81 = fConst2 * (fSlow79 / fSlow78);
		float fSlow82 = ((iSlow76) ? fSlow81 : fSlow80);
		float fSlow83 = std::tan(fConst2 * fSlow77);
		float fSlow84 = 1.0f / fSlow83;
		float fSlow85 = fSlow84 * (fSlow84 + fSlow82) + 1.0f;
		float fSlow86 = ((iSlow76) ? fSlow80 : fSlow81);
		float fSlow87 = fSlow84 * (fSlow84 - fSlow86) + 1.0f;
		float fSlow88 = 2.0f * (1.0f - 1.0f / mydsp_faustpower2_f(fSlow83));
		float fSlow89 = fSlow84 * (fSlow84 - fSlow82) + 1.0f;
		float fSlow90 = float(fVslider6);
		int iSlow91 = fSlow90 > 0.0f;
		float fSlow92 = float(fHslider12);
		float fSlow93 = std::sin(fConst1 * fSlow92);
		float fSlow94 = float(fHslider13);
		float fSlow95 = fConst2 * (fSlow94 * std::pow(1e+01f, 0.05f * std::fabs(fSlow90)) / fSlow93);
		float fSlow96 = fConst2 * (fSlow94 / fSlow93);
		float fSlow97 = ((iSlow91) ? fSlow96 : fSlow95);
		float fSlow98 = std::tan(fConst2 * fSlow92);
		float fSlow99 = 1.0f / fSlow98;
		float fSlow100 = fSlow99 * (fSlow99 + fSlow97) + 1.0f;
		float fSlow101 = ((iSlow91) ? fSlow95 : fSlow96);
		float fSlow102 = fSlow99 * (fSlow99 - fSlow101) + 1.0f;
		float fSlow103 = 2.0f * (1.0f - 1.0f / mydsp_faustpower2_f(fSlow98));
		float fSlow104 = fSlow99 * (fSlow99 - fSlow97) + 1.0f;
		float fSlow105 = float(fVslider7);
		int iSlow106 = fSlow105 > 0.0f;
		float fSlow107 = float(fHslider14);
		float fSlow108 = std::sin(fConst1 * fSlow107);
		float fSlow109 = float(fHslider15);
		float fSlow110 = fConst2 * (fSlow109 * std::pow(1e+01f, 0.05f * std::fabs(fSlow105)) / fSlow108);
		float fSlow111 = fConst2 * (fSlow109 / fSlow108);
		float fSlow112 = ((iSlow106) ? fSlow111 : fSlow110);
		float fSlow113 = std::tan(fConst2 * fSlow107);
		float fSlow114 = 1.0f / fSlow113;
		float fSlow115 = fSlow114 * (fSlow114 + fSlow112) + 1.0f;
		float fSlow116 = ((iSlow106) ? fSlow110 : fSlow111);
		float fSlow117 = fSlow114 * (fSlow114 - fSlow116) + 1.0f;
		float fSlow118 = 2.0f * (1.0f - 1.0f / mydsp_faustpower2_f(fSlow113));
		float fSlow119 = fSlow114 * (fSlow114 - fSlow112) + 1.0f;
		float fSlow120 = float(fVslider8);
		int iSlow121 = fSlow120 > 0.0f;
		float fSlow122 = float(fHslider16);
		float fSlow123 = std::sin(fConst1 * fSlow122);
		float fSlow124 = float(fHslider17);
		float fSlow125 = fConst2 * (fSlow124 * std::pow(1e+01f, 0.05f * std::fabs(fSlow120)) / fSlow123);
		float fSlow126 = fConst2 * (fSlow124 / fSlow123);
		float fSlow127 = ((iSlow121) ? fSlow126 : fSlow125);
		float fSlow128 = std::tan(fConst2 * fSlow122);
		float fSlow129 = 1.0f / fSlow128;
		float fSlow130 = fSlow129 * (fSlow129 + fSlow127) + 1.0f;
		float fSlow131 = ((iSlow121) ? fSlow125 : fSlow126);
		float fSlow132 = fSlow129 * (fSlow129 - fSlow131) + 1.0f;
		float fSlow133 = 2.0f * (1.0f - 1.0f / mydsp_faustpower2_f(fSlow128));
		float fSlow134 = fSlow129 * (fSlow129 - fSlow127) + 1.0f;
		float fSlow135 = float(fVslider9);
		int iSlow136 = fSlow135 > 0.0f;
		float fSlow137 = float(fHslider18);
		float fSlow138 = std::sin(fConst1 * fSlow137);
		float fSlow139 = float(fHslider19);
		float fSlow140 = fConst2 * (fSlow139 * std::pow(1e+01f, 0.05f * std::fabs(fSlow135)) / fSlow138);
		float fSlow141 = fConst2 * (fSlow139 / fSlow138);
		float fSlow142 = ((iSlow136) ? fSlow141 : fSlow140);
		float fSlow143 = std::tan(fConst2 * fSlow137);
		float fSlow144 = 1.0f / fSlow143;
		float fSlow145 = fSlow144 * (fSlow144 + fSlow142) + 1.0f;
		float fSlow146 = ((iSlow136) ? fSlow140 : fSlow141);
		float fSlow147 = fSlow144 * (fSlow144 - fSlow146) + 1.0f;
		float fSlow148 = 2.0f * (1.0f - 1.0f / mydsp_faustpower2_f(fSlow143));
		float fSlow149 = fSlow144 * (fSlow144 - fSlow142) + 1.0f;
		float fSlow150 = fSlow144 * (fSlow144 + fSlow146) + 1.0f;
		float fSlow151 = fSlow129 * (fSlow129 + fSlow131) + 1.0f;
		float fSlow152 = fSlow114 * (fSlow114 + fSlow116) + 1.0f;
		float fSlow153 = fSlow99 * (fSlow99 + fSlow101) + 1.0f;
		float fSlow154 = fSlow84 * (fSlow84 + fSlow86) + 1.0f;
		float fSlow155 = fSlow69 * (fSlow69 + fSlow71) + 1.0f;
		float fSlow156 = fSlow54 * (fSlow54 + fSlow56) + 1.0f;
		float fSlow157 = fSlow39 * (fSlow39 + fSlow41) + 1.0f;
		float fSlow158 = fSlow24 * (fSlow24 + fSlow26) + 1.0f;
		float fSlow159 = fSlow9 * (fSlow9 + fSlow11) + 1.0f;
		for (int i0 = 0; i0 < count; i0 = i0 + 1) {
			float fTemp0 = fSlow13 * fRec0[1];
			float fTemp1 = fSlow28 * fRec1[1];
			float fTemp2 = fSlow43 * fRec2[1];
			float fTemp3 = fSlow58 * fRec3[1];
			float fTemp4 = fSlow73 * fRec4[1];
			float fTemp5 = fSlow88 * fRec5[1];
			float fTemp6 = fSlow103 * fRec6[1];
			float fTemp7 = fSlow118 * fRec7[1];
			float fTemp8 = fSlow133 * fRec8[1];
			float fTemp9 = fSlow148 * fRec9[1];
			fRec9[0] = float(input0[i0]) - (fRec9[2] * fSlow149 + fTemp9) / fSlow145;
			fRec8[0] = (fTemp9 + fRec9[0] * fSlow150 + fRec9[2] * fSlow147) / fSlow145 - (fRec8[2] * fSlow134 + fTemp8) / fSlow130;
			fRec7[0] = (fTemp8 + fRec8[0] * fSlow151 + fRec8[2] * fSlow132) / fSlow130 - (fRec7[2] * fSlow119 + fTemp7) / fSlow115;
			fRec6[0] = (fTemp7 + fRec7[0] * fSlow152 + fRec7[2] * fSlow117) / fSlow115 - (fRec6[2] * fSlow104 + fTemp6) / fSlow100;
			fRec5[0] = (fTemp6 + fRec6[0] * fSlow153 + fRec6[2] * fSlow102) / fSlow100 - (fRec5[2] * fSlow89 + fTemp5) / fSlow85;
			fRec4[0] = (fTemp5 + fRec5[0] * fSlow154 + fRec5[2] * fSlow87) / fSlow85 - (fRec4[2] * fSlow74 + fTemp4) / fSlow70;
			fRec3[0] = (fTemp4 + fRec4[0] * fSlow155 + fRec4[2] * fSlow72) / fSlow70 - (fRec3[2] * fSlow59 + fTemp3) / fSlow55;
			fRec2[0] = (fTemp3 + fRec3[0] * fSlow156 + fRec3[2] * fSlow57) / fSlow55 - (fRec2[2] * fSlow44 + fTemp2) / fSlow40;
			fRec1[0] = (fTemp2 + fRec2[0] * fSlow157 + fRec2[2] * fSlow42) / fSlow40 - (fRec1[2] * fSlow29 + fTemp1) / fSlow25;
			fRec0[0] = (fTemp1 + fRec1[0] * fSlow158 + fRec1[2] * fSlow27) / fSlow25 - (fRec0[2] * fSlow14 + fTemp0) / fSlow10;
			output0[i0] = FAUSTFLOAT((fTemp0 + fRec0[0] * fSlow159 + fRec0[2] * fSlow12) / fSlow10);
			fRec9[2] = fRec9[1];
			fRec9[1] = fRec9[0];
			fRec8[2] = fRec8[1];
			fRec8[1] = fRec8[0];
			fRec7[2] = fRec7[1];
			fRec7[1] = fRec7[0];
			fRec6[2] = fRec6[1];
			fRec6[1] = fRec6[0];
			fRec5[2] = fRec5[1];
			fRec5[1] = fRec5[0];
			fRec4[2] = fRec4[1];
			fRec4[1] = fRec4[0];
			fRec3[2] = fRec3[1];
			fRec3[1] = fRec3[0];
			fRec2[2] = fRec2[1];
			fRec2[1] = fRec2[0];
			fRec1[2] = fRec1[1];
			fRec1[1] = fRec1[0];
			fRec0[2] = fRec0[1];
			fRec0[1] = fRec0[0];
		}
	}

};

#endif
