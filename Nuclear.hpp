/*++ BUILD Version: V.1

Copyright (c) xTyzenDev. All rights reserved.

Module Name:

    Nuclear.hpp


--*/


#ifndef NUCLEAR_HPP
#define NUCLEAR_HPP
#pragma once
#include <iostream>
#include <cmath>

namespace NuclearStatics {
    namespace UNIVERSAL_CONST {
        constexpr double LIGHT_SPEED = 299792458.0;
        constexpr double AVOGADRO = 6.02214076 * 1e23;
        constexpr double ELEMENTARY_CHARGE = 1.602176634 * 1e-19;

        constexpr double A_VOLUME = 15.75;
        constexpr double A_SURFACE = 17.8;
        constexpr double A_COULOMB = 0.711;
        constexpr double A_ASYMMETRY = 23.7;
        constexpr double A_PAIRING = 11.18;
    }

    namespace UNITS {
        constexpr double AMU = 1.660539 * 1e-27;
        constexpr double MEV = 1.602176 * 1e-13;
        constexpr double EV = 1.602176634 * 1e-19;
        constexpr double MEV_PER_AMU = 931.49410242;
        
    }

    namespace PARTICLE_MASS {
        constexpr double MASS_ENERGY_ATOMIC = 931.49410242;
        constexpr double ATOMIC_MASS = 1.66053906660* 1e-27;
        constexpr double PROTON_MASS_KG = 1.67262192369 * 1e-27;
        constexpr double NEUTRON_MASS_KG = 1.67492749804 * 1e-27;
        constexpr double ELECTRON_MASS_KG = 9.1093837015 * 1e-31;
        constexpr double PROTON_MASS_AMU = 1.007276466621;
        constexpr double NEUTRON_MASS_AMU = 1.00866491595;
        constexpr double ELECTRON_MASS_AMU = 0.000548579909;
    }
}

namespace NuclearEnergetics {
    inline double defect_mass(double Z, double N, double real_mass){
        return Z * (NuclearStatics::PARTICLE_MASS::PROTON_MASS_AMU)
            + (N * NuclearStatics::PARTICLE_MASS::NEUTRON_MASS_AMU)
            - real_mass;
    }
    
    inline double binding_energy(double mass_defect_amu){
        return mass_defect_amu * NuclearStatics::PARTICLE_MASS::MASS_ENERGY_ATOMIC;
    }

    inline double binding_per_nucleon(double total_biding_energy, double A)
    {
        if (A == 0) {  return 1; }
        return total_biding_energy / A;
    }
}

namespace Radioactivity { 
    inline double lamdba_decay (double half_life_seconds){
        return std::log(2.0) / half_life_seconds;
    }

    inline double exponential_decay(double N0, double lambda, double t){
        return N0 * std::exp(-lambda * t);
    }

    inline double Activity(double Lambda, double N_actuel){
        return Lambda * N_actuel;
    }
    
}

namespace NuclearReactions {
    inline double Q_Value(double before_mass, double after_mass){
        double Temp_QValue = (before_mass - after_mass) * NuclearStatics::UNITS::MEV_PER_AMU;
    }
    
    inline double Threshold_Energy(double q_value_mev, double m_projectile_u, double m_target_u){
        if(q_value_mev >= 0){  return 0.0; }
        if(m_target_u == 0){   return 0.0; }
        return std::abs(q_value_mev) * ((m_projectile_u +  m_target_u) / m_target_u );
    }

    inline double Fission_Power(double number_of_fissions_per_second, double Energy_per_second){
        return number_of_fissions_per_second * Energy_per_second;
    }
}

namespace NuclearModels{

}

#endif // NUCLEAR_HPP

