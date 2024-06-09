void tut11() {
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

    hist->GetXaxis()->SetTitleSize(0.05);
    hist->GetYaxis()->SetTitleSize(0.05);
    hist->GetXaxis()->SetLabelSize(0.05);
    hist->GetYaxis()->SetLabelSize(0.05);

    hist->SetFillColor(kYellow - 9);
    hist->SetStats(0);

    c1->SetTickx();
    c1->SetTicky();
    c1->SetGridy();
    c1->SetGridx();

    TF1 *fit = new TF1("fit", "gaus", 0, 10);
    fit->SetParameter(0, 40);
    fit->SetParameter(1, 5);
    fit->SetParameter(2, 1);

    fit->SetLineWidth(3);
    fit->SetLineStyle(2);
    fit->SetLineColor(kBlue);

    hist->Draw();
    hist->Fit("fit", "R");

    TLegend *leg = new TLegend(0.7, 0.7, 0.9, 0.9);
    leg->SetBorderSize(0);
    leg->AddEntry(hist, "data measured", "f");
    leg->AddEntry(fit, "Fit", "l");
    leg->Draw("SAME");

    TLine *line = new TLine(0, 20, 10, 20);
    line->SetLineWidth(2);
    line->SetLineColor(kBlue);
    line->Draw();


    double x0 = 6.3;
    int bin = hist->FindBin(x0);
    double y0 = hist->GetBinContent(bin);

    TArrow *arr = new TArrow(10, 30, x0, y0);
    arr->Draw();

    TLatex *latex = new TLatex(10, 30, "important point");
    latex->Draw();

    double mean = fit->GetParameter(1);
    double sigma = fit->GetParameter(2);

    cout << mean/sigma << endl;

    c1->Draw();
}
