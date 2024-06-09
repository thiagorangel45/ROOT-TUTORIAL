#include <TRandom3.h>

void main3()
{
    TFile *file = new TFile("test3.root", "RECREATE");
    TTree *tree = new TTree("tree", "A tree with branches A, B, and C");

    float a, b, c;

    tree->Branch("A", &a, "A/F");
    tree->Branch("B", &b, "B/F");
    tree->Branch("C", &c, "C/F");

    TRandom3 rand;

    for (int i = 0; i < 1000; ++i) {
        a = rand.Gaus(0, 1);  
        b = rand.Gaus(0, 1);
        c = rand.Gaus(0, 1);
        tree->Fill();
    }

    file->mkdir("dir1");
    file->mkdir("dir2");
    file->mkdir("dir3");

    file->cd("dir1");
    TH1F *hist1 = new TH1F("hist1", "", 100, -10, 10);
    hist1->FillRandom("gaus", 1e6);
    hist1->Write();

    file->cd("dir2");
    TH1F *hist2 = new TH1F("hist2", "", 100, -10, 10);
    hist2->FillRandom("gaus", 1e6);
    hist2->Write();

    file->cd("dir3");
    TH1F *hist3 = new TH1F("hist3", "", 100, -10, 10);
    hist3->FillRandom("gaus", 1e6);
    hist3->Write();

    file->cd("/");
    tree->Write();

    file->ls();
    file->Close();
}
