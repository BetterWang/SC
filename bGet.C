#include "label.h"
#include "noff.h"
#include <TFile.h>
#include <TH1.h>
#include "const.h"

void bGet(int s1 = 1, int s2 = 10, int s3 = 10)
{
//	TFile * f = new TFile(Form("%s/%s_%i_%i_.root", ftxt[s1], s.c_str(), s2, s3));
	TFile* fsave = new TFile(Form("%s/outCumu_%i_%i.root", ftxt[s1], s2, s3), "recreate");

	std::vector<std::string> vQ = vectQ;

	int NCent = NCentAA5TeV4;
	auto CentNoffCut = CentCutAA5TeV;

	for ( auto s : vQ ) {
		TFile * f = new TFile( Form("%s/%s_%i_%i.root", ftxt[s1], s.c_str(), s2, s3) );

		TH1D * hSC = (TH1D*) f->Get("hSC");
		TH1D * hSCi = (TH1D*) f->Get("hSCi");
		TH1D * hSCw = (TH1D*) f->Get("hSCw");
		TH1D * hNoff = (TH1D*) f->Get("hNoff");
		TH1D * hMult = (TH1D*) f->Get("hMult");

		TH1D * hSC_merged   = (TH1D*) hSC  ->Rebin(NCent, Form("hSC_%s",   s.c_str()), CentNoffCut);
		TH1D * hSCi_merged  = (TH1D*) hSCi ->Rebin(NCent, Form("hSCi_%s",  s.c_str()), CentNoffCut);
		TH1D * hSCw_merged  = (TH1D*) hSCw ->Rebin(NCent, Form("hSCw_%s",  s.c_str()), CentNoffCut);
		TH1D * hNoff_merged = (TH1D*) hNoff->Rebin(NCent, Form("hNoff_%s", s.c_str()), CentNoffCut);
		TH1D * hMult_merged = (TH1D*) hMult->Rebin(NCent, Form("hMult_%s", s.c_str()), CentNoffCut);

		TH1D * hSCNorm_merged = (TH1D*) hSC_merged->Clone(Form("hSCNorm_%s", s.c_str()));
		TH1D * hSCiNorm_merged = (TH1D*) hSCi_merged->Clone(Form("hSCiNorm_%s", s.c_str()));
		hSCNorm_merged->Divide(hSCw_merged);
		hSCiNorm_merged->Divide(hSCw_merged);

		fsave->cd();
		hSC_merged->Write();
		hSCi_merged->Write();
		hSCw_merged->Write();
		hSCNorm_merged->Write();
		hSCiNorm_merged->Write();

		f->Close();
	}

	fsave->Close();
}
