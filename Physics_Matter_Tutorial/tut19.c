void tut19()
{
    TCanvas *c1 = new TCanvas();
    TProfile *hprof = new TProfile("hprof", "", 100, 0, 10);

    TRandom2 *rand = new TRandom2();

    for (int i = 0; i < 1e6; i++)
    {
        hprof->Fill(rand->Rndm()*10, rand->Rndm());
    }
    
    hprof->Draw();
}