#include "../include/TriggerLateStudy.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <typeinfo>
#include "TLorentzVector.h"

using namespace std;

bool TriggerLateStudy::Offline()
{
    if(muon_n<2){return false;}
    for(int i=0; i!=muon_n; i++){
        if((*muon_author)[i]!=1 || (*muon_Type)[i]!=0){continue;}
        float can1eta = (*muon_eta)[i];
        float can1phi = (*muon_phi)[i];
        float can1pt = (*muon_pt)[i]/1000;
        float can1m = (*muon_m)[i]/1000;
        TLorentzVector can1;
        can1.SetPtEtaPhiM(can1pt,can1eta,can1phi,can1m);

        for(int j=i+1;j!=muon_n;j++){
            if((*muon_author)[j]!=1 || (*muon_Type)[j]!=0){continue;}
            float can2eta = (*muon_eta)[j];
            float can2phi = (*muon_phi)[j];
            float can2pt = (*muon_pt)[j]/1000;
            float can2m = (*muon_m)[j]/1000;
            TLorentzVector can2;
            can1.SetPtEtaPhiM(can2pt,can2eta,can2phi,can2m);

            float eta_cal = cosh(can1eta - can2eta);
            float phi_cal = cos(can1phi - can2phi);
            float mass = 2*can1pt*can2pt*(eta_cal - phi_cal);

            if(sqrt(mass)>=5.166&&sqrt(mass)<=5.526){
                off_eta.push_back(can1eta);
                off_eta.push_back(can2eta);
                off_phi.push_back(can1phi);
                off_phi.push_back(can2phi);
                off_pt.push_back(can1pt);
                off_pt.push_back(can2pt);
                h_offpt->Fill(can1pt,can2pt);
            }
        }
    }
    if(off_eta.size()>0){return true;}
    else {return false;}
}

bool TriggerLateStudy::Match()
{
    return true;
}

