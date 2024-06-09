void write()
{
    TFile *output = new TFile("tut20.root", "recreate");
    TTree *tree = new TTree("tree", "tree");

    double x, y;

    tree->Branch("x", &x, "x/D");
    tree->Branch("y", &y, "y/D");

    TRandom2 *rand = new TRandom2();

    for (int i = 0; i < 1e6; i++)
    {
        x = 1 + rand->Rndm()*9;
        y = x*2;

        tree->Fill();
    }
    output->Write();
    output->Close();
}

void cut()
{
    TCut cut1 = "x < 5";
    TCut cut2 = "x > 8";
    TFile *input = new TFile("tut20.root", "READ");
    TTree *tree = (TTree*)input->Get("tree");
    tree->Draw("y", cut1||cut2);

}


void tut20()
{
    write();
    cut();
}