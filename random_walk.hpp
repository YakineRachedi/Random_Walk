#ifndef RW_HPP_INCLUDED
#define RW_HPP_INCLUDED

#include <random>

class RandomWalk {
    protected :
        unsigned n; // current time
        int s; // S_n value
        int s_ini; // S_0 value
        std::bernoulli_distribution U;
    public :
        RandomWalk(int s0, double p) : n(0), s(s0), s_ini(s0), U(p) {}
        int val() const {return this-> s;} // Getter
        unsigned time() const {return this-> n;} // Getter
        void reset() {
            n = 0, s = s_ini 
            ;}
        template <class RNG> void update(RNG & G) { // Update of s: moving from n to n+1
            n++;
            if( U(G) ){
                s++;
            }
            else{
                s--;
            }
        }
};





#endif