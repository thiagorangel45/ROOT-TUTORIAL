void example11()
{
    TFile *file = new TFile("tiny.root", "RECREATE");
    TTree *tree = new TTree("tree", "a simple tree");

    tree->SetMaxTreeSize(500);
    
    Int_t money_a, money_b, money_c;

    tree->Branch("money A", &money_a, "money_a/F");
    tree->Branch("money B", &money_b, "money_b/F");
    tree->Branch("money C", &money_c, "money_c/F");

    for (int i = 0; i < 100*500; i++)
    {
        money_a = 10;
        money_b = 30;
        money_c = 50;
        tree->Fill();
    }
    
    tree->Write();
    gROOT->ProcessLine(".!ls -lthr");

    TChain chain("tree");
    chain.Add("tiny.root");
    chain.Add("tiny1.root");
    chain.Add("tiny2.root");

}