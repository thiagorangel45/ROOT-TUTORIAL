void tut23()
{
    THStack *hstack = new THStack();

    TH1F *hist = new TH1F("hist", "histogram", 100, -10, 10);
    TH1F *hist2 = new TH1F("hist2", "histogram 2", 100, -10, 10);

    hstack->Add(hist);
    hstack->Add(hist2);

    hist->FillRandom("gaus", 1e5);
    hist2->FillRandom("gaus", 1e4);

    TCanvas *c1 = new TCanvas();
    hist->Draw();
    hist2->Draw("SAME");

    TCanvas *c2 = new TCanvas();
    hstack->Draw("nostack");
}