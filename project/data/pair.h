#ifndef PAIR_H
#define PAIR_H

template<typename A, typename B>
class Pair
{
public:
    A fst;
    B snd;

    Pair(A fst, B snd) : fst(fst), snd(snd) {}
};

#endif // PAIR_H
