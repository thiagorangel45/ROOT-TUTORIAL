void example8(){

    TFile f("example3.root");
    TTree* t;  f.GetObject("t",t);
    
    Int_t energy[100];
    Int_t n;

    t->SetBranchAddress("Size", &n);
    t->SetBranchAddress("Energy", energy);

    Int_t nn = t->GetEntries();

    for(Int_t i=0; i<nn; i++) { 
        
        for(Int_t ii=0; ii<100; ii++) { energy[ii] = 0; }

        t->GetEntry(i); 

        cout <<"num = "<< n <<"\n"\
             << energy[0]   <<"\n"\
             << energy[1]   <<"\n"\
             << energy[2]   << endl;
        cout << "-----------------" << endl;
    }

    t->GetEntry(2);
    cout << n <<"\t"<< energy[0] <<"\t"\
                    << energy[1] <<"\t"\
                    << energy[2] << endl;

    t->GetEntry(0);
    cout << n <<"\t"<< energy[0] <<"\t"\
              << energy[1] <<"\t"\
              << energy[2] << endl;
    
    t->GetEntry(1);
    cout << n <<"\t"<< energy[0] <<"\t"\
                    << energy[1] <<"\t"\
                    << energy[2] << endl;

}