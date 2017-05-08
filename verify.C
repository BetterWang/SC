#include "label.h"
#include "const.h"

void verify(int s1 = 1, string sq = "all", int verbos = 0){
	int vNoff[72][20] = {};
	TFile *f;
	int s3 = 10;

	std::vector<std::string> vQ;
	if ( sq == "all" ){
		vQ = vectQ;
	} else {
		vQ.push_back(sq);
	}
	for ( int i = 0; i < vQ.size(); i++ ) {
		auto s = vQ[i];
		for ( int s2 = 0; s2 <= s3; s2++ ) {
			f = new TFile(Form("%s/%s_%i_%i.root", ftxt[s1], s.c_str(), s2, s3));
			TH1D * h;
			TH1D * x;
			if (!f->IsZombie()) {
				h= (TH1D*) f->Get("hNoff");
				vNoff[i][s2] = h->GetEntries();
				if ( vNoff[i][s2] == 0 ) cout << "!!!Empty!!!   s1 = " << s1 << "\t" << s << "\t" << s2  << endl;
			} else {
				cout << "!!!Missing!!!   s1 = " << s1 << "\t" << s << "\t" << s2  << endl;
			}
			f->Close();
		}

		bool miss = false;
		for ( int s2 = 0; s2 < s3; s2++ ) {
//			int err = sqrt(vNoff[i][s3]/s3);
			int err = 10;
			int NoffS3 = vNoff[i][s3]/s3;
			if ( (NoffS3 < vNoff[i][s2] - err) or (NoffS3 > vNoff[i][s2] + err) ) {
//				cout << " NoffS3 = " << NoffS3 << "\t err = " << err << "\t" << (vNoff[i][s2] - err) << "\t" << (NoffS3 > vNoff[i][s2] + err) << " i = " << i << endl;
				miss = true;
				break;
			}
		}
		if ( miss ) {
			cout << "!!!miss matching!!! << s1 = " << s1 << "\t" << s << endl;
			if ( sq != "all") {
				for ( int s2 = 0; s2 <= s3; s2++ ) {
					cout << "   s2 = " << s2 << "\t" << vNoff[i][s2] << endl;
				}
			}
		}
		if ( verbos == 1 ) {
			for ( int s2 = 0; s2 <= s3; s2++ ) {
				cout << "   s2 = " << s2 << "\t" << vNoff[i][s2] << endl;
			}
		}
	}
}

