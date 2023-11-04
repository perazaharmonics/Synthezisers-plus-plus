/* ------------------------------------------------------------
name: "httpsfaustservicecloudgramefr", "Josué E. Peraza, B.Sc, M. EngEe"
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
	
	int iVec3[2];
	int iRec16[2];
	
  public:
	
	int getNumInputsmydspSIG0() {
		return 0;
	}
	int getNumOutputsmydspSIG0() {
		return 1;
	}
	
	void instanceInitmydspSIG0(int sample_rate) {
		for (int l7 = 0; l7 < 2; l7 = l7 + 1) {
			iVec3[l7] = 0;
		}
		for (int l8 = 0; l8 < 2; l8 = l8 + 1) {
			iRec16[l8] = 0;
		}
	}
	
	void fillmydspSIG0(int count, float* table) {
		for (int i1 = 0; i1 < count; i1 = i1 + 1) {
			iVec3[0] = 1;
			iRec16[0] = (iVec3[1] + iRec16[1]) % 65536;
			table[i1] = std::sin(9.58738e-05f * float(iRec16[0]));
			iVec3[1] = iVec3[0];
			iRec16[1] = iRec16[0];
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
	
	FAUSTFLOAT fVslider0;
	FAUSTFLOAT fVslider1;
	int fSampleRate;
	float fConst1;
	int iVec0[2];
	FAUSTFLOAT fVslider2;
	FAUSTFLOAT fVslider3;
	FAUSTFLOAT fVslider4;
	float fConst3;
	FAUSTFLOAT fVslider5;
	FAUSTFLOAT fVslider6;
	float fConst4;
	float fRec13[2];
	FAUSTFLOAT fVslider7;
	float fRec12[2];
	int IOTA0;
	float fVec1[16384];
	int iConst6;
	FAUSTFLOAT fButton0;
	float fVec2[2];
	int iRec14[2];
	float fConst7;
	float fConst8;
	float fRec15[2];
	float fConst9;
	FAUSTFLOAT fHslider0;
	float fConst10;
	float fRec18[2];
	FAUSTFLOAT fHslider1;
	FAUSTFLOAT fHslider2;
	float fRec17[2];
	float fVec4[16384];
	FAUSTFLOAT fVslider8;
	float fConst11;
	float fVec5[4096];
	int iConst12;
	float fRec10[2];
	float fConst14;
	float fRec22[2];
	float fRec21[2];
	float fVec6[16384];
	int iConst16;
	float fVec7[2048];
	int iConst17;
	float fRec19[2];
	float fConst19;
	float fRec26[2];
	float fRec25[2];
	float fVec8[16384];
	int iConst21;
	float fVec9[4096];
	int iConst22;
	float fRec23[2];
	float fConst24;
	float fRec30[2];
	float fRec29[2];
	float fVec10[16384];
	int iConst26;
	float fVec11[2048];
	int iConst27;
	float fRec27[2];
	float fConst29;
	float fRec34[2];
	float fRec33[2];
	float fVec12[32768];
	int iConst31;
	float fVec13[4096];
	int iConst32;
	float fRec31[2];
	float fConst34;
	float fRec38[2];
	float fRec37[2];
	float fVec14[16384];
	int iConst36;
	float fVec15[4096];
	int iConst37;
	float fRec35[2];
	float fConst39;
	float fRec42[2];
	float fRec41[2];
	float fVec16[32768];
	int iConst41;
	float fVec17[4096];
	int iConst42;
	float fRec39[2];
	float fConst44;
	float fRec46[2];
	float fRec45[2];
	float fVec18[32768];
	int iConst46;
	float fVec19[2048];
	int iConst47;
	float fRec43[2];
	float fRec2[3];
	float fRec3[3];
	float fRec4[3];
	float fRec5[3];
	float fRec6[3];
	float fRec7[3];
	float fRec8[3];
	float fRec9[3];
	float fRec1[3];
	float fRec0[3];
	float fConst48;
	float fConst49;
	FAUSTFLOAT fVslider9;
	float fRec47[2];
	FAUSTFLOAT fVslider10;
	float fRec48[2];
	float fRec50[3];
	float fRec49[3];
	FAUSTFLOAT fHslider3;
	FAUSTFLOAT fHslider4;
	
 public:
	mydsp() {}

	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/tabulateNd", "Copyright (C) 2023 Bart Brouns <bart@magnetophon.nl>");
		m->declare("basics.lib/version", "1.11.1");
		m->declare("compile_options", "-lang cpp -ct 1 -es 1 -mcd 16 -single -ftz 0");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "1.1.0");
		m->declare("demos.lib/name", "Faust Demos Library");
		m->declare("demos.lib/version", "1.1.0");
		m->declare("demos.lib/zita_rev1:author", "Julius O. Smith III");
		m->declare("demos.lib/zita_rev1:licence", "MIT");
		m->declare("envelopes.lib/adsr:author", "Yann Orlarey and Andrey Bundin");
		m->declare("envelopes.lib/author", "GRAME");
		m->declare("envelopes.lib/copyright", "GRAME");
		m->declare("envelopes.lib/license", "LGPL with exception");
		m->declare("envelopes.lib/name", "Faust Envelope Library");
		m->declare("envelopes.lib/version", "1.3.0");
		m->declare("filename", "httpsfaustservicecloudgramefr.dsp");
		m->declare("filters.lib/allpass_comb:author", "Julius O. Smith III");
		m->declare("filters.lib/allpass_comb:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/allpass_comb:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/fir:author", "Julius O. Smith III");
		m->declare("filters.lib/fir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/fir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/iir:author", "Julius O. Smith III");
		m->declare("filters.lib/iir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/iir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/lowpass0_highpass1", "MIT-style STK-4.3 license");
		m->declare("filters.lib/lowpass0_highpass1:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/lowpass:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/peak_eq_rm:author", "Julius O. Smith III");
		m->declare("filters.lib/peak_eq_rm:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/peak_eq_rm:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf1:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf1s:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1s:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1s:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf2:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2:license", "MIT-style STK-4.3 license");
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
		m->declare("oscillators.lib/name", "Faust Oscillator Library");
		m->declare("oscillators.lib/version", "1.4.0");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("reverbs.lib/name", "Faust Reverb Library");
		m->declare("reverbs.lib/version", "1.2.0");
		m->declare("routes.lib/hadamard:author", "Remy Muller, revised by Romain Michon");
		m->declare("routes.lib/name", "Faust Signal Routing Library");
		m->declare("routes.lib/version", "1.2.0");
		m->declare("signals.lib/name", "Faust Signal Routing Library");
		m->declare("signals.lib/version", "1.5.0");
	}

	virtual int getNumInputs() {
		return 0;
	}
	virtual int getNumOutputs() {
		return 4;
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
		fConst1 = 6.2831855f / fConst0;
		float fConst2 = std::floor(0.174713f * fConst0 + 0.5f);
		fConst3 = 6.9077554f * (fConst2 / fConst0);
		fConst4 = 3.1415927f / fConst0;
		float fConst5 = std::floor(0.022904f * fConst0 + 0.5f);
		iConst6 = int(std::min<float>(8192.0f, std::max<float>(0.0f, fConst2 - fConst5)));
		fConst7 = std::max<float>(1.0f, 0.01f * fConst0);
		fConst8 = 1.0f / fConst7;
		fConst9 = 1.0f / std::max<float>(1.0f, 0.05f * fConst0);
		fConst10 = 1.0f / fConst0;
		fConst11 = 0.001f * fConst0;
		iConst12 = int(std::min<float>(2048.0f, std::max<float>(0.0f, fConst5 + -1.0f)));
		float fConst13 = std::floor(0.153129f * fConst0 + 0.5f);
		fConst14 = 6.9077554f * (fConst13 / fConst0);
		float fConst15 = std::floor(0.020346f * fConst0 + 0.5f);
		iConst16 = int(std::min<float>(8192.0f, std::max<float>(0.0f, fConst13 - fConst15)));
		iConst17 = int(std::min<float>(1024.0f, std::max<float>(0.0f, fConst15 + -1.0f)));
		float fConst18 = std::floor(0.127837f * fConst0 + 0.5f);
		fConst19 = 6.9077554f * (fConst18 / fConst0);
		float fConst20 = std::floor(0.031604f * fConst0 + 0.5f);
		iConst21 = int(std::min<float>(8192.0f, std::max<float>(0.0f, fConst18 - fConst20)));
		iConst22 = int(std::min<float>(2048.0f, std::max<float>(0.0f, fConst20 + -1.0f)));
		float fConst23 = std::floor(0.125f * fConst0 + 0.5f);
		fConst24 = 6.9077554f * (fConst23 / fConst0);
		float fConst25 = std::floor(0.013458f * fConst0 + 0.5f);
		iConst26 = int(std::min<float>(8192.0f, std::max<float>(0.0f, fConst23 - fConst25)));
		iConst27 = int(std::min<float>(1024.0f, std::max<float>(0.0f, fConst25 + -1.0f)));
		float fConst28 = std::floor(0.210389f * fConst0 + 0.5f);
		fConst29 = 6.9077554f * (fConst28 / fConst0);
		float fConst30 = std::floor(0.024421f * fConst0 + 0.5f);
		iConst31 = int(std::min<float>(16384.0f, std::max<float>(0.0f, fConst28 - fConst30)));
		iConst32 = int(std::min<float>(2048.0f, std::max<float>(0.0f, fConst30 + -1.0f)));
		float fConst33 = std::floor(0.192303f * fConst0 + 0.5f);
		fConst34 = 6.9077554f * (fConst33 / fConst0);
		float fConst35 = std::floor(0.029291f * fConst0 + 0.5f);
		iConst36 = int(std::min<float>(8192.0f, std::max<float>(0.0f, fConst33 - fConst35)));
		iConst37 = int(std::min<float>(2048.0f, std::max<float>(0.0f, fConst35 + -1.0f)));
		float fConst38 = std::floor(0.256891f * fConst0 + 0.5f);
		fConst39 = 6.9077554f * (fConst38 / fConst0);
		float fConst40 = std::floor(0.027333f * fConst0 + 0.5f);
		iConst41 = int(std::min<float>(16384.0f, std::max<float>(0.0f, fConst38 - fConst40)));
		iConst42 = int(std::min<float>(2048.0f, std::max<float>(0.0f, fConst40 + -1.0f)));
		float fConst43 = std::floor(0.219991f * fConst0 + 0.5f);
		fConst44 = 6.9077554f * (fConst43 / fConst0);
		float fConst45 = std::floor(0.019123f * fConst0 + 0.5f);
		iConst46 = int(std::min<float>(16384.0f, std::max<float>(0.0f, fConst43 - fConst45)));
		iConst47 = int(std::min<float>(1024.0f, std::max<float>(0.0f, fConst45 + -1.0f)));
		fConst48 = 44.1f / fConst0;
		fConst49 = 1.0f - fConst48;
	}
	
	virtual void instanceResetUserInterface() {
		fVslider0 = FAUSTFLOAT(0.0f);
		fVslider1 = FAUSTFLOAT(1.5e+03f);
		fVslider2 = FAUSTFLOAT(0.0f);
		fVslider3 = FAUSTFLOAT(315.0f);
		fVslider4 = FAUSTFLOAT(2.0f);
		fVslider5 = FAUSTFLOAT(6e+03f);
		fVslider6 = FAUSTFLOAT(2e+02f);
		fVslider7 = FAUSTFLOAT(3.0f);
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider0 = FAUSTFLOAT(2.2e+02f);
		fHslider1 = FAUSTFLOAT(1.0f);
		fHslider2 = FAUSTFLOAT(4.4e+02f);
		fVslider8 = FAUSTFLOAT(6e+01f);
		fVslider9 = FAUSTFLOAT(0.0f);
		fVslider10 = FAUSTFLOAT(-2e+01f);
		fHslider3 = FAUSTFLOAT(1.0f);
		fHslider4 = FAUSTFLOAT(0.0f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = l0 + 1) {
			iVec0[l0] = 0;
		}
		for (int l1 = 0; l1 < 2; l1 = l1 + 1) {
			fRec13[l1] = 0.0f;
		}
		for (int l2 = 0; l2 < 2; l2 = l2 + 1) {
			fRec12[l2] = 0.0f;
		}
		IOTA0 = 0;
		for (int l3 = 0; l3 < 16384; l3 = l3 + 1) {
			fVec1[l3] = 0.0f;
		}
		for (int l4 = 0; l4 < 2; l4 = l4 + 1) {
			fVec2[l4] = 0.0f;
		}
		for (int l5 = 0; l5 < 2; l5 = l5 + 1) {
			iRec14[l5] = 0;
		}
		for (int l6 = 0; l6 < 2; l6 = l6 + 1) {
			fRec15[l6] = 0.0f;
		}
		for (int l9 = 0; l9 < 2; l9 = l9 + 1) {
			fRec18[l9] = 0.0f;
		}
		for (int l10 = 0; l10 < 2; l10 = l10 + 1) {
			fRec17[l10] = 0.0f;
		}
		for (int l11 = 0; l11 < 16384; l11 = l11 + 1) {
			fVec4[l11] = 0.0f;
		}
		for (int l12 = 0; l12 < 4096; l12 = l12 + 1) {
			fVec5[l12] = 0.0f;
		}
		for (int l13 = 0; l13 < 2; l13 = l13 + 1) {
			fRec10[l13] = 0.0f;
		}
		for (int l14 = 0; l14 < 2; l14 = l14 + 1) {
			fRec22[l14] = 0.0f;
		}
		for (int l15 = 0; l15 < 2; l15 = l15 + 1) {
			fRec21[l15] = 0.0f;
		}
		for (int l16 = 0; l16 < 16384; l16 = l16 + 1) {
			fVec6[l16] = 0.0f;
		}
		for (int l17 = 0; l17 < 2048; l17 = l17 + 1) {
			fVec7[l17] = 0.0f;
		}
		for (int l18 = 0; l18 < 2; l18 = l18 + 1) {
			fRec19[l18] = 0.0f;
		}
		for (int l19 = 0; l19 < 2; l19 = l19 + 1) {
			fRec26[l19] = 0.0f;
		}
		for (int l20 = 0; l20 < 2; l20 = l20 + 1) {
			fRec25[l20] = 0.0f;
		}
		for (int l21 = 0; l21 < 16384; l21 = l21 + 1) {
			fVec8[l21] = 0.0f;
		}
		for (int l22 = 0; l22 < 4096; l22 = l22 + 1) {
			fVec9[l22] = 0.0f;
		}
		for (int l23 = 0; l23 < 2; l23 = l23 + 1) {
			fRec23[l23] = 0.0f;
		}
		for (int l24 = 0; l24 < 2; l24 = l24 + 1) {
			fRec30[l24] = 0.0f;
		}
		for (int l25 = 0; l25 < 2; l25 = l25 + 1) {
			fRec29[l25] = 0.0f;
		}
		for (int l26 = 0; l26 < 16384; l26 = l26 + 1) {
			fVec10[l26] = 0.0f;
		}
		for (int l27 = 0; l27 < 2048; l27 = l27 + 1) {
			fVec11[l27] = 0.0f;
		}
		for (int l28 = 0; l28 < 2; l28 = l28 + 1) {
			fRec27[l28] = 0.0f;
		}
		for (int l29 = 0; l29 < 2; l29 = l29 + 1) {
			fRec34[l29] = 0.0f;
		}
		for (int l30 = 0; l30 < 2; l30 = l30 + 1) {
			fRec33[l30] = 0.0f;
		}
		for (int l31 = 0; l31 < 32768; l31 = l31 + 1) {
			fVec12[l31] = 0.0f;
		}
		for (int l32 = 0; l32 < 4096; l32 = l32 + 1) {
			fVec13[l32] = 0.0f;
		}
		for (int l33 = 0; l33 < 2; l33 = l33 + 1) {
			fRec31[l33] = 0.0f;
		}
		for (int l34 = 0; l34 < 2; l34 = l34 + 1) {
			fRec38[l34] = 0.0f;
		}
		for (int l35 = 0; l35 < 2; l35 = l35 + 1) {
			fRec37[l35] = 0.0f;
		}
		for (int l36 = 0; l36 < 16384; l36 = l36 + 1) {
			fVec14[l36] = 0.0f;
		}
		for (int l37 = 0; l37 < 4096; l37 = l37 + 1) {
			fVec15[l37] = 0.0f;
		}
		for (int l38 = 0; l38 < 2; l38 = l38 + 1) {
			fRec35[l38] = 0.0f;
		}
		for (int l39 = 0; l39 < 2; l39 = l39 + 1) {
			fRec42[l39] = 0.0f;
		}
		for (int l40 = 0; l40 < 2; l40 = l40 + 1) {
			fRec41[l40] = 0.0f;
		}
		for (int l41 = 0; l41 < 32768; l41 = l41 + 1) {
			fVec16[l41] = 0.0f;
		}
		for (int l42 = 0; l42 < 4096; l42 = l42 + 1) {
			fVec17[l42] = 0.0f;
		}
		for (int l43 = 0; l43 < 2; l43 = l43 + 1) {
			fRec39[l43] = 0.0f;
		}
		for (int l44 = 0; l44 < 2; l44 = l44 + 1) {
			fRec46[l44] = 0.0f;
		}
		for (int l45 = 0; l45 < 2; l45 = l45 + 1) {
			fRec45[l45] = 0.0f;
		}
		for (int l46 = 0; l46 < 32768; l46 = l46 + 1) {
			fVec18[l46] = 0.0f;
		}
		for (int l47 = 0; l47 < 2048; l47 = l47 + 1) {
			fVec19[l47] = 0.0f;
		}
		for (int l48 = 0; l48 < 2; l48 = l48 + 1) {
			fRec43[l48] = 0.0f;
		}
		for (int l49 = 0; l49 < 3; l49 = l49 + 1) {
			fRec2[l49] = 0.0f;
		}
		for (int l50 = 0; l50 < 3; l50 = l50 + 1) {
			fRec3[l50] = 0.0f;
		}
		for (int l51 = 0; l51 < 3; l51 = l51 + 1) {
			fRec4[l51] = 0.0f;
		}
		for (int l52 = 0; l52 < 3; l52 = l52 + 1) {
			fRec5[l52] = 0.0f;
		}
		for (int l53 = 0; l53 < 3; l53 = l53 + 1) {
			fRec6[l53] = 0.0f;
		}
		for (int l54 = 0; l54 < 3; l54 = l54 + 1) {
			fRec7[l54] = 0.0f;
		}
		for (int l55 = 0; l55 < 3; l55 = l55 + 1) {
			fRec8[l55] = 0.0f;
		}
		for (int l56 = 0; l56 < 3; l56 = l56 + 1) {
			fRec9[l56] = 0.0f;
		}
		for (int l57 = 0; l57 < 3; l57 = l57 + 1) {
			fRec1[l57] = 0.0f;
		}
		for (int l58 = 0; l58 < 3; l58 = l58 + 1) {
			fRec0[l58] = 0.0f;
		}
		for (int l59 = 0; l59 < 2; l59 = l59 + 1) {
			fRec47[l59] = 0.0f;
		}
		for (int l60 = 0; l60 < 2; l60 = l60 + 1) {
			fRec48[l60] = 0.0f;
		}
		for (int l61 = 0; l61 < 3; l61 = l61 + 1) {
			fRec50[l61] = 0.0f;
		}
		for (int l62 = 0; l62 < 3; l62 = l62 + 1) {
			fRec49[l62] = 0.0f;
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
		ui_interface->declare(0, "0", "");
		ui_interface->declare(0, "tooltip", "~ ZITA REV1 FEEDBACK DELAY NETWORK (FDN) & SCHROEDER     ALLPASS-COMB REVERBERATOR (8x8). See Faust's reverbs.lib for documentation and     references");
		ui_interface->openHorizontalBox("Zita_Rev1");
		ui_interface->declare(0, "1", "");
		ui_interface->openHorizontalBox("Input");
		ui_interface->declare(&fVslider8, "1", "");
		ui_interface->declare(&fVslider8, "style", "knob");
		ui_interface->declare(&fVslider8, "tooltip", "Delay in ms         before reverberation begins");
		ui_interface->declare(&fVslider8, "unit", "ms");
		ui_interface->addVerticalSlider("In Delay", &fVslider8, FAUSTFLOAT(6e+01f), FAUSTFLOAT(2e+01f), FAUSTFLOAT(1e+02f), FAUSTFLOAT(1.0f));
		ui_interface->closeBox();
		ui_interface->declare(0, "2", "");
		ui_interface->openHorizontalBox("Decay Times in Bands (see tooltips)");
		ui_interface->declare(&fVslider6, "1", "");
		ui_interface->declare(&fVslider6, "scale", "log");
		ui_interface->declare(&fVslider6, "style", "knob");
		ui_interface->declare(&fVslider6, "tooltip", "Crossover frequency (Hz) separating low and middle frequencies");
		ui_interface->declare(&fVslider6, "unit", "Hz");
		ui_interface->addVerticalSlider("LF X", &fVslider6, FAUSTFLOAT(2e+02f), FAUSTFLOAT(5e+01f), FAUSTFLOAT(1e+03f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fVslider7, "2", "");
		ui_interface->declare(&fVslider7, "scale", "log");
		ui_interface->declare(&fVslider7, "style", "knob");
		ui_interface->declare(&fVslider7, "tooltip", "T60 = time (in seconds) to decay 60dB in low-frequency band");
		ui_interface->declare(&fVslider7, "unit", "s");
		ui_interface->addVerticalSlider("Low RT60", &fVslider7, FAUSTFLOAT(3.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(8.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fVslider4, "3", "");
		ui_interface->declare(&fVslider4, "scale", "log");
		ui_interface->declare(&fVslider4, "style", "knob");
		ui_interface->declare(&fVslider4, "tooltip", "T60 = time (in seconds) to decay 60dB in middle band");
		ui_interface->declare(&fVslider4, "unit", "s");
		ui_interface->addVerticalSlider("Mid RT60", &fVslider4, FAUSTFLOAT(2.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(8.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fVslider5, "4", "");
		ui_interface->declare(&fVslider5, "scale", "log");
		ui_interface->declare(&fVslider5, "style", "knob");
		ui_interface->declare(&fVslider5, "tooltip", "Frequency (Hz) at which the high-frequency T60 is half the middle-band's T60");
		ui_interface->declare(&fVslider5, "unit", "Hz");
		ui_interface->addVerticalSlider("HF Damping", &fVslider5, FAUSTFLOAT(6e+03f), FAUSTFLOAT(1.5e+03f), FAUSTFLOAT(2.352e+04f), FAUSTFLOAT(1.0f));
		ui_interface->closeBox();
		ui_interface->declare(0, "3", "");
		ui_interface->openHorizontalBox("RM Peaking Equalizer 1");
		ui_interface->declare(&fVslider3, "1", "");
		ui_interface->declare(&fVslider3, "scale", "log");
		ui_interface->declare(&fVslider3, "style", "knob");
		ui_interface->declare(&fVslider3, "tooltip", "Center-frequency of second-order Regalia-Mitra peaking equalizer section 1");
		ui_interface->declare(&fVslider3, "unit", "Hz");
		ui_interface->addVerticalSlider("Eq1 Freq", &fVslider3, FAUSTFLOAT(315.0f), FAUSTFLOAT(4e+01f), FAUSTFLOAT(2.5e+03f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fVslider2, "2", "");
		ui_interface->declare(&fVslider2, "style", "knob");
		ui_interface->declare(&fVslider2, "tooltip", "Peak level         in dB of second-order Regalia-Mitra peaking equalizer section 1");
		ui_interface->declare(&fVslider2, "unit", "dB");
		ui_interface->addVerticalSlider("Eq1 Level", &fVslider2, FAUSTFLOAT(0.0f), FAUSTFLOAT(-15.0f), FAUSTFLOAT(15.0f), FAUSTFLOAT(0.1f));
		ui_interface->closeBox();
		ui_interface->declare(0, "4", "");
		ui_interface->openHorizontalBox("RM Peaking Equalizer 2");
		ui_interface->declare(&fVslider1, "1", "");
		ui_interface->declare(&fVslider1, "scale", "log");
		ui_interface->declare(&fVslider1, "style", "knob");
		ui_interface->declare(&fVslider1, "tooltip", "Center-frequency of second-order Regalia-Mitra peaking equalizer section 2");
		ui_interface->declare(&fVslider1, "unit", "Hz");
		ui_interface->addVerticalSlider("Eq2 Freq", &fVslider1, FAUSTFLOAT(1.5e+03f), FAUSTFLOAT(1.6e+02f), FAUSTFLOAT(1e+04f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fVslider0, "2", "");
		ui_interface->declare(&fVslider0, "style", "knob");
		ui_interface->declare(&fVslider0, "tooltip", "Peak level         in dB of second-order Regalia-Mitra peaking equalizer section 2");
		ui_interface->declare(&fVslider0, "unit", "dB");
		ui_interface->addVerticalSlider("Eq2 Level", &fVslider0, FAUSTFLOAT(0.0f), FAUSTFLOAT(-15.0f), FAUSTFLOAT(15.0f), FAUSTFLOAT(0.1f));
		ui_interface->closeBox();
		ui_interface->declare(0, "5", "");
		ui_interface->openHorizontalBox("Output");
		ui_interface->declare(&fVslider9, "1", "");
		ui_interface->declare(&fVslider9, "style", "knob");
		ui_interface->declare(&fVslider9, "tooltip", "-1 = dry, 1 = wet");
		ui_interface->addVerticalSlider("Dry/Wet Mix", &fVslider9, FAUSTFLOAT(0.0f), FAUSTFLOAT(-1.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fVslider10, "2", "");
		ui_interface->declare(&fVslider10, "style", "knob");
		ui_interface->declare(&fVslider10, "tooltip", "Output scale         factor");
		ui_interface->declare(&fVslider10, "unit", "dB");
		ui_interface->addVerticalSlider("Level", &fVslider10, FAUSTFLOAT(-2e+01f), FAUSTFLOAT(-7e+01f), FAUSTFLOAT(4e+01f), FAUSTFLOAT(0.1f));
		ui_interface->closeBox();
		ui_interface->closeBox();
		ui_interface->addHorizontalSlider("carrierFreq", &fHslider2, FAUSTFLOAT(4.4e+02f), FAUSTFLOAT(2e+01f), FAUSTFLOAT(2e+04f), FAUSTFLOAT(1.0f));
		ui_interface->addHorizontalSlider("dry", &fHslider3, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("index", &fHslider1, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1e+01f), FAUSTFLOAT(0.01f));
		ui_interface->addHorizontalSlider("modulatorFreq", &fHslider0, FAUSTFLOAT(2.2e+02f), FAUSTFLOAT(2e+01f), FAUSTFLOAT(2e+04f), FAUSTFLOAT(1.0f));
		ui_interface->addHorizontalSlider("wet", &fHslider4, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		FAUSTFLOAT* output2 = outputs[2];
		FAUSTFLOAT* output3 = outputs[3];
		float fSlow0 = std::pow(1e+01f, 0.05f * float(fVslider0));
		float fSlow1 = float(fVslider1);
		float fSlow2 = fConst1 * (fSlow1 / std::sqrt(std::max<float>(0.0f, fSlow0)));
		float fSlow3 = (1.0f - fSlow2) / (fSlow2 + 1.0f);
		float fSlow4 = std::cos(fConst1 * fSlow1) * (fSlow3 + 1.0f);
		float fSlow5 = std::pow(1e+01f, 0.05f * float(fVslider2));
		float fSlow6 = float(fVslider3);
		float fSlow7 = fConst1 * (fSlow6 / std::sqrt(std::max<float>(0.0f, fSlow5)));
		float fSlow8 = (1.0f - fSlow7) / (fSlow7 + 1.0f);
		float fSlow9 = std::cos(fConst1 * fSlow6) * (fSlow8 + 1.0f);
		float fSlow10 = float(fVslider4);
		float fSlow11 = std::exp(-(fConst3 / fSlow10));
		float fSlow12 = mydsp_faustpower2_f(fSlow11);
		float fSlow13 = 1.0f - fSlow12;
		float fSlow14 = std::cos(fConst1 * float(fVslider5));
		float fSlow15 = 1.0f - fSlow14 * fSlow12;
		float fSlow16 = std::sqrt(std::max<float>(0.0f, mydsp_faustpower2_f(fSlow15) / mydsp_faustpower2_f(fSlow13) + -1.0f));
		float fSlow17 = fSlow15 / fSlow13;
		float fSlow18 = fSlow17 - fSlow16;
		float fSlow19 = 1.0f / std::tan(fConst4 * float(fVslider6));
		float fSlow20 = 1.0f - fSlow19;
		float fSlow21 = 1.0f / (fSlow19 + 1.0f);
		float fSlow22 = float(fVslider7);
		float fSlow23 = std::exp(-(fConst3 / fSlow22)) / fSlow11 + -1.0f;
		float fSlow24 = fSlow11 * (fSlow16 + (1.0f - fSlow17));
		float fSlow25 = float(fButton0);
		int iSlow26 = fSlow25 == 0.0f;
		float fSlow27 = fConst10 * float(fHslider0);
		float fSlow28 = float(fHslider1);
		float fSlow29 = float(fHslider2);
		int iSlow30 = int(std::min<float>(8192.0f, std::max<float>(0.0f, fConst11 * float(fVslider8))));
		float fSlow31 = std::exp(-(fConst14 / fSlow10));
		float fSlow32 = mydsp_faustpower2_f(fSlow31);
		float fSlow33 = 1.0f - fSlow32;
		float fSlow34 = 1.0f - fSlow32 * fSlow14;
		float fSlow35 = std::sqrt(std::max<float>(0.0f, mydsp_faustpower2_f(fSlow34) / mydsp_faustpower2_f(fSlow33) + -1.0f));
		float fSlow36 = fSlow34 / fSlow33;
		float fSlow37 = fSlow36 - fSlow35;
		float fSlow38 = std::exp(-(fConst14 / fSlow22)) / fSlow31 + -1.0f;
		float fSlow39 = fSlow31 * (fSlow35 + (1.0f - fSlow36));
		float fSlow40 = std::exp(-(fConst19 / fSlow10));
		float fSlow41 = mydsp_faustpower2_f(fSlow40);
		float fSlow42 = 1.0f - fSlow41;
		float fSlow43 = 1.0f - fSlow14 * fSlow41;
		float fSlow44 = std::sqrt(std::max<float>(0.0f, mydsp_faustpower2_f(fSlow43) / mydsp_faustpower2_f(fSlow42) + -1.0f));
		float fSlow45 = fSlow43 / fSlow42;
		float fSlow46 = fSlow45 - fSlow44;
		float fSlow47 = std::exp(-(fConst19 / fSlow22)) / fSlow40 + -1.0f;
		float fSlow48 = fSlow40 * (fSlow44 + (1.0f - fSlow45));
		float fSlow49 = std::exp(-(fConst24 / fSlow10));
		float fSlow50 = mydsp_faustpower2_f(fSlow49);
		float fSlow51 = 1.0f - fSlow50;
		float fSlow52 = 1.0f - fSlow14 * fSlow50;
		float fSlow53 = std::sqrt(std::max<float>(0.0f, mydsp_faustpower2_f(fSlow52) / mydsp_faustpower2_f(fSlow51) + -1.0f));
		float fSlow54 = fSlow52 / fSlow51;
		float fSlow55 = fSlow54 - fSlow53;
		float fSlow56 = std::exp(-(fConst24 / fSlow22)) / fSlow49 + -1.0f;
		float fSlow57 = fSlow49 * (fSlow53 + (1.0f - fSlow54));
		float fSlow58 = std::exp(-(fConst29 / fSlow10));
		float fSlow59 = mydsp_faustpower2_f(fSlow58);
		float fSlow60 = 1.0f - fSlow59;
		float fSlow61 = 1.0f - fSlow14 * fSlow59;
		float fSlow62 = std::sqrt(std::max<float>(0.0f, mydsp_faustpower2_f(fSlow61) / mydsp_faustpower2_f(fSlow60) + -1.0f));
		float fSlow63 = fSlow61 / fSlow60;
		float fSlow64 = fSlow63 - fSlow62;
		float fSlow65 = std::exp(-(fConst29 / fSlow22)) / fSlow58 + -1.0f;
		float fSlow66 = fSlow58 * (fSlow62 + (1.0f - fSlow63));
		float fSlow67 = std::exp(-(fConst34 / fSlow10));
		float fSlow68 = mydsp_faustpower2_f(fSlow67);
		float fSlow69 = 1.0f - fSlow68;
		float fSlow70 = 1.0f - fSlow14 * fSlow68;
		float fSlow71 = std::sqrt(std::max<float>(0.0f, mydsp_faustpower2_f(fSlow70) / mydsp_faustpower2_f(fSlow69) + -1.0f));
		float fSlow72 = fSlow70 / fSlow69;
		float fSlow73 = fSlow72 - fSlow71;
		float fSlow74 = std::exp(-(fConst34 / fSlow22)) / fSlow67 + -1.0f;
		float fSlow75 = fSlow67 * (fSlow71 + (1.0f - fSlow72));
		float fSlow76 = std::exp(-(fConst39 / fSlow10));
		float fSlow77 = mydsp_faustpower2_f(fSlow76);
		float fSlow78 = 1.0f - fSlow77;
		float fSlow79 = 1.0f - fSlow14 * fSlow77;
		float fSlow80 = std::sqrt(std::max<float>(0.0f, mydsp_faustpower2_f(fSlow79) / mydsp_faustpower2_f(fSlow78) + -1.0f));
		float fSlow81 = fSlow79 / fSlow78;
		float fSlow82 = fSlow81 - fSlow80;
		float fSlow83 = std::exp(-(fConst39 / fSlow22)) / fSlow76 + -1.0f;
		float fSlow84 = fSlow76 * (fSlow80 + (1.0f - fSlow81));
		float fSlow85 = std::exp(-(fConst44 / fSlow10));
		float fSlow86 = mydsp_faustpower2_f(fSlow85);
		float fSlow87 = 1.0f - fSlow86;
		float fSlow88 = 1.0f - fSlow14 * fSlow86;
		float fSlow89 = std::sqrt(std::max<float>(0.0f, mydsp_faustpower2_f(fSlow88) / mydsp_faustpower2_f(fSlow87) + -1.0f));
		float fSlow90 = fSlow88 / fSlow87;
		float fSlow91 = fSlow90 - fSlow89;
		float fSlow92 = std::exp(-(fConst44 / fSlow22)) / fSlow85 + -1.0f;
		float fSlow93 = fSlow85 * (fSlow89 + (1.0f - fSlow90));
		float fSlow94 = fConst48 * float(fVslider9);
		float fSlow95 = fConst48 * std::pow(1e+01f, 0.05f * float(fVslider10));
		float fSlow96 = float(fHslider3);
		float fSlow97 = float(fHslider4);
		for (int i0 = 0; i0 < count; i0 = i0 + 1) {
			iVec0[0] = 1;
			float fTemp0 = fSlow4 * fRec0[1];
			float fTemp1 = fSlow9 * fRec1[1];
			fRec13[0] = -(fSlow21 * (fSlow20 * fRec13[1] - (fRec6[1] + fRec6[2])));
			fRec12[0] = fSlow24 * (fRec6[1] + fSlow23 * fRec13[0]) + fSlow18 * fRec12[1];
			fVec1[IOTA0 & 16383] = 0.35355338f * fRec12[0] + 1e-20f;
			fVec2[0] = fSlow25;
			iRec14[0] = iSlow26 * (iRec14[1] + 1);
			fRec15[0] = fSlow25 + fRec15[1] * float(fVec2[1] >= fSlow25);
			float fTemp2 = std::max<float>(0.0f, std::min<float>(fConst8 * fRec15[0], std::max<float>(fConst9 * (fConst7 - fRec15[0]) + 1.0f, 0.0f)) * (1.0f - fConst8 * float(iRec14[0])));
			int iTemp3 = 1 - iVec0[1];
			float fTemp4 = ((iTemp3) ? 0.0f : fSlow27 + fRec18[1]);
			fRec18[0] = fTemp4 - std::floor(fTemp4);
			float fTemp5 = ((iTemp3) ? 0.0f : fRec17[1] + fConst10 * (fSlow29 + fSlow28 * ftbl0mydspSIG0[std::max<int>(0, std::min<int>(int(65536.0f * fRec18[0]), 65535))]));
			fRec17[0] = fTemp5 - std::floor(fTemp5);
			float fTemp6 = ftbl0mydspSIG0[std::max<int>(0, std::min<int>(int(65536.0f * fRec17[0]), 65535))];
			fVec4[IOTA0 & 16383] = fTemp6 * fTemp2;
			float fTemp7 = 0.3f * fVec4[(IOTA0 - iSlow30) & 16383];
			float fTemp8 = fTemp7 + fVec1[(IOTA0 - iConst6) & 16383] - 0.6f * fRec10[1];
			fVec5[IOTA0 & 4095] = fTemp8;
			fRec10[0] = fVec5[(IOTA0 - iConst12) & 4095];
			float fRec11 = 0.6f * fTemp8;
			fRec22[0] = -(fSlow21 * (fSlow20 * fRec22[1] - (fRec2[1] + fRec2[2])));
			fRec21[0] = fSlow39 * (fRec2[1] + fSlow38 * fRec22[0]) + fSlow37 * fRec21[1];
			fVec6[IOTA0 & 16383] = 0.35355338f * fRec21[0] + 1e-20f;
			float fTemp9 = fVec6[(IOTA0 - iConst16) & 16383] + fTemp7 - 0.6f * fRec19[1];
			fVec7[IOTA0 & 2047] = fTemp9;
			fRec19[0] = fVec7[(IOTA0 - iConst17) & 2047];
			float fRec20 = 0.6f * fTemp9;
			float fTemp10 = fRec20 + fRec11;
			fRec26[0] = -(fSlow21 * (fSlow20 * fRec26[1] - (fRec4[1] + fRec4[2])));
			fRec25[0] = fSlow48 * (fRec4[1] + fSlow47 * fRec26[0]) + fSlow46 * fRec25[1];
			fVec8[IOTA0 & 16383] = 0.35355338f * fRec25[0] + 1e-20f;
			float fTemp11 = fVec8[(IOTA0 - iConst21) & 16383] - (fTemp7 + 0.6f * fRec23[1]);
			fVec9[IOTA0 & 4095] = fTemp11;
			fRec23[0] = fVec9[(IOTA0 - iConst22) & 4095];
			float fRec24 = 0.6f * fTemp11;
			fRec30[0] = -(fSlow21 * (fSlow20 * fRec30[1] - (fRec8[1] + fRec8[2])));
			fRec29[0] = fSlow57 * (fRec8[1] + fSlow56 * fRec30[0]) + fSlow55 * fRec29[1];
			fVec10[IOTA0 & 16383] = 0.35355338f * fRec29[0] + 1e-20f;
			float fTemp12 = fVec10[(IOTA0 - iConst26) & 16383] - (fTemp7 + 0.6f * fRec27[1]);
			fVec11[IOTA0 & 2047] = fTemp12;
			fRec27[0] = fVec11[(IOTA0 - iConst27) & 2047];
			float fRec28 = 0.6f * fTemp12;
			float fTemp13 = fRec28 + fRec24 + fTemp10;
			fRec34[0] = -(fSlow21 * (fSlow20 * fRec34[1] - (fRec3[1] + fRec3[2])));
			fRec33[0] = fSlow66 * (fRec3[1] + fSlow65 * fRec34[0]) + fSlow64 * fRec33[1];
			fVec12[IOTA0 & 32767] = 0.35355338f * fRec33[0] + 1e-20f;
			float fTemp14 = fVec12[(IOTA0 - iConst31) & 32767] + fTemp7 + 0.6f * fRec31[1];
			fVec13[IOTA0 & 4095] = fTemp14;
			fRec31[0] = fVec13[(IOTA0 - iConst32) & 4095];
			float fRec32 = -(0.6f * fTemp14);
			fRec38[0] = -(fSlow21 * (fSlow20 * fRec38[1] - (fRec7[1] + fRec7[2])));
			fRec37[0] = fSlow75 * (fRec7[1] + fSlow74 * fRec38[0]) + fSlow73 * fRec37[1];
			fVec14[IOTA0 & 16383] = 0.35355338f * fRec37[0] + 1e-20f;
			float fTemp15 = fVec14[(IOTA0 - iConst36) & 16383] + fTemp7 + 0.6f * fRec35[1];
			fVec15[IOTA0 & 4095] = fTemp15;
			fRec35[0] = fVec15[(IOTA0 - iConst37) & 4095];
			float fRec36 = -(0.6f * fTemp15);
			fRec42[0] = -(fSlow21 * (fSlow20 * fRec42[1] - (fRec5[1] + fRec5[2])));
			fRec41[0] = fSlow84 * (fRec5[1] + fSlow83 * fRec42[0]) + fSlow82 * fRec41[1];
			fVec16[IOTA0 & 32767] = 0.35355338f * fRec41[0] + 1e-20f;
			float fTemp16 = 0.6f * fRec39[1] + fVec16[(IOTA0 - iConst41) & 32767];
			fVec17[IOTA0 & 4095] = fTemp16 - fTemp7;
			fRec39[0] = fVec17[(IOTA0 - iConst42) & 4095];
			float fRec40 = 0.6f * (fTemp7 - fTemp16);
			fRec46[0] = -(fSlow21 * (fSlow20 * fRec46[1] - (fRec9[1] + fRec9[2])));
			fRec45[0] = fSlow93 * (fRec9[1] + fSlow92 * fRec46[0]) + fSlow91 * fRec45[1];
			fVec18[IOTA0 & 32767] = 0.35355338f * fRec45[0] + 1e-20f;
			float fTemp17 = 0.6f * fRec43[1] + fVec18[(IOTA0 - iConst46) & 32767];
			fVec19[IOTA0 & 2047] = fTemp17 - fTemp7;
			fRec43[0] = fVec19[(IOTA0 - iConst47) & 2047];
			float fRec44 = 0.6f * (fTemp7 - fTemp17);
			fRec2[0] = fRec43[1] + fRec39[1] + fRec35[1] + fRec31[1] + fRec27[1] + fRec23[1] + fRec10[1] + fRec19[1] + fRec44 + fRec40 + fRec36 + fRec32 + fTemp13;
			fRec3[0] = fRec27[1] + fRec23[1] + fRec10[1] + fRec19[1] + fTemp13 - (fRec43[1] + fRec39[1] + fRec35[1] + fRec31[1] + fRec44 + fRec40 + fRec32 + fRec36);
			float fTemp18 = fRec24 + fRec28;
			fRec4[0] = fRec35[1] + fRec31[1] + fRec10[1] + fRec19[1] + fRec36 + fRec32 + fTemp10 - (fRec43[1] + fRec39[1] + fRec27[1] + fRec23[1] + fRec44 + fRec40 + fTemp18);
			fRec5[0] = fRec43[1] + fRec39[1] + fRec10[1] + fRec19[1] + fRec44 + fRec40 + fTemp10 - (fRec35[1] + fRec31[1] + fRec27[1] + fRec23[1] + fRec36 + fRec32 + fTemp18);
			float fTemp19 = fRec11 + fRec28;
			float fTemp20 = fRec20 + fRec24;
			fRec6[0] = fRec39[1] + fRec31[1] + fRec23[1] + fRec19[1] + fRec40 + fRec32 + fTemp20 - (fRec43[1] + fRec35[1] + fRec27[1] + fRec10[1] + fRec44 + fRec36 + fTemp19);
			fRec7[0] = fRec43[1] + fRec35[1] + fRec23[1] + fRec19[1] + fRec44 + fRec36 + fTemp20 - (fRec39[1] + fRec31[1] + fRec27[1] + fRec10[1] + fRec40 + fRec32 + fTemp19);
			float fTemp21 = fRec11 + fRec24;
			float fTemp22 = fRec20 + fRec28;
			fRec8[0] = fRec43[1] + fRec31[1] + fRec27[1] + fRec19[1] + fRec44 + fRec32 + fTemp22 - (fRec39[1] + fRec35[1] + fRec23[1] + fRec10[1] + fRec40 + fRec36 + fTemp21);
			fRec9[0] = fRec39[1] + fRec35[1] + fRec27[1] + fRec19[1] + fRec40 + fRec36 + fTemp22 - (fRec43[1] + fRec31[1] + fRec23[1] + fRec10[1] + fRec44 + fRec32 + fTemp21);
			float fTemp23 = 0.37f * (fRec3[0] + fRec4[0]);
			float fTemp24 = fTemp23 + fTemp1;
			fRec1[0] = fTemp24 - fSlow8 * fRec1[2];
			float fTemp25 = fSlow8 * fRec1[0];
			float fTemp26 = fSlow5 * (fRec1[2] + fTemp25 - fTemp24);
			float fTemp27 = fTemp25 + fTemp23 + fRec1[2];
			fRec0[0] = 0.5f * (fTemp27 - fTemp1 + fTemp26) + fTemp0 - fSlow3 * fRec0[2];
			float fTemp28 = 0.5f * (fTemp27 + fTemp26 - fTemp1);
			float fTemp29 = fRec0[2] + fSlow3 * fRec0[0];
			fRec47[0] = fSlow94 + fConst49 * fRec47[1];
			float fTemp30 = fRec47[0] + 1.0f;
			float fTemp31 = 1.0f - 0.5f * fTemp30;
			float fTemp32 = fTemp30 * fTemp6 * fTemp2;
			fRec48[0] = fSlow95 + fConst49 * fRec48[1];
			output0[i0] = FAUSTFLOAT(0.5f * fRec48[0] * (fTemp32 + fTemp31 * (fTemp29 + fTemp28 + fSlow0 * (fTemp29 - (fTemp0 + fTemp28)) - fTemp0)));
			float fTemp33 = fSlow4 * fRec49[1];
			float fTemp34 = fSlow9 * fRec50[1];
			float fTemp35 = 0.37f * (fRec3[0] - fRec4[0]);
			float fTemp36 = fTemp35 + fTemp34;
			fRec50[0] = fTemp36 - fSlow8 * fRec50[2];
			float fTemp37 = fSlow8 * fRec50[0];
			float fTemp38 = fSlow5 * (fRec50[2] + fTemp37 - fTemp36);
			float fTemp39 = fTemp37 + fTemp35 + fRec50[2];
			fRec49[0] = 0.5f * (fTemp39 - fTemp34 + fTemp38) + fTemp33 - fSlow3 * fRec49[2];
			float fTemp40 = 0.5f * (fTemp39 + fTemp38 - fTemp34);
			float fTemp41 = fRec49[2] + fSlow3 * fRec49[0];
			output1[i0] = FAUSTFLOAT(0.5f * fRec48[0] * (fTemp32 + fTemp31 * (fTemp41 + fTemp40 + fSlow0 * (fTemp41 - (fTemp33 + fTemp40)) - fTemp33)));
			output2[i0] = FAUSTFLOAT(fSlow96);
			output3[i0] = FAUSTFLOAT(fSlow97);
			iVec0[1] = iVec0[0];
			fRec13[1] = fRec13[0];
			fRec12[1] = fRec12[0];
			IOTA0 = IOTA0 + 1;
			fVec2[1] = fVec2[0];
			iRec14[1] = iRec14[0];
			fRec15[1] = fRec15[0];
			fRec18[1] = fRec18[0];
			fRec17[1] = fRec17[0];
			fRec10[1] = fRec10[0];
			fRec22[1] = fRec22[0];
			fRec21[1] = fRec21[0];
			fRec19[1] = fRec19[0];
			fRec26[1] = fRec26[0];
			fRec25[1] = fRec25[0];
			fRec23[1] = fRec23[0];
			fRec30[1] = fRec30[0];
			fRec29[1] = fRec29[0];
			fRec27[1] = fRec27[0];
			fRec34[1] = fRec34[0];
			fRec33[1] = fRec33[0];
			fRec31[1] = fRec31[0];
			fRec38[1] = fRec38[0];
			fRec37[1] = fRec37[0];
			fRec35[1] = fRec35[0];
			fRec42[1] = fRec42[0];
			fRec41[1] = fRec41[0];
			fRec39[1] = fRec39[0];
			fRec46[1] = fRec46[0];
			fRec45[1] = fRec45[0];
			fRec43[1] = fRec43[0];
			fRec2[2] = fRec2[1];
			fRec2[1] = fRec2[0];
			fRec3[2] = fRec3[1];
			fRec3[1] = fRec3[0];
			fRec4[2] = fRec4[1];
			fRec4[1] = fRec4[0];
			fRec5[2] = fRec5[1];
			fRec5[1] = fRec5[0];
			fRec6[2] = fRec6[1];
			fRec6[1] = fRec6[0];
			fRec7[2] = fRec7[1];
			fRec7[1] = fRec7[0];
			fRec8[2] = fRec8[1];
			fRec8[1] = fRec8[0];
			fRec9[2] = fRec9[1];
			fRec9[1] = fRec9[0];
			fRec1[2] = fRec1[1];
			fRec1[1] = fRec1[0];
			fRec0[2] = fRec0[1];
			fRec0[1] = fRec0[0];
			fRec47[1] = fRec47[0];
			fRec48[1] = fRec48[0];
			fRec50[2] = fRec50[1];
			fRec50[1] = fRec50[0];
			fRec49[2] = fRec49[1];
			fRec49[1] = fRec49[0];
		}
	}

};

#endif
