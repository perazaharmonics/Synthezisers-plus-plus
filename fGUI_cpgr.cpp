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

static float mydsp_faustpower2_f(float value) {
	return value * value;
}

class mydsp : public dsp {
	
 private:
	
	float fVec0[3];
	FAUSTFLOAT fEntry0;
	int fSampleRate;
	float fConst1;
	FAUSTFLOAT fHslider0;
	FAUSTFLOAT fEntry1;
	float fConst2;
	float fRec0[3];
	
 public:
	mydsp() {}

	void metadata(Meta* m) { 
		m->declare("compile_options", "-lang cpp -ct 1 -es 1 -mcd 16 -single -ftz 0");
		m->declare("filename", "untitled.dsp");
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
		float fConst0 = float(fSampleRate);
		fConst1 = 1.0f / fConst0;
		fConst2 = 6.2831855f / fConst0;
	}
	
	virtual void instanceResetUserInterface() {
		fEntry0 = FAUSTFLOAT(1e+02f);
		fHslider0 = FAUSTFLOAT(1.0f);
		fEntry1 = FAUSTFLOAT(1e+03f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 3; l0 = l0 + 1) {
			fVec0[l0] = 0.0f;
		}
		for (int l1 = 0; l1 < 3; l1 = l1 + 1) {
			fRec0[l1] = 0.0f;
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
		ui_interface->addNumEntry("bandwidth (Hz)", &fEntry0, FAUSTFLOAT(1e+02f), FAUSTFLOAT(2e+01f), FAUSTFLOAT(2e+04f), FAUSTFLOAT(1e+01f));
		ui_interface->addNumEntry("frequency (Hz)", &fEntry1, FAUSTFLOAT(1e+03f), FAUSTFLOAT(2e+01f), FAUSTFLOAT(2e+04f), FAUSTFLOAT(1.0f));
		ui_interface->addHorizontalSlider("peak gain", &fHslider0, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1e+01f), FAUSTFLOAT(0.01f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = std::exp(fConst1 * (0.0f - 3.1415927f * float(fEntry0)));
		float fSlow1 = 0.5f * float(fHslider0) * (1.0f - mydsp_faustpower2_f(fSlow0));
		float fSlow2 = 2.0f * std::cos(fConst2 * float(fEntry1));
		for (int i0 = 0; i0 < count; i0 = i0 + 1) {
			float fTemp0 = float(input0[i0]);
			fVec0[0] = fTemp0;
			fRec0[0] = fSlow0 * (fSlow2 * fRec0[1] - fSlow0 * fRec0[2]) + fSlow1 * (fTemp0 - fVec0[2]);
			output0[i0] = FAUSTFLOAT(fRec0[0]);
			fVec0[2] = fVec0[1];
			fVec0[1] = fVec0[0];
			fRec0[2] = fRec0[1];
			fRec0[1] = fRec0[0];
		}
	}

};

#endif
