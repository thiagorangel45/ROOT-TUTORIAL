// criando diretorios dentro do arquivo e preenchendo com histogramas

void main2()
{
    TFile *file1 = new TFile("test1.root", "RECREATE");
    TFile *file2 = new TFile("test2.root", "RECREATE");

    file1->mkdir("dir1");
    file2->mkdir("dir1");

    file1->cd("dir1");
    TH1F *hist = new TH1F("hist", "", 100, -10, 10);
    hist->FillRandom("gaus", 1e6);
    hist->Write();
    file1->ls();

    file2->cd("dir1");
    TH1F *hist1 = new TH1F("hist1", "", 100, -10, 10);
    hist1->FillRandom("landau", 1e6);
    hist1->Write();
    file2->ls();

    file1->Close();
    file2->Close();
}
