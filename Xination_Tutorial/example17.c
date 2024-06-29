void example17()
{
    TFile* f = new TFile("simple.root");
    TTree* t;
    f->GetObject("t",t);
    
    t->Scan("*")

    t->SetScanField(10);
    t->Scan("*");

    t->Scan("*","","colsize=20");
    t->Scan("*","","col=5:10:15");

    t->Scan("*","","colsize=15 precision=4");
    t->Scan("*","","col=5.0F:10.0F:15.0F");
    t->Scan("*","","col=5.1F:10.2F:15.3F");

    t->Scan("*","","",10,0); // 10 runs, start from index = 0
    t->Scan("*","","",10,5); // 10 runs, start from index = 5
    t->Scan("sqrt(money)",        "", "colsize=15", 10,0 );
    t->Scan("TMath::Log2(money)", "", "colsize=15", 10,0 );
    f->Close();
}