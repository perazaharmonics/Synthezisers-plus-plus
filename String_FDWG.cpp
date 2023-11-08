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


class mydsp : public dsp {
	
 private:
	
	int IOTA0;
	FAUSTFLOAT fHslider0;
	int fSampleRate;
	float fConst0;
	FAUSTFLOAT fHslider1;
	float fRec0[2048];
	
 public:
	mydsp() {}

	void metadata(Meta* m) { 
		m->declare("compile_options", "-lang cpp -ct 1 -es 1 -mcd 16 -single -ftz 0");
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
		m->declare("music.lib/author", "GRAME");
		m->declare("music.lib/copyright", "GRAME");
		m->declare("music.lib/deprecated", "This library is deprecated and is not maintained anymore. It will be removed in August 2017.");
		m->declare("music.lib/license", "LGPL with exception");
		m->declare("music.lib/name", "Music Library");
		m->declare("music.lib/version", "1.0");
		m->declare("name", "untitled");
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
		fConst0 = std::min<float>(1.92e+05f, std::max<float>(1.0f, float(fSampleRate)));
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(4.4e+02f);
		fHslider1 = FAUSTFLOAT(0.9f);
	}
	
	virtual void instanceClear() {
		IOTA0 = 0;
		for (int l0 = 0; l0 < 2048; l0 = l0 + 1) {
			fRec0[l0] = 0.0f;
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
		ui_interface->addHorizontalSlider("feedback", &fHslider1, FAUSTFLOAT(0.9f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->addHorizontalSlider("freq", &fHslider0, FAUSTFLOAT(4.4e+02f), FAUSTFLOAT(51.0f), FAUSTFLOAT(2e+03f), FAUSTFLOAT(0.01f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = fConst0 / float(fHslider0);
		int iSlow1 = int(fSlow0 + -1.499995f);
		int iSlow2 = ((iSlow1 + 4) & 1023) + 1;
		float fSlow3 = float(iSlow1);
		float fSlow4 = fSlow0 + (-3.0f - fSlow3);
		float fSlow5 = fSlow0 + (-2.0f - fSlow3);
		float fSlow6 = fSlow0 + (-1.0f - fSlow3);
		float fSlow7 = fSlow0 - fSlow3;
		float fSlow8 = fSlow7 * fSlow6;
		float fSlow9 = fSlow8 * fSlow5;
		float fSlow10 = 0.041666668f * fSlow9 * fSlow4;
		int iSlow11 = ((iSlow1 + 3) & 1023) + 1;
		float fSlow12 = 0.16666667f * fSlow9;
		int iSlow13 = ((iSlow1 + 2) & 1023) + 1;
		float fSlow14 = 0.25f * fSlow8;
		int iSlow15 = ((iSlow1 + 1) & 1023) + 1;
		float fSlow16 = 0.16666667f * fSlow7;
		int iSlow17 = (iSlow1 & 1023) + 1;
		float fSlow18 = 0.041666668f * fSlow6;
		float fSlow19 = fSlow0 + (-4.0f - fSlow3);
		float fSlow20 = float(fHslider1);
		for (int i0 = 0; i0 < count; i0 = i0 + 1) {
			fRec0[IOTA0 & 2047] = float(input0[i0]) + fSlow20 * (fSlow19 * (fSlow4 * (fSlow5 * (fSlow18 * fRec0[(IOTA0 - iSlow17) & 2047] - fSlow16 * fRec0[(IOTA0 - iSlow15) & 2047]) + fSlow14 * fRec0[(IOTA0 - iSlow13) & 2047]) - fSlow12 * fRec0[(IOTA0 - iSlow11) & 2047]) + fSlow10 * fRec0[(IOTA0 - iSlow2) & 2047]);
			output0[i0] = FAUSTFLOAT(fRec0[IOTA0 & 2047]);
			IOTA0 = IOTA0 + 1;
		}
	}

};

#endif
