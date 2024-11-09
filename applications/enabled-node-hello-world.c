/*
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain this list of conditions
 *    and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the Institute nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL
 * THE SOFTWARE PROVIDER OR DEVELOPERS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#include <stdio.h>
#include <math.h>
#include "contiki.h"
#include "sdn-core.h"
#include "flow-table-tests.h"
#include "src-route-tests.h"
#include "sdn-debug.h"
#include "string.h"
#include "lib/random.h"
#include <inttypes.h>
#include "manage-info.h"
#include "sdn-node-security-module.h"
#include "sdn-send-packet.h"

#ifdef DEMO
#include "leds.h"
#endif

#include "sys/etimer.h"

#ifndef SDN_SIMULATION_N_SINKS
#define SDN_SIMULATION_N_SINKS 1
#endif

#define SENSING_AT_SECONDS 60
#define IDS_TIMER 120
// #define CP_TIMER 120
#define Vs 3

#ifdef MONETWSEC
#define CP_TIMER 120
#endif
#ifdef MSIXTYSEC
#define CP_TIMER 60
#endif
#ifdef MTHIRSEC
#define CP_TIMER 30
#endif
#ifdef MTENSEC
#define CP_TIMER 10
#endif

// #ifdef CP_DETECT
// #define m_win 201 // number of samples for the training process. It starts in 201 to discard the first sample
// #define d_win 50
// #endif

/*---------------------------------------------------------------------------*/
PROCESS(sdn_test_process, "Contiki SDN example process");
AUTOSTART_PROCESSES(&sdn_test_process);
/*---------------------------------------------------------------------------*/
static void
receiver(uint8_t *data, uint16_t len, sdnaddr_t *source_addr, uint16_t flowId) {

  SDN_DEBUG("Receiving message from ");
  sdnaddr_print(source_addr);
  SDN_DEBUG(" of len %d: %s\n", len, (char*) data);
}

/* Use to defines either node is a sensor node and sends packets to sink or only router node and forward packets. */
// static uint8_t isSensing() {

//   uint8_t sensing = 0;

//   sensing = 1;

//   return sensing;
// }

unsigned long last_cpu;
unsigned long diff_cpu;

unsigned long node_processing_time();

unsigned long node_processing_time(){
  energest_flush();
  diff_cpu = energest_type_time(ENERGEST_TYPE_CPU) - last_cpu;
  last_cpu = energest_type_time(ENERGEST_TYPE_CPU);
  printf("Processing time: %lu\n", diff_cpu);
  return diff_cpu;
}

/*---------------------------------------------------------------------------*/
PROCESS_THREAD(sdn_test_process, ev, data) {

  PROCESS_BEGIN();

  sdn_init(receiver);

  static struct etimer periodic_timer;

  etimer_set(&periodic_timer, 30 * CLOCK_SECOND);

  if (sdn_node_addr.u8[0] == 2) {
    sdn_register_flowid(2018);
  }

  while(1) {

    PROCESS_WAIT_EVENT_UNTIL(etimer_expired(&periodic_timer));

    etimer_restart(&periodic_timer);
    
    if (sdn_node_addr.u8[0] == 3) {
      char *data = "Hello World";
      sdn_send((uint8_t*) data, strlen(data), 2018);
    }
  
  }

  PROCESS_END();
}
