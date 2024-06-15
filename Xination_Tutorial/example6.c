#include "TROOT.h"    
#include "TObject.h" 
#include "TFile.h"
#include "TTree.h"



void example6(){

    TFile f("example1.root");
    TTree* t;  f.GetObject("t",t);
   
    Int_t AA, BB, CC;
    t->SetBranchAddress("mA",&AA);
    t->SetBranchAddress("mB",&BB);
    t->SetBranchAddress("mC",&CC);
    t->GetEntry(0);
    cout << AA << "\t" << BB << "\t" << CC << endl;

    t->GetEntry(1);
    cout << AA << "\t" << BB << "\t" << CC << endl;

    t->GetEntry(2);
    cout << AA << "\t" << BB << "\t" << CC << endl;


    cout << t->GetEntries() << endl;
    Int_t nn = t->GetEntries();

    for(Int_t i=0; i<nn; i++) { 

        t->GetEntry(i); 
        cout << AA << "\t" << BB << "\t" << CC << endl; 
    }


}