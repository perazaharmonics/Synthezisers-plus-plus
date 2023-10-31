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
	
	int iVec2[2];
	int iRec12[2];
	
  public:
	
	int getNumInputsmydspSIG0() {
		return 0;
	}
	int getNumOutputsmydspSIG0() {
		return 1;
	}
	
	void instanceInitmydspSIG0(int sample_rate) {
		for (int l4 = 0; l4 < 2; l4 = l4 + 1) {
			iVec2[l4] = 0;
		}
		for (int l5 = 0; l5 < 2; l5 = l5 + 1) {
			iRec12[l5] = 0;
		}
	}
	
	void fillmydspSIG0(int count, float* table) {
		for (int i1 = 0; i1 < count; i1 = i1 + 1) {
			iVec2[0] = 1;
			iRec12[0] = (iVec2[1] + iRec12[1]) % 65536;
			table[i1] = std::sin(9.58738e-05f * float(iRec12[0]));
			iVec2[1] = iVec2[0];
			iRec12[1] = iRec12[0];
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
	
	int iVec0[2];
	FAUSTFLOAT fVslider0;
	int fSampleRate;
	float fConst2;
	FAUSTFLOAT fVslider1;
	float fConst3;
	FAUSTFLOAT fVslider2;
	float fConst4;
	float fRec11[2];
	FAUSTFLOAT fVslider3;
	float fRec10[2];
	int IOTA0;
	float fVec1[16384];
	int iConst6;
	FAUSTFLOAT fHslider0;
	float fConst7;
	float fRec13[2];
	FAUSTFLOAT fHslider1;
	float fRec15[2];
	FAUSTFLOAT fHslider2;
	FAUSTFLOAT fHslider3;
	float fRec14[2];
	FAUSTFLOAT fHslider4;
	float fVec3[16384];
	FAUSTFLOAT fVslider4;
	float fConst8;
	float fVec4[4096];
	int iConst9;
	float fRec8[2];
	float fConst11;
	float fRec19[2];
	float fRec18[2];
	float fVec5[16384];
	int iConst13;
	float fVec6[2048];
	int iConst14;
	float fRec16[2];
	float fConst16;
	float fRec23[2];
	float fRec22[2];
	float fVec7[16384];
	int iConst18;
	float fVec8[4096];
	int iConst19;
	float fRec20[2];
	float fConst21;
	float fRec27[2];
	float fRec26[2];
	float fVec9[16384];
	int iConst23;
	float fVec10[2048];
	int iConst24;
	float fRec24[2];
	float fConst26;
	float fRec31[2];
	float fRec30[2];
	float fVec11[32768];
	int iConst28;
	float fVec12[4096];
	int iConst29;
	float fRec28[2];
	float fConst31;
	float fRec35[2];
	float fRec34[2];
	float fVec13[16384];
	int iConst33;
	float fVec14[4096];
	int iConst34;
	float fRec32[2];
	float fConst36;
	float fRec39[2];
	float fRec38[2];
	float fVec15[32768];
	int iConst38;
	float fVec16[4096];
	int iConst39;
	float fRec36[2];
	float fConst41;
	float fRec43[2];
	float fRec42[2];
	float fVec17[32768];
	int iConst43;
	float fVec18[2048];
	int iConst44;
	float fRec40[2];
	float fRec0[3];
	float fRec1[3];
	float fRec2[3];
	float fRec3[3];
	float fRec4[3];
	float fRec5[3];
	float fRec6[3];
	float fRec7[3];
	FAUSTFLOAT fVslider5;
	FAUSTFLOAT fVslider6;
	float fRec44[3];
	FAUSTFLOAT fVslider7;
	FAUSTFLOAT fVslider8;
	float fRec45[3];
	float fConst45;
	float fConst46;
	FAUSTFLOAT fVslider9;
	float fRec46[2];
	FAUSTFLOAT fVslider10;
	float fRec47[2];
	float fRec48[3];
	float fRec49[3];
	
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
		m->declare("filename", "untitled.dsp");
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
		m->declare("reverbs.lib/name", "Faust Reverb Library");
		m->declare("reverbs.lib/version", "1.2.0");
		m->declare("routes.lib/hadamard:author", "Remy Muller, revised by Romain Michon");
		m->declare("routes.lib/name", "Faust Signal Routing Library");
		m->declare("routes.lib/version", "1.2.0");
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
		float fConst1 = std::floor(0.174713f * fConst0 + 0.5f);
		fConst2 = (0.0f - 6.9077554f * fConst1) / fConst0;
		fConst3 = 6.2831855f / fConst0;
		fConst4 = 3.1415927f / fConst0;
		float fConst5 = std::floor(0.022904f * fConst0 + 0.5f);
		iConst6 = int(std::min<float>(8192.0f, std::max<float>(0.0f, fConst1 - fConst5)));
		fConst7 = 1.0f / fConst0;
		fConst8 = 0.001f * fConst0;
		iConst9 = int(std::min<float>(2048.0f, std::max<float>(0.0f, fConst5 + -1.0f)));
		float fConst10 = std::floor(0.153129f * fConst0 + 0.5f);
		fConst11 = (0.0f - 6.9077554f * fConst10) / fConst0;
		float fConst12 = std::floor(0.020346f * fConst0 + 0.5f);
		iConst13 = int(std::min<float>(8192.0f, std::max<float>(0.0f, fConst10 - fConst12)));
		iConst14 = int(std::min<float>(1024.0f, std::max<float>(0.0f, fConst12 + -1.0f)));
		float fConst15 = std::floor(0.127837f * fConst0 + 0.5f);
		fConst16 = (0.0f - 6.9077554f * fConst15) / fConst0;
		float fConst17 = std::floor(0.031604f * fConst0 + 0.5f);
		iConst18 = int(std::min<float>(8192.0f, std::max<float>(0.0f, fConst15 - fConst17)));
		iConst19 = int(std::min<float>(2048.0f, std::max<float>(0.0f, fConst17 + -1.0f)));
		float fConst20 = std::floor(0.125f * fConst0 + 0.5f);
		fConst21 = (0.0f - 6.9077554f * fConst20) / fConst0;
		float fConst22 = std::floor(0.013458f * fConst0 + 0.5f);
		iConst23 = int(std::min<float>(8192.0f, std::max<float>(0.0f, fConst20 - fConst22)));
		iConst24 = int(std::min<float>(1024.0f, std::max<float>(0.0f, fConst22 + -1.0f)));
		float fConst25 = std::floor(0.210389f * fConst0 + 0.5f);
		fConst26 = (0.0f - 6.9077554f * fConst25) / fConst0;
		float fConst27 = std::floor(0.024421f * fConst0 + 0.5f);
		iConst28 = int(std::min<float>(16384.0f, std::max<float>(0.0f, fConst25 - fConst27)));
		iConst29 = int(std::min<float>(2048.0f, std::max<float>(0.0f, fConst27 + -1.0f)));
		float fConst30 = std::floor(0.192303f * fConst0 + 0.5f);
		fConst31 = (0.0f - 6.9077554f * fConst30) / fConst0;
		float fConst32 = std::floor(0.029291f * fConst0 + 0.5f);
		iConst33 = int(std::min<float>(8192.0f, std::max<float>(0.0f, fConst30 - fConst32)));
		iConst34 = int(std::min<float>(2048.0f, std::max<float>(0.0f, fConst32 + -1.0f)));
		float fConst35 = std::floor(0.256891f * fConst0 + 0.5f);
		fConst36 = (0.0f - 6.9077554f * fConst35) / fConst0;
		float fConst37 = std::floor(0.027333f * fConst0 + 0.5f);
		iConst38 = int(std::min<float>(16384.0f, std::max<float>(0.0f, fConst35 - fConst37)));
		iConst39 = int(std::min<float>(2048.0f, std::max<float>(0.0f, fConst37 + -1.0f)));
		float fConst40 = std::floor(0.219991f * fConst0 + 0.5f);
		fConst41 = (0.0f - 6.9077554f * fConst40) / fConst0;
		float fConst42 = std::floor(0.019123f * fConst0 + 0.5f);
		iConst43 = int(std::min<float>(16384.0f, std::max<float>(0.0f, fConst40 - fConst42)));
		iConst44 = int(std::min<float>(1024.0f, std::max<float>(0.0f, fConst42 + -1.0f)));
		fConst45 = 44.1f / fConst0;
		fConst46 = 1.0f - fConst45;
	}
	
	virtual void instanceResetUserInterface() {
		fVslider0 = FAUSTFLOAT(2.0f);
		fVslider1 = FAUSTFLOAT(6e+03f);
		fVslider2 = FAUSTFLOAT(2e+02f);
		fVslider3 = FAUSTFLOAT(3.0f);
		fHslider0 = FAUSTFLOAT(1.0f);
		fHslider1 = FAUSTFLOAT(2.2e+02f);
		fHslider2 = FAUSTFLOAT(1e+02f);
		fHslider3 = FAUSTFLOAT(4.4e+02f);
		fHslider4 = FAUSTFLOAT(0.1f);
		fVslider4 = FAUSTFLOAT(6e+01f);
		fVslider5 = FAUSTFLOAT(0.0f);
		fVslider6 = FAUSTFLOAT(315.0f);
		fVslider7 = FAUSTFLOAT(0.0f);
		fVslider8 = FAUSTFLOAT(1.5e+03f);
		fVslider9 = FAUSTFLOAT(0.0f);
		fVslider10 = FAUSTFLOAT(-2e+01f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = l0 + 1) {
			iVec0[l0] = 0;
		}
		for (int l1 = 0; l1 < 2; l1 = l1 + 1) {
			fRec11[l1] = 0.0f;
		}
		for (int l2 = 0; l2 < 2; l2 = l2 + 1) {
			fRec10[l2] = 0.0f;
		}
		IOTA0 = 0;
		for (int l3 = 0; l3 < 16384; l3 = l3 + 1) {
			fVec1[l3] = 0.0f;
		}
		for (int l6 = 0; l6 < 2; l6 = l6 + 1) {
			fRec13[l6] = 0.0f;
		}
		for (int l7 = 0; l7 < 2; l7 = l7 + 1) {
			fRec15[l7] = 0.0f;
		}
		for (int l8 = 0; l8 < 2; l8 = l8 + 1) {
			fRec14[l8] = 0.0f;
		}
		for (int l9 = 0; l9 < 16384; l9 = l9 + 1) {
			fVec3[l9] = 0.0f;
		}
		for (int l10 = 0; l10 < 4096; l10 = l10 + 1) {
			fVec4[l10] = 0.0f;
		}
		for (int l11 = 0; l11 < 2; l11 = l11 + 1) {
			fRec8[l11] = 0.0f;
		}
		for (int l12 = 0; l12 < 2; l12 = l12 + 1) {
			fRec19[l12] = 0.0f;
		}
		for (int l13 = 0; l13 < 2; l13 = l13 + 1) {
			fRec18[l13] = 0.0f;
		}
		for (int l14 = 0; l14 < 16384; l14 = l14 + 1) {
			fVec5[l14] = 0.0f;
		}
		for (int l15 = 0; l15 < 2048; l15 = l15 + 1) {
			fVec6[l15] = 0.0f;
		}
		for (int l16 = 0; l16 < 2; l16 = l16 + 1) {
			fRec16[l16] = 0.0f;
		}
		for (int l17 = 0; l17 < 2; l17 = l17 + 1) {
			fRec23[l17] = 0.0f;
		}
		for (int l18 = 0; l18 < 2; l18 = l18 + 1) {
			fRec22[l18] = 0.0f;
		}
		for (int l19 = 0; l19 < 16384; l19 = l19 + 1) {
			fVec7[l19] = 0.0f;
		}
		for (int l20 = 0; l20 < 4096; l20 = l20 + 1) {
			fVec8[l20] = 0.0f;
		}
		for (int l21 = 0; l21 < 2; l21 = l21 + 1) {
			fRec20[l21] = 0.0f;
		}
		for (int l22 = 0; l22 < 2; l22 = l22 + 1) {
			fRec27[l22] = 0.0f;
		}
		for (int l23 = 0; l23 < 2; l23 = l23 + 1) {
			fRec26[l23] = 0.0f;
		}
		for (int l24 = 0; l24 < 16384; l24 = l24 + 1) {
			fVec9[l24] = 0.0f;
		}
		for (int l25 = 0; l25 < 2048; l25 = l25 + 1) {
			fVec10[l25] = 0.0f;
		}
		for (int l26 = 0; l26 < 2; l26 = l26 + 1) {
			fRec24[l26] = 0.0f;
		}
		for (int l27 = 0; l27 < 2; l27 = l27 + 1) {
			fRec31[l27] = 0.0f;
		}
		for (int l28 = 0; l28 < 2; l28 = l28 + 1) {
			fRec30[l28] = 0.0f;
		}
		for (int l29 = 0; l29 < 32768; l29 = l29 + 1) {
			fVec11[l29] = 0.0f;
		}
		for (int l30 = 0; l30 < 4096; l30 = l30 + 1) {
			fVec12[l30] = 0.0f;
		}
		for (int l31 = 0; l31 < 2; l31 = l31 + 1) {
			fRec28[l31] = 0.0f;
		}
		for (int l32 = 0; l32 < 2; l32 = l32 + 1) {
			fRec35[l32] = 0.0f;
		}
		for (int l33 = 0; l33 < 2; l33 = l33 + 1) {
			fRec34[l33] = 0.0f;
		}
		for (int l34 = 0; l34 < 16384; l34 = l34 + 1) {
			fVec13[l34] = 0.0f;
		}
		for (int l35 = 0; l35 < 4096; l35 = l35 + 1) {
			fVec14[l35] = 0.0f;
		}
		for (int l36 = 0; l36 < 2; l36 = l36 + 1) {
			fRec32[l36] = 0.0f;
		}
		for (int l37 = 0; l37 < 2; l37 = l37 + 1) {
			fRec39[l37] = 0.0f;
		}
		for (int l38 = 0; l38 < 2; l38 = l38 + 1) {
			fRec38[l38] = 0.0f;
		}
		for (int l39 = 0; l39 < 32768; l39 = l39 + 1) {
			fVec15[l39] = 0.0f;
		}
		for (int l40 = 0; l40 < 4096; l40 = l40 + 1) {
			fVec16[l40] = 0.0f;
		}
		for (int l41 = 0; l41 < 2; l41 = l41 + 1) {
			fRec36[l41] = 0.0f;
		}
		for (int l42 = 0; l42 < 2; l42 = l42 + 1) {
			fRec43[l42] = 0.0f;
		}
		for (int l43 = 0; l43 < 2; l43 = l43 + 1) {
			fRec42[l43] = 0.0f;
		}
		for (int l44 = 0; l44 < 32768; l44 = l44 + 1) {
			fVec17[l44] = 0.0f;
		}
		for (int l45 = 0; l45 < 2048; l45 = l45 + 1) {
			fVec18[l45] = 0.0f;
		}
		for (int l46 = 0; l46 < 2; l46 = l46 + 1) {
			fRec40[l46] = 0.0f;
		}
		for (int l47 = 0; l47 < 3; l47 = l47 + 1) {
			fRec0[l47] = 0.0f;
		}
		for (int l48 = 0; l48 < 3; l48 = l48 + 1) {
			fRec1[l48] = 0.0f;
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
			fRec44[l55] = 0.0f;
		}
		for (int l56 = 0; l56 < 3; l56 = l56 + 1) {
			fRec45[l56] = 0.0f;
		}
		for (int l57 = 0; l57 < 2; l57 = l57 + 1) {
			fRec46[l57] = 0.0f;
		}
		for (int l58 = 0; l58 < 2; l58 = l58 + 1) {
			fRec47[l58] = 0.0f;
		}
		for (int l59 = 0; l59 < 3; l59 = l59 + 1) {
			fRec48[l59] = 0.0f;
		}
		for (int l60 = 0; l60 < 3; l60 = l60 + 1) {
			fRec49[l60] = 0.0f;
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
		ui_interface->declare(&fHslider0, "Hz", "");
		ui_interface->addHorizontalSlider("AM Message Frequency", &fHslider0, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.1f), FAUSTFLOAT(1e+01f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider3, "Hz", "");
		ui_interface->addHorizontalSlider("Carrier Frequency", &fHslider3, FAUSTFLOAT(4.4e+02f), FAUSTFLOAT(2e+01f), FAUSTFLOAT(2e+03f), FAUSTFLOAT(0.01f));
		ui_interface->addHorizontalSlider("FM Index", &fHslider2, FAUSTFLOAT(1e+02f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1e+03f), FAUSTFLOAT(0.001f));
		ui_interface->addHorizontalSlider("Intermodulation Intensity", &fHslider4, FAUSTFLOAT(0.1f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider1, "Hz", "");
		ui_interface->addHorizontalSlider("Modulator Frequency", &fHslider1, FAUSTFLOAT(2.2e+02f), FAUSTFLOAT(2e+01f), FAUSTFLOAT(2e+03f), FAUSTFLOAT(0.001f));
		ui_interface->declare(0, "0", "");
		ui_interface->declare(0, "tooltip", "~ ZITA REV1 FEEDBACK DELAY NETWORK (FDN) & SCHROEDER     ALLPASS-COMB REVERBERATOR (8x8). See Faust's reverbs.lib for documentation and     references");
		ui_interface->openHorizontalBox("Zita_Rev1");
		ui_interface->declare(0, "1", "");
		ui_interface->openHorizontalBox("Input");
		ui_interface->declare(&fVslider4, "1", "");
		ui_interface->declare(&fVslider4, "style", "knob");
		ui_interface->declare(&fVslider4, "tooltip", "Delay in ms         before reverberation begins");
		ui_interface->declare(&fVslider4, "unit", "ms");
		ui_interface->addVerticalSlider("In Delay", &fVslider4, FAUSTFLOAT(6e+01f), FAUSTFLOAT(2e+01f), FAUSTFLOAT(1e+02f), FAUSTFLOAT(1.0f));
		ui_interface->closeBox();
		ui_interface->declare(0, "2", "");
		ui_interface->openHorizontalBox("Decay Times in Bands (see tooltips)");
		ui_interface->declare(&fVslider2, "1", "");
		ui_interface->declare(&fVslider2, "scale", "log");
		ui_interface->declare(&fVslider2, "style", "knob");
		ui_interface->declare(&fVslider2, "tooltip", "Crossover frequency (Hz) separating low and middle frequencies");
		ui_interface->declare(&fVslider2, "unit", "Hz");
		ui_interface->addVerticalSlider("LF X", &fVslider2, FAUSTFLOAT(2e+02f), FAUSTFLOAT(5e+01f), FAUSTFLOAT(1e+03f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fVslider3, "2", "");
		ui_interface->declare(&fVslider3, "scale", "log");
		ui_interface->declare(&fVslider3, "style", "knob");
		ui_interface->declare(&fVslider3, "tooltip", "T60 = time (in seconds) to decay 60dB in low-frequency band");
		ui_interface->declare(&fVslider3, "unit", "s");
		ui_interface->addVerticalSlider("Low RT60", &fVslider3, FAUSTFLOAT(3.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(8.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fVslider0, "3", "");
		ui_interface->declare(&fVslider0, "scale", "log");
		ui_interface->declare(&fVslider0, "style", "knob");
		ui_interface->declare(&fVslider0, "tooltip", "T60 = time (in seconds) to decay 60dB in middle band");
		ui_interface->declare(&fVslider0, "unit", "s");
		ui_interface->addVerticalSlider("Mid RT60", &fVslider0, FAUSTFLOAT(2.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(8.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fVslider1, "4", "");
		ui_interface->declare(&fVslider1, "scale", "log");
		ui_interface->declare(&fVslider1, "style", "knob");
		ui_interface->declare(&fVslider1, "tooltip", "Frequency (Hz) at which the high-frequency T60 is half the middle-band's T60");
		ui_interface->declare(&fVslider1, "unit", "Hz");
		ui_interface->addVerticalSlider("HF Damping", &fVslider1, FAUSTFLOAT(6e+03f), FAUSTFLOAT(1.5e+03f), FAUSTFLOAT(2.352e+04f), FAUSTFLOAT(1.0f));
		ui_interface->closeBox();
		ui_interface->declare(0, "3", "");
		ui_interface->openHorizontalBox("RM Peaking Equalizer 1");
		ui_interface->declare(&fVslider6, "1", "");
		ui_interface->declare(&fVslider6, "scale", "log");
		ui_interface->declare(&fVslider6, "style", "knob");
		ui_interface->declare(&fVslider6, "tooltip", "Center-frequency of second-order Regalia-Mitra peaking equalizer section 1");
		ui_interface->declare(&fVslider6, "unit", "Hz");
		ui_interface->addVerticalSlider("Eq1 Freq", &fVslider6, FAUSTFLOAT(315.0f), FAUSTFLOAT(4e+01f), FAUSTFLOAT(2.5e+03f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fVslider5, "2", "");
		ui_interface->declare(&fVslider5, "style", "knob");
		ui_interface->declare(&fVslider5, "tooltip", "Peak level         in dB of second-order Regalia-Mitra peaking equalizer section 1");
		ui_interface->declare(&fVslider5, "unit", "dB");
		ui_interface->addVerticalSlider("Eq1 Level", &fVslider5, FAUSTFLOAT(0.0f), FAUSTFLOAT(-15.0f), FAUSTFLOAT(15.0f), FAUSTFLOAT(0.1f));
		ui_interface->closeBox();
		ui_interface->declare(0, "4", "");
		ui_interface->openHorizontalBox("RM Peaking Equalizer 2");
		ui_interface->declare(&fVslider8, "1", "");
		ui_interface->declare(&fVslider8, "scale", "log");
		ui_interface->declare(&fVslider8, "style", "knob");
		ui_interface->declare(&fVslider8, "tooltip", "Center-frequency of second-order Regalia-Mitra peaking equalizer section 2");
		ui_interface->declare(&fVslider8, "unit", "Hz");
		ui_interface->addVerticalSlider("Eq2 Freq", &fVslider8, FAUSTFLOAT(1.5e+03f), FAUSTFLOAT(1.6e+02f), FAUSTFLOAT(1e+04f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fVslider7, "2", "");
		ui_interface->declare(&fVslider7, "style", "knob");
		ui_interface->declare(&fVslider7, "tooltip", "Peak level         in dB of second-order Regalia-Mitra peaking equalizer section 2");
		ui_interface->declare(&fVslider7, "unit", "dB");
		ui_interface->addVerticalSlider("Eq2 Level", &fVslider7, FAUSTFLOAT(0.0f), FAUSTFLOAT(-15.0f), FAUSTFLOAT(15.0f), FAUSTFLOAT(0.1f));
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
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		float fSlow0 = float(fVslider0);
		float fSlow1 = std::exp(fConst2 / fSlow0);
		float fSlow2 = mydsp_faustpower2_f(fSlow1);
		float fSlow3 = 1.0f - fSlow2;
		float fSlow4 = std::cos(fConst3 * float(fVslider1));
		float fSlow5 = 1.0f - fSlow4 * fSlow2;
		float fSlow6 = std::sqrt(std::max<float>(0.0f, mydsp_faustpower2_f(fSlow5) / mydsp_faustpower2_f(fSlow3) + -1.0f));
		float fSlow7 = fSlow5 / fSlow3;
		float fSlow8 = fSlow7 - fSlow6;
		float fSlow9 = 1.0f / std::tan(fConst4 * float(fVslider2));
		float fSlow10 = 1.0f - fSlow9;
		float fSlow11 = 1.0f / (fSlow9 + 1.0f);
		float fSlow12 = float(fVslider3);
		float fSlow13 = std::exp(fConst2 / fSlow12) / fSlow1 + -1.0f;
		float fSlow14 = fSlow1 * (fSlow6 + (1.0f - fSlow7));
		float fSlow15 = fConst7 * float(fHslider0);
		float fSlow16 = fConst7 * float(fHslider1);
		float fSlow17 = float(fHslider2);
		float fSlow18 = float(fHslider3);
		float fSlow19 = float(fHslider4);
		float fSlow20 = 1.0f - fSlow19;
		int iSlow21 = int(std::min<float>(8192.0f, std::max<float>(0.0f, fConst8 * float(fVslider4))));
		float fSlow22 = std::exp(fConst11 / fSlow0);
		float fSlow23 = mydsp_faustpower2_f(fSlow22);
		float fSlow24 = 1.0f - fSlow23;
		float fSlow25 = 1.0f - fSlow23 * fSlow4;
		float fSlow26 = std::sqrt(std::max<float>(0.0f, mydsp_faustpower2_f(fSlow25) / mydsp_faustpower2_f(fSlow24) + -1.0f));
		float fSlow27 = fSlow25 / fSlow24;
		float fSlow28 = fSlow27 - fSlow26;
		float fSlow29 = std::exp(fConst11 / fSlow12) / fSlow22 + -1.0f;
		float fSlow30 = fSlow22 * (fSlow26 + (1.0f - fSlow27));
		float fSlow31 = std::exp(fConst16 / fSlow0);
		float fSlow32 = mydsp_faustpower2_f(fSlow31);
		float fSlow33 = 1.0f - fSlow32;
		float fSlow34 = 1.0f - fSlow4 * fSlow32;
		float fSlow35 = std::sqrt(std::max<float>(0.0f, mydsp_faustpower2_f(fSlow34) / mydsp_faustpower2_f(fSlow33) + -1.0f));
		float fSlow36 = fSlow34 / fSlow33;
		float fSlow37 = fSlow36 - fSlow35;
		float fSlow38 = std::exp(fConst16 / fSlow12) / fSlow31 + -1.0f;
		float fSlow39 = fSlow31 * (fSlow35 + (1.0f - fSlow36));
		float fSlow40 = std::exp(fConst21 / fSlow0);
		float fSlow41 = mydsp_faustpower2_f(fSlow40);
		float fSlow42 = 1.0f - fSlow41;
		float fSlow43 = 1.0f - fSlow4 * fSlow41;
		float fSlow44 = std::sqrt(std::max<float>(0.0f, mydsp_faustpower2_f(fSlow43) / mydsp_faustpower2_f(fSlow42) + -1.0f));
		float fSlow45 = fSlow43 / fSlow42;
		float fSlow46 = fSlow45 - fSlow44;
		float fSlow47 = std::exp(fConst21 / fSlow12) / fSlow40 + -1.0f;
		float fSlow48 = fSlow40 * (fSlow44 + (1.0f - fSlow45));
		float fSlow49 = std::exp(fConst26 / fSlow0);
		float fSlow50 = mydsp_faustpower2_f(fSlow49);
		float fSlow51 = 1.0f - fSlow50;
		float fSlow52 = 1.0f - fSlow4 * fSlow50;
		float fSlow53 = std::sqrt(std::max<float>(0.0f, mydsp_faustpower2_f(fSlow52) / mydsp_faustpower2_f(fSlow51) + -1.0f));
		float fSlow54 = fSlow52 / fSlow51;
		float fSlow55 = fSlow54 - fSlow53;
		float fSlow56 = std::exp(fConst26 / fSlow12) / fSlow49 + -1.0f;
		float fSlow57 = fSlow49 * (fSlow53 + (1.0f - fSlow54));
		float fSlow58 = std::exp(fConst31 / fSlow0);
		float fSlow59 = mydsp_faustpower2_f(fSlow58);
		float fSlow60 = 1.0f - fSlow59;
		float fSlow61 = 1.0f - fSlow4 * fSlow59;
		float fSlow62 = std::sqrt(std::max<float>(0.0f, mydsp_faustpower2_f(fSlow61) / mydsp_faustpower2_f(fSlow60) + -1.0f));
		float fSlow63 = fSlow61 / fSlow60;
		float fSlow64 = fSlow63 - fSlow62;
		float fSlow65 = std::exp(fConst31 / fSlow12) / fSlow58 + -1.0f;
		float fSlow66 = fSlow58 * (fSlow62 + (1.0f - fSlow63));
		float fSlow67 = std::exp(fConst36 / fSlow0);
		float fSlow68 = mydsp_faustpower2_f(fSlow67);
		float fSlow69 = 1.0f - fSlow68;
		float fSlow70 = 1.0f - fSlow4 * fSlow68;
		float fSlow71 = std::sqrt(std::max<float>(0.0f, mydsp_faustpower2_f(fSlow70) / mydsp_faustpower2_f(fSlow69) + -1.0f));
		float fSlow72 = fSlow70 / fSlow69;
		float fSlow73 = fSlow72 - fSlow71;
		float fSlow74 = std::exp(fConst36 / fSlow12) / fSlow67 + -1.0f;
		float fSlow75 = fSlow67 * (fSlow71 + (1.0f - fSlow72));
		float fSlow76 = std::exp(fConst41 / fSlow0);
		float fSlow77 = mydsp_faustpower2_f(fSlow76);
		float fSlow78 = 1.0f - fSlow77;
		float fSlow79 = 1.0f - fSlow4 * fSlow77;
		float fSlow80 = std::sqrt(std::max<float>(0.0f, mydsp_faustpower2_f(fSlow79) / mydsp_faustpower2_f(fSlow78) + -1.0f));
		float fSlow81 = fSlow79 / fSlow78;
		float fSlow82 = fSlow81 - fSlow80;
		float fSlow83 = std::exp(fConst41 / fSlow12) / fSlow76 + -1.0f;
		float fSlow84 = fSlow76 * (fSlow80 + (1.0f - fSlow81));
		float fSlow85 = std::pow(1e+01f, 0.05f * float(fVslider5));
		float fSlow86 = float(fVslider6);
		float fSlow87 = fConst3 * (fSlow86 / std::sqrt(std::max<float>(0.0f, fSlow85)));
		float fSlow88 = (1.0f - fSlow87) / (fSlow87 + 1.0f);
		float fSlow89 = 0.0f - std::cos(fConst3 * fSlow86) * (fSlow88 + 1.0f);
		float fSlow90 = std::pow(1e+01f, 0.05f * float(fVslider7));
		float fSlow91 = float(fVslider8);
		float fSlow92 = fConst3 * (fSlow91 / std::sqrt(std::max<float>(0.0f, fSlow90)));
		float fSlow93 = (1.0f - fSlow92) / (fSlow92 + 1.0f);
		float fSlow94 = 0.0f - std::cos(fConst3 * fSlow91) * (fSlow93 + 1.0f);
		float fSlow95 = fConst45 * float(fVslider9);
		float fSlow96 = fConst45 * std::pow(1e+01f, 0.05f * float(fVslider10));
		for (int i0 = 0; i0 < count; i0 = i0 + 1) {
			iVec0[0] = 1;
			fRec11[0] = 0.0f - fSlow11 * (fSlow10 * fRec11[1] - (fRec4[1] + fRec4[2]));
			fRec10[0] = fSlow14 * (fRec4[1] + fSlow13 * fRec11[0]) + fSlow8 * fRec10[1];
			fVec1[IOTA0 & 16383] = 0.35355338f * fRec10[0] + 1e-20f;
			int iTemp0 = 1 - iVec0[1];
			float fTemp1 = ((iTemp0) ? 0.0f : fSlow15 + fRec13[1]);
			fRec13[0] = fTemp1 - std::floor(fTemp1);
			float fTemp2 = ((iTemp0) ? 0.0f : fSlow16 + fRec15[1]);
			fRec15[0] = fTemp2 - std::floor(fTemp2);
			float fTemp3 = ((iTemp0) ? 0.0f : fRec14[1] + fConst7 * (fSlow18 + fSlow17 * ftbl0mydspSIG0[std::max<int>(0, std::min<int>(int(65536.0f * fRec15[0]), 65535))]));
			fRec14[0] = fTemp3 - std::floor(fTemp3);
			float fTemp4 = ftbl0mydspSIG0[std::max<int>(0, std::min<int>(int(65536.0f * fRec14[0]), 65535))] * ftbl0mydspSIG0[std::max<int>(0, std::min<int>(int(65536.0f * fRec13[0]), 65535))];
			float fTemp5 = fSlow20 * fTemp4 + fSlow19 * mydsp_faustpower2_f(fTemp4);
			fVec3[IOTA0 & 16383] = fTemp5;
			float fTemp6 = 0.3f * fVec3[(IOTA0 - iSlow21) & 16383];
			float fTemp7 = fTemp6 + fVec1[(IOTA0 - iConst6) & 16383] - 0.6f * fRec8[1];
			fVec4[IOTA0 & 4095] = fTemp7;
			fRec8[0] = fVec4[(IOTA0 - iConst9) & 4095];
			float fRec9 = 0.6f * fTemp7;
			fRec19[0] = 0.0f - fSlow11 * (fSlow10 * fRec19[1] - (fRec0[1] + fRec0[2]));
			fRec18[0] = fSlow30 * (fRec0[1] + fSlow29 * fRec19[0]) + fSlow28 * fRec18[1];
			fVec5[IOTA0 & 16383] = 0.35355338f * fRec18[0] + 1e-20f;
			float fTemp8 = fVec5[(IOTA0 - iConst13) & 16383] + fTemp6 - 0.6f * fRec16[1];
			fVec6[IOTA0 & 2047] = fTemp8;
			fRec16[0] = fVec6[(IOTA0 - iConst14) & 2047];
			float fRec17 = 0.6f * fTemp8;
			float fTemp9 = fRec17 + fRec9;
			fRec23[0] = 0.0f - fSlow11 * (fSlow10 * fRec23[1] - (fRec2[1] + fRec2[2]));
			fRec22[0] = fSlow39 * (fRec2[1] + fSlow38 * fRec23[0]) + fSlow37 * fRec22[1];
			fVec7[IOTA0 & 16383] = 0.35355338f * fRec22[0] + 1e-20f;
			float fTemp10 = fVec7[(IOTA0 - iConst18) & 16383] - (fTemp6 + 0.6f * fRec20[1]);
			fVec8[IOTA0 & 4095] = fTemp10;
			fRec20[0] = fVec8[(IOTA0 - iConst19) & 4095];
			float fRec21 = 0.6f * fTemp10;
			fRec27[0] = 0.0f - fSlow11 * (fSlow10 * fRec27[1] - (fRec6[1] + fRec6[2]));
			fRec26[0] = fSlow48 * (fRec6[1] + fSlow47 * fRec27[0]) + fSlow46 * fRec26[1];
			fVec9[IOTA0 & 16383] = 0.35355338f * fRec26[0] + 1e-20f;
			float fTemp11 = fVec9[(IOTA0 - iConst23) & 16383] - (fTemp6 + 0.6f * fRec24[1]);
			fVec10[IOTA0 & 2047] = fTemp11;
			fRec24[0] = fVec10[(IOTA0 - iConst24) & 2047];
			float fRec25 = 0.6f * fTemp11;
			float fTemp12 = fRec25 + fRec21 + fTemp9;
			fRec31[0] = 0.0f - fSlow11 * (fSlow10 * fRec31[1] - (fRec1[1] + fRec1[2]));
			fRec30[0] = fSlow57 * (fRec1[1] + fSlow56 * fRec31[0]) + fSlow55 * fRec30[1];
			fVec11[IOTA0 & 32767] = 0.35355338f * fRec30[0] + 1e-20f;
			float fTemp13 = fVec11[(IOTA0 - iConst28) & 32767] + fTemp6 + 0.6f * fRec28[1];
			fVec12[IOTA0 & 4095] = fTemp13;
			fRec28[0] = fVec12[(IOTA0 - iConst29) & 4095];
			float fRec29 = 0.0f - 0.6f * fTemp13;
			fRec35[0] = 0.0f - fSlow11 * (fSlow10 * fRec35[1] - (fRec5[1] + fRec5[2]));
			fRec34[0] = fSlow66 * (fRec5[1] + fSlow65 * fRec35[0]) + fSlow64 * fRec34[1];
			fVec13[IOTA0 & 16383] = 0.35355338f * fRec34[0] + 1e-20f;
			float fTemp14 = fVec13[(IOTA0 - iConst33) & 16383] + fTemp6 + 0.6f * fRec32[1];
			fVec14[IOTA0 & 4095] = fTemp14;
			fRec32[0] = fVec14[(IOTA0 - iConst34) & 4095];
			float fRec33 = 0.0f - 0.6f * fTemp14;
			fRec39[0] = 0.0f - fSlow11 * (fSlow10 * fRec39[1] - (fRec3[1] + fRec3[2]));
			fRec38[0] = fSlow75 * (fRec3[1] + fSlow74 * fRec39[0]) + fSlow73 * fRec38[1];
			fVec15[IOTA0 & 32767] = 0.35355338f * fRec38[0] + 1e-20f;
			float fTemp15 = 0.6f * fRec36[1] + fVec15[(IOTA0 - iConst38) & 32767] - fTemp6;
			fVec16[IOTA0 & 4095] = fTemp15;
			fRec36[0] = fVec16[(IOTA0 - iConst39) & 4095];
			float fRec37 = 0.0f - 0.6f * fTemp15;
			fRec43[0] = 0.0f - fSlow11 * (fSlow10 * fRec43[1] - (fRec7[1] + fRec7[2]));
			fRec42[0] = fSlow84 * (fRec7[1] + fSlow83 * fRec43[0]) + fSlow82 * fRec42[1];
			fVec17[IOTA0 & 32767] = 0.35355338f * fRec42[0] + 1e-20f;
			float fTemp16 = 0.6f * fRec40[1] + fVec17[(IOTA0 - iConst43) & 32767] - fTemp6;
			fVec18[IOTA0 & 2047] = fTemp16;
			fRec40[0] = fVec18[(IOTA0 - iConst44) & 2047];
			float fRec41 = 0.0f - 0.6f * fTemp16;
			fRec0[0] = fRec40[1] + fRec36[1] + fRec32[1] + fRec28[1] + fRec24[1] + fRec20[1] + fRec8[1] + fRec16[1] + fRec41 + fRec37 + fRec33 + fRec29 + fTemp12;
			fRec1[0] = fRec24[1] + fRec20[1] + fRec8[1] + fRec16[1] + fTemp12 - (fRec40[1] + fRec36[1] + fRec32[1] + fRec28[1] + fRec41 + fRec37 + fRec29 + fRec33);
			float fTemp17 = fRec21 + fRec25;
			fRec2[0] = fRec32[1] + fRec28[1] + fRec8[1] + fRec16[1] + fRec33 + fRec29 + fTemp9 - (fRec40[1] + fRec36[1] + fRec24[1] + fRec20[1] + fRec41 + fRec37 + fTemp17);
			fRec3[0] = fRec40[1] + fRec36[1] + fRec8[1] + fRec16[1] + fRec41 + fRec37 + fTemp9 - (fRec32[1] + fRec28[1] + fRec24[1] + fRec20[1] + fRec33 + fRec29 + fTemp17);
			float fTemp18 = fRec9 + fRec25;
			float fTemp19 = fRec17 + fRec21;
			fRec4[0] = fRec36[1] + fRec28[1] + fRec20[1] + fRec16[1] + fRec37 + fRec29 + fTemp19 - (fRec40[1] + fRec32[1] + fRec24[1] + fRec8[1] + fRec41 + fRec33 + fTemp18);
			fRec5[0] = fRec40[1] + fRec32[1] + fRec20[1] + fRec16[1] + fRec41 + fRec33 + fTemp19 - (fRec36[1] + fRec28[1] + fRec24[1] + fRec8[1] + fRec37 + fRec29 + fTemp18);
			float fTemp20 = fRec9 + fRec21;
			float fTemp21 = fRec17 + fRec25;
			fRec6[0] = fRec40[1] + fRec28[1] + fRec24[1] + fRec16[1] + fRec41 + fRec29 + fTemp21 - (fRec36[1] + fRec32[1] + fRec20[1] + fRec8[1] + fRec37 + fRec33 + fTemp20);
			fRec7[0] = fRec36[1] + fRec32[1] + fRec24[1] + fRec16[1] + fRec37 + fRec33 + fTemp21 - (fRec40[1] + fRec28[1] + fRec20[1] + fRec8[1] + fRec41 + fRec29 + fTemp20);
			float fTemp22 = 0.37f * (fRec1[0] + fRec2[0]);
			float fTemp23 = fSlow89 * fRec44[1];
			fRec44[0] = fTemp22 - (fTemp23 + fSlow88 * fRec44[2]);
			float fTemp24 = fSlow88 * fRec44[0];
			float fTemp25 = 0.5f * (fTemp24 + fRec44[2] + fTemp22 + fTemp23 + fSlow85 * (fTemp24 + fTemp23 + fRec44[2] - fTemp22));
			float fTemp26 = fSlow94 * fRec45[1];
			fRec45[0] = fTemp25 - (fTemp26 + fSlow93 * fRec45[2]);
			float fTemp27 = fSlow93 * fRec45[0];
			fRec46[0] = fSlow95 + fConst46 * fRec46[1];
			float fTemp28 = fRec46[0] + 1.0f;
			float fTemp29 = 1.0f - 0.5f * fTemp28;
			float fTemp30 = fTemp28 * fTemp5;
			fRec47[0] = fSlow96 + fConst46 * fRec47[1];
			output0[i0] = FAUSTFLOAT(0.5f * fRec47[0] * (fTemp30 + fTemp29 * (fTemp27 + fRec45[2] + fTemp25 + fTemp26 + fSlow90 * (fTemp27 + fTemp26 + fRec45[2] - fTemp25))));
			float fTemp31 = 0.37f * (fRec1[0] - fRec2[0]);
			float fTemp32 = fSlow89 * fRec48[1];
			fRec48[0] = fTemp31 - (fTemp32 + fSlow88 * fRec48[2]);
			float fTemp33 = fSlow88 * fRec48[0];
			float fTemp34 = 0.5f * (fTemp33 + fRec48[2] + fTemp31 + fTemp32 + fSlow85 * (fTemp33 + fTemp32 + fRec48[2] - fTemp31));
			float fTemp35 = fSlow94 * fRec49[1];
			fRec49[0] = fTemp34 - (fTemp35 + fSlow93 * fRec49[2]);
			float fTemp36 = fSlow93 * fRec49[0];
			output1[i0] = FAUSTFLOAT(0.5f * fRec47[0] * (fTemp30 + fTemp29 * (fTemp36 + fRec49[2] + fTemp34 + fTemp35 + fSlow90 * (fTemp36 + fTemp35 + fRec49[2] - fTemp34))));
			iVec0[1] = iVec0[0];
			fRec11[1] = fRec11[0];
			fRec10[1] = fRec10[0];
			IOTA0 = IOTA0 + 1;
			fRec13[1] = fRec13[0];
			fRec15[1] = fRec15[0];
			fRec14[1] = fRec14[0];
			fRec8[1] = fRec8[0];
			fRec19[1] = fRec19[0];
			fRec18[1] = fRec18[0];
			fRec16[1] = fRec16[0];
			fRec23[1] = fRec23[0];
			fRec22[1] = fRec22[0];
			fRec20[1] = fRec20[0];
			fRec27[1] = fRec27[0];
			fRec26[1] = fRec26[0];
			fRec24[1] = fRec24[0];
			fRec31[1] = fRec31[0];
			fRec30[1] = fRec30[0];
			fRec28[1] = fRec28[0];
			fRec35[1] = fRec35[0];
			fRec34[1] = fRec34[0];
			fRec32[1] = fRec32[0];
			fRec39[1] = fRec39[0];
			fRec38[1] = fRec38[0];
			fRec36[1] = fRec36[0];
			fRec43[1] = fRec43[0];
			fRec42[1] = fRec42[0];
			fRec40[1] = fRec40[0];
			fRec0[2] = fRec0[1];
			fRec0[1] = fRec0[0];
			fRec1[2] = fRec1[1];
			fRec1[1] = fRec1[0];
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
			fRec44[2] = fRec44[1];
			fRec44[1] = fRec44[0];
			fRec45[2] = fRec45[1];
			fRec45[1] = fRec45[0];
			fRec46[1] = fRec46[0];
			fRec47[1] = fRec47[0];
			fRec48[2] = fRec48[1];
			fRec48[1] = fRec48[0];
			fRec49[2] = fRec49[1];
			fRec49[1] = fRec49[0];
		}
	}

};

#endif
