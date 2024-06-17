void example13()
{

    TFile *file = new TFile("simple.root");
    TTree* t;
    file->GetObject("t", t);

    TCanvas *c1 = new TCanvas("c1", "", 800, 300);
    c1->Divide(2,1);

    c1->cd(1);
    t->Draw("log10(money)");

    c1->cd(2);
    t->Draw("sqrt(money)");

}