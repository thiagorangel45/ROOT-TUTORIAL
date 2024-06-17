void example15() {

    TFile *file = new TFile("simple.root");
    TTree* t;
    file->GetObject("t", t);

    TCanvas *c1 = new TCanvas("c1", "", 800, 300);
    c1->Divide(2, 1);

    TCut cut1 = "money < 1000";
    TCut cut2 = "money > 2000";

    c1->cd(1);
    t->Draw("money");

    c1->cd(2);
    t->Draw("money", cut1 || cut2);

    TH1F *h1 = new TH1F("h1", "Money Distribution;Money;Entries", 2000, 0, 4000);
    TH1F *h2 = new TH1F("h2", "Money Distribution with Cuts;Money;Entries", 2000, 0, 4000);

    t->Draw("money>>h1", "", "goff");
    t->Draw("money>>h2", cut1 || cut2, "goff");

    c1->cd(1);
    h1->Draw();
    c1->cd(2);
    h2->Draw();
}
