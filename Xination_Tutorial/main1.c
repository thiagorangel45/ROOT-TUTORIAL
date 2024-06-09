// criando arquivo e preechendo com histogramas

void main1()
{
    TFile *file = new TFile("test.root", "RECREATE");

    TH1F *h0 = new TH1F("h0", "", 100, -10, 10);
    TH1F *h1 = new TH1F("h1", "", 100, -10, 10);

    h0->FillRandom("gaus", 1e4);
    h1->FillRandom("landau", 1e4);

    h0->Write();
    h1->Write();

    file->Close();
}