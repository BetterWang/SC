#include <TChain.h>
#include <iostream>
TChain * chV = new TChain("trV");

const char * fname[] = {
	"test/",				// 0
	"../SC/PAHighPt/crab_pPb5_SC_eff_noff_v1/161109_221029/0000/",					// 1 pPb 5 TeV 2013 HM
	"../SC/HIMinimumBias5/crab_HIMB5_SC_ppReco_eff_noff_v2/161123_105949/0000/",			// 2 PbPb 5 TeV pp reco
	"../SC/PAHighMultiplicity0/crab_PAHM0_SC_eff_v3/161201_194804/0000/",				// 3 pPb 8 TeV HM0
	"../SC/PAHighMultiplicity1/crab_PAHM1_SC_eff_v3/161201_194322/0000/",				// 4 pPb 8 TeV HM1
	"../SC/PAHighMultiplicity2/crab_PAHM2_SC_eff_v3/161201_194345/0000/",				// 5 pPb 8 TeV HM2
	"../SC/PAHighMultiplicity3/crab_PAHM3_SC_eff_v3/161201_194402/0000/",				// 6 pPb 8 TeV HM3
	"../SC/PAHighMultiplicity4/crab_PAHM4_SC_eff_v3/161201_194425/0000/",				// 7 pPb 8 TeV HM4
	"../SC/PAHighMultiplicity5/crab_PAHM5_SC_eff_v3/161201_194445/0000/",				// 8 pPb 8 TeV HM5
	"../SC/PAHighMultiplicity6/crab_PAHM6_SC_eff_v3/161201_194514/0000/",				// 9 pPb 8 TeV HM6
	"../SC/PAHighMultiplicity7/crab_PAHM7_SC_eff_v3/161201_194534/0000/",				// 10 pPb 8 TeV HM7
	"NA",												// 11 pPb 8 TeV HM[0-7]
	"../SC/PAMinimumBias1/crab_PAMB1_SC_eff_v2/161201_160025/0000/",				// 12 pPb 8 TeV MB1
	"../SC/PAMinimumBias2/crab_PAMB2_SC_eff_v2/161201_160037/0000/",				// 13 pPb 8 TeV MB2
	"../SC/PAMinimumBias3/crab_PAMB3_SC_eff_v2/161201_160051/0000/",				// 14 pPb 8 TeV MB3
	"../SC/PAMinimumBias4/crab_PAMB4_SC_eff_v2/161201_160103/0000/",				// 15 pPb 8 TeV MB4
	"../SC/PAMinimumBias5/crab_PAMB5_SC_eff_v2/161201_160113/0000/",				// 16 pPb 8 TeV MB5
	"../SC/PAMinimumBias6/crab_PAMB6_SC_eff_v2/161201_160124/0000/",				// 17 pPb 8 TeV MB6
	"../SC/PAMinimumBias7/crab_PAMB7_SC_eff_v2/161201_160134/0000/",				// 18 pPb 8 TeV MB7
	"../SC/PAMinimumBias8/crab_PAMB8_SC_eff_v2/161201_160144/0000/",				// 19 pPb 8 TeV MB8
	"NA",												// 20 pPb 8 TeV MB[1-8]
};

const char * ftxt[] = {
	"txt/test",					// 0
	"txt/pPb5_2013/",				// 1
	"txt/PbPb5_ppReco_2015/",			// 2
	"txt/pPb8_HM0_2016/",				// 3
	"txt/pPb8_HM1_2016/",				// 4
	"txt/pPb8_HM2_2016/",				// 5
	"txt/pPb8_HM3_2016/",				// 6
	"txt/pPb8_HM4_2016/",				// 7
	"txt/pPb8_HM5_2016/",				// 8
	"txt/pPb8_HM6_2016/",				// 9
	"txt/pPb8_HM7_2016/",				// 10
	"txt/pPb8_HM_2016/",				// 11
	"txt/pPb8_MB1_2016/",				// 12
	"txt/pPb8_MB2_2016/",				// 13
	"txt/pPb8_MB3_2016/",				// 14
	"txt/pPb8_MB4_2016/",				// 15
	"txt/pPb8_MB5_2016/",				// 16
	"txt/pPb8_MB6_2016/",				// 17
	"txt/pPb8_MB7_2016/",				// 18
	"txt/pPb8_MB8_2016/",				// 19
	"txt/pPb8_MB_2016/",				// 20
};

void addchain(int s1, string s)
{
        std::cout << fname[s1] << std::endl;
        chV->Add(Form("%s/*.root/%s/trV", fname[s1], s.c_str()));
}
