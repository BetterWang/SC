#include "label.h"
#include "noff.h"


void bGetE(int s1 = 1, int s3 = 10)
{
	cout << " s1 = " << s1 << " s3 = " << s3 << endl;

	int NCent = NCentAA5TeV4;
	auto CentNoffCut = CentCutAA5TeV;

	double Q2c[50][5][20] = {};
	double Q4c[50][5][20] = {};
	double Q6c[50][5][20] = {};
	double Q8c[50][5][20] = {};

	for ( int s2 = 0; s2 <= s3; s2++ ) {
		TFile * f = new TFile( Form("%s/outQc_%i_%i.root", ftxt[s1], s2, s3) );

		for ( int n = 2; n < 5; n++ ) {
			TH1D * hQc2 = (TH1D*) f->Get(Form("hQc2%i", n));
			TH1D * hQc4 = (TH1D*) f->Get(Form("hQc4%i", n));
			TH1D * hQc6 = (TH1D*) f->Get(Form("hQc6%i", n));
			TH1D * hQc8 = (TH1D*) f->Get(Form("hQc8%i", n));

			for ( int c = 0; c < NCent; c++ ) {
				Q2c[s2][n][c] = hQc2->GetBinContent(c+1);
				Q4c[s2][n][c] = hQc4->GetBinContent(c+1);
				Q6c[s2][n][c] = hQc6->GetBinContent(c+1);
				Q8c[s2][n][c] = hQc8->GetBinContent(c+1);
			}
		}
		f->Close();
	}

	double eQ2c[5][20] = {};
	double eQ4c[5][20] = {};
	double eQ6c[5][20] = {};
	double eQ8c[5][20] = {};

	double V2c[5][20] = {};
	double V4c[5][20] = {};
	double V6c[5][20] = {};
	double V8c[5][20] = {};

	double eV2c[5][20] = {};
	double eV4c[5][20] = {};
	double eV6c[5][20] = {};
	double eV8c[5][20] = {};

	for ( int n = 2; n < 5; n++ ) {
		for ( int c = 0; c < NCent; c++ ) {
			double sumC2 = 0;
			double sumC4 = 0;
			double sumC6 = 0;
			double sumC8 = 0;
			for ( int fn = 0; fn < s3; fn++ ) {
				sumC2 += (Q2c[fn][n][c] - Q2c[s3][n][c]) * (Q2c[fn][n][c] - Q2c[s3][n][c]);
				sumC4 += (Q4c[fn][n][c] - Q4c[s3][n][c]) * (Q4c[fn][n][c] - Q4c[s3][n][c]);
				sumC6 += (Q6c[fn][n][c] - Q6c[s3][n][c]) * (Q6c[fn][n][c] - Q6c[s3][n][c]);
				sumC8 += (Q8c[fn][n][c] - Q8c[s3][n][c]) * (Q8c[fn][n][c] - Q8c[s3][n][c]);
			}
			eQ2c[n][c] = sqrt( sumC2 ) /s3;
			eQ4c[n][c] = sqrt( sumC4 ) /s3;
			eQ6c[n][c] = sqrt( sumC6 ) /s3;
			eQ8c[n][c] = sqrt( sumC8 ) /s3;

			double C = Q2c[s3][n][c];
			double V = 0;
			if ( C > 0 ) V = pow( C, 1./2);
			else V = - pow( -C, 1./2);
			eV2c[n][c] = fabs( eQ2c[n][c] * V / C / 2. );
			V2c[n][c] = V;

			C = Q4c[s3][n][c];
			V = 0;
			if ( C > 0 ) V = - pow( C, 1./4);
			else V = pow( -C, 1./4);
			eV4c[n][c] = fabs( eQ4c[n][c] * V / C / 4. );
			V4c[n][c] = V;

			C = Q6c[s3][n][c];
			V = 0;
			if ( C > 0 ) V = pow( C/4., 1./6);
			else V = - pow( -C/4., 1./6);
			eV6c[n][c] = fabs( eQ6c[n][c] * V / C / 6. );
			V6c[n][c] = V;

			C = Q8c[s3][n][c];
			V = 0;
			if ( C > 0 ) V = - pow( C/33., 1./8);
			else V = pow( -C/33., 1./8);
			eV8c[n][c] = fabs( eQ8c[n][c] * V / C / 8. );
			V8c[n][c] = V;
		}
	}

	TFile * fsave = new TFile( Form("%s/outputE.root", ftxt[s1]), "recreate" );
	TH1D * hCn2[5] = {};
	TH1D * hVn2[5] = {};
	TH1D * hCn4[5] = {};
	TH1D * hVn4[5] = {};
	TH1D * hCn6[5] = {};
	TH1D * hVn6[5] = {};
	TH1D * hCn8[5] = {};
	TH1D * hVn8[5] = {};
	for ( int n = 2; n < 5; n++ ) {
		hCn2[n] = new TH1D( Form("hC2n%i", n), "", 20, 0, 20);
		hCn4[n] = new TH1D( Form("hC4n%i", n), "", 20, 0, 20);
		hCn6[n] = new TH1D( Form("hC6n%i", n), "", 20, 0, 20);
		hCn8[n] = new TH1D( Form("hC8n%i", n), "", 20, 0, 20);

		hVn2[n] = new TH1D( Form("hV2n%i", n), "", 20, 0, 20);
		hVn4[n] = new TH1D( Form("hV4n%i", n), "", 20, 0, 20);
		hVn6[n] = new TH1D( Form("hV6n%i", n), "", 20, 0, 20);
		hVn8[n] = new TH1D( Form("hV8n%i", n), "", 20, 0, 20);

		for ( int c = 0; c < NCent; c++ ) {
			hCn2[n]->SetBinContent(c+1, Q2c[s3][n][c]);
			hCn4[n]->SetBinContent(c+1, Q4c[s3][n][c]);
			hCn6[n]->SetBinContent(c+1, Q6c[s3][n][c]);
			hCn8[n]->SetBinContent(c+1, Q8c[s3][n][c]);

			hCn2[n]->SetBinError(c+1, eQ2c[n][c]);
			hCn4[n]->SetBinError(c+1, eQ4c[n][c]);
			hCn6[n]->SetBinError(c+1, eQ6c[n][c]);
			hCn8[n]->SetBinError(c+1, eQ8c[n][c]);

			hVn2[n]->SetBinContent(c+1, V2c[n][c]);
			hVn4[n]->SetBinContent(c+1, V4c[n][c]);
			hVn6[n]->SetBinContent(c+1, V6c[n][c]);
			hVn8[n]->SetBinContent(c+1, V8c[n][c]);

			hVn2[n]->SetBinError(c+1, eV2c[n][c]);
			hVn4[n]->SetBinError(c+1, eV4c[n][c]);
			hVn6[n]->SetBinError(c+1, eV6c[n][c]);
			hVn8[n]->SetBinError(c+1, eV8c[n][c]);
		}

		hCn2[n]->Write();
		hCn4[n]->Write();
		hCn6[n]->Write();
		hCn8[n]->Write();
		hVn2[n]->Write();
		hVn4[n]->Write();
		hVn6[n]->Write();
		hVn8[n]->Write();
	}
	fsave->Close();
}
