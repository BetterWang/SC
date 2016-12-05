void SetStyle() {

  TH1::SetDefaultSumw2();
  gROOT->SetStyle("Plain");

  TStyle *QWStyle = new TStyle("MIT-Style","The Perfect Style for Plots ;-)");
  gStyle = QWStyle;

//  gStyle->SetTitleSize(0.08,"t");//  gStyle->SetTitleX(0.8);
//  gStyle->SetTitleW(0.3);

  // Canvas

  QWStyle->SetCanvasColor     (0);
  QWStyle->SetCanvasBorderSize(10);
  QWStyle->SetCanvasBorderMode(0);

  QWStyle->SetCanvasDefH      (500);
  QWStyle->SetCanvasDefW      (550);
  //  QWStyle->SetCanvasDefX      (100);
  //  QWStyle->SetCanvasDefY      (100);

  // Pads

  QWStyle->SetPadColor       (0);
  //  QWStyle->SetPadBorderSize  (10);
  QWStyle->SetPadBorderMode  (0);
  QWStyle->SetPadBottomMargin(0.16);
  QWStyle->SetPadTopMargin   (0.06);
  QWStyle->SetPadLeftMargin  (0.15);
  QWStyle->SetPadRightMargin (0.04);
  QWStyle->SetPadGridX       (0);
  QWStyle->SetPadGridY       (0);
  QWStyle->SetPadTickX       (1);
  QWStyle->SetPadTickY       (1);

  // Frames

  QWStyle->SetFrameFillStyle ( 0);
  QWStyle->SetFrameFillColor ( 0);
  QWStyle->SetFrameLineColor ( 1);
  QWStyle->SetFrameLineStyle ( 0);
  QWStyle->SetFrameLineWidth ( 1);
  //  QWStyle->SetFrameBorderSize(10);
  QWStyle->SetFrameBorderMode( 0);

  // Histograms

  QWStyle->SetHistLineColor(1);
  QWStyle->SetHistLineStyle(0);
//  QWStyle->SetHistLineWidth(3);
  QWStyle->SetNdivisions(505,"X");
  QWStyle->SetNdivisions(505,"Y");
  QWStyle->SetNdivisions(505,"Z");

  // Functions

  QWStyle->SetFuncColor(1);
  QWStyle->SetFuncStyle(0);
  QWStyle->SetFuncWidth(2);

  // Various

//  QWStyle->SetMarkerStyle(20);
//  QWStyle->SetMarkerColor(kBlack);
  QWStyle->SetMarkerSize (2);

//  QWStyle->SetTitleSize  (0.1,"t");

  QWStyle->SetTitleSize  (0.070,"X");
  QWStyle->SetTitleOffset(1.0,"X");
  QWStyle->SetTitleFont  (42,"X");
  QWStyle->SetLabelOffset(0.005,"X");
  QWStyle->SetLabelSize  (0.070,"X");
  QWStyle->SetLabelFont  (42   ,"X");

  QWStyle->SetTitleSize  (0.070,"Y");
  QWStyle->SetTitleOffset(1.0,"Y");
  QWStyle->SetTitleFont  (42,"Y");
  QWStyle->SetLabelOffset(0.005,"Y");
  QWStyle->SetLabelSize  (0.070,"Y");
  QWStyle->SetLabelFont  (42   ,"Y");

  QWStyle->SetTitleSize  (0.06,"Z");
  QWStyle->SetTitleOffset(1.640,"Z");
  QWStyle->SetTitleFont  (42,"Z");
  QWStyle->SetLabelOffset(0.005,"Z");
  QWStyle->SetLabelSize  (0.070,"Z");
  QWStyle->SetLabelFont  (42   ,"Z");

  QWStyle->SetStripDecimals(kFALSE);
  QWStyle->SetTitleBorderSize(0);
  QWStyle->SetTitleFillColor(0);
  //  QWStyle->SetTitleAlign(6);

  QWStyle->SetTextSize   (20);
  QWStyle->SetTextFont   (43);

  QWStyle->SetStatFont   (42);
  QWStyle->SetOptStat    (0);

  QWStyle->SetLegendBorderSize(0);
  QWStyle->SetLegendFillColor(kWhite);
//  QWStyle->SetEndErrorSize(0);
//  QWStyle->SetErrorX(0);

  QWStyle->SetPalette    (1,0);
  return;
}

void InitHist(TH1        *hist,
	      const char *xtit,
	      const char *ytit  = "Number of Entries",
	      EColor      color = kBlack)
{
  hist->SetXTitle(xtit);
  hist->SetYTitle(ytit);
  hist->SetLineColor(color);
  hist->SetTitleSize  (0.06,"X");
  hist->SetTitleSize  (0.06,"Y");
  hist->SetTitleSize  (0.06,"Z");
  hist->SetTitleOffset(1.10,"Y");
  hist->SetTitleOffset(1.10,"X");
  hist->SetTitleOffset(1.10,"Z");
  hist->SetLabelOffset(0.008,"Y");
  hist->SetLabelSize  (0.050,"Y");
  hist->SetLabelFont  (42   ,"Y");
  hist->SetMarkerStyle(20);
  hist->SetMarkerColor(color);
  hist->SetMarkerSize (0.6);
  // Strangely enough this cannot be set anywhere else??
  hist->GetXaxis()->SetLabelSize(0.05);
  hist->GetYaxis()->SetTitleFont(42);
  hist->GetXaxis()->CenterTitle();
  hist->GetYaxis()->CenterTitle();
  hist->SetTitle("");  
  return;
}


void trimGraph(TGraphErrors* gr, int limit)
{
	for ( int i = 0; i < gr->GetN(); i++ ) {
		if ( limit < 0 ) {
			if ( gr->GetX()[i] < fabs(limit) ) {
				gr->RemovePoint(i);
				i--;
			}
		}
		if ( limit > 0 ) {
			if ( gr->GetX()[i] > limit ) {
				gr->RemovePoint(i);
				i--;
			}
		}
	}
}
