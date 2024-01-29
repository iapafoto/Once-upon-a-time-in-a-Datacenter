//--------------------------------------------------------------------------//
// iq / rgba  .  tiny codes  .  2008/2021                                   //
//--------------------------------------------------------------------------//

#ifndef _MZK_H_
#define _MZK_H_

#define WIN32_LEAN_AND_MEAN
#define WIN32_EXTRA_LEAN
#define VC_LEANMEAN
#define VC_EXTRALEAN

#define MZK_DURATION    134
#define MZK_RATE        44100
#define MZK_NUMCHANNELS 2 

#define MZK_NUMSAMPLES  (MZK_DURATION*MZK_RATE)
#define MZK_NUMSAMPLESC (MZK_NUMSAMPLES*MZK_NUMCHANNELS)

void mzk_init( short *buffer );


#endif