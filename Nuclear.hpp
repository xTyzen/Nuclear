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
    }

    namespace Units {
        constexpr double AMU = 1.660539 * 1e-27;
        constexpr double MEV = 1.602176 * 1e-13;
        constexpr double EV = 1.602176634 * 1e-19;
        constexpr double MEV_PER_AMU = 931.49410242
        
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
        return Z * NuclearStatics::PARTICLE_MASS::PROTON_MASS_KG
            + N * NuclearStatics::PARTICLE_MASS::NEUTRON_MASS_KG
            - real_mass;
    }
    
    inline double binding_energy()
}

#endif // NUCLEAR_HPP

