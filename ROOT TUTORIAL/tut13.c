void tut13()
{
    TCanvas *c1 = new TCanvas();
    TF1 *func = new TF1("func2", "exp(-[1]*x)*[0]*sin(x)", 0, 10*TMath::Pi());

    func->SetParameter(0, 1);
    func->SetParameter(1, 0.1);
    func->SetTitle("");
    func->GetXaxis()->SetTitle("X axis");
    func->GetYaxis()->SetTitle("Y axis");


    func->Draw();

    c1->Print("func.pdf");
    c1->Draw(); 

}