#include "TROOT.h"    
#include "TObject.h" 
#include "TFile.h"
#include "TTree.h"
#include "TSystem.h"

void example5()
{
    TTree t("t","a simple Tree with class");
    gSystem->Load("particle_CLASS_h.so");
    particle_CLASS* sParticle = new particle_CLASS(); 

    t.Branch("Particle_info",  &sParticle );
    sParticle->Set_energy(11);
    sParticle->Set_position(1.1, 2.2, 3.3);
    t.Fill();    

    sParticle->Set_energy(99.);
    sParticle->Set_position(191., 291., 391.);
    t.Fill();  

    TFile f("example5.root","recreate");  

    t.Write();
    f.Close();
}


