void example14()
{
    TFile *file = new TFile("simple.root");
    TTree* t;
    file->GetObject("t", t);

    TCanvas *c1 = new TCanvas("c1", "", 800, 300);
    c1->Divide(2,1);

    c1->cd(1); t->Draw("money", "money > 1000 && money < 2000 ");
    c1->cd(2); t->Draw("money", "money < 1000 || money > 2000 ");
}