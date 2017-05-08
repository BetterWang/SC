#include "label.h"
#include "noff.h"
#include <TFile.h>
#include <TH1.h>
#include "const.h"
#include <complex>

typedef std::complex<double> QVect;

void bGetC(int s1 = 1, int s2 = 10, int s3 = 10)
{
	TFile* f = new TFile(Form("%s/outCumu_%i_%i.root", ftxt[s1], s2, s3));

	int NCent = NCentAA5TeV4;
	auto CentNoffCut = CentCutAA5TeV;

	double test1[5][20] = {};
	double test2[5][20] = {};
	double test3[5][20] = {};
	double test4[5][20] = {};
	double Q2c[5][20] = {};
	double Q4c[5][20] = {};
	double Q6c[5][20] = {};
	double Q8c[5][20] = {};

	for ( int n = 2; n < 5; n++ ) {
		double QSC1[20];
		double QSC2[20];
		double QSC3[20];
		double QSC4[20];
		double QSC5[20];
		double QSC6[20];
		double QSC7[20];
		double QSC8[20];
		double QSC1_1[20];
		double QSC2_1[20];
		double QSC3_1[20];
		double QSC4_1[20];
		double QSC5_1[20];
		double QSC6_1[20];
		double QSC7_1[20];
		double QSC2_2[20];
		double QSC3_2[20];
		double QSC4_2[20];
		double QSC5_2[20];
		double QSC6_2[20];
		double QSC3_3[20];
		double QSC4_3[20];
		double QSC5_3[20];
		double QSC4_4[20];

		double iQSC1[20];
		double iQSC2[20];
		double iQSC3[20];
		double iQSC4[20];
		double iQSC5[20];
		double iQSC6[20];
		double iQSC7[20];
		double iQSC8[20];
		double iQSC1_1[20];
		double iQSC2_1[20];
		double iQSC3_1[20];
		double iQSC4_1[20];
		double iQSC5_1[20];
		double iQSC6_1[20];
		double iQSC7_1[20];
		double iQSC2_2[20];
		double iQSC3_2[20];
		double iQSC4_2[20];
		double iQSC5_2[20];
		double iQSC6_2[20];
		double iQSC3_3[20];
		double iQSC4_3[20];
		double iQSC5_3[20];
		double iQSC4_4[20];

		double wQSC1[20];
		double wQSC2[20];
		double wQSC3[20];
		double wQSC4[20];
		double wQSC5[20];
		double wQSC6[20];
		double wQSC7[20];
		double wQSC8[20];
		double wQSC1_1[20];
		double wQSC2_1[20];
		double wQSC3_1[20];
		double wQSC4_1[20];
		double wQSC5_1[20];
		double wQSC6_1[20];
		double wQSC7_1[20];
		double wQSC2_2[20];
		double wQSC3_2[20];
		double wQSC4_2[20];
		double wQSC5_2[20];
		double wQSC6_2[20];
		double wQSC3_3[20];
		double wQSC4_3[20];
		double wQSC5_3[20];
		double wQSC4_4[20];

		TH1D * hQSC1   = (TH1D*) f->Get( Form( "hSCNorm_QWSC%i"                   , n                     ) );
		TH1D * hQSC2   = (TH1D*) f->Get( Form( "hSCNorm_QWSC%i%i"                 , n, n                  ) );
		TH1D * hQSC3   = (TH1D*) f->Get( Form( "hSCNorm_QWSC%i%i%i"               , n, n, n               ) );
		TH1D * hQSC4   = (TH1D*) f->Get( Form( "hSCNorm_QWSC%i%i%i%i"             , n, n, n, n            ) );
		TH1D * hQSC5   = (TH1D*) f->Get( Form( "hSCNorm_QWSC%i%i%i%i%i"           , n, n, n, n, n         ) );
		TH1D * hQSC6   = (TH1D*) f->Get( Form( "hSCNorm_QWSC%i%i%i%i%i%i"         , n, n, n, n, n, n      ) );
		TH1D * hQSC7   = (TH1D*) f->Get( Form( "hSCNorm_QWSC%i%i%i%i%i%i%i"       , n, n, n, n, n, n, n   ) );
		TH1D * hQSC8   = (TH1D*) f->Get( Form( "hSCNorm_QWSC%i%i%i%i%i%i%i%i"     , n, n, n, n, n, n, n, n) );
		TH1D * hQSC1_1 = (TH1D*) f->Get( Form( "hSCNorm_QWSC%i_%i"                , n, n                  ) );
		TH1D * hQSC2_1 = (TH1D*) f->Get( Form( "hSCNorm_QWSC%i%i_%i"              , n, n, n               ) );
		TH1D * hQSC3_1 = (TH1D*) f->Get( Form( "hSCNorm_QWSC%i%i%i_%i"            , n, n, n, n            ) );
		TH1D * hQSC4_1 = (TH1D*) f->Get( Form( "hSCNorm_QWSC%i%i%i%i_%i"          , n, n, n, n, n         ) );
		TH1D * hQSC5_1 = (TH1D*) f->Get( Form( "hSCNorm_QWSC%i%i%i%i%i_%i"        , n, n, n, n, n, n      ) );
		TH1D * hQSC6_1 = (TH1D*) f->Get( Form( "hSCNorm_QWSC%i%i%i%i%i%i_%i"      , n, n, n, n, n, n, n   ) );
		TH1D * hQSC7_1 = (TH1D*) f->Get( Form( "hSCNorm_QWSC%i%i%i%i%i%i%i_%i"    , n, n, n, n, n, n, n, n) );
		TH1D * hQSC2_2 = (TH1D*) f->Get( Form( "hSCNorm_QWSC%i%i_%i_%i"           , n, n, n, n            ) );
		TH1D * hQSC3_2 = (TH1D*) f->Get( Form( "hSCNorm_QWSC%i%i%i_%i_%i"         , n, n, n, n, n         ) );
		TH1D * hQSC4_2 = (TH1D*) f->Get( Form( "hSCNorm_QWSC%i%i%i%i_%i_%i"       , n, n, n, n, n, n      ) );
		TH1D * hQSC5_2 = (TH1D*) f->Get( Form( "hSCNorm_QWSC%i%i%i%i%i_%i_%i"     , n, n, n, n, n, n, n   ) );
		TH1D * hQSC6_2 = (TH1D*) f->Get( Form( "hSCNorm_QWSC%i%i%i%i%i%i_%i_%i"   , n, n, n, n, n, n, n, n) );
		TH1D * hQSC3_3 = (TH1D*) f->Get( Form( "hSCNorm_QWSC%i%i%i_%i_%i_%i"      , n, n, n, n, n, n      ) );
		TH1D * hQSC4_3 = (TH1D*) f->Get( Form( "hSCNorm_QWSC%i%i%i%i_%i_%i_%i"    , n, n, n, n, n, n, n   ) );
		TH1D * hQSC5_3 = (TH1D*) f->Get( Form( "hSCNorm_QWSC%i%i%i%i%i_%i_%i_%i"  , n, n, n, n, n, n, n, n) );
		TH1D * hQSC4_4 = (TH1D*) f->Get( Form( "hSCNorm_QWSC%i%i%i%i_%i_%i_%i_%i" , n, n, n, n, n, n, n, n) );

		TH1D * hwQSC1   = (TH1D*) f->Get( Form( "hSCw_QWSC%i"                   , n                     ) );
		TH1D * hwQSC2   = (TH1D*) f->Get( Form( "hSCw_QWSC%i%i"                 , n, n                  ) );
		TH1D * hwQSC3   = (TH1D*) f->Get( Form( "hSCw_QWSC%i%i%i"               , n, n, n               ) );
		TH1D * hwQSC4   = (TH1D*) f->Get( Form( "hSCw_QWSC%i%i%i%i"             , n, n, n, n            ) );
		TH1D * hwQSC5   = (TH1D*) f->Get( Form( "hSCw_QWSC%i%i%i%i%i"           , n, n, n, n, n         ) );
		TH1D * hwQSC6   = (TH1D*) f->Get( Form( "hSCw_QWSC%i%i%i%i%i%i"         , n, n, n, n, n, n      ) );
		TH1D * hwQSC7   = (TH1D*) f->Get( Form( "hSCw_QWSC%i%i%i%i%i%i%i"       , n, n, n, n, n, n, n   ) );
		TH1D * hwQSC8   = (TH1D*) f->Get( Form( "hSCw_QWSC%i%i%i%i%i%i%i%i"     , n, n, n, n, n, n, n, n) );
		TH1D * hwQSC1_1 = (TH1D*) f->Get( Form( "hSCw_QWSC%i_%i"                , n, n                  ) );
		TH1D * hwQSC2_1 = (TH1D*) f->Get( Form( "hSCw_QWSC%i%i_%i"              , n, n, n               ) );
		TH1D * hwQSC3_1 = (TH1D*) f->Get( Form( "hSCw_QWSC%i%i%i_%i"            , n, n, n, n            ) );
		TH1D * hwQSC4_1 = (TH1D*) f->Get( Form( "hSCw_QWSC%i%i%i%i_%i"          , n, n, n, n, n         ) );
		TH1D * hwQSC5_1 = (TH1D*) f->Get( Form( "hSCw_QWSC%i%i%i%i%i_%i"        , n, n, n, n, n, n      ) );
		TH1D * hwQSC6_1 = (TH1D*) f->Get( Form( "hSCw_QWSC%i%i%i%i%i%i_%i"      , n, n, n, n, n, n, n   ) );
		TH1D * hwQSC7_1 = (TH1D*) f->Get( Form( "hSCw_QWSC%i%i%i%i%i%i%i_%i"    , n, n, n, n, n, n, n, n) );
		TH1D * hwQSC2_2 = (TH1D*) f->Get( Form( "hSCw_QWSC%i%i_%i_%i"           , n, n, n, n            ) );
		TH1D * hwQSC3_2 = (TH1D*) f->Get( Form( "hSCw_QWSC%i%i%i_%i_%i"         , n, n, n, n, n         ) );
		TH1D * hwQSC4_2 = (TH1D*) f->Get( Form( "hSCw_QWSC%i%i%i%i_%i_%i"       , n, n, n, n, n, n      ) );
		TH1D * hwQSC5_2 = (TH1D*) f->Get( Form( "hSCw_QWSC%i%i%i%i%i_%i_%i"     , n, n, n, n, n, n, n   ) );
		TH1D * hwQSC6_2 = (TH1D*) f->Get( Form( "hSCw_QWSC%i%i%i%i%i%i_%i_%i"   , n, n, n, n, n, n, n, n) );
		TH1D * hwQSC3_3 = (TH1D*) f->Get( Form( "hSCw_QWSC%i%i%i_%i_%i_%i"      , n, n, n, n, n, n      ) );
		TH1D * hwQSC4_3 = (TH1D*) f->Get( Form( "hSCw_QWSC%i%i%i%i_%i_%i_%i"    , n, n, n, n, n, n, n   ) );
		TH1D * hwQSC5_3 = (TH1D*) f->Get( Form( "hSCw_QWSC%i%i%i%i%i_%i_%i_%i"  , n, n, n, n, n, n, n, n) );
		TH1D * hwQSC4_4 = (TH1D*) f->Get( Form( "hSCw_QWSC%i%i%i%i_%i_%i_%i_%i" , n, n, n, n, n, n, n, n) );

		TH1D * hiQSC1   = (TH1D*) f->Get( Form( "hSCiNorm_QWSC%i"                   , n                     ) );
		TH1D * hiQSC2   = (TH1D*) f->Get( Form( "hSCiNorm_QWSC%i%i"                 , n, n                  ) );
		TH1D * hiQSC3   = (TH1D*) f->Get( Form( "hSCiNorm_QWSC%i%i%i"               , n, n, n               ) );
		TH1D * hiQSC4   = (TH1D*) f->Get( Form( "hSCiNorm_QWSC%i%i%i%i"             , n, n, n, n            ) );
		TH1D * hiQSC5   = (TH1D*) f->Get( Form( "hSCiNorm_QWSC%i%i%i%i%i"           , n, n, n, n, n         ) );
		TH1D * hiQSC6   = (TH1D*) f->Get( Form( "hSCiNorm_QWSC%i%i%i%i%i%i"         , n, n, n, n, n, n      ) );
		TH1D * hiQSC7   = (TH1D*) f->Get( Form( "hSCiNorm_QWSC%i%i%i%i%i%i%i"       , n, n, n, n, n, n, n   ) );
		TH1D * hiQSC8   = (TH1D*) f->Get( Form( "hSCiNorm_QWSC%i%i%i%i%i%i%i%i"     , n, n, n, n, n, n, n, n) );
		TH1D * hiQSC1_1 = (TH1D*) f->Get( Form( "hSCiNorm_QWSC%i_%i"                , n, n                  ) );
		TH1D * hiQSC2_1 = (TH1D*) f->Get( Form( "hSCiNorm_QWSC%i%i_%i"              , n, n, n               ) );
		TH1D * hiQSC3_1 = (TH1D*) f->Get( Form( "hSCiNorm_QWSC%i%i%i_%i"            , n, n, n, n            ) );
		TH1D * hiQSC4_1 = (TH1D*) f->Get( Form( "hSCiNorm_QWSC%i%i%i%i_%i"          , n, n, n, n, n         ) );
		TH1D * hiQSC5_1 = (TH1D*) f->Get( Form( "hSCiNorm_QWSC%i%i%i%i%i_%i"        , n, n, n, n, n, n      ) );
		TH1D * hiQSC6_1 = (TH1D*) f->Get( Form( "hSCiNorm_QWSC%i%i%i%i%i%i_%i"      , n, n, n, n, n, n, n   ) );
		TH1D * hiQSC7_1 = (TH1D*) f->Get( Form( "hSCiNorm_QWSC%i%i%i%i%i%i%i_%i"    , n, n, n, n, n, n, n, n) );
		TH1D * hiQSC2_2 = (TH1D*) f->Get( Form( "hSCiNorm_QWSC%i%i_%i_%i"           , n, n, n, n            ) );
		TH1D * hiQSC3_2 = (TH1D*) f->Get( Form( "hSCiNorm_QWSC%i%i%i_%i_%i"         , n, n, n, n, n         ) );
		TH1D * hiQSC4_2 = (TH1D*) f->Get( Form( "hSCiNorm_QWSC%i%i%i%i_%i_%i"       , n, n, n, n, n, n      ) );
		TH1D * hiQSC5_2 = (TH1D*) f->Get( Form( "hSCiNorm_QWSC%i%i%i%i%i_%i_%i"     , n, n, n, n, n, n, n   ) );
		TH1D * hiQSC6_2 = (TH1D*) f->Get( Form( "hSCiNorm_QWSC%i%i%i%i%i%i_%i_%i"   , n, n, n, n, n, n, n, n) );
		TH1D * hiQSC3_3 = (TH1D*) f->Get( Form( "hSCiNorm_QWSC%i%i%i_%i_%i_%i"      , n, n, n, n, n, n      ) );
		TH1D * hiQSC4_3 = (TH1D*) f->Get( Form( "hSCiNorm_QWSC%i%i%i%i_%i_%i_%i"    , n, n, n, n, n, n, n   ) );
		TH1D * hiQSC5_3 = (TH1D*) f->Get( Form( "hSCiNorm_QWSC%i%i%i%i%i_%i_%i_%i"  , n, n, n, n, n, n, n, n) );
		TH1D * hiQSC4_4 = (TH1D*) f->Get( Form( "hSCiNorm_QWSC%i%i%i%i_%i_%i_%i_%i" , n, n, n, n, n, n, n, n) );

		for ( int c = 0; c < NCent; c++ ) {
			QSC1  [c] = hQSC1  ->GetBinContent(c+1);
			QSC2  [c] = hQSC2  ->GetBinContent(c+1);
			QSC3  [c] = hQSC3  ->GetBinContent(c+1);
			QSC4  [c] = hQSC4  ->GetBinContent(c+1);
			QSC5  [c] = hQSC5  ->GetBinContent(c+1);
			QSC6  [c] = hQSC6  ->GetBinContent(c+1);
			QSC7  [c] = hQSC7  ->GetBinContent(c+1);
			QSC8  [c] = hQSC8  ->GetBinContent(c+1);
			QSC1_1[c] = hQSC1_1->GetBinContent(c+1);
			QSC2_1[c] = hQSC2_1->GetBinContent(c+1);
			QSC3_1[c] = hQSC3_1->GetBinContent(c+1);
			QSC4_1[c] = hQSC4_1->GetBinContent(c+1);
			QSC5_1[c] = hQSC5_1->GetBinContent(c+1);
			QSC6_1[c] = hQSC6_1->GetBinContent(c+1);
			QSC7_1[c] = hQSC7_1->GetBinContent(c+1);
			QSC2_2[c] = hQSC2_2->GetBinContent(c+1);
			QSC3_2[c] = hQSC3_2->GetBinContent(c+1);
			QSC4_2[c] = hQSC4_2->GetBinContent(c+1);
			QSC5_2[c] = hQSC5_2->GetBinContent(c+1);
			QSC6_2[c] = hQSC6_2->GetBinContent(c+1);
			QSC3_3[c] = hQSC3_3->GetBinContent(c+1);
			QSC4_3[c] = hQSC4_3->GetBinContent(c+1);
			QSC5_3[c] = hQSC5_3->GetBinContent(c+1);
			QSC4_4[c] = hQSC4_4->GetBinContent(c+1);

			iQSC1  [c] = hiQSC1  ->GetBinContent(c+1);
			iQSC2  [c] = hiQSC2  ->GetBinContent(c+1);
			iQSC3  [c] = hiQSC3  ->GetBinContent(c+1);
			iQSC4  [c] = hiQSC4  ->GetBinContent(c+1);
			iQSC5  [c] = hiQSC5  ->GetBinContent(c+1);
			iQSC6  [c] = hiQSC6  ->GetBinContent(c+1);
			iQSC7  [c] = hiQSC7  ->GetBinContent(c+1);
			iQSC8  [c] = hiQSC8  ->GetBinContent(c+1);
			iQSC1_1[c] = hiQSC1_1->GetBinContent(c+1);
			iQSC2_1[c] = hiQSC2_1->GetBinContent(c+1);
			iQSC3_1[c] = hiQSC3_1->GetBinContent(c+1);
			iQSC4_1[c] = hiQSC4_1->GetBinContent(c+1);
			iQSC5_1[c] = hiQSC5_1->GetBinContent(c+1);
			iQSC6_1[c] = hiQSC6_1->GetBinContent(c+1);
			iQSC7_1[c] = hiQSC7_1->GetBinContent(c+1);
			iQSC2_2[c] = hiQSC2_2->GetBinContent(c+1);
			iQSC3_2[c] = hiQSC3_2->GetBinContent(c+1);
			iQSC4_2[c] = hiQSC4_2->GetBinContent(c+1);
			iQSC5_2[c] = hiQSC5_2->GetBinContent(c+1);
			iQSC6_2[c] = hiQSC6_2->GetBinContent(c+1);
			iQSC3_3[c] = hiQSC3_3->GetBinContent(c+1);
			iQSC4_3[c] = hiQSC4_3->GetBinContent(c+1);
			iQSC5_3[c] = hiQSC5_3->GetBinContent(c+1);
			iQSC4_4[c] = hiQSC4_4->GetBinContent(c+1);

			wQSC1  [c] = hwQSC1  ->GetBinContent(c+1);
			wQSC2  [c] = hwQSC2  ->GetBinContent(c+1);
			wQSC3  [c] = hwQSC3  ->GetBinContent(c+1);
			wQSC4  [c] = hwQSC4  ->GetBinContent(c+1);
			wQSC5  [c] = hwQSC5  ->GetBinContent(c+1);
			wQSC6  [c] = hwQSC6  ->GetBinContent(c+1);
			wQSC7  [c] = hwQSC7  ->GetBinContent(c+1);
			wQSC8  [c] = hwQSC8  ->GetBinContent(c+1);
			wQSC1_1[c] = hwQSC1_1->GetBinContent(c+1);
			wQSC2_1[c] = hwQSC2_1->GetBinContent(c+1);
			wQSC3_1[c] = hwQSC3_1->GetBinContent(c+1);
			wQSC4_1[c] = hwQSC4_1->GetBinContent(c+1);
			wQSC5_1[c] = hwQSC5_1->GetBinContent(c+1);
			wQSC6_1[c] = hwQSC6_1->GetBinContent(c+1);
			wQSC7_1[c] = hwQSC7_1->GetBinContent(c+1);
			wQSC2_2[c] = hwQSC2_2->GetBinContent(c+1);
			wQSC3_2[c] = hwQSC3_2->GetBinContent(c+1);
			wQSC4_2[c] = hwQSC4_2->GetBinContent(c+1);
			wQSC5_2[c] = hwQSC5_2->GetBinContent(c+1);
			wQSC6_2[c] = hwQSC6_2->GetBinContent(c+1);
			wQSC3_3[c] = hwQSC3_3->GetBinContent(c+1);
			wQSC4_3[c] = hwQSC4_3->GetBinContent(c+1);
			wQSC5_3[c] = hwQSC5_3->GetBinContent(c+1);
			wQSC4_4[c] = hwQSC4_4->GetBinContent(c+1);

			QVect Q1(QSC1[c], iQSC1[c]);
			QVect Q2(QSC2[c], iQSC2[c]);
			QVect Q3(QSC3[c], iQSC3[c]);
			QVect Q4(QSC4[c], iQSC4[c]);

			QVect Q1_1(QSC1_1[c], iQSC1_1[c]);
			QVect Q2_1(QSC2_1[c], iQSC2_1[c]);
			QVect Q3_1(QSC3_1[c], iQSC3_1[c]);
			QVect Q4_1(QSC4_1[c], iQSC4_1[c]);

			QVect Q2_2(QSC2_2[c], iQSC2_2[c]);
			QVect Q3_2(QSC3_2[c], iQSC3_2[c]);
			QVect Q4_2(QSC4_2[c], iQSC4_2[c]);

			QVect Q3_3(QSC3_3[c], iQSC3_3[c]);
			QVect Q4_3(QSC4_3[c], iQSC4_3[c]);

			QVect Q4_4(QSC4_4[c], iQSC4_4[c]);

			// 1 part
			QVect Qc1_0 = Q1;
			// 2 part
			QVect Qc2_0 = Q2 - Qc1_0 * Qc1_0;
			QVect Qc1_1 = Q1_1 - Qc1_0 * std::conj(Qc1_0);

			// 3 part
			QVect Qc3_0 = Q3 
				-1.0 * Qc1_0 * Qc1_0 * Qc1_0
				-3.0 * Qc1_0 * Qc2_0;
			// {'++-': 1, '+_+-': 2, '-_++': 1, '+_+_-': 1}
			QVect Qc2_1 = Q2_1 
				-2.0 * Qc1_0 * Qc1_1
				-1.0 * Qc1_0 * Qc1_0 * std::conj(Qc1_0)
				-1.0 * std::conj(Qc1_0) * Qc2_0;

			// 4 part
			QVect Qc4_0 = Q4 
				-6.0 * Qc1_0 * Qc1_0 * Qc2_0
				-1.0 * Qc1_0 * Qc1_0 * Qc1_0 * Qc1_0
				-3.0 * Qc2_0 * Qc2_0
				-4.0 * Qc1_0 * Qc3_0;
			// {'+++-': 1, '+_++-': 3, '++_+-': 3, '-_+++': 1, '+_+_+-': 3, '+_-_++': 3, '+_+_+_-': 1}
			QVect Qc3_1 = Q3_1 
				-3.0 * Qc1_0 * Qc2_1
				-3.0 * Qc1_0 * std::conj(Qc1_0) * Qc2_0
				-3.0 * Qc1_0 * Qc1_0 * Qc1_1
				-1.0 * std::conj(Qc1_0) * Qc3_0
				-3.0 * Qc2_0 * Qc1_1
				-1.0 * Qc1_0 * Qc1_0 * Qc1_0 * std::conj(Qc1_0);
			// {'++--': 1, '+_+--': 2, '++_--': 1, '-_++-': 2, '+-_+-': 2, '+_+_--': 1, '+_-_+-': 4, '-_-_++': 1, '+_+_-_-': 1}
			QVect Qc2_2 = Q2_2 
				-1.0 * Qc1_0 * Qc1_0 * std::conj(Qc2_0)
				-1.0 * Qc2_0 * std::conj(Qc2_0)
				-4.0 * Qc1_0 * std::conj(Qc1_0) * Qc1_1
				-1.0 * Qc1_0 * Qc1_0 * std::conj(Qc1_0) * std::conj(Qc1_0)
				-2.0 * Qc1_1 * Qc1_1
				-2.0 * std::conj(Qc1_0) * Qc2_1
				-2.0 * Qc1_0 * std::conj(Qc2_1)
				-1.0 * std::conj(Qc1_0) * std::conj(Qc1_0) * Qc2_0;
			// 5 part
			QVect Qc3_2 = Q3_2
				-3. * Qc1_0 * Qc2_2
				-3. * Qc2_0 * std::conj(Qc2_1)
				-1. * std::conj(Qc2_0) * Qc3_0
				-2. * std::conj(Qc1_0) * Qc3_1
				-6. * Qc1_1 * Qc2_1
				-3. * Qc1_0 * Qc1_0 * std::conj(Qc2_1)
				-3. * Qc1_0 * Qc2_0 * std::conj(Qc2_0)
				-6. * Qc1_0 * std::conj(Qc1_0) * Qc2_1
				-6. * Qc1_0 * Qc1_1 * Qc1_1
				-6. * std::conj(Qc1_0) * Qc2_0 * Qc1_1
				-1. * std::conj(Qc1_0) * std::conj(Qc1_0) * Qc3_0
				-1. * Qc1_0 * Qc1_0 * Qc1_0 * std::conj(Qc2_0)
				-6. * Qc1_0 * Qc1_0 * std::conj(Qc1_0) * Qc1_1
				-3. * Qc1_0 * std::conj(Qc1_0) * std::conj(Qc1_0) * Qc2_0
				-1. * Qc1_0 * Qc1_0 * Qc1_0 * std::conj(Qc1_0) * std::conj(Qc1_0);

			QVect Qc4_1 = Q4_1
				-4. * Qc1_0 * Qc3_1
				-6. * Qc2_0 * Qc2_1
				-4. * Qc1_1 * Qc3_0
				-1. * std::conj(Qc1_0) * Qc4_0
				-6. * Qc1_0 * Qc1_0 * Qc2_1
				-12.* Qc1_0 * Qc2_0 * Qc1_1
				-4. * Qc1_0 * std::conj(Qc1_0) * Qc3_0
				-3. * std::conj(Qc1_0) * Qc2_0 * Qc2_0
				-4. * Qc1_0 * Qc1_0 * Qc1_0 * Qc1_1
				-6. * Qc1_0 * Qc1_0 * std::conj(Qc1_0) * Qc2_0
				-1. * Qc1_0 * Qc1_0 * Qc1_0 * Qc1_0 * std::conj(Qc1_0);

			// 6 part
			QVect Qc3_3 = Q3_3
				-3. * Qc1_0 * std::conj(Qc3_2)
				-3. * Qc2_0 * std::conj(Qc3_1)
				-1. * Qc3_0 * std::conj(Qc3_0)
				-3. * std::conj(Qc2_0) * Qc3_1
				-6. * Qc2_1 * std::conj(Qc2_1)
				-9. * Qc1_1 * Qc2_2
				-3. * std::conj(Qc1_0) * Qc3_2
				-3. * std::conj(Qc2_1) * Qc2_1
				-3. * Qc1_0 * Qc1_0 * std::conj(Qc3_1)
				-3. * Qc1_0 * Qc2_0 * std::conj(Qc3_0)
				-9. * Qc1_0 * std::conj(Qc2_0) * Qc2_1
				-18. * Qc1_0 * Qc1_1 * std::conj(Qc2_1)
				-6. * Qc2_0 * Qc1_1 * std::conj(Qc2_0)
				-9. * Qc1_0 * std::conj(Qc1_0) * Qc2_2
				-9. * std::conj(Qc1_0) * Qc2_0 * std::conj(Qc2_1)
				-3. * std::conj(Qc1_0) * std::conj(Qc2_0) * Qc3_0
				-3. * Qc2_0 * std::conj(Qc2_0) * Qc1_1
				-3. * std::conj(Qc1_0) * std::conj(Qc1_0) * Qc3_1
				-18. * std::conj(Qc1_0) * Qc1_1 * Qc2_1
				-6. * Qc1_1 * Qc1_1 * Qc1_1
				-1. * Qc1_0 * Qc1_0 * Qc1_0 * std::conj(Qc3_0)
				-6. * Qc1_0 * Qc1_0 * Qc1_1 * std::conj(Qc2_0)
				-9. * Qc1_0 * Qc1_0 * std::conj(Qc1_0) * std::conj(Qc2_1)
				-9. * Qc1_0 * std::conj(Qc1_0) * Qc2_0 * std::conj(Qc2_0)
				-3. * Qc1_0 * Qc1_0 * std::conj(Qc2_0) * Qc1_1
				-9. * Qc1_0 * std::conj(Qc1_0) * std::conj(Qc1_0) * Qc2_1
				-18. * Qc1_0 * std::conj(Qc1_0) * Qc1_1 * Qc1_1
				-9. * std::conj(Qc1_0) * std::conj(Qc1_0) * Qc2_0 * Qc1_1
				-1. * std::conj(Qc1_0) * std::conj(Qc1_0) * std::conj(Qc1_0) * Qc3_0
				-3. * Qc1_0 * Qc1_0 * Qc1_0 * std::conj(Qc1_0) * std::conj(Qc2_0)
				-9. * Qc1_0 * Qc1_0 * std::conj(Qc1_0) * std::conj(Qc1_0) * Qc1_1
				-3. * Qc1_0 * std::conj(Qc1_0) * std::conj(Qc1_0) * std::conj(Qc1_0) * Qc2_0
				-1. * Qc1_0 * Qc1_0 * Qc1_0 * std::conj(Qc1_0) * std::conj(Qc1_0) * std::conj(Qc1_0);

			QVect Qc4_2 = Q4_2
				-4. * Qc1_0 * Qc3_2
				-6. * Qc2_0 * Qc2_2
				-4. * Qc3_0 * std::conj(Qc2_1)
				-1. * std::conj(Qc2_0) * Qc4_0
				-2. * std::conj(Qc1_0) * Qc4_1
				-8. * Qc1_1 * Qc3_1
				-6. * Qc2_1 * Qc2_1
				-6. * Qc1_0 * Qc1_0 * Qc2_2
				-12. * Qc1_0 * Qc2_0 * std::conj(Qc2_1)
				-4. * Qc1_0 * std::conj(Qc2_0) * Qc3_0
				-3. * Qc2_0 * Qc2_0 * std::conj(Qc2_0)
				-8. * Qc1_0 * std::conj(Qc1_0) * Qc3_1
				-24. * Qc1_0 * Qc1_1 * Qc2_1
				-12. * std::conj(Qc1_0) * Qc2_0 * Qc2_1
				-12. * Qc2_0 * Qc1_1 * Qc1_1
				-8. * std::conj(Qc1_0) * Qc1_1 * Qc3_0
				-1. * std::conj(Qc1_0) * std::conj(Qc1_0) * Qc4_0
				-4. * Qc1_0 * Qc1_0 * Qc1_0 * std::conj(Qc2_1)
				-6. * Qc1_0 * Qc1_0 * Qc2_0 * std::conj(Qc2_0)
				-12. * Qc1_0 * Qc1_0 * std::conj(Qc1_0) * Qc2_1
				-12. * Qc1_0 * Qc1_0 * Qc1_1 * Qc1_1
				-24. * Qc1_0 * std::conj(Qc1_0) * Qc2_0 * Qc1_1
				-4. * Qc1_0 * std::conj(Qc1_0) * std::conj(Qc1_0) * Qc3_0
				-3. * std::conj(Qc1_0) * std::conj(Qc1_0) * Qc2_0 * Qc2_0
				-1. * Qc1_0 * Qc1_0 * Qc1_0 * Qc1_0 * std::conj(Qc2_0)
				-8. * Qc1_0 * Qc1_0 * Qc1_0 * std::conj(Qc1_0) * Qc1_1
				-6. * Qc1_0 * Qc1_0 * std::conj(Qc1_0) * std::conj(Qc1_0) * Qc2_0
				-1. * Qc1_0 * Qc1_0 * Qc1_0 * Qc1_0 * std::conj(Qc1_0) * std::conj(Qc1_0);

			// 7 part
			QVect Qc4_3 = Q4_3
				-4. * Qc1_0 * Qc3_3
				-6. * Qc2_0 * std::conj(Qc3_2)
				-4. * Qc3_0 * std::conj(Qc3_1)
				-1. * std::conj(Qc3_0) * Qc4_0
				-3. * std::conj(Qc2_0) * Qc4_1
				-12. * std::conj(Qc2_1) * Qc3_1
				-18. * Qc2_1 * Qc2_2
				-12. * Qc1_1 * Qc3_2
				-3. * std::conj(Qc1_0) * Qc4_2
				-6. * Qc1_0 * Qc1_0 * std::conj(Qc3_2)
				-12. * Qc1_0 * Qc2_0 * std::conj(Qc3_1)
				-4. * Qc1_0 * Qc3_0 * std::conj(Qc3_0)
				-3. * Qc2_0 * Qc2_0 * std::conj(Qc3_0)
				-12. * Qc1_0 * std::conj(Qc2_0) * Qc3_1
				-24. * Qc1_0 * Qc2_1 * std::conj(Qc2_1)
				-18. * Qc2_0 * std::conj(Qc2_0) * Qc2_1
				-36. * Qc1_0 * Qc1_1 * Qc2_2
				-36. * Qc2_0 * Qc1_1 * std::conj(Qc2_1)
				-8. * Qc1_1 * std::conj(Qc2_0) * Qc3_0
				-12. * Qc1_0 * std::conj(Qc1_0) * Qc3_2
				-18. * std::conj(Qc1_0) * Qc2_0 * Qc2_2
				-12. * std::conj(Qc1_0) * Qc3_0 * std::conj(Qc2_1)
				-3. * std::conj(Qc1_0) * std::conj(Qc2_0) * Qc4_0
				-12. * Qc1_0 * std::conj(Qc2_1) * Qc2_1
				-4. * std::conj(Qc2_0) * Qc1_1 * Qc3_0
				-3. * std::conj(Qc1_0) * std::conj(Qc1_0) * Qc4_1
				-24. * std::conj(Qc1_0) * Qc1_1 * Qc3_1
				-18. * std::conj(Qc1_0) * Qc2_1 * Qc2_1
				-36. * Qc1_1 * Qc1_1 * Qc2_1
				-4. * Qc1_0 * Qc1_0 * Qc1_0 * std::conj(Qc3_1)
				-6. * Qc1_0 * Qc1_0 * Qc2_0 * std::conj(Qc3_0)
				-18. * Qc1_0 * Qc1_0 * std::conj(Qc2_0) * Qc2_1
				-36. * Qc1_0 * Qc1_0 * Qc1_1 * std::conj(Qc2_1)
				-24. * Qc1_0 * Qc2_0 * Qc1_1 * std::conj(Qc2_0)
				-18. * Qc1_0 * Qc1_0 * std::conj(Qc1_0) * Qc2_2
				-36. * Qc1_0 * std::conj(Qc1_0) * Qc2_0 * std::conj(Qc2_1)
				-12. * Qc1_0 * std::conj(Qc1_0) * std::conj(Qc2_0) * Qc3_0
				-9. * std::conj(Qc1_0) * Qc2_0 * Qc2_0 * std::conj(Qc2_0)
				-12. * Qc1_0 * Qc2_0 * std::conj(Qc2_0) * Qc1_1
				-12. * Qc1_0 * std::conj(Qc1_0) * std::conj(Qc1_0) * Qc3_1
				-72. * Qc1_0 * std::conj(Qc1_0) * Qc1_1 * Qc2_1
				-18. * std::conj(Qc1_0) * std::conj(Qc1_0) * Qc2_0 * Qc2_1
				-24. * Qc1_0 * Qc1_1 * Qc1_1 * Qc1_1
				-36. * std::conj(Qc1_0) * Qc2_0 * Qc1_1 * Qc1_1
				-12. * std::conj(Qc1_0) * std::conj(Qc1_0) * Qc1_1 * Qc3_0
				-1. * std::conj(Qc1_0) * std::conj(Qc1_0) * std::conj(Qc1_0) * Qc4_0
				-1. * Qc1_0 * Qc1_0 * Qc1_0 * Qc1_0 * std::conj(Qc3_0)
				-8. * Qc1_0 * Qc1_0 * Qc1_0 * Qc1_1 * std::conj(Qc2_0)
				-12. * Qc1_0 * Qc1_0 * Qc1_0 * std::conj(Qc1_0) * std::conj(Qc2_1)
				-18. * Qc1_0 * Qc1_0 * std::conj(Qc1_0) * Qc2_0 * std::conj(Qc2_0)
				-4. * Qc1_0 * Qc1_0 * Qc1_0 * std::conj(Qc2_0) * Qc1_1
				-18. * Qc1_0 * Qc1_0 * std::conj(Qc1_0) * std::conj(Qc1_0) * Qc2_1
				-36. * Qc1_0 * Qc1_0 * std::conj(Qc1_0) * Qc1_1 * Qc1_1
				-36. * Qc1_0 * std::conj(Qc1_0) * std::conj(Qc1_0) * Qc2_0 * Qc1_1
				-4. * Qc1_0 * std::conj(Qc1_0) * std::conj(Qc1_0) * std::conj(Qc1_0) * Qc3_0
				-3. * std::conj(Qc1_0) * std::conj(Qc1_0) * std::conj(Qc1_0) * Qc2_0 * Qc2_0
				-3. * Qc1_0 * Qc1_0 * Qc1_0 * Qc1_0 * std::conj(Qc1_0) * std::conj(Qc2_0)
				-12. * Qc1_0 * Qc1_0 * Qc1_0 * std::conj(Qc1_0) * std::conj(Qc1_0) * Qc1_1
				-6. * Qc1_0 * Qc1_0 * std::conj(Qc1_0) * std::conj(Qc1_0) * std::conj(Qc1_0) * Qc2_0
				-1. * Qc1_0 * Qc1_0 * Qc1_0 * Qc1_0 * std::conj(Qc1_0) * std::conj(Qc1_0) * std::conj(Qc1_0);

			// 8 part
			QVect Qc4_4 = Q4_4
				-4. * Qc1_0 * std::conj(Qc4_3)
				-6. * Qc2_0 * std::conj(Qc4_2)
				-4. * Qc3_0 * std::conj(Qc4_1)
				-1. * Qc4_0 * std::conj(Qc4_0)
				-4. * std::conj(Qc3_0) * Qc4_1
				-12. * Qc3_1 * std::conj(Qc3_1)
				-24. * Qc2_1 * std::conj(Qc3_2)
				-16. * Qc1_1 * Qc3_3
				-4. * std::conj(Qc1_0) * Qc4_3
				-6. * std::conj(Qc2_0) * Qc4_2
				-24. * std::conj(Qc2_1) * Qc3_2
				-18. * Qc2_2 * Qc2_2
				-4. * std::conj(Qc3_1) * Qc3_1
				-6. * Qc1_0 * Qc1_0 * std::conj(Qc4_2)
				-12. * Qc1_0 * Qc2_0 * std::conj(Qc4_1)
				-4. * Qc1_0 * Qc3_0 * std::conj(Qc4_0)
				-3. * Qc2_0 * Qc2_0 * std::conj(Qc4_0)
				-16. * Qc1_0 * std::conj(Qc3_0) * Qc3_1
				-48. * Qc1_0 * Qc2_1 * std::conj(Qc3_1)
				-18. * Qc2_0 * Qc2_1 * std::conj(Qc3_0)
				-48. * Qc1_0 * Qc1_1 * std::conj(Qc3_2)
				-48. * Qc2_0 * Qc1_1 * std::conj(Qc3_1)
				-16. * Qc1_1 * Qc3_0 * std::conj(Qc3_0)
				-16. * Qc1_0 * std::conj(Qc1_0) * Qc3_3
				-24. * std::conj(Qc1_0) * Qc2_0 * std::conj(Qc3_2)
				-16. * std::conj(Qc1_0) * Qc3_0 * std::conj(Qc3_1)
				-4. * std::conj(Qc1_0) * std::conj(Qc3_0) * Qc4_0
				-24. * Qc1_0 * std::conj(Qc2_0) * Qc3_2
				-72. * Qc1_0 * std::conj(Qc2_1) * Qc2_2
				-36. * Qc2_0 * std::conj(Qc2_0) * Qc2_2
				-36. * Qc2_0 * std::conj(Qc2_1) * std::conj(Qc2_1)
				-24. * std::conj(Qc2_0) * Qc3_0 * std::conj(Qc2_1)
				-3. * std::conj(Qc2_0) * std::conj(Qc2_0) * Qc4_0
				-12. * std::conj(Qc1_0) * std::conj(Qc2_0) * Qc4_1
				-32. * Qc1_1 * std::conj(Qc2_0) * Qc3_1
				-48. * std::conj(Qc1_0) * std::conj(Qc2_1) * Qc3_1
				-36. * std::conj(Qc2_0) * Qc2_1 * Qc2_1
				-96. * Qc1_1 * Qc2_1 * std::conj(Qc2_1)
				-72. * std::conj(Qc1_0) * Qc2_1 * Qc2_2
				-72. * Qc1_1 * Qc1_1 * Qc2_2
				-48. * std::conj(Qc1_0) * Qc1_1 * Qc3_2
				-6. * std::conj(Qc1_0) * std::conj(Qc1_0) * Qc4_2
				-6. * Qc2_0 * std::conj(Qc3_0) * Qc2_1
				-16. * std::conj(Qc2_0) * Qc1_1 * Qc3_1
				-48. * Qc1_1 * std::conj(Qc2_1) * Qc2_1
				-4. * Qc1_0 * Qc1_0 * Qc1_0 * std::conj(Qc4_1)
				-6. * Qc1_0 * Qc1_0 * Qc2_0 * std::conj(Qc4_0)
				-18. * Qc1_0 * Qc1_0 * Qc2_1 * std::conj(Qc3_0)
				-48. * Qc1_0 * Qc1_0 * Qc1_1 * std::conj(Qc3_1)
				-48. * Qc1_0 * Qc2_0 * Qc1_1 * std::conj(Qc3_0)
				-24. * Qc1_0 * Qc1_0 * std::conj(Qc1_0) * std::conj(Qc3_2)
				-48. * Qc1_0 * std::conj(Qc1_0) * Qc2_0 * std::conj(Qc3_1)
				-16. * Qc1_0 * std::conj(Qc1_0) * Qc3_0 * std::conj(Qc3_0)
				-12. * std::conj(Qc1_0) * Qc2_0 * Qc2_0 * std::conj(Qc3_0)
				-36. * Qc1_0 * Qc1_0 * std::conj(Qc2_0) * Qc2_2
				-36. * Qc1_0 * Qc1_0 * std::conj(Qc2_1) * std::conj(Qc2_1)
				-72. * Qc1_0 * Qc2_0 * std::conj(Qc2_0) * std::conj(Qc2_1)
				-12. * Qc1_0 * std::conj(Qc2_0) * std::conj(Qc2_0) * Qc3_0
				-9. * Qc2_0 * Qc2_0 * std::conj(Qc2_0) * std::conj(Qc2_0)
				-48. * Qc1_0 * std::conj(Qc1_0) * std::conj(Qc2_0) * Qc3_1
				-96. * Qc1_0 * Qc1_1 * std::conj(Qc2_0) * Qc2_1
				-96. * Qc1_0 * std::conj(Qc1_0) * Qc2_1 * std::conj(Qc2_1)
				-72. * std::conj(Qc1_0) * Qc2_0 * std::conj(Qc2_0) * Qc2_1
				-144. * Qc1_0 * Qc1_1 * Qc1_1 * std::conj(Qc2_1)
				-36. * Qc2_0 * Qc1_1 * Qc1_1 * std::conj(Qc2_0)
				-144. * Qc1_0 * std::conj(Qc1_0) * Qc1_1 * Qc2_2
				-144. * std::conj(Qc1_0) * Qc2_0 * Qc1_1 * std::conj(Qc2_1)
				-32. * std::conj(Qc1_0) * Qc1_1 * std::conj(Qc2_0) * Qc3_0
				-24. * Qc1_0 * std::conj(Qc1_0) * std::conj(Qc1_0) * Qc3_2
				-36. * std::conj(Qc1_0) * std::conj(Qc1_0) * Qc2_0 * Qc2_2
				-24. * std::conj(Qc1_0) * std::conj(Qc1_0) * Qc3_0 * std::conj(Qc2_1)
				-6. * std::conj(Qc1_0) * std::conj(Qc1_0) * std::conj(Qc2_0) * Qc4_0
				-6. * Qc1_0 * Qc1_0 * std::conj(Qc3_0) * Qc2_1
				-48. * Qc1_0 * std::conj(Qc2_0) * Qc1_1 * Qc2_1
				-24. * Qc2_0 * Qc1_1 * std::conj(Qc2_0) * Qc1_1
				-48. * Qc1_0 * std::conj(Qc1_0) * std::conj(Qc2_1) * Qc2_1
				-16. * std::conj(Qc1_0) * std::conj(Qc2_0) * Qc1_1 * Qc3_0
				-12. * Qc2_0 * std::conj(Qc2_0) * Qc1_1 * Qc1_1
				-4. * std::conj(Qc1_0) * std::conj(Qc1_0) * std::conj(Qc1_0) * Qc4_1
				-48. * std::conj(Qc1_0) * std::conj(Qc1_0) * Qc1_1 * Qc3_1
				-36. * std::conj(Qc1_0) * std::conj(Qc1_0) * Qc2_1 * Qc2_1
				-144. * std::conj(Qc1_0) * Qc1_1 * Qc1_1 * Qc2_1
				-24. * Qc1_1 * Qc1_1 * Qc1_1 * Qc1_1
				-1. * Qc1_0 * Qc1_0 * Qc1_0 * Qc1_0 * std::conj(Qc4_0)
				-16. * Qc1_0 * Qc1_0 * Qc1_0 * Qc1_1 * std::conj(Qc3_0)
				-16. * Qc1_0 * Qc1_0 * Qc1_0 * std::conj(Qc1_0) * std::conj(Qc3_1)
				-24. * Qc1_0 * Qc1_0 * std::conj(Qc1_0) * Qc2_0 * std::conj(Qc3_0)
				-24. * Qc1_0 * Qc1_0 * Qc1_0 * std::conj(Qc2_0) * std::conj(Qc2_1)
				-18. * Qc1_0 * Qc1_0 * Qc2_0 * std::conj(Qc2_0) * std::conj(Qc2_0)
				-72. * Qc1_0 * Qc1_0 * std::conj(Qc1_0) * std::conj(Qc2_0) * Qc2_1
				-36. * Qc1_0 * Qc1_0 * Qc1_1 * Qc1_1 * std::conj(Qc2_0)
				-144. * Qc1_0 * Qc1_0 * std::conj(Qc1_0) * Qc1_1 * std::conj(Qc2_1)
				-96. * Qc1_0 * std::conj(Qc1_0) * Qc2_0 * Qc1_1 * std::conj(Qc2_0)
				-36. * Qc1_0 * Qc1_0 * std::conj(Qc1_0) * std::conj(Qc1_0) * Qc2_2
				-72. * Qc1_0 * std::conj(Qc1_0) * std::conj(Qc1_0) * Qc2_0 * std::conj(Qc2_1)
				-24. * Qc1_0 * std::conj(Qc1_0) * std::conj(Qc1_0) * std::conj(Qc2_0) * Qc3_0
				-18. * std::conj(Qc1_0) * std::conj(Qc1_0) * Qc2_0 * Qc2_0 * std::conj(Qc2_0)
				-24. * Qc1_0 * Qc1_0 * Qc1_1 * std::conj(Qc2_0) * Qc1_1
				-48. * Qc1_0 * std::conj(Qc1_0) * Qc2_0 * std::conj(Qc2_0) * Qc1_1
				-12. * Qc1_0 * Qc1_0 * std::conj(Qc2_0) * Qc1_1 * Qc1_1
				-16. * Qc1_0 * std::conj(Qc1_0) * std::conj(Qc1_0) * std::conj(Qc1_0) * Qc3_1
				-144. * Qc1_0 * std::conj(Qc1_0) * std::conj(Qc1_0) * Qc1_1 * Qc2_1
				-24. * std::conj(Qc1_0) * std::conj(Qc1_0) * std::conj(Qc1_0) * Qc2_0 * Qc2_1
				-96. * Qc1_0 * std::conj(Qc1_0) * Qc1_1 * Qc1_1 * Qc1_1
				-72. * std::conj(Qc1_0) * std::conj(Qc1_0) * Qc2_0 * Qc1_1 * Qc1_1
				-16. * std::conj(Qc1_0) * std::conj(Qc1_0) * std::conj(Qc1_0) * Qc1_1 * Qc3_0
				-1. * std::conj(Qc1_0) * std::conj(Qc1_0) * std::conj(Qc1_0) * std::conj(Qc1_0) * Qc4_0
				-4. * Qc1_0 * Qc1_0 * Qc1_0 * Qc1_0 * std::conj(Qc1_0) * std::conj(Qc3_0)
				-3. * Qc1_0 * Qc1_0 * Qc1_0 * Qc1_0 * std::conj(Qc2_0) * std::conj(Qc2_0)
				-32. * Qc1_0 * Qc1_0 * Qc1_0 * std::conj(Qc1_0) * Qc1_1 * std::conj(Qc2_0)
				-24. * Qc1_0 * Qc1_0 * Qc1_0 * std::conj(Qc1_0) * std::conj(Qc1_0) * std::conj(Qc2_1)
				-36. * Qc1_0 * Qc1_0 * std::conj(Qc1_0) * std::conj(Qc1_0) * Qc2_0 * std::conj(Qc2_0)
				-16. * Qc1_0 * Qc1_0 * Qc1_0 * std::conj(Qc1_0) * std::conj(Qc2_0) * Qc1_1
				-24. * Qc1_0 * Qc1_0 * std::conj(Qc1_0) * std::conj(Qc1_0) * std::conj(Qc1_0) * Qc2_1
				-72. * Qc1_0 * Qc1_0 * std::conj(Qc1_0) * std::conj(Qc1_0) * Qc1_1 * Qc1_1
				-48. * Qc1_0 * std::conj(Qc1_0) * std::conj(Qc1_0) * std::conj(Qc1_0) * Qc2_0 * Qc1_1
				-4. * Qc1_0 * std::conj(Qc1_0) * std::conj(Qc1_0) * std::conj(Qc1_0) * std::conj(Qc1_0) * Qc3_0
				-3. * std::conj(Qc1_0) * std::conj(Qc1_0) * std::conj(Qc1_0) * std::conj(Qc1_0) * Qc2_0 * Qc2_0
				-6. * Qc1_0 * Qc1_0 * Qc1_0 * Qc1_0 * std::conj(Qc1_0) * std::conj(Qc1_0) * std::conj(Qc2_0)
				-16. * Qc1_0 * Qc1_0 * Qc1_0 * std::conj(Qc1_0) * std::conj(Qc1_0) * std::conj(Qc1_0) * Qc1_1
				-6. * Qc1_0 * Qc1_0 * std::conj(Qc1_0) * std::conj(Qc1_0) * std::conj(Qc1_0) * std::conj(Qc1_0) * Qc2_0
				-1. * Qc1_0 * Qc1_0 * Qc1_0 * Qc1_0 * std::conj(Qc1_0) * std::conj(Qc1_0) * std::conj(Qc1_0) * std::conj(Qc1_0);




			test1[n][c] = Q1_1.real();
			test2[n][c] = Q1_1.imag();
			test3[n][c] = Qc1_0.real();
			test4[n][c] = Qc1_0.imag();

			Q2c[n][c] = Qc1_1.real();
			Q4c[n][c] = Qc2_2.real();
			Q6c[n][c] = Qc3_3.real();
			Q8c[n][c] = Qc4_4.real();
		}
	}

	TFile * fsave = new TFile( Form("%s/outQc_%i_%i.root", ftxt[s1], s2, s3), "recreate" );
	TH1D * hQc2[5] = {};
	TH1D * hQc4[5] = {};
	TH1D * hQc6[5] = {};
	TH1D * hQc8[5] = {};
	TH1D * htest1[5] = {};
	TH1D * htest2[5] = {};
	TH1D * htest3[5] = {};
	TH1D * htest4[5] = {};
	for ( int n = 2; n < 5; n++ ) {
		hQc2[n] = new TH1D(Form("hQc2%i", n), "", 20, 0, 20);
		hQc4[n] = new TH1D(Form("hQc4%i", n), "", 20, 0, 20);
		hQc6[n] = new TH1D(Form("hQc6%i", n), "", 20, 0, 20);
		hQc8[n] = new TH1D(Form("hQc8%i", n), "", 20, 0, 20);
		htest1[n] = new TH1D(Form("htest1%i", n), "", 20, 0, 20);
		htest2[n] = new TH1D(Form("htest2%i", n), "", 20, 0, 20);
		htest3[n] = new TH1D(Form("htest3%i", n), "", 20, 0, 20);
		htest4[n] = new TH1D(Form("htest4%i", n), "", 20, 0, 20);

		for ( int c = 0; c < NCent; c++ ) {
			hQc2[n]->SetBinContent(c+1, Q2c[n][c]);
			hQc4[n]->SetBinContent(c+1, Q4c[n][c]);
			hQc6[n]->SetBinContent(c+1, Q6c[n][c]);
			hQc8[n]->SetBinContent(c+1, Q8c[n][c]);
			htest1[n]->SetBinContent(c+1, test1[n][c]);
			htest2[n]->SetBinContent(c+1, test2[n][c]);
			htest3[n]->SetBinContent(c+1, test3[n][c]);
			htest4[n]->SetBinContent(c+1, test4[n][c]);
		}
		hQc2[n]->Write();
		hQc4[n]->Write();
		hQc6[n]->Write();
		hQc8[n]->Write();
//		htest1[n]->Write();
//		htest2[n]->Write();
//		htest3[n]->Write();
//		htest4[n]->Write();
	}
	fsave->Close();
}
