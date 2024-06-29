void example16()
{
    TFile* f = new TFile("simple.root");
    TTree* t;
    f->GetObject("t",t);

    TCanvas *c2 = new TCanvas("c2", "2D Plot", 500, 500);
    t->Draw("x:y>>hxy(2000,0,1500,2000,0,12000)", "", "colz");

    t->Draw("x:y>>hxy(2000,0,1500,2000,0,12000)", "mycut",  "colz");
    t->Draw("x:y>>hxy(2000,0,1500,2000,0,12000)", "!mycut", "colz");

    c1.cd(1); t->Draw("money", "mycut", "");
    c1.cd(2); t->Draw("money", "", "");

    TFile g("cut.root","recreate");
    mycut->Write();
    TCanvas* ctest = new TCanvas("ctest", "just for test", 500, 500);
    mycut->Draw(); 
    mycut->Print();  
    f->Close();

}