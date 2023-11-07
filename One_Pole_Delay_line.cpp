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
	int fSampleRate;
	float fConst0;
	float fConst1;
	FAUSTFLOAT fHslider0;
	float fRec1[2];
	int iRec2[2];
	float fRec0[4096];
	FAUSTFLOAT fHslider1;
	
 public:
	mydsp() {}

	void metadata(Meta* m) { 
		m->declare("compile_options", "-lang cpp -ct 1 -es 1 -mcd 16 -single -ftz 0");
		m->declare("filename", "untitled.dsp");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.7.0");
		m->declare("name", "untitled");
		m->declare("noises.lib/name", "Faust Noise Generator Library");
		m->declare("noises.lib/version", "1.4.0");
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
		fConst0 = 44.1f / std::min<float>(1.92e+05f, std::max<float>(1.0f, float(fSampleRate)));
		fConst1 = 1.0f - fConst0;
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(0.0f);
		fHslider1 = FAUSTFLOAT(2048.0f);
	}
	
	virtual void instanceClear() {
		IOTA0 = 0;
		for (int l0 = 0; l0 < 2; l0 = l0 + 1) {
			fRec1[l0] = 0.0f;
		}
		for (int l1 = 0; l1 < 2; l1 = l1 + 1) {
			iRec2[l1] = 0;
		}
		for (int l2 = 0; l2 < 4096; l2 = l2 + 1) {
			fRec0[l2] = 0.0f;
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
		ui_interface->declare(&fHslider1, "1,2048", "");
		ui_interface->addHorizontalSlider("delay length", &fHslider1, FAUSTFLOAT(2048.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(2048.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider0, "-1,1", "");
		ui_interface->addHorizontalSlider("feedback gain", &fHslider0, FAUSTFLOAT(0.0f), FAUSTFLOAT(-1.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = fConst0 * float(fHslider0);
		int iSlow1 = int(float(fHslider1));
		for (int i0 = 0; i0 < count; i0 = i0 + 1) {
			fRec1[0] = fSlow0 + fConst1 * fRec1[1];
			iRec2[0] = 1103515245 * iRec2[1] + 12345;
			fRec0[IOTA0 & 4095] = 4.656613e-10f * float(iRec2[0]) - fRec1[0] * fRec0[(IOTA0 - 1) & 4095];
			output0[i0] = FAUSTFLOAT(fRec0[(IOTA0 - iSlow1) & 4095]);
			IOTA0 = IOTA0 + 1;
			fRec1[1] = fRec1[0];
			iRec2[1] = iRec2[0];
		}
	}

};

#endif
