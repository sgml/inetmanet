//
// Copyright (C) 2005 Andras Varga
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
//


#ifndef __THRUPUTMETER_H
#define __THRUPUTMETER_H

#include <omnetpp.h>
#include "INETDefs.h"


/**
 * Measures and records network thruput
 */
class INET_API ThruputMeter : public cSimpleModule
{
  private:
    // config
    simtime_t starttime; // start time
    int batchsize;   // number of packets in a batch
    int maxinterval; // max length of measurement interval (measurement ends
                     // if either batchsize or maxinterval is reached, whichever
                     // is reached first)

    // global statistics
    unsigned long numpackets;
    unsigned long numbits;

    // current measurement interval
    simtime_t intvl_starttime;
    simtime_t intvl_lastpktime;
    unsigned long intvl_numpackets;
    unsigned long intvl_numbits;

    // statistics
    cOutVector bitpersecVector;
    cOutVector pkpersecVector;

  protected:
    void updateStats(simtime_t now, unsigned long bits);
    void beginNewInterval(simtime_t now);

  protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
    virtual void finish();
};

#endif
