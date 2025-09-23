#pragma once

#include <string>

namespace star_map {
    enum class System {
        AlphaCentauri,
        BetaHydri,
        DeltaEridani,
        EpsilonEridani,
        Omicron2Eridani,
        Sol
    };
};

namespace heaven {
    class Vessel {
        public:
            star_map::System current_system;
            std::string name;
            int generation;
            int busters;

            Vessel(std::string name, int generation);
            Vessel(std::string name, int generation, star_map::System system);
            Vessel replicate(std::string name);

            void make_buster();
            bool shoot_buster();
    };

    std::string get_older_bob(Vessel vessel1, Vessel vessel2);
    bool in_the_same_system(Vessel vessel1, Vessel vessel2);
};
