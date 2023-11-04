/* ------------------------------------------------------------
name: "httpsfaustservicecloudgramefr"
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

static float mydsp_faustpower2_f(float value) {
	return value * value;
}

class mydsp : public dsp {
	
 private:
	
	FAUSTFLOAT fHslider0;
	int fSampleRate;
	float fConst1;
	FAUSTFLOAT fButton0;
	float fVec0[2];
	FAUSTFLOAT fButton1;
	float fVec1[2];
	FAUSTFLOAT fButton2;
	float fVec2[2];
	FAUSTFLOAT fButton3;
	float fVec3[2];
	FAUSTFLOAT fButton4;
	float fVec4[2];
	FAUSTFLOAT fButton5;
	float fVec5[2];
	FAUSTFLOAT fButton6;
	float fVec6[2];
	float fVec7[2];
	int iRec3[2];
	float fConst2;
	float fConst3;
	float fRec4[2];
	float fConst4;
	FAUSTFLOAT fHslider1;
	int IOTA0;
	float fRec2[4096];
	FAUSTFLOAT fHslider2;
	float fVec8[2];
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
		m->declare("filename", "httpsfaustservicecloudgramefr.dsp");
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
		m->declare("name", "httpsfaustservicecloudgramefr");
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
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		float fConst0 = std::min<float>(1.92e+05f, std::max<float>(1.0f, float(fSampleRate)));
		fConst1 = 3.1415927f / fConst0;
		fConst2 = std::max<float>(1.0f, 0.01f * fConst0);
		fConst3 = 1.0f / fConst2;
		fConst4 = 1.0f / std::max<float>(1.0f, 0.05f * fConst0);
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(4e+02f);
		fButton0 = FAUSTFLOAT(0.0f);
		fButton1 = FAUSTFLOAT(0.0f);
		fButton2 = FAUSTFLOAT(0.0f);
		fButton3 = FAUSTFLOAT(0.0f);
		fButton4 = FAUSTFLOAT(0.0f);
		fButton5 = FAUSTFLOAT(0.0f);
		fButton6 = FAUSTFLOAT(0.0f);
		fHslider1 = FAUSTFLOAT(0.7f);
		fHslider2 = FAUSTFLOAT(0.5f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = l0 + 1) {
			fVec0[l0] = 0.0f;
		}
		for (int l1 = 0; l1 < 2; l1 = l1 + 1) {
			fVec1[l1] = 0.0f;
		}
		for (int l2 = 0; l2 < 2; l2 = l2 + 1) {
			fVec2[l2] = 0.0f;
		}
		for (int l3 = 0; l3 < 2; l3 = l3 + 1) {
			fVec3[l3] = 0.0f;
		}
		for (int l4 = 0; l4 < 2; l4 = l4 + 1) {
			fVec4[l4] = 0.0f;
		}
		for (int l5 = 0; l5 < 2; l5 = l5 + 1) {
			fVec5[l5] = 0.0f;
		}
		for (int l6 = 0; l6 < 2; l6 = l6 + 1) {
			fVec6[l6] = 0.0f;
		}
		for (int l7 = 0; l7 < 2; l7 = l7 + 1) {
			fVec7[l7] = 0.0f;
		}
		for (int l8 = 0; l8 < 2; l8 = l8 + 1) {
			iRec3[l8] = 0;
		}
		for (int l9 = 0; l9 < 2; l9 = l9 + 1) {
			fRec4[l9] = 0.0f;
		}
		IOTA0 = 0;
		for (int l10 = 0; l10 < 4096; l10 = l10 + 1) {
			fRec2[l10] = 0.0f;
		}
		for (int l11 = 0; l11 < 2; l11 = l11 + 1) {
			fVec8[l11] = 0.0f;
		}
		for (int l12 = 0; l12 < 2; l12 = l12 + 1) {
			fRec1[l12] = 0.0f;
		}
		for (int l13 = 0; l13 < 3; l13 = l13 + 1) {
			fRec0[l13] = 0.0f;
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
		ui_interface->openVerticalBox("httpsfaustservicecloudgramefr");
		ui_interface->addButton("A3", &fButton1);
		ui_interface->addButton("B3", &fButton0);
		ui_interface->addButton("C4", &fButton2);
		ui_interface->addButton("D4", &fButton3);
		ui_interface->addButton("E4", &fButton4);
		ui_interface->addButton("F4", &fButton5);
		ui_interface->addButton("G4", &fButton6);
		ui_interface->declare(&fHslider2, "style", "knob");
		ui_interface->addHorizontalSlider("gain", &fHslider2, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.001f));
		ui_interface->addHorizontalSlider("lowfreq", &fHslider0, FAUSTFLOAT(4e+02f), FAUSTFLOAT(2e+01f), FAUSTFLOAT(2e+04f), FAUSTFLOAT(1.0f));
		ui_interface->addHorizontalSlider("reed_stiffness", &fHslider1, FAUSTFLOAT(0.7f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
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
		float fSlow7 = float(fButton0);
		float fSlow8 = float(fButton1);
		float fSlow9 = float(fButton2);
		float fSlow10 = float(fButton3);
		float fSlow11 = float(fButton4);
		float fSlow12 = float(fButton5);
		float fSlow13 = float(fButton6);
		float fSlow14 = float(fHslider1);
		float fSlow15 = float(fHslider2);
		float fSlow16 = 1.0f - fSlow3;
		float fSlow17 = 1.0f / (fSlow3 + 1.0f);
		float fSlow18 = 1.0f / (fSlow1 * fSlow5);
		for (int i0 = 0; i0 < count; i0 = i0 + 1) {
			fVec0[0] = fSlow7;
			float fTemp0 = fSlow7 - fVec0[1];
			float fTemp1 = fTemp0 * float(fTemp0 > 0.0f);
			fVec1[0] = fSlow8;
			float fTemp2 = fSlow8 - fVec1[1];
			float fTemp3 = fTemp2 * float(fTemp2 > 0.0f);
			fVec2[0] = fSlow9;
			float fTemp4 = fSlow9 - fVec2[1];
			float fTemp5 = fTemp4 * float(fTemp4 > 0.0f);
			fVec3[0] = fSlow10;
			float fTemp6 = fSlow10 - fVec3[1];
			float fTemp7 = fTemp6 * float(fTemp6 > 0.0f);
			fVec4[0] = fSlow11;
			float fTemp8 = fSlow11 - fVec4[1];
			float fTemp9 = fTemp8 * float(fTemp8 > 0.0f);
			fVec5[0] = fSlow12;
			float fTemp10 = fSlow12 - fVec5[1];
			float fTemp11 = fTemp10 * float(fTemp10 > 0.0f);
			fVec6[0] = fSlow13;
			float fTemp12 = fSlow13 - fVec6[1];
			float fTemp13 = fTemp12 * float(fTemp12 > 0.0f);
			float fTemp14 = fTemp13 + fTemp11 + fTemp9 + fTemp7 + fTemp5 + fTemp3 + fTemp1;
			fVec7[0] = fTemp14;
			iRec3[0] = (iRec3[1] + 1) * (fTemp14 == 0.0f);
			fRec4[0] = fTemp14 + fRec4[1] * float(fVec7[1] >= fTemp14);
			float fTemp15 = 2.2e+02f * fTemp3 + 247.5f * fTemp1 + 261.63f * fTemp5 + 293.66f * fTemp7 + 329.63f * fTemp9 + 349.23f * fTemp11 + 392.0f * fTemp13;
			int iTemp16 = int(4.41e+04f / std::max<float>(1.0f, fTemp15));
			float fTemp17 = fTemp15 + -1.499995f;
			int iTemp18 = int(fTemp17);
			float fTemp19 = std::floor(fTemp17);
			float fTemp20 = fTemp15 + (-3.0f - fTemp19);
			float fTemp21 = fTemp15 + (-2.0f - fTemp19);
			float fTemp22 = fTemp15 + (-1.0f - fTemp19);
			float fTemp23 = fTemp15 - fTemp19;
			float fTemp24 = fTemp23 * fTemp22;
			float fTemp25 = fTemp24 * fTemp21;
			fRec2[IOTA0 & 4095] = (fTemp15 + (-4.0f - fTemp19)) * (fTemp20 * (fTemp21 * (0.041666668f * fRec2[(IOTA0 - (std::min<int>(iTemp16, std::max<int>(0, iTemp18)) + 1)) & 4095] * fTemp22 - 0.16666667f * fTemp23 * fRec2[(IOTA0 - (std::min<int>(iTemp16, std::max<int>(0, iTemp18 + 1)) + 1)) & 4095]) + 0.25f * fTemp24 * fRec2[(IOTA0 - (std::min<int>(iTemp16, std::max<int>(0, iTemp18 + 2)) + 1)) & 4095]) - 0.16666667f * fTemp25 * fRec2[(IOTA0 - (std::min<int>(iTemp16, std::max<int>(0, iTemp18 + 3)) + 1)) & 4095]) + 0.041666668f * fTemp25 * fTemp20 * fRec2[(IOTA0 - (std::min<int>(iTemp16, std::max<int>(0, iTemp18 + 4)) + 1)) & 4095] + tanhf(fSlow14 * fTemp14 * std::max<float>(0.0f, std::min<float>(fConst3 * fRec4[0], std::max<float>(fConst4 * (fConst2 - fRec4[0]) + 1.0f, 0.0f)) * (1.0f - fConst3 * float(iRec3[0])))) + 0.3f;
			float fTemp26 = fSlow15 * fRec2[IOTA0 & 4095];
			fVec8[0] = fTemp26;
			fRec1[0] = -(fSlow17 * (fSlow16 * fRec1[1] - fSlow3 * (fTemp26 - fVec8[1])));
			fRec0[0] = fRec1[0] - fSlow6 * (fSlow4 * fRec0[2] + fSlow2 * fRec0[1]);
			output0[i0] = FAUSTFLOAT(fSlow18 * (fRec0[0] + fRec0[2] - 2.0f * fRec0[1]));
			fVec0[1] = fVec0[0];
			fVec1[1] = fVec1[0];
			fVec2[1] = fVec2[0];
			fVec3[1] = fVec3[0];
			fVec4[1] = fVec4[0];
			fVec5[1] = fVec5[0];
			fVec6[1] = fVec6[0];
			fVec7[1] = fVec7[0];
			iRec3[1] = iRec3[0];
			fRec4[1] = fRec4[0];
			IOTA0 = IOTA0 + 1;
			fVec8[1] = fVec8[0];
			fRec1[1] = fRec1[0];
			fRec0[2] = fRec0[1];
			fRec0[1] = fRec0[0];
		}
	}

};

#endif
