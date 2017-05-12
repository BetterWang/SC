#include <TChain.h>
#include <iostream>
TChain * chV = new TChain("trV");

const char * fname[] = {
	"test/",				// 0
	"../PbPb2015_cumu/HIMinimumBias2/crab_HIMB2_SC_Pixel_eff_cent_v1/170427_131539/0000/",			// 1 PbPb 5 TeV Pixel Cent
	"../PbPb2015_cumu/HIMinimumBias2/crab_HIMB2_SC_Pixel_eff_cent_sysPosEta_v1/170504_142352/0000/",	// 2 PbPb 5 TeV Pixel Cent PosEta
	"../PbPb2015_cumu/HIMinimumBias2/crab_HIMB2_SC_Pixel_eff_cent_sysNegEta_v3/170507_181919/0000/",	// 3 PbPb 5 TeV Pixel Cent NegEta
	"../PbPb2015_cumu/MC/HIJING_SC_mod2_acc/",								// 4 HIJING 5 TeV Pixel Cent
	"../PbPb2015_cumu/MC/HIJING_SC_sysPosEta_mod2_acc/",							// 5 HIJING 5 TeV Pixel Cent PosEta
	"../PbPb2015_cumu/MC/HIJING_SC_sysNegEta_mod2_acc/",							// 6 HIJING 5 TeV Pixel Cent NegEta
};

const char * ftxt[] = {
	"txt/test",					// 0
	"txt/PbPb5TeV_Pixel_cent/",			// 1
	"txt/PbPb5TeV_Pixel_cent_PosEta/",		// 2
	"txt/PbPb5TeV_Pixel_cent_NegEta/",		// 3
	"txt/HIJING_fEllP_8pct_v2/",			// 4
	"txt/HIJING_fEllP_8pct_v2_PosEta/",		// 5
	"txt/HIJING_fEllP_8pct_v2_NegEta/",		// 6
};

void addchain(int s1, string s)
{
        std::cout << fname[s1] << std::endl;
        chV->Add(Form("%s/*.root/%s/trV", fname[s1], s.c_str()));
}
