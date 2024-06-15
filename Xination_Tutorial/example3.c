void example3()
{
    TFile *file = new TFile("example3.root", "RECREATE");
    TTree *tree = new TTree("tree", "tree");

    const int n_maxsize = 100; 
    int energy[n_maxsize] = {0};
    int n; 

    tree->Branch("size", &n, "n/I");
    tree->Branch("Energy", energy, "Energy[n]/I");

    n = 1;
    energy[0] = 100;
    tree->Fill();

    n = 2;
    energy[0] = 50;
    energy[1] = 75;
    tree->Fill();

    n = 3;
    energy[0] = 56;
    energy[1] = 34;
    energy[2] = 79;
    tree->Fill();

    tree->Write();
    file->Close();
}
