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
        virtual void reset() {
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
            return;
        }
};

class RandomWalk_with_min: public RandomWalk {
    protected :
        int m; // M_n value
    public :
        RandomWalk_with_min(int s0, double p) : RandomWalk(s0,p) , m(s0) {}
        int minimum() const {return this -> m;} // Getter
        void reset() {RandomWalk::reset() ; m = s_ini;}
        template <class RNG> void update(RNG & G){
            RandomWalk::update(G);
            if(s < m) {m = s;}
            return;
        }
};




#endif