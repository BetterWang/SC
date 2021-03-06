#include "label.h"
#include "noff.h"
#include "util.h"


void plotDraw(int sMB = 12, int sHM = 11, int limit = 125, string tag = "")
{
	TFile * fMB = new TFile(Form("%s/outGraph.root", ftxt[sMB]));
	TFile * fHM = new TFile(Form("%s/outGraph.root", ftxt[sHM]));

	SetStyle();

	TGraphErrors * gr2323MB = (TGraphErrors*) fMB->Get("gr2323");
	TGraphErrors * gr2424MB = (TGraphErrors*) fMB->Get("gr2424");
	TGraphErrors * gr2525MB = (TGraphErrors*) fMB->Get("gr2525");
	TGraphErrors * gr2626MB = (TGraphErrors*) fMB->Get("gr2626");
	TGraphErrors * gr3434MB = (TGraphErrors*) fMB->Get("gr3434");
	TGraphErrors * gr3535MB = (TGraphErrors*) fMB->Get("gr3535");
	TGraphErrors * gr3636MB = (TGraphErrors*) fMB->Get("gr3636");
	TGraphErrors * gr4545MB = (TGraphErrors*) fMB->Get("gr4545");
	TGraphErrors * gr4646MB = (TGraphErrors*) fMB->Get("gr4646");
	TGraphErrors * gr5656MB = (TGraphErrors*) fMB->Get("gr5656");

	TGraphErrors * gr2323HM = (TGraphErrors*) fHM->Get("gr2323");
	TGraphErrors * gr2424HM = (TGraphErrors*) fHM->Get("gr2424");
	TGraphErrors * gr2525HM = (TGraphErrors*) fHM->Get("gr2525");
	TGraphErrors * gr2626HM = (TGraphErrors*) fHM->Get("gr2626");
	TGraphErrors * gr3434HM = (TGraphErrors*) fHM->Get("gr3434");
	TGraphErrors * gr3535HM = (TGraphErrors*) fHM->Get("gr3535");
	TGraphErrors * gr3636HM = (TGraphErrors*) fHM->Get("gr3636");
	TGraphErrors * gr4545HM = (TGraphErrors*) fHM->Get("gr4545");
	TGraphErrors * gr4646HM = (TGraphErrors*) fHM->Get("gr4646");
	TGraphErrors * gr5656HM = (TGraphErrors*) fHM->Get("gr5656");

	gr2323MB->SetMarkerStyle(kFullSquare);
	gr2424MB->SetMarkerStyle(kFullSquare);
	gr2525MB->SetMarkerStyle(kFullSquare);
	gr2626MB->SetMarkerStyle(kFullSquare);
	gr3434MB->SetMarkerStyle(kFullSquare);
	gr3535MB->SetMarkerStyle(kFullSquare);
	gr3636MB->SetMarkerStyle(kFullSquare);
	gr4545MB->SetMarkerStyle(kFullSquare);
	gr4646MB->SetMarkerStyle(kFullSquare);
	gr5656MB->SetMarkerStyle(kFullSquare);

	gr2323MB->SetMarkerSize(1.3);
	gr2424MB->SetMarkerSize(1.3);
	gr2525MB->SetMarkerSize(1.3);
	gr2626MB->SetMarkerSize(1.3);
	gr3434MB->SetMarkerSize(1.3);
	gr3535MB->SetMarkerSize(1.3);
	gr3636MB->SetMarkerSize(1.3);
	gr4545MB->SetMarkerSize(1.3);
	gr4646MB->SetMarkerSize(1.3);
	gr5656MB->SetMarkerSize(1.3);

	gr2323HM->SetMarkerStyle(kOpenSquare);
	gr2424HM->SetMarkerStyle(kOpenSquare);
	gr2525HM->SetMarkerStyle(kOpenSquare);
	gr2626HM->SetMarkerStyle(kOpenSquare);
	gr3434HM->SetMarkerStyle(kOpenSquare);
	gr3535HM->SetMarkerStyle(kOpenSquare);
	gr3636HM->SetMarkerStyle(kOpenSquare);
	gr4545HM->SetMarkerStyle(kOpenSquare);
	gr4646HM->SetMarkerStyle(kOpenSquare);
	gr5656HM->SetMarkerStyle(kOpenSquare);

	gr2323HM->SetMarkerSize(1.3);
	gr2424HM->SetMarkerSize(1.3);
	gr2525HM->SetMarkerSize(1.3);
	gr2626HM->SetMarkerSize(1.3);
	gr3434HM->SetMarkerSize(1.3);
	gr3535HM->SetMarkerSize(1.3);
	gr3636HM->SetMarkerSize(1.3);
	gr4545HM->SetMarkerSize(1.3);
	gr4646HM->SetMarkerSize(1.3);
	gr5656HM->SetMarkerSize(1.3);

	trimGraph(gr2323MB , limit);
	trimGraph(gr2424MB , limit);
	trimGraph(gr2525MB , limit);
	trimGraph(gr2626MB , limit);
	trimGraph(gr3434MB , limit);
	trimGraph(gr3535MB , limit);
	trimGraph(gr3636MB , limit);
	trimGraph(gr4545MB , limit);
	trimGraph(gr4646MB , limit);
	trimGraph(gr5656MB , limit);

	trimGraph(gr2323HM , -limit);
	trimGraph(gr2424HM , -limit);
	trimGraph(gr2525HM , -limit);
	trimGraph(gr2626HM , -limit);
	trimGraph(gr3434HM , -limit);
	trimGraph(gr3535HM , -limit);
	trimGraph(gr3636HM , -limit);
	trimGraph(gr4545HM , -limit);
	trimGraph(gr4646HM , -limit);
	trimGraph(gr5656HM , -limit);

	TCanvas * c = new TCanvas("c", "c", 500, 500);
	TH2D * hframe = new TH2D("hframe", "", 1, 1, 450, 1, -4.5e-6, 8.5e-6);
	InitHist(hframe, "N_{trk}^{offline}", "SC(n,m)");
	hframe->Draw();

	TLine * l0 = new TLine(1, 0, 450, 0);
	l0->Draw("same");

	gr2323MB->SetMarkerColor(kBlue);
	gr2323MB->SetLineColor(kBlue);
	gr2323HM->SetMarkerColor(kBlue);
	gr2323HM->SetLineColor(kBlue);

	gr2424MB->SetMarkerColor(kRed);
	gr2424MB->SetLineColor(kRed);
	gr2424HM->SetMarkerColor(kRed);
	gr2424HM->SetLineColor(kRed);

	gr2323MB->Draw("psame");
	gr2323HM->Draw("psame");

	gr2424MB->Draw("psame");
	gr2424HM->Draw("psame");

	TLegend *leg = new TLegend(0.4, 0.67, 0.6, 0.93);
	leg->AddEntry(gr2424MB, "SC(2,4) MB", "p");
	leg->AddEntry(gr2424HM, "SC(2,4) HM", "p");
	leg->AddEntry(gr2323MB, "SC(2,3) MB", "p");
	leg->AddEntry(gr2323HM, "SC(2,3) HM", "p");

	leg->Draw();



	TCanvas * c1 = new TCanvas("c1", "c1", 500, 500);

	TH2D * hframe1 = new TH2D("hframe1", "", 1, 1, 450, 1, -.4e-6, 1.4e-6);
	InitHist(hframe1, "N_{trk}^{offline}", "SC(n,m)");
	hframe1->Draw();

	l0->Draw("same");

	gr3434MB->SetMarkerColor(kRed);
	gr3434MB->SetLineColor(kRed);
	gr3434HM->SetMarkerColor(kRed);
	gr3434HM->SetLineColor(kRed);

	gr3535MB->SetMarkerColor(kBlack);
	gr3535HM->SetMarkerColor(kBlack);
	gr3535MB->SetLineColor(kBlack);
	gr3535HM->SetLineColor(kBlack);

	gr3636MB->SetMarkerColor(kBlue);
	gr3636MB->SetLineColor(kBlue);
	gr3636HM->SetMarkerColor(kBlue);
	gr3636HM->SetLineColor(kBlue);

	gr3434MB->Draw("psame");
	gr3434HM->Draw("psame");
//	gr3535MB->Draw("psame");
//	gr3535HM->Draw("psame");
	gr3636MB->Draw("psame");
	gr3636HM->Draw("psame");

	TLegend *leg3 = new TLegend(0.4, 0.67, 0.6, 0.93);
	leg3->AddEntry(gr3434MB, "SC(3,4) MB", "p");
	leg3->AddEntry(gr3434HM, "SC(3,4) HM", "p");
	leg3->AddEntry(gr3636MB, "SC(3,6) MB", "p");
	leg3->AddEntry(gr3636HM, "SC(3,6) HM", "p");

	leg3->Draw();

	////////////////////////////
	TCanvas * c5 = new TCanvas("c5", "c5", 500, 500);

	TH2D * hframe5 = new TH2D("hframe5", "", 1, 1, 450, 1, -.4e-6, 1.4e-6);
	InitHist(hframe5, "N_{trk}^{offline}", "SC(n,m)");
	hframe5->Draw();

	l0->Draw("same");

	gr4545MB->SetMarkerColor(kRed);
	gr4545HM->SetMarkerColor(kRed);
	gr4545MB->SetLineColor(kRed);
	gr4545HM->SetLineColor(kRed);

	gr4646MB->SetMarkerColor(kBlue);
	gr4646HM->SetMarkerColor(kBlue);
	gr4646MB->SetLineColor(kBlue);
	gr4646HM->SetLineColor(kBlue);

	gr4545MB->Draw("psame");
	gr4545HM->Draw("psame");
	gr4545MB->Draw("psame");
	gr4545HM->Draw("psame");

	gr4646MB->Draw("psame");
	gr4646HM->Draw("psame");
	gr4646MB->Draw("psame");
	gr4646HM->Draw("psame");

	TLegend *leg5 = new TLegend(0.4, 0.67, 0.6, 0.93);
	leg5->AddEntry(gr4545MB, "SC(4,5) MB", "p");
	leg5->AddEntry(gr4545HM, "SC(4,5) HM", "p");
	leg5->AddEntry(gr4646MB, "SC(4,6) MB", "p");
	leg5->AddEntry(gr4646HM, "SC(4,6) HM", "p");

	leg5->Draw();



	TGraphErrors * gr2323 = mergeGraph(gr2323MB, gr2323HM);
	TGraphErrors * gr2424 = mergeGraph(gr2424MB, gr2424HM);
	TGraphErrors * gr2525 = mergeGraph(gr2525MB, gr2525HM);
	TGraphErrors * gr2626 = mergeGraph(gr2626MB, gr2626HM);

	TGraphErrors * gr3434 = mergeGraph(gr3434MB, gr3434HM);
	TGraphErrors * gr3535 = mergeGraph(gr3535MB, gr3535HM);
	TGraphErrors * gr3636 = mergeGraph(gr3636MB, gr3636HM);

	TGraphErrors * gr4545 = mergeGraph(gr4545MB, gr4545HM);
	TGraphErrors * gr4646 = mergeGraph(gr4646MB, gr4646HM);

	TGraphErrors * gr5656 = mergeGraph(gr5656MB, gr5656HM);


	c->SaveAs("SC2324.pdf");
	c1->SaveAs("SC3436.pdf");
	c5->SaveAs("SC4546.pdf");

	TFile * fsave = new TFile(Form("pPb8TeV%s.root", tag.c_str()), "recreate");
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

}
