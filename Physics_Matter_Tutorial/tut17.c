void tut17()
{
    TCanvas *c1 = new TCanvas("c1", "Canvas", 800, 600);
    TH2F *hist = new TH2F("hist", "hist 2D", 100, -5, 5, 100, -5, 5);
    hist->SetStats(0);

    TRandom *rand = new TRandom(10);

    for (int i = 0; i < 1e6; i++)
    {
        double x = rand->Gaus();
        double y = rand->Gaus();
        hist->Fill(x, y);
    }

    hist->Draw();
    c1->Draw();
}
