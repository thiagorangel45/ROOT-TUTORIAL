void tut14()
{
    TFile *file = new TFile("output.root", "RECREATE");
    TH1F *hist = new TH1F("hist", "", 100, 0, 100);
    TCanvas *c1 = new TCanvas();
    hist->Fill(10);
    hist->Fill(20);

    file->Write();
    file->Close();
}