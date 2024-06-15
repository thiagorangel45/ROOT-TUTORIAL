void example1()
{


    TTree t("t","a simple Tree");

	Int_t money_A, money_B, money_C;

    t.Branch("mA", &money_A, "money_A/I");
    t.Branch("mB", &money_B, "money_B/I");
    t.Branch("mC", &money_C, "money_C/I");

    money_A = 10;   money_B = 30;   money_C = 60;   t.Fill();
    money_A = 20;   money_B = 30;   money_C = 50;   t.Fill();
    money_A = 50;   money_B = 35;   money_C = 15;   t.Fill();


	TFile f("example1.root","recreate");   
	t.Write();
	f.Close();
}