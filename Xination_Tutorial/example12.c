void example12()
{
    TFile *file = new TFile("example1.root");
    TTree *tBrother;
    file->GetObject("t", tBrother);

    Int_t money_Mom;
    Int_t money_Dad;

    TTree *tParent = new TTree("tParent", "a friend");
    tParent->Branch("money_M", &money_Mom, "money_M/I");
    tParent->Branch("money_D", &money_Dad, "money_D/I");

    money_Mom = 500; money_Dad = 600; tParent->Fill();
    money_Mom = 500; money_Dad = 100; tParent->Fill();
    money_Mom = 600; money_Dad = 200; tParent->Fill();
    money_Mom = 600; money_Dad = 900; tParent->Fill();
    money_Mom = 200; money_Dad = 1000; tParent->Fill();

    TFile *file2 = new TFile("example1_friend.root", "RECREATE");
    tParent->Write();
    file2->Close();
    tBrother->AddFriend("tParent", "example1_friend.root");

    tBrother->Scan("money_A:tParent.money_M:tParent.money_D");
    tBrother->Draw("tParent.money_D");
}
