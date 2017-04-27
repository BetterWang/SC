#include "label.h"
#include "noff.h"
#include "util.h"

void plotComp(string s1, string s2, string s3, string lt1, string lt2, string lt3)
{
	TFile * f1 = new TFile(s1.c_str());
	TFile * f2 = new TFile(s2.c_str());
	TFile * f3 = new TFile(s3.c_str());

	SetStyle();

	TGraphErrors * gr2323_1 = (TGraphErrors*) f1->Get("gr2323");
	TGraphErrors * gr2424_1 = (TGraphErrors*) f1->Get("gr2424");
	TGraphErrors * gr2525_1 = (TGraphErrors*) f1->Get("gr2525");
	TGraphErrors * gr2626_1 = (TGraphErrors*) f1->Get("gr2626");

	TGraphErrors * gr3434_1 = (TGraphErrors*) f1->Get("gr3434");
	TGraphErrors * gr3535_1 = (TGraphErrors*) f1->Get("gr3535");
	TGraphErrors * gr3636_1 = (TGraphErrors*) f1->Get("gr3636");

	TGraphErrors * gr4545_1 = (TGraphErrors*) f1->Get("gr4545");
	TGraphErrors * gr4646_1 = (TGraphErrors*) f1->Get("gr4646");

	TGraphErrors * gr5656_1 = (TGraphErrors*) f1->Get("gr5656");


	TGraphErrors * gr2323_2 = (TGraphErrors*) f2->Get("gr2323");
	TGraphErrors * gr2424_2 = (TGraphErrors*) f2->Get("gr2424");
	TGraphErrors * gr2525_2 = (TGraphErrors*) f2->Get("gr2525");
	TGraphErrors * gr2626_2 = (TGraphErrors*) f2->Get("gr2626");

	TGraphErrors * gr3434_2 = (TGraphErrors*) f2->Get("gr3434");
	TGraphErrors * gr3535_2 = (TGraphErrors*) f2->Get("gr3535");
	TGraphErrors * gr3636_2 = (TGraphErrors*) f2->Get("gr3636");

	TGraphErrors * gr4545_2 = (TGraphErrors*) f2->Get("gr4545");
	TGraphErrors * gr4646_2 = (TGraphErrors*) f2->Get("gr4646");

	TGraphErrors * gr5656_2 = (TGraphErrors*) f2->Get("gr5656");

	TGraphErrors * gr2323_3 = (TGraphErrors*) f3->Get("gr2323");
	TGraphErrors * gr2424_3 = (TGraphErrors*) f3->Get("gr2424");
	TGraphErrors * gr2525_3 = (TGraphErrors*) f3->Get("gr2525");
	TGraphErrors * gr2626_3 = (TGraphErrors*) f3->Get("gr2626");

	TGraphErrors * gr3434_3 = (TGraphErrors*) f3->Get("gr3434");
	TGraphErrors * gr3535_3 = (TGraphErrors*) f3->Get("gr3535");
	TGraphErrors * gr3636_3 = (TGraphErrors*) f3->Get("gr3636");

	TGraphErrors * gr4545_3 = (TGraphErrors*) f3->Get("gr4545");
	TGraphErrors * gr4646_3 = (TGraphErrors*) f3->Get("gr4646");

	TGraphErrors * gr5656_3 = (TGraphErrors*) f3->Get("gr5656");



	//////////////
	TCanvas * c23 = new TCanvas("c23", "c23", 500, 500);
	TH2D * hframe23 = new TH2D("hframe23", "", 1, 1, 450, 1, -4.5e-6, 8.5e-6);
	InitHist(hframe23, "N_{trk}^{offline}", "SC(2,3)");
	hframe23->Draw();

	TLine * l0 = new TLine(1, 0, 450, 0);
	l0->Draw("same");

	gr2323_1->SetMarkerColor(kBlack);
	gr2323_2->SetMarkerColor(kBlue);
	gr2323_3->SetMarkerColor(kRed);

	gr2323_1->SetMarkerStyle(kFullSquare);
	gr2323_2->SetMarkerStyle(kOpenCircle);
	gr2323_3->SetMarkerStyle(kOpenCircle);

	gr2323_1->Draw("psame");
	gr2323_2->Draw("psame");
	gr2323_3->Draw("psame");

	TLegend *leg23 = new TLegend(0.4, 0.67, 0.6, 0.93);
	leg23->AddEntry(gr2323_1, lt1.c_str(), "p");
	leg23->AddEntry(gr2323_2, lt2.c_str(), "p");
	leg23->AddEntry(gr2323_3, lt3.c_str(), "p");

	leg23->Draw();

	//////////////
	TCanvas * r23 = new TCanvas("r23", "r23", 500, 500);
	TH2D * rframe23 = new TH2D("rframe23", "", 1, 1, 450, 1, -5, 5);
	InitHist(rframe23, "N_{trk}^{offline}", "SC(2,3) Ratio");
	rframe23->Draw();

	TGraphErrors* gr2323_21 = ratioGraph(gr2323_1, gr2323_2);
	TGraphErrors* gr2323_31 = ratioGraph(gr2323_1, gr2323_3);

	gr2323_21->SetMarkerStyle(kOpenCircle);
	gr2323_31->SetMarkerStyle(kOpenCircle);

	gr2323_21->SetMarkerColor(kBlue);
	gr2323_31->SetMarkerColor(kRed);

	gr2323_21->Draw("psame");
	gr2323_31->Draw("psame");

	TLegend *leg23r = new TLegend(0.4, 0.67, 0.6, 0.93);
	leg23r->AddEntry(gr2323_21, lt2.c_str(), "p");
	leg23r->AddEntry(gr2323_31, lt3.c_str(), "p");

//	leg23r->Draw();

	//////////////
	TCanvas * c24 = new TCanvas("c24", "c24", 500, 500);
	TH2D * hframe24 = new TH2D("hframe24", "", 1, 1, 450, 1, -4.5e-6, 8.5e-6);
	InitHist(hframe24, "N_{trk}^{offline}", "SC(2,4)");
	hframe24->Draw();

	l0->Draw("same");

	gr2424_1->SetMarkerColor(kBlack);
	gr2424_2->SetMarkerColor(kBlue);
	gr2424_3->SetMarkerColor(kRed);

	gr2424_1->SetMarkerStyle(kFullSquare);
	gr2424_2->SetMarkerStyle(kOpenCircle);
	gr2424_3->SetMarkerStyle(kOpenCircle);

	gr2424_1->Draw("psame");
	gr2424_2->Draw("psame");
	gr2424_3->Draw("psame");

	TLegend *leg24 = new TLegend(0.4, 0.67, 0.6, 0.93);
	leg24->AddEntry(gr2424_1, lt1.c_str(), "p");
	leg24->AddEntry(gr2424_2, lt2.c_str(), "p");
	leg24->AddEntry(gr2424_3, lt3.c_str(), "p");

	leg24->Draw();
	//
	//////////////
	TCanvas * r24 = new TCanvas("r24", "r24", 500, 500);
	TH2D * rframe24 = new TH2D("rframe24", "", 1, 1, 450, 1, -0, 2);
	InitHist(rframe24, "N_{trk}^{offline}", "SC(2,4) Ratio");
	rframe24->Draw();

	TGraphErrors* gr2424_21 = ratioGraph(gr2424_1, gr2424_2);
	TGraphErrors* gr2424_31 = ratioGraph(gr2424_1, gr2424_3);

	gr2424_21->SetMarkerStyle(kOpenCircle);
	gr2424_31->SetMarkerStyle(kOpenCircle);

	gr2424_21->SetMarkerColor(kBlue);
	gr2424_31->SetMarkerColor(kRed);

	gr2424_21->Draw("psame");
	gr2424_31->Draw("psame");

	TLegend *leg24r = new TLegend(0.4, 0.67, 0.6, 0.93);
	leg24r->AddEntry(gr2424_21, lt2.c_str(), "p");
	leg24r->AddEntry(gr2424_31, lt3.c_str(), "p");

//	leg23r->Draw();

	c23->SaveAs("sys23.pdf");
	c24->SaveAs("sys24.pdf");
	r23->SaveAs("sysR23.pdf");
	r24->SaveAs("sysR24.pdf");
}
