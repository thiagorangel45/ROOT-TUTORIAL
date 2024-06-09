#include <TFile.h>
#include <TTree.h>
#include <TRandom3.h>

void main7()
{
    TFile *file = new TFile("test7.root", "RECREATE");
    TRandom3 rand;

    const int n_size = 1000;
    int energy[n_size];

    for (int i = 0; i < n_size; ++i)
    {
        energy[i] = rand.Integer(100);
    }

    TTree *tree = new TTree("tree", "tree");
    tree->Branch("Energy", energy, "Energy[1000]/I");
    tree->Fill();
    tree->Write();

    file->Close();
}
