void tut1()

{
    TCanvas *c1 = new TCanvas();
    TH1F *hist = new TH1F("hist", "", 100, 0, 100);

    hist->GetXaxis()->SetTitle("eixo x");
    hist->GetYaxis()->SetTitle("eixo y");

    hist->Fill(10);
    hist->Fill(90);

    hist->Draw();
    c1->Draw();

}