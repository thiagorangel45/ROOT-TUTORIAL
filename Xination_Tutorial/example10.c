void example10(){

    gSystem->Load("particle_CLASS_h.so");
    TFile f("example5.root");
    TTree* t;  f.GetObject("t",t);


    particle_CLASS* sParticle = new particle_CLASS(); 
    t->SetBranchAddress("Particle_info",  &sParticle );
    t->GetEntry(0);

    cout << sParticle->Get_energy() << endl;
    cout << sParticle->Get_position()[0] << endl;
    cout << sParticle->Get_position()[1] << endl;
    cout << sParticle->Get_position()[2] << endl;


}
