#include <TFile.h>
#include <TTree.h>
#include <TRandom3.h>

void main6()
{
    TFile *file = new TFile("test6.root", "RECREATE");
    file->mkdir("dir1");
    file->cd("dir1");

    TRandom3 rand;

    const int n_maxsize = 100;
    int energy[n_maxsize] = {0};

    TTree *tree = new TTree("tree", "tree");

    int n;

    tree->Branch("size", &n, "n/I");
    tree->Branch("Energy", energy, "Energy[n]/I");

    for (int i = 0; i < n_maxsize; i++)
    {
        n = rand.Integer(n_maxsize) + 1; 
        for (int j = 0; j < n; j++)
        {
            energy[j] = rand.Integer(100); 
        }
        tree->Fill();
    }

    tree->Write();
    file->Close();
}
