#include <TChain.h>
#include <iostream>
TChain * chV = new TChain("trV");

const char * fname[] = {
	"test/",				// 0
	"../PbPb2015_cumu/HIMinimumBias2/crab_HIMB2_SC_Pixel_eff_cent_v1/170427_131539/0000/",		// 1 PbPb 5 TeV Pixel Cent
};

const char * ftxt[] = {
	"txt/test",					// 0
	"txt/PbPb5TeV_Pixel_cent/",			// 1
};

void addchain(int s1, string s)
{
        std::cout << fname[s1] << std::endl;
        chV->Add(Form("%s/*.root/%s/trV", fname[s1], s.c_str()));
}
