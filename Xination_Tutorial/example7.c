void example7()
{
    TFile f("example2.root");
    TTree* t; f.GetObject("t", t);

    Int_t A_account[2] = {0};
    Int_t B_account[3] = {0};

    t->SetBranchAddress("A", A_account);
    t->SetBranchAddress("B", B_account);

    t->GetEntry(0);
    cout << A_account[0] <<"\n" << A_account[1] << endl;
    cout << B_account[0] <<"\n" \
         << B_account[1] << "\n"\
         << B_account[2] <<endl;
}