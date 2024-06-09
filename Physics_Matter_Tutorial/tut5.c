void tut5() {
    
    TRandom2 *rand = new TRandom2();
    TH1F *hist = new TH1F("hist", "", 100, 0, 100);
    TCanvas *c1 = new TCanvas();

    for (int i = 0; i < 1000; i++) {
        double r = rand->Rndm() * 100;
        hist->Fill(r);
        std::cout << r << std::endl;
    }

    hist->GetYaxis()->SetRangeUser(0, 200);
    hist->Draw();
    c1->Draw();

}