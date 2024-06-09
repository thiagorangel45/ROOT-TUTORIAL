#include <iostream>
#include "TFile.h"
#include "TTree.h"
#include "TClonesArray.h"
#include "TRandom2.h"
#include "TVector3.h"

using namespace std;

void write()
{
    TClonesArray *arr = new TClonesArray("TVector3");
    TClonesArray &ar = *arr;
    TFile *file = new TFile("file.root", "RECREATE");

    TTree *tree = new TTree("tcl", "tcl");
    tree->Branch("array", &arr);

    TRandom2 *rand = new TRandom2(1);

    for (int i = 0; i < 100; i++)
    {
        arr->Clear();
        for (int j = 0; j < 1000; j++)
        {
            double x = rand->Rndm();
            double y = rand->Rndm();
            double z = rand->Rndm();

            new (ar[j]) TVector3(x, y, z);
        }
        tree->Fill();
    }

    file->Write();
    file->Close();
    delete file;
    delete arr;
    delete rand;
}

void read()
{
    TFile *file = TFile::Open("file.root");
    if (!file || file->IsZombie())
    {
        std::cerr << "Error opening file" << std::endl;
        return;
    }

    TTree *tree = (TTree*)file->Get("tcl");
    if (!tree)
    {
        std::cerr << "Error getting tree" << std::endl;
        return;
    }

    TClonesArray *arr = new TClonesArray("TVector3");
    tree->SetBranchAddress("array", &arr);

    int entries = tree->GetEntries();

    for (int i = 0; i < entries; i++)
    {
        tree->GetEntry(i);
        int lines = arr->GetEntries();
        for (int j = 0; j < lines; j++)
        {
            TVector3 *vec = (TVector3*)arr->At(j);
            cout << vec->X() << endl;
        }
    }

    file->Close();
    delete file;
    delete arr;
}

void tut25()
{
    write();
    read();
}

int main()
{
    tut25();
    return 0;
}
