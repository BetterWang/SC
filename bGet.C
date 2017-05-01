#include "label.h"
#include "noff.h"
#include <TFile.h>
#include <TH1.h>

void bGet(int s1 = 0, int s2 = 10, int s3 = 10, string s = "QWSC2")
{
	TFile * f = new TFile(Form("%s/%s_%i_%i_.root", ftxt[s1], s.c_str(), s2, s3));

	int NCent = NCent8TeV4;
	double * CentNoffCut = CentNoffCutPA8TeV4;

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

	TFile* fsave = new TFile(Form("%s/out%s_%i_%i.root", ftxt[s1], s.c_str(), s2, s3), "recreate");
	hSCNorm_merged->Write();
	hSCw_merged->Write();
}
