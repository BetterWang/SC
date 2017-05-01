#include "label.h"

void verify(int s1 = 1, int s3 = 10){
	std::vector<string> vs = {
		"QWSC2",
		"QWSC3",
		"QWSC4",
		"QWSC22",
		"QWSC2_2",
		"QWSC33",
		"QWSC3_3",
		"QWSC44",
		"QWSC4_4",
		"QWSC222",
		"QWSC22_2",
		"QWSC333",
		"QWSC33_3",
		"QWSC444",
		"QWSC44_4",
		"QWSC2222",
		"QWSC222_2",
		"QWSC22_2_2",
		"QWSC3333",
		"QWSC333_3",
		"QWSC33_3_3",
		"QWSC4444",
		"QWSC444_4",
		"QWSC44_4_4",
		"QWSC22222",
		"QWSC2222_2",
		"QWSC222_2_2",
		"QWSC33333",
		"QWSC3333_3",
		"QWSC333_3_3",
		"QWSC44444",
		"QWSC4444_4",
		"QWSC444_4_4",
		"QWSC222222",
		"QWSC22222_2",
		"QWSC2222_2_2",
		"QWSC222_2_2_2",
		"QWSC333333",
		"QWSC33333_3",
		"QWSC3333_3_3",
		"QWSC333_3_3_3",
		"QWSC444444",
		"QWSC44444_4",
		"QWSC4444_4_4",
		"QWSC444_4_4_4",
		"QWSC2222222",
		"QWSC222222_2",
		"QWSC22222_2_2",
		"QWSC2222_2_2_2",
		"QWSC3333333",
		"QWSC333333_3",
		"QWSC33333_3_3",
		"QWSC3333_3_3_3",
		"QWSC4444444",
		"QWSC444444_4",
		"QWSC44444_4_4",
		"QWSC4444_4_4_4",
		"QWSC22222222",
		"QWSC2222222_2",
		"QWSC222222_2_2",
		"QWSC22222_2_2_2",
		"QWSC2222_2_2_2_2",
		"QWSC33333333",
		"QWSC3333333_3",
		"QWSC333333_3_3",
		"QWSC33333_3_3_3",
		"QWSC3333_3_3_3_3",
		"QWSC44444444",
		"QWSC4444444_4",
		"QWSC444444_4_4",
		"QWSC44444_4_4_4",
		"QWSC4444_4_4_4_4"
	};
	cout << vs.size() << endl;
	double vNoff[72][20];
	TFile *f;
	for ( int s2 = 0; s2 <= s3; s2++ ) {
		for ( auto s :vs) {
			f = new TFile(Form("%s/%s_%i_%i.root", ftxt[s1], s.c_str(), s2, s3));

			TH1D * h;
			TH1D * x;
			int Nevt = 0;
			if (!f->IsZombie()) {
				h= (TH1D*) f->Get("hNoff");
				x= (TH1D*) f->Get("hCnR2");
				Nevt = h->GetEntries();
				cout << " s1 = " << s1 << "\ts2 = " << s2 << "\tNevt = " << Nevt;
				if (Nevt==0 ) cout << "\t!!!Empty!!!" << endl;
				else cout << endl;
			} else {
				cout << " s1 = " << s1 << "\ts2 = " << s2 << "\tNot exist!!!" << endl;
			}
			f->Close();

		}
	}
}

