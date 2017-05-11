#include "label.h"
//#include "noff.h"
#include <TFile.h>
#include <TTree.h>
#include <TH1.h>
#include <TMath.h>
#include "complex"
using namespace std;

void process(int s1 = 0, int s2 = 10, int s3 = 10, string s = "QWSC2_3_2_3")
{
	cout << " s1 = " << s1 << " s2 = " << s2 << " s3 = " << s3 << "\t s = " << s << endl;
	addchain(s1, s);
	chV->SetMakeClass(1);
	TH1::SetDefaultSumw2();


	int Noff;
	int Mult;
	double rQ;
	double iQ;
	double wQ;

	chV->SetBranchAddress("Noff", &Noff);
	chV->SetBranchAddress("Mult", &Mult);

	chV->SetBranchAddress("rQ", &rQ);
	chV->SetBranchAddress("iQ", &iQ);
	chV->SetBranchAddress("wQ", &wQ);

	TH1D * hSC  = new TH1D("hSC",  s.c_str(), 800, 0, 800);
	TH1D * hSCi = new TH1D("hSCi", s.c_str(), 800, 0, 800);
	TH1D * hSCw = new TH1D("hSCw", s.c_str(), 800, 0, 800);

	TH1D * hNoff  = new TH1D("hNoff", "hNoff", 800, 0, 800);
	TH1D * hMult  = new TH1D("hMult", "hMult", 800, 0, 800);

	unsigned int ievt = 0;
	if (s2!=s3) ievt = s2;
	while ( chV->GetEntry(ievt) ) {
		if ( !((ievt-s2)%100000) ) cout << "!! ievt = " << ievt << endl;
		if ( s2 == s3 ) ievt++;
		else ievt+= s3;
		if ( TMath::IsNaN(rQ) ) {
			std::cout << "!!! NaN !!! " << chV->GetFile()->GetName() << std::endl;
			continue;
		}
		hSC->Fill(Noff, rQ);
		hSCi->Fill(Noff, iQ);
		hSCw->Fill(Noff, wQ);
		hNoff->Fill(Noff);
		hMult->Fill(Mult);
	}


	TFile* fsave = new TFile(Form("%s/%s_%i_%i.root", ftxt[s1], s.c_str(), s2, s3), "recreate");
	hSC->Write();
	hSCi->Write();
	hSCw->Write();
	hNoff->Write();
	hMult->Write();

	fsave->Close();
}
