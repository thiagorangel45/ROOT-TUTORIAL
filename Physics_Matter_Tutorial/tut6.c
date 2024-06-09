void tut6() {
    TH1F *hist = new TH1F("hist", "", 100, 0, 10);
    TCanvas *c1 = new TCanvas();
    TRandom2 *rand = new TRandom2(3);

    std::fstream file;
    file.open("data3.txt", std::ios::out);

    for (int i = 0; i < 1000; i++) {
        double r = rand->Gaus(5, 1);
        file << r << std::endl;
    }
    file.close();

    file.open("data3.txt", std::ios::in);
    double value;

    while (file >> value) {
        hist->Fill(value);
    }

    file.close();

    hist->GetXaxis()->SetTitle("Value");
    hist->GetYaxis()->SetTitle("Frequency");

    hist->Draw();
    c1->Draw();
}
