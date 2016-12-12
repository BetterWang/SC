#include <TChain.h>
#include <iostream>
TChain * chV = new TChain("trV");

const char * fname[] = {
	"test/",				// 0
	"../SC/PAHighPt/crab_pPb5_SC_eff_noff_v1/161109_221029/0000/",					// 1 pPb 5 TeV 2013 HM
	"NA",												// 2 PbPb 5 TeV pp reco
	"../SCuser/PAHighMultiplicity0/crab_PAHM0_SC_eff_v5/161206_112807/0000/",			// 3 pPb 8 TeV HM0
	"../SCuser/PAHighMultiplicity1/crab_PAHM1_SC_eff_rerun_v5/161206_152905/0000/",			// 4 pPb 8 TeV HM1
	"../SC/PAHighMultiplicity2/crab_PAHM2_SC_eff_v3/161201_194345/0000/",				// 5 pPb 8 TeV HM2
	"../SC/PAHighMultiplicity3/crab_PAHM3_SC_eff_v3/161201_194402/0000/",				// 6 pPb 8 TeV HM3
	"../SC/PAHighMultiplicity4/crab_PAHM4_SC_eff_v3/161201_194425/0000/",				// 7 pPb 8 TeV HM4
	"../SC/PAHighMultiplicity5/crab_PAHM5_SC_eff_v3/161201_194445/0000/",				// 8 pPb 8 TeV HM5
	"../SC/PAHighMultiplicity6/crab_PAHM6_SC_eff_v3/161201_194514/0000/",				// 9 pPb 8 TeV HM6
	"../SCuser/PAHighMultiplicity7/crab_PAHM7_SC_eff_rerun_v5/161206_151200/0000/",			// 10 pPb 8 TeV HM7
	"NA",												// 11 pPb 8 TeV HM[0-7]
	"../SCuser/PAMinimumBias1/crab_PAMB1_SC_eff_v5/161206_110902/0000/",				// 12 pPb 8 TeV MB1
	"../SCuser/PAMinimumBias2/crab_PAMB2_SC_eff_rerun_v5/161206_150512/0000/",			// 13 pPb 8 TeV MB2
	"../SCuser/PAMinimumBias3/crab_PAMB3_SC_eff_v6/161207_085652/0000/",				// 14 pPb 8 TeV MB3
	"../SCuser/PAMinimumBias4/crab_PAMB4_SC_eff_v6/161207_083512/0000/",				// 15 pPb 8 TeV MB4
	"../SC/PAMinimumBias5/crab_PAMB5_SC_eff_v2/161201_160113/0000/",				// 16 pPb 8 TeV MB5
	"../SC/PAMinimumBias6/crab_PAMB6_SC_eff_v2/161201_160124/0000/",				// 17 pPb 8 TeV MB6
	"../SC/PAMinimumBias7/crab_PAMB7_SC_eff_v2/161201_160134/0000/",				// 18 pPb 8 TeV MB7
	"../SC/PAMinimumBias8/crab_PAMB8_SC_eff_v2/161201_160144/0000/",				// 19 pPb 8 TeV MB8
	"NA",												// 20 pPb 8 TeV MB[1-8]
	"../SC/HIMinimumBias5/crab_HIMB5_SC_ppReco_eff_noff_v3/161201_171433/0000/",			// 21 PbPb 5 TeV HIMB5 pp reco
	"../SC/HIMinimumBias6/crab_HIMB6_SC_ppReco_eff_noff_v3/161201_171451/0000/",			// 22 PbPb 5 TeV HIMB6 pp reco
	"../SCuser/PAHighMultiplicity0/crab_PAHM0_SC_eff_sysTight_v5/161206_112825/0000/",		// 23 pPb 8 TeV sysTight HM0
	"../SCuser/PAHighMultiplicity1/crab_PAHM1_SC_eff_sysTight_v5/161206_113104/0000/",		// 24 pPb 8 TeV sysTight HM1
	"../SCuser/PAHighMultiplicity7/crab_PAHM7_SC_eff_sysTight_rerun_v5/161206_155237/0000/",	// 25 pPb 8 TeV sysTight HM7
	"NA",												// 26 pPb 8 TeV sysTight HM[0-7]
	"../SCuser/PAMinimumBias1/crab_PAMB1_SC_eff_sysTight_v5/161206_110916/0000/",			// 27 pPb 8 TeV sysTight MB1
	"../SCuser/PAMinimumBias2/crab_PAMB2_SC_eff_sysTight_v5/161206_111024/0000/",			// 28 pPb 8 TeV sysTight MB2
	"NA",												// 29 pPb 8 TeV sysTight MB[1-3]
	"../SCuser/PAHighMultiplicity0/crab_PAHM0_SC_eff_sysLoose_v5/161206_112845/0000/",		// 30 pPb 8 TeV sysLoose HM0
	"../SCuser/PAHighMultiplicity1/crab_PAHM1_SC_eff_sysLoose_v5/161206_113220/0000/",		// 31 pPb 8 TeV sysLoose HM1
	"../SCuser/PAHighMultiplicity7/crab_PAHM7_SC_eff_sysLoose_v5/161206_113456/0000/",		// 32 pPb 8 TeV sysLoose HM7
	"NA",												// 33 pPb 8 TeV sysLoose HM[0-7]
	"../SCuser/PAMinimumBias1/crab_PAMB1_SC_eff_sysLoose_v5/161206_110929/0000/",			// 34 pPb 8 TeV sysLoose MB1
	"../SCuser/PAMinimumBias2/crab_PAMB2_SC_eff_sysLoose_v5/161206_111035/0000/",			// 35 pPb 8 TeV sysLoose MB2
	"NA",												// 36 pPb 8 TeV sysLoose MB[1-3]
	"../SCuser/PAHighMultiplicity0/crab_PAHM0_SC_eff_sysVzNarrow_resub_v5/161206_165244/0000/",	// 37 pPb 8 TeV sysVzNarrow HM0
	"../SCuser/PAHighMultiplicity1/crab_PAHM1_SC_eff_sysVzNarrow_resub_v5/161206_165330/0000/",	// 38 pPb 8 TeV sysVzNarrow HM1
	"../SCuser/PAHighMultiplicity7/crab_PAHM7_SC_eff_sysVzNarrow_resub_v5/161206_165414/0000/",	// 39 pPb 8 TeV sysVzNarrow HM7
	"NA",												// 40 pPb 8 TeV sysVzNarrow HM[0-7]
	"../SCuser/PAMinimumBias1/crab_PAMB1_SC_eff_sysVzNarrow_v5/161206_110944/0000/",		// 41 pPb 8 TeV sysVzNarrow MB1
	"../SCuser/PAMinimumBias2/crab_PAMB2_SC_eff_sysVzNarrow_v5/161206_111050/0000/",		// 42 pPb 8 TeV sysVzNarrow MB2
	"NA",												// 43 pPb 8 TeV sysVzNarrow MB[1-3]
	"../SCuser/PAHighMultiplicity0/crab_PAHM0_SC_eff_sysVzWide_resub_v5/161206_165307/0000/",	// 44 pPb 8 TeV sysVzWide HM0
	"../SCuser/PAHighMultiplicity1/crab_PAHM1_SC_eff_sysVzWide_resub_v5/161206_165349/0000/",	// 45 pPb 8 TeV sysVzWide HM1
	"../SCuser/PAHighMultiplicity7/crab_PAHM7_SC_eff_sysVzWide_resub_v5/161206_165433/0000/",	// 46 pPb 8 TeV sysVzWide HM7
	"NA",												// 47 pPb 8 TeV sysVzWide HM[0-7]
	"../SCuser/PAMinimumBias1/crab_PAMB1_SC_eff_sysVzWide_v5/161206_110958/0000/",			// 48 pPb 8 TeV sysVzWide MB1
	"../SCuser/PAMinimumBias2/crab_PAMB2_SC_eff_sysVzWide_v5/161206_111101/0000/",			// 49 pPb 8 TeV sysVzWide MB2
	"NA",												// 50 pPb 8 TeV sysVzWide MB[1-3]
	"../SCuser/PAMinimumBias3/crab_PAMB3_SC_eff_sysTight_v6/161207_083417/0000/",			// 51 pPb 8 TeV MB3 sysTight
	"../SCuser/PAMinimumBias3/crab_PAMB3_SC_eff_sysLoose_v6/161207_085710/0000/",			// 52 pPb 8 TeV MB3 sysLoose
	"../SCuser/PAMinimumBias3/crab_PAMB3_SC_eff_sysVzNarrow_v6/161207_083456/0000/",		// 53 pPb 8 TeV MB3 sysVzNarrow
	"../SCuser/PAMinimumBias3/crab_PAMB3_SC_eff_sysVzWide_v6/161207_090042/0000/",			// 54 pPb 8 TeV MB3 sysVzWide
	"../SCuser/PAMinimumBias4/crab_PAMB4_SC_eff_sysTight_v6/161207_083556/0000/",			// 55 pPb 8 TeV MB4 sysTight
	"../SCuser/PAMinimumBias4/crab_PAMB4_SC_eff_sysLoose_v6/161207_085900/0000/",			// 56 pPb 8 TeV MB4 sysLoose
	"../SCuser/PAMinimumBias4/crab_PAMB4_SC_eff_sysVzNarrow_v6/161207_083717/0000/",		// 57 pPb 8 TeV MB4 sysVzNarrow
	"../SCuser/PAMinimumBias4/crab_PAMB4_SC_eff_sysVzWide_v6/161207_083729/0000/",			// 58 pPb 8 TeV MB4 sysVzWide

	"../SCuser/PAHighMultiplicity0/crab_PAHM0_SC_eff_v7/161209_141445/0000/",			// 59 pPb 8 TeV HM0
	"../SCuser/PAHighMultiplicity1/crab_PAHM1_SC_eff_v7/161209_141624/0000/",			// 60 pPb 8 TeV HM1
	"../SCuser/PAHighMultiplicity7/crab_PAHM7_SC_eff_v7/161209_141759/0000/",			// 61 pPb 8 TeV HM7
	"../SCuser/PAMinimumBias1/crab_PAMB1_SC_eff_v7/161209_204337/0000/",				// 62 pPb 8 TeV MB1
	"../SCuser/PAHighMultiplicity0/crab_PAHM0_SC_eff_sysGplus_v7/161209_143931/0000/",		// 63 pPb 8 TeV HM0 sysGplus
	"../SCuser/PAHighMultiplicity1/crab_PAHM1_SC_eff_sysGplus_v7/161209_143943/0000/",		// 64 pPb 8 TeV HM1 sysGplus
	"../SCuser/PAHighMultiplicity7/crab_PAHM7_SC_eff_sysGplus_v7/161209_143956/0000/",		// 65 pPb 8 TeV HM7 sysGplus
	"../SCuser/PAMinimumBias1/crab_PAMB1_SC_eff_sysGplus_v7/161209_145239/0000/",			// 66 pPb 8 TeV MB1 sysGplus
	"testMB/",											// 67 test pPb 8 MB
	"testHM0/",											// 68 test pPb 8 HM0
	"testHM1/",											// 69 test pPb 8 HM1
	"testHM7/",											// 70 test pPb 8 HM7
	"testHM/",											// 71 test pPb 8 HM
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
	"txt/PbPb5_HIMB5_ppReco_2015/",			// 21
	"txt/PbPb5_HIMB6_ppReco_2015/",			// 22
	"txt/pPb8_sysTight_HM0/",			// 23
	"txt/pPb8_sysTight_HM1/",			// 24
	"txt/pPb8_sysTight_HM7/",			// 25
	"txt/pPb8_sysTight_HM/",			// 26
	"txt/pPb8_sysTight_MB1/",			// 27
	"txt/pPb8_sysTight_MB2/",			// 28
	"txt/pPb8_sysTight_MB/",			// 29
	"txt/pPb8_sysLoose_HM0/",			// 30
	"txt/pPb8_sysLoose_HM1/",			// 31
	"txt/pPb8_sysLoose_HM7/",			// 32
	"txt/pPb8_sysLoose_HM/",			// 33
	"txt/pPb8_sysLoose_MB1/",			// 34
	"txt/pPb8_sysLoose_MB2/",			// 35
	"txt/pPb8_sysLoose_MB/",			// 36
	"txt/pPb8_sysVzNarrow_HM0/",			// 37
	"txt/pPb8_sysVzNarrow_HM1/",			// 38
	"txt/pPb8_sysVzNarrow_HM7/",			// 39
	"txt/pPb8_sysVzNarrow_HM/",			// 40
	"txt/pPb8_sysVzNarrow_MB1/",			// 41
	"txt/pPb8_sysVzNarrow_MB2/",			// 42
	"txt/pPb8_sysVzNarrow_MB/",			// 43
	"txt/pPb8_sysVzWide_HM0/",			// 44
	"txt/pPb8_sysVzWide_HM1/",			// 45
	"txt/pPb8_sysVzWide_HM7/",			// 46
	"txt/pPb8_sysVzWide_HM/",			// 47
	"txt/pPb8_sysVzWide_MB1/",			// 48
	"txt/pPb8_sysVzWide_MB2/",			// 49
	"txt/pPb8_sysVzWide_MB/",			// 50
	"txt/pPb8_sysVzTight_MB3/",			// 51
	"txt/pPb8_sysVzLoose_MB3/",			// 52
	"txt/pPb8_sysVzVzNarrow_MB3/",			// 53
	"txt/pPb8_sysVzVzWide_MB3/",			// 54
	"txt/pPb8_sysVzTight_MB4/",			// 55
	"txt/pPb8_sysVzLoose_MB4/",			// 56
	"txt/pPb8_sysVzVzNarrow_MB4/",			// 57
	"txt/pPb8_sysVzVzWide_MB4/",			// 58
	"txt/pPb8_HM0_v7/",				// 59
	"txt/pPb8_HM1_v7/",				// 60
	"txt/pPb8_HM7_v7/",				// 61
	"txt/pPb8_MB1_v7/",				// 62
	"txt/pPb8_HM0_sysGplus_v7/",			// 63
	"txt/pPb8_HM1_sysGplus_v7/",			// 64
	"txt/pPb8_HM7_sysGplus_v7/",			// 65
	"txt/pPb8_MB1_sysGplus_v7/",			// 66
	"txt/testMB/",					// 67
	"txt/testHM0/",					// 68
	"txt/testHM1/",					// 69
	"txt/testHM7/",					// 70
	"txt/testHM/",					// 71
};

void addchain(int s1, string s)
{
        std::cout << fname[s1] << std::endl;
        chV->Add(Form("%s/*.root/%s/trV", fname[s1], s.c_str()));
}
