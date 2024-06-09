//preenchendo tree com um array de tamanho conhecido

void main4()
{
    TFile *file = new TFile("test4.root", "RECREATE");

    TTree *tree = new TTree("tree", "money in bank");

    int A_account[5] = {0, 2, 5, 6, 9};
    int B_account[5] = {0, 5, 6, 2, 8};
    int C_account[5] = {4, 6, 4, 6, 7};

    tree->Branch("A", A_account, "Abank[5]/I");
    tree->Branch("B", B_account, "Bbank[5]/I");
    tree->Branch("C", C_account, "Cbanch[5]/I");

    tree->Fill();
    tree->Write();

    file->Close();
}