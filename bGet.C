#include "label.h"
#include "noff.h"
#include <TFile.h>
#include <TH1.h>

void bGet(int s1 = 1, string s = "QWSC2_3_2_3")
{
	TFile * f = new TFile(Form("%s/%s.root", ftxt[s1], s.c_str()));

	int NCent = NCentCommon;
	double * CentNoffCut = CentNoffCutCommon;

	TH1D * hSC = (TH1D*) f->Get("hSC");
	TH1D * hSCw = (TH1D*) f->Get("hSCw");
	TH1D * hNoff = (TH1D*) f->Get("hNoff");
	TH1D * hMult = (TH1D*) f->Get("hMult");

	TH1D * hSC_merged = (TH1D*) hSC->Rebin(NCent, "hSC_merged", CentNoffCut);
	TH1D * hSCw_merged = (TH1D*) hSCw->Rebin(NCent, "hSCw_merged", CentNoffCut);
	TH1D * hNoff_merged = (TH1D*) hNoff->Rebin(NCent, "hNoff_merged", CentNoffCut);
	TH1D * hMult_merged = (TH1D*) hMult->Rebin(NCent, "hMult_merged", CentNoffCut);

	TH1D * hSCNorm_merged = (TH1D*) hSC_merged->Clone("hSCNorm_merged");
	hSCNorm_merged->Divide(hSCw_merged);

	TFile* fsave = new TFile(Form("%s/out%s.root", ftxt[s1], s.c_str()), "recreate");
	hSCNorm_merged->Write();
}
