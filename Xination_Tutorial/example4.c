void example4()
{

    struct particle_STRUCT { 
        Float_t energy; 
        Float_t position[3]; 
    };

    particle_STRUCT sParticle;

    TTree t("t","a simple Tree with struct");

    t.Branch("Energy",  &sParticle.energy,  "p_energy/F");
    t.Branch("Position", sParticle.position,"pos[3]/F");
    
    sParticle.energy = 11.;
    sParticle.position[0] = 7.7;
    sParticle.position[1] = 2.2;
    sParticle.position[2] = 3.3;
    t.Fill();    

    sParticle.energy = 99.;
    sParticle.position[0] = 191.;
    sParticle.position[1] = 291.;
    sParticle.position[2] = 391.;
    t.Fill();

    TFile f("example4.root","recreate");  
    t.Write();
    f.Close();

}