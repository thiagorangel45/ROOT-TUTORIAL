void tut3(){

    TH1F *hist = new TH1F("h1", "", 10, 0, 10);
    TCanvas *c1 = new TCanvas();

    fstream file;
    file.open("data.txt", ios::in);

    double value;

    while (1)
    {
        file >> value;
        hist->Fill(value);
        if (file.eof()) break;
    }

    hist->GetXaxis()->SetTitle("eixo x");
    hist->GetYaxis()->SetTitle("eixo y");

    hist->Draw();
    c1->Draw();

}