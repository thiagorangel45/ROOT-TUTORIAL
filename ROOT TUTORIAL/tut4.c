void tut4()
{
    TCanvas *c1 = new TCanvas();
    TGraph *gr = new TGraph();

    gr->SetMarkerStyle(kFullCircle);
    gr->SetLineWidth(2);
    gr->SetLineColor(kRed);

    gr->GetXaxis()->SetTitle("eixo x");
    gr->GetYaxis()->SetTitle("eixo y");

    fstream file;
    file.open("data2.txt", ios::in);

    
    while (1)
    {
        double x, y;

        file >> x >> y;
        gr->SetPoint(gr->GetN(), x, y);
        if (file.eof()) break;
    }
    file.close();

    gr->Draw();
    c1->Draw();

}