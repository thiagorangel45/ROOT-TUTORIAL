void example9(){

    TFile f("example4.root");
    TTree* t;  f.GetObject("t",t);
    
    struct particle_STRUCT { 
        Float_t energy; 
        Float_t position[3]; 
    };

    particle_STRUCT sParticle;
    TBranch* tb = t->GetBranch("Particle_info");
    tb->SetAddress(&sParticle);
    
    t->GetEntry(0);

    cout << sParticle.energy << "\n" << sParticle.position[0] << "\n" << sParticle.position[1] << "\n" << sParticle.position[2] << endl;
}