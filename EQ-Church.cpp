/* ------------------------------------------------------------
name: "untitled", "Josué E. Peraza, B.Sc, M. EngEe"
Code generated with Faust 2.70.3 (https://faust.grame.fr)
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

const static float fmydspSIG0Wave0[350] = {0.525285f,0.814174f,0.483261f,0.296745f,0.975056f,0.472244f,0.409501f,0.425364f,0.687559f,0.288381f,0.309285f,0.123054f,0.286333f,0.576706f,0.908322f,0.626974f,0.0801852f,0.309835f,0.45143f,0.132845f,0.470635f,0.417008f,0.265112f,0.0752802f,0.46347f,0.47181f,0.275324f,0.547027f,0.512519f,0.394078f,0.595404f,0.941306f,0.392501f,0.381435f,0.391232f,0.118924f,0.339495f,0.101421f,0.241755f,0.0873255f,0.378944f,0.637705f,0.171946f,0.149859f,0.23329f,0.54181f,1.0f,0.115554f,0.244172f,0.574329f,0.606171f,0.938397f,0.392555f,0.277359f,0.86857f,0.432489f,0.408856f,0.407932f,0.299815f,0.256659f,0.549572f,0.406347f,0.312331f,0.627578f,0.670167f,0.524648f,0.406926f,0.637524f,0.555837f,1.0f,0.818979f,0.705347f,0.678141f,0.427382f,0.674404f,0.636105f,0.643635f,0.699136f,0.836201f,0.613085f,0.319019f,0.725259f,0.545519f,0.479861f,0.49836f,0.488654f,0.861672f,0.314287f,0.671052f,0.531905f,0.421781f,0.815066f,0.772032f,0.488722f,0.0896674f,0.291286f,0.65873f,0.635632f,0.679357f,0.459497f,0.36024f,0.582289f,0.650605f,0.49095f,0.38191f,0.157261f,0.479624f,0.477491f,0.174435f,0.013094f,0.879113f,0.608069f,0.268877f,0.604479f,0.24513f,0.170507f,0.292888f,0.545849f,0.476646f,0.922316f,0.669192f,0.578094f,0.578797f,0.311396f,0.60121f,0.549955f,1.0f,0.66573f,0.980115f,0.537848f,0.0740531f,0.252472f,0.25575f,0.223974f,0.0865103f,0.138209f,0.198623f,0.0453034f,0.432453f,0.292407f,0.39441f,0.857659f,0.271668f,0.201545f,0.583994f,0.0602378f,0.190618f,0.849505f,0.975542f,0.17314f,0.206472f,0.344793f,0.761011f,0.558125f,0.117245f,0.0338485f,0.337597f,0.336646f,0.174253f,0.23017f,0.934873f,0.593647f,0.393225f,0.683704f,0.0566093f,0.0405012f,0.148972f,0.338722f,0.283419f,0.394007f,0.237475f,0.269964f,0.428313f,0.177499f,0.462585f,0.443963f,0.981793f,0.408239f,0.676527f,0.402865f,0.0163303f,0.0515114f,0.34139f,0.311135f,0.613276f,0.805884f,0.95329f,0.406091f,0.578705f,0.386785f,0.434103f,0.77526f,1.0f,0.635909f,0.782052f,0.0137183f,0.0387725f,0.618964f,0.857071f,0.131522f,0.184988f,0.299495f,0.789212f,0.603114f,0.0704989f,0.0129339f,0.252481f,0.254121f,0.189206f,0.357713f,0.950308f,0.552573f,0.466454f,0.77736f,0.0307886f,0.0251943f,0.378886f,0.740187f,0.247637f,0.235201f,0.493045f,0.51785f,0.883954f,0.429473f,0.409433f,0.415266f,0.940198f,0.282334f,0.43789f,0.375385f,0.0157366f,0.0171763f,0.485555f,0.461015f,0.858958f,0.907991f,0.935191f,0.37551f,1.0f,0.585493f,0.269981f,0.423053f,0.666067f,0.43509f,0.790252f,0.00889586f,0.0208844f,0.449735f,0.790808f,0.159856f,0.089599f,0.161546f,0.528168f,0.380642f,0.0206276f,0.00726426f,0.0315352f,0.0315841f,0.197649f,0.475057f,0.517232f,0.360922f,0.421204f,0.63134f,0.00952139f,0.016105f,0.499615f,0.922958f,0.214983f,0.0655141f,0.50397f,0.514848f,1.0f,0.483619f,0.254027f,0.228372f,0.436105f,0.233125f,0.152242f,0.279513f,0.00906739f,0.0132332f,0.451257f,0.388566f,0.737226f,0.479378f,0.233037f,0.103767f,0.845609f,0.644127f,0.261359f,0.371457f,0.527229f,0.381373f,0.334492f,0.00833749f,0.00861982f,0.255919f,0.254197f,0.0872333f,0.0461512f,0.113018f,0.345986f,0.236344f,0.01078f,0.00816506f,0.405181f,0.38718f,0.343681f,0.816493f,0.259082f,0.211906f,0.432455f,0.696886f,0.00576224f,0.013131f,0.455969f,0.811609f,0.426544f,0.128489f,0.215937f,0.233934f,0.72307f,0.351623f,0.394231f,0.323766f,0.168803f,0.276932f,0.264684f,0.227703f,0.00680935f,0.0170703f,0.603018f,0.476461f,0.585925f,0.71696f,1.0f,0.576527f,0.475524f,0.447322f,0.356902f,0.597573f,0.697246f,0.505333f,0.285421f,0.0147193f,0.0141618f,0.136188f,0.0336537f,0.216437f};
class mydspSIG0 {
	
  private:
	
	int fmydspSIG0Wave0_idx;
	
  public:
	
	int getNumInputsmydspSIG0() {
		return 0;
	}
	int getNumOutputsmydspSIG0() {
		return 1;
	}
	
	void instanceInitmydspSIG0(int sample_rate) {
		fmydspSIG0Wave0_idx = 0;
	}
	
	void fillmydspSIG0(int count, float* table) {
		for (int i1 = 0; i1 < count; i1 = i1 + 1) {
			table[i1] = fmydspSIG0Wave0[fmydspSIG0Wave0_idx];
			fmydspSIG0Wave0_idx = (1 + fmydspSIG0Wave0_idx) % 350;
		}
	}

};

static mydspSIG0* newmydspSIG0() { return (mydspSIG0*)new mydspSIG0(); }
static void deletemydspSIG0(mydspSIG0* dsp) { delete dsp; }

static float mydsp_faustpower2_f(float value) {
	return value * value;
}
static float ftbl0mydspSIG0[350];

class mydsp : public dsp {
	
 private:
	
	int fSampleRate;
	float fConst2;
	FAUSTFLOAT fVslider0;
	FAUSTFLOAT fEntry0;
	float fConst3;
	FAUSTFLOAT fHslider0;
	float fConst4;
	FAUSTFLOAT fVslider1;
	FAUSTFLOAT fEntry1;
	FAUSTFLOAT fHslider1;
	FAUSTFLOAT fVslider2;
	FAUSTFLOAT fEntry2;
	FAUSTFLOAT fHslider2;
	FAUSTFLOAT fVslider3;
	FAUSTFLOAT fEntry3;
	FAUSTFLOAT fHslider3;
	FAUSTFLOAT fVslider4;
	FAUSTFLOAT fEntry4;
	FAUSTFLOAT fHslider4;
	FAUSTFLOAT fVslider5;
	FAUSTFLOAT fEntry5;
	FAUSTFLOAT fHslider5;
	FAUSTFLOAT fVslider6;
	FAUSTFLOAT fEntry6;
	FAUSTFLOAT fHslider6;
	FAUSTFLOAT fVslider7;
	FAUSTFLOAT fEntry7;
	FAUSTFLOAT fHslider7;
	FAUSTFLOAT fVslider8;
	FAUSTFLOAT fEntry8;
	FAUSTFLOAT fHslider8;
	FAUSTFLOAT fVslider9;
	FAUSTFLOAT fEntry9;
	FAUSTFLOAT fHslider9;
	FAUSTFLOAT fEntry10;
	float fConst6;
	float fConst7;
	FAUSTFLOAT fButton0;
	float fVec0[2];
	int iRec13[2];
	FAUSTFLOAT fHslider10;
	float fConst8;
	FAUSTFLOAT fHslider11;
	float fConst11;
	float fConst13;
	float fConst15;
	int iRec16[2];
	float fRec15[3];
	float fConst16;
	float fRec14[3];
	FAUSTFLOAT fHslider12;
	float fRec12[3];
	float fConst18;
	float fConst19;
	float fRec17[3];
	float fConst21;
	float fConst22;
	float fRec18[3];
	float fConst24;
	float fConst25;
	float fRec19[3];
	float fConst27;
	float fConst28;
	float fRec20[3];
	float fConst30;
	float fConst31;
	float fRec21[3];
	float fConst33;
	float fConst34;
	float fRec22[3];
	float fConst36;
	float fConst37;
	float fRec23[3];
	float fConst39;
	float fConst40;
	float fRec24[3];
	float fConst42;
	float fConst43;
	float fRec25[3];
	float fConst45;
	float fConst46;
	float fRec26[3];
	float fConst48;
	float fConst49;
	float fRec27[3];
	float fConst51;
	float fConst52;
	float fRec28[3];
	float fConst54;
	float fConst55;
	float fRec29[3];
	float fConst57;
	float fConst58;
	float fRec30[3];
	float fConst60;
	float fConst61;
	float fRec31[3];
	float fConst63;
	float fConst64;
	float fRec32[3];
	float fConst66;
	float fConst67;
	float fRec33[3];
	float fConst69;
	float fConst70;
	float fRec34[3];
	float fConst72;
	float fConst73;
	float fRec35[3];
	float fConst75;
	float fConst76;
	float fRec36[3];
	float fConst78;
	float fConst79;
	float fRec37[3];
	float fConst81;
	float fConst82;
	float fRec38[3];
	float fConst84;
	float fConst85;
	float fRec39[3];
	float fConst87;
	float fConst88;
	float fRec40[3];
	float fConst90;
	float fConst91;
	float fRec41[3];
	float fConst93;
	float fConst94;
	float fRec42[3];
	float fConst96;
	float fConst97;
	float fRec43[3];
	float fConst99;
	float fConst100;
	float fRec44[3];
	float fConst102;
	float fConst103;
	float fRec45[3];
	float fConst105;
	float fConst106;
	float fRec46[3];
	float fConst108;
	float fConst109;
	float fRec47[3];
	float fConst111;
	float fConst112;
	float fRec48[3];
	float fConst114;
	float fConst115;
	float fRec49[3];
	float fConst117;
	float fConst118;
	float fRec50[3];
	float fConst120;
	float fConst121;
	float fRec51[3];
	float fConst123;
	float fConst124;
	float fRec52[3];
	float fConst126;
	float fConst127;
	float fRec53[3];
	float fConst129;
	float fConst130;
	float fRec54[3];
	float fConst132;
	float fConst133;
	float fRec55[3];
	float fConst135;
	float fConst136;
	float fRec56[3];
	float fConst138;
	float fConst139;
	float fRec57[3];
	float fConst141;
	float fConst142;
	float fRec58[3];
	float fConst144;
	float fConst145;
	float fRec59[3];
	float fConst147;
	float fConst148;
	float fRec60[3];
	float fConst150;
	float fConst151;
	float fRec61[3];
	float fConst153;
	float fConst154;
	float fRec62[3];
	float fConst156;
	float fConst157;
	float fRec63[3];
	float fConst159;
	float fConst160;
	float fRec64[3];
	float fConst162;
	float fConst163;
	float fRec65[3];
	float fConst164;
	float fConst165;
	FAUSTFLOAT fHslider13;
	float fRec66[2];
	int IOTA0;
	FAUSTFLOAT fHslider14;
	float fConst166;
	float fRec68[2];
	FAUSTFLOAT fHslider15;
	float fRec69[2];
	float fRec67[131072];
	float fRec11[3];
	float fRec10[3];
	float fRec9[3];
	float fRec8[3];
	float fRec7[3];
	float fRec6[3];
	float fRec5[3];
	float fRec4[3];
	float fRec3[3];
	float fRec2[3];
	float fVec1[2];
	float fConst167;
	float fRec1[2];
	float fRec0[2];
	
 public:
	mydsp() {}

	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/tabulateNd", "Copyright (C) 2023 Bart Brouns <bart@magnetophon.nl>");
		m->declare("basics.lib/version", "1.11.1");
		m->declare("compile_options", "-lang cpp -ct 1 -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0");
		m->declare("envelopes.lib/ar:author", "Yann Orlarey, Stéphane Letz");
		m->declare("envelopes.lib/author", "GRAME");
		m->declare("envelopes.lib/copyright", "GRAME");
		m->declare("envelopes.lib/license", "LGPL with exception");
		m->declare("envelopes.lib/name", "Faust Envelope Library");
		m->declare("envelopes.lib/version", "1.3.0");
		m->declare("filename", "untitled.dsp");
		m->declare("filters.lib/dcblockerat:author", "Julius O. Smith III");
		m->declare("filters.lib/dcblockerat:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/dcblockerat:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/fir:author", "Julius O. Smith III");
		m->declare("filters.lib/fir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/fir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/highpass:author", "Julius O. Smith III");
		m->declare("filters.lib/highpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/iir:author", "Julius O. Smith III");
		m->declare("filters.lib/iir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/iir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/lowpass0_highpass1", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/lowpass0_highpass1:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/lowpass:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/peak_eq:author", "Julius O. Smith III");
		m->declare("filters.lib/peak_eq:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/peak_eq:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/pole:author", "Julius O. Smith III");
		m->declare("filters.lib/pole:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/pole:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf2:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf2s:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2s:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2s:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/version", "1.3.0");
		m->declare("filters.lib/zero:author", "Julius O. Smith III");
		m->declare("filters.lib/zero:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/zero:license", "MIT-style STK-4.3 license");
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
		m->declare("noises.lib/name", "Faust Noise Generator Library");
		m->declare("noises.lib/version", "1.4.0");
		m->declare("physmodels.lib/name", "Faust Physical Models Library");
		m->declare("physmodels.lib/version", "1.1.0");
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
		sig0->fillmydspSIG0(350, ftbl0mydspSIG0);
		deletemydspSIG0(sig0);
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		float fConst0 = std::min<float>(1.92e+05f, std::max<float>(1.0f, float(fSampleRate)));
		float fConst1 = 219.91148f / fConst0;
		fConst2 = 1.0f - fConst1;
		fConst3 = 6.2831855f / fConst0;
		fConst4 = 3.1415927f / fConst0;
		float fConst5 = std::pow(0.001f, 1.316172e+07f / fConst0);
		fConst6 = mydsp_faustpower2_f(fConst5);
		fConst7 = 2.0f * std::cos(25346.182f / fConst0) * fConst5;
		fConst8 = 0.002f * fConst0;
		float fConst9 = std::tan(31.415926f / fConst0);
		float fConst10 = mydsp_faustpower2_f(fConst9);
		fConst11 = 2.0f * (1.0f - 1.0f / fConst10);
		float fConst12 = 1.0f / fConst9;
		fConst13 = (fConst12 + -1.4142135f) / fConst9 + 1.0f;
		float fConst14 = (fConst12 + 1.4142135f) / fConst9 + 1.0f;
		fConst15 = 1.0f / fConst14;
		fConst16 = 1.0f / (fConst10 * fConst14);
		float fConst17 = std::pow(0.001f, 1752.4181f / fConst0);
		fConst18 = mydsp_faustpower2_f(fConst17);
		fConst19 = 2.0f * std::cos(25027.498f / fConst0) * fConst17;
		float fConst20 = std::pow(0.001f, 1631.8125f / fConst0);
		fConst21 = mydsp_faustpower2_f(fConst20);
		fConst22 = 2.0f * std::cos(25018.01f / fConst0) * fConst20;
		float fConst23 = std::pow(0.001f, 415.09854f / fConst0);
		fConst24 = mydsp_faustpower2_f(fConst23);
		fConst25 = 2.0f * std::cos(24772.023f / fConst0) * fConst23;
		float fConst26 = std::pow(0.001f, 173.36896f / fConst0);
		fConst27 = mydsp_faustpower2_f(fConst26);
		fConst28 = 2.0f * std::cos(24528.174f / fConst0) * fConst26;
		float fConst29 = std::pow(0.001f, 27.05635f / fConst0);
		fConst30 = mydsp_faustpower2_f(fConst29);
		fConst31 = 2.0f * std::cos(23616.357f / fConst0) * fConst29;
		float fConst32 = std::pow(0.001f, 22.858442f / fConst0);
		fConst33 = mydsp_faustpower2_f(fConst32);
		fConst34 = 2.0f * std::cos(23495.03f / fConst0) * fConst32;
		float fConst35 = std::pow(0.001f, 21.155993f / fConst0);
		fConst36 = mydsp_faustpower2_f(fConst35);
		fConst37 = 2.0f * std::cos(23436.533f / fConst0) * fConst35;
		float fConst38 = std::pow(0.001f, 7.955602f / fConst0);
		fConst39 = mydsp_faustpower2_f(fConst38);
		fConst40 = 2.0f * std::cos(22517.805f / fConst0) * fConst38;
		float fConst41 = std::pow(0.001f, 7.9104223f / fConst0);
		fConst42 = mydsp_faustpower2_f(fConst41);
		fConst43 = 2.0f * std::cos(22511.334f / fConst0) * fConst41;
		float fConst44 = std::pow(0.001f, 6.265179f / fConst0);
		fConst45 = mydsp_faustpower2_f(fConst44);
		fConst46 = 2.0f * std::cos(22233.303f / fConst0) * fConst44;
		float fConst47 = std::pow(0.001f, 5.6190987f / fConst0);
		fConst48 = mydsp_faustpower2_f(fConst47);
		fConst49 = 2.0f * std::cos(22094.38f / fConst0) * fConst47;
		float fConst50 = std::pow(0.001f, 3.4294884f / fConst0);
		fConst51 = mydsp_faustpower2_f(fConst50);
		fConst52 = 2.0f * std::cos(21382.309f / fConst0) * fConst50;
		float fConst53 = std::pow(0.001f, 3.2622824f / fConst0);
		fConst54 = mydsp_faustpower2_f(fConst53);
		fConst55 = 2.0f * std::cos(21302.072f / fConst0) * fConst53;
		float fConst56 = std::pow(0.001f, 2.6162083f / fConst0);
		fConst57 = mydsp_faustpower2_f(fConst56);
		fConst58 = 2.0f * std::cos(20927.97f / fConst0) * fConst56;
		float fConst59 = std::pow(0.001f, 1.5768591f / fConst0);
		fConst60 = mydsp_faustpower2_f(fConst59);
		fConst61 = 2.0f * std::cos(19934.096f / fConst0) * fConst59;
		float fConst62 = std::pow(0.001f, 0.9919395f / fConst0);
		fConst63 = mydsp_faustpower2_f(fConst62);
		fConst64 = 2.0f * std::cos(18829.701f / fConst0) * fConst62;
		float fConst65 = std::pow(0.001f, 0.98179346f / fConst0);
		fConst66 = mydsp_faustpower2_f(fConst65);
		fConst67 = 2.0f * std::cos(18802.809f / fConst0) * fConst65;
		float fConst68 = std::pow(0.001f, 0.7012868f / fConst0);
		fConst69 = mydsp_faustpower2_f(fConst68);
		fConst70 = 2.0f * std::cos(17858.824f / fConst0) * fConst68;
		float fConst71 = std::pow(0.001f, 0.67953837f / fConst0);
		fConst72 = mydsp_faustpower2_f(fConst71);
		fConst73 = 2.0f * std::cos(17763.758f / fConst0) * fConst71;
		float fConst74 = std::pow(0.001f, 0.5856073f / fConst0);
		fConst75 = mydsp_faustpower2_f(fConst74);
		fConst76 = 2.0f * std::cos(17298.3f / fConst0) * fConst74;
		float fConst77 = std::pow(0.001f, 0.58267206f / fConst0);
		fConst78 = mydsp_faustpower2_f(fConst77);
		fConst79 = 2.0f * std::cos(17282.09f / fConst0) * fConst77;
		float fConst80 = std::pow(0.001f, 0.580975f / fConst0);
		fConst81 = mydsp_faustpower2_f(fConst80);
		fConst82 = 2.0f * std::cos(17272.664f / fConst0) * fConst80;
		float fConst83 = std::pow(0.001f, 0.5687717f / fConst0);
		fConst84 = mydsp_faustpower2_f(fConst83);
		fConst85 = 2.0f * std::cos(17203.738f / fConst0) * fConst83;
		float fConst86 = std::pow(0.001f, 0.50018454f / fConst0);
		fConst87 = mydsp_faustpower2_f(fConst86);
		fConst88 = 2.0f * std::cos(16773.78f / fConst0) * fConst86;
		float fConst89 = std::pow(0.001f, 0.49948025f / fConst0);
		fConst90 = mydsp_faustpower2_f(fConst89);
		fConst91 = 2.0f * std::cos(16768.941f / fConst0) * fConst89;
		float fConst92 = std::pow(0.001f, 0.39274538f / fConst0);
		fConst93 = mydsp_faustpower2_f(fConst92);
		fConst94 = 2.0f * std::cos(15902.239f / fConst0) * fConst92;
		float fConst95 = std::pow(0.001f, 0.39134577f / fConst0);
		fConst96 = mydsp_faustpower2_f(fConst95);
		fConst97 = 2.0f * std::cos(15888.73f / fConst0) * fConst95;
		float fConst98 = std::pow(0.001f, 0.34248844f / fConst0);
		fConst99 = mydsp_faustpower2_f(fConst98);
		fConst100 = 2.0f * std::cos(15370.054f / fConst0) * fConst98;
		float fConst101 = std::pow(0.001f, 0.34146693f / fConst0);
		fConst102 = mydsp_faustpower2_f(fConst101);
		fConst103 = 2.0f * std::cos(15358.115f / fConst0) * fConst101;
		float fConst104 = std::pow(0.001f, 0.29868853f / fConst0);
		fConst105 = mydsp_faustpower2_f(fConst104);
		fConst106 = 2.0f * std::cos(14808.274f / fConst0) * fConst104;
		float fConst107 = std::pow(0.001f, 0.2133362f / fConst0);
		fConst108 = mydsp_faustpower2_f(fConst107);
		fConst109 = 2.0f * std::cos(13288.497f / fConst0) * fConst107;
		float fConst110 = std::pow(0.001f, 0.18220912f / fConst0);
		fConst111 = mydsp_faustpower2_f(fConst110);
		fConst112 = 2.0f * std::cos(12502.722f / fConst0) * fConst110;
		float fConst113 = std::pow(0.001f, 0.18117331f / fConst0);
		fConst114 = mydsp_faustpower2_f(fConst113);
		fConst115 = 2.0f * std::cos(12473.38f / fConst0) * fConst113;
		float fConst116 = std::pow(0.001f, 0.16025603f / fConst0);
		fConst117 = mydsp_faustpower2_f(fConst116);
		fConst118 = 2.0f * std::cos(11825.457f / fConst0) * fConst116;
		float fConst119 = std::pow(0.001f, 0.15741721f / fConst0);
		fConst120 = mydsp_faustpower2_f(fConst119);
		fConst121 = 2.0f * std::cos(11728.382f / fConst0) * fConst119;
		float fConst122 = std::pow(0.001f, 0.12780982f / fConst0);
		fConst123 = mydsp_faustpower2_f(fConst122);
		fConst124 = 2.0f * std::cos(10544.002f / fConst0) * fConst122;
		float fConst125 = std::pow(0.001f, 0.12776917f / fConst0);
		fConst126 = mydsp_faustpower2_f(fConst125);
		fConst127 = 2.0f * std::cos(10542.117f / fConst0) * fConst125;
		float fConst128 = std::pow(0.001f, 0.12368589f / fConst0);
		fConst129 = mydsp_faustpower2_f(fConst128);
		fConst130 = 2.0f * std::cos(10348.406f / fConst0) * fConst128;
		float fConst131 = std::pow(0.001f, 0.12358238f / fConst0);
		fConst132 = mydsp_faustpower2_f(fConst131);
		fConst133 = 2.0f * std::cos(10343.38f / fConst0) * fConst131;
		float fConst134 = std::pow(0.001f, 0.110012196f / fConst0);
		fConst135 = mydsp_faustpower2_f(fConst134);
		fConst136 = 2.0f * std::cos(9628.416f / fConst0) * fConst134;
		float fConst137 = std::pow(0.001f, 0.1070149f / fConst0);
		fConst138 = mydsp_faustpower2_f(fConst137);
		fConst139 = 2.0f * std::cos(9453.681f / fConst0) * fConst137;
		float fConst140 = std::pow(0.001f, 0.08750992f / fConst0);
		fConst141 = mydsp_faustpower2_f(fConst140);
		fConst142 = 2.0f * std::cos(8120.891f / fConst0) * fConst140;
		float fConst143 = std::pow(0.001f, 0.087489985f / fConst0);
		fConst144 = mydsp_faustpower2_f(fConst143);
		fConst145 = 2.0f * std::cos(8119.3203f / fConst0) * fConst143;
		float fConst146 = std::pow(0.001f, 0.072250575f / fConst0);
		fConst147 = mydsp_faustpower2_f(fConst146);
		fConst148 = 2.0f * std::cos(6748.015f / fConst0) * fConst146;
		float fConst149 = std::pow(0.001f, 0.07215856f / fConst0);
		fConst150 = mydsp_faustpower2_f(fConst149);
		fConst151 = 2.0f * std::cos(6738.528f / fConst0) * fConst149;
		float fConst152 = std::pow(0.001f, 0.061235286f / fConst0);
		fConst153 = mydsp_faustpower2_f(fConst152);
		fConst154 = 2.0f * std::cos(5475.18f / fConst0) * fConst152;
		float fConst155 = std::pow(0.001f, 0.06090948f / fConst0);
		fConst156 = mydsp_faustpower2_f(fConst155);
		fConst157 = 2.0f * std::cos(5432.7124f / fConst0) * fConst155;
		float fConst158 = std::pow(0.001f, 0.04495365f / fConst0);
		fConst159 = mydsp_faustpower2_f(fConst158);
		fConst160 = 2.0f * std::cos(2858.8494f / fConst0) * fConst158;
		float fConst161 = std::pow(0.001f, 0.04485706f / fConst0);
		fConst162 = mydsp_faustpower2_f(fConst161);
		fConst163 = 2.0f * std::cos(2839.4846f / fConst0) * fConst161;
		fConst164 = 44.1f / fConst0;
		fConst165 = 1.0f - fConst164;
		fConst166 = 0.0005663f * fConst0;
		fConst167 = 1.0f / (fConst1 + 1.0f);
	}
	
	virtual void instanceResetUserInterface() {
		fVslider0 = FAUSTFLOAT(0.0f);
		fEntry0 = FAUSTFLOAT(1e+04f);
		fHslider0 = FAUSTFLOAT(1e+02f);
		fVslider1 = FAUSTFLOAT(0.0f);
		fEntry1 = FAUSTFLOAT(9e+03f);
		fHslider1 = FAUSTFLOAT(1e+02f);
		fVslider2 = FAUSTFLOAT(0.0f);
		fEntry2 = FAUSTFLOAT(8e+03f);
		fHslider2 = FAUSTFLOAT(1e+02f);
		fVslider3 = FAUSTFLOAT(0.0f);
		fEntry3 = FAUSTFLOAT(7e+03f);
		fHslider3 = FAUSTFLOAT(1e+02f);
		fVslider4 = FAUSTFLOAT(0.0f);
		fEntry4 = FAUSTFLOAT(6e+03f);
		fHslider4 = FAUSTFLOAT(1e+02f);
		fVslider5 = FAUSTFLOAT(0.0f);
		fEntry5 = FAUSTFLOAT(5e+03f);
		fHslider5 = FAUSTFLOAT(1e+02f);
		fVslider6 = FAUSTFLOAT(0.0f);
		fEntry6 = FAUSTFLOAT(4e+03f);
		fHslider6 = FAUSTFLOAT(1e+02f);
		fVslider7 = FAUSTFLOAT(0.0f);
		fEntry7 = FAUSTFLOAT(3e+03f);
		fHslider7 = FAUSTFLOAT(1e+02f);
		fVslider8 = FAUSTFLOAT(0.0f);
		fEntry8 = FAUSTFLOAT(2e+03f);
		fHslider8 = FAUSTFLOAT(1e+02f);
		fVslider9 = FAUSTFLOAT(0.0f);
		fEntry9 = FAUSTFLOAT(1e+03f);
		fHslider9 = FAUSTFLOAT(1e+02f);
		fEntry10 = FAUSTFLOAT(0.0f);
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider10 = FAUSTFLOAT(0.5f);
		fHslider11 = FAUSTFLOAT(6.5e+03f);
		fHslider12 = FAUSTFLOAT(1.0f);
		fHslider13 = FAUSTFLOAT(1.0f);
		fHslider14 = FAUSTFLOAT(2.5e+02f);
		fHslider15 = FAUSTFLOAT(0.0f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = l0 + 1) {
			fVec0[l0] = 0.0f;
		}
		for (int l1 = 0; l1 < 2; l1 = l1 + 1) {
			iRec13[l1] = 0;
		}
		for (int l2 = 0; l2 < 2; l2 = l2 + 1) {
			iRec16[l2] = 0;
		}
		for (int l3 = 0; l3 < 3; l3 = l3 + 1) {
			fRec15[l3] = 0.0f;
		}
		for (int l4 = 0; l4 < 3; l4 = l4 + 1) {
			fRec14[l4] = 0.0f;
		}
		for (int l5 = 0; l5 < 3; l5 = l5 + 1) {
			fRec12[l5] = 0.0f;
		}
		for (int l6 = 0; l6 < 3; l6 = l6 + 1) {
			fRec17[l6] = 0.0f;
		}
		for (int l7 = 0; l7 < 3; l7 = l7 + 1) {
			fRec18[l7] = 0.0f;
		}
		for (int l8 = 0; l8 < 3; l8 = l8 + 1) {
			fRec19[l8] = 0.0f;
		}
		for (int l9 = 0; l9 < 3; l9 = l9 + 1) {
			fRec20[l9] = 0.0f;
		}
		for (int l10 = 0; l10 < 3; l10 = l10 + 1) {
			fRec21[l10] = 0.0f;
		}
		for (int l11 = 0; l11 < 3; l11 = l11 + 1) {
			fRec22[l11] = 0.0f;
		}
		for (int l12 = 0; l12 < 3; l12 = l12 + 1) {
			fRec23[l12] = 0.0f;
		}
		for (int l13 = 0; l13 < 3; l13 = l13 + 1) {
			fRec24[l13] = 0.0f;
		}
		for (int l14 = 0; l14 < 3; l14 = l14 + 1) {
			fRec25[l14] = 0.0f;
		}
		for (int l15 = 0; l15 < 3; l15 = l15 + 1) {
			fRec26[l15] = 0.0f;
		}
		for (int l16 = 0; l16 < 3; l16 = l16 + 1) {
			fRec27[l16] = 0.0f;
		}
		for (int l17 = 0; l17 < 3; l17 = l17 + 1) {
			fRec28[l17] = 0.0f;
		}
		for (int l18 = 0; l18 < 3; l18 = l18 + 1) {
			fRec29[l18] = 0.0f;
		}
		for (int l19 = 0; l19 < 3; l19 = l19 + 1) {
			fRec30[l19] = 0.0f;
		}
		for (int l20 = 0; l20 < 3; l20 = l20 + 1) {
			fRec31[l20] = 0.0f;
		}
		for (int l21 = 0; l21 < 3; l21 = l21 + 1) {
			fRec32[l21] = 0.0f;
		}
		for (int l22 = 0; l22 < 3; l22 = l22 + 1) {
			fRec33[l22] = 0.0f;
		}
		for (int l23 = 0; l23 < 3; l23 = l23 + 1) {
			fRec34[l23] = 0.0f;
		}
		for (int l24 = 0; l24 < 3; l24 = l24 + 1) {
			fRec35[l24] = 0.0f;
		}
		for (int l25 = 0; l25 < 3; l25 = l25 + 1) {
			fRec36[l25] = 0.0f;
		}
		for (int l26 = 0; l26 < 3; l26 = l26 + 1) {
			fRec37[l26] = 0.0f;
		}
		for (int l27 = 0; l27 < 3; l27 = l27 + 1) {
			fRec38[l27] = 0.0f;
		}
		for (int l28 = 0; l28 < 3; l28 = l28 + 1) {
			fRec39[l28] = 0.0f;
		}
		for (int l29 = 0; l29 < 3; l29 = l29 + 1) {
			fRec40[l29] = 0.0f;
		}
		for (int l30 = 0; l30 < 3; l30 = l30 + 1) {
			fRec41[l30] = 0.0f;
		}
		for (int l31 = 0; l31 < 3; l31 = l31 + 1) {
			fRec42[l31] = 0.0f;
		}
		for (int l32 = 0; l32 < 3; l32 = l32 + 1) {
			fRec43[l32] = 0.0f;
		}
		for (int l33 = 0; l33 < 3; l33 = l33 + 1) {
			fRec44[l33] = 0.0f;
		}
		for (int l34 = 0; l34 < 3; l34 = l34 + 1) {
			fRec45[l34] = 0.0f;
		}
		for (int l35 = 0; l35 < 3; l35 = l35 + 1) {
			fRec46[l35] = 0.0f;
		}
		for (int l36 = 0; l36 < 3; l36 = l36 + 1) {
			fRec47[l36] = 0.0f;
		}
		for (int l37 = 0; l37 < 3; l37 = l37 + 1) {
			fRec48[l37] = 0.0f;
		}
		for (int l38 = 0; l38 < 3; l38 = l38 + 1) {
			fRec49[l38] = 0.0f;
		}
		for (int l39 = 0; l39 < 3; l39 = l39 + 1) {
			fRec50[l39] = 0.0f;
		}
		for (int l40 = 0; l40 < 3; l40 = l40 + 1) {
			fRec51[l40] = 0.0f;
		}
		for (int l41 = 0; l41 < 3; l41 = l41 + 1) {
			fRec52[l41] = 0.0f;
		}
		for (int l42 = 0; l42 < 3; l42 = l42 + 1) {
			fRec53[l42] = 0.0f;
		}
		for (int l43 = 0; l43 < 3; l43 = l43 + 1) {
			fRec54[l43] = 0.0f;
		}
		for (int l44 = 0; l44 < 3; l44 = l44 + 1) {
			fRec55[l44] = 0.0f;
		}
		for (int l45 = 0; l45 < 3; l45 = l45 + 1) {
			fRec56[l45] = 0.0f;
		}
		for (int l46 = 0; l46 < 3; l46 = l46 + 1) {
			fRec57[l46] = 0.0f;
		}
		for (int l47 = 0; l47 < 3; l47 = l47 + 1) {
			fRec58[l47] = 0.0f;
		}
		for (int l48 = 0; l48 < 3; l48 = l48 + 1) {
			fRec59[l48] = 0.0f;
		}
		for (int l49 = 0; l49 < 3; l49 = l49 + 1) {
			fRec60[l49] = 0.0f;
		}
		for (int l50 = 0; l50 < 3; l50 = l50 + 1) {
			fRec61[l50] = 0.0f;
		}
		for (int l51 = 0; l51 < 3; l51 = l51 + 1) {
			fRec62[l51] = 0.0f;
		}
		for (int l52 = 0; l52 < 3; l52 = l52 + 1) {
			fRec63[l52] = 0.0f;
		}
		for (int l53 = 0; l53 < 3; l53 = l53 + 1) {
			fRec64[l53] = 0.0f;
		}
		for (int l54 = 0; l54 < 3; l54 = l54 + 1) {
			fRec65[l54] = 0.0f;
		}
		for (int l55 = 0; l55 < 2; l55 = l55 + 1) {
			fRec66[l55] = 0.0f;
		}
		IOTA0 = 0;
		for (int l56 = 0; l56 < 2; l56 = l56 + 1) {
			fRec68[l56] = 0.0f;
		}
		for (int l57 = 0; l57 < 2; l57 = l57 + 1) {
			fRec69[l57] = 0.0f;
		}
		for (int l58 = 0; l58 < 131072; l58 = l58 + 1) {
			fRec67[l58] = 0.0f;
		}
		for (int l59 = 0; l59 < 3; l59 = l59 + 1) {
			fRec11[l59] = 0.0f;
		}
		for (int l60 = 0; l60 < 3; l60 = l60 + 1) {
			fRec10[l60] = 0.0f;
		}
		for (int l61 = 0; l61 < 3; l61 = l61 + 1) {
			fRec9[l61] = 0.0f;
		}
		for (int l62 = 0; l62 < 3; l62 = l62 + 1) {
			fRec8[l62] = 0.0f;
		}
		for (int l63 = 0; l63 < 3; l63 = l63 + 1) {
			fRec7[l63] = 0.0f;
		}
		for (int l64 = 0; l64 < 3; l64 = l64 + 1) {
			fRec6[l64] = 0.0f;
		}
		for (int l65 = 0; l65 < 3; l65 = l65 + 1) {
			fRec5[l65] = 0.0f;
		}
		for (int l66 = 0; l66 < 3; l66 = l66 + 1) {
			fRec4[l66] = 0.0f;
		}
		for (int l67 = 0; l67 < 3; l67 = l67 + 1) {
			fRec3[l67] = 0.0f;
		}
		for (int l68 = 0; l68 < 3; l68 = l68 + 1) {
			fRec2[l68] = 0.0f;
		}
		for (int l69 = 0; l69 < 2; l69 = l69 + 1) {
			fVec1[l69] = 0.0f;
		}
		for (int l70 = 0; l70 < 2; l70 = l70 + 1) {
			fRec1[l70] = 0.0f;
		}
		for (int l71 = 0; l71 < 2; l71 = l71 + 1) {
			fRec0[l71] = 0.0f;
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
		ui_interface->openHorizontalBox("Echo Filter");
		ui_interface->declare(&fHslider14, "1", "");
		ui_interface->declare(&fHslider14, "style", "knob");
		ui_interface->addHorizontalSlider("Time (ms)", &fHslider14, FAUSTFLOAT(2.5e+02f), FAUSTFLOAT(0.1f), FAUSTFLOAT(1e+03f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fHslider15, "2", "");
		ui_interface->declare(&fHslider15, "style", "knob");
		ui_interface->addHorizontalSlider("Feedback", &fHslider15, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0001f));
		ui_interface->declare(&fHslider13, "3", "");
		ui_interface->declare(&fHslider13, "style", "knob");
		ui_interface->addHorizontalSlider("Dry", &fHslider13, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->closeBox();
		ui_interface->openHorizontalBox("Parametric EQ");
		ui_interface->openHorizontalBox("Band- 0");
		ui_interface->declare(&fEntry9, "1", "");
		ui_interface->addNumEntry("Freq", &fEntry9, FAUSTFLOAT(1e+03f), FAUSTFLOAT(0.0f), FAUSTFLOAT(2e+04f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fHslider9, "2", "");
		ui_interface->declare(&fHslider9, "style", "knob");
		ui_interface->addHorizontalSlider("Q factor", &fHslider9, FAUSTFLOAT(1e+02f), FAUSTFLOAT(1.0f), FAUSTFLOAT(4.41e+04f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fVslider9, "3", "");
		ui_interface->addVerticalSlider("Peak / Notch", &fVslider9, FAUSTFLOAT(0.0f), FAUSTFLOAT(-6e+01f), FAUSTFLOAT(1e+01f), FAUSTFLOAT(0.1f));
		ui_interface->closeBox();
		ui_interface->openHorizontalBox("Band- 1");
		ui_interface->declare(&fEntry8, "1", "");
		ui_interface->addNumEntry("Freq", &fEntry8, FAUSTFLOAT(2e+03f), FAUSTFLOAT(0.0f), FAUSTFLOAT(2e+04f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fHslider8, "2", "");
		ui_interface->declare(&fHslider8, "style", "knob");
		ui_interface->addHorizontalSlider("Q factor", &fHslider8, FAUSTFLOAT(1e+02f), FAUSTFLOAT(1.0f), FAUSTFLOAT(4.41e+04f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fVslider8, "3", "");
		ui_interface->addVerticalSlider("Peak / Notch", &fVslider8, FAUSTFLOAT(0.0f), FAUSTFLOAT(-6e+01f), FAUSTFLOAT(1e+01f), FAUSTFLOAT(0.1f));
		ui_interface->closeBox();
		ui_interface->openHorizontalBox("Band- 2");
		ui_interface->declare(&fEntry7, "1", "");
		ui_interface->addNumEntry("Freq", &fEntry7, FAUSTFLOAT(3e+03f), FAUSTFLOAT(0.0f), FAUSTFLOAT(2e+04f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fHslider7, "2", "");
		ui_interface->declare(&fHslider7, "style", "knob");
		ui_interface->addHorizontalSlider("Q factor", &fHslider7, FAUSTFLOAT(1e+02f), FAUSTFLOAT(1.0f), FAUSTFLOAT(4.41e+04f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fVslider7, "3", "");
		ui_interface->addVerticalSlider("Peak / Notch", &fVslider7, FAUSTFLOAT(0.0f), FAUSTFLOAT(-6e+01f), FAUSTFLOAT(1e+01f), FAUSTFLOAT(0.1f));
		ui_interface->closeBox();
		ui_interface->openHorizontalBox("Band- 3");
		ui_interface->declare(&fEntry6, "1", "");
		ui_interface->addNumEntry("Freq", &fEntry6, FAUSTFLOAT(4e+03f), FAUSTFLOAT(0.0f), FAUSTFLOAT(2e+04f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fHslider6, "2", "");
		ui_interface->declare(&fHslider6, "style", "knob");
		ui_interface->addHorizontalSlider("Q factor", &fHslider6, FAUSTFLOAT(1e+02f), FAUSTFLOAT(1.0f), FAUSTFLOAT(4.41e+04f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fVslider6, "3", "");
		ui_interface->addVerticalSlider("Peak / Notch", &fVslider6, FAUSTFLOAT(0.0f), FAUSTFLOAT(-6e+01f), FAUSTFLOAT(1e+01f), FAUSTFLOAT(0.1f));
		ui_interface->closeBox();
		ui_interface->openHorizontalBox("Band- 4");
		ui_interface->declare(&fEntry5, "1", "");
		ui_interface->addNumEntry("Freq", &fEntry5, FAUSTFLOAT(5e+03f), FAUSTFLOAT(0.0f), FAUSTFLOAT(2e+04f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fHslider5, "2", "");
		ui_interface->declare(&fHslider5, "style", "knob");
		ui_interface->addHorizontalSlider("Q factor", &fHslider5, FAUSTFLOAT(1e+02f), FAUSTFLOAT(1.0f), FAUSTFLOAT(4.41e+04f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fVslider5, "3", "");
		ui_interface->addVerticalSlider("Peak / Notch", &fVslider5, FAUSTFLOAT(0.0f), FAUSTFLOAT(-6e+01f), FAUSTFLOAT(1e+01f), FAUSTFLOAT(0.1f));
		ui_interface->closeBox();
		ui_interface->openHorizontalBox("Band- 5");
		ui_interface->declare(&fEntry4, "1", "");
		ui_interface->addNumEntry("Freq", &fEntry4, FAUSTFLOAT(6e+03f), FAUSTFLOAT(0.0f), FAUSTFLOAT(2e+04f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fHslider4, "2", "");
		ui_interface->declare(&fHslider4, "style", "knob");
		ui_interface->addHorizontalSlider("Q factor", &fHslider4, FAUSTFLOAT(1e+02f), FAUSTFLOAT(1.0f), FAUSTFLOAT(4.41e+04f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fVslider4, "3", "");
		ui_interface->addVerticalSlider("Peak / Notch", &fVslider4, FAUSTFLOAT(0.0f), FAUSTFLOAT(-6e+01f), FAUSTFLOAT(1e+01f), FAUSTFLOAT(0.1f));
		ui_interface->closeBox();
		ui_interface->openHorizontalBox("Band- 6");
		ui_interface->declare(&fEntry3, "1", "");
		ui_interface->addNumEntry("Freq", &fEntry3, FAUSTFLOAT(7e+03f), FAUSTFLOAT(0.0f), FAUSTFLOAT(2e+04f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fHslider3, "2", "");
		ui_interface->declare(&fHslider3, "style", "knob");
		ui_interface->addHorizontalSlider("Q factor", &fHslider3, FAUSTFLOAT(1e+02f), FAUSTFLOAT(1.0f), FAUSTFLOAT(4.41e+04f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fVslider3, "3", "");
		ui_interface->addVerticalSlider("Peak / Notch", &fVslider3, FAUSTFLOAT(0.0f), FAUSTFLOAT(-6e+01f), FAUSTFLOAT(1e+01f), FAUSTFLOAT(0.1f));
		ui_interface->closeBox();
		ui_interface->openHorizontalBox("Band- 7");
		ui_interface->declare(&fEntry2, "1", "");
		ui_interface->addNumEntry("Freq", &fEntry2, FAUSTFLOAT(8e+03f), FAUSTFLOAT(0.0f), FAUSTFLOAT(2e+04f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fHslider2, "2", "");
		ui_interface->declare(&fHslider2, "style", "knob");
		ui_interface->addHorizontalSlider("Q factor", &fHslider2, FAUSTFLOAT(1e+02f), FAUSTFLOAT(1.0f), FAUSTFLOAT(4.41e+04f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fVslider2, "3", "");
		ui_interface->addVerticalSlider("Peak / Notch", &fVslider2, FAUSTFLOAT(0.0f), FAUSTFLOAT(-6e+01f), FAUSTFLOAT(1e+01f), FAUSTFLOAT(0.1f));
		ui_interface->closeBox();
		ui_interface->openHorizontalBox("Band- 8");
		ui_interface->declare(&fEntry1, "1", "");
		ui_interface->addNumEntry("Freq", &fEntry1, FAUSTFLOAT(9e+03f), FAUSTFLOAT(0.0f), FAUSTFLOAT(2e+04f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fHslider1, "2", "");
		ui_interface->declare(&fHslider1, "style", "knob");
		ui_interface->addHorizontalSlider("Q factor", &fHslider1, FAUSTFLOAT(1e+02f), FAUSTFLOAT(1.0f), FAUSTFLOAT(4.41e+04f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fVslider1, "3", "");
		ui_interface->addVerticalSlider("Peak / Notch", &fVslider1, FAUSTFLOAT(0.0f), FAUSTFLOAT(-6e+01f), FAUSTFLOAT(1e+01f), FAUSTFLOAT(0.1f));
		ui_interface->closeBox();
		ui_interface->openHorizontalBox("Band- 9");
		ui_interface->declare(&fEntry0, "1", "");
		ui_interface->addNumEntry("Freq", &fEntry0, FAUSTFLOAT(1e+04f), FAUSTFLOAT(0.0f), FAUSTFLOAT(2e+04f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fHslider0, "2", "");
		ui_interface->declare(&fHslider0, "style", "knob");
		ui_interface->addHorizontalSlider("Q factor", &fHslider0, FAUSTFLOAT(1e+02f), FAUSTFLOAT(1.0f), FAUSTFLOAT(4.41e+04f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fVslider0, "3", "");
		ui_interface->addVerticalSlider("Peak / Notch", &fVslider0, FAUSTFLOAT(0.0f), FAUSTFLOAT(-6e+01f), FAUSTFLOAT(1e+01f), FAUSTFLOAT(0.1f));
		ui_interface->closeBox();
		ui_interface->closeBox();
		ui_interface->declare(0, "0", "");
		ui_interface->openVerticalBox("Church Bell");
		ui_interface->openVerticalBox("churchBell");
		ui_interface->declare(&fEntry10, "0", "");
		ui_interface->addNumEntry("strikePosition", &fEntry10, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(4.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider11, "1", "");
		ui_interface->addHorizontalSlider("strikeCutoff", &fHslider11, FAUSTFLOAT(6.5e+03f), FAUSTFLOAT(2e+01f), FAUSTFLOAT(2e+04f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider10, "2", "");
		ui_interface->addHorizontalSlider("strikeSharpness", &fHslider10, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.01f), FAUSTFLOAT(5.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider12, "3", "");
		ui_interface->addHorizontalSlider("gain", &fHslider12, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fButton0, "4", "");
		ui_interface->addButton("gate", &fButton0);
		ui_interface->closeBox();
		ui_interface->closeBox();
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = float(fVslider0);
		int iSlow1 = fSlow0 > 0.0f;
		float fSlow2 = float(fEntry0);
		float fSlow3 = std::sin(fConst3 * fSlow2);
		float fSlow4 = float(fHslider0);
		float fSlow5 = fConst4 * (fSlow4 * std::pow(1e+01f, 0.05f * std::fabs(fSlow0)) / fSlow3);
		float fSlow6 = fConst4 * (fSlow4 / fSlow3);
		float fSlow7 = ((iSlow1) ? fSlow6 : fSlow5);
		float fSlow8 = std::tan(fConst4 * fSlow2);
		float fSlow9 = 1.0f / fSlow8;
		float fSlow10 = fSlow9 * (fSlow9 + fSlow7) + 1.0f;
		float fSlow11 = ((iSlow1) ? fSlow5 : fSlow6);
		float fSlow12 = fSlow9 * (fSlow9 - fSlow11) + 1.0f;
		float fSlow13 = 2.0f * (1.0f - 1.0f / mydsp_faustpower2_f(fSlow8));
		float fSlow14 = fSlow9 * (fSlow9 - fSlow7) + 1.0f;
		float fSlow15 = float(fVslider1);
		int iSlow16 = fSlow15 > 0.0f;
		float fSlow17 = float(fEntry1);
		float fSlow18 = std::sin(fConst3 * fSlow17);
		float fSlow19 = float(fHslider1);
		float fSlow20 = fConst4 * (fSlow19 * std::pow(1e+01f, 0.05f * std::fabs(fSlow15)) / fSlow18);
		float fSlow21 = fConst4 * (fSlow19 / fSlow18);
		float fSlow22 = ((iSlow16) ? fSlow21 : fSlow20);
		float fSlow23 = std::tan(fConst4 * fSlow17);
		float fSlow24 = 1.0f / fSlow23;
		float fSlow25 = fSlow24 * (fSlow24 + fSlow22) + 1.0f;
		float fSlow26 = ((iSlow16) ? fSlow20 : fSlow21);
		float fSlow27 = fSlow24 * (fSlow24 - fSlow26) + 1.0f;
		float fSlow28 = 2.0f * (1.0f - 1.0f / mydsp_faustpower2_f(fSlow23));
		float fSlow29 = fSlow24 * (fSlow24 - fSlow22) + 1.0f;
		float fSlow30 = float(fVslider2);
		int iSlow31 = fSlow30 > 0.0f;
		float fSlow32 = float(fEntry2);
		float fSlow33 = std::sin(fConst3 * fSlow32);
		float fSlow34 = float(fHslider2);
		float fSlow35 = fConst4 * (fSlow34 * std::pow(1e+01f, 0.05f * std::fabs(fSlow30)) / fSlow33);
		float fSlow36 = fConst4 * (fSlow34 / fSlow33);
		float fSlow37 = ((iSlow31) ? fSlow36 : fSlow35);
		float fSlow38 = std::tan(fConst4 * fSlow32);
		float fSlow39 = 1.0f / fSlow38;
		float fSlow40 = fSlow39 * (fSlow39 + fSlow37) + 1.0f;
		float fSlow41 = ((iSlow31) ? fSlow35 : fSlow36);
		float fSlow42 = fSlow39 * (fSlow39 - fSlow41) + 1.0f;
		float fSlow43 = 2.0f * (1.0f - 1.0f / mydsp_faustpower2_f(fSlow38));
		float fSlow44 = fSlow39 * (fSlow39 - fSlow37) + 1.0f;
		float fSlow45 = float(fVslider3);
		int iSlow46 = fSlow45 > 0.0f;
		float fSlow47 = float(fEntry3);
		float fSlow48 = std::sin(fConst3 * fSlow47);
		float fSlow49 = float(fHslider3);
		float fSlow50 = fConst4 * (fSlow49 * std::pow(1e+01f, 0.05f * std::fabs(fSlow45)) / fSlow48);
		float fSlow51 = fConst4 * (fSlow49 / fSlow48);
		float fSlow52 = ((iSlow46) ? fSlow51 : fSlow50);
		float fSlow53 = std::tan(fConst4 * fSlow47);
		float fSlow54 = 1.0f / fSlow53;
		float fSlow55 = fSlow54 * (fSlow54 + fSlow52) + 1.0f;
		float fSlow56 = ((iSlow46) ? fSlow50 : fSlow51);
		float fSlow57 = fSlow54 * (fSlow54 - fSlow56) + 1.0f;
		float fSlow58 = 2.0f * (1.0f - 1.0f / mydsp_faustpower2_f(fSlow53));
		float fSlow59 = fSlow54 * (fSlow54 - fSlow52) + 1.0f;
		float fSlow60 = float(fVslider4);
		int iSlow61 = fSlow60 > 0.0f;
		float fSlow62 = float(fEntry4);
		float fSlow63 = std::sin(fConst3 * fSlow62);
		float fSlow64 = float(fHslider4);
		float fSlow65 = fConst4 * (fSlow64 * std::pow(1e+01f, 0.05f * std::fabs(fSlow60)) / fSlow63);
		float fSlow66 = fConst4 * (fSlow64 / fSlow63);
		float fSlow67 = ((iSlow61) ? fSlow66 : fSlow65);
		float fSlow68 = std::tan(fConst4 * fSlow62);
		float fSlow69 = 1.0f / fSlow68;
		float fSlow70 = fSlow69 * (fSlow69 + fSlow67) + 1.0f;
		float fSlow71 = ((iSlow61) ? fSlow65 : fSlow66);
		float fSlow72 = fSlow69 * (fSlow69 - fSlow71) + 1.0f;
		float fSlow73 = 2.0f * (1.0f - 1.0f / mydsp_faustpower2_f(fSlow68));
		float fSlow74 = fSlow69 * (fSlow69 - fSlow67) + 1.0f;
		float fSlow75 = float(fVslider5);
		int iSlow76 = fSlow75 > 0.0f;
		float fSlow77 = float(fEntry5);
		float fSlow78 = std::sin(fConst3 * fSlow77);
		float fSlow79 = float(fHslider5);
		float fSlow80 = fConst4 * (fSlow79 * std::pow(1e+01f, 0.05f * std::fabs(fSlow75)) / fSlow78);
		float fSlow81 = fConst4 * (fSlow79 / fSlow78);
		float fSlow82 = ((iSlow76) ? fSlow81 : fSlow80);
		float fSlow83 = std::tan(fConst4 * fSlow77);
		float fSlow84 = 1.0f / fSlow83;
		float fSlow85 = fSlow84 * (fSlow84 + fSlow82) + 1.0f;
		float fSlow86 = ((iSlow76) ? fSlow80 : fSlow81);
		float fSlow87 = fSlow84 * (fSlow84 - fSlow86) + 1.0f;
		float fSlow88 = 2.0f * (1.0f - 1.0f / mydsp_faustpower2_f(fSlow83));
		float fSlow89 = fSlow84 * (fSlow84 - fSlow82) + 1.0f;
		float fSlow90 = float(fVslider6);
		int iSlow91 = fSlow90 > 0.0f;
		float fSlow92 = float(fEntry6);
		float fSlow93 = std::sin(fConst3 * fSlow92);
		float fSlow94 = float(fHslider6);
		float fSlow95 = fConst4 * (fSlow94 * std::pow(1e+01f, 0.05f * std::fabs(fSlow90)) / fSlow93);
		float fSlow96 = fConst4 * (fSlow94 / fSlow93);
		float fSlow97 = ((iSlow91) ? fSlow96 : fSlow95);
		float fSlow98 = std::tan(fConst4 * fSlow92);
		float fSlow99 = 1.0f / fSlow98;
		float fSlow100 = fSlow99 * (fSlow99 + fSlow97) + 1.0f;
		float fSlow101 = ((iSlow91) ? fSlow95 : fSlow96);
		float fSlow102 = fSlow99 * (fSlow99 - fSlow101) + 1.0f;
		float fSlow103 = 2.0f * (1.0f - 1.0f / mydsp_faustpower2_f(fSlow98));
		float fSlow104 = fSlow99 * (fSlow99 - fSlow97) + 1.0f;
		float fSlow105 = float(fVslider7);
		int iSlow106 = fSlow105 > 0.0f;
		float fSlow107 = float(fEntry7);
		float fSlow108 = std::sin(fConst3 * fSlow107);
		float fSlow109 = float(fHslider7);
		float fSlow110 = fConst4 * (fSlow109 * std::pow(1e+01f, 0.05f * std::fabs(fSlow105)) / fSlow108);
		float fSlow111 = fConst4 * (fSlow109 / fSlow108);
		float fSlow112 = ((iSlow106) ? fSlow111 : fSlow110);
		float fSlow113 = std::tan(fConst4 * fSlow107);
		float fSlow114 = 1.0f / fSlow113;
		float fSlow115 = fSlow114 * (fSlow114 + fSlow112) + 1.0f;
		float fSlow116 = ((iSlow106) ? fSlow110 : fSlow111);
		float fSlow117 = fSlow114 * (fSlow114 - fSlow116) + 1.0f;
		float fSlow118 = 2.0f * (1.0f - 1.0f / mydsp_faustpower2_f(fSlow113));
		float fSlow119 = fSlow114 * (fSlow114 - fSlow112) + 1.0f;
		float fSlow120 = float(fVslider8);
		int iSlow121 = fSlow120 > 0.0f;
		float fSlow122 = float(fEntry8);
		float fSlow123 = std::sin(fConst3 * fSlow122);
		float fSlow124 = float(fHslider8);
		float fSlow125 = fConst4 * (fSlow124 * std::pow(1e+01f, 0.05f * std::fabs(fSlow120)) / fSlow123);
		float fSlow126 = fConst4 * (fSlow124 / fSlow123);
		float fSlow127 = ((iSlow121) ? fSlow126 : fSlow125);
		float fSlow128 = std::tan(fConst4 * fSlow122);
		float fSlow129 = 1.0f / fSlow128;
		float fSlow130 = fSlow129 * (fSlow129 + fSlow127) + 1.0f;
		float fSlow131 = ((iSlow121) ? fSlow125 : fSlow126);
		float fSlow132 = fSlow129 * (fSlow129 - fSlow131) + 1.0f;
		float fSlow133 = 2.0f * (1.0f - 1.0f / mydsp_faustpower2_f(fSlow128));
		float fSlow134 = fSlow129 * (fSlow129 - fSlow127) + 1.0f;
		float fSlow135 = float(fVslider9);
		int iSlow136 = fSlow135 > 0.0f;
		float fSlow137 = float(fEntry9);
		float fSlow138 = std::sin(fConst3 * fSlow137);
		float fSlow139 = float(fHslider9);
		float fSlow140 = fConst4 * (fSlow139 * std::pow(1e+01f, 0.05f * std::fabs(fSlow135)) / fSlow138);
		float fSlow141 = fConst4 * (fSlow139 / fSlow138);
		float fSlow142 = ((iSlow136) ? fSlow141 : fSlow140);
		float fSlow143 = std::tan(fConst4 * fSlow137);
		float fSlow144 = 1.0f / fSlow143;
		float fSlow145 = fSlow144 * (fSlow144 + fSlow142) + 1.0f;
		float fSlow146 = ((iSlow136) ? fSlow140 : fSlow141);
		float fSlow147 = fSlow144 * (fSlow144 - fSlow146) + 1.0f;
		float fSlow148 = 2.0f * (1.0f - 1.0f / mydsp_faustpower2_f(fSlow143));
		float fSlow149 = fSlow144 * (fSlow144 - fSlow142) + 1.0f;
		int iSlow150 = 50 * int(float(fEntry10));
		float fSlow151 = ftbl0mydspSIG0[iSlow150 + 49];
		float fSlow152 = float(fButton0);
		float fSlow153 = 1.0f / std::max<float>(1.0f, fConst8 * float(fHslider10));
		float fSlow154 = std::tan(fConst4 * float(fHslider11));
		float fSlow155 = 2.0f * (1.0f - 1.0f / mydsp_faustpower2_f(fSlow154));
		float fSlow156 = 1.0f / fSlow154;
		float fSlow157 = (fSlow156 + -1.4142135f) / fSlow154 + 1.0f;
		float fSlow158 = (fSlow156 + 1.4142135f) / fSlow154 + 1.0f;
		float fSlow159 = 1.0f / fSlow158;
		float fSlow160 = float(fHslider12) / fSlow158;
		float fSlow161 = ftbl0mydspSIG0[iSlow150 + 48];
		float fSlow162 = ftbl0mydspSIG0[iSlow150 + 47];
		float fSlow163 = ftbl0mydspSIG0[iSlow150 + 46];
		float fSlow164 = ftbl0mydspSIG0[iSlow150 + 45];
		float fSlow165 = ftbl0mydspSIG0[iSlow150 + 44];
		float fSlow166 = ftbl0mydspSIG0[iSlow150 + 43];
		float fSlow167 = ftbl0mydspSIG0[iSlow150 + 42];
		float fSlow168 = ftbl0mydspSIG0[iSlow150 + 41];
		float fSlow169 = ftbl0mydspSIG0[iSlow150 + 40];
		float fSlow170 = ftbl0mydspSIG0[iSlow150 + 39];
		float fSlow171 = ftbl0mydspSIG0[iSlow150 + 38];
		float fSlow172 = ftbl0mydspSIG0[iSlow150 + 37];
		float fSlow173 = ftbl0mydspSIG0[iSlow150 + 36];
		float fSlow174 = ftbl0mydspSIG0[iSlow150 + 35];
		float fSlow175 = ftbl0mydspSIG0[iSlow150 + 34];
		float fSlow176 = ftbl0mydspSIG0[iSlow150 + 33];
		float fSlow177 = ftbl0mydspSIG0[iSlow150 + 32];
		float fSlow178 = ftbl0mydspSIG0[iSlow150 + 31];
		float fSlow179 = ftbl0mydspSIG0[iSlow150 + 30];
		float fSlow180 = ftbl0mydspSIG0[iSlow150 + 29];
		float fSlow181 = ftbl0mydspSIG0[iSlow150 + 28];
		float fSlow182 = ftbl0mydspSIG0[iSlow150 + 27];
		float fSlow183 = ftbl0mydspSIG0[iSlow150 + 26];
		float fSlow184 = ftbl0mydspSIG0[iSlow150 + 25];
		float fSlow185 = ftbl0mydspSIG0[iSlow150 + 24];
		float fSlow186 = ftbl0mydspSIG0[iSlow150 + 23];
		float fSlow187 = ftbl0mydspSIG0[iSlow150 + 22];
		float fSlow188 = ftbl0mydspSIG0[iSlow150 + 21];
		float fSlow189 = ftbl0mydspSIG0[iSlow150 + 20];
		float fSlow190 = ftbl0mydspSIG0[iSlow150 + 19];
		float fSlow191 = ftbl0mydspSIG0[iSlow150 + 18];
		float fSlow192 = ftbl0mydspSIG0[iSlow150 + 17];
		float fSlow193 = ftbl0mydspSIG0[iSlow150 + 16];
		float fSlow194 = ftbl0mydspSIG0[iSlow150 + 15];
		float fSlow195 = ftbl0mydspSIG0[iSlow150 + 14];
		float fSlow196 = ftbl0mydspSIG0[iSlow150 + 13];
		float fSlow197 = ftbl0mydspSIG0[iSlow150 + 12];
		float fSlow198 = ftbl0mydspSIG0[iSlow150 + 11];
		float fSlow199 = ftbl0mydspSIG0[iSlow150 + 10];
		float fSlow200 = ftbl0mydspSIG0[iSlow150 + 9];
		float fSlow201 = ftbl0mydspSIG0[iSlow150 + 8];
		float fSlow202 = ftbl0mydspSIG0[iSlow150 + 7];
		float fSlow203 = ftbl0mydspSIG0[iSlow150 + 6];
		float fSlow204 = ftbl0mydspSIG0[iSlow150 + 5];
		float fSlow205 = ftbl0mydspSIG0[iSlow150 + 4];
		float fSlow206 = ftbl0mydspSIG0[iSlow150 + 3];
		float fSlow207 = ftbl0mydspSIG0[iSlow150 + 2];
		float fSlow208 = ftbl0mydspSIG0[iSlow150 + 1];
		float fSlow209 = ftbl0mydspSIG0[iSlow150];
		float fSlow210 = fConst164 * float(fHslider13);
		float fSlow211 = fConst166 * float(fHslider14);
		float fSlow212 = fConst164 * float(fHslider15);
		float fSlow213 = fSlow144 * (fSlow144 + fSlow146) + 1.0f;
		float fSlow214 = fSlow129 * (fSlow129 + fSlow131) + 1.0f;
		float fSlow215 = fSlow114 * (fSlow114 + fSlow116) + 1.0f;
		float fSlow216 = fSlow99 * (fSlow99 + fSlow101) + 1.0f;
		float fSlow217 = fSlow84 * (fSlow84 + fSlow86) + 1.0f;
		float fSlow218 = fSlow69 * (fSlow69 + fSlow71) + 1.0f;
		float fSlow219 = fSlow54 * (fSlow54 + fSlow56) + 1.0f;
		float fSlow220 = fSlow39 * (fSlow39 + fSlow41) + 1.0f;
		float fSlow221 = fSlow24 * (fSlow24 + fSlow26) + 1.0f;
		float fSlow222 = fSlow9 * (fSlow9 + fSlow11) + 1.0f;
		for (int i0 = 0; i0 < count; i0 = i0 + 1) {
			float fTemp0 = fSlow13 * fRec2[1];
			float fTemp1 = fSlow28 * fRec3[1];
			float fTemp2 = fSlow43 * fRec4[1];
			float fTemp3 = fSlow58 * fRec5[1];
			float fTemp4 = fSlow73 * fRec6[1];
			float fTemp5 = fSlow88 * fRec7[1];
			float fTemp6 = fSlow103 * fRec8[1];
			float fTemp7 = fSlow118 * fRec9[1];
			float fTemp8 = fSlow133 * fRec10[1];
			float fTemp9 = fSlow148 * fRec11[1];
			fVec0[0] = fSlow152;
			iRec13[0] = (iRec13[1] + (iRec13[1] > 0)) * (fSlow152 <= fVec0[1]) + (fSlow152 > fVec0[1]);
			float fTemp10 = fSlow153 * float(iRec13[0]);
			iRec16[0] = 1103515245 * iRec16[1] + 12345;
			fRec15[0] = 4.656613e-10f * float(iRec16[0]) - fConst15 * (fConst13 * fRec15[2] + fConst11 * fRec15[1]);
			fRec14[0] = fConst16 * (fRec15[2] + (fRec15[0] - 2.0f * fRec15[1])) - fSlow159 * (fSlow157 * fRec14[2] + fSlow155 * fRec14[1]);
			float fTemp11 = fSlow160 * (fRec14[2] + fRec14[0] + 2.0f * fRec14[1]) * std::max<float>(0.0f, std::min<float>(fTemp10, 2.0f - fTemp10));
			fRec12[0] = fTemp11 + fConst7 * fRec12[1] - fConst6 * fRec12[2];
			fRec17[0] = fTemp11 + fConst19 * fRec17[1] - fConst18 * fRec17[2];
			fRec18[0] = fTemp11 + fConst22 * fRec18[1] - fConst21 * fRec18[2];
			fRec19[0] = fTemp11 + fConst25 * fRec19[1] - fConst24 * fRec19[2];
			fRec20[0] = fTemp11 + fConst28 * fRec20[1] - fConst27 * fRec20[2];
			fRec21[0] = fTemp11 + fConst31 * fRec21[1] - fConst30 * fRec21[2];
			fRec22[0] = fTemp11 + fConst34 * fRec22[1] - fConst33 * fRec22[2];
			fRec23[0] = fTemp11 + fConst37 * fRec23[1] - fConst36 * fRec23[2];
			fRec24[0] = fTemp11 + fConst40 * fRec24[1] - fConst39 * fRec24[2];
			fRec25[0] = fTemp11 + fConst43 * fRec25[1] - fConst42 * fRec25[2];
			fRec26[0] = fTemp11 + fConst46 * fRec26[1] - fConst45 * fRec26[2];
			fRec27[0] = fTemp11 + fConst49 * fRec27[1] - fConst48 * fRec27[2];
			fRec28[0] = fTemp11 + fConst52 * fRec28[1] - fConst51 * fRec28[2];
			fRec29[0] = fTemp11 + fConst55 * fRec29[1] - fConst54 * fRec29[2];
			fRec30[0] = fTemp11 + fConst58 * fRec30[1] - fConst57 * fRec30[2];
			fRec31[0] = fTemp11 + fConst61 * fRec31[1] - fConst60 * fRec31[2];
			fRec32[0] = fTemp11 + fConst64 * fRec32[1] - fConst63 * fRec32[2];
			fRec33[0] = fTemp11 + fConst67 * fRec33[1] - fConst66 * fRec33[2];
			fRec34[0] = fTemp11 + fConst70 * fRec34[1] - fConst69 * fRec34[2];
			fRec35[0] = fTemp11 + fConst73 * fRec35[1] - fConst72 * fRec35[2];
			fRec36[0] = fTemp11 + fConst76 * fRec36[1] - fConst75 * fRec36[2];
			fRec37[0] = fTemp11 + fConst79 * fRec37[1] - fConst78 * fRec37[2];
			fRec38[0] = fTemp11 + fConst82 * fRec38[1] - fConst81 * fRec38[2];
			fRec39[0] = fTemp11 + fConst85 * fRec39[1] - fConst84 * fRec39[2];
			fRec40[0] = fTemp11 + fConst88 * fRec40[1] - fConst87 * fRec40[2];
			fRec41[0] = fTemp11 + fConst91 * fRec41[1] - fConst90 * fRec41[2];
			fRec42[0] = fTemp11 + fConst94 * fRec42[1] - fConst93 * fRec42[2];
			fRec43[0] = fTemp11 + fConst97 * fRec43[1] - fConst96 * fRec43[2];
			fRec44[0] = fTemp11 + fConst100 * fRec44[1] - fConst99 * fRec44[2];
			fRec45[0] = fTemp11 + fConst103 * fRec45[1] - fConst102 * fRec45[2];
			fRec46[0] = fTemp11 + fConst106 * fRec46[1] - fConst105 * fRec46[2];
			fRec47[0] = fTemp11 + fConst109 * fRec47[1] - fConst108 * fRec47[2];
			fRec48[0] = fTemp11 + fConst112 * fRec48[1] - fConst111 * fRec48[2];
			fRec49[0] = fTemp11 + fConst115 * fRec49[1] - fConst114 * fRec49[2];
			fRec50[0] = fTemp11 + fConst118 * fRec50[1] - fConst117 * fRec50[2];
			fRec51[0] = fTemp11 + fConst121 * fRec51[1] - fConst120 * fRec51[2];
			fRec52[0] = fTemp11 + fConst124 * fRec52[1] - fConst123 * fRec52[2];
			fRec53[0] = fTemp11 + fConst127 * fRec53[1] - fConst126 * fRec53[2];
			fRec54[0] = fTemp11 + fConst130 * fRec54[1] - fConst129 * fRec54[2];
			fRec55[0] = fTemp11 + fConst133 * fRec55[1] - fConst132 * fRec55[2];
			fRec56[0] = fTemp11 + fConst136 * fRec56[1] - fConst135 * fRec56[2];
			fRec57[0] = fTemp11 + fConst139 * fRec57[1] - fConst138 * fRec57[2];
			fRec58[0] = fTemp11 + fConst142 * fRec58[1] - fConst141 * fRec58[2];
			fRec59[0] = fTemp11 + fConst145 * fRec59[1] - fConst144 * fRec59[2];
			fRec60[0] = fTemp11 + fConst148 * fRec60[1] - fConst147 * fRec60[2];
			fRec61[0] = fTemp11 + fConst151 * fRec61[1] - fConst150 * fRec61[2];
			fRec62[0] = fTemp11 + fConst154 * fRec62[1] - fConst153 * fRec62[2];
			fRec63[0] = fTemp11 + fConst157 * fRec63[1] - fConst156 * fRec63[2];
			fRec64[0] = fTemp11 + fConst160 * fRec64[1] - fConst159 * fRec64[2];
			fRec65[0] = fTemp11 + fConst163 * fRec65[1] - fConst162 * fRec65[2];
			float fTemp12 = (fRec65[0] - fRec65[2]) * fSlow209 + (fRec64[0] - fRec64[2]) * fSlow208 + (fRec63[0] - fRec63[2]) * fSlow207 + (fRec62[0] - fRec62[2]) * fSlow206 + (fRec61[0] - fRec61[2]) * fSlow205 + (fRec60[0] - fRec60[2]) * fSlow204 + (fRec59[0] - fRec59[2]) * fSlow203 + (fRec58[0] - fRec58[2]) * fSlow202 + (fRec57[0] - fRec57[2]) * fSlow201 + (fRec56[0] - fRec56[2]) * fSlow200 + (fRec55[0] - fRec55[2]) * fSlow199 + (fRec54[0] - fRec54[2]) * fSlow198 + (fRec53[0] - fRec53[2]) * fSlow197 + (fRec52[0] - fRec52[2]) * fSlow196 + (fRec51[0] - fRec51[2]) * fSlow195 + (fRec50[0] - fRec50[2]) * fSlow194 + (fRec49[0] - fRec49[2]) * fSlow193 + (fRec48[0] - fRec48[2]) * fSlow192 + (fRec47[0] - fRec47[2]) * fSlow191 + (fRec46[0] - fRec46[2]) * fSlow190 + (fRec45[0] - fRec45[2]) * fSlow189 + (fRec44[0] - fRec44[2]) * fSlow188 + (fRec43[0] - fRec43[2]) * fSlow187 + (fRec42[0] - fRec42[2]) * fSlow186 + (fRec41[0] - fRec41[2]) * fSlow185 + (fRec40[0] - fRec40[2]) * fSlow184 + (fRec39[0] - fRec39[2]) * fSlow183 + (fRec38[0] - fRec38[2]) * fSlow182 + (fRec37[0] - fRec37[2]) * fSlow181 + (fRec36[0] - fRec36[2]) * fSlow180 + (fRec35[0] - fRec35[2]) * fSlow179 + (fRec34[0] - fRec34[2]) * fSlow178 + (fRec33[0] - fRec33[2]) * fSlow177 + (fRec32[0] - fRec32[2]) * fSlow176 + (fRec31[0] - fRec31[2]) * fSlow175 + (fRec30[0] - fRec30[2]) * fSlow174 + (fRec29[0] - fRec29[2]) * fSlow173 + (fRec28[0] - fRec28[2]) * fSlow172 + (fRec27[0] - fRec27[2]) * fSlow171 + (fRec26[0] - fRec26[2]) * fSlow170 + (fRec25[0] - fRec25[2]) * fSlow169 + (fRec24[0] - fRec24[2]) * fSlow168 + (fRec23[0] - fRec23[2]) * fSlow167 + (fRec22[0] - fRec22[2]) * fSlow166 + (fRec21[0] - fRec21[2]) * fSlow165 + (fRec20[0] - fRec20[2]) * fSlow164 + (fRec19[0] - fRec19[2]) * fSlow163 + (fRec18[0] - fRec18[2]) * fSlow162 + (fRec17[0] - fRec17[2]) * fSlow161 + (fRec12[0] - fRec12[2]) * fSlow151;
			fRec66[0] = fSlow210 + fConst165 * fRec66[1];
			fRec68[0] = fSlow211 + 0.4337f * fRec68[1];
			int iTemp13 = int(fRec68[0]);
			float fTemp14 = float(iTemp13);
			fRec69[0] = fSlow212 + fConst165 * fRec69[1];
			fRec67[IOTA0 & 131071] = 0.02f * fTemp12 - fRec69[0] * (fRec67[(IOTA0 - ((iTemp13 & 65535) + 1)) & 131071] * (fTemp14 + (1.0f - fRec68[0])) + (fRec68[0] - fTemp14) * fRec67[(IOTA0 - (((iTemp13 + 1) & 65535) + 1)) & 131071]);
			fRec11[0] = fRec67[IOTA0 & 131071] * (1.0f - fRec66[0]) + 0.02f * fRec66[0] * fTemp12 - (fRec11[2] * fSlow149 + fTemp9) / fSlow145;
			fRec10[0] = (fTemp9 + fRec11[0] * fSlow213 + fRec11[2] * fSlow147) / fSlow145 - (fRec10[2] * fSlow134 + fTemp8) / fSlow130;
			fRec9[0] = (fTemp8 + fRec10[0] * fSlow214 + fRec10[2] * fSlow132) / fSlow130 - (fRec9[2] * fSlow119 + fTemp7) / fSlow115;
			fRec8[0] = (fTemp7 + fRec9[0] * fSlow215 + fRec9[2] * fSlow117) / fSlow115 - (fRec8[2] * fSlow104 + fTemp6) / fSlow100;
			fRec7[0] = (fTemp6 + fRec8[0] * fSlow216 + fRec8[2] * fSlow102) / fSlow100 - (fRec7[2] * fSlow89 + fTemp5) / fSlow85;
			fRec6[0] = (fTemp5 + fRec7[0] * fSlow217 + fRec7[2] * fSlow87) / fSlow85 - (fRec6[2] * fSlow74 + fTemp4) / fSlow70;
			fRec5[0] = (fTemp4 + fRec6[0] * fSlow218 + fRec6[2] * fSlow72) / fSlow70 - (fRec5[2] * fSlow59 + fTemp3) / fSlow55;
			fRec4[0] = (fTemp3 + fRec5[0] * fSlow219 + fRec5[2] * fSlow57) / fSlow55 - (fRec4[2] * fSlow44 + fTemp2) / fSlow40;
			fRec3[0] = (fTemp2 + fRec4[0] * fSlow220 + fRec4[2] * fSlow42) / fSlow40 - (fRec3[2] * fSlow29 + fTemp1) / fSlow25;
			fRec2[0] = (fTemp1 + fRec3[0] * fSlow221 + fRec3[2] * fSlow27) / fSlow25 - (fRec2[2] * fSlow14 + fTemp0) / fSlow10;
			float fTemp15 = (fTemp0 + fRec2[0] * fSlow222 + fRec2[2] * fSlow12) / fSlow10;
			fVec1[0] = fTemp15;
			fRec1[0] = fConst167 * (fTemp15 - fVec1[1] + fConst2 * fRec1[1]);
			fRec0[0] = 0.559f * fRec1[0] + 0.441f * fRec0[1];
			output0[i0] = FAUSTFLOAT(fRec0[0]);
			fVec0[1] = fVec0[0];
			iRec13[1] = iRec13[0];
			iRec16[1] = iRec16[0];
			fRec15[2] = fRec15[1];
			fRec15[1] = fRec15[0];
			fRec14[2] = fRec14[1];
			fRec14[1] = fRec14[0];
			fRec12[2] = fRec12[1];
			fRec12[1] = fRec12[0];
			fRec17[2] = fRec17[1];
			fRec17[1] = fRec17[0];
			fRec18[2] = fRec18[1];
			fRec18[1] = fRec18[0];
			fRec19[2] = fRec19[1];
			fRec19[1] = fRec19[0];
			fRec20[2] = fRec20[1];
			fRec20[1] = fRec20[0];
			fRec21[2] = fRec21[1];
			fRec21[1] = fRec21[0];
			fRec22[2] = fRec22[1];
			fRec22[1] = fRec22[0];
			fRec23[2] = fRec23[1];
			fRec23[1] = fRec23[0];
			fRec24[2] = fRec24[1];
			fRec24[1] = fRec24[0];
			fRec25[2] = fRec25[1];
			fRec25[1] = fRec25[0];
			fRec26[2] = fRec26[1];
			fRec26[1] = fRec26[0];
			fRec27[2] = fRec27[1];
			fRec27[1] = fRec27[0];
			fRec28[2] = fRec28[1];
			fRec28[1] = fRec28[0];
			fRec29[2] = fRec29[1];
			fRec29[1] = fRec29[0];
			fRec30[2] = fRec30[1];
			fRec30[1] = fRec30[0];
			fRec31[2] = fRec31[1];
			fRec31[1] = fRec31[0];
			fRec32[2] = fRec32[1];
			fRec32[1] = fRec32[0];
			fRec33[2] = fRec33[1];
			fRec33[1] = fRec33[0];
			fRec34[2] = fRec34[1];
			fRec34[1] = fRec34[0];
			fRec35[2] = fRec35[1];
			fRec35[1] = fRec35[0];
			fRec36[2] = fRec36[1];
			fRec36[1] = fRec36[0];
			fRec37[2] = fRec37[1];
			fRec37[1] = fRec37[0];
			fRec38[2] = fRec38[1];
			fRec38[1] = fRec38[0];
			fRec39[2] = fRec39[1];
			fRec39[1] = fRec39[0];
			fRec40[2] = fRec40[1];
			fRec40[1] = fRec40[0];
			fRec41[2] = fRec41[1];
			fRec41[1] = fRec41[0];
			fRec42[2] = fRec42[1];
			fRec42[1] = fRec42[0];
			fRec43[2] = fRec43[1];
			fRec43[1] = fRec43[0];
			fRec44[2] = fRec44[1];
			fRec44[1] = fRec44[0];
			fRec45[2] = fRec45[1];
			fRec45[1] = fRec45[0];
			fRec46[2] = fRec46[1];
			fRec46[1] = fRec46[0];
			fRec47[2] = fRec47[1];
			fRec47[1] = fRec47[0];
			fRec48[2] = fRec48[1];
			fRec48[1] = fRec48[0];
			fRec49[2] = fRec49[1];
			fRec49[1] = fRec49[0];
			fRec50[2] = fRec50[1];
			fRec50[1] = fRec50[0];
			fRec51[2] = fRec51[1];
			fRec51[1] = fRec51[0];
			fRec52[2] = fRec52[1];
			fRec52[1] = fRec52[0];
			fRec53[2] = fRec53[1];
			fRec53[1] = fRec53[0];
			fRec54[2] = fRec54[1];
			fRec54[1] = fRec54[0];
			fRec55[2] = fRec55[1];
			fRec55[1] = fRec55[0];
			fRec56[2] = fRec56[1];
			fRec56[1] = fRec56[0];
			fRec57[2] = fRec57[1];
			fRec57[1] = fRec57[0];
			fRec58[2] = fRec58[1];
			fRec58[1] = fRec58[0];
			fRec59[2] = fRec59[1];
			fRec59[1] = fRec59[0];
			fRec60[2] = fRec60[1];
			fRec60[1] = fRec60[0];
			fRec61[2] = fRec61[1];
			fRec61[1] = fRec61[0];
			fRec62[2] = fRec62[1];
			fRec62[1] = fRec62[0];
			fRec63[2] = fRec63[1];
			fRec63[1] = fRec63[0];
			fRec64[2] = fRec64[1];
			fRec64[1] = fRec64[0];
			fRec65[2] = fRec65[1];
			fRec65[1] = fRec65[0];
			fRec66[1] = fRec66[0];
			IOTA0 = IOTA0 + 1;
			fRec68[1] = fRec68[0];
			fRec69[1] = fRec69[0];
			fRec11[2] = fRec11[1];
			fRec11[1] = fRec11[0];
			fRec10[2] = fRec10[1];
			fRec10[1] = fRec10[0];
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
			fVec1[1] = fVec1[0];
			fRec1[1] = fRec1[0];
			fRec0[1] = fRec0[0];
		}
	}

};

#endif
