// preenchendo tree com valores inteiro

void main3()
{   
    TFile *file = new TFile("test3.root", "RECREATE");
    TTree tree("tree", "a simple tree");

    int money_A, money_B, money_C;

    tree.Branch("mA", &money_A, "money_A/I");
    tree.Branch("mB", &money_B, "money_B/I");
    tree.Branch("mC", &money_C, "money_C/I");

    money_A = 50, money_B = 20, money_C = 10;
    tree.Fill();
    money_A = 20, money_B = 20, money_C = 100;
    tree.Fill();

    tree.Write();
    file->Close();


}