#include "label.h"
#include "noff.h"

void makeplot(int s1=12)
{
	TFile * f23 = new TFile(Form("%s/outQWSC2_3_2_3.root", ftxt[s1]));
	TFile * f24 = new TFile(Form("%s/outQWSC2_4_2_4.root", ftxt[s1]));
	TFile * f25 = new TFile(Form("%s/outQWSC2_5_2_5.root", ftxt[s1]));
	TFile * f26 = new TFile(Form("%s/outQWSC2_6_2_6.root", ftxt[s1]));

	TFile * f34 = new TFile(Form("%s/outQWSC3_4_3_4.root", ftxt[s1]));
	TFile * f35 = new TFile(Form("%s/outQWSC3_5_3_5.root", ftxt[s1]));
	TFile * f36 = new TFile(Form("%s/outQWSC3_6_3_6.root", ftxt[s1]));

	TFile * f45 = new TFile(Form("%s/outQWSC4_5_4_5.root", ftxt[s1]));
	TFile * f46 = new TFile(Form("%s/outQWSC4_6_4_6.root", ftxt[s1]));

	TFile * f56 = new TFile(Form("%s/outQWSC5_6_5_6.root", ftxt[s1]));

	TFile * f22 = new TFile(Form("%s/outQWSC2_2.root", ftxt[s1]));
	TFile * f33 = new TFile(Form("%s/outQWSC3_3.root", ftxt[s1]));
	TFile * f44 = new TFile(Form("%s/outQWSC4_4.root", ftxt[s1]));
	TFile * f55 = new TFile(Form("%s/outQWSC5_5.root", ftxt[s1]));
	TFile * f66 = new TFile(Form("%s/outQWSC6_6.root", ftxt[s1]));

	TH1D * h2323 = (TH1D *) f23->Get("hSCNorm_merged");
	TH1D * h2424 = (TH1D *) f24->Get("hSCNorm_merged");
	TH1D * h2525 = (TH1D *) f25->Get("hSCNorm_merged");
	TH1D * h2626 = (TH1D *) f26->Get("hSCNorm_merged");

	TH1D * h3434 = (TH1D *) f34->Get("hSCNorm_merged");
	TH1D * h3535 = (TH1D *) f35->Get("hSCNorm_merged");
	TH1D * h3636 = (TH1D *) f36->Get("hSCNorm_merged");

	TH1D * h4545 = (TH1D *) f45->Get("hSCNorm_merged");
	TH1D * h4646 = (TH1D *) f46->Get("hSCNorm_merged");

	TH1D * h5656 = (TH1D *) f56->Get("hSCNorm_merged");

	TH1D * h22 = (TH1D *) f22->Get("hSCNorm_merged");
	TH1D * h33 = (TH1D *) f33->Get("hSCNorm_merged");
	TH1D * h44 = (TH1D *) f44->Get("hSCNorm_merged");
	TH1D * h55 = (TH1D *) f55->Get("hSCNorm_merged");
	TH1D * h66 = (TH1D *) f66->Get("hSCNorm_merged");

	TH1D * h2233 = (TH1D*) h22->Clone("h2233");
	TH1D * h2244 = (TH1D*) h22->Clone("h2244");
	TH1D * h2255 = (TH1D*) h22->Clone("h2255");
	TH1D * h2266 = (TH1D*) h22->Clone("h2266");

	TH1D * h3344 = (TH1D*) h33->Clone("h3344");
	TH1D * h3355 = (TH1D*) h33->Clone("h3355");
	TH1D * h3366 = (TH1D*) h33->Clone("h3366");

	TH1D * h4455 = (TH1D*) h44->Clone("h4455");
	TH1D * h4466 = (TH1D*) h44->Clone("h4466");

	TH1D * h5566 = (TH1D*) h55->Clone("h5566");

	h2233->Multiply(h33);
	h2244->Multiply(h44);
	h2255->Multiply(h55);
	h2266->Multiply(h66);

	h3344->Multiply(h44);
	h3355->Multiply(h55);
	h3366->Multiply(h66);

	h4455->Multiply(h55);
	h4466->Multiply(h66);

	h5566->Multiply(h66);

	h2323->Add(h2233, -1);
	h2424->Add(h2244, -1);
	h2525->Add(h2255, -1);
	h2626->Add(h2266, -1);

	h3434->Add(h3344, -1);
	h3535->Add(h3355, -1);
	h3636->Add(h3366, -1);

	h4545->Add(h4455, -1);
	h4646->Add(h4466, -1);

	h5656->Add(h5566, -1);


	double y2323[100] = {};
	double y2424[100] = {};
	double y2525[100] = {};
	double y2626[100] = {};

	double y3434[100] = {};
	double y3535[100] = {};
	double y3636[100] = {};

	double y4545[100] = {};
	double y4646[100] = {};

	double y5656[100] = {};

	double e2323[100] = {};
	double e2424[100] = {};
	double e2525[100] = {};
	double e2626[100] = {};

	double e3434[100] = {};
	double e3535[100] = {};
	double e3636[100] = {};

	double e4545[100] = {};
	double e4646[100] = {};

	double e5656[100] = {};

	double y22[100] = {};
	double y33[100] = {};
	double y44[100] = {};
	double y55[100] = {};
	double y66[100] = {};

	double e22[100] = {};
	double e33[100] = {};
	double e44[100] = {};
	double e55[100] = {};
	double e66[100] = {};

	int NCent = NCentCommon;
	double * CentX = CentNoffX;
	if ( s1 == 2 ) {
		NCent = NCentPbPb;
		CentX = CentNoffXPbPb;
	}


	for ( int i = 0; i < NCent; i++ ) {
		y2323[i] = h2323->GetBinContent(i+1);
		y2424[i] = h2424->GetBinContent(i+1);
		y2525[i] = h2525->GetBinContent(i+1);
		y2626[i] = h2626->GetBinContent(i+1);

		y3434[i] = h3434->GetBinContent(i+1);
		y3535[i] = h3535->GetBinContent(i+1);
		y3636[i] = h3636->GetBinContent(i+1);

		y4545[i] = h4545->GetBinContent(i+1);
		y4646[i] = h4646->GetBinContent(i+1);

		y5656[i] = h5656->GetBinContent(i+1);

		e2323[i] = h2323->GetBinError(i+1);
		e2424[i] = h2424->GetBinError(i+1);
		e2525[i] = h2525->GetBinError(i+1);
		e2626[i] = h2626->GetBinError(i+1);

		e3434[i] = h3434->GetBinError(i+1);
		e3535[i] = h3535->GetBinError(i+1);
		e3636[i] = h3636->GetBinError(i+1);

		e4545[i] = h4545->GetBinError(i+1);
		e4646[i] = h4646->GetBinError(i+1);

		e5656[i] = h5656->GetBinError(i+1);

		y22[i] = h22->GetBinContent(i+1);
		y33[i] = h33->GetBinContent(i+1);
		y44[i] = h44->GetBinContent(i+1);
		y55[i] = h55->GetBinContent(i+1);
		y66[i] = h66->GetBinContent(i+1);

		e22[i] = h22->GetBinError(i+1);
		e33[i] = h33->GetBinError(i+1);
		e44[i] = h44->GetBinError(i+1);
		e55[i] = h55->GetBinError(i+1);
		e66[i] = h66->GetBinError(i+1);
	}


	TGraphErrors * gr2323 = new TGraphErrors(NCent, CentX, y2323, 0, e2323);
	TGraphErrors * gr2424 = new TGraphErrors(NCent, CentX, y2424, 0, e2424);
	TGraphErrors * gr2525 = new TGraphErrors(NCent, CentX, y2525, 0, e2525);
	TGraphErrors * gr2626 = new TGraphErrors(NCent, CentX, y2626, 0, e2626);

	TGraphErrors * gr3434 = new TGraphErrors(NCent, CentX, y3434, 0, e3434);
	TGraphErrors * gr3535 = new TGraphErrors(NCent, CentX, y3535, 0, e3535);
	TGraphErrors * gr3636 = new TGraphErrors(NCent, CentX, y3636, 0, e3636);

	TGraphErrors * gr4545 = new TGraphErrors(NCent, CentX, y4545, 0, e4545);
	TGraphErrors * gr4646 = new TGraphErrors(NCent, CentX, y4646, 0, e4646);

	TGraphErrors * gr5656 = new TGraphErrors(NCent, CentX, y5656, 0, e5656);

	TGraphErrors * gr22 = new TGraphErrors(NCent, CentX, y22, 0, e22);
	TGraphErrors * gr33 = new TGraphErrors(NCent, CentX, y33, 0, e33);
	TGraphErrors * gr44 = new TGraphErrors(NCent, CentX, y44, 0, e44);
	TGraphErrors * gr55 = new TGraphErrors(NCent, CentX, y55, 0, e55);
	TGraphErrors * gr66 = new TGraphErrors(NCent, CentX, y66, 0, e66);

	TFile * fsave = new TFile(Form("%s/outGraph.root", ftxt[s1]), "recreate");

	h2323->Write("h2323");
	h2424->Write("h2424");
	h2525->Write("h2525");
	h2626->Write("h2626");

	h3434->Write("h3434");
	h3535->Write("h3535");
	h3636->Write("h3636");

	h4545->Write("h4545");
	h4646->Write("h4646");

	h5656->Write("h5656");

	h22->Write("h22");
	h33->Write("h33");
	h44->Write("h44");
	h55->Write("h55");
	h66->Write("h66");

	h2233->Write("h2233");
	h2244->Write("h2244");
	h2255->Write("h2255");
	h2266->Write("h2266");

	h3344->Write("h3344");
	h3355->Write("h3355");
	h3366->Write("h3366");

	h4455->Write("h4455");
	h4466->Write("h4466");

	h5566->Write("h5566");

	gr2323->Write("gr2323");
	gr2424->Write("gr2424");
	gr2525->Write("gr2525");
	gr2626->Write("gr2626");

	gr3434->Write("gr3434");
	gr3535->Write("gr3535");
	gr3636->Write("gr3636");

	gr4545->Write("gr4545");
	gr4646->Write("gr4646");

	gr5656->Write("gr5656");

	gr22->Write("gr22");
	gr33->Write("gr33");
	gr44->Write("gr44");
	gr55->Write("gr55");
	gr66->Write("gr66");
}
