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
	
	float fVec0[2];
	int iVec1[2];
	FAUSTFLOAT fVslider0;
	FAUSTFLOAT fVslider1;
	FAUSTFLOAT fVslider2;
	FAUSTFLOAT fVslider3;
	FAUSTFLOAT fVslider4;
	FAUSTFLOAT fVslider5;
	float fVec2[2];
	FAUSTFLOAT fVslider6;
	float fRec0[2];
	FAUSTFLOAT fVslider7;
	FAUSTFLOAT fVslider8;
	FAUSTFLOAT fVslider9;
	FAUSTFLOAT fVslider10;
	FAUSTFLOAT fVslider11;
	FAUSTFLOAT fVslider12;
	FAUSTFLOAT fVslider13;
	float fRec1[2];
	FAUSTFLOAT fVslider14;
	FAUSTFLOAT fVslider15;
	FAUSTFLOAT fVslider16;
	FAUSTFLOAT fVslider17;
	FAUSTFLOAT fVslider18;
	FAUSTFLOAT fVslider19;
	FAUSTFLOAT fVslider20;
	float fRec2[2];
	FAUSTFLOAT fVslider21;
	FAUSTFLOAT fVslider22;
	FAUSTFLOAT fVslider23;
	FAUSTFLOAT fVslider24;
	FAUSTFLOAT fVslider25;
	FAUSTFLOAT fVslider26;
	FAUSTFLOAT fVslider27;
	float fRec3[2];
	FAUSTFLOAT fVslider28;
	FAUSTFLOAT fVslider29;
	FAUSTFLOAT fVslider30;
	FAUSTFLOAT fVslider31;
	FAUSTFLOAT fVslider32;
	FAUSTFLOAT fVslider33;
	FAUSTFLOAT fVslider34;
	float fRec4[2];
	FAUSTFLOAT fVslider35;
	FAUSTFLOAT fVslider36;
	FAUSTFLOAT fVslider37;
	FAUSTFLOAT fVslider38;
	FAUSTFLOAT fVslider39;
	FAUSTFLOAT fVslider40;
	FAUSTFLOAT fVslider41;
	FAUSTFLOAT fVslider42;
	FAUSTFLOAT fVslider43;
	FAUSTFLOAT fVslider44;
	FAUSTFLOAT fVslider45;
	FAUSTFLOAT fVslider46;
	FAUSTFLOAT fVslider47;
	FAUSTFLOAT fVslider48;
	FAUSTFLOAT fVslider49;
	FAUSTFLOAT fVslider50;
	FAUSTFLOAT fVslider51;
	FAUSTFLOAT fVslider52;
	FAUSTFLOAT fVslider53;
	FAUSTFLOAT fVslider54;
	FAUSTFLOAT fVslider55;
	int fSampleRate;
	
 public:
	mydsp() {}

	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/tabulateNd", "Copyright (C) 2023 Bart Brouns <bart@magnetophon.nl>");
		m->declare("basics.lib/version", "1.11.1");
		m->declare("compile_options", "-lang cpp -ct 1 -es 1 -mcd 16 -single -ftz 0");
		m->declare("filename", "untitled.dsp");
		m->declare("name", "untitled");
		m->declare("signals.lib/name", "Faust Signal Routing Library");
		m->declare("signals.lib/version", "1.3.0");
	}

	virtual int getNumInputs() {
		return 2;
	}
	virtual int getNumOutputs() {
		return 3;
	}
	
	static void classInit(int sample_rate) {
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
	}
	
	virtual void instanceResetUserInterface() {
		fVslider0 = FAUSTFLOAT(-1e+01f);
		fVslider1 = FAUSTFLOAT(-1e+01f);
		fVslider2 = FAUSTFLOAT(-1e+01f);
		fVslider3 = FAUSTFLOAT(-1e+01f);
		fVslider4 = FAUSTFLOAT(-1e+01f);
		fVslider5 = FAUSTFLOAT(-1e+01f);
		fVslider6 = FAUSTFLOAT(-1e+01f);
		fVslider7 = FAUSTFLOAT(-1e+01f);
		fVslider8 = FAUSTFLOAT(-1e+01f);
		fVslider9 = FAUSTFLOAT(-1e+01f);
		fVslider10 = FAUSTFLOAT(-1e+01f);
		fVslider11 = FAUSTFLOAT(-1e+01f);
		fVslider12 = FAUSTFLOAT(-1e+01f);
		fVslider13 = FAUSTFLOAT(-1e+01f);
		fVslider14 = FAUSTFLOAT(-1e+01f);
		fVslider15 = FAUSTFLOAT(-1e+01f);
		fVslider16 = FAUSTFLOAT(-1e+01f);
		fVslider17 = FAUSTFLOAT(-1e+01f);
		fVslider18 = FAUSTFLOAT(-1e+01f);
		fVslider19 = FAUSTFLOAT(-1e+01f);
		fVslider20 = FAUSTFLOAT(-1e+01f);
		fVslider21 = FAUSTFLOAT(-1e+01f);
		fVslider22 = FAUSTFLOAT(-1e+01f);
		fVslider23 = FAUSTFLOAT(-1e+01f);
		fVslider24 = FAUSTFLOAT(-1e+01f);
		fVslider25 = FAUSTFLOAT(-1e+01f);
		fVslider26 = FAUSTFLOAT(-1e+01f);
		fVslider27 = FAUSTFLOAT(-1e+01f);
		fVslider28 = FAUSTFLOAT(-1e+01f);
		fVslider29 = FAUSTFLOAT(-1e+01f);
		fVslider30 = FAUSTFLOAT(-1e+01f);
		fVslider31 = FAUSTFLOAT(-1e+01f);
		fVslider32 = FAUSTFLOAT(-1e+01f);
		fVslider33 = FAUSTFLOAT(-1e+01f);
		fVslider34 = FAUSTFLOAT(-1e+01f);
		fVslider35 = FAUSTFLOAT(-1e+01f);
		fVslider36 = FAUSTFLOAT(-1e+01f);
		fVslider37 = FAUSTFLOAT(-1e+01f);
		fVslider38 = FAUSTFLOAT(-1e+01f);
		fVslider39 = FAUSTFLOAT(-1e+01f);
		fVslider40 = FAUSTFLOAT(-1e+01f);
		fVslider41 = FAUSTFLOAT(-1e+01f);
		fVslider42 = FAUSTFLOAT(-1e+01f);
		fVslider43 = FAUSTFLOAT(-1e+01f);
		fVslider44 = FAUSTFLOAT(-1e+01f);
		fVslider45 = FAUSTFLOAT(-1e+01f);
		fVslider46 = FAUSTFLOAT(-1e+01f);
		fVslider47 = FAUSTFLOAT(-1e+01f);
		fVslider48 = FAUSTFLOAT(-1e+01f);
		fVslider49 = FAUSTFLOAT(-1e+01f);
		fVslider50 = FAUSTFLOAT(-1e+01f);
		fVslider51 = FAUSTFLOAT(-1e+01f);
		fVslider52 = FAUSTFLOAT(-1e+01f);
		fVslider53 = FAUSTFLOAT(-1e+01f);
		fVslider54 = FAUSTFLOAT(-1e+01f);
		fVslider55 = FAUSTFLOAT(-1e+01f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = l0 + 1) {
			fVec0[l0] = 0.0f;
		}
		for (int l1 = 0; l1 < 2; l1 = l1 + 1) {
			iVec1[l1] = 0;
		}
		for (int l2 = 0; l2 < 2; l2 = l2 + 1) {
			fVec2[l2] = 0.0f;
		}
		for (int l3 = 0; l3 < 2; l3 = l3 + 1) {
			fRec0[l3] = 0.0f;
		}
		for (int l4 = 0; l4 < 2; l4 = l4 + 1) {
			fRec1[l4] = 0.0f;
		}
		for (int l5 = 0; l5 < 2; l5 = l5 + 1) {
			fRec2[l5] = 0.0f;
		}
		for (int l6 = 0; l6 < 2; l6 = l6 + 1) {
			fRec3[l6] = 0.0f;
		}
		for (int l7 = 0; l7 < 2; l7 = l7 + 1) {
			fRec4[l7] = 0.0f;
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
		ui_interface->openTabBox("Matrix: 3 x 2");
		ui_interface->openHorizontalBox("Output 0");
		ui_interface->addVerticalSlider("Input 0", &fVslider37, FAUSTFLOAT(-1e+01f), FAUSTFLOAT(-96.0f), FAUSTFLOAT(4.0f), FAUSTFLOAT(0.1f));
		ui_interface->addVerticalSlider("Input 1", &fVslider36, FAUSTFLOAT(-1e+01f), FAUSTFLOAT(-96.0f), FAUSTFLOAT(4.0f), FAUSTFLOAT(0.1f));
		ui_interface->closeBox();
		ui_interface->openHorizontalBox("Output 1");
		ui_interface->addVerticalSlider("Input 0", &fVslider44, FAUSTFLOAT(-1e+01f), FAUSTFLOAT(-96.0f), FAUSTFLOAT(4.0f), FAUSTFLOAT(0.1f));
		ui_interface->addVerticalSlider("Input 1", &fVslider43, FAUSTFLOAT(-1e+01f), FAUSTFLOAT(-96.0f), FAUSTFLOAT(4.0f), FAUSTFLOAT(0.1f));
		ui_interface->closeBox();
		ui_interface->openHorizontalBox("Output 2");
		ui_interface->addVerticalSlider("Input 0", &fVslider51, FAUSTFLOAT(-1e+01f), FAUSTFLOAT(-96.0f), FAUSTFLOAT(4.0f), FAUSTFLOAT(0.1f));
		ui_interface->addVerticalSlider("Input 1", &fVslider50, FAUSTFLOAT(-1e+01f), FAUSTFLOAT(-96.0f), FAUSTFLOAT(4.0f), FAUSTFLOAT(0.1f));
		ui_interface->closeBox();
		ui_interface->closeBox();
		ui_interface->openTabBox("Matrix: 3 x 5");
		ui_interface->openHorizontalBox("Output 0");
		ui_interface->addVerticalSlider("Input 0", &fVslider35, FAUSTFLOAT(-1e+01f), FAUSTFLOAT(-96.0f), FAUSTFLOAT(4.0f), FAUSTFLOAT(0.1f));
		ui_interface->addVerticalSlider("Input 1", &fVslider38, FAUSTFLOAT(-1e+01f), FAUSTFLOAT(-96.0f), FAUSTFLOAT(4.0f), FAUSTFLOAT(0.1f));
		ui_interface->addVerticalSlider("Input 2", &fVslider39, FAUSTFLOAT(-1e+01f), FAUSTFLOAT(-96.0f), FAUSTFLOAT(4.0f), FAUSTFLOAT(0.1f));
		ui_interface->addVerticalSlider("Input 3", &fVslider40, FAUSTFLOAT(-1e+01f), FAUSTFLOAT(-96.0f), FAUSTFLOAT(4.0f), FAUSTFLOAT(0.1f));
		ui_interface->addVerticalSlider("Input 4", &fVslider41, FAUSTFLOAT(-1e+01f), FAUSTFLOAT(-96.0f), FAUSTFLOAT(4.0f), FAUSTFLOAT(0.1f));
		ui_interface->closeBox();
		ui_interface->openHorizontalBox("Output 1");
		ui_interface->addVerticalSlider("Input 0", &fVslider42, FAUSTFLOAT(-1e+01f), FAUSTFLOAT(-96.0f), FAUSTFLOAT(4.0f), FAUSTFLOAT(0.1f));
		ui_interface->addVerticalSlider("Input 1", &fVslider45, FAUSTFLOAT(-1e+01f), FAUSTFLOAT(-96.0f), FAUSTFLOAT(4.0f), FAUSTFLOAT(0.1f));
		ui_interface->addVerticalSlider("Input 2", &fVslider46, FAUSTFLOAT(-1e+01f), FAUSTFLOAT(-96.0f), FAUSTFLOAT(4.0f), FAUSTFLOAT(0.1f));
		ui_interface->addVerticalSlider("Input 3", &fVslider47, FAUSTFLOAT(-1e+01f), FAUSTFLOAT(-96.0f), FAUSTFLOAT(4.0f), FAUSTFLOAT(0.1f));
		ui_interface->addVerticalSlider("Input 4", &fVslider48, FAUSTFLOAT(-1e+01f), FAUSTFLOAT(-96.0f), FAUSTFLOAT(4.0f), FAUSTFLOAT(0.1f));
		ui_interface->closeBox();
		ui_interface->openHorizontalBox("Output 2");
		ui_interface->addVerticalSlider("Input 0", &fVslider49, FAUSTFLOAT(-1e+01f), FAUSTFLOAT(-96.0f), FAUSTFLOAT(4.0f), FAUSTFLOAT(0.1f));
		ui_interface->addVerticalSlider("Input 1", &fVslider52, FAUSTFLOAT(-1e+01f), FAUSTFLOAT(-96.0f), FAUSTFLOAT(4.0f), FAUSTFLOAT(0.1f));
		ui_interface->addVerticalSlider("Input 2", &fVslider53, FAUSTFLOAT(-1e+01f), FAUSTFLOAT(-96.0f), FAUSTFLOAT(4.0f), FAUSTFLOAT(0.1f));
		ui_interface->addVerticalSlider("Input 3", &fVslider54, FAUSTFLOAT(-1e+01f), FAUSTFLOAT(-96.0f), FAUSTFLOAT(4.0f), FAUSTFLOAT(0.1f));
		ui_interface->addVerticalSlider("Input 4", &fVslider55, FAUSTFLOAT(-1e+01f), FAUSTFLOAT(-96.0f), FAUSTFLOAT(4.0f), FAUSTFLOAT(0.1f));
		ui_interface->closeBox();
		ui_interface->closeBox();
		ui_interface->openTabBox("Matrix: 5 x 2");
		ui_interface->openHorizontalBox("Output 0");
		ui_interface->addVerticalSlider("Input 0", &fVslider0, FAUSTFLOAT(-1e+01f), FAUSTFLOAT(-96.0f), FAUSTFLOAT(4.0f), FAUSTFLOAT(0.1f));
		ui_interface->addVerticalSlider("Input 1", &fVslider6, FAUSTFLOAT(-1e+01f), FAUSTFLOAT(-96.0f), FAUSTFLOAT(4.0f), FAUSTFLOAT(0.1f));
		ui_interface->closeBox();
		ui_interface->openHorizontalBox("Output 1");
		ui_interface->addVerticalSlider("Input 0", &fVslider7, FAUSTFLOAT(-1e+01f), FAUSTFLOAT(-96.0f), FAUSTFLOAT(4.0f), FAUSTFLOAT(0.1f));
		ui_interface->addVerticalSlider("Input 1", &fVslider13, FAUSTFLOAT(-1e+01f), FAUSTFLOAT(-96.0f), FAUSTFLOAT(4.0f), FAUSTFLOAT(0.1f));
		ui_interface->closeBox();
		ui_interface->openHorizontalBox("Output 2");
		ui_interface->addVerticalSlider("Input 0", &fVslider14, FAUSTFLOAT(-1e+01f), FAUSTFLOAT(-96.0f), FAUSTFLOAT(4.0f), FAUSTFLOAT(0.1f));
		ui_interface->addVerticalSlider("Input 1", &fVslider20, FAUSTFLOAT(-1e+01f), FAUSTFLOAT(-96.0f), FAUSTFLOAT(4.0f), FAUSTFLOAT(0.1f));
		ui_interface->closeBox();
		ui_interface->openHorizontalBox("Output 3");
		ui_interface->addVerticalSlider("Input 0", &fVslider21, FAUSTFLOAT(-1e+01f), FAUSTFLOAT(-96.0f), FAUSTFLOAT(4.0f), FAUSTFLOAT(0.1f));
		ui_interface->addVerticalSlider("Input 1", &fVslider27, FAUSTFLOAT(-1e+01f), FAUSTFLOAT(-96.0f), FAUSTFLOAT(4.0f), FAUSTFLOAT(0.1f));
		ui_interface->closeBox();
		ui_interface->openHorizontalBox("Output 4");
		ui_interface->addVerticalSlider("Input 0", &fVslider28, FAUSTFLOAT(-1e+01f), FAUSTFLOAT(-96.0f), FAUSTFLOAT(4.0f), FAUSTFLOAT(0.1f));
		ui_interface->addVerticalSlider("Input 1", &fVslider34, FAUSTFLOAT(-1e+01f), FAUSTFLOAT(-96.0f), FAUSTFLOAT(4.0f), FAUSTFLOAT(0.1f));
		ui_interface->closeBox();
		ui_interface->closeBox();
		ui_interface->openTabBox("Matrix: 5 x 5");
		ui_interface->openHorizontalBox("Output 0");
		ui_interface->addVerticalSlider("Input 0", &fVslider5, FAUSTFLOAT(-1e+01f), FAUSTFLOAT(-96.0f), FAUSTFLOAT(4.0f), FAUSTFLOAT(0.1f));
		ui_interface->addVerticalSlider("Input 1", &fVslider4, FAUSTFLOAT(-1e+01f), FAUSTFLOAT(-96.0f), FAUSTFLOAT(4.0f), FAUSTFLOAT(0.1f));
		ui_interface->addVerticalSlider("Input 2", &fVslider3, FAUSTFLOAT(-1e+01f), FAUSTFLOAT(-96.0f), FAUSTFLOAT(4.0f), FAUSTFLOAT(0.1f));
		ui_interface->addVerticalSlider("Input 3", &fVslider2, FAUSTFLOAT(-1e+01f), FAUSTFLOAT(-96.0f), FAUSTFLOAT(4.0f), FAUSTFLOAT(0.1f));
		ui_interface->addVerticalSlider("Input 4", &fVslider1, FAUSTFLOAT(-1e+01f), FAUSTFLOAT(-96.0f), FAUSTFLOAT(4.0f), FAUSTFLOAT(0.1f));
		ui_interface->closeBox();
		ui_interface->openHorizontalBox("Output 1");
		ui_interface->addVerticalSlider("Input 0", &fVslider12, FAUSTFLOAT(-1e+01f), FAUSTFLOAT(-96.0f), FAUSTFLOAT(4.0f), FAUSTFLOAT(0.1f));
		ui_interface->addVerticalSlider("Input 1", &fVslider11, FAUSTFLOAT(-1e+01f), FAUSTFLOAT(-96.0f), FAUSTFLOAT(4.0f), FAUSTFLOAT(0.1f));
		ui_interface->addVerticalSlider("Input 2", &fVslider10, FAUSTFLOAT(-1e+01f), FAUSTFLOAT(-96.0f), FAUSTFLOAT(4.0f), FAUSTFLOAT(0.1f));
		ui_interface->addVerticalSlider("Input 3", &fVslider9, FAUSTFLOAT(-1e+01f), FAUSTFLOAT(-96.0f), FAUSTFLOAT(4.0f), FAUSTFLOAT(0.1f));
		ui_interface->addVerticalSlider("Input 4", &fVslider8, FAUSTFLOAT(-1e+01f), FAUSTFLOAT(-96.0f), FAUSTFLOAT(4.0f), FAUSTFLOAT(0.1f));
		ui_interface->closeBox();
		ui_interface->openHorizontalBox("Output 2");
		ui_interface->addVerticalSlider("Input 0", &fVslider19, FAUSTFLOAT(-1e+01f), FAUSTFLOAT(-96.0f), FAUSTFLOAT(4.0f), FAUSTFLOAT(0.1f));
		ui_interface->addVerticalSlider("Input 1", &fVslider18, FAUSTFLOAT(-1e+01f), FAUSTFLOAT(-96.0f), FAUSTFLOAT(4.0f), FAUSTFLOAT(0.1f));
		ui_interface->addVerticalSlider("Input 2", &fVslider17, FAUSTFLOAT(-1e+01f), FAUSTFLOAT(-96.0f), FAUSTFLOAT(4.0f), FAUSTFLOAT(0.1f));
		ui_interface->addVerticalSlider("Input 3", &fVslider16, FAUSTFLOAT(-1e+01f), FAUSTFLOAT(-96.0f), FAUSTFLOAT(4.0f), FAUSTFLOAT(0.1f));
		ui_interface->addVerticalSlider("Input 4", &fVslider15, FAUSTFLOAT(-1e+01f), FAUSTFLOAT(-96.0f), FAUSTFLOAT(4.0f), FAUSTFLOAT(0.1f));
		ui_interface->closeBox();
		ui_interface->openHorizontalBox("Output 3");
		ui_interface->addVerticalSlider("Input 0", &fVslider26, FAUSTFLOAT(-1e+01f), FAUSTFLOAT(-96.0f), FAUSTFLOAT(4.0f), FAUSTFLOAT(0.1f));
		ui_interface->addVerticalSlider("Input 1", &fVslider25, FAUSTFLOAT(-1e+01f), FAUSTFLOAT(-96.0f), FAUSTFLOAT(4.0f), FAUSTFLOAT(0.1f));
		ui_interface->addVerticalSlider("Input 2", &fVslider24, FAUSTFLOAT(-1e+01f), FAUSTFLOAT(-96.0f), FAUSTFLOAT(4.0f), FAUSTFLOAT(0.1f));
		ui_interface->addVerticalSlider("Input 3", &fVslider23, FAUSTFLOAT(-1e+01f), FAUSTFLOAT(-96.0f), FAUSTFLOAT(4.0f), FAUSTFLOAT(0.1f));
		ui_interface->addVerticalSlider("Input 4", &fVslider22, FAUSTFLOAT(-1e+01f), FAUSTFLOAT(-96.0f), FAUSTFLOAT(4.0f), FAUSTFLOAT(0.1f));
		ui_interface->closeBox();
		ui_interface->openHorizontalBox("Output 4");
		ui_interface->addVerticalSlider("Input 0", &fVslider33, FAUSTFLOAT(-1e+01f), FAUSTFLOAT(-96.0f), FAUSTFLOAT(4.0f), FAUSTFLOAT(0.1f));
		ui_interface->addVerticalSlider("Input 1", &fVslider32, FAUSTFLOAT(-1e+01f), FAUSTFLOAT(-96.0f), FAUSTFLOAT(4.0f), FAUSTFLOAT(0.1f));
		ui_interface->addVerticalSlider("Input 2", &fVslider31, FAUSTFLOAT(-1e+01f), FAUSTFLOAT(-96.0f), FAUSTFLOAT(4.0f), FAUSTFLOAT(0.1f));
		ui_interface->addVerticalSlider("Input 3", &fVslider30, FAUSTFLOAT(-1e+01f), FAUSTFLOAT(-96.0f), FAUSTFLOAT(4.0f), FAUSTFLOAT(0.1f));
		ui_interface->addVerticalSlider("Input 4", &fVslider29, FAUSTFLOAT(-1e+01f), FAUSTFLOAT(-96.0f), FAUSTFLOAT(4.0f), FAUSTFLOAT(0.1f));
		ui_interface->closeBox();
		ui_interface->closeBox();
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* input1 = inputs[1];
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		FAUSTFLOAT* output2 = outputs[2];
		float fSlow0 = std::pow(1e+01f, 0.05f * float(fVslider0));
		float fSlow1 = std::pow(1e+01f, 0.05f * float(fVslider1));
		float fSlow2 = std::pow(1e+01f, 0.05f * float(fVslider2));
		float fSlow3 = std::pow(1e+01f, 0.05f * float(fVslider3));
		float fSlow4 = std::pow(1e+01f, 0.05f * float(fVslider4));
		float fSlow5 = std::pow(1e+01f, 0.05f * float(fVslider5));
		float fSlow6 = std::pow(1e+01f, 0.05f * float(fVslider6));
		float fSlow7 = std::pow(1e+01f, 0.05f * float(fVslider7));
		float fSlow8 = std::pow(1e+01f, 0.05f * float(fVslider8));
		float fSlow9 = std::pow(1e+01f, 0.05f * float(fVslider9));
		float fSlow10 = std::pow(1e+01f, 0.05f * float(fVslider10));
		float fSlow11 = std::pow(1e+01f, 0.05f * float(fVslider11));
		float fSlow12 = std::pow(1e+01f, 0.05f * float(fVslider12));
		float fSlow13 = std::pow(1e+01f, 0.05f * float(fVslider13));
		float fSlow14 = std::pow(1e+01f, 0.05f * float(fVslider14));
		float fSlow15 = std::pow(1e+01f, 0.05f * float(fVslider15));
		float fSlow16 = std::pow(1e+01f, 0.05f * float(fVslider16));
		float fSlow17 = std::pow(1e+01f, 0.05f * float(fVslider17));
		float fSlow18 = std::pow(1e+01f, 0.05f * float(fVslider18));
		float fSlow19 = std::pow(1e+01f, 0.05f * float(fVslider19));
		float fSlow20 = std::pow(1e+01f, 0.05f * float(fVslider20));
		float fSlow21 = std::pow(1e+01f, 0.05f * float(fVslider21));
		float fSlow22 = std::pow(1e+01f, 0.05f * float(fVslider22));
		float fSlow23 = std::pow(1e+01f, 0.05f * float(fVslider23));
		float fSlow24 = std::pow(1e+01f, 0.05f * float(fVslider24));
		float fSlow25 = std::pow(1e+01f, 0.05f * float(fVslider25));
		float fSlow26 = std::pow(1e+01f, 0.05f * float(fVslider26));
		float fSlow27 = std::pow(1e+01f, 0.05f * float(fVslider27));
		float fSlow28 = std::pow(1e+01f, 0.05f * float(fVslider28));
		float fSlow29 = std::pow(1e+01f, 0.05f * float(fVslider29));
		float fSlow30 = std::pow(1e+01f, 0.05f * float(fVslider30));
		float fSlow31 = std::pow(1e+01f, 0.05f * float(fVslider31));
		float fSlow32 = std::pow(1e+01f, 0.05f * float(fVslider32));
		float fSlow33 = std::pow(1e+01f, 0.05f * float(fVslider33));
		float fSlow34 = std::pow(1e+01f, 0.05f * float(fVslider34));
		float fSlow35 = std::pow(1e+01f, 0.05f * float(fVslider35));
		float fSlow36 = std::pow(1e+01f, 0.05f * float(fVslider36));
		float fSlow37 = std::pow(1e+01f, 0.05f * float(fVslider37));
		float fSlow38 = std::pow(1e+01f, 0.05f * float(fVslider38));
		float fSlow39 = std::pow(1e+01f, 0.05f * float(fVslider39));
		float fSlow40 = std::pow(1e+01f, 0.05f * float(fVslider40));
		float fSlow41 = std::pow(1e+01f, 0.05f * float(fVslider41));
		float fSlow42 = std::pow(1e+01f, 0.05f * float(fVslider42));
		float fSlow43 = std::pow(1e+01f, 0.05f * float(fVslider43));
		float fSlow44 = std::pow(1e+01f, 0.05f * float(fVslider44));
		float fSlow45 = std::pow(1e+01f, 0.05f * float(fVslider45));
		float fSlow46 = std::pow(1e+01f, 0.05f * float(fVslider46));
		float fSlow47 = std::pow(1e+01f, 0.05f * float(fVslider47));
		float fSlow48 = std::pow(1e+01f, 0.05f * float(fVslider48));
		float fSlow49 = std::pow(1e+01f, 0.05f * float(fVslider49));
		float fSlow50 = std::pow(1e+01f, 0.05f * float(fVslider50));
		float fSlow51 = std::pow(1e+01f, 0.05f * float(fVslider51));
		float fSlow52 = std::pow(1e+01f, 0.05f * float(fVslider52));
		float fSlow53 = std::pow(1e+01f, 0.05f * float(fVslider53));
		float fSlow54 = std::pow(1e+01f, 0.05f * float(fVslider54));
		float fSlow55 = std::pow(1e+01f, 0.05f * float(fVslider55));
		for (int i0 = 0; i0 < count; i0 = i0 + 1) {
			float fTemp0 = float(input0[i0]);
			fVec0[0] = fTemp0;
			iVec1[0] = 1;
			float fTemp1 = float(input1[i0]);
			fVec2[0] = fTemp1;
			fRec0[0] = fSlow6 * fVec2[1] + fSlow5 * fRec0[1] + fSlow4 * fRec1[1] + fSlow3 * fRec2[1] + fSlow2 * fRec3[1] + fSlow1 * fRec4[1] + fSlow0 * fVec0[1];
			fRec1[0] = fSlow13 * fVec2[1] + fSlow12 * fRec0[1] + fSlow11 * fRec1[1] + fSlow10 * fRec2[1] + fSlow9 * fRec3[1] + fSlow8 * fRec4[1] + fSlow7 * fVec0[1];
			fRec2[0] = fSlow20 * fVec2[1] + fSlow19 * fRec0[1] + fSlow18 * fRec1[1] + fSlow17 * fRec2[1] + fSlow16 * fRec3[1] + fSlow15 * fRec4[1] + fSlow14 * fVec0[1];
			fRec3[0] = fSlow27 * fVec2[1] + fSlow26 * fRec0[1] + fSlow25 * fRec1[1] + fSlow24 * fRec2[1] + fSlow23 * fRec3[1] + fSlow22 * fRec4[1] + fSlow21 * fVec0[1];
			fRec4[0] = fSlow34 * fVec2[1] + fSlow33 * fRec0[1] + fSlow32 * fRec1[1] + fSlow31 * fRec2[1] + fSlow30 * fRec3[1] + fSlow29 * fRec4[1] + fSlow28 * fVec0[1];
			int iTemp2 = 1 - iVec1[1];
			float fTemp3 = fRec1[0] + float(iTemp2);
			float fTemp4 = fRec2[0] + float(2 * iTemp2);
			float fTemp5 = fRec3[0] + float(3 * iTemp2);
			float fTemp6 = fRec4[0] + float(4 * iTemp2);
			output0[i0] = FAUSTFLOAT(fSlow41 * fTemp6 + fSlow40 * fTemp5 + fSlow39 * fTemp4 + fSlow38 * fTemp3 + fSlow37 * fTemp0 + fSlow36 * fTemp1 + fSlow35 * fRec0[0]);
			output1[i0] = FAUSTFLOAT(fSlow48 * fTemp6 + fSlow47 * fTemp5 + fSlow46 * fTemp4 + fSlow45 * fTemp3 + fSlow44 * fTemp0 + fSlow43 * fTemp1 + fSlow42 * fRec0[0]);
			output2[i0] = FAUSTFLOAT(fSlow55 * fTemp6 + fSlow54 * fTemp5 + fSlow53 * fTemp4 + fSlow52 * fTemp3 + fSlow51 * fTemp0 + fSlow50 * fTemp1 + fSlow49 * fRec0[0]);
			fVec0[1] = fVec0[0];
			iVec1[1] = iVec1[0];
			fVec2[1] = fVec2[0];
			fRec0[1] = fRec0[0];
			fRec1[1] = fRec1[0];
			fRec2[1] = fRec2[0];
			fRec3[1] = fRec3[0];
			fRec4[1] = fRec4[0];
		}
	}

};

#endif
